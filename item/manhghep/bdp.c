
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 1000; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "MG Bảo Để Phù" );
		set_picid_1(3454);
        set_picid_2(3454);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Nghe nói thu thập đủ 50 cái sẽ có cơ hội nhận được Bảo Để Phù. \n (Thu thập đủ sẽ có 80% tỉ lệ đổi ra Bảo Để Phù tại Phàm Chân - Chu)";
}
