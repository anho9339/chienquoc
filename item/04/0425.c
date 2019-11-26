inherit ITEM;

// 函数：构造处理
void create()
{
        set_name("Hạt chocolate");
        set_picid_1(9971);
        set_picid_2(9971);
        set_unit("粒");
        set_value(10);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// 函数：获取描述
string get_desc() 
{ 
        return "Hạt chocolate tốt, có thể được sử dụng để làm sô cô la。";
}
