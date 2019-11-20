
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Diêm Vương Thương");
        set_picid_1(6892);
        set_picid_2(6892);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 32800);
        set("dp+", 2000);
        set("hp+", 5000);
        set("!%+", 10000);
        set("?%+", 10000);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(SPEAR);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Thương Pháp”";
}

//
string get_tail_desc()
{
	return "“Thần binh Nhị Lang Chân Quân, thương thân nhiệt như xí diệm”\n Khi có mục tiêu tấn công phải có tỉ lệ nhất định\n Cho kết quả hư hại có thể phát sinh của mục tiêu";		
}