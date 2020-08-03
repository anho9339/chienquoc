// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

int get_max_combined()
{
    return 30;
}

void create()
{
    set_name("Bột Gạo Nếp Nước");

    set_picid_1(3204);
    set_picid_2(3204);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Sử dụng để làm bánh bao gạo nếp dẻo thơm ngon";
}

void reset()
{
    if (gone_time(get_drop_time()) > 2400)
    {
        remove_from_scene();
        destruct(this_object());
    }
}
