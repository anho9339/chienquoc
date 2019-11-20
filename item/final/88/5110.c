
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// 函数：适用门派
int get_family() { return 5; }

// 函数：成品编号
int get_fin_type() { return 2103; }

// 函数：构造处理
void create()
{
        set_name("Kiền Vân Chi Hài");
        set_picid_1(8812);
        set_picid_2(8812);

        set_level(110);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 50);
        set("cp", 0);
        set("pp", 0);
        set("sp", 55);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Kiền Vân Chi Hài";
}
