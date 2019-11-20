#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <map.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() {return 2 ;}

// 函数：构造处理
void create()
{
        set_name( "Hoa Hồng Thâu Tâm" );
        set_picid_1(3005);
        set_picid_2(3005);
        set_value(100);
	//	set_save("knb2",3);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Loại hoa hồng đặc biệt trong ngày Lễ Tình Nhân.\nCó thể giúp bạn bày tỏ tình cảm với người bạn yêu.";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{	                        
	send_user( me, "%c%c%d%s", '?', 16, 10, "Xin nhập vào ID muồn bày tỏ tình cảm:\n" ESC "vlt ? %s\n" );
	return 0;	                        
} 