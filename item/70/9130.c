
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：适用门派
int get_family() { return 1; }
int is_thanbinh() { return 1; }
int is_thanbinh1() { return 1; }
// 函数：构造处理
void create()
{
        set_name("Trụ Thiên Quyền Thủ");
        set_picid_1(6827);
        set_picid_2(6827);

        set_level(100);
		set_bind(1);
        set_value(20000);
        set_max_lasting(36099);
        set("ap+", 480);
        set("hp+", 100);
        set("double", 200);
        set("!%+", 300);
 	set_item_color(3);	//紫色
        setup();

        set_weapon_type(UNARMED);
}

// 函数：获取武器级别
int get_weapon_level() { return 100; }

// 函数：获取描述
string get_desc()
{
        return "Trang bị \"Quyền Pháp\"";
}

//
string get_tail_desc()
{
	return "[Đặc tính]Khi bị tấn công có xác xuất 10% tạo ra Linh giáp hộ thể.\n"
			"Đồng thời có tỷ lệ nhất định thi triển Cuồng Tâm khiến tấn công\n"
			"làm choáng 3 giây hoặc làm phá vỡ 300 phòng thủ của mục tiêu.";	
}