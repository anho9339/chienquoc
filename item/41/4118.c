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
    return 30;
}

int get_item_type_2()
{
    return ITEM_TYPE_2_STUFF;
}

void create()
{
    set_name("Thổ Hồn");

    set_picid_1(3450);
    set_picid_2(3450);

    set_value(150);

    set_amount(1);
}

string get_desc()
{
    return "Thổ tinh linh hấp thụ tinh hoa mà thành";
}
