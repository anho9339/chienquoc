
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 10000; }
int get_item_color() {return 1 ;}
// 函数：构造处理
void create()
{
        set_name( "Nước Ngọt" );
        set_picid_1(4255);
        set_picid_2(4255);
        set_value(10000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Loại thuỷ dược cần thiết để trồng Hoa Hồng.";
}
