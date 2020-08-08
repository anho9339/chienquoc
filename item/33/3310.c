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

void create()
{
    set_name("Thịt Bò Khô");

    set_picid_1(3310);
    set_picid_2(3310);

    set_value(1500);

    set_amount(1);

    set("level", 110);
    set("add_hp", 1600);
}

string get_desc()
{
    string desc;
    desc = "Thịt bò được đông lạnh phơi nắng và chế biến\n Trong 20s hồi phục cho người chơi 1600 điểm KH";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + desc + "\n" HIR "Yêu cầu sử dụng %d cấp", get("level"));
    else
        return sprintf(desc + "\nYêu cầu sử dụng %d cấp", get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
