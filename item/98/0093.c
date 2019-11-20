#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// 函数：构造处理
void create()
{
        set_name( "Lão Tửu" );
        set_picid_1(3152);
        set_picid_2(3152);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm nhiệm vụ. Áp dụng chế độ riêng để chưng cất, chôn cùng với Rượu Đế, có thể tăng cường lực."; 
}