#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <time.h>
#include <equip.h>
inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}
int is_nangcap() {return 1;}
inherit BACK;
// 函数：构造处理
void create()
{
        set_name("Xí Nhiệt Phi Phong");
        set_picid_1(3021);
        set_picid_2(3021);

        set_level(1);
		set_bind(1);
        set_value(1000);
		set_save("qsvst",1500);
        set_max_lasting(21599);
        set("ap", 300);
        set("pp", 300);
        set("hp", 800);
		set("mp", 800);
	//	set("sp", 100);
		set("double", 500);

        setup();

        set_gender(2);
        set_back_type(1);
		set_back_color(2550255);//0xaaaaa
}

// 函数：获取描述
string get_desc()
{
        return "Áo choàng nữ anh hùng không kém đấng mày râu, mặc áo choàng này lên, sẽ hiện rõ khí chất anh hùng.";
}

/*
void start_loop_perform(object me)
{
		CHAR_CHAR_D->init_loop_perform(me);
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 40812, 1,UNDER_FOOT, PF_LOOP );
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 59111, 1,UNDER_FOOT, PF_LOOP );
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 95619, 1,UNDER_FOOT, PF_LOOP );
	//	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	}
	
void stop_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 40812, 1, UNDER_FOOT, PF_STOP );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 59111, 1, UNDER_FOOT, PF_STOP );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 95619, 1, UNDER_FOOT, PF_STOP );
//	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));	
}
*/