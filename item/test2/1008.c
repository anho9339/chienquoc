
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 10000; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Mảnh Ghép Vương Giả" );
        set_picid_1(3028);
        set_picid_2(3028);
        set_value(10);
		set_save_2("diemnhiemvu.score",40);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi thu thập đủ 120 mảnh ghép có thể đến \nSứ Giả Hoạt Động để hợp thành Hổ ấn Bá Vương.";
}
