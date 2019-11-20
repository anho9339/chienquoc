
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 10000; }
int get_item_color() { return 2; }
int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}

// 函数：构造处理
void create()
{
        set_name( "Ngũ Hành Hồn Thạch" );
        set_picid_1(8970);
        set_picid_2(8970);
        set_value(1000);
        set_amount(1);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(0);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Bảo Thạch được tạo ra bởi thuộc tính Ngũ Hành \nNghe nói loại bảo thạch này có Linh hồn ẩn chứa bên trong \nCó thể sử dụng để đổi lấy trang bị Phi Phong và Cánh \nVật phẩm đã Khoá";
}
