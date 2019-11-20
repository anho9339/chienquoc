#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// 函数：构造处理
void create()
{
        set_name( "Tín Thơ" );
        set_picid_1(3855);
        set_picid_2(3855);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm nhiệm vụ. Chủ Tiệm Sữa Chữa Tân Thủ Thôn muốn giao cho Khổng Lão Đầu."; 
}