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
    set_name("Sủng Vật Gia Quả");

    set_picid_1(9975);
    set_picid_2(9975);

    set_value(1700);

    set_amount(1);
}

string get_desc()
{
    string desc;
    return desc =
               "Một loại quả thần kì dành cho thú nuôi\nKhi sử dụng sẽ giúp tuổi thọ thú cưng tăng thêm"
               "10 điểm \n Tỷ lệ bị ngộ độc 1%";
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

    me->add_life(10);
    owner = me->get_owner();
    tell_user(owner, "của bạn" + me->get_name() + "Tuổi thọ gia tăng 10 điểm");

    if (!random100())
    {
        me->add_life(-200);
        send_user(owner, "%c%s", '!', "của bạn" + me->get_name() + "bị trúng độc!");
    }

    return 1;
}
