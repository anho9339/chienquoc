
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：nh9h适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 3; }

// 函数：nh9h构造处理
void create()
{
        set_name("[Thần Chiến]Chân quân sí diễm thương");
        set_picid_1(6892);
        set_picid_2(6892);

        set_level(10);
        set_value(50000000);
        set_max_lasting(14099);
        set("ap+", 350);
        set("dp+", 350);
        set("hp+", 350);
        set("!%+", 3500);
        set("?%+", 100);
		set_item_color(2);	//紫色
        setup();

        set_weapon_type(SPEAR);
}

// 函数：nh9h获取武器级别
int get_weapon_level() { return 75; }

// 函数：nh9h获取描述
string get_desc()
{
        return "“Thương pháp”Trang bị";
}

//
string get_tail_desc()
{
	return "“Nhị lang chân quân chi thần binh, thương thân nhiệt như sí diễm”\nCông kích mục tiêu thời hữu nhất định kỷ suất\nCấp mục tiêu sản sinh phá giáp hiệu quả ";		
}