#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("Túi Quà Trung Thu Lớn");

    set_picid_1(4981);
    set_picid_2(4981);

    set_value(1);
}

int is_usable()
{
    return 1;
}

string get_desc()
{
    return "";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
    int rate, p, cash;
    object item;

    rate = random(100);

    if (rate < 12)
    {
        item = new ("item/08/0001");

        if (!item)
            return 0;
    }

    else if (rate < 24)
    {
        item = new ("item/08/0002");

        if (!item)
            return 0;
    }

    else if (rate < 44)
    {
        item = new ("item/08/0003");

        if (!item)
            return 0;
    }

    else if (rate < 64)
    {
        item = new ("item/08/0004");

        if (!item)
            return 0;
    }

    else if (rate < 87)
        cash = 10000;

    else if (rate < 97)
        cash = 50000;

    else if (rate < 99)
    {
        item = new ("item/std/6001");

        if (!item)
            return 0;
    }

    else
    {
        item = new ("item/std/6002");

        if (!item)
            return 0;
    }

    gift->remove_from_user();
    destruct(gift);

    if (item)
    {
        send_user(who, "%c%s", '!', "Chúc mừng!Bạn mở Túi quà Trung Thu lớn đạt được" + item->get_name());
        p = item->move2(who);
        item->add_to_user(p);
    }

    else if (cash)
    {
        who->add_cash(cash);
        send_user(who, "%c%s", '!', sprintf("Chúc mừng!Bạn mở Túi quà Trung Thu lớn đạt được%dvàng", cash));
    }

    return 0;
}
