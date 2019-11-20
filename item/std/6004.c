#include <item.h>
#include <ansi.h>
inherit ITEM;
//inherit USABLE;   

// 函数：成品编号
int get_fin_type() { return 2328; }

// 函数：构造处理
void create()
{
        set_name( "Lăng Bao Bố" );
        set_picid_1(7104);
        set_picid_2(7104);
        set_value(1000);
        set("bag", 6);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Lăng Bao Bố \nGia tăng 6 ô cho hành trang, sau 10 ngày tự động hỏng"; 
}

// 函数：使用效果
int get_use_effect( object me ) { return "/cmd/std/bag" ->get_use_effect(me, this_object()); }
