
#include <equip.h>

inherit WEAPON;
inherit LEGEND_ITEM;

// 函数：构造处理
void create()
{
        set_name("Mộc Kiếm Gia Gia");
        set_picid_1(7300);
        set_picid_2(7300);
        set_unit("把");

        set_value(0);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
        setup();

        set_weapon_type(-1);
}

// 函数：获取武器级别
int get_weapon_level() { return 0; }

int get_equip_type() { return 0; }

// 函数：获取描述
string get_desc()
{
        return "Nhiệm vụ đạo cụ.Chủ tiệm vũ khí lão yêu cầu giao cho thần tiên gia gia vật phẩm này。";
}
