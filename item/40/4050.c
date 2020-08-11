// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

int get_stuff_type()
{
    return 237;
}

//  int get_max_combined() { return 30; }

void create()
{
    set_name("Mạng Nhện");

    set_picid_1(4050);
    set_picid_2(4050);

    set_value(290);

    set_amount(1);
}

string get_desc()
{
    return "Sợi tơ do con Nhện tiết ra và đan lại tạo nên\n Vật phẩm dùng để bán";
}
