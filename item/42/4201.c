// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

int is_grey()
{
    return 2;
}

//  int get_max_combined() { return 30; }

int get_stuff_type()
{
    return 194;
}

void create()
{
    set_name("Da Hổ");  // tên file "Hùng Bi"

    set_picid_1(3453);  // sai picid
    set_picid_2(3453);

    set_value(100);

    set_amount(1);
}

string get_desc()
{
    return "Là một vật khiến con hổ chống lạnh";
}
