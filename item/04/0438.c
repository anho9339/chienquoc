#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 200; }

// 函数：构造处理
void create()
{
        set_name("战国劳动奖章");
        set_picid_1(3859);
        set_picid_2(3859);
        set_value(50);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	return "可累积后换取奖励与称号的物品，请保存好不要丢失。";    	
}