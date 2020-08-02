inherit ITEM;
inherit LEGEND_ITEM;

void create()
{
    set_name("Linh Thạch");

    set_picid_1(4940);
    set_picid_2(4940);

    set_value(10);

    set_no_drop(1);
    set_no_get(1);
    set_no_give(1);
    set_no_sell(1);
}

string get_desc()
{
    return "Một khối tràn ngập linh khí";
}
