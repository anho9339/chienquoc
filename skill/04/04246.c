
// 暗器技能  TIPS:[PF_THROWING_AREA]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0424
#define THIS_PERFORM    04246
#define PF_START       "04246"
#define PF_NAME        "Cuồng Lôi Thuật"

#define SKILL_LEVEL     150
#define TIME_INTERVAL   3
#define SUB_MP          300 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/150*2
#define ADD_CP          100 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/150*30

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return sprintf(HIR " %s \n Võ công yêu cầu: Cấp 150\n Côn Luân tuyệt kĩ độc môn chi truyền,gọi sấm sét liên hoàn tấn công nhiều mục tiêu và có 40％ xác xuất gây choáng 2 giây.", PF_NAME);
        cur_level = (level - SKILL_LEVEL)/150 + 1;
        result = sprintf(HIY" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Pháp Lực tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Côn Luân tuyệt kĩ độc môn chi truyền,Tăng %d nội công và gọi sấm sét liên hoàn tấn công nhiều mục tiêu và có 40％ xác xuất gây choáng 2 giây.\n " HIC"Cấp tiếp theo:\n "NOR "Võ công yêu cầu: " HIR "Cấp %d " NOR "\n    Gia tăng %d nội công。",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_CP, cur_level*150+SKILL_LEVEL, ADD_CP+30 );
	return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int z, act, pf;
        int level, mp, speed;
		
        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;
	//	if (me->get_save("04246")==0) return 1;
		
        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }

/*        if( me->get_weapon_code() != THROWING ) 
        {
                printf( ECHO "使用“" PF_NAME "”得装备暗器。" );
                return 1;
        }
*/
        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                z = get_z(who);  x = get_x(who);  y = get_y(who);

//                send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
                me->set_time( "pf", time() );

                pf = 78;    // 抄自 /sys/user/fight

                if( !( act = pf / 10 ) )    // pf: [动作序号][光影序号]
                {
		        pf = 0;  act = 1 + random(3);    // 无指定动作序号，随机
	        }

                me->to_front_xy(x, y);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 70, get_d(me), getoid(who) );
        }
        else
        {
                if( !inside_screen( get_x(me), get_y(me), x, y ) ) return 1;

                z = get_z(me);
//                send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
                me->set_time( "pf", time() );

                pf = 78;    // 抄自 /sys/user/fight

                if( !( act = pf / 10 ) )    // pf: [动作序号][光影序号]
                {
		        pf = 0;  act = 1 + random(3);    // 无指定动作序号，随机
	        }

                me->to_front_xy(x, y);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 70, get_d(me), 0 );
        }

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        speed = 7 - me->get_sp()/60;
        if (speed<1) speed = 1;
        set_heart_count_2(me, speed);
        me->add_2("go_count.count2",speed);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d,%d,%d,%d", level, z, x, y ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}
/*
// 函数：法术处理
int cast_done( object me )
{
        object *char, *user, who;
        string arg;
        int z, x, y;
        int level, i, size, count, ret; 
		int add, cp;	

        if( !stringp( arg = me->get_cast_arg() ) || sscanf(arg, "%d,%d,%d,%d", level, z, x, y) != 4 ) return 1;

        char = get_scene_object(z, x, y, USER_TYPE);
//		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 51141, 1, OVER_BODY, PF_ONCE );
        send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42321, 3, OVER_BODY, PF_ONCE );
		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 25164, 1, OVER_BODY, PF_ONCE );
//		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42322, 1, OVER_BODY, PF_ONCE );

//      if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 执行成功
	if( ( level = me->get_skill(THIS_SKILL) ) < 70 )
        	char = get_range_object(z, x, y, 5, USER_TYPE) + get_range_object(z, x, y, 5, CHAR_TYPE) - ({ me });
        else
        	char = get_range_object(z, x, y, 5, USER_TYPE) + get_range_object(z, x, y, 5, CHAR_TYPE) - ({ me });

        cp = ADD_CP;    // 小心准备 me
	count = 0;
        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                if( who = char[i] ) 
                {
                	if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
                	count ++;
                	if (count<=20)
//   	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 5116, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42321, 3, OVER_BODY, PF_ONCE );
//    send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42322, 1, OVER_BODY, PF_ONCE );
//	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 25163, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 25164, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%d%w%w%d%w%c%c%w%c%c", 0x8a, getoid(me), time2(),
                get_x(me), get_y(me), getoid(who), 42511, 1, OVER_BODY  );
					ret = CHAR_FIGHT_D->cast_done(me, who, ADD_CP);
					ret += CHAR_FIGHT_D->cast_done(me, who, ADD_CP);
		        if ( who && !who->is_die() )
		        	CHAR_FIGHT_D->set_enmity(me,who,80);	
					
					if (ret>0 && who && random100()<40)
	        {	        	
//		        if (who->is_anti_effect())continue;
//        		if (who->get("anti_faint")) continue;
//			if(     get_effect(who, EFFECT_CHAR_FAINT)
//			||      get_effect(who, EFFECT_CHAR_FAINT_0) ) continue;    // 执行成功
			if(      get_effect(who, EFFECT_CHAR_FAINT_0) ) continue;
//			if (who->get_perform("02222#")) continue;
		        user = get_scene_object_2(who, USER_TYPE);
		        set_effect(who, EFFECT_CHAR_FAINT, 2);    // 小心准备 me
		        CHAR_CHAR_D->init_loop_perform(who);
		        if( get_heart_state(who) == MAGIC_STAT ) send_user( user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END );    // 结束施法动作               
		        send_user( who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD );
		        send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD );
		        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP );
			}

                }		
        return 2;    // 执行成功
}*/
int cast_done(object me, string arg)
{
        object *user, *char, who;
        int z, x, y,*xy,x0,y0,p;
        int level, mp, rate, i, size, ret;

        z = get_z(me);  x = get_x(me);  y = get_y(me);
	xy = ({});
	size=0;
	for(i=0;i<121;i++)		//发送效果
        {
        	x0 = x+random(10)-7;
        	y0 = y+random(10)-7;
        	if ( x0<=0 || y0<=0 )
        		continue;
        	p = x0*1000+y0;
        	if ( member_array(p,xy) != -1 )
        		continue;
        	xy+=({p,});
        	size++;
                send_user( get_scene_object(z, x0, y0, USER_TYPE), "%c%w%w%w%c%c%w%c%c%c", 0x4f, x0, y0, 
                        42321, 3, OVER_BODY, 25164, 1, OVER_BODY, PF_ONCE );
		if ( size>=10 )
			break;                  
        }
        char = get_range_object(z, x, y, 4, USER_TYPE) + get_range_object(z, x, y, 4, CHAR_TYPE) - ({ me });
        for( i = 0, size = sizeof(char); i < size; i ++ ) if( who = char[i] ) 
        {
                if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
                ret = CHAR_FIGHT_D->cast_done(me, who);
				ret += CHAR_FIGHT_D->cast_done(me, who);
				if (ret>0 && who && random100()<40)
	        {	        	
//		        if (who->is_anti_effect())continue;
//        		if (who->get("anti_faint")) continue;
//			if(     get_effect(who, EFFECT_CHAR_FAINT)
//			||      get_effect(who, EFFECT_CHAR_FAINT_0) ) continue;    // 执行成功
			if(      get_effect(who, EFFECT_CHAR_FAINT_0) ) continue;
//			if (who->get_perform("02222#")) continue;
		        user = get_scene_object_2(who, USER_TYPE);
		        set_effect(who, EFFECT_CHAR_FAINT, 2);    // 小心准备 me
		        CHAR_CHAR_D->init_loop_perform(who);
		        if( get_heart_state(who) == MAGIC_STAT ) send_user( user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END );    // 结束施法动作               
		        send_user( who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD );
		        send_user( user - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD );
		        send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP );
			}
        }	
/*	if( !get_effect_3(me, EFFECT_PROGRESS) ) 
	{
		me->set_attack_speed(10);
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END );
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9102, 1, UNDER_FOOT, PF_STOP );
	}*/
}
// 函数：获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数：能否使用特技
void can_perform( object me )
{
        int interval;
        string name;
        
        int speed;
        speed=7-me->get_sp()/60;
        if (speed<1) speed = 1;
     //   if (me->get_save("04246")==0) return;	
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL )
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf(" %s (Cấp %d )", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0,10,1, 70, speed, 0);
}
