#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";

int get_item_color()
{
    return 2;
}

inherit BACK;

void create()
{
    set_name("Lữ Phong Phi Phong");

    set_picid_1(3021);
    set_picid_2(3021);

    set_level(1);
    set_bind(1);
    set_value(1000);
    set_max_lasting(35099);

    set("time_item", 1);

    set("ap", 200);
    set("pp", 200);
    set("hp", 400);
    set("mp", 400);
    set("double", 300);

    setup();

    set_gender(2);

    set_back_type(1);
    set_back_color(0xaaaaa);
}

string get_desc()
{
    return "Áo Choàng trong truyền thuyết, giúp người mặc cảm thấy thoải mái.";
}

int get_equip_effect(object me)
{
    return __FILE__->get_equip_effect_callout(me, this_object());
}

int get_equip_effect_callout(object me, object item)
{
    if (item->get_lock_time() == 0)
    {
        item->set_lock_time(time() + 14 * 24 * 60 * 60);
        send_user(me, "%c%d%c", 0x31, getoid(item), 0);
    }
}

string get_tail_desc()
{
    object item = this_object();
    string desc;

    if (item->get_lock_time() == 0)
        desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 14 ngày]\n ";

    return desc;
}
