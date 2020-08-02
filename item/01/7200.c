#include <equip.h>

inherit WEAPON;

void create()
{
    set_name("Sơ Học Giả Mộc Đao");

    set_picid_1(7200);
    set_picid_2(7200);

    set_level(0);
    set_value(50);
    set_max_lasting(3599);

    set("ap", 8);
    set("dp", 2);

    setup();

    set_weapon_type(BLADE);
}

int get_weapon_level()
{
    return 0;
}

string get_desc()
{
    return "Một loại vũ khí chế tạo bằng gỗ, có thể giúp người sử dụng giết quái vật nhanh chóng";
}
