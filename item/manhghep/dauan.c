
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 1000; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Dầu Ăn" );
		set_picid_1(3155);
        set_picid_2(3155);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Tương truyền sau này sẽ đổi tên thành Neptune. \n Có khả năng làm tinh thần minh mẫn và khỏe khoắn. \n Đặc biệt là giành cho nam giới. \n (Thu thập đủ sẽ đổi được trang bị Vai vĩnh viễn)";
}
