
// 自动生成：/make/equip/60b

#include <equip.h>

inherit WAIST;

// 函数：适用门派
int get_family() { return 6; }

// 函数：构造处理
void create()
{
        set_name("Hổ Đầu Yêu Đới");
        set_picid_1(8709);
        set_picid_2(8709);

        set_level(45);
        set_value(13250);
        set_max_lasting(6099);
        set("dp", 30);
        set("pp", 45);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Hổ Đầu Yêu Đới";
}
