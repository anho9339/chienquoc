#include <ansi.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int card_id;
int card_time;

int get_max_combined()
{
    return 1;
}
// int get_item_value() {return 2 ;}
// int get_item_value_2() {return 2 ;}
// int get_item_number() {return 10001053 ;}
// int get_item_color() {return 1 ;}
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
    set_name("Thẻ Niên Thú Kỳ Lân");

    set_picid_1(3811);
    set_picid_2(3811);

    set_value(198);

    set_card_id(8100);
    set_card_time(3600);

    set_amount(1);
}

string get_desc()
{
    return "Trong 1 giờ biến thân thành NTKL\n có thể giúp gia tăng Khí Huyết, Ngoại Kháng và Nội Kháng lên 10%";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object item)
{
    send_user(who, "%c%c%w%s", ':', 3, 0,
              sprintf("Bạn chắc chắn muốn sử dụng %s không?\n" ESC "Xác nhận\nuse ! %x#\n" ESC "Hủy bỏ",
                      item->get_name(), getoid(item)));
    return 0;
}

int confirm_use(object me)
{
    return __FILE__->confirm_use_callout(me, this_object());
}

int confirm_use_callout(object who, object item)
{
    int hp, dp, pp;

    if ("sys/sys/magic_card"->change_shape(who, item->get_card_id(), item->get_card_time()) != 1)
        return 0;

    hp = who->get_max_hp() * 10 / 100;
    who->set_2("magic_card.hp", hp);
    USER_ENERGY_D->count_max_hp(who);

    dp = who->get_dp() * 10 / 100;
    who->set_2("magic_card.dp", dp);
    USER_ENERGY_D->count_dp(who);

    pp = who->get_pp() * 10 / 100;
    who->set_2("magic_card.pp", pp);
    USER_ENERGY_D->count_pp(who);

    return 1;
}

void remove_effect(object who)
{
    int hp, dp, pp;

    hp = who->get_2("magic_card.hp");
    dp = who->get_2("magic_card.dp");
    pp = who->get_2("magic_card.pp");

    if (!hp || !dp || !pp)
        return;

    who->delete_2("magic_card.hp");
    who->delete_2("magic_card.dp");
    who->delete_2("magic_card.pp");
    USER_ENERGY_D->count_max_hp(who);
    USER_ENERGY_D->count_dp(who);
    USER_ENERGY_D->count_pp(who);
    send_user(who, "%c%s", ';', "年兽卡的力量已经用完了，你回复了正常状态……");
}
