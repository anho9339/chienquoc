
// 自动生成：/make/weapon/make71

#include <equip.h>

inherit MISSILE;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("ap", %d);
        set("t!%%", %d);
        set("spec.hp", %d);
        set("spec.mp", %d);
        set("spec.mp*", %d);

        setup();

        set_weapon_type(THROWING);
}

// 函数：获取武器级别
int get_weapon_level() { return %d; }

// 函数：获取描述
string get_desc()
{
        return "“暗器”装备";
}
