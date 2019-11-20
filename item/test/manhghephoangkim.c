
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Mảnh Ghép Hoàng Kim" );
        set_picid_1(8000);
        set_picid_2(8000);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi thu thập đủ số lượng mảnh ghép có thể đến \nNPC Hợp Thành Vật Phẩm để hợp thành vật phẩm.";
}
