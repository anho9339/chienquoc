#include <equip.h>

inherit HEAD;

void create()
{
    set_name("Băng Phách Chiến Khôi");

    set_picid_1(6642);
    set_picid_2(6642);

    set_level(0);
    set_value(0);
    set_max_lasting(1099);

    set("dp", 10);
    set("pp", 8);

    setup();

    set_gender(2);

    set_head_code(F_ZHANKUI);
    set_head_color(0x3a082965);
}

string get_desc()
{
    return "Băng Phách Chiến Khôi";
}
