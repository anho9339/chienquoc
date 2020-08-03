#include <ansi.h>
#include <effect.h>
#include <equip.h>

inherit TALISMAN;

int get_talisman_type()
{
    return 13;
}

int get_item_color()
{
    return 2;
}

int get_gender()
{
    return 1;
}

void create()
{
    set_name("Nhẫn Tình Ngưu Lang");

    set_picid_1(0908);
    set_picid_2(0908);

    set_level(1);
    set_value(1998);
    set_max_lasting(17099);

    set("ap", 30);
    set("cp", 30);
    set("hp", 120);
    set("sp", 30);

    set_no_give(1);
    //        set_no_drop(1);
    set_no_sell(1);
    set_bind(4);

    setup();
}

string get_desc()
{
    return sprintf("Gia tăng thuộc tính\n" HIC
                   "Ngưu Lang Chức Nữ đưa tặng chiếc nhẫn,bạn đạt được sức mạnh thần kỳ\nTrang bị yêu cầu：" HIR
                   "Nam Tính\n" HIB "Event Thất Tịch");
}
