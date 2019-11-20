#include <effect.h>
#include <skill.h>

inherit TALISMAN;

int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}
int get_item_color() {return 2 ;}

// 函数：生效几率
int get_active_rate() { return 30; }

// 函数：法宝识别
int get_talisman_type() { return 3; }

// 函数：构造处理
void create()
{
        set_name( "Nhiếp Hồn Linh Vương" );
        set_picid_1(9521);
        set_picid_2(9521);
        set_unit( "口" );

        set_level(2);
        set_value(1000);
        set_max_lasting(180099);

		set("ap", 400);
		set("dp", 200);
        set("pp", 200);
        set("hp", 600);

        setup();
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi trang bị Pháp Bảo này, các đòn tấn công\nngoại công có tỷ lệ làm choáng đối phương.";
}

void start_loop_perform( object me )
{
	CHAR_CHAR_D->init_loop_perform(me);
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9325, 1,UNDER_FOOT, PF_LOOP );
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 21152, 1,UNDER_FOOT, PF_LOOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41341, 1,UNDER_FOOT, PF_LOOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41100, 1,UNDER_FOOT, PF_LOOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42100, 1,UNDER_FOOT, PF_LOOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}
void stop_loop_perform( object me )
{
	CHAR_CHAR_D->init_loop_perform(me);
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9325, 1, UNDER_FOOT, PF_STOP );
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 21152, 1, UNDER_FOOT, PF_STOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41341, 1, UNDER_FOOT, PF_STOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41100, 1, UNDER_FOOT, PF_STOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42100, 1, UNDER_FOOT, PF_STOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}
