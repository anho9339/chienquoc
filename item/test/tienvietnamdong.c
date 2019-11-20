
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 10000; }
int get_item_color() { return 2; }
int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}

// 函数：构造处理
void create()
{
        set_name( "Tiền Việt Nam Đồng" );
        set_picid_1(0001);
        set_picid_2(0001);
        set_value(1000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Tiền Việt Nam Đồng \n một đồng tiền xu tương ứng 1000 Việt Nam đồng";
}
