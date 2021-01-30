// 自动生成：/make/item/make31c
#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

//  int get_max_combined() { return 30; }

int get_item_type_2()
{
    return ITEM_TYPE_2_PET;
}

int is_pet_item()
{
    return 1;
}

void create()
{
    set_name("Bảo Thú Thực Phẩm");

    set_picid_1(9977);
    set_picid_2(9977);

    set_value(250);

    set_amount(1);
}

string get_desc()
{
    string desc;
    return desc = "Một loại thức ăn dành cho thú nuôi\nmỗi lần Bảo Thú ăn độ trung thành của Bảo Thú tăng 10 điểm";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_call(me, this_object());
}

int get_use_effect_call(object me, object item)
{
    object owner;

    if (!me->is_pet())
        return 0;

    owner = me->get_owner();

    if (me->get_faith() >= 100)
    {
        send_user(owner, "%c%s", '!', "Mức độ trung thành của Bảo Thú " + me->get_name() + " đã vượt qua giới hạn 100");
        return 0;
    }

    tell_user(owner, "Trung thành của " + me->get_name() + " tăng 10 điểm");
    me->add_faith(10);
    return 1;
}
