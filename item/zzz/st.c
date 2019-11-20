#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("ST");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "ST."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item,item1,item2,item3;
	if ( who->get_gender()!=1 ) return 0;
	gift->add_amount(-1);
	who->add_save_2("songtu.time",43200);
	return 0;
}

