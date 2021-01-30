#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
// inherit USABLE;

//  int get_max_combined() { return 30; }

int get_item_color()
{
    return 1;
}

// int get_item_type_2() { return ITEM_TYPE_2_PET; }

int is_pet_item()
{
    return 1;
}

void create()
{
    set_name("Ngọc Linh Dịch");

    set_picid_1(9991);
    set_picid_2(9991);

    set_value(250000);

    set_amount(1);
}

string get_desc()
{
    string desc;
    return desc =
               "Thiên Tôn Thần Thủy trong truyền thuyết\nCó thể làm cho một Bảo Thú bình thường trở thành\nBảo Thú Bảo"
               "Bảo";
}
