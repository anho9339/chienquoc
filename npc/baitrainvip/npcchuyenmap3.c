#include <npc.h>
#include <ansi.h>
#include <cmd.h>

inherit OFFICER;

int get_char_picid()
{
	return 5205;
}
void do_welcome(string arg);

void create()
{
	set_name("Cày Cấp VIP 3");
	set_real_name("Bạch Tần");
	set_2("talk",(["welcome":(:do_welcome:)]));
	setup();
}

void do_look(object who)
{
	string result;
	object me;
	
	me=this_object();
	result=sprintf(get_name()+":\n Đây là bãi train dành cho nhân vật 120 cấp. Hãy tới nơi này để train cấp một cách nhanh chóng hơn nhé.\n");
	result+=sprintf(ESC "Đi nào! (Mất 150k ngân lượng)\ntalk %x# welcome.1\n",getoid(me));
	result+=sprintf(ESC "Rời khỏi.");
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),result);
	
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}

void do_welcome2(object me, string arg)
{
	int flag;
	string result;
	object who;
	who=this_player();
	who->set_time("talk",0);
	flag=to_int(arg);
	
	switch(flag)
	{
		case 1:
		    if (who->get_cash() < 150000) 
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Số ngân lượng của bạn không đủ 100k!"
				ESC"Rời khỏi",get_name())); 
				return;
			}
		    who->add_cash(-150000); 
			who->add_to_scene(940,42,61);
			who->delete("gumu");
			who->delele("map");
        		break;
	}	
}

