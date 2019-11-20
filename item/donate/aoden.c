
#include <equip.h>

inherit ARMOR;

// 函数：nh9h构造处理
void create()
{
        set_name("Phu tử phục");
        set_picid_1(0005);
        set_picid_2(0005);
        set_unit("Kiện");

        set_level(50);
        set_value(5000);
        set_max_lasting(10599);
        set("dp", 60);
        set("pp", 60);
        set("hp", 55);
        set("mp", 55);

        setup();

        set_armor_code(M_CHANGPAO);
        set_armor_color_1(H_BLACK);
        set_armor_color_2(H_BLACK);
}

// 函数：nh9h获取描述
string get_desc()
{
        return "Chiếc áo thời trang màu Đen";
}
