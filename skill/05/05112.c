
// 单体远程技能  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0511
#define THIS_PERFORM    05112
#define PF_START       "05112"
#define PF_NAME        "Sơ Trị"

#define SKILL_LEVEL     5
#define TIME_INTERVAL   2
#define SUB_MP        ( 10 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 7 * 6 )
#define ADD_EFFECT    ( 45 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 7 * 50 )

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n Võ công yêu cầu: 5 cấp\n    Cơ bản y thuật, phục hồi 45 điểm Khí Huyết cho mục tiêu";
        cur_level = (level - SKILL_LEVEL)/7 + 1;
        result = sprintf(HIC" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Pháp Lực tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Cơ bản y thuật, phục hồi %d điểm Khí Huyết cho mục tiêu.\n " HIC"Cấp tiếp theo:\n "NOR"Võ công yêu cầu: " HIR "Cấp %d " NOR"\n    Cơ bản y thuật, phục hồi %d điểm Khí Huyết cho mục tiêu.",
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_EFFECT, cur_level*7+SKILL_LEVEL, ADD_EFFECT+50 );
	return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;
        if ( me->get_perform("05016#"))
	{
                printf( ECHO "Sử dụng \"Đấu Chuyển Tinh Di\" không thể sử dụng \""PF_NAME"\"." );
                return 1;		
	}
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
                        me->to_front_xy(x, y);
                        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

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
	if ("/sys/user/attack"->can_use_help(me, who)==0)
	{				
		printf( ECHO "Đối với đối phương không thể sử dụng " PF_NAME );
		return 1;				
	} 

        me->set_enemy_2(who);    // 远程目标锁定

        me->to_front_xy(x, y);
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );

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

// 函数：法术处理
int cast_done( object me )
{
        object who,item;
        string arg;
        int z, x, y;
        int level, cp, hp;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( sscanf(arg, "%d,%d,%d", z, x, y) == 3 )
        {
                send_user( get_scene_object(z, x, y, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, x, y, 51121, 1, OVER_BODY, PF_ONCE );

                return 1;    // 打到空地
        }
        if( sscanf(arg, "%s,%d", arg, level) != 2 ) return 1;
        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 51121, 1, OVER_BODY, PF_ONCE );
        
        hp = ADD_EFFECT;    // 小心准备 me, cp
	if( get_effect(who, EFFECT_CHAR_GOOD_BAD) )
        	hp /= 2;
        hp += me->get("add_magic_heal");
	if( objectp(item=me->get_equip(WEAPON_TYPE)) && item->get_name()=="Ngọc Thần Bảo Kiếm" )
		hp += random(51);
	if( objectp(item=me->get_equip(WEAPON_TYPE)) && item->get_name()=="Lục Tiên Kiếm" )
		hp += 50 + random(51);
	if( objectp(item=me->get_equip(WEAPON_TYPE)) && item->get_name()=="Huyết Lệ" )
		hp += 400 + random(101);	
        if (random100()<me->get_double_rate_2()/100) 
        {
        	hp *= 2;
        	send_user( ({ me, who }), "%c%d%w%c%d%w%c", 0x4a, getoid(who), -hp, get_d(who), getoid(who), 1 );
        }
        else
        	send_user( ({ me, who }), "%c%d%w", 0x68, getoid(who), -hp );        
        if (!who->no_recover() && !get_effect_3(who, EFFECT_USER_BURN)) who->add_hp(hp);        
       	CHAR_FIGHT_D->set_enmity2(me,who,90+hp);
        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数：能否使用特技
void can_perform( object me )
{
        int interval;
        string name;

        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL )
        {
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
                return;
        }
	name = sprintf(" %s (Cấp %d )", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/7+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0,10, MAGIC_ACT_BEGIN, 0, 5, 0);
}
