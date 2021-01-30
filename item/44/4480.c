#include <ansi.h>
#include <item.h>

inherit ITEM;

//  int get_max_combined() { return 30; }

// int get_item_type_2() { return ITEM_TYPE_2_PET; }

int is_pet_item()
{
    return 1;
}

void create()
{
    set_name("Hấp Hồn Châu");

    set_picid_1(9125);
    set_picid_2(9125);

    set_value(1000);
}

string get_desc()
{
    string desc;
    return desc = "Có thể tinh luyện một loại kỹ năng của sủng vật";
}
