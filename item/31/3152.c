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

int get_stuff_type()
{
    return 233;
}

void create()
{
    set_name("Lão Tửu");

    set_picid_1(3152);
    set_picid_2(3152);

    set_value(1150);

    set_amount(1);

    set("level", 50);
    set("add_mp", 1000);
}

string get_desc()
{
    string desc;
    desc = "Một loại rượu đế của Nông dân \nTrong 20 giây hồi phục cho người chơi 1000 điểm PL";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + desc + "\n" HIR "Yêu cầu sử dụng %d cấp", get("level"));
    else
        return sprintf(desc + "\nYêu cầu sử dụng %d cấp", get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
