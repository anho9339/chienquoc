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
    return 229;
}

void create()
{
    set_name("Trái Đào");

    set_picid_1(3285);
    set_picid_2(3285);

    set_value(1050);

    set_amount(1);

    set("level", 50);
    set("add_hp", 1000);
}

string get_desc()
{
    string desc;
    desc = "Trời sinh có Mận thì phải có Đào nha\n Trong 20s giúp người chơi hồi phục 1000 điểm KH";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + desc + "\n" HIR "Yêu cầu sử dụng %d cấp", get("level"));
    else
        return sprintf(desc + "\nYêu cầu sử dụng %d cấp", get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
