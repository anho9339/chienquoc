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
    set_name("Cánh Bọ Ngựa");

    set_picid_1(4012);
    set_picid_2(4012);

    set_value(100);

    set_amount(1);
}

string get_desc()
{
    return "Một bộ phận của Bọ Ngựa\n Vật phẩm dùng để bán";
}
