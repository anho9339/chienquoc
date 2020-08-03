#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;

int is_christmas()
{
    return 1;
}

void reset()
{
    if (gone_time(get_drop_time()) > 7200)
    {
        remove_from_scene();
        destruct(this_object());
    }
}

void create()
{
    set_name("Vớ");

    set_picid_1(9983);
    set_picid_2(9983);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Chiếc vớ giáng sinh, có thể giao cho ông già Noel để đổi quà.";
}
