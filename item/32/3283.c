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
    return 228;
}

void create()
{
    set_name("Trái Táo");

    set_picid_1(3283);
    set_picid_2(3283);

    set_value(800);

    set_amount(1);

    set("level", 20);
    set("add_hp", 400);
}

string get_desc()
{
    string desc;
    desc = "Hương vị giòn giòn ngọt lịm tan trong miệng\n Trong 20s giúp người chơi hồi phục 400 điểm KH.";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + " %s \n " HIR "Yêu cầu sử dụng %d cấp", desc, get("level"));
    else
        return sprintf(" %s \n Yêu cầu sử dụng %d cấp", desc, get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
