inherit BOOTS;

void create()
{
    set_name("Vấn Đồ Hài");

    set_picid_1(8802);
    set_picid_2(8802);

    set_level(0);
    set_value(10);
    set_max_lasting(2199);

    set("dp", 2);
    set("pp", 2);
    set("X@%", 5);

    setup();
}

string get_desc()
{
    return "Vấn Đồ Hài";
}
