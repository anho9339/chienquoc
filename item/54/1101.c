#include <ansi.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int card_id;
int card_time;

int get_item_value()
{
    return 2;
}

int get_item_value_2()
{
    return 2;
}

int get_item_number()
{
    return 10001057;
}

int get_item_color()
{
    return 1;
}

int set_card_id(int i)
{
    return card_id = i;
}

int get_card_id()
{
    return card_id;
}

int set_card_time(int i)
{
    return card_time = i;
}

int get_card_time()
{
    return card_time;
}

void create()
{
    set_name("Thẻ Kiếm Hồn");

    set_picid_1(3812);
    set_picid_2(3812);

    set_value(20);

    set_card_id(1101);
    set_card_time(3600);

    set_amount(1);
}

string get_desc()
{
    return "Trong 1 giờ biến thân thành Kiếm Hồn\n có thể giúp gia tăng Chính Xác lên 2%";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object item)
{
    send_user(who, "%c%c%w%s", ':', 3, 0,
              sprintf("Bạn chắc chắn muốn sử dụng %s không ?\n" ESC "Xác nhận\nuse ! %x#\n" ESC "Huỷ bỏ",
                      item->get_name(), getoid(item)));
    return 0;
}

int confirm_use(object me)
{
    return __FILE__->confirm_use_callout(me, this_object());
}

int confirm_use_callout(object who, object item)
{
    int rate, rate1;

    if ("sys/sys/magic_card"->change_shape(who, item->get_card_id(), item->get_card_time()) != 1)
        return 0;

    who->set_2("magic_card.hit_rate", 2);
    who->set_2("magic_card.hit_rate1", 2);
    USER_ENERGY_D->count_hit_rate(who);
    return 1;
}

void remove_effect(object who)
{
    who->delete_2("magic_card.hit_rate");
    who->delete_2("magic_card.hit_rate1");
    USER_ENERGY_D->count_hit_rate(who);
}
