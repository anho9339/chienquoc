inherit ITEM;
inherit COMBINED;

int get_item_color()
{
    return 1;
}

void create()
{
    set_name("Hồ Lô Chiêu Hợi");

    set_picid_1(4271);
    set_picid_2(4271);

    set_amount(1);

    set_value(50);
}

string get_desc()
{
    return "Hồ Lô Thần Kỳ，\nCó thể thu phục những con heo ăn trộm dưa hấu，\nHãy đem giao nó cho chủ tiệm dưa。";
}
