
#include <equip.h>

inherit WEAPON;

// 函数：构造处理
void create()
{
        set_name("Phệ Hồn Thương");
        set_picid_1(7422);
        set_picid_2(7422);
        set_unit("杆");

        set_level(0);
        set_value(0);
        set_max_lasting(1099);
        set("ap", 20);
        set("!%", 6);

        setup();

        set_weapon_type(SPEAR);
}

// 函数：获取武器级别
int get_weapon_level() { return 22; }

// 函数：获取描述
string get_desc()
{
        return "“Thương Pháp”Trang bị";
}
