#include <effect.h>

inherit ITEM;
inherit COMBINED;

int get_max_combined()
{
    return 10000;
}

int get_item_color()
{
    return 1;
}

void create()
{
    set_name("Hồng Cầu");

    set_picid_1(3567);
    set_picid_2(3567);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Dùng sợi tơ đỏ và đen mà đan thành cầu, dùng để đổi vật phẩm";
}
