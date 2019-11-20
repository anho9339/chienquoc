
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 4; }
int is_thanbinh() { return 1; }
int is_thanbinh2() { return 1; }
// 函数：构造处理
void create()
{
        set_name("Đoạt Mệnh Ma Khí");
        set_picid_1(7810);//7811
        set_picid_2(7810);//7811

        set_level(100);
		set_bind(1);
        set_value(20000);
        set_max_lasting(36099);
        set("ap+", 450);
        set("hp+", 100);
        set("!%+", 300);
        set("double", 200);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(THROWING);
}

// 函数：获取武器级别
int get_weapon_level() { return 100; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị \"Ám Khí\"";
}

//
string get_tail_desc()
{
	return "[Đặc tính]Khi tấn công có thể làm mục tiêu trúng 300 sát thương Độc Tố trong 20 giây.\n"
			"Đồng thời có tỷ lệ nhất định thi triển Ma Khí khiến tấn công\n"
			"làm mù loà 6 giây hoặc làm phá vỡ 100 phòng thủ của mục tiêu.";	
}