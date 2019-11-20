
// ؔ֯ʺԉú/make/equip/60b

#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 1; }


// گ˽úٹլԦm
void create()
{
        set_name("Cánh thiên thần (Xanh)");
        set_picid_1(100);
        set_picid_2(100);

        set_level(0);
        set_value(100);
        set_max_lasting(2599);
        set("ap", 5);
        set("cp", 5);
        set("hp", 100);
		set("mp", 100);

        setup();

        set_back_type(7);
		set_back2_type(7);
		set_back_color(255);
		set_back2_color(255);
}

// گ˽úܱȡĨ˶
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{
        return "Là chiếc cánh với màu xanh tuyệt đẹp. Đeo cho đẹp.";
}
