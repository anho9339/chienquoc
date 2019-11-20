
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Ngọc Tiên Đế" );
        set_picid_1(4952);
        set_picid_2(4952);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Ngọc bội do tiên đế đánh rơi xuống trần gian.\nDùng để nâng cấp cánh hoặc phi phong.";
}
