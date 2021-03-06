#include <ansi.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int card_id;
int card_time;

int get_item_value()
{
    return 10;
}

int get_item_value_2()
{
    return 10;
}

int get_item_color()
{
    return 2;
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
    set_name("Thẻ Biến Hình Vô Môn Phái Nữ");

    set_picid_1(3811);
    set_picid_2(3811);

    set_value(20);

    set_card_id(10100);
    set_card_time(7200);

    set_amount(1);
}

string get_desc()
{
    return "Trong 2 giờ hóa thân thành nhân vật VMP\n có thể giúp gia tăng Ngoại Công và Nội Công lên 1%";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object item)
{
    send_user(who, "%c%c%w%s", ':', 3, 0,
              sprintf("Bạn muốn sử dụng %s không？\n" ESC "Chấp nhận\nuse ! %x#\n" ESC "Hủy bỏ", item->get_name(),
                      getoid(item)));
    return 0;
}

int confirm_use(object me)
{
    return __FILE__->confirm_use_callout(me, this_object());
}

int confirm_use_callout(object who, object item)
{
    int ap, cp;

    if ("sys/sys/magic_card"->change_shape(who, item->get_card_id(), item->get_card_time()) != 1)
        return 0;

    ap = who->get_ap() * 1 / 100;
    cp = who->get_cp() * 1 / 100;
    who->set_2("magic_card.ap", ap);
    who->set_2("magic_card.cp", cp);
    USER_ENERGY_D->count_ap(who);
    USER_ENERGY_D->count_cp(who);
    return 1;
}

void remove_effect(object who)
{
    int ap, cp;

    ap = who->get_2("magic_card.ap");
    cp = who->get_2("magic_card.cp");

    if (!ap || !cp)
        return;

    who->delete_2("magic_card.ap");
    who->delete_2("magic_card.cp");
    USER_ENERGY_D->count_ap(who);
    USER_ENERGY_D->count_cp(who);
}
