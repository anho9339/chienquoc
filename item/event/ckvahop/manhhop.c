#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 1000; }
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name("Mảnh Hộp");
        set_picid_1(6709);
        set_picid_2(6709);
        set_value(50);
		set_amount(1);
}

// 函数：获取描述
string get_desc()
{
        return "Nghe đồn 3 mảnh ghép lại sẽ được Hộp đặc biệt.";
}
