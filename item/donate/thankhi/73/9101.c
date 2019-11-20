
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 9; }

// 函数：构造处理
void create()
{
        set_name("Ỷ Thiên Bảo Kiếm - Sức Mạnh Vô Song");
        set_picid_1(6872);
        set_picid_2(6872);

        set_level(100);
		set_bind(1);
        set_value(20000);
        set_max_lasting(16099);
        set("cp+", 45000);
        set("hp+", 10000);
        set("double", 20000);
        set("?%+", 20000);
	set_item_color(3);	//紫色
        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return 100; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Kiếm Pháp”";
}

//
string get_tail_desc()
{
	return "【Đặc tính】Tăng sat thương pháp thuật 50-100 hoặc tăng hiệu quả trị liệu y thuật.";		
}