#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <action.h>

#define _DEBUG(x)	tell_user(find_char("971"),x);

inherit NPC;

int flag;
int saytime,hptime,RelaxTime,pTime,pTime1,iRelax,lowhp,summon;
string *nFamily = ({"Đào Hoa Nguyên","Thục Sơn","Cấm Vệ Quân","Đường Môn","Mao Sơn","Côn Luân","Vân Mộng Cốc"});
// 函数：是否不能进城
int cannot_enter_city() { return 1; }
int get_id_color() { return 0x800080; }
void drop_items( object me, object who );
int perform_action_npc(object me,object who);
object summon_guard(object who);

// 函数：修正经验奖励
int correct_exp_bonus( int level, int level2, int exp ) { return exp; }

// 函数：修正掉宝率
int correct_drop_rate( int level ) { return 100; }

// 函数：获取人物名称
string get_short() 
{ 
        return this_object()->get_name(); 
}

void init_fight_status()
{
	set_ap(500);
	set_dp(200);
	set_cp(500);
	set_pp(200);
	set_sp(200);	
}

// 函数：构造处理
void create()
{
	object me = this_object();
        set_name("Đại Úy Vô Song Thành");
        set_head_color(0x3290);
        set_char_picid(1267); 
        set_level(60);
        set_max_hp(2000000);
        set_max_mp(5000000);
	init_fight_status();
        set_walk_speed(2);
        set_attack_speed(10);
        set_max_seek(8);
        set_walk_step(2);
        set("no_sk04211",1);	//变身术对其没有效果
        set("anti_sleep",1);	//不会昏迷
        set("anti_no_move",1);	//不会冻结
        
        set_skill(261,70);
        setup();
        set_char_type(FIGHTER_TYPE_2);
        set( "birthday", time() );
        set_enmity_flag(1);
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
        object owner, item;
        string leader, id;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		set_enemy(0);
		return 0;
	}
	if( who->is_user() && USER_INVENTORY_D->get_free_count(who) < 1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),  "Hành trang của ngươi không đủ 1 chỗ trống, không thể nào tấn công ta được đâu Ha ha ha!" );
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
				SAY_CMD->say(me, "Ngươi muốn đoạt được Cờ Hiệu à, vượt qua ải của ta trước đi rồi hẵng nói tiếp !!"); 
			}
		}
	}
	else if ( RelaxTime == 0 )
	{
		RelaxTime = time();
		init_fight_status();
	}
	if ( RelaxTime && gone_time(RelaxTime) >= 120 )
	{
		RelaxTime = 0;	
		init_fight_status();
		iRelax = 1;
		me->add_to_scene(get_z(me),245,83,4);
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
		if ( objectp(enemy) )
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
			
		}
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
	int rate,x,y,z,i,size,p;
	object me = this_object(),*char,*user,npc;
	
	RelaxTime = 0;
	iRelax = 0;
	
	if ( lowhp == 0 && get_hp() * 100 / get_max_hp() < 30 )	//生命值为30％以下
	{
		lowhp = 1;
	}
	rate = random(100);	
	if ( !lowhp )
	{
		if ( gone_time(pTime) > 20 )
		{
			if ( "skill/02/02613"->perform_action_npc(me,who) )
			{
				pTime = time();
				SAY_CMD->say(me, "Vô Song Thành là nơi chỉ có quyền vị cao mới được vào, cút ngay cho ta !");
				return 1;
			}
		}
		if ( gone_time(pTime1) > 60 )
		{
			pTime1 = time();
			SAY_CMD->say(me, "Đánh thắng ta rồi hãy nói !");
			perform_action_npc(me,who);
			return 1;
		}
	}
	else
	{
		if ( gone_time(pTime) > 10 )
		{
			if ( "skill/02/02613"->perform_action_npc(me,who) )
			{
				pTime = time();
				SAY_CMD->say(me, "Vô Song Thành là nơi chỉ có quyền vị cao mới được vào, cút ngay cho ta !");
				return 1;
			}
		}
		if ( gone_time(pTime1) > 60 )
		{
			pTime1 = time();
			SAY_CMD->say(me, "Ngươi dám vào Vô Song Thành à !");
			perform_action_npc(me,who);
			return 1;
		}
		x = get_x(me); y = get_y(me); z = get_z(me); 
		/*if ( summon == 0 )
		{
			summon = 1;
			for(i=0;i<4;i++)
			{
				if ( objectp(me->get(sprintf("guard%d",i))) )
					continue;
				p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK);
				if ( !p )
					continue;
				npc = summon_guard(me);	
				if ( !npc )
					continue;
				npc->add_to_scene( z, p / 1000, p % 1000);
				npc->set_owner(me);
				NPC_SLAVE_D->find_enemy(npc);    // 寻找敌人
				send_user( get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc), 
		                        41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE );
				me->set(sprintf("guard%d",i),npc);
			}
		}	*/
	}		
	
	return 0;
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
        object owner, *team, item;
        int level, level2, exp, exp2, pot, alllevel;
        int i, size, status, time, flag, e1;

        if( !objectp( who = me->get_enemy_4() ) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;
		
		item = new("item/event/cohieuvst");
		e1 = item->move2(who,-1);
			if ( !e1)
			{
				destruct(item);
				return ;	
			}
		item->add_to_user(e1);
		send_user(who,"%c%s",';',"Bạn nhận được "HIY "Cờ Hiệu Vô Song Thành");	
		USER_D->user_channel(sprintf(HIR "Đại Úy Vô Song Thành đã bại trận rút lui !!!" ));
		USER_D->user_channel(sprintf(HIR "Đại Úy Vô Song Thành đã bại trận rút lui !!!" ));
		USER_D->user_channel(sprintf(HIR "Đại Úy Vô Song Thành đã bại trận rút lui !!!" ));
		USER_D->user_channel(sprintf(HIY"Bằng hữu "HIC"%s "HIY"đã đoạt được "HIG"Cờ Hiệu Vô Song Thành"HIY" !", who->get_name() ));
	//drop_items(me,who);
	
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
	exp = 500;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
                level2 = level - team[i]->get_level();
                exp2 = exp * team[i]->get_level()/alllevel;                        
                exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;  

                if (exp2<5) exp2 = 5;
                team[i]->add_exp(exp2);
                team[i]->add_potential(100);	
                team[i]->add_log("#copyboss4", 1);
		team[i]->add_log("&copyboss4", exp2);
		team[i]->add_log("*copyboss4", 100);
		//team[i]->add_save("bosslvl",1);
	//	"sys/sys/test_db"->add_yuanbao(team[i],89);
	}
}

/*
// 函数：掉宝奖励
void drop_items( object me, object who )
{
	int x,y,z,p,i,rate,rate1;
	string *nTmp,id,owner;
	object item,leader;
	
	z = get_z(me);  x = get_x(me);  y = get_y(me);
        id = who->get_leader();
		USER_D->user_channel(sprintf(HIR "Đại Úy Vô Song Thành đã bại trận rút lui !!!" ));
		USER_D->user_channel(sprintf(HIR "Đại Úy Vô Song Thành đã bại trận rút lui !!!" ));
		USER_D->user_channel(sprintf(HIR "Đại Úy Vô Song Thành đã bại trận rút lui !!!" ));
        
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

	if ( random(100) < rate1 )	//必掉(有等级修正)
	{				
					if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	                {
	                        item = new( "/item/event/cohieuvst" );
							if ( !item )
								return;
	                        TEAM_D->drop_item(item,who);
				item->set_user_id(owner);
	                        item->add_to_scene(z, p / 1000, p % 1000);
	                        item->set("winner", who);
	                        item->set( "time", time() );
	                }
	}
}

*/
//杀死一个敌人加20000气血
void stop_fight()
{
	object enemy;
	enemy = get_enemy();
	if ( enemy && enemy->get_hp()==0 )
	{
		SAY_CMD->say(this_object(), "Nhìn ngươi tư chất rất tốt, hãy ở lại với tao để đi cướp Vàng rồi giết người đi. ha ha ha !!");
		add_hp(20000);
		add_dp(get_dp()/10);
	}
	::stop_fight();	
}

int perform_action_npc(object me,object who)
{
        send_user( get_scene_object_2(me, USER_TYPE), "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg(sprintf("%d",lowhp));	
	return 1;	
}

int cast_done_npc( object me )
{
	int i,size,hp,mp;
	int x,y,z;
	object *char,who;
	
	i = to_int(me->get_cast_arg());
	x = get_x(me);y = get_y(me);z = get_z(me);
	char = get_range_object(z, x, y, 10, USER_TYPE) + get_range_object(z, x, y, 10, CHAR_TYPE) - ({ me,0 });
	size = sizeof(char);
	if ( i == 1 )	//万马奔腾
	{
		for(i=0;i<size;i++)
		{
			who = char[i];
			if( !who->can_be_fighted(me) || !me->can_fight(who) )
				continue;
			mp = who->get_mp()/2;
			who->add_mp(-mp);
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 36851, 1, OVER_BODY, PF_ONCE );
		}
	}
	else		//千马奔腾
	{
		for(i=0;i<size;i++)
		{
			who = char[i];
			if( !who->can_be_fighted(me) || !me->can_fight(who) )
				continue;
			hp = who->get_hp()/10;
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x68, getoid(who), hp );
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 36861, 1, OVER_BODY, PF_ONCE );
			CHAR_DIE_D->is_enemy_die(me,who,hp);
		}
	}	
	return 1;	
}

object summon_guard(object who)
{
	int level = 10;
	object npc;
	
	npc = new ("npc/boss/00081");
	npc->set_char_picid(8000);
	npc->set_level(level);
	npc->set_name( "Thủ Vệ" );
	npc->set_owner(who);
	return npc;
}