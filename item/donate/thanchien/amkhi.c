
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

// 函数：nh9h适用门派

int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 4; }

// 函数：nh9h构造处理
void create()
{
        set_name("[Thần Chiến]Bích hoả hàn nguyệt hoàn");
        set_picid_1(7813);
        set_picid_2(7813);

        set_level(10);
        set_value(50000000);
        set_max_lasting(14099);
        set("ap+", 350);
        set("dp+", 350);
        set("pp+", 350);
        set("!%+", 3500);
        set("?%+", 350);
 	set_item_color(2);	//紫色
        setup();
        set_weapon_type(THROWING);
}

// 函数：nh9h获取武器级别
int get_weapon_level() { return 75; }

// 函数：nh9h获取描述
string get_desc()
{
        return "“Ám khí”Trang bị";
}

//
string get_tail_desc()
{
	return "“Ám sát giả chí bảo,Sát nhân ư vô hình”\nSử nhĩ dụng độc đích tổng cộng thương hại đề cao 100 điểm";	
}