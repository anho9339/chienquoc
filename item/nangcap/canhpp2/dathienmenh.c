
#include <item.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 5000; }
// 函数：原料颜色
int get_item_color() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Đá Thiên Mệnh");
        set_picid_1(9811);
        set_picid_2(9811);
         set_value(300);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Đá do ngàn kiếp luyện thành, có khả năng nhìn xuyên vận mệnh. Dùng để nâng cấp Thần Phong và Thần Dực."; 
}
