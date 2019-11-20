
inherit GOOD;
inherit COMBINED;

int get_max_combined() { return 5; }
// 函数：构造处理
void create()
{
        set_name( "Thạch tài" );
        set_picid_1(9952);
        set_picid_2(9952);
        set_unit( "包" );
        set_buy_price(500);
        set_buy_range(500);
        set_sell_price(500);
        set_sell_range(1000);

		set_amount(1);
        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// 函数：获取国名
string get_city_name() { return "Tần Quốc"; }

// 函数：获取描述
string get_desc()
{
        return "［thương phẩm］ đặc sản của Tần Quốc";
}
