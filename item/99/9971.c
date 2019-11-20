
inherit GOOD;
inherit COMBINED;

int get_max_combined() { return 5; }
// 函数：构造处理
void create()
{
        set_name( "Hạt dẻ" );
        set_picid_1(9971);
        set_picid_2(9971);
        set_unit( "包" );
        set_buy_price(15);
        set_buy_range(85);
        set_sell_price(30);
        set_sell_range(170);

		set_amount(1);
        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// 函数：获取国名
string get_city_name() { return "Yên Quốc"; }

// 函数：获取描述
string get_desc()
{
        return "［thương phẩm］ đặc sản của Yên Quốc";
}
