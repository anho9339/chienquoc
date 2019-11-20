#include <item.h>
#include <effect.h>
#include <skill.h>
// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }
int get_item_color() {return 2 ;}

// 函数：构造处理
void create()
{
        set_name("Giải Phóng Lao Động");
        set_picid_1(4102);
        set_picid_2(4102);
      //  set_unit("块");
        set_value(100);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Khúc tre khắc tinh phách ẩn chứa điều bí ẩn. Hãy tới ... để hỏi"; 
}
