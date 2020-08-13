
// 自动生成：/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_2; }

// 函数：宝石属性
string get_diamond_type() { return "ap"; }

// 函数：构造处理
void create()
{
        set_name("Tàn khuyết bạch tinh thạch");
        set_picid_1(8905);
        set_picid_2(8905);
        set_unit("块");
        set_value(20000);
        set_bonus_value(8000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "[ bảo thạch hợp thành tài liêu ] Gia Tăng CK"; 
}

// 函数：生成宝石文件
string get_diamond_file()
{
        return __DIR__ "8955";
}
