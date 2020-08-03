inherit ITEM;
inherit COMBINED;

int get_item_color()
{
    return 1;
}

void create()
{
    set_name("Dưa Hấu Bá Bá");

    set_picid_1(3280);
    set_picid_2(3280);

    set_amount(1);

    set_value(50);
}

void reset()
{
    if (gone_time(get_drop_time()) > 6000)
    {
        remove_from_scene();
        destruct(this_object());
    }
}

string get_desc()
{
    return "Dưa hấu ngọt và to，\nNhưng bạn không được phép ăn nó，\n Vì đây là dưa hấu mà Bá Bá đã vất vả trồng "
           "trọt。";
}
