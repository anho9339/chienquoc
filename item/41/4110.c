// 自动生成：/make/item/make30
#include <item.h>
inherit ITEM;
inherit COMBINED;

int get_max_combined()
{
    return 30;
}

int get_stuff_type()
{
    return 218;
}

int get_item_type_2()
{
    return ITEM_TYPE_2_STUFF;
}

int get_item_color()
{
    return 0;
}

void create()
{
    set_name("Nhiếp Hồn Thạch");

    set_picid_1(4110);
    set_picid_2(4110);

    set_value(500);

    set_amount(1);
}

string get_desc()
{
    return "Nguyên liệu cần thiết của rèn đúc, điêu khắc, may mặc, cơ quan";
}
