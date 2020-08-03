// make/item/make_ss_item生成

#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit USABLE;

int get_item_color()
{
    return 3;
}

int get_item_value()
{
    return 1000;
}

int get_item_value_2()
{
    return 1000;
}

void create()
{
    set_name("Niên Thú");

    set_picid_1(10);
    set_picid_2(4006);
    set("picid", 8100);

    set_value(888);

    set_no_give(1);
}

string get_desc()
{
    return "Niên Thú là 1 con Kỳ Lân săn đuổi Năm mới";
}

int get_use_effect(object me)
{
    send_user(me, "%c%c%w%s", ':', 3, 0,
              sprintf("Sử dụng sẽ đạt được Thần thú, muốn sử dụng không ? \n" ESC "Đồng ý\nuse ! %x#\n" ESC "Huỷ Bỏ",
                      getoid(this_object())));
    return 0;
}

int confirm_use(object me)
{
    return "sys/user/beast"->use_shenshou_item(me, this_object());
}
