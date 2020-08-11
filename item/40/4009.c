// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

int get_item_color()
{
    return 0;
}

//  int get_max_combined() { return 30; }

void create()
{
    set_name("Râu Kiến");

    set_picid_1(4009);
    set_picid_2(4009);

    set_value(52);

    set_amount(1);
}

string get_desc()
{
    return "Một bộ phận của con kiến\n Vật phẩm dùng để bán";
}
