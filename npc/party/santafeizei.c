#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
// 函数:获取人物造型
int get_char_picid() { return 1290; }
// 函数:构造处理
void create()
{
        set_name("Phi Tặc Noel");
        setup();
}

void do_look(object who)
{
	object me=this_object();
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n Chúc %s có một giáng sinh vui vẻ và ấm áp !",me->get_name(),who->get_name()));
}



