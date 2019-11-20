
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 7; }

// 函数：成品编号
int get_fin_type() { return 2216; }

// 函数：构造处理
void create()
{
        set_name("Tử Thuỷ Tinh Hài");
        set_picid_1(8813);
        set_picid_2(8813);

        set_level(85);
        set_value(10000);
        set_max_lasting(24899);
        set("ap", 0);
        set("dp", 39);
        set("cp", 0);
        set("pp", 0);
        set("sp", 43);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Tử Thuỷ Tinh Hài";
}
