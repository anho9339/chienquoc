// 自动生成：/make/item/make33

inherit ITEM;
inherit COMBINED;

//  int get_max_combined() { return 30; }

int is_snack()
{
    return 1;
}

void create()
{
    set_name("Hạt Hướng Dương");
    set_picid_1(3323);
    set_picid_2(3323);
    set_unit("盘");
    set_value(20);
    set_amount(1);
}

string get_desc()
{
    return "Một món ăn vặt vào dịp lễ Tết";
}
