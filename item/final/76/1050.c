
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 9; }

// 函数：成品编号
int get_fin_type() { return 1019; }

// 函数：构造处理
void create()
{
        set_name("Ngân Xà Kiếm");
        set_picid_1(7322);
        set_picid_2(7322);

        set_level(50);
        set_value(5000);
        set_max_lasting(8099);
        set("ap", 110);
        set("dp", 6);
        set("cp", 180);
        set("pp", 0);

        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return LEVEL_06; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị \"Kiếm Pháp\"";
}
