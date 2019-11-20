#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 3031; }
// 函数：构造处理
void create()
{
        set_name(HIY"Cây hoàng kim");
        setup();
}


void do_look(object who)
{
		if ( who->get_level()<61 || who->get_level()>100 )
		{
			send_user(who, "%c%s", ';', "Cấp bậc 61-100 mới có thể hái quả ở Cây hoàng kim !");
			return 0;
		}
		if ( get_effect_3(who, EFFECT_PROGRESS) )
		{
			send_user(who, "%c%s", ';', "Không thể làm 2 việc cùng 1 lúc !");
			return 0;
		}
		if ( get_effect(who, EFFECT_PROGRESS2) )
		{
			send_user(who, "%c%s", ';', "Không thể làm 2 việc cùng 1 lúc !");
			return 0;
		}
				set_effect(who, EFFECT_PROGRESS2, 24);
				who->set_progress_file(__FILE__);   
				send_user(who, "%c%c%w%s", 0x5a, 0, 24, "Đang hái quả...");
}
int into_effect( object who , string arg)
{
	int p, rate;
	object item, me;
	rate = random(100);
	send_user(who, "%c%c%c", 0x5a, 1, 1);
	
		if( objectp( item = present("Quả hoàng kim", who, 1, MAX_CARRY*4) ) && item->get_amount() < 10000 )
		{
			item->add_amount(1);				
		}
		else
		{
				item = new("/item/event/quahoangkim");
				p = item->move2(who,-1);
				item->add_to_user(p);
		}		
				send_user(who, "%c%s", ';', sprintf("Bạn đã hái được %s !", item->get_name()));
		//	me->remove_from_scene();
		//	destruct(me);	
	return 1;
}
void effect_break(object me, string arg)
{
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect(me, EFFECT_PROGRESS2, 0 );	
}