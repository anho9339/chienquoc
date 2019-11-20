
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Bá Vương Sát Thần Giả");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(0);
		set_bind(1);
        set_value(1000);
        set_max_lasting(21599);
        set("ap+", 600);
		set("cp+", 600);
		set("dp+", 600);
        set("pp+", 600);
        set("hp+", 2000);
		set("mp+", 2000);
		set("sp+", 200);
		set("double", 500);
		set_hide(0);
        setup();

     //   set_gender(1);
        set_back_type(1);
		set_back_color(0x00A09E5F);//125185250//0x00EBCE87
//		set_back_color(0xfc62);
}

// 函数：获取描述
string get_desc()
{
        return "★★★★★★";
}
