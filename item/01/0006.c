#include <equip.h>

inherit USABLE;
inherit ITEM;
inherit COMBINED;

int get_item_value()
{
    return 1;
}

int get_item_value_2()
{
    return 1;
}

int get_item_number()
{
    return 10001073;
}

void create()
{
    set_name("Rương Dự Trữ");

    set_picid_1(0080);
    set_picid_2(0080);

    set_value(10);
    set_amount(1);
}

string get_desc()
{
    return "Có thể thay thế Trưởng Phòng Tiên Sinh dự trữ tất cả vật phẩm, phải sau khi giao lại cho Trưởng Phòng Tiên "
           "Sinh mới có thể Hoàn thành nhiệm vụ.";
}
