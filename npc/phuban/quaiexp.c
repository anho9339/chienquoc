
#include <npc.h>
#include <equip.h>
#include <skill.h>

inherit BADMAN;

int hptime;
// 函数：远程攻击的怪
// int is_caster() { return 1; }

// 函数：是否允许移动
// int is_moveable() { return 0; }    // 禁止使用 go 命令

// 函数：跟随对手(心跳之中调用)
// void follow_user() { }    // 禁止跟随敌人

// 函数：获取人物造型
int get_char_picid() { return 1251; }

// 函数：构造处理
void create()
{
        set_name("Hồng Long Mãnh Sư");

        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0x9B81CF);
		  
        NPC_ENERGY_D->init_level( this_object(), 3+ random(30) );    
        set_max_seek(4);
		set("anti_05311",1); // Không bị Mê Hồn
        setup();

        set_char_type(FIGHTER_TYPE);    // 重设类型
}


// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
int perform_action( object who ) { return 0; }    // XXXXX->perform_action_npc( this_object(), who ); }

// 函数：掉宝奖励
void drop_items( object who ) { __FILE__ ->drop_items_callout( this_object(), who ); }

// 函数：掉宝奖励(在线更新)
void drop_items_callout( object me, object who )
{
        object item, leader;
        string file, owner, id;
        int p, rate, rate1, i, size, gold, equip, total, total2;
        int z, x, y, level;
	
	z = get_z(me);  x = get_x(me);  y = get_y(me);
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
		
        p = random(100);  size = ( p > 2 ) ? 1 : ( p > 0 ) ? 2 : 8;  total = 2;  total2 = 3;
		level = me->get_level();
        rate = me->correct_drop_rate( me->get_level() - who->get_level() ) * who->get_online_rate() / 100;
		who->add_exp(level*100+random(1200));
        for( i = 0; i < size; i ++ )
        {
                p = random(10000);

				if( p < 5000 * rate / 100 )    // 金钱
                {
                        if( gold >= total ) continue;

                        if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                        {
                                item = new( "/item/std/0001" );
                                TEAM_D->drop_item(item,who);
                                item->set_user_id(owner);
                                item->set_value( 100 + random(100) );
                                item->add_to_scene(z, p / 1000, p % 1000);
                                item->set("winner", who);
                                item->set( "time", time() );
                                gold ++;
                        }
                } 
		}
}

void heart_beat_walk()
{
	int i,x,y,z,x0,y0,z0,p,x1,y1;
	object enemy,me=this_object();	
	if (hptime==0) hptime = time();
	if ( gone_time(hptime) >= 10 )
	{
		enemy = me->get_enemy();
		hptime = time();
		if ( objectp(enemy) )
		{
			z = get_z(enemy);z0=get_z(me);
			if (distance_between(me, enemy) < 2) return;
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
			        if ( x1 && y1 && z )
			        {
		                        send_user( get_scene_object_2(me, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, x1, y1, 9413, 1, OVER_BODY, PF_ONCE );    // 补发指令
		                        me->add_to_scene( z, x1, y1 );
		                        me->to_front_xy(x, y);
				}
			}
			
		}
	}
	::heart_beat_walk();	
}