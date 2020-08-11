// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

int get_item_color()
{
    return 0;
}

//  int get_max_combined() { return 30; }

int get_stuff_type()
{
    return 322;
}

void create()
{
    set_name("Tơ Nhện");

    set_picid_1(4037);
    set_picid_2(4037);

    set_value(225);

    set_amount(1);
}

string get_desc()
{
    return "Một loại nguyên liệu dùng để dệt vải\n Vật phẩm dùng để bán";
}
