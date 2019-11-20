
// ؔ֯ʺԉú/make/equip/60b

#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 1; }


// گ˽úٹլԦm
void create()
{
        set_name("Cánh thiên thần - ác quỷ (Hoàng Kim)");
        set_picid_1(100);
        set_picid_2(100);

        set_level(0);
        set_value(1000);
        set_max_lasting(2599);
        set("ap", 5);
        set("cp", 5);
        set("hp", 100);
		set("mp", 100);

        setup();
        set_back_type(8);
		set_back2_type(7);
		set_back_color(YELLOW);
		set_back2_color(YELLOW);
}

// گ˽úܱȡĨ˶
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "Là chiếc cánh có sức mạnh ghê hồn của thiên thần - ác quỷ. Đeo cho đẹp";
}
