#include <equip.h>

inherit ARMOR;

void create()
{
    set_name("Nữ Phục Bố Y");

    set_picid_1(6100);
    set_picid_2(6100);

    set_level(0);
    set_value(40);
    set_max_lasting(2599);

    set("dp", 10);

    setup();

    set_gender(2);

    set_armor_code(F_BUYI);
    set_armor_color_1(0x10e41988);
    set_armor_color_2(0x000010a3);
}

string get_desc()
{
    return "一Trang bị thích hợp cho các nữ nhi tân thủ。";
}
