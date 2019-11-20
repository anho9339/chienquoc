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
int get_char_picid() { return 3032; }
// 函数：构造处理
void create()
{
        set_name("Cây non");
        setup();
}


void do_look(object who)
{
			send_user(who, "%c%s", ';', "Cây đã đâm hoa kết trái mới có thể hái quả !");
}