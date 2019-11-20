#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;


// 函数：成品编号
//int get_fin_type() { return 1527; }
int get_item_color() { return 2; }

// 函数：镶嵌识别
int get_item_type() { return ITEM_TYPE_EPPP; }

// 函数：构造处理
void create()
{
        set_name( "Thiên Khí Ngoại Kháng" );
        set_picid_1(4980);
        set_picid_2(4980);
        set_value(100);
        set("dpp2", 100);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Gia tăng cho Trang Bị Vai 100 điểm Ngoại Kháng. Tối đa 500 điểm.";
}

