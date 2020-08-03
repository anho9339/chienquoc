#include <ansi.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int card_id;
int card_time;

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
    set_name("Thẻ biến hình Phi Tặc Noel");

    set_picid_1(3812);
    set_picid_2(3812);

    set_value(1);

    set_card_id(1290);
    set_card_time(3600);

    set_amount(1);
}

string get_desc()
{
    return "Liên tục trong 1 giờ biến thân thành Phi Tặc Noel.";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object item)
{
    send_user(who, "%c%c%w%s", ':', 3, 0,
              sprintf("Bạn muốn sử dụng %s không ?\n" ESC "Xác nhận\nuse ! %x#\n" ESC "Rời khỏi", item->get_name(),
                      getoid(item)));
    return 0;
}

int confirm_use(object me)
{
    return __FILE__->confirm_use_callout(me, this_object());
}

int confirm_use_callout(object who, object item)
{
    if ("sys/sys/magic_card"->change_shape(who, item->get_card_id(), item->get_card_time()) != 1)
        return 0;

    return 1;
}

void remove_effect(object who) {}
