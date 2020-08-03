// make/item/make_ss_item生成

#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit USABLE;

int get_item_color()
{
    return 2;
}

int get_item_value()
{
    return 1600;
}

int get_item_value_2()
{
    return 1600;
}

void create()
{
    set_name("Thần Thú VIP");

    set_picid_1(10);
    set_picid_2(4006);
    set("picid", 5201);

    set_value(888);
    //       set_no_give(1);
}

string get_desc()
{
    return "Một con thần bảo thú giúp đỡ mọi mặt cho người chơi";
}

int get_use_effect(object me)
{
    send_user(
        me, "%c%c%w%s", ':', 3, 0,
        sprintf("Sử dụng sẽ đạt được Thần thú VIP, muốn sử dụng không ? \n" ESC "Đồng ý\nuse ! %x#\n" ESC "Huỷ Bỏ",
                getoid(this_object())));
    return 0;
}

int confirm_use(object me)
{
    return "sys/user/beast"->use_shenshou_item(me, this_object());
}
