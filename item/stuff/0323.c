#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit "/inh/item/diamond";
inherit COMBINED;

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_DIAMOND_4; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// 函数：原料类型
int get_stuff_type() { return 323; }

// 函数：构造处理
void create()
{
        set_name("Âu Dã Bảo Thạch");
        set_picid_1(8969);
        set_picid_2(8969);
        set_value(100);
		set_save("knb",10);
        set_amount(1);
}

string get_loop_desc(object me)
{
	return "";
}

// 函数：获取描述
string get_desc() 
{
	return "Truyền thuyết âu dã tạo vũ khí sử dụng bảo thạch";
}

