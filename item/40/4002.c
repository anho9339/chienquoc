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
    set_name("Vỏ Trứng");

    set_picid_1(4002);
    set_picid_2(4002);

    set_value(30);

    set_amount(1);
}

string get_desc()
{
    return "Vỏ trứng vỡ gà con đâu ùi\n Vật phẩm dùng để bán";
}
