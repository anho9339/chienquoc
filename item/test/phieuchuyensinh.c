
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：物品叠加上限
int get_max_combined() { return 10000; }

// 函数：构造处理
void create()
{
        set_name( "Bí Kíp Chuyển Sinh" );
        set_picid_1(9808);
        set_picid_2(9808);
        set_value(10);


        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Bí Kíp chỉ sử dụng hỗ trợ cho Chuyển Sinh \nVật phẩm không khoá \nCó thể cộng dồn 10000 cái";
}
