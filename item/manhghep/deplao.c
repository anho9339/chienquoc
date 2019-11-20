
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 1000; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Dép Lào" );
		set_picid_1(8802);
        set_picid_2(8802);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Phiên bản nâng cấp của huyền thoại tổ ong. \n Các bô lão thời tam quốc thường đeo. \n Nay đã trở thành vũ khí lợi hại của trẻ trâu. \n (Thu thập đủ sẽ đổi được trang bị Vai vĩnh viễn)";
}
