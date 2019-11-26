#include <ansi.h>
inherit ITEM;
// 函数：构造处理
void create()
{
        set_name("Thẻ Biến Hình");
        set_picid_1(3810);
        set_picid_2(3810);
        set_value(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng có thể thay đổi hình dạng trong 2 giờ。"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( "sys/sys/magic_card"->change_shape(who,11,7200) == 0 )
		return ;
	item->remove_from_user();
	destruct(item);
}

