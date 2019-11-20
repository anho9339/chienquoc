
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Đá Thần" );
		set_picid_1(4940);
        set_picid_2(4940);
        set_value(100000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Đá thần do nữ oa ban tặng. Một trong những đồ nâng cấp thú cưỡi.";
}
