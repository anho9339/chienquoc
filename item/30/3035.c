#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}
inherit BACK;
// 函数：构造处理
void create()
{
        set_name("Vạn Ác Chi Dực - Xanh Đậm");
        set_picid_1(3035);
        set_picid_2(3035);

        set_level(1);
		set_bind(1);
        set_value(1000);
		set_save("qsvst",1200);
        set_max_lasting(21599);
        set("cp+", 300);
        set("dp+", 300);
        set("hp+", 800);
		set("mp+", 800);
		set("sp+", 100);
	//	set("double", 500);

        setup();

    //    set_gender(1);
        set_back_type(8);
		set_back2_type(8);
		set_back_color(0x002F6B55);
		set_back2_color(0x002F6B55);
}

// 函数：获取描述
string get_desc()
{
        return "Vạn Ác chi dực do Nha Ác Vu Sư chế tạo, hiệu quả bất ngờ khi sử dụng.";
}
