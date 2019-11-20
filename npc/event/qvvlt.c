#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>

inherit BADMAN;

object robber;
int get_id_color() { return 0107215; }
// 函数：获取人物造型
int get_char_picid() { return 9960; }
void do_bonus();
// 函数：构造处理
void create()
{
        set_name("Quái Vật Valentine");
        set_2( "talk", ([
                 "bonus"         : (: do_bonus :),
        ]) );
	set_char_type(FIGHTER_TYPE_2);
	set_level(20);
	set_max_hp(2000+random(1000));
	set_ap(300);
	set_dp(200);
	set_pp(200);
	set_walk_speed(1);  
	set_attack_speed(25);
		set("no_sk04211",1);	//变身术对其没有效果
        set("anti_sleep",1);	//不会昏迷
        set("anti_no_move",1);	//不会冻结
	set("birthday",time());
        setup();
	set_char_type(FIGHTER_TYPE_2);

}
// 函数：死亡奖励
void win_bonus( object who ) { "sys/party/tinhnhan"->win_bonus_callout( this_object(), who ); }


