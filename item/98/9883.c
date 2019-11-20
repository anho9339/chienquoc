#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;
int is_tieqiu() { return 1;}

// 函数：构造处理
void create()
{
        set_name( "Xẻng" );
        set_picid_1(3401);
        set_picid_2(3401);
        set_unit( "把" );
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm nhiệm vụ. Một loại nông cụ thô xơ."; 
}