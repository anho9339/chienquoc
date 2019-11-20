
#include <effect.h>
#include <skill.h>

// 函数：消耗法力(ＮＰＣ)
void into_effect( object me )    // 僵尸符法
{
        object who, *zombie;

        set_effect(me, EFFECT_NPC_ZOMBIE, 10);

        if( objectp( who = me->get_owner() ) && who->is_user() )
        {
                if( who->get_mp() >= 20 )
                {
                        who->add_mp(-20);
                }
                else
                {
                        me->remove_from_scene();
                        if( arrayp( zombie = who->get("zombie") ) )
                        {
                                zombie -= ({ me, 0 });
                                who->set("zombie", zombie);
                        }
                        destruct(me);
                }
        }
/*      else    // 有 logout 效果，故注释
        {
                me->remove_from_scene();
                destruct(me);
        }       */
}

// 函数：消耗法力(ＮＰＣ)
void into_effect_2( object me )    // 撒豆成兵
{
        object who, *zombie;

        set_effect(me, EFFECT_NPC_ZOMBIE_2, 10);

        if( objectp( who = me->get_owner() ) && who->is_user() )
        {
                if( who->get_mp() >= 16 )
                {
                        who->add_mp(-16);
                }
                else
                {
                        me->remove_from_scene();
                        if( arrayp( zombie = who->get("zombie") ) )
                        {
                                zombie -= ({ me, 0 });
                                who->set("zombie", zombie);
                        }
                        destruct(me);
                }
        }
/*      else    // 有 logout 效果，故注释
        {
                me->remove_from_scene();
                destruct(me);
        }       */
}

void into_effect_conjure( object me )    // 召唤
{
	int type, level;
	int hp, mp, ap, dp, cp, sp, pp;
	int z, x, y, p, x0, y0, ben,ben1,ben2,ben3,ben4,ben5,ben6,ben7;
	object npc;	
	send_user(me, "%c%c%c", 0x5a, 1, 1);
	type = me->get_2("conjure.type");
	level = me->get_2("conjure.level");
	if ( type == 9999 )
	{
		if ( npc = me->get_2("conjure.pet") )
			USER_BEAST_D->show_beast(me,npc);
		return ;
	}
	z = get_z(me); x0 = get_x(me); y0 = get_y(me);
	p = get_valid_xy(z, x0 + random(3) - 1, y0 + random(3) - 1, IS_CHAR_BLOCK) ;
	if (!p) return;
	npc = new (sprintf("/npc/std/%d", type));
	if (!npc) return;
	hp = me->get_max_hp();
	mp = me->get_max_hp();
	ap = me->get_ap();
	cp = me->get_cp();
	dp = me->get_dp();
	sp = me->get_sp();
	pp = me->get_pp();
	npc->set_level(level);
	ben  = (hp*20/100);
	ben1 = (mp*20/100);
	ben2 = (ap*10/100);
	ben3 = (cp*10/100);
	ben4 = (dp*10/100);
	ben5 = (pp*10/100);
	ben6 = (ap*10/100);
	switch(type)
	{
	case 4131:
		npc->set_name( sprintf( "Quỷ Tốt ( %s )", me->get_name() ) );
		npc->set_max_hp((150+(level-1)/10*300)+ben);
		npc->set_max_mp((100+(level-1)/10*20)+ben1);
		npc->set_ap((20+(level-1)/10*20)+ben2);
		npc->set_dp((150+(level-1)/10*60)+ben4);
		npc->set_cp((70+(level-1)/10*200)+ben3);
		npc->set_pp((150+(level-1)/10*60)+ben5);
		npc->set_sp(80+(level-1)/10*55);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		me->set("soldier", npc);
		break;
	case 4132:
		npc->set_name( sprintf( "Thiên Binh ( %s )", me->get_name() ) );
		npc->set_max_hp((500+(level-15)/10*1000)+ben);
		npc->set_ap((130+(level-15)/10*200)+ben3);
		npc->set_dp((250+(level-15)/10*150)+ben4);
		npc->set_pp((250+(level-15)/10*150)+ben5);
		npc->set_sp(50+(level-15)/10*40);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		me->set("soldier", npc);
		break;	
/*		
	case 4133:
		npc->set_name( sprintf( "Thần Tướng ( %s )", me->get_name() ) );
		npc->set_max_hp(150+level*(level+1)/38+(cp+pp)*45/100);
		npc->set_ap(80+level*(level+1)/45+cp*7/10);
		npc->set_dp(100+level*(level+1)/50+pp*4/10);
		npc->set_pp(100+level*(level+1)/50+pp*4/10);
		npc->set_sp(70+level*(level+1)/80+cp/10);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		me->set("soldier", npc);           
		break;	
*/				
	case 4134:
		npc->set_name( sprintf( "Cương Thi ( %s )", me->get_name() ) );
		npc->set_max_hp((1600+(level-35)/10*1000)+ben);//300
		npc->set_ap((400+(level-35)/10*300)+ben3);//120
		npc->set_dp((300+(level-35)/10*300)+ben4);//100
		npc->set_pp((300+(level-35)/10*100)+ben5);
		npc->set_sp(150+(level-35)/10*50);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		me->set("soldier", npc);
		break;		
	case 4135:
		npc->set_name( sprintf( "Đậu Binh ( %s )", me->get_name() ) );
		npc->set_max_hp((500+(level-15)/10*800)+ben1);
		npc->set_ap((350+(level-15)/10*150)+ben3);
		npc->set_dp((250+(level-15)/10*150)+ben4);
		npc->set_pp((250+(level-15)/10*150)+ben5);
		npc->set_sp(50+(level-15)/10*40);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		me->set("soldier", npc);
		break;	
	case 4137:
		npc->set_name( sprintf( "Song Phủ Vương ( %s )", me->get_name() ) );
		npc->set_max_hp(50000+(level-1)/150*5000);
		npc->set_max_mp(50000+(level-1)/150*5000);
		npc->set_ap(5000+(level-1)/150*500);
		npc->set_dp(5000+(level-1)/150*500);
		npc->set_cp(5000+(level-1)/150*500);
		npc->set_pp(5000+(level-1)/150*500);
		npc->set_sp(3000+(level-1)/150*500);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		me->set("soldier", npc);
		break;	
	case 4139:
		npc->set_name( sprintf( "Tiên Nhi ( %s )", me->get_name() ) );
		npc->set_max_hp((2000+(level-1)/10*1000)+ben1);
		npc->set_max_mp((1600+(level-1)/10*300)+ben);
		npc->set_ap((600+(level-1)/10*200)+ben3);
		npc->set_dp((300+(level-1)/10*200)+ben4);
		npc->set_pp((300+(level-1)/10*100)+ben5);
		npc->set_sp(20+(level-1)/10*10);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		npc->set_hit_rate(400);
        npc->set_hit_rate_2(400);
		npc->set_double_rate(200);
		me->set("soldier", npc);
		break;	
	case 4140: // Pet Ngoại
		npc->set_name( sprintf( "Tuyết Ngoại Nhi ( %s )", me->get_name() ) );
		npc->set_max_hp((18000*100)+ben);
		npc->set_max_mp((1600*100)+ben);
		npc->set_ap((400*10)+ben6);
		npc->set_dp((300*50)+ben4);
		npc->set_pp((300*50)+ben5);
		npc->set_sp(150*10);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		npc->set_hit_rate(200);
     //   npc->set_hit_rate_2(100);
		npc->set_double_rate(100);
		me->set("tienlinh", npc);
		break;
	case 4141: // Pet Nội
		npc->set_name( sprintf( "Tuyết Nội Nhi ( %s )", me->get_name() ) );
		npc->set_max_hp((18000*100)+ben);
		npc->set_max_mp((1600*100)+ben);
		npc->set_ap((400*10)+ben3);
		npc->set_dp((300*50)+ben4);
		npc->set_pp((300*50)+ben5);
		npc->set_sp(150*10);
		npc->set_hp(npc->get_max_hp());
		npc->set_mp(npc->get_max_mp());
		npc->set_hit_rate(200);
     //   npc->set_hit_rate_2(100);
		npc->set_double_rate(100);
		me->set("tienlinh", npc);
		break;
	}
	if ( me->get_2("suit_effect.summon") )	//套装
	{
		npc->set("suit_effect",npc->get_max_hp()/10);
		npc->add_max_hp(npc->get_max_hp()/10);
		npc->add_dp(50);
	}
	npc->upgrade_level(1);
        npc->set_owner(me);
        npc->set_level_0(level);    // 道法神通

        npc->set_city_name( me->get_city_name() );    // 用于战场
        npc->set_manager( me->get_manager() );
        npc->set_org_name( me->get_org_name() );

        x = p / 1000;  y = p % 1000;
        npc->set_action_mode(2);
        npc->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0) );
        switch(type)
        {
        case 4131:
        	send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                	41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE );
                break;
	case 4132:
                send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41321, 1, OVER_BODY, 41322, 1, OVER_BODY, 41323, 1, UNDER_FOOT, PF_ONCE );
		break;
	case 4133:
                send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41331, 1, OVER_BODY, 41332, 1, UNDER_FOOT, PF_ONCE );
		break;
	case 4134:
                send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41341, 1, OVER_BODY, 41342, 1, OVER_BODY, 41343, 1, UNDER_FOOT, PF_ONCE );
		break;
	default:
                send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        59111, 1, OVER_BODY, 59112, 1, UNDER_FOOT, PF_ONCE );
		break;				               
	}               
        
        send_user(me, "%c%c%d%s", 0x2c, 1, getoid(npc), npc->get_name() );
        send_user(me, "%c%c%d%w%w%w", 0x2c, 2, getoid(npc), 1, 2, 3 );
        send_user(me, "%c%c%d%c", 0x2c, 3, getoid(npc), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 4, getoid(npc), 50 );
        send_user(me, "%c%c%d%c", 0x2c, 5, getoid(npc), 2 );
        send_user(me, "%c%c%d%c", 0x2c, 6, getoid(npc), 2 );
        send_user(me, "%c%c%d%w%w", 0x2c, 7, getoid(npc), get_x(npc), get_y(npc) );
        send_user(me, "%c%c%d%d", 0x2c, 8, getoid(npc), npc->get_char_picid() );
}

void effect_break( object me )    // 召唤中断
{
	set_effect(me, EFFECT_CONJURE, 0);
	send_user(me, "%c%c%c", 0x5a, 1, 0);	
}