
inherit ITEM;
inherit COMBINED;
int get_item_color() {return 1 ;}
// 函数：构造处理
void create()
{
        set_name( "Quà" );
		set_picid_1(3301);
        set_picid_2(3301);
        set_value(30000);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Món quà nằm trong hộp tròn chưa được gói lại.";
}
