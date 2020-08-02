inherit BOOTS;

void create()
{
    set_name("Kim Ti Hài");

    set_picid_1(8812);
    set_picid_2(8812);

    set_level(0);
    set_value(0);
    set_max_lasting(1099);

    set("dp", 3);
    set("pp", 3);
    set("sp", 15);

    setup();
}

string get_desc()
{
    return "Kim Ti Hài";
}
