#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Tu luyện Mật Tịch 100");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng sẽ tu luyện kĩ năng 100 lên cấp 10, sau khi sử dụng thoát trò chơi vào lại mới có tác dụng."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item,item1,item2,item3;
	
	if(USER_INVENTORY_D->get_free_count(who) < 5 )
		{
				notify( "Hành trang không đủ 5 chỗ trống" );
		return 0;
		}
	gift->add_amount(-1);
		who->add_save("luyenskill100",100000);
	return 0;
}

