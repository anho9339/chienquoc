#include <equip.h>

inherit USABLE;
inherit ITEM;

void create()
{
    set_name("Thư Nhà");

    set_picid_1(3854);
    set_picid_2(3854);

    set_value(1);

    set_no_give(1);
    set_no_drop(1);
    set_no_sell(1);
}

string get_desc()
{
    return "Nhiệm vụ vật phẩm, lá thư gửi về nhà";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
    if (me->get_save_2("orgtask2.type") != 4)
        return 1;
}
