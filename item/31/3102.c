
// 自动生成：/make/item/make31a

inherit ITEM;
    inherit COMBINED;

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：构造处理
void create()
{
        set_name("Lục Trà");
        set_picid_1(3102);
        set_picid_2(3102);
        set_unit("包");
        set_value(20);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Một loại trà."; 
}
