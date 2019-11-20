#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>

inherit BADMAN;

object robber;
int picid;
// 函数：获取人物造型
int get_char_picid() { return picid; }
void do_bonus();
// 函数：构造处理
void create()
{
        set_name("Quái Vật Kì Lạ");
        set_2( "talk", ([
                 "bonus"         : (: do_bonus :),
        ]) );
	set_char_type(FIGHTER_TYPE_2);
	picid = ({1200,1201,9002,8251,9005})[random(5)];
	set_level(20);
	set("birthday",time());
        setup();
	set_char_type(FIGHTER_TYPE_2);

}
/*void reset() {
        if( gone_time( get("birthday") ) >= ACTIVE_FEIZEI->get_alive_time() &&  !objectp(get_enemy())) {
                remove_from_scene();
                destruct( this_object() );
        }
}*/
int can_fight( object who ) 
{ 
	if ( !objectp(this_object()->get_enemy()) )
		return 0;	
	return 1;
}

// 函数：死亡奖励
void win_bonus( object who ) { "sys/party/chiakhoavahop"->win_bonus_callout( this_object(), who ); }


