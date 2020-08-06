// 自动生成：/make/item/make31c

#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

//  int get_max_combined() { return 30; }

int get_item_type_2()
{
    return ITEM_TYPE_2_CON_ALL;
}

int get_stuff_type()
{
    return 169;
}

void create()
{
    set_name("Mật Ong");

    set_picid_1(3244);
    set_picid_2(3244);

    set_value(100);

    set_amount(1);

    set("add_hp", 150);
    set("add_mp", 150);
}

string get_desc()
{
    return "Mật Ong vàng óng ngọt ngào hương vị\n Giúp hồi phục 150 KH và PL trong 20s \n Mỗi 2s hồi 15 điểm";
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
