
inherit ITEM;

// 函数：构造处理
void create()
{
        set_name( "铁矿" );
        set_picid_1(9534);
        set_picid_2(9534);
        set_unit( "块" );
        set_value(100);
}

// 函数：获取描述
string get_desc() 
{ 
        return "矿产的一种"; 
}
