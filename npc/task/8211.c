#include <ansi.h>
#include <npc.h>
#include <equip.h>
#include <action.h>

inherit SLAVE;
int iWalk;
// 函数：获取召唤兽类型
int get_zombie_type() { return 99; }     // 判断种类
// 函数：是否不能进城
int cannot_enter_city() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "Tay Sai" );
        set_char_picid(8000);    // 蒙面人
	
        setup();

        set( "birthday", time() );
}

void win_bonus( object who ) 
{
	int exp,level1,level2;
	object owner;

	owner = get_owner();
	if ( !objectp(owner) )
		return ;

	owner->add("robber.slave",-1);

	level1 = get_level();
	level2 = who->get_level();
	exp = correct_exp_bonus(level1,level1-level2,50);
	who->add_exp(exp);
	who->add_potential(1);	
	who->add_log("&robber", exp);
	who->add_log("*robber",1);
	tell_user( who, "Ngài hạ gục %s , Kinh nghiệm %+d , Tiềm năng %+d .", get_name(), exp, 1 );		
}

void heart_beat_walk()
{
	string robber;
	object *member,who,enemy;

	if ( (iWalk++)%3 )
	{
		::heart_beat_walk();
		return;
	}
	if ( iWalk>2&&!objectp(get_owner() ) )
	{
		remove_from_scene(FALL_ACT);
		destruct(this_object());
		return ;
	}
	member = get_range_object_2(this_object(),get_max_seek(), USER_TYPE);
	if ( sizeof(member) != 0 )
	{
		robber = get("robber.id");
		foreach(who in member)
		{
			if ( who->get_task("robber") != robber )
				continue;
			set_main_enemy(who);
			::heart_beat_walk();
			return;
		}		
	}
	set_enemy(0);
}

// 函数：可以接受战斗
int can_be_fighted( object who ) 
{ 
        object owner;
        string leader, id;

        if( who->get_enemy() == this_object() ) return 1;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return 0;

        if( stringp( id = who->get_task("robber") )
        &&      id == get("robber.id") ) 
		return 1;
        send_user( who, "%c%c%w%s", ':',3,get_char_picid(), get_name() + "：\n    Cút ngay! Bổn đại gia không hứng thú với ngươi!" );
        return 0;
}

int can_fight( object who ) 
{ 
        object owner;
        string leader, id;
	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		set_enemy(0);
		return 0;
	}
        if( who->get_enemy() == this_object() ) return 1;
        	
        if( stringp( id = who->get_task("robber") )
        &&      id == get("robber.id") ) 
		return 1;
        set_enemy(0);
        return 0;
}