
// 自动生成：/make/equip/60b

#include <equip.h>

inherit NECK;

// 函数：适用门派
int get_family() { return 7; }

// 函数：构造处理
void create()
{
        set_name("Thanh Ngọc Hạng Liên");
        set_picid_1(8657);
        set_picid_2(8657);

        set_level(50);
        set_value(35000);
        set_max_lasting(5299);
        set("cp", 90);
        set("pp", 60);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Thanh Ngọc Hạng Liên";
}
