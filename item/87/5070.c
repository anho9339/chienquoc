
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 5; }

// 函数：构造处理
void create()
{
        set_name("Thị Thiên Yêu Đới");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(70);
        set_value(22000);
        set_max_lasting(6799);
        set("dp", 57);
        set("pp", 70);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Thị Thiên Yêu Đới";
}
