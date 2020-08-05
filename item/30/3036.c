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
    set_name("Vạn Ác Chi Dực - Xám Nhạt");

    set_picid_1(3036);
    set_picid_2(3036);

    set_level(1);
    set_bind(1);
    set_value(500);
    set_max_lasting(35099);

    set("time_item", 1);

    set("cp", 300);
    set("dp", 200);
    set("hp", 500);
    set("sp", 100);

    setup();

    set_gender(1);

    set_back_type(8);
    set_back2_type(8);
}

string get_desc()
{
    return "Vạn Ác chi dực do Nha Ác Vu Sư chế tạo, hiệu quả bất ngờ khi sử dụng";
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
