#include <equip.h>

inherit "/inh/equip/back";

int get_item_color()
{
    return 2;
}

int get_item_value()
{
    return 1000;
}

int get_item_value_2()
{
    return 1000;
}

inherit BACK;

void create()
{
    set_name("Thánh Linh Chi Dực·Xanh Lục");

    set_picid_1(3032);
    set_picid_2(3032);

    set_level(1);
    set_bind(1);
    set_value(1000);
    set_save("qsvst", 1200);
    set_max_lasting(21599);

    set("cp+", 300);
    set("dp+", 300);
    set("hp+", 800);
    set("mp+", 800);
    set("sp+", 100);
    //  set("double", 500);

    setup();

    //    set_gender(1);
    set_back_type(7);
    set_back2_type(7);
    set_back_color(0x008B3D48);  // 0x00E22B8A
    set_back2_color(0x008B3D48);
}

string get_desc()
{
    return "Thánh vật của sứ giả Quang Minh, dùng để ngăn cản lực lượng tà ác uy hiếp.";
}
