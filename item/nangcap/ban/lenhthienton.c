
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 500; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Lệnh Thiên Tôn" );
        set_picid_1(9541);
        set_picid_2(9541);
        set_value(100000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Lệnh bài thần có thể sai khiến ma tôn thiên địa.\nDùng để nâng cấp cánh hoặc phi phong.";
}
