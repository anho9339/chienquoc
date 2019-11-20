
// 单体远程技能  TIPS:[PF_CAST]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

#define THIS_SKILL      0417
#define THIS_PERFORM    04176
#define PF_START       "04176"
#define PF_NAME        "Tế Thần Tướng"

#define SKILL_LEVEL     40
#define TIME_INTERVAL	180
#define SUB_MP          ( 1 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 20 * 5 )
#define ADD_TIME	( 15 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 20 * 2000 )
#define ADD_RATE	( 3 + ( me->get_skill(THIS_SKILL)-SKILL_LEVEL) / 20 * 1 )
// 函数：获取符法效果
// int get_cast_seal() { return 41100; }    // 符纸逆旋

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        int cur_level;
        string result;
        if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n Võ công yêu cầu: 40 cấp\n    Hy sinh Triệu hồi thú của bản thân để triệu hồi “Thần Tướng” hỗ trợ chiến đấu. Mỗi lần tấn công Thần Tướng có 3％ khả năng làm cho kẻ địch bị Choáng trong 3 giây. Thần Tướng có thể duy trì xuất hiện trong 15 giây。";
        cur_level = (level - SKILL_LEVEL)/20 + 1;
        result = sprintf(HIC" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Pháp Lực tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Hy sinh Triệu hồi thú của bản thân để triệu hồi “Thần Tướng” hỗ trợ chiến đấu. Mỗi lần tấn công Thần Tướng có %d％ khả năng làm cho kẻ địch bị Choáng trong 3 giây. Thần Tướng có thể duy trì xuất hiện trong %d giây。\n " HIC"Cấp tiếp theo:\n "NOR "Võ công yêu cầu: " HIR "Cấp %d " NOR "\n    Tăng Thần Tướng thêm 1000 điểm Khí Huyết；\n    Tăng Thần Tướng thêm 400 điểm Ngoại Công；\n    Tăng Thần Tướng thêm 350 điểm Ngoại Kháng；\n    Tăng Thần Tướng thêm 350 điểm Nội Kháng；\n    Tăng Thần Tướng thêm 200 điểm Thân Thủ。\n    Mỗi lần tấn công Thần Tướng có %d％ khả năng làm cho kẻ địch bị Choáng trong 3 giây. Thần Tướng có thể duy trì xuất hiện trong %d giây。", 
        	PF_NAME, cur_level, SKILL_LEVEL, SUB_MP, TIME_INTERVAL, ADD_RATE, ADD_TIME, cur_level*20+SKILL_LEVEL, ADD_RATE + 1,ADD_TIME + 2000 );
        return result;	        
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, item;
        int z;
        int level, mp;

        if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( me->get_perform(PF_START) == time() ) return 1;

        if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 me
        {
                printf( ECHO "Sử dụng “ %s ”cần %d điểm Pháp Lực.", PF_NAME, mp );
                return 1;
        }

/*      if( !objectp( item = present("bùa giấy", me, 1, MAX_CARRY) ) )
        {
                printf( ECHO "您得有符纸才能使用“" PF_NAME "”。" );
                return 1;
        }       */

        who = me->get("soldier");
        if (!who) return 1;

        if( !who->is_zombie() || who->get_owner() != me )
        {
                printf( ECHO "只能对自己的召唤兽使用“" PF_NAME "”。" );
                return 1;
        }

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // 所有出招２秒后能使用
        me->set_time( "pf", time() );

        me->set_enemy_2(who);    // 远程目标锁定

        me->to_front_xy(x, y);
        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
//      send_user( user, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

        me->add_mp(-mp);
//      item->add_amount(-1);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 5);
         me->add_2("go_count.count2",5);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( who->get_char_id() );
	send_user( me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0 );
        me->set_perform( PF_START, time() );
        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object who;
        string arg;
        int z, x, y, p, x0, y0;
        int level, cp, hp;
        object npc, npc1, npc2, npc3, npc4, npc5, npc6, npc7, npc8, npc9;        

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;

        if( !objectp( who = find_char(arg) ) ) return 1;

        send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 41411, 1, OVER_BODY, PF_ONCE );

	send_user( get_scene_object_2(who, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(who), get_y(who), 4176, 1, OVER_BODY, PF_ONCE );
	send_user(me, "%c%c%d", 0x2c, 0, getoid(who));
	who->remove_from_scene(FALL_ACT);
	destruct(who);	
	npc = new (sprintf("/npc/std/%d", 4133));
	npc1 = new (sprintf("/npc/std/%d", 1000));
	npc2 = new (sprintf("/npc/std/%d", 2000));
	npc3 = new (sprintf("/npc/std/%d", 3000));
	npc4 = new (sprintf("/npc/std/%d", 4000));
	npc5 = new (sprintf("/npc/std/%d", 5000));
	npc6 = new (sprintf("/npc/std/%d", 6000));
	npc7 = new (sprintf("/npc/std/%d", 7000));
	npc8 = new (sprintf("/npc/std/%d", 8000));
	npc9 = new (sprintf("/npc/std/%d", 9000));
	if (!npc && !npc1 && !npc2 && !npc3 && !npc4 && !npc5 && !npc6 && !npc7 && !npc8 && !npc9) return 2;
	level = me->get_skill(THIS_SKILL);
	npc->set_level(level);
	npc->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc->set_max_hp(1000+(level-40)/20*1000);
	npc->set_ap(600+(level-40)/20*400);
	npc->set_dp(600+(level-40)/20*350);
	npc->set_pp(600+(level-40)/20*350);
	npc->set_sp(200+(level-40)/20*200);
	npc->set_hp(npc->get_max_hp());
	npc->set_mp(npc->get_max_mp());
	npc1->set_level(level);
	npc1->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc1->set_max_hp(1000+(level-40)/20*1000);
	npc1->set_ap(600+(level-40)/20*400);
	npc1->set_dp(600+(level-40)/20*350);
	npc1->set_pp(600+(level-40)/20*350);
	npc1->set_sp(200+(level-40)/20*200);
	npc1->set_hp(npc1->get_max_hp());
	npc1->set_mp(npc1->get_max_mp());
	npc2->set_level(level);
	npc2->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc2->set_max_hp(1000+(level-40)/20*1000);
	npc2->set_ap(600+(level-40)/20*400);
	npc2->set_dp(600+(level-40)/20*350);
	npc2->set_pp(600+(level-40)/20*350);
	npc2->set_sp(200+(level-40)/20*200);
	npc2->set_hp(npc2->get_max_hp());
	npc2->set_mp(npc2->get_max_mp());
	npc3->set_level(level);
	npc3->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc3->set_max_hp(1000+(level-40)/20*1000);
	npc3->set_ap(600+(level-40)/20*400);
	npc3->set_dp(600+(level-40)/20*350);
	npc3->set_pp(600+(level-40)/20*350);
	npc3->set_sp(200+(level-40)/20*200);
	npc3->set_hp(npc3->get_max_hp());
	npc3->set_mp(npc3->get_max_mp());
	npc4->set_level(level);
	npc4->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc4->set_max_hp(1000+(level-40)/20*1000);
	npc4->set_ap(600+(level-40)/20*400);
	npc4->set_dp(600+(level-40)/20*350);
	npc4->set_pp(600+(level-40)/20*350);
	npc4->set_sp(200+(level-40)/20*200);
	npc4->set_hp(npc4->get_max_hp());
	npc4->set_mp(npc4->get_max_mp());
	npc5->set_level(level);
	npc5->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc5->set_max_hp(1000+(level-40)/20*1000);
	npc5->set_ap(600+(level-40)/20*400);
	npc5->set_dp(600+(level-40)/20*350);
	npc5->set_pp(600+(level-40)/20*350);
	npc5->set_sp(200+(level-40)/20*200);
	npc5->set_hp(npc5->get_max_hp());
	npc5->set_mp(npc5->get_max_mp());
	npc6->set_level(level);
	npc6->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc6->set_max_hp(1000+(level-40)/20*1000);
	npc6->set_ap(600+(level-40)/20*400);
	npc6->set_dp(600+(level-40)/20*350);
	npc6->set_pp(600+(level-40)/20*350);
	npc6->set_sp(200+(level-40)/20*200);
	npc6->set_hp(npc6->get_max_hp());
	npc6->set_mp(npc6->get_max_mp());
	npc7->set_level(level);
	npc7->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc7->set_max_hp(1000+(level-40)/20*1000);
	npc7->set_ap(600+(level-40)/20*400);
	npc7->set_dp(600+(level-40)/20*350);
	npc7->set_pp(600+(level-40)/20*350);
	npc7->set_sp(200+(level-40)/20*200);
	npc7->set_hp(npc7->get_max_hp());
	npc7->set_mp(npc7->get_max_mp());
	npc8->set_level(level);
	npc8->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc8->set_max_hp(1000+(level-40)/20*1000);
	npc8->set_ap(600+(level-40)/20*400);
	npc8->set_dp(600+(level-40)/20*350);
	npc8->set_pp(600+(level-40)/20*350);
	npc8->set_sp(200+(level-40)/20*200);
	npc8->set_hp(npc8->get_max_hp());
	npc8->set_mp(npc8->get_max_mp());
	npc9->set_level(level);
	npc9->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
	npc9->set_max_hp(1000+(level-40)/20*1000);
	npc9->set_ap(600+(level-40)/20*400);
	npc9->set_dp(600+(level-40)/20*350);
	npc9->set_pp(600+(level-40)/20*350);
	npc9->set_sp(200+(level-40)/20*200);
	npc9->set_hp(npc9->get_max_hp());
	npc9->set_mp(npc9->get_max_mp());
	me->set("soldier", npc);
	me->set("soldier", npc1);
	me->set("soldier", npc2);
	me->set("soldier", npc3);
	me->set("soldier", npc4);
	me->set("soldier", npc5);
	me->set("soldier", npc6);
	me->set("soldier", npc7);
	me->set("soldier", npc8);
	me->set("soldier", npc9);
	npc->upgrade_level(1);
        npc->set_owner(me);
        npc->set_level_0(level);    
        npc->set_city_name( me->get_city_name() ); 
        npc->set_manager( me->get_manager() );
        npc->set_org_name( me->get_org_name() );
	npc1->upgrade_level(1);
        npc1->set_owner(me);
        npc1->set_level_0(level);    
        npc1->set_city_name( me->get_city_name() ); 
        npc1->set_manager( me->get_manager() );
        npc1->set_org_name( me->get_org_name() );
	npc2->upgrade_level(1);
        npc2->set_owner(me);
        npc2->set_level_0(level);    
        npc2->set_city_name( me->get_city_name() ); 
        npc2->set_manager( me->get_manager() );
        npc2->set_org_name( me->get_org_name() );
	npc3->upgrade_level(1);
        npc3->set_owner(me);
        npc3->set_level_0(level);    
        npc3->set_city_name( me->get_city_name() ); 
        npc3->set_manager( me->get_manager() );
        npc3->set_org_name( me->get_org_name() );
	npc4->upgrade_level(1);
        npc4->set_owner(me);
        npc4->set_level_0(level);    
        npc4->set_city_name( me->get_city_name() ); 
        npc4->set_manager( me->get_manager() );
        npc4->set_org_name( me->get_org_name() );
	npc5->upgrade_level(1);
        npc5->set_owner(me);
        npc5->set_level_0(level);    
        npc5->set_city_name( me->get_city_name() ); 
        npc5->set_manager( me->get_manager() );
        npc5->set_org_name( me->get_org_name() );
	npc6->upgrade_level(1);
        npc6->set_owner(me);
        npc6->set_level_0(level);    
        npc6->set_city_name( me->get_city_name() ); 
        npc6->set_manager( me->get_manager() );
        npc6->set_org_name( me->get_org_name() );	
	npc7->upgrade_level(1);
        npc7->set_owner(me);
        npc7->set_level_0(level);    
        npc7->set_city_name( me->get_city_name() ); 
        npc7->set_manager( me->get_manager() );
        npc7->set_org_name( me->get_org_name() );
	npc8->upgrade_level(1);
        npc8->set_owner(me);
        npc8->set_level_0(level);    
        npc8->set_city_name( me->get_city_name() ); 
        npc8->set_manager( me->get_manager() );
        npc8->set_org_name( me->get_org_name() );
	npc9->upgrade_level(1);
        npc9->set_owner(me);
        npc9->set_level_0(level);    
        npc9->set_city_name( me->get_city_name() ); 
        npc9->set_manager( me->get_manager() );
        npc9->set_org_name( me->get_org_name() );	
        z = get_z(me); x0 = get_x(me); y0 = get_y(me);
        p = get_valid_xy(z, x0 + random(3) - 1, y0 + random(3) - 1, IS_CHAR_BLOCK) ;
        x = p / 1000;  y = p % 1000;
        npc->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc1->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc1, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc1), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc2->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc2, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc2), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc3->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc3, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc3), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc4->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc4, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc4), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc5->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc5, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc5), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc6->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc6, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc6), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc7->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc7, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc7), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc8->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc8, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc8), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		npc9->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );                
        send_user( get_scene_object_2(npc9, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc9), 
                41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );		
        npc->set_life(ADD_TIME);
        npc->Action_Mode(1);
		npc1->set_life(ADD_TIME);
        npc1->Action_Mode(1);
		npc2->set_life(ADD_TIME);
        npc2->Action_Mode(1);
		npc3->set_life(ADD_TIME);
        npc3->Action_Mode(1);
		npc4->set_life(ADD_TIME);
        npc4->Action_Mode(1);
		npc5->set_life(ADD_TIME);
        npc5->Action_Mode(1);
		npc6->set_life(ADD_TIME);
        npc6->Action_Mode(1);
		npc7->set_life(ADD_TIME);
        npc7->Action_Mode(1);
		npc8->set_life(ADD_TIME);
        npc8->Action_Mode(1);
		npc9->set_life(ADD_TIME);
        npc9->Action_Mode(1);
        send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc), get_x(npc), get_y(npc) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc1), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc1), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc1), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc1), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc1), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc1), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc1), get_x(npc1), get_y(npc1) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc1), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc2), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc2), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc2), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc2), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc2), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc2), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc2), get_x(npc2), get_y(npc2) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc2), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc3), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc3), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc3), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc3), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc3), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc3), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc3), get_x(npc3), get_y(npc3) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc3), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc4), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc4), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc4), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc4), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc4), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc4), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc4), get_x(npc4), get_y(npc4) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc4), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc5), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc5), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc5), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc5), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc5), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc5), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc5), get_x(npc5), get_y(npc5) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc5), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc6), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc6), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc6), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc6), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc6), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc6), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc6), get_x(npc6), get_y(npc6) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc6), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc7), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc7), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc7), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc7), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc7), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc7), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc7), get_x(npc7), get_y(npc7) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc7), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc8), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc8), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc8), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc8), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc8), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc8), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc8), get_x(npc8), get_y(npc8) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc8), npc->get_char_picid() );
		send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc9), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc9), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc9), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc9), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc9), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc9), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc9), get_x(npc9), get_y(npc9) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc9), npc->get_char_picid() );
        CHAR_FIGHT_D->set_enmity1(me,30);
        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME; }

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
	name = sprintf(" %s (Cấp %d )", PF_NAME, (me->get_skill(THIS_SKILL)-SKILL_LEVEL)/20+1);
        interval = TIME_INTERVAL - gone_time( me->get_perform(PF_START) );
        if( interval < 0 )
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name );
	send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, 0, 1, MAGIC_ACT_BEGIN, 0, 5, 0);
}
