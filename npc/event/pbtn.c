#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>

inherit BADMAN;

object robber;
int get_id_color() { return 0107215; }
// 函数：获取人物造型
int get_char_picid() { return 9999; }
void do_bonus();
// 函数：构造处理
void create()
{
        set_name("Đào Hoa Đại Tặc");
        set_2( "talk", ([
                 "bonus"         : (: do_bonus :),
        ]) );
	set_char_type(FIGHTER_TYPE_2);
	set_level(40);
	set("birthday",time());
        setup();
	set_char_type(FIGHTER_TYPE_2);

}

// 函数：可以接受战斗
int can_be_fighted( object who ) 
{ 
        object owner, me;
        string leader;
        int id;
        me = this_object();

        if( who->get_enemy() == this_object() ) return 1;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return 0;

	if (me->get("userpbtn")==who->get_number())
		return 1;  
	else if (me->get("userpbtn2")==who->get_number())
		return 1;	
        
        return 0;
}

// --------------------------------------------------------------- 远程调用 ----

// 函数：死亡奖励
void win_bonus( object who ) { __FILE__ ->win_bonus_callout( this_object(), who ); }

// 函数：死亡奖励(在线更新)
void win_bonus_callout( object me, object who )
{
        object owner,npc, *all;
        int i, size;

        if( !me->can_be_fighted(who) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;        	
	if (!who) return;
	all = get_scene_object_2(me, USER_TYPE);
	size = sizeof(all);
	for (i=0;i<size;i++) if (who=all[i])
	{
		if ( me->get("userpbtn") == who->get_number() )
		{
			npc = new("/npc/event/ruongpbtn");	
			if ( !npc )
				return ;
			npc->set("user",who->get_number());
			npc->set("level",me->get_level());
			npc->add_to_scene(get_z(me),get_x(me)-2,get_y(me)+2);
			break;
		}
		else if ( me->get("userpbtn2") == who->get_number() )
		{
			npc = new("/npc/event/ruongpbtn");	
			if ( !npc )
				return ;
			npc->set("user",who->get_number());
			npc->set("level",me->get_level());
			npc->add_to_scene(get_z(me),get_x(me)-2,get_y(me)+2);
			break;
		}
	}			
}

void do_fight(int sec)
{
	object me = this_object(),who;
	who = me->get("fightpbtn");
	if ( !who ||  get_z(who) != me->get("pbtn_z") )
	{
		destruct(me);
		return ;	
	}
	sec--;
	if ( sec > 0 )
	{
		tell_user(who,"Sau %d giây %s sẽ xuất hiện, mời chuẩn bị ứng chiến!",sec,get_name());
		call_out("do_fight",1,sec);
	}
	else
	{
		me->add_to_scene(get("pbtn_z"),get("pbtn_x"),get("pbtn_y"),);	
	}		
}
