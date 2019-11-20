
inherit ITEM;
inherit LEGEND_ITEM;
// 函数：构造处理
void create()
{
        set_name("Linh Thạch");
        set_picid_1(4940);
        set_picid_2(4940);
        set_unit("块");
        set_value(10);
        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
        set_no_sell(1);        
}

// 函数：获取描述
string get_desc() 
{ 
        return "Một khối tràn ngập linh khí";
}
