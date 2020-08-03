#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";
inherit COMBINED;

int get_item_type_2()
{
    return ITEM_TYPE_DIAMOND_4;
}

int confirm_sell_item()
{
    return 1;
}

int get_item_color()
{
    return 1;
}

int get_stuff_type()
{
    return 324;
}

void create()
{
    set_name("Can Tương Bảo Thạch");

    set_picid_1(8962);
    set_picid_2(8962);

    set_value(200);

    set_amount(1);
}

string get_loop_desc(object me)
{
    return "";
}

string get_desc()
{
    return "Truyền thuyết tướng tài lúc chế tạo vũ khí sử dụng bảo thạch。";
}
