
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <music.h>

#define FILE_NPC "npc/boss/00161"

inherit NPC;
int iAtt,iWalk,hptime;
string *nFamily = ({"桃花源","蜀山","禁卫军","唐门","茅山","昆仑山","云梦泽"});

void summon_guard();

// 函数：门派人物
int is_boss() { return 1; }

// 函数：是否不能进城
int cannot_enter_city() { return 1; }

//设置战斗状态
int set_fight_status(int type,int level)
{
	object me=this_object();
	me->set("type",type);
	switch(type)
	{
	 case 1:  	//低物防高敏型
	        set_skill(3483,level);  
		set_skill(2512,level);
		set_skill(2416,level);
                
                set_attack_speed(21);  //攻击速度 
                set_walk_speed(3);     //移动速度
                	
                add_dp(-1*get_dp()*400/100);    //物理防御
                add_max_hp(get_max_hp()*7000/100);	//最大气血
                add_sp(get_sp()*200/100);	//躲闪
                add_ap(get_ap()*600/100);      //物理攻击
                add_max_mp(get_max_mp()*200/100);  	//法术力
              
	 	break;
	 case 2:	//高物防低法防型：
	 	set_skill(2216,level);  
		set_skill(2313,level);
		set_skill(2314,level);
                
                set_attack_speed(23);  //攻击速度 
                set_walk_speed(4);     //移动速度
                	
                add_dp(get_dp()*400/100);    //物理防御
                add_max_hp(get_max_hp()*7000/100);	//最大气血
                add_pp(-1*get_pp()*400/100);	//法防
                add_ap(get_ap()*600/100);      //物理攻击
                add_max_mp(get_max_mp()*200/100);  	//法术力
	 	break;
	 case 3:	//高法防低物防型
	 	set_skill(4231,level);  
		set_skill(4232,level);
		set_skill(4234,level);
                set_skill(4243,level);
                
                set_attack_speed(24);  //攻击速度 
                set_walk_speed(5);     //移动速度
                	
                add_dp(-1*get_dp()*400/100);    //物理防御
                add_max_hp(get_max_hp()*7000/100);	//最大气血
               // add_attack_speed(get_attack_speed()*300/100)  //速度
                add_pp(get_pp()*400/100);	//法防
                add_cp(get_cp()*600/100);      //法术攻击
                add_max_mp(get_max_mp()*2400/100);  	//法术力
	 	break;
	 case 4:	//长血型：
	 	set_skill(2118,level);  
		set_skill(2114,level);
		set_skill(2115,level);
                                
                set_attack_speed(25);  //攻击速度 
                set_walk_speed(6);     //移动速度
                	
                add_dp(-1*get_dp()*400/100);    //物理防御
                add_max_hp(get_max_hp()*7000/100);	//最大气血
                add_pp(-1*get_pp()*400/100);	//法防
                add_ap(get_ap()*600/100);      //物理攻击
                add_max_mp(get_max_mp()*200/100);  	//法术力
	 	break;
	 case 5:	//长血高物防高法防型：
	 	set_skill(2616,level);  
		set_skill(2615,level);
		                                
                set_attack_speed(26);  //攻击速度 
                set_walk_speed(7);     //移动速度
                	
                add_dp(get_dp()*400/100);    //物理防御
                add_max_hp(get_max_hp()*7000/100);	//最大气血
                //add_attack_speed(get_attack_speed()*300/100)  //速度
                add_pp(get_pp()*400/100);	//法防
                add_ap(get_ap()*600/100);      //物理攻击
                add_max_mp(get_max_mp()*400/100);  	//法术力
	 	break;
	 case 6:	//强攻型加召唤：
	 	set_skill(4143,level);  
		set_skill(4144,level);
		                                
                set_attack_speed(13);  //攻击速度 
                set_walk_speed(30);     //移动速度
                	
                add_dp(get_dp()*400/100);    //物理防御
                add_max_hp(get_max_hp()*5000/100);	//最大气血
               // add_attack_speed(get_attack_speed()*350/100)  //速度
                add_pp(get_pp()*450/100);	//法防
                add_ap(get_ap()*600/100);      //物理攻击
                add_max_mp(get_max_mp()*600/100);  	//法术力
	 	break;	
	}
//	tell_user(this_player(),"set_fight_status type=%d",type);
		
}

// 函数：构造处理
void create()
{
        object me=this_object();
        set_name( "Mộng Ảo Cương Thi Vương");
        set_char_picid(4134);   
	set_level(120);
//	set_max_hp(1000);
	set_max_hp(15000);
	set_max_mp(10000);
	set_ap(1400);
	set_dp(1000);
	set_cp(1000);
	set_pp(2200);
	set_sp(200);
	set_effect(me, EFFECT_CHAR_BUSY, 15);
	call_out("do_fight", 15);
        setup();
        set_char_type(FIGHTER_TYPE_2); 
}

//15秒后复活，开始战斗
void do_fight() 
{
	object me = this_object();
	set_effect(me, EFFECT_CHAR_BUSY, 0);
	me->add_to_scene(get_z(me), get_x(me), get_y(me));
}

// 函数：特技攻击对手
int perform_action( object who ) 
{
	int rate,type;
	object me = this_object();
	
	if( get_z(who)!=get_z(me) || !inside_screen_2(me, who)  )
		return 0;
	rate = random(100);
	type=me->get("type");	
	switch(type)
	{
	case 1:
		if ( rate < 10 )
			return PF_FILE_03483->perform_action_npc(me, who);
		else if ( rate < 34 )
			return PF_FILE_02512->perform_action_npc(me, who);
		else if ( rate < 40 )
			return PF_FILE_02416->perform_action_npc(me, who);			
		break;
	case 2:
		if ( rate < 16 )
			return PF_FILE_02216->perform_action_npc(me, who);
		else if ( rate < 32 )
			return PF_FILE_02313->perform_action_npc(me, who);
		else if ( rate < 48 )
			return PF_FILE_02314->perform_action_npc(me, who);
		break;			
	case 3:	
		if( get_effect(me, EFFECT_CHAR_NO_PF) ) return 0;
		if ( get_effect(me, EFFECT_CHAR_CHANGE) < 1)
		{
			PF_FILE_04251->cast_done_npc(me);			
		}
		if ( rate < 70 )
			return PF_FILE_04231->perform_action_npc(me, who);
		else if ( rate < 90 )
			return PF_FILE_04232->perform_action_npc(me, who);
		else if ( rate < 97 )
			return PF_FILE_04234->perform_action_npc(me, who);
		else
			return PF_FILE_04243->perform_action_npc(me, who);	
		break;
	case 4: 
		if( !me->get_perform("03173") ) 
		{
			PF_FILE_03173->perform_action_npc(me,who);
		}
		if ( rate < 10 )
			return PF_FILE_02118->perform_action_npc(me, who);
		else if ( rate < 26 )
			return PF_FILE_02114->perform_action_npc(me, who);
		else if ( rate < 38 )
			return PF_FILE_02115->perform_action_npc(me, who);
		break;
	case 5:
		if( !me->get_effect(me, EFFECT_USER_HURT) ) 
		{
			PF_FILE_03632->cast_done_npc(me);
		}
		if ( rate < 20 )
			return PF_FILE_02616->perform_action_npc(me, who);
		else if ( rate < 40 )
			return PF_FILE_02615->perform_action_npc(me, who);
		break;
	case 6:
		summon_guard();
		if( get_effect(me, EFFECT_CHAR_NO_PF) ) return 0;
		if ( rate < 12 )
			return PF_FILE_04143->perform_action_npc(me, who);
		else if ( rate < 24 )
			return PF_FILE_04144->perform_action_npc(me, who);
		break;		
	}
	return 0;
}


// --------------------------------------------------------------- 远程调用 ----
//死亡奖励
void win_bonus( object who )
{
	object owner,*team,*team2,map;
	object me = this_object();
	string id,id2;
	int i,size,level;
        if( !me->can_be_fighted(who) ) return;
        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;
	team = who->get_team();
	if ( sizeof(team) < 1 ) team = ({who});
        team = me->correct_bonus_team( team );
        if( ( size = sizeof(team) ) < 1 ) return;
	if( !objectp( map = get_map_object(get_z(me)) ) || !map->is_scene() ) return;	
        for(i=0;i<size;i++)
        {
        	team[i]->add_exp(20200+random(500));
        }
        __FILE__->drop_items(me,who);
        return;
}


void drop_items( object me, object who )
{
	int x,y,z,p,i,rate,rate1,level;
	string *nTmp,id,owner,file;
	object item,leader;
	
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	level=me->get_level();
	if(!level) level=120;
        id = who->get_leader();
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
	rate = random(100);
	if ( rate < rate1 ) //必掉
	{
		for(i=0;i<2;i++)	//2
	        {	
	        	if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	                {
	                        item = new( "/item/std/0001" );
	                        item->set_value( 100 );
	                        TEAM_D->drop_item(item,who);
				item->set_user_id(owner);
	                        item->add_to_scene(z, p / 1000, p % 1000);
	                        item->set("winner", who);
	                        item->set( "time", time() );
	                      
	                }
		}
	}
	
}

//自动跟踪有任务的玩家
void heart_beat_walk()
{
	string robber;
	object *member,who,owner;
	object me = this_object(),enemy;
	int x,y,z,x0,y0,z0,x1,y1,p,i;
	//3秒处理一次
	if ( (iWalk++)%3 )
	{
		::heart_beat_walk();
		return;		
	}
	if ( gone_time(hptime) >= 20+random(21) )
	{
		hptime = time();
		//瞬间移动
		enemy = get_enemy();
		if ( objectp(enemy) )
		{
			z = get_z(enemy);z0=get_z(me);
			
			if( z == z0 && distance_between(me, enemy) < 20 )
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
			        if ( x1 && y1 && z && !MAP_D->is_inside_city(z, x1, y1) )
			        {
		                        send_user( get_scene_object_2(me, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, x0, y0, 9413, 1, OVER_BODY, PF_ONCE );    // 补发指令
		                        me->add_to_scene( z, x1, y1 );
		                        me->to_front_xy(x, y);
				}
			}
			
		}
	}
	member = get_range_object_2(me, me->get_max_seek(), CHAR_TYPE)+get_range_object_2(me, me->get_max_seek(), USER_TYPE)-({me});
	if ( sizeof(member) != 0 )
	{
		robber = sprintf( "%x#", getoid(me) );
		foreach(who in member)
		{
				
			if ( who->is_die() ) 
				continue;
			if( (owner = who->get_owner()) && (owner->get_task("robber") != robber) ) 
			{
				continue;	
			}
			else if (  !(owner = who->get_owner()) && who->get_task("robber") != robber )
				continue;
			me->set_main_enemy(who);
			::heart_beat_walk();
			return;
		}		
	}
	owner =  me->get_enemy();
	if ( !objectp(owner) )
		return ;
        if( get_z(owner)!=get_z(me) || distance_between(me, owner) > 20 )  
        {
		me->set_enemy(0);
		return ;
	}

}


void heart_beat_attack( )
{
	string robber;
	object who;
	object me = this_object();
	//3秒处理一次
	if ( (iAtt++)%3 )	
	{
		::heart_beat_attack();
		return;		
	}	
	who = me->get_enemy();
	if ( !objectp(who) )
		return ;
        if( get_z(who)!=get_z(me) || distance_between(me, who) > 20 || !who->can_fight(me) )  
        {
		me->set_enemy(0);
		return ;
	}	

	::heart_beat_attack();

}


//召唤
void summon_guard()
{
	int i,size,x,y,z,count,p,level,mp;
	object npc,me=this_object();

	x = get_x(me);y = get_y(me);z = get_z(me);
	mp=me->get_mp();
	level=get_level()-5;
	for(i=0;i<5;i++)
	{
		if ( objectp(get(sprintf("guard%d",i))) )
			continue;
		p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK);
		if ( !p )
			continue;
		if(!(mp>=10)) continue;
		npc = new(FILE_NPC);	
		if ( !npc )
			break;
		me->add_mp(-10);
		set(sprintf("guard%d",i),npc);
		add("guard",({npc}));
		NPC_ENERGY_D->init_level(npc,level);
		npc->set_fight_status(level);
		npc->add_to_scene( z, p / 1000, p % 1000);
		npc->set_owner(me);
		NPC_SLAVE_D->find_enemy(npc);    // 寻找敌人
		send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
                        41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE );
	}
	
}
