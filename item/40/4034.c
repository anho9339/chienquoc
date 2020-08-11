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
    set_name("Tứ Giả Di Vật");

    set_picid_1(4034);
    set_picid_2(4034);

    set_value(251);

    set_amount(1);
}

string get_desc()
{
    return "Vật phẩm của người chết để lại\n Vật phẩm dùng để bán";
}
