#include <ansi.h>
#include <equip.h>
//inherit USABLE;
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 1000; }
int get_item_color() { return 1; }
//int is_ghepngocboi() { return 1; }
// 函数：构造处理
void create()
{
        set_name("Mảnh Ghép Đoạn Thạch");
        set_picid_1(4274);
        set_picid_2(4274);
        set_value(50);
		   set_amount(1);
		//set_save("ghep",80);
}

// 函数：获取描述
string get_desc()
{
        return "Nghe đồn rằng, khi gom đủ mảnh ghép cần thiết, có khả năng ghép được Đoạn Thạch tùy ý tại NPC Phàm Chân - Chu Quốc.";
}