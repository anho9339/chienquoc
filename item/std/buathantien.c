#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit COMBINED;

int get_item_color() {return 1 ;}
int get_max_combined() { return 10000; }
int get_item_value() {return 20 ;}
int get_item_value_2() {return 20 ;}
// 函数：构造处理
void create()
{
        set_name( "Bùa Thần Tiên" );
        set_picid_1(0413);
        set_picid_2(0413);
        set_unit( "张" );
        set_value(3500);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Chuyên dùng để kêu gọi Thần Tiên hỗ trợ.";
}
