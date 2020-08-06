// 自动生成：/make/item/make32a

inherit ITEM;
inherit COMBINED;

//  int get_max_combined() { return 30; }

int get_max_combined()
{
    return 10000;
}

int get_stuff_type()
{
    return 160;
}

void create()
{
    set_name("Đậu Nành");

    set_picid_1(3231);
    set_picid_2(3231);

    set_value(400);

    set_amount(1);
}

string get_desc()
{
    return "Một loại sản phảm nông nghiệp";
}
