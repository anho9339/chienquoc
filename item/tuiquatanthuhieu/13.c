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
        set_name("Tu Luyện Bao");
		set_picid_1(7108);
        set_picid_2(7108);
		set_level(0);
        set_value(5000);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{
		return "Sử dụng sẽ mở ra các chức năng Tu Luyện giúp đỡ cho người chơi.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object me,object gift ) 
{
	string arg;
	
	"cmd/user/tuluyen"->main(me,arg);
	return 0;
}