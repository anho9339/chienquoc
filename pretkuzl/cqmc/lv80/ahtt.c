#include <ansi.h>
#include <skill.h>
inherit COMBINED;
inherit ITEM;

int get_item_value() {return 450 ;}
int get_item_value_2() {return 380 ;}
//int get_item_number() {return 10001006 ;}
int get_item_color() {return 3 ;}

// 函数:构造处理
void create()
{
        set_name("Anh Hùng Tương Trợ");
        set_picid_1(0096);
        set_picid_2(0096);
        set_value(100);
        set_amount(1);       		
}
int is_usable() {return 1;}

string get_desc() 
{ 
        return "Lệnh bài thần kỳ, sau khi sử dụng bạn sẽ được lên thẳng cấp 60 (Nhưng không có kĩ năng)."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
    if ( who->get_level() > 59 )
		{
		send_user(who,"%c%s",'!',"Nhỏ hơn cấp 60 mới có thể sử dụng.");
		    		return 0;

		}
    who->set_level(60);
    who->count_gift();	
	return 1;
}