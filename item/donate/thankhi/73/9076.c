
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 9; }

// 函数：构造处理
void create()
{
        set_name("Thần Kiếm Uy Võ");
        set_picid_1(6872);
        set_picid_2(6872);

        set_level(75);
        set_value(20000);
        set_max_lasting(14099);
        set("ap+", 19000);
        set("cp+", 38000);
        set("dp+", 1500);
        set("hp+", 5000);
        set("double", 10000);
        set("?%+", 10000);
	set_item_color(3);	//紫色
        setup();

        set_weapon_type(SWORD);
}

// 函数：获取武器级别
int get_weapon_level() { return 75; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị “Kiếm Pháp”";
}

//
string get_tail_desc()
{
	return "“Pháp Thuật bảo kiếm mà Thái Thượng Ngọc Thần sử dụng”\n Kết quả làm tổn hại\n và kết quả Trị Liệu bệnh trong quá trình nâng cấp bảo kiếm, nhiều nhất là 50 điểm";		
}