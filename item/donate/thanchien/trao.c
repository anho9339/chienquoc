
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：nh9h适用门派
int get_family() { return 1; }

// 函数：nh9h构造处理
void create()
{
        set_name("[Thần Chiến]Anh kiệt quyền nhẫn");
        set_picid_1(6833);
        set_picid_2(6833);

        set_level(10);
        set_value(50000000);
        set_max_lasting(14099);
        set("ap+", 350);
        set("dp+", 350);
        set("pp+", 350);
        set("!%+", 3500);
        set("?%+", 100);
 	set_item_color(2);	//紫色
        setup();

        set_weapon_type(UNARMED);
}

// 函数：nh9h获取武器级别
int get_weapon_level() { return 75; }

// 函数：nh9h获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "“Quyền pháp”Trang bị";
}

//
string get_tail_desc()
{
	return "“Lịch đại anh kiệt sở lưu truyền chí kim chi vũ khí”\nĐương nhĩ tại bị công kích hậu hữu nhất định\nĐích kỷ suất cấp dư tự kỷ nhất cá linh khí giáp";	
}