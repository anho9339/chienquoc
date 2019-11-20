#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("SexToy Nhật Bản (Nữ)");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Vật dùng thường dùng cho các cô gái mỗi đêm, đặc biệt là các cô gái dâm đãng."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item,item1,item2,item3;
	if ( who->get_gender()!=2 ) return 0;
	gift->add_amount(-1);
	who->set_hair(1011); 
			who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
	return 0;
}

