
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Cánh Thiên Thần" );
        set_picid_1(3028);
        set_picid_2(3028);
        set_value(100000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Cánh thiên thần sa ngã làm rớt xuống nhân gian.\nDùng để nâng cấp cánh hoặc phi phong.";
}
