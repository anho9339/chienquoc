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
    return 10001054;
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
    set_name("Thẻ Địa Sát Môn Thủ");

    set_picid_1(3810);
    set_picid_2(3810);

    set_value(20);

    set_card_id(1051);
    set_card_time(3600);

    set_amount(1);
}

string get_desc()
{
    return "Trong 1 giờ biến thân thành ĐSMT\n có thể giúp gia tăng Ngoại Kháng lên 2%";
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
    int dp;

    if ("sys/sys/magic_card"->change_shape(who, item->get_card_id(), item->get_card_time()) != 1)
        return 0;

    dp = who->get_dp() * 2 / 100;
    who->set_2("magic_card.dp", dp);
    USER_ENERGY_D->count_dp(who);
    return 1;
}

void remove_effect(object who)
{
    int dp;

    dp = who->get_2("magic_card.dp");

    if (!dp)
        return;

    who->delete_2("magic_card.dp");
    USER_ENERGY_D->count_dp(who);
}
