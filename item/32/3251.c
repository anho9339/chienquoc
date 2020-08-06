#include <effect.h>
#include <item.h>
#include <skill.h>

inherit ITEM;
inherit COMBINED;

int get_item_type_2()
{
    return ITEM_TYPE_2_STUFF;
}

int get_stuff_type()
{
    return 171;
}

void create()
{
    set_name("Trứng");

    set_picid_1(3251);
    set_picid_2(3251);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Là thứ cần thiết trong kỹ năng sống";
}
