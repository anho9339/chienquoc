
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 10000; }
int get_item_value() {return 20 ;}
int get_item_value_2() {return 10 ;}
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Thư Chúc Phúc" );
        set_picid_1(3855);
        set_picid_2(3855);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Lá thư chúc phúc mang đấy ý nghĩa đến thầy, cô nhân dịp ngày Nhà giáo 20/11.";
}
