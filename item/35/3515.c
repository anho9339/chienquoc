// 自动生成：/make/item/make35a

#include <item.h>

inherit ITEM;
inherit COMBINED;

int get_max_combined()
{
    return 30;
}

int get_stuff_type()
{
    return 31;
}

int get_item_type_2()
{
    return ITEM_TYPE_2_COOK;
}

void create()
{
    set_name("Đá Đánh Lữa");

    set_picid_1(3515);
    set_picid_2(3515);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Hai viên đá va chạm vào nhau tạo ra tia lữa";
}
