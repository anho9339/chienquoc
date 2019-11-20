
#include <npc.h>
#include <ansi.h>
#include <map.h>
#include <task.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>

inherit OFFICER;

void do_welcome( string arg );

// 函数:获取人物造型
int get_char_picid() { return 6009; } 

// 函数:构造处理
void create()
{
        set_name( "Trì Dũ Tiên Tử" );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));    
        setup();     
}

void do_look( object who )
{
        int status;
        string name;
        object me = this_object();
        status = who->get("xiannv.status");
        if (who->get_gender()==1) name = "tiểu huynh đệ";
        else name = "tiểu cô nương";
        if (who->get_level()<10)
        	send_user( who, "%c%c%w%s", ':', 3, 6009,
	        	sprintf("%s:\n    Này %s ! Ngươi là tân thủ, ta có thể giúp ngươi hồi phục lại sức khoẻ của mình, nào ! muốn ta giúp ngươi không ?\n"
	                ESC "Ta muốn hồi phục sức khoẻ\ntalk %x# welcome.1\n"
	                ESC "Rời khỏi\nCLOSE\n", me->get_name(), name, getoid(me) ) );
	else
        	send_user( who, "%c%c%w%s", ':', 3, 6009,
	        	sprintf("%s:\n    Ngươi không còn là tân thủ nữa, ta không phụ trách chữa trị cho ngươi đâu !\n"
	                ESC "Rời khỏi\nCLOSE\n", me->get_name(), getoid(me) ) );
		               
}

void do_welcome( string arg )
{
        object map, map2, who, me, npc, item,*nEquip, level;
        int flag, status, z, z2, x, y, p;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, result;
        me = this_object();
        who = this_player();
        flag = to_int(arg);
        status = who->get("xiannv.status");
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if (who->get_level()>=10)
        	{
	        	send_user( who, "%c%c%w%s", ':', 4, 6009,
		        	sprintf("%s:\n    Ngươi không còn là tân thủ nữa, ta không phụ trách chữa trị cho ngươi đâu !\n"
		                ESC "Rời khỏi\nCLOSE\n", me->get_name(), getoid(me) ) );
        		return;
        	}       	
        	who->set_hp(who->get_max_hp());
        	who->set_mp(who->get_max_mp());
        	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 51121, 1, OVER_BODY, PF_ONCE );
                break;
        }
}