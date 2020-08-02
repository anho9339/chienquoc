#include <ansi.h>

inherit ITEM;

int get_item_value()
{
    return 225;
}

int get_item_value_2()
{
    return 200;
}

int get_item_number()
{
    return 1;
}

void create()
{
    set_name("Đại Lễ Bao");

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
    return "Chứa quà tặng lễ bao。";
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

    if (rate < 8)
    {
        item = new ("item/08/0001");

        if (!item)
            return 0;
    }

    else if (rate < 16)
    {
        item = new ("item/08/0002");

        if (!item)
            return 0;
    }

    else if (rate < 26)
    {
        item = new ("item/08/0003");

        if (!item)
            return 0;
    }

    else if (rate < 36)
    {
        item = new ("item/08/0004");

        if (!item)
            return 0;
    }

    else if (rate < 50)
    {
        item = new ("item/91/9100");

        if (!item)
            return 0;

        item->set_amount(20);
    }

    else if (rate < 64)
    {
        item = new ("item/91/9110");

        if (!item)
            return 0;

        item->set_amount(20);
    }

    else if (rate < 74)
    {
        item = new ("item/std/8000");

        if (!item)
            return 0;
    }

    else if (rate < 94)
        cash = 10000;

    else if (rate < 98)
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
        send_user(who, "%c%s", '!', "Chúc mừng!Bạn mở gói quà Đại Lễ Bao đạt được" + item->get_name());
        p = item->move2(who);
        item->add_to_user(p);
    }

    else if (cash)
    {
        who->add_cash(cash);
        who->add_gold_log("item0405", cash);
        "/sys/sys/count"->add_income("item0405", cash);
        send_user(who, "%c%s", '!', "Chúc mừng!Bạn mở gói quà Đại Lễ Bao đạt được 10000 vàng");
    }

    return 0;
}
