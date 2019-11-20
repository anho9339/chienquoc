#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <task.h>
#include <action.h>

inherit SLAVE;

int get_max_level0() { return 3;}
int get_hair() { return 1006; }
int get_hair_color() { return 0x00FFFFE0; }
int get_photo() { return 1005; }
int get_armor_code() { return 570100; }
int get_armor_color_1() { return 0x42084208; }
int get_weapon_color() { return 0; }
int get_weapon_color_2() { return 0xfc62; }
int get_back() { return 7; }
int get_back2() { return 7; }
int get_back_color() {return 0x00FFFFE0;}
int get_back2_color() {return 0x00FFFFE0;}

void show_to_user( object who )
{
        object me = this_object(),map;
        int id = getoid(me);
        int type = 0, armor, speed = 0;
		int gender;
        if (get_invisible(me)==2 && who!=me) return;
        armor = get_armor_code();
        if( get_effect(me, EFFECT_MAGIC_4243) )
        {
        	type = get_save("pf#4243");
        	armor = type;
        	speed = 2;
        }
        else
        if ( get_effect(me, EFFECT_MAGIC_CARD) )
        {
        	type = get_save("magic_card");
        	armor = type;
        	speed = 2;
        }
        else
        if (me->get_save("temp_act"))
        {
        	type = me->get_save("temp_act");
        	armor = type;
        	speed = 2;
        }
        else
        if (me->get("temp_act"))
        {
        	type = me->get("temp_act");
        	armor = type;
        	speed = 2;
        }
        else type = get_head_code();
        if ("/sys/sys/count"->get_new_person()) type = me->get_hair();
//        if (MAIN_D->get_host_type()!=1000)
	if ("/sys/sys/count"->get_new_person())
	        send_user( who, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%c%d%s", 0x69, 10, id,
	        	get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
	        	me->get_photo(), armor, me->get_armor_color_1(), 
	        	type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(), 
	        	get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(), 
		        0, 0,
	        	get_hp_cent(), speed, 0, get_short() );
	else
	        send_user( who, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
	        	get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
		        armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
	        	get_hp_cent(), speed, 0, get_short() );

	if (!is_player(me)) send_user( who, "%c%d%d", 0x66, id, 0xff6500);
	if (me->get_id_color()) send_user( who, "%c%d%d", 0x66, id, me->get_id_color());
	if (me->get_ride()) send_user( who, "%c%d%d", 0x62, id, me->get_ride());
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9326, 1,UNDER_FOOT, PF_LOOP );
        CHAR_CHAR_D->send_loop_perform(me, who);    // 显示持续效果
        CHAR_CHAR_D->send_loop_perform_2(me, who);    // 显示持续图标
}

// 函数：列示给玩家看(新进入场景)(NPC 专用)
varargs void show_to_scene( object *user, int x, int y, int d, int add_pf, int add_pf_2 )
{
        object me = this_object(),map;
        int id = getoid(me);
        int type = 0, armor, speed = 0;
        if (get_invisible(me)==2) return;
        armor = get_armor_code();
        if( get_effect(me, EFFECT_MAGIC_4243) )
        {
        	type = get_save("pf#4243");
        	armor = type;
        	speed = 2;
        }
        else
        if ( get_effect(me, EFFECT_MAGIC_CARD) )
        {
        	type = get_save("magic_card");
        	armor = type;
        	speed = 2;
        }
        else
        if (me->get_save("temp_act"))
        {
        	type = me->get_save("temp_act");
        	armor = type;
        	speed = 2;
        }
        else
        if (me->get("temp_act"))
        {
        	type = me->get("temp_act");
        	armor = type;
        	speed = 2;
        }
        else type = get_head_code();     
        if ("/sys/sys/count"->get_new_person()) type = me->get_hair();
	if ("/sys/sys/count"->get_new_person())
        {	
		if( !add_pf )
		        send_user( user, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%c%d%s", 0x69, 10, id,
		        	get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
		        	me->get_photo(), armor, me->get_armor_color_1(), 
		        	type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(), 
		        	get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(), 
			        0, 0,
		        	get_hp_cent(), speed, 0, get_short() );        	
		else if( !add_pf_2 )
		        send_user( user, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%w%c%c%c%d%s", 0x69, 11, id,
		        	get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
		        	me->get_photo(), armor, me->get_armor_color_1(), 
		        	type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(), 
		        	get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(), 
			        0, 0,
		        	get_hp_cent(), add_pf, 1, OVER_BODY, speed, 0, get_short() );        	
		else		
		        send_user( user, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%w%c%c%w%c%c%c%d%s", 0x69, 12, id,
		        	get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
		        	me->get_photo(), armor, me->get_armor_color_1(), 
		        	type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(), 
		        	get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(), 
			        0, 0,
		        	get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, speed, 0, get_short() );        	
	}
	else
	{
		if( !add_pf )
		        send_user( user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
		                x, y, d, get_char_type(), get_char_action(),
		                armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
		                get_hp_cent(), speed, 0, get_short() );
		else if( !add_pf_2 )
		        send_user( user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%c%d%s", 0x69, 1, id,
		                x, y, d, get_char_type(), get_char_action(),
		                armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
		                get_hp_cent(), add_pf, 1, OVER_BODY, speed, 0, get_short() );
		else    send_user( user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%w%c%c%c%d%s", 0x69, 2, id,
		                x, y, d, get_char_type(), get_char_action(),
		                armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
		                get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, speed, 0, get_short() );

	}
	if (!is_player(me)) send_user( user, "%c%d%d", 0x66, id, 0xff6500);
	if (me->get_id_color()) send_user( user, "%c%d%d", 0x66, id, me->get_id_color());
	if (me->get_ride()) send_user( user, "%c%d%d", 0x62, id, me->get_ride());
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9326, 1,UNDER_FOOT, PF_LOOP );
        CHAR_CHAR_D->send_loop_perform(me, user);    // 显示持续效果
        CHAR_CHAR_D->send_loop_perform_2(me, user);    // 显示持续图标
}

// 函数：获取召唤兽类型
int get_zombie_type() { return ZOMBIE_TYPE_1; }     // 判断种类

// 函数：构造处理
void create()
{
     object me = this_object();
	 
        set_name( "Tiên Nhi" );
        set_char_picid(160);
		
	set_weapon_code(SWORD);
	
        setup();
}

// --------------------------------------------------------------- 远程调用 ----

// 函数：升级处理
void upgrade_level( int level ) { __FILE__ ->upgrade_level_callout( this_object(), level ); }

// 函数：升级处理(在线更新)
void upgrade_level_callout( object me, int level )
{
        switch( level )
        {
      default : me->set_char_type(SLAVE_TYPE_1);
                break;
       case 2 : me->set_char_type(SLAVE_TYPE_2);
                break;
       case 3 : me->set_char_type(SLAVE_TYPE_3);
                break;
        }
        me->set_attack_speed(10);
        me->set_walk_speed(2);
        me->set_walk_step(2);
}

// 函数：升级处理
void upgrade_level_2( int level ) { __FILE__ ->upgrade_level_2_callout( this_object(), level ); }

// 函数：升级处理(在线更新)
void upgrade_level_2_callout( object me, int level )
{
        object owner;
        int hp, cp, pp;

        if( level > 1 ) if( objectp( owner = me->get_owner() ) && owner->is_user() )
        {
                cp = owner->get_cp();
                pp = owner->get_pp();
                me->add_max_hp( 80 );  
                me->set_hp(me->get_max_hp());
                me->set_mp(me->get_max_mp());
                me->add_ap( 40 );
                me->add_dp( 10 );
                me->add_pp( 20 );
                me->add_sp( 20 );
        }
}

		
void do_after_attack(object who)
{
	object me = this_object();
	object * user;
	int level, level0, rate;
	level = me->get_level_2();
	level0 = me->get_level_0();
	rate = 40+ (level0-40)/150*100;
	if (random(100)<rate && !get_effect(who, EFFECT_CHAR_FAINT_0))
       {
                user = get_scene_object_2(who, USER_TYPE);
                set_effect(who, EFFECT_CHAR_FAINT, 1);    // 小心准备 me
                if( get_heart_state(who) == MAGIC_STAT ) send_user( user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END );    // 结束施法动作               
                send_user( who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD );
                send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD );
                send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP );
        }
}