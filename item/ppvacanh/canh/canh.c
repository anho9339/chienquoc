#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("★ VÔ SONG Chi Dực ★");
        set_picid_1(3031);
        set_picid_2(3031);

        set_level(0);
		set_bind(1);
        set_value(1000);
        set_max_lasting(21599);
        set("ap+", 750);
		set("cp+", 750);
		set("dp+", 750);
        set("pp+", 750);
        set("hp+", 2550);
		set("mp+", 2550);
		set("sp+", 440);
		set("double", 500);
		set_hide(0);
        setup();

    //    set_gender(1);
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