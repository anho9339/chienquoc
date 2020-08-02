#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("Loạn Thế Tinh Nhân Đại Lễ Bao");

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
    string result;

    if (USER_INVENTORY_D->get_free_count(who) < 1)
    {
        send_user(who, "%c%s", '!', "Bạn cần phải để trống ba ô túi hành trang。");
        return;
    }

    gift->remove_from_user();
    destruct(gift);
    item = new ("/item/std/8000");

    if (item)
    {
        p = item->move2(who);
        item->add_to_user(p);
    }

    item = new ("/quest/book"->get_book_file());

    if (item)
    {
        p = item->move2(who);
        item->add_to_user(p);
    }

    who->add_cash(10000);
    send_user(who, "%c%s", '!', "Bạn nhận được tàng bảo đồ, sách nhập môn cùng một vạn ngân lượng！");

    return 0;
}
