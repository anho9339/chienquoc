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
    return 325;
}

void create()
{
    set_name("Đá Tương Uyên");

    set_picid_1(8972);
    set_picid_2(8972);

    set_value(100);

    set_amount(1);
}

string get_loop_desc(object me)
{
    return "";
}

string get_desc()
{
    return "Theo truyền thuyết đây là vật liệu hiếm có, được bậc thầy đúc kiếm thời xa xưa sử dụng để đúc luyện vũ khí "
           "sắc bén.";
}
