#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Hoàng Sa Chi Tâm");
        set_picid_1(3027);
        set_picid_2(3027);

        set_level(1);
		set_bind(1);
        set_value(500);
        set_max_lasting(35099);

         set("ap", 300);
        set("pp", 300);
        set("hp", 800);
		set("mp", 800);
	//	set("sp", 100);
		set("double", 500);
        setup();

        set_back_type(5);
		set_back_color(0x002F6B55);
}

// 函数：获取描述
string get_desc()
{
        return "Hồ lô của tiên nhân, bề ngoài trắng toát vì chứa đựng linh khí của thần tiên.";
}

