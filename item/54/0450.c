//makecard.c自动生成
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

int card_id;
int card_time;
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
        set_name("苦役卡");
        set_picid_1(3810);
        set_picid_2(3810);
        set_value(40000);
        set_card_id(450);
        set_card_time(3600);
        set_amount(1);
}
// 函数：获取描述
string get_desc() 
{ 
        return "持续1小时内变身为苦役，gia tăng 2% khí huyết.。"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}
//使用后的影响
int get_use_effect_callout( object who,object item) 
{
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("Bạn chắc chắn muốn sử dụng %s không?\n"ESC"Xác nhận\nuse ! %x#\n"ESC"Hủy bỏ",item->get_name(),getoid(item))); 
	return 0;
}

// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	int hp;
	if ( "sys/sys/magic_card"->change_shape(who,item->get_card_id(),item->get_card_time()) != 1 )
		return 0;
	hp = who->get_max_hp()/50;
	who->set_2("magic_card.hp",hp);
	USER_ENERGY_D->count_max_hp(who);
	return 1;
}

void remove_effect(object who)
{
	int hp;
	
	hp = who->get_2("magic_card.hp");
	if ( !hp ) 
		return ;
	who->delete_2("magic_card.hp");	
	USER_ENERGY_D->count_max_hp(who);
}

