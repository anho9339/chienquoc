// make/item/make_ss_item生成

#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit USABLE;

int get_item_color()
{
    return 2;
};

void create()
{
    set_name("Ma Yết");

    set_picid_1(3030);
    set_picid_2(4269);
    set("picid", 3030);

    set_value(888);

    set_no_give(1);
}

string get_desc()
{
    return "Ma Yết là 1 trong 12 cung Hoàng Đạo";
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
