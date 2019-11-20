#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Quà Tân Thủ");
		set_picid_1(3106);
        set_picid_2(3106);
		set_level(0);
        set_value(5000);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{
		return "Túi Quà hỗ trợ Tân Thủ \nKích chuột phải để sử dụng \nTúi quà tân thủ hỗ trợ tốt hơn cho \nnhân vật có đẳng cấp dưới 10\n";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object me,object gift ) 
{
	string arg;
		
	"cmd/user/tanthu"->main(me,arg);
	return 0;
}