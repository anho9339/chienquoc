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
    set_name("Trứng Kiến");

    set_picid_1(4006);
    set_picid_2(4006);

    set_value(33);

    set_amount(1);
}

string get_desc()
{
    return "Một quả trứng rất nhỏ của loài kiến\n Vật phẩm dùng để bán";
}
