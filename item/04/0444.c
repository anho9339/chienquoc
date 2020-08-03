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
    set_name("Lam Cầu");

    set_picid_1(3566);
    set_picid_2(3566);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Dùng sợi tơ lam và trắng mà đan thành cầu, dùng để đổi vật phẩm";
}
