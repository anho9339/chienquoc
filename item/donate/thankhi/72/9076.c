
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Thiên Giới Bảo Đao");
        set_picid_1(6812);
        set_picid_2(6812);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 32000);
        set("hp+", 5000);
        set("!%+", 10000);
        set("?%+", 10000);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(BLADE);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Đao Pháp”";
}

//
string get_tail_desc()
{
	return "“天宫宝库的收藏品”\n攻击目标时有一定的几率\n对目标产生200点的额外物理伤害";		
}