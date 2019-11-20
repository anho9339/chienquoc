#include <item.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() {return 1 ;}
// 修理道具 

// 函数：构造处理
void create()
{
        set_name( "Giấy Gói Quà" );
        set_picid_1(3321);
        set_picid_2(3321);
        set_value(10000);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Tờ giấy nhỏ dùng để gói quà tặng cho ngày Quốc Tế Phụ Nữ."; 
}