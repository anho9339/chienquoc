
// 自动生成：/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>
#include <ansi.h>
inherit ARMOR;
//套装组件标志
int is_suit()	{ return 1;}	
//第几套
int get_equip_serial() { return 1; }	//第几套
// 函数：适用门派
int get_family() { return 5; }
//套装名字
string get_suit_name() { return "Tu Sĩ"; }	//属于某某套装
// 函数：构造处理
void create()
{
        set_name("Huyết Long - Tu Sĩ Phục");
        set_picid_1(6142);
        set_picid_2(6142);

        set_level(105);
        set_value(15000);
        set_max_lasting(20099);
        set("ap+", 0);
        set("dp+", 148);
        set("cp+", 0);
        set("pp+", 282);
        set("sp+", 0);
        set("hp+", 135);
        set("mp+", 192);
	set_item_color(5);	
	set_bind(3);		
	set_hide(0);	
        setup();
}

// 函数：获取描述
string get_desc()
{
        return HIR"Huyết Long Set";
}

// 函数：获取套装描述
string get_suit_desc()
{
        return "Trang bị Huyết Long - Tu Sĩ";
}

