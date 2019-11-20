
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 4; }

// 函数：构造处理
void create()
{
        set_name("Tiên Long Ám Khí");
        set_picid_1(7813);
        set_picid_2(7813);

        set_level(100);
		set_bind(1);
        set_value(20000);
        set_max_lasting(16099);
        set("ap+", 40000);
        set("hp+", 10000);
        set("!%+", 30000);
        set("double", 20000);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(THROWING);
}

// 函数：获取武器级别
int get_weapon_level() { return 100; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “ám khí”";
}

//
string get_tail_desc()
{
	return "【Đặc tính】Khi tân công co thê lam muc tiêu trung 300 sat thương Đôc Tô trong 20 giây.";	
}