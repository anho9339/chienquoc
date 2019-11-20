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
        set_name("Mảnh Ghép Phượng Hoàng");
        set_picid_1(0904);
        set_picid_2(0904);
        set_value(50);
		   set_amount(1);
		//set_save("ghep",80);
}

// 函数：获取描述
string get_desc()
{
        return "Nghe đồn rằng, khi gom đủ 50 mảnh ghép, có khả năng ghép được Phượng Hoàng Ngọc Bội trong truyền thuyết tại NPC Kinh Thiên - Chu Quốc.\nGiúp Tín Vật từ +2 thăng lên +3.";
}