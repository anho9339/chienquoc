
inherit ITEM;
inherit COMBINED;
int get_item_color() {return 1 ;}
// 函数：构造处理
void create()
{
        set_name( "Thiệp Quốc Tế Phụ Nữ" );
		set_picid_1(3854);
        set_picid_2(3854);
        set_value(10);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Tấm thiệp quý giá cho ngày Quốc Tế Phụ Nữ \nCó trong tay thiệp này đến Thư Sinh để đổi phần thưởng.";
}
