#include <ansi.h>
#include <item.h>

inherit ITEM;

//int get_item_type() { return ITEM_TYPE_SPECIAL; }
int is_brand() { return 1; }
// 函数：构造处理
void create()
{
        set_name( "Hoa Hồng Tím Thất Tịch" );
        set_picid_1(0052);
        set_picid_2(0052);
        set_value(0);
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);  
//        set_amount(1);
}
// 函数：获取描述
string get_desc() 
{ 
        return "Duyên phận tín vật, nghe nói khi 2 người khác giới có tín vật này hãy mau lập tổ đội tìm tới Nguyệt lão，\nHoàn thành nv của Lão có thể nhận quà bất ngờ。"; 
}