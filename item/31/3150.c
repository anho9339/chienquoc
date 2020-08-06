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
    return 230;
}

void create()
{
    set_name("Rượu Đế");

    set_picid_1(3150);
    set_picid_2(3150);

    set_value(650);

    set_amount(1);

    set("level", 10);
    set("add_mp", 350);
}

string get_desc()
{
    string desc;
    desc = "Một loại rượu lên men từ lúa gạo \nTrong 20 giây khôi phục cho người chơi 350 điểm PL";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + " %s \n " HIR "Yêu cầu sử dụng %d cấp", desc, get("level"));
    else
        return sprintf(" %s \n Yêu cầu sử dụng %d cấp", desc, get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
