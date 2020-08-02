#include <equip.h>

inherit WEAPON;

void create()
{
    set_name("Tuyệt Sát");

    set_picid_1(7522);
    set_picid_2(7522);

    set_level(0);
    set_value(0);
    set_max_lasting(1099);

    set("ap", 20);
    set("!%", 6);

    setup();

    set_weapon_type(STICK);
}

int get_weapon_level()
{
    return 22;
}

string get_desc()
{
    return "“Côn Pháp”Trang bị";
}
