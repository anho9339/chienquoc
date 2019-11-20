#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#define CHRISTMAS "sys/party/christmas"

inherit OFFICER;
int iStart,iFinish;

// 函数:获取人物造型
int get_char_picid() { return 9972; }
void do_welcome(string arg);
// 函数:构造处理
void create()
{
        set_name("Ông Già Noel");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );

        setup();
	iStart = mktime(2014,12,18,0,0,0);	
	iFinish = mktime(2014,12,30,0,0,0);	

}

void do_look(object who)
{
        object me = this_object();
        
        if ( time() > iFinish )
        {
        	me->remove_from_scene();	
        	destruct(me);
        	return ;
        }
//	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n Cám ơn mọi người đã ủng hộ Chiến Quốc, ta có phần quà dành tặng bạn đây.\n"ESC"Tôi muốn nhận\ntalk %x# welcome.4\n"ESC"Tôi sẽ nhận sau.",me->get_name(),getoid(me)));
	CHRISTMAS->do_look(this_object(),who);
}


void do_welcome( string arg )
{
        object me = this_object();
        CHRISTMAS->do_welcome(me, arg);
}
