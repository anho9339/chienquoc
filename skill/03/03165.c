
// 暗器技能  TIPS:[PF_THROWING_AREA]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0316
#define THIS_PERFORM    03165
#define PF_START       "03165"
#define PF_NAME        "Hắc Hoả Thần Long"

#define SKILL_LEVEL     150
#define TIME_INTERVAL   3
#define SUB_MP          0 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/150*2
#define SUB_YUAN        4
#define ADD_AP          100 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/150*30

// 函数:获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return sprintf(HIR " %s \n Võ công yêu cầu: Cấp 150\n Tuyệt kỹ độc môn cuối cùng của Đào Hoa Nguyên, gọi thập bát long công kích đối thủ và có 50%% gây chậm chạp.", PF_NAME);
        cur_level = (level - SKILL_LEVEL)/150 + 1;
        result = sprintf(HIY" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Pháp Lực tiêu hao: %d điểm \n Nguyên khí tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Tuyệt kỹ độc môn cuối cùng của Đào Hoa Nguyên,gia tăng %d ngoại công khi gọi thập bát long công kích đối thủ và có 50%% gây chậm chạp.\n " HIC"Cấp tiếp theo:\n "NOR "Võ công yêu cầu: " HIR "Cấp %d " NOR "\n    Gia tăng %d ngoại công.",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, SUB_YUAN, TIME_INTERVAL, ADD_AP, cur_level*150+SKILL_LEVEL, ADD_AP+30 );
	return result;
}

// 函数:命令处理
int main( object me, object who, int x, int y, string arg )
{
        int z, act, pf;
        int level, mp, speed;
		
        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;
		if (me->get_save("03165")==0) return 1;
		
        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 me

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }
		
		if( me->get_yuan() < SUB_YUAN )
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN );
                return 1;
        }
		
        if( me->get_weapon_code() != UNARMED ) 
        {
                printf( ECHO "Sử dụng \"" PF_NAME "\" phải trang bị Triển Thủ." );
                return 1;
        }

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
		me->add_yuan( -SUB_YUAN );

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

// 函数:法术处理
int cast_done( object me )
{
        object *char, who;
        string arg;
        int z, x, y;
        int level, ap, i, size, count, ret, flag;        

        if( !stringp( arg = me->get_cast_arg() ) || sscanf(arg, "%d,%d,%d,%d", level, z, x, y) != 4 ) return 1;

        char = get_scene_object(z, x, y, USER_TYPE);
//		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 51141, 1, OVER_BODY, PF_ONCE );
//        send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 5116, 1, OVER_BODY, PF_ONCE );
	//	send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42341, 3, OVER_BODY, PF_ONCE );
		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42332, 2, OVER_BODY, PF_ONCE );
		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42352, 3, OVER_BODY, PF_ONCE );
	//	send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42361, 3, OVER_BODY, PF_ONCE );
	//	send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42331, 3, OVER_BODY, PF_ONCE );
	//	send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 3642, 3, OVER_BODY, PF_ONCE );
	//	send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 9026, 6, OVER_BODY, PF_ONCE );
		send_user( char, "%c%w%w%w%c%c%c", 0x4f, x, y, 42411, 1, OVER_BODY, PF_ONCE );

//      if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 执行成功
	if( ( level = me->get_skill(THIS_SKILL) ) < 70 )
        	char = get_range_object(z, x, y, 5, USER_TYPE) + get_range_object(z, x, y, 5, CHAR_TYPE) - ({ me });
        else
        	char = get_range_object(z, x, y, 5, USER_TYPE) + get_range_object(z, x, y, 5, CHAR_TYPE) - ({ me });

        ap = ADD_AP;    // 小心准备 me
	count = 0;
        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                if( who = char[i] ) 
                {
                	if( !who->can_be_fighted(me) || !me->can_fight(who) ) continue;
                	count ++;
                	if (count<=18)
//		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42332, 1, OVER_BODY, PF_ONCE );
//        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42341, 1, OVER_BODY, PF_ONCE );
//		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 5116, 1, OVER_BODY, PF_ONCE );
	//	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42341, 3, OVER_BODY, PF_ONCE );
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42332, 2, OVER_BODY, PF_ONCE );
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42352, 3, OVER_BODY, PF_ONCE );
	//	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42361, 3, OVER_BODY, PF_ONCE );
	//	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42331, 3, OVER_BODY, PF_ONCE );
	//	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 3642, 3, OVER_BODY, PF_ONCE );
	//	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9026, 6, OVER_BODY, PF_ONCE );
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42411, 1, OVER_BODY, PF_ONCE );
		send_user( get_scene_object_2(who, USER_TYPE), "%c%d%d%w%w%d%w%c%c%w%c%c", 0x8a, getoid(me), time2(),
                get_x(me), get_y(me), getoid(who), 32531, 1, OVER_BODY  );//25161
					ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ap);
					ret += CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ap);
		        if ( who && !who->is_die() )
		        	CHAR_FIGHT_D->set_enmity(me,who,80);	
					
/*					if (ret>0)
        {
                set_effect(who, EFFECT_CHAR_BLIND, 3);    // 小心准备 me
                send_user( who, "%c%w%w%c", 0x81, 9024, 6, EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9024, 1, EFFECT_BAD );
                send_user( who, "%c%c%c", 0x3d, 243, 1);    // 玩家失明
        	
        }*/
	//		if (!who) return 1;
//        if (who->is_anti_effect()) return 1;
//        if ( !who->get("anti_slow") &&  ret>0)
//        {
//	        if(     get_effect(who, EFFECT_CHAR_SLOW)
//	        ||      get_effect(who, EFFECT_CHAR_SLOW_0) ) return 2;    // 执行成功
			if (ret>0 && who && random100()<50)
		{	
			if(     get_effect(who, EFFECT_CHAR_SLOW_0)   ) return 2;
                set_effect(who, EFFECT_CHAR_SLOW, 3);
                send_user( who, "%c%w%w%c", 0x81, 9012, get_effect_3(who, EFFECT_CHAR_SLOW), EFFECT_BAD );
                send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9012, 1, EFFECT_BAD );
                send_user(who, "%c%c%c", 0x3d, 241, 1);    // 更改走路步数
        } 
			
                }

        return 2;    // 执行成功
}

// 函数:获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数:能否使用特技
void can_perform( object me )
{
        int interval;
        string name;
        
        int speed;
        speed=7-me->get_sp()/60;
        if (speed<1) speed = 1;
        if (me->get_save("03165")==0) return;	
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
