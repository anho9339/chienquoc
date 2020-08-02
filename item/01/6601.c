#include <equip.h>

inherit HEAD;

void create()
{
    set_name("Bố Mão");

    set_picid_1(6600);
    set_picid_2(6600);

    set_level(0);
    set_value(10);
    set_max_lasting(2499);

    set("dp", 5);
    set("pp", 5);
    set("hp", 5);
    set("mp", 5);

    setup();

    set_gender(2);

    set_head_code(F_PINGMAO);
    set_head_color(0x4208226d);
}

string get_desc()
{
    return "Bố Mão";
}
