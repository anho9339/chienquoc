inherit ITEM;
inherit COMBINED;

int get_item_color()
{
    return 1;
}

void create()
{
    set_name("Cúc Hoa Tửu");

    set_picid_1(3151);
    set_picid_2(3151);

    set_amount(1);

    set_value(100);
}

void reset()
{
    if (gone_time(get_drop_time()) > 3000)
    {
        remove_from_scene();
        destruct(this_object());
    }
}

string get_desc()
{
    return "Một trong bốn báu vật của Trọng Dương";
}
