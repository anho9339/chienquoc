
// 自动生成：/make/equip/60b

#include <equip.h>
#include <effect.h>
#include <skill.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Phi Thiên Tố Quần");
        set_picid_1(6154);
        set_picid_2(6154);

        set_level(55);
        set_value(24500);
        set_max_lasting(18099);
        set("dp", 132);
        set("pp", 84);

        setup();

        set_gender(2);
        set_armor_code(24);
}

// 函数：获取描述
string get_desc()
{
        return "Phi Thiên Tố Quần";
}
void start_loop_perform( object me )
{
	CHAR_CHAR_D->init_loop_perform(me);
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 2416, 1,UNDER_FOOT, PF_LOOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 24155, 1,UNDER_FOOT, PF_LOOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}
void stop_loop_perform( object me )
{
	CHAR_CHAR_D->init_loop_perform(me);
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 2416, 1, UNDER_FOOT, PF_STOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 24155, 1, UNDER_FOOT, PF_STOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}