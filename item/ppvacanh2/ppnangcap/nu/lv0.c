#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}
inherit BACK;
// 函数：构造处理
void create()
{
        set_name("Xí Nhiệt Phi Phong");
        set_picid_1(3021);
        set_picid_2(3021);

        set_level(1);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
        set("ap+", 300);
        set("pp+", 300);
        set("hp+", 800);
		set("mp+", 800);
		set("sp+", 100);
		set("double", 500);

        setup();

        set_gender(2);
        set_back_type(1);
		set_back_color(0xaaaaa);
}

// 函数：获取描述
string get_desc()
{
        return "Áo choàng nữ anh hùng không kém đấng mày râu, mặc áo choàng này lên, sẽ hiện rõ khí chất anh hùng.";
}
