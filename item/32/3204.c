// 自动生成：/make/item/make32a

inherit ITEM;
inherit COMBINED;

//  int get_max_combined() { return 30; }

int get_stuff_type()
{
    return 145;
}

void create()
{
    set_name("Gạo Kê");

    set_picid_1(3204);
    set_picid_2(3204);

    set_value(100);

    set_amount(1);
}

string get_desc()
{
    return "Một loại nông sản.";
}
