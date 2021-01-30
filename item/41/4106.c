// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

//  int get_max_combined() { return 30; }

int get_stuff_type()
{
    return 236;
}

void create()
{
    set_name("Động Vật Bì Mao");

    set_picid_1(4106);
    set_picid_2(4106);

    set_value(150);

    set_amount(1);
}

string get_desc()
{
    return "Là một thứ khiến động vật chống lạnh";
}
