#include <ansi.h>
#include <equip.h>

inherit USABLE;
inherit ITEM;

int is_box()
{
    return 1;
}

int get_item_value()
{
    return 300;
}

int get_item_value_2()
{
    return 300;
}

int get_item_color()
{
    return 2;
}

void create()
{
    set_name("Hộp Đặc Biệt");

    set_picid_1(8503);
    set_picid_2(8503);

    set_level(4);
    set_value(50);
}

string get_desc()
{
    return "Một chiếc hộp dùng cho sự kiện Chìa Khóa và Hộp ( có thể dùng " HIY "Chìa Khoá Đặc Biệt " NOR " mở ra).";
}

int get_use_effect(object me)
{
    return "/item/01/0203"->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object item)
{
    int p;
    object item1;

    if (USER_INVENTORY_D->get_free_count(who) < 1)
    {
        write_user(who, ECHO "Hành trang không đủ 1 chỗ trống");
        return 0;
    }

    if (who->get_2("openbox.item"))
        return 0;

    if (who->get_online_rate() < 100)
    {
        send_user(who, "%c%s", ';', "bla bla bla");
        return 0;
    }

    send_user(who, "%c%c%c%d", 0x91, 1, 3, getoid(item));
    return 0;
}
