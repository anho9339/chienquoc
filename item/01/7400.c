#include <equip.h>

inherit WEAPON;

void create()
{
    set_name("Giáo trúc");

    set_picid_1(7400);
    set_picid_2(7400);

    set_level(0);
    set_value(50);
    set_max_lasting(3899);

    set("ap", 11);
    set("?%", -300);

    setup();

    set_weapon_type(SPEAR);
}

int get_weapon_level()
{
    return 0;
}

string get_desc()
{
    return "Một cây giáo dài, thân giáo làm bằng trúc, vô cùng nhọn, có thể săn các động vật nhỏ một cách dễ dàng.";
}
