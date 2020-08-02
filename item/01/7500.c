#include <equip.h>

inherit WEAPON;

void create()
{
    set_name("Trường mộc côn");

    set_picid_1(7500);
    set_picid_2(7500);

    set_level(0);
    set_value(50);
    set_max_lasting(4099)

        set("ap", 13);
    set("dp", -3);

    setup();

    set_weapon_type(STICK);
}

int get_weapon_level()
{
    return 0;
}

string get_desc()
{
    return "Một loại côn dài, có thể đánh các động vật nhỏ.";
}
