#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;

int is_zhongqiu()
{
    return 1;
}

void create()
{
    set_name("Thỏ Ngọc");

    set_picid_1(3569);
    set_picid_2(3569);

    set_value(100);

    set_amount(1);

    set_no_give(0);
    set_no_drop(0);
    set_no_sell(0);
}

string get_desc()
{
    return "Đây là Thỏ Ngọc trên thiên đình, bắt mang về chu cho Hằng Nga để đổi thưởng.";
}
