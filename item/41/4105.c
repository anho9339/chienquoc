// 自动生成：/make/item/make30
#include <item.h>

inherit ITEM;
inherit COMBINED;

int get_stuff_type()
{
    return 217;
}

int get_item_type_2()
{
    return ITEM_TYPE_2_STUFF;
}

//  int get_max_combined() { return 30; }

void create()
{
    set_name("Chân Gấu");

    set_picid_1(4105);
    set_picid_2(4105);

    set_value(200);

    set_amount(1);
}

string get_desc()
{
    return "Là một bộ phận trên người con gấu";
}
