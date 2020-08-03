#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_type_2()
{
    return ITEM_TYPE_2_CON_ALL;
}

int get_recover_count()
{
    return 5;
}

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
    set_name("Gà Tây Noel");

    set_picid_1(9982);
    set_picid_2(9982);

    set_value(50);

    set_amount(1);

    set("add_hp", 350);
    set("add_mp", 400);
}

string get_desc()
{
    return "Một con gà tây trong mùa giáng sinh ấm áp.\nCó thể giao cho Ông già Noel để đổi quà tặng.\n" HIR
           "Sử dụng trong 10 giây sẽ hồi phục 350 Khí Huyết và 400 Pháp Lực.";
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
