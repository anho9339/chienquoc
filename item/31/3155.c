// 自动生成：/make/item/make31c

#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

//  int get_max_combined() { return 30; }

int get_item_type_2()
{
    return ITEM_TYPE_2_CON_MP;
}

void create()
{
    set_name("Đỗ Khang Tửu");

    set_picid_1(3155);
    set_picid_2(3155);

    set_value(1700);

    set_amount(1);

    set("level", 110);
    set("add_mp", 1800);
}

string get_desc()
{
    string desc;
    desc = "Một loại rượu Đỗ Khang \nTrong 20 giây hồi phục cho người chơi 1800 điểm PL";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + desc + "\n" HIR "Yêu cầu sử dụng %d cấp", get("level"));
    else
        return sprintf(desc + "\nYêu cầu sử dụng %d cấp", get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
