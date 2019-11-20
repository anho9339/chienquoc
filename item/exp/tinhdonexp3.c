#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 510 ;}
int get_item_value_2() {return 510 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Mộc Liêm Đơn - Cao");
        set_picid_1(9591);
        set_picid_2(9591);
        set_value(1000);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Mộc Liêm Đơn khi ăn vào sẽ giúp người chơi có 1 lượng kinh nghiệm nhất định. \nSử dụng sẽ nhận được 15.000 kinh nghiệm.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift, object me ) 
{
	int p;
	object item;
	me = this_player();
	
	me->add_exp(15000);
	send_user(who,"%c%s",';',"Bạn nhận được "HIY "15000 điểm kinh nghiệm");
	gift->add_amount(-1);
	return 0;
}