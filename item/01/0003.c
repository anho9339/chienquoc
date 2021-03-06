#include <equip.h>

inherit USABLE;
inherit ITEM;

void create()
{
    set_name("Thương Dược Người Đưa Tin");

    set_picid_1(7120);
    set_picid_2(7120);

    set_value(1);

    set_no_give(1);
    set_no_drop(1);
    set_no_sell(1);
}

string get_desc()
{
    string result;
    object me = this_player();
    result = "Nhiệm vụ vật phẩm, một loại thuốc bột trị thương\n";

    if (me->get_save_2("orgtask2.type") == 1)
        result +=
            sprintf("Tức tốc giao cho %s %s Người Đưa Tin\n", me->get_save_2("orgtask2.place"), me->get_org_name());

    return result;
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
    if (me->get_save_2("orgtask2.type") != 1)
        return 1;
}
