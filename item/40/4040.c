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
    set_name("Khoen Mũi");

    set_picid_1(4040);
    set_picid_2(4040);

    set_value(225);

    set_amount(1);
}

string get_desc()
{
    return "Vật phẩm dùng để thuần hóa động vật\n Vật phẩm dùng để bán";
}
