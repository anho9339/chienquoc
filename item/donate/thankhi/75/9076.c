
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Gậy Như Ý");
        set_picid_1(6850);
        set_picid_2(6850);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 32700);
        set("dp+", 2000);
        set("hp+", 5000);
        set("double", 10000);
        set("?%+", 10000);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(STICK);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Côn Pháp”";
}

//
string get_tail_desc()
{
	return "“Mạc gia chí bảo, vùng vẫy thì sẽ chuyển được càn khôn”\n Lúc đồng thời tấn công mục tiêu có tỉ lệ nhất định\n Làm cho kẻ bị tấn công bối rối 2 giây";		
}