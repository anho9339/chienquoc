
// 单体远程技能  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0414
#define THIS_PERFORM    04145
#define PF_START       "04145"
#define PF_TIME        "04145#"
#define PF_NAME        "Thực Tâm"

#define SKILL_LEVEL     22
#define TIME_INTERVAL   2
#define SUB_MP          ( 20 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 10 )
#define ADD_EFFECT     	( 300 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 10 * 200 )
#define ADD_INTERVAL    20

// 函数:获取符法效果
int get_cast_seal() { return 9103; }    // 符纸逆旋

// 函数:获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n Võ công yêu cầu: 22 cấp\    Tà thuật ăn mòn thân thể, làm cho đối thủ liên tục trong vòng 20 giây mất đi 300 điểm Khí Huyết.";
        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Pháp Lực tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Tà thuật ăn mòn thân thể, làm cho đối thủ liên tục trong vòng 20 giây mất đi %d điểm Khí Huyết.\n " HIC"Cấp tiếp theo:\n "NOR"Võ công yêu cầu: " HIR "Cấp %d " NOR"\n    Làm cho đối thủ liên tục trong vòng 20 giây mất đi %d điểm Khí Huyết. ",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*10+SKILL_LEVEL, ADD_EFFECT + 200 );
	return result;
}

// 函数:获取描述(持续)
string get_loop_desc( object me )
{
        if( get_effect(me, EFFECT_CHAR_FALL ) )
                return sprintf( PF_NAME ":\n　　Mỗi 2 giây mất đi %d điểm Khí Huyết.\n", me->get("pf.fall") );
        else    return sprintf( PF_NAME "\n" );
}

// 函数:命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user;
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }

        if( who )
        {
                if( !inside_screen_2(me, who) ) return 1;

                x = get_x(who);  y = get_y(who);
        }
        else if( objectp( who = me->get_enemy_2() ) && inside_screen_2(me, who) )
        {
                x = get_x(who);  y = get_y(who);
        }
        else
        {
                z = get_z(me);

                if( !inside_screen( get_x(me), get_y(me), x, y ) ) return 1;
                if( !objectp( who = get_xy_object(z, x, y, CHAR_TYPE) ) && !objectp( who = get_xy_object(z, x, y, USER_TYPE) ) ) 
                {
                        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
                        me->set_time( "pf", time() );

                        me->to_front_xy(x, y);
                        user = get_scene_object_2(me, USER_TYPE);
                        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
                        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

                        me->add_mp(-mp);

                        set_heart_state(me, MAGIC_STAT);
                        set_heart_count_2(me, 5);
                        me->add_2("go_count.count2",5);
                        me->set_cast_file(__FILE__);
                        me->set_cast_arg( sprintf( "%d,%d,%d", z, x, y ) );
			send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        		me->set_perform( PF_START, time() );
                        return 1;
                }
        }

        if( me == who )
        {
                printf( ECHO "Chính mình không thể sử dụng \"" PF_NAME "\"." );
                return 1;
        }
        if( !who->can_be_fighted(me) || !me->can_fight(who) )
        {
                printf( ECHO "Chỉ đối với đối phương mới có thể sử dụng \"" PF_NAME "\"." );
                return 1;
        }
	if (who->is_anti_effect()) return 2;
	if (who->get("anti_curse")) return 2;
        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // 远程目标锁定

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// 函数:法术处理
int cast_done( object me )
{
        object *user, who;
        string arg;
        int z, x, y;
        int level, ret, flag=0, damage;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                send_user( get_scene_object(z, x, y, USER_TYPE), "%c%w%w%w%c%c%w%c%c%c", 0x4f, x, y, 
                        41451, 1, OVER_BODY, 41452, 1, OVER_BODY, PF_ONCE );

                return 1;    // 打到空地
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                41451, 1, OVER_BODY, 41452, 1, OVER_BODY, PF_ONCE );

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 以下为附加效果！

        if( get_effect(who, EFFECT_CHAR_HALFGOD) ) return 2;    // 处于神打状态下不成功
        
        if (get_effect_3(who, EFFECT_CHAR_ARMORFALL)) flag += 1;
        if (get_effect_3(who, EFFECT_MP_FALL)) flag += 1;
        if (get_effect_3(who, EFFECT_CHAR_POWERFALL)) flag += 1;                      
//        if (flag>=2) return 2;        
        damage = ADD_EFFECT;
        if (-who->get("pf.fall")>damage/10) return 2;     
        if( !who->get_max_damage() && who->get_action_mode()==1 ) who->init_enemy_damage(me, damage);
        else
        if( damage >= who->get_max_damage() && who->get_action_mode()!=0 ) who->init_enemy_damage(me, damage);    // 记录最强伤害(NPC)   
        if( who->get_enemy_4() == me )
                who->set_attack_time( time() );    // 同一个人:更新持续时间
        else if( gone_time( who->get_attack_time() ) > 12 )
        {
                who->set_enemy_4(me);
                who->set_attack_time( time() );    // 不同的人:更新持续敌手
        }        
        level = me->get_skill(THIS_SKILL);
        who->set("pf.fall", -damage/10);    // 小心准备 me
        if (who->is_user()) who->set_save_2("pf.fall", -damage/10);
        set_effect_2(who, EFFECT_CHAR_FALL, ADD_INTERVAL / 2, 2);    // 小心准备 me
        send_user( who, "%c%w%w%c", 0x81, 4145, get_effect_3(who, EFFECT_CHAR_FALL), EFFECT_BAD );
        send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 4145, 1, EFFECT_BAD );
        
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,140);
        return 2;    // 执行成功
}

// 函数:获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数:能否使用特技
void can_perform( object me )
{
        int interval;
        string name;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf(" %s (Cấp %d )", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/10+1);
        interval = 2 - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 2, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 2, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 10, MAGIC_ACT_BEGIN, 0, 5, 0);
}

int perform_action_npc( object me, object who )
{
        object *user;
        int z;
        int level, mp;

        if( me == who )
        {
                return 1;
        }
        if( !who->can_be_fighted(me) || !me->can_fight(who) )
        {
                return 1;
        }
	if (who->is_anti_effect()) return 2;
	if (who->get("anti_curse")) return 2;
        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // 远程目标锁定

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%s,%d", who->get_char_id(), level ) );

        return 1;
}

int cast_done_npc( object me )
{
        object *user, who;
        string arg;
        int z, x, y;
        int level, ret, flag=0, damage;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                send_user( get_scene_object(z, x, y, USER_TYPE), "%c%w%w%w%c%c%w%c%c%c", 0x4f, x, y, 
                        41451, 1, OVER_BODY, 41452, 1, OVER_BODY, PF_ONCE );

                return 1;    // 打到空地
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 
                41451, 1, OVER_BODY, 41452, 1, OVER_BODY, PF_ONCE );

        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return 2;    // 以下为附加效果！

        if( get_effect(who, EFFECT_CHAR_HALFGOD) ) return 2;    // 处于神打状态下不成功
        
        if (get_effect_3(who, EFFECT_CHAR_ARMORFALL)) flag += 1;
        if (get_effect_3(who, EFFECT_MP_FALL)) flag += 1;
        if (get_effect_3(who, EFFECT_CHAR_POWERFALL)) flag += 1;                      
//        if (flag>=2) return 2;        
        damage = ADD_EFFECT;
        if (-who->get("pf.fall")>damage/15) return 2;     
        if( !who->get_max_damage() && who->get_action_mode()==1 ) who->init_enemy_damage(me, damage);
        else
        if( damage >= who->get_max_damage() && who->get_action_mode()!=0 ) who->init_enemy_damage(me, damage);    // 记录最强伤害(NPC)   
        if( who->get_enemy_4() == me )
                who->set_attack_time( time() );    // 同一个人:更新持续时间
        else if( gone_time( who->get_attack_time() ) > 12 )
        {
                who->set_enemy_4(me);
                who->set_attack_time( time() );    // 不同的人:更新持续敌手
        }        
        level = me->get_skill(THIS_SKILL);
        who->set("pf.fall", -damage/15);    // 小心准备 me
        if (who->is_user()) who->set_save_2("pf.fall", -damage/15);
        set_effect_2(who, EFFECT_CHAR_FALL, ADD_INTERVAL / 2, 0);    // 小心准备 me
        send_user( who, "%c%w%w%c", 0x81, 4145, get_effect_3(who, EFFECT_CHAR_FALL), EFFECT_BAD );
        send_user( get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 4145, 1, EFFECT_BAD );
        
        if ( who && !who->is_die() )
        	CHAR_FIGHT_D->set_enmity(me,who,140);
        return 2;    // 执行成功
}