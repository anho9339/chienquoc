
// 自动生成：/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 1 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "cp"; }

// 宝石打造的辩别标志
string get_diamond_index() {return "5";}

// 函数：宝石精炼装备最高级别
int get_mix_level() { return 20; }

// 函数：构造处理
void create()
{
        set_name("Hỏa Tinh Thạch");
        set_picid_1(8984);
        set_picid_2(8984);
        set_unit("块");
        set_value(50);
        set_level(1);
        set_no_give(1);
        set_no_sell(1); 
}

int get_diamond_add()
{
	int value, level;
	object me = this_object();
	level = me->get_level();
	switch(level)
	{
	default:
		value = 17;
		break;	
	case 2:
		value = 22;
		break;	
	case 3:
		value = 27;
		break;	
	case 4:
		value = 32;
		break;			
	}
	return value;	
}

// 函数：获取描述
string get_desc() 
{ 
	object me = this_object();
	if (!clonep(me)) return "[Tinh luyện] Nội công\n[Trang bị thích hợp] Vũ khí, Hạng Liên cấp 20 trở xuống.";
        return sprintf("[Tinh luyện] Nội công %+d\n[Trang bị thích hợp] Vũ khí, Hạng Liên cấp 20 trở xuống.", me->get_diamond_add()); 
}

string get_name()
{
	object me = this_object();
	if (!clonep(me)) return "Tân Thủ Hỏa Tinh Thạch";
	return sprintf("Tân Thủ Hỏa Tinh Thạch cấp %d", me->get_level());
}