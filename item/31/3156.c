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
    set_name("Nữ Nhi Hồng");

    set_picid_1(3156);
    set_picid_2(3156);

    set_value(2000);

    set_amount(1);

    set("level", 130);
    set("add_mp", 2000);
}

string get_desc()
{
    string desc;
    desc = "Một loại rượu thượng hạng \nTrong 20 giây hồi phục cho người chơi 2000 điểm PL";

    if (this_player()->get_level() < this_object()->get("level"))
        return sprintf(HIR + desc + "\n" HIR "Yêu cầu sử dụng %d cấp", get("level"));
    else
        return sprintf(desc + "\nYêu cầu sử dụng %d cấp", get("level"));
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
