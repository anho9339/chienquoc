
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Bá Vương Huyết Phụng Dực");
        set_picid_1(3028);
        set_picid_2(3028);

        set_level(0);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
        set("ap+", 600);
		set("cp+", 600);
		set("dp+", 600);
        set("pp+", 600);
        set("hp+", 2000);
		set("mp+", 2000);
		set("sp+", 300);
		set("double", 600);
		
		set_hide(0);
        setup();

        set_gender(2);
        set_back_type(7);
		set_back2_type(7);
		set_back_color(0x00FFFFE0);
		set_back2_color(0x00FFFFE0);
}

// 函数：获取描述
string get_desc()
{
        return "★★★★★★★★★";
}
