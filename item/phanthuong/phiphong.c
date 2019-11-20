#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Lóng Lánh Phi Phong (Xanh Lá)");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(0);
		set_bind(1);
        set_value(1000);
        set_max_lasting(21599);
      /*  set("ap+", 750);
		set("cp+", 750);
		set("dp+", 750);
        set("pp+", 750);
        set("hp+", 2550);
		set("mp+", 2550);
		set("sp+", 340);
		set("double", 500); */
		set_hide(0);
        setup();

    //    set_gender(1);
        set_back_type(1);
		set_back_color(0x1983);
}

// 函数：获取描述
string get_desc()
{
        return "Óng ánh màu sắc, không tăng chỉ số nhưng làm nhân vật thêm oai phong.";
}