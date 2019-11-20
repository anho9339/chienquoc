#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <task.h>
#include <action.h>
#define _DEBUG(x)	tell_user(find_char("971"),x);

inherit BADMAN;

int flag;
int saytime,hptime,RelaxTime,pTime,pTime1,pTime2,pTime3,iRelax,i4252,i4233,i3642;
//string *nFamily = ({"Đào Hoa Nguyên","Thục Sơn","Cấm Vệ Quân","Đường Môn","Mao Sơn","Côn Luân","Vân Mộng Cốc"});
// 函数：是否不能进城
int cannot_enter_city() { return 1; }
int get_id_color() { return 0107215; }
void drop_items( object me, object who );
int is_caster() { return 1; }
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

// 函数：列示给新玩家(对方进场景)(NPC 专用)
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

// 函数：修正经验奖励
int correct_exp_bonus( int level, int level2, int exp ) { return exp; }

// 函数：修正掉宝率
int correct_drop_rate( int level ) { return 100; }

// 函数：获取人物名称
string get_short() 
{ 
	return get_name() + "||||" + PPM"Thiên Hạ Đại Tướng Quân";
}

void init_fight_status()
{
	set_ap(500);
	set_dp(3000);
	set_cp(3000);
	set_pp(3000);
	set_sp(3000);
}

// 函数：构造处理
void create()
{
	object me = this_object();
        set_name("Tuyết Nhi");
	set_fam_name("Côn Luân");
	set_skill(0421, 150);
	set_skill(0422, 150);
	set_skill(0423, 150);
	set_skill(0424, 150);
	set_skill(0425, 150);
	set_skill(0441, 150);
	set_skill(0442, 150);
	set_skill(0443, 150);
	set_skill(0444, 150);
	set_skill(0445, 150);
        set_level(150);
        set_max_hp(1000000);
        set_max_mp(1000000000);
	set_weapon_code(SWORD);
	set_weapon_color(13);
	set_double_rate(5000);
	set_double_rate_2(5000);
	set_hit_rate_2(60);
	set_skill(0104, 150);
	set_skill(0109, 150);
	set_skill(0111, 150);
	set_skill(0121, 150);
	set_skill(0131, 150);
	set_skill(0141, 150);
	set_skill(0151, 150);
	set_skill(0161, 150);
	set_skill(0202, 150);
	set_skill(0401, 150);
	set_skill(0402, 150);
	set_skill(0403, 150);
	set_skill(0404, 150);
	set_skill(0405, 150);
	set_skill(0430, 20);
	set_skill(0431, 20);
	set_skill(0432, 20);
	set_skill(0433, 20);
	set_skill(0434, 10);
	set_skill(0435, 10);
	set_skill(0436, 5);
	set_skill(0437, 20);
	set_skill(0438, 20);
	init_fight_status();
        set_walk_speed(3);
        set_attack_speed(1);
        set_max_seek(6);
        set_walk_step(2);
        set("no_sk04211",1);	//变身术对其没有效果
        set("anti_sleep",1);	//不会昏迷
        set("anti_no_move",1);	//不会冻结
		set("anti_blind",1);    //No Blind
                
        setup();
	set_char_type(FIGHTER_TYPE_2);
}

int can_fight( object who ) 
{ 
        object owner;
        string leader, id;
	if( who->is_die() )
	{
		set_enemy(0);
		return 0;
	}
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		set_enemy(0);
		return 0;
	}
	
	return ::can_fight(who);
}

int can_be_fighted( object who ) 
{ 
        object owner;
        string leader, id;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		set_enemy(0);
		return 0;
	}
	
	return ::can_be_fighted(who);
}

void heart_beat_walk()
{
	int i,x,y,z,x0,y0,z0,p,x1,y1;
	object enemy,me=this_object();

	if ( iRelax )
		return ;
	enemy = get_enemy();
	if ( objectp(enemy) )
	{		
		if ( enemy->is_die() )
			set_enemy(0);
		if ( gone_time(saytime) >=60 )
		{
			saytime = time();
			if(random(100) < 40)
			{
				SAY_CMD->say(me, "Các ngươi có nhận ra ta là ai không ? #29 "); 
			}
		}
	}
	else if ( RelaxTime == 0 )
	{
		RelaxTime = time();
	}
//	if ( RelaxTime && gone_time(RelaxTime) >= 120 )
	if ( RelaxTime && gone_time(RelaxTime) >= 2000000000 )
	{
		RelaxTime = 0;	
		init_fight_status();
		iRelax = 1;
	}
	if( !get_effect(me, EFFECT_CHAR_NO_PF_0) )		//不沉默
	{
		set_effect(me, EFFECT_CHAR_NO_PF_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_WOUND_0) )		//不负伤
	{
		set_effect(me, EFFECT_CHAR_WOUND_0, 3600);
	}	
	if( !get_effect(me, EFFECT_CHAR_FAINT_0) )		//不眩晕
	{
		set_effect(me, EFFECT_CHAR_FAINT_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_SHUT_0) )		//不囚禁
	{
		set_effect(me, EFFECT_CHAR_SHUT_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_DREAM_0) )		//不囚禁
	{
		set_effect(me, EFFECT_CHAR_DREAM_0, 3600);
	}
	if( !get_effect(me, EFFECT_CHAR_LAZY_0) )		//不延缓
	{
		set_effect(me, EFFECT_CHAR_LAZY_0, 3600);
	}
	if ( gone_time(hptime) >= 15 )
	{
		hptime = time();
		//瞬间移动
/*		if ( objectp(enemy) )
		{
			z = get_z(enemy);z0=get_z(me);
			
			if( z == z0 && (p=distance_between(me, enemy)) < 20 && p >1 )
			{
				x = get_x(enemy);y = get_y(enemy);
				x0 = get_x(me);y0 = get_y(me);
			        for( i = 0; i < 10; i ++ )
			        {
			                if( p = get_valid_xy(z, abs( x + random(3) - 1 ), abs( y + random(3) - 1 ), IS_CHAR_BLOCK) )
			                {
			                        x1 = p / 1000;  y1 = p % 1000;  break;
			                }
			        }
			        if ( x1 && y1 && z )
			        {
		                        me->add_to_scene( z, x1, y1,4,9413);
		                        me->to_front_xy(x, y);
				}
			}
			
		}*/
	}

	::heart_beat_walk();	
}
void heart_beat_attack( )
{
	::heart_beat_attack( );
	
}

// 函数：特技攻击对手
int perform_action( object who ) 
{
	int rate,x,y,z,i,size,ret,type,interval,cp;
	object me = this_object(),*char;

	if ( !who ) return 2;
	if ( who->is_die() ) return 2;
	if( distance_between(me, who) > me->get_max_seek()*3/2 ) 
	{
		return 0;	
	}
	RelaxTime = 0;
	iRelax = 0;

	if ( gone_time(i4233) > 1 )
	{
		i4233 = time();
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who),
                42331, 2, OVER_BODY, 42332, 2, OVER_BODY, PF_ONCE );

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 执行成功

        ret = CHAR_FIGHT_D->cast_done(me, who, 10 + (me->get_skill(0423) - 1)/10*8);
		ret += CHAR_FIGHT_D->cast_done(me, who, 10 + (me->get_skill(0423) - 1)/10*8);
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,90);
        if( !who ) return 1;    // 执行成功
	if (who->is_anti_effect()) return 2;

        if( get_effect(who, EFFECT_CHAR_9145) ) return 2;    // 执行成功
	
        if( ret > 0 )
        {
//        	damage = ADD_DAMAGE;
        	if (get_effect(me, EFFECT_USER_BURN))
        	{
        		if ((who->get_save("pf.burn")>1000 ) ) return 2;
        	}
                who->set_save("pf.burn", 1000);    // 小心准备 me
                char = get_scene_object_2(who, USER_TYPE);
                set_effect_2(who, EFFECT_USER_BURN, (20) / 3, 0);    // 小心准备 me
                CHAR_CHAR_D->init_loop_perform(who);
                send_user( who, "%c%w%w%c", 0x81, 9026, get_effect_3(who, EFFECT_USER_BURN), EFFECT_BAD );
                send_user( char - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9026, 1, EFFECT_BAD );
                send_user( char, "%c%d%w%c%c%c", 0x6f, getoid(who), 9026, 1, OVER_BODY, PF_LOOP );
        }
	}
	if ( gone_time(i4252) > 10 )
	{
		i4252 = time();
		char = get_scene_object_2(me, USER_TYPE);
      	CHAR_FIGHT_D->set_enmity1(me,10);
        set_effect(me, EFFECT_CHAR_MISS, 300);
        send_user( me, "%c%w%w%c", 0x81, 4252, get_effect_3(me, EFFECT_CHAR_MISS), EFFECT_GOOD );
        send_user( char - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 4252, 1, EFFECT_GOOD );
        send_user( char, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me), 
                42511, 1, OVER_BODY, 42511, 1, OVER_BODY, PF_ONCE );
		me->set_save("pf.miss", 3000);
		return 1;
	}
	if ( gone_time(pTime1) > 2 )
	{
		pTime1 = time();
		char = get_scene_object_2(me, USER_TYPE) - ({ me });
		if ( !sizeof(char) )
			return ;
		who = char[random(sizeof(char))];
		switch(random(2))
		{
		default:
			"skill/04/04235"->perform_action_npc(me, who);
			break;
		case 1:
			"skill/04/04232"->perform_action_npc(me, who);
			break;
			
		}
		return 1;	
	}
	if ( gone_time(pTime2) > 3 )
	{
		pTime2 = time();
		me->add_hp( 2000 * ( 100 + me->get_healing_rate() ) / 100 );        
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE );      
		return 1;
	}
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 10, get_d(me), getoid(who) );
        ret = CHAR_FIGHT_D->cast_done(me, who, HIT_NONE, 10 + (me->get_skill(0423) - 1)/10*8);
		ret += CHAR_FIGHT_D->cast_done(me, who, HIT_NONE, 10 + (me->get_skill(0423) - 1)/10*8);
        if (who->get("anti_faint")) return 2;
        if (ret >0 && random(100) < 30)
        {
        	if (!who) return 1;
	        if(     get_effect(who, EFFECT_CHAR_FAINT)
	        ||      get_effect(who, EFFECT_CHAR_FAINT_0) ) return 1;    // 执行成功
	        if (who->get_perform("02222#")) return 1;
                char = get_scene_object_2(who, USER_TYPE);
                set_effect(who, EFFECT_CHAR_FAINT, 3);    // 小心准备 me
                CHAR_CHAR_D->init_loop_perform(who);
                if( get_heart_state(who) == MAGIC_STAT ) send_user( char, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END );    // 结束施法动作               
                send_user( who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD );
                send_user( char - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD );
                send_user( char, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP );	        
        }
	return 1;
}


// 函数：复位处理
void reset() 
{
       
}

// --------------------------------------------------------------- 远程调用 ----

// 函数：死亡奖励
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// 函数：死亡奖励(在线更新)
void win_bonus_callout( object me, object who )
{
        object owner, *team;
        int level, level2, exp, exp2, pot, alllevel;
        int i, size, status, time, flag, kk;

        if( !objectp( who = me->get_enemy_4() ) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;

//	who->add_title("Y020");
//	who->show_title("Y020");
	
	drop_items(me,who);
	
        level = me->get_level();
        if( who->get_leader() && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
        {
                team = me->correct_bonus_team(team);
                size = sizeof(team);
        }
        else
        {
        	team = ({who});
            	size = 1;
        }

        alllevel = 0;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
        	alllevel += team[i]->get_level();
        }
	if (alllevel==0) alllevel = 1;        	        		
	exp = 1000;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
                level2 = level - team[i]->get_level();
                exp2 = exp * team[i]->get_level()/alllevel;                        
                exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;  

                if (exp2<5) exp2 = 5;
                team[i]->add_exp(exp2);
                team[i]->add_potential(1000);
			//	team[i]->add_title("Y020");
			//	team[i]->show_title("Y020");		
	}
}

// 函数：掉宝奖励
void drop_items( object me, object who )
{
	int x,y,z,p,i,rate,rate1,e1,e2,e3,e4,e5;
	string *nTmp,id,owner;
	object item,leader,item1,item2,item3,item4;
	
	z = get_z(me);  x = get_x(me);  y = get_y(me);
        id = who->get_leader();
			USER_D->user_channel(sprintf(HIY"Bằng hữu "HIC "%s"  HIY" đã đánh bại "HIG "Tuyết Nhi "HIC" ! ", who->get_name() ));
        if (!id) owner = who->get_id();
        else
        {
        	if ( leader = find_player(id ) )
        	{
        		owner = leader->get_id();
		}      
		else
			owner = who->get_id();  		
	}
        rate1 = me->correct_drop_rate( me->get_level() - who->get_level() ) * who->get_online_rate() / 100;

}

//杀死一个敌人加10000气血
void stop_fight()
{
	object enemy;
	enemy = get_enemy();
	if ( enemy && enemy->get_hp()==0 )
	{
		if ( this_object()->get("killed") >= 10 )
		{
			SAY_CMD->say(this_object(), "Yêu quá cơ #24");
		}
		else
		{
			SAY_CMD->say(this_object(), "Lại nhường ta nữa à #1");
		}
		add_hp(10000);
		this_object()->add("killed", 1);
	}
	::stop_fight();	
}

// 函数：法术处理
int cast_done_npc( object me )
{
        object who,*char;
        string arg;
        int z, x, y;
        int type, level, i, size,count;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;
	if ( sscanf(arg, "%d,%d,%d,%d 2618", level, z, x, y) == 4 )
	{
		char = get_scene_object(z, x, y, USER_TYPE);
		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 26171, 1, OVER_BODY, PF_ONCE );
		char = get_range_object(z, x, y, 3, USER_TYPE) + get_range_object(z, x, y, 3, CHAR_TYPE) - ({ me });
		for( i = 0, size = sizeof(char); i < size; i ++ ) 
			if( who = char[i] ) 
			{
				if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
				count ++;
				if (count<=1)
					send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2618, 1, OVER_BODY, PF_ONCE );
				CHAR_FIGHT_D->cast_done(me, who, HIT_NONE, 30 + (level - 40)/10*8);
				if ( who && !who->is_die() )
					CHAR_FIGHT_D->set_enmity(me,who,80);	

			}
	}
        return 2;    // 执行成功
}