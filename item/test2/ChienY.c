
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 5000; }
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Chiến Y" );
        set_picid_1(6042);
        set_picid_2(6042);
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Nghe nói đây là cái Chiến Y quý hiếm mà \nThiên Sơn Tướng Quân (Chu Quốc) đang tìm kiếm";
}
