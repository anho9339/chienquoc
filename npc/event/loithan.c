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
int get_char_picid() { return 9970; }
void do_gift( string arg );
// 函数：构造处理
void create()
{
        set_name("Lôi Thần");
		set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));
        setup();
}


void do_look(object who)
{
			send_user(who, "%c%s", ';', "Lôi Thần với nhiệm vụ chém gió thành bão để tạo ra sấm sét !");
}