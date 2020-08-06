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
    return 225;
}

void create()
{
    set_name("Dưa Hấu");

    set_picid_1(3280);
    set_picid_2(3280);

    set_value(1100);

    set_amount(1);

    set("level", 60);
    set("add_hp", 1100);
}

string get_desc()
{
    string desc;
    desc = "Một loại trái cây với lượng nước cao và thanh ngọt\n Trong 20s giúp người chơi hồi phục 1100 điểm KH";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + " %s \n " HIR "Yêu cầu sử dụng %d cấp", desc, get("level"));
    else
        return sprintf(" %s \n Yêu cầu sử dụng %d cấp", desc, get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
