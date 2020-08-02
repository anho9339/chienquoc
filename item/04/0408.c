#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_type_2()
{
    return ITEM_TYPE_2_CON_ALL;
}

int get_recover_count()
{
    return 5;
}

int is_zhongqiu()
{
    return 1;
}

void reset()
{
    if (gone_time(get_drop_time()) > 7200)  // 2小时
    {
        remove_from_scene();
        destruct(this_object());
    }
}

void create()
{
    set_name("Moon Cake");

    set_picid_1(3570);
    set_picid_2(3570);

    set_value(50);

    set_amount(1);

    set("add_hp", 350);
    set("add_mp", 400);
}

string get_desc()
{
    return "Ăn một miếng Bánh Trung Thu,nó quá sá ngon。\nCó thể giao cho Hằng Nga Tỷ Tỷ đổi quà Trung thu。\nSử Dụng "
           "trong 10 giây hồi phục 350 điểm khí huyết và 400 điểm pháp lực。";
}

int get_use_effect(object me)
{
    return "/sys/item/food"->get_use_effect(me, this_object());
}
