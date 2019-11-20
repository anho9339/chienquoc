#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 2113; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
        set_name("");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
        setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
	int iTime=time();
	
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("看来这只石头狮子便是连通地面的唯一出路。你确定现在就要离开夷齐之墓吗？\n"ESC"确定\ntalk %x# welcome.1\n"ESC"取消",id));
	
}


void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag, p,iTime,i,size;
       	object who, item;
       	string name,*nTmp,tmp;
	mixed *mxTime;  

        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
   		who->add_to_scene(81,125,75,get_d(who), 40971, 0, 40971, 0 );
        	break;

	}

}

