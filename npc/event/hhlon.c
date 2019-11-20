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
        set_name("");
        setup();
}


void do_look(object who)
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,0,"Ta là cây, ta là cây! Biết không hả? \n"
		ESC "Ta biết\nCLOSE\n"
		ESC"Rời khỏi");
}