// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

int get_max_combined()
{
    return 30;
}

void create()
{
    set_name("Liễu Thảo");

    set_picid_1(3250);
    set_picid_2(3250);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Một loại lá cây dùng để gói bánh";
}

void reset()
{
    if (gone_time(get_drop_time()) > 2400)
    {
        remove_from_scene();
        destruct(this_object());
    }
}
