
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Phế Liệu" );
        set_picid_1(4905);         set_picid_2(4905);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Là một phế phẩm sau khi ghép vật phẩm thất bại mà thành";
}
