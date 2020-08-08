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
    set_name("Đậu Phụ Khô");

    set_picid_1(3321);
    set_picid_2(3321);

    set_value(20);

    set_amount(1);
}

string get_desc()
{
    return "Một món ăn vặt";
}
