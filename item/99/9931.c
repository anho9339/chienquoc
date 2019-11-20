
inherit GOOD;
inherit COMBINED;

int get_max_combined() { return 5; }
// 函数：构造处理
void create()
{
        set_name( "Hoa tiêu" );
        set_picid_1(9931);
        set_picid_2(9931);
        set_unit( "包" );
        set_buy_price(50);
        set_buy_range(150);
        set_sell_price(100);
        set_sell_range(400);

		set_amount(1);
        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
}

// 函数：获取国名
string get_city_name() { return "Triệu Quốc"; }

// 函数：获取描述
string get_desc()
{
        return "［thương phẩm］ đặc sản của Triệu Quốc";
}
