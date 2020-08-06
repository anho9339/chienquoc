// 自动生成：/make/item/make32a

inherit ITEM;
inherit COMBINED;

//  int get_max_combined() { return 30; }

int get_stuff_type()
{
    return 170;
}

void create()
{
    set_name("Thuốc Lá");

    set_picid_1(3250);
    set_picid_2(3250);

    set_value(20);

    set_amount(1);
}

string get_desc()
{
    return "Một loại nông sản.";
}
