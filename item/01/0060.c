#include <equip.h>

inherit ARMOR;

void create()
{
    set_name("Lân Giáp Chiến Bào");

    set_picid_1(6042);
    set_picid_2(6042);

    set_level(0);
    set_value(0);
    set_max_lasting(1099);

    set("dp", 22);
    set("pp", 20);

    setup();

    set_gender(1);

    set_armor_code(M_ZHANJIA);
    set_armor_color_1(0x308150e0);
    set_armor_color_2(0x00004208);
}

string get_desc()
{
    return "Lân Giáp Chiến Bào";
}
