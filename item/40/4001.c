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
    set_name("Lông Vũ");

    set_picid_1(4001);
    set_picid_2(4001);

    set_value(30);

    set_amount(1);
}

string get_desc()
{
    return "Loại lông nhẹ nhiều màu sắc\n Vật phẩm dùng để bán";
}
