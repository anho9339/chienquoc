#include <ansi.h>
#include <task.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Trứng Tử Mao");
        set_picid_1(15);
        set_picid_2(15);
        set_value(10);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Tử Mao vốn là Kỵ Thú của nước Sở\n Điều kiện sử dụng: Người sử dụng phải trở thành dân của nước Sở hoặc đạt đủ Giao Hảo với nước Sở.\n Vật phẩm sau khi sử dụng sẽ Phong Ấn vào nhân vật.\n"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item,item1,item2,item3;
	
	who->add_to_scene(get_z(who), get_x(who), get_y(who), get_d(who));
	return 0;
}

