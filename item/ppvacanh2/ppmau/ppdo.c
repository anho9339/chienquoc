
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 1; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Phi Phong (Đỏ)");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(0);
        set_value(100);
        set_max_lasting(2599);
          set("ap", 5);
        set("cp", 5);     
        set("mp", 100);
        set("hp", 100);
        setup();
      
        set_back_type(1);
		set_back_color(0x6186);
}

// 函数：获取描述
string get_desc()
{
        return "Là chiếc pp màu Đỏ tuyệt đẹp. Đeo cho đẹp.";
}

