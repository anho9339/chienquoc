// 自动生成：/make/item/make31c

#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

//  int get_max_combined() { return 30; }

int get_item_type_2()
{
    return ITEM_TYPE_2_CON_HP;
}

int get_stuff_type()
{
    return 231;
}

void create()
{
    set_name("Trái Quýt");

    set_picid_1(3282);
    set_picid_2(3282);

    set_value(400);

    set_amount(1);

    set("level", 0);
    set("add_hp", 100);
}

string get_desc()
{
    string desc;
    desc = "Anh em họ nhà Cam chua ngọt nhiều nước\n Trong 20s giúp người chơi hồi phục 100 điểm KH.";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + " %s \n " HIR "Yêu cầu sử dụng %d cấp", desc, get("level"));
    else
        return sprintf(" %s \n Yêu cầu sử dụng %d cấp", desc, get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
