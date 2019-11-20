
inherit ITEM;

int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Cờ Hiệu Vô Song Thành" );
		set_picid_1(4985);
        set_picid_2(4985);
        set_value(10);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Nắm giữ trong tay Cờ hiệu này, có thể tiến vào Vô Song Cung \ngiao cho Quan Viên Vô Song Thành để chiếm lấy Vô Song Thành.";
}
