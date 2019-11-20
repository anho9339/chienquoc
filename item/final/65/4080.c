
// 自动生成：/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// 函数：适用门派
int get_family() { return 4; }

// 函数：成品编号
int get_fin_type() { return 2038; }

// 函数：构造处理
void create()
{
        set_name("Hàn Tinh Đầu Cân");
        set_picid_1(6625);
        set_picid_2(6625);

        set_level(80);
        set_value(6000);
        set_max_lasting(15899);
        set("ap", 0);
        set("dp", 135);
        set("cp", 0);
        set("pp", 54);
        set("sp", 0);

        setup();
}

// 函数：获取描述
string get_desc()
{
        return "Hàn Tinh Đầu Cân";
}
