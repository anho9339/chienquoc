
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 10000; }
int get_item_color() {return 2 ;}
int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}
// 函数：构造处理
void create()
{
        set_name( "Hoả Phù" );
        set_picid_1(3553);
        set_picid_2(3553);
        set_value(10);
		set_save_2("diemnhiemvu.score",80);
        set_amount(1);
		set_no_give(1);
		set_no_sell(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Một chiếc Phù làm bằng vải có màu đỏ tươi. \nDùng để thuê trang bị Phi Phong và Cánh \ntại Chủ Tiền Trang ở Thiên Đàn Chu Quốc \nhoặc Chủ Tiền Trang ở Tân Thủ Thôn.";
}
