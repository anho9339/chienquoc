#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Đuôi Rắn Neon");
        set_picid_1(9994);      
set_picid_2(9994);

        set_level(1);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
        
		set_hide(0);
        setup();

        //set_gender(1);
		set_back_type(19);
}

// 函数：获取描述
string get_desc()
{
        return "Một cái đuôi thật là hãi hùng.";
}
