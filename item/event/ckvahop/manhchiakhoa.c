#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 1000; }
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name("Mảnh Chìa Khóa");
        set_picid_1(6705);
        set_picid_2(6705);
     //   set_level(3);
        set_value(50);
		set_save("knb",20);
		set_amount(1);
}

// 函数：获取描述
string get_desc()
{
        return "Nghe nói ghép 3 mảnh chìa khóa sẽ được Chìa Khóa Đặc Biệt.";
}
