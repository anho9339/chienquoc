
#include <equip.h>

inherit WEAPON;

// 函数：构造处理
void create()
{
        set_name("Tử Tinh Hộ Thủ");
        set_picid_1(7022);
        set_picid_2(7022);
        set_unit("双");

        set_level(0);
        set_value(0);
        set_max_lasting(1099);
        set("ap", 20);
        set("!%", 6);

        setup();

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return 22; }

// 函数：获取描述
string get_desc()
{
        return "“Quyền Pháp”Trang bị";
}
