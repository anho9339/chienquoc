// 自动生成：/make/item/make30

inherit ITEM;
inherit COMBINED;

int get_max_combined()
{
    return 30;
}

void create()
{
    set_name("Thịt Lợn Băm Nhỏ");

    set_picid_1(4218);
    set_picid_2(4218);

    set_value(50);

    set_amount(1);
}

string get_desc()
{
    return "Thịt lợn băm nhỏ để làm nhân bánh bao";
}

void reset()
{
    if (gone_time(get_drop_time()) > 2400)
    {
        remove_from_scene();
        destruct(this_object());
    }
}
