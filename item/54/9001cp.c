//makesellcard.c自动生成
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

int card_id;
int card_time;

int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}
int get_item_color() {return 1 ;}

//设置变身卡ID
int set_card_id(int i) { return card_id = i;}
//获取变身卡ID
int get_card_id() { return card_id;}
//设置变身卡时间
int set_card_time(int i) { return card_time = i;}
//获取变身卡时间
int get_card_time() { return card_time;}

// 函数：构造处理
void create()
{
        set_name("Thẻ Biến Hình Bí Ngô");
        set_picid_1(3811);
        set_picid_2(3811);
        set_value(20);
        set_card_id(9001);
        set_card_time(3600);
        set_amount(1);
}
// 函数：获取描述
string get_desc() 
{ 
        return "Biến hình thành Bí Ngô Halloween trong 1h, gia tăng 10% nội công"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}
//使用后的影响
int get_use_effect_callout( object who,object item) 
{
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("Bạn chắc chắn muốn sử dụng %s không?\n"ESC"Chấp nhận\nuse ! %x#\n"ESC"Hủy bỏ",item->get_name(),getoid(item))); 
	return 0;
}

// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	int cp;
	if ( "sys/sys/magic_card"->change_shape(who,item->get_card_id(),item->get_card_time()) != 1 )
		return 0;
	cp = who->get_cp()*10/100;
	who->set_2("magic_card.cp",cp);
	USER_ENERGY_D->count_cp(who);
	return 1;
}

void remove_effect(object who)
{
	int cp;
	
	cp = who->get_2("magic_card.cp");
	if ( !cp )
		return ;
	who->delete_2("magic_card.cp");	
	USER_ENERGY_D->count_cp(who);
}