
// 自动生成：/make/equip/60b

#include <equip.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Ngọc Phong Mão Quán");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(130);
        set_value(10000);
        set_max_lasting(16099);
        set("dp", 148);
        set("pp", 84);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Ngọc Phong Mão Quán";
}
