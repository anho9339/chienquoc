#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Đuôi Chong Chóng Tre");
        set_picid_1(4079);
        set_picid_2(4079);

        set_level(1);
		set_bind(1);
        set_value(1000);
        set_max_lasting(21599);       
        set("hp+", 1000);
		set("mp+", 1000);
		set("sp+", 50);
		set("double", 500);
        setup();

        //set_gender(1);
		set_back_type(21);
}

// 函数：获取描述
string get_desc()
{
        return "Một cái đuôi thật là hãi hùng.";
}
