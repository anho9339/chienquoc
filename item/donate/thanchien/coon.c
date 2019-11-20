
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
        set_name("[Thần Chiến]Càn khôn vô cực côn");
        set_picid_1(6850);
        set_picid_2(6850);

        set_level(10);
        set_value(50000000);
        set_max_lasting(14099);
        set("ap+", 350);
        set("dp+", 350);
        set("hp+", 350);
        set("double", 100);
		        set("!%+", 3500);

        set("?%+", 100);
		set_item_color(2);	//紫色
        setup();

        set_weapon_type(STICK);
}

// 函数：nh9h获取武器级别
int get_weapon_level() { return 75; }

// 函数：nh9h获取描述
string get_desc()
{
        return "“Côn pháp”Trang bị";
}

//
string get_tail_desc()
{
	return "“Mặc gia chí bảo，Huy vũ khởi lai khả dĩ nữu chuyển càn khôn”\nTại công kích mục tiêu đích đồng thời hữu nhất định kỷ suất\nSử bị công kích mục tiêu sản sinh 2 giây huyễn vựng";		
}