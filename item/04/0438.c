#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 200; }

// 函数：构造处理
void create()
{
        set_name("Huân Chương Lao Động Chiến Quốc");
        set_picid_1(3859);
        set_picid_2(3859);
        set_value(50);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	return " Có thể đổi được các phần thưởng vật phẩm và danh hiệu sau khi tích lũy, vui lòng giữ lại đừng để mất。";    	
}