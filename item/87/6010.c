
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("Bố Yêu Đới");
        set_picid_1(8703);
        set_picid_2(8703);

        set_level(10);
        set_value(1000);
        set_max_lasting(4999);
        set("dp", 0);
        set("pp", 10);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Bố Yêu Đới";
}