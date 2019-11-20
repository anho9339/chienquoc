#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>
#include <city.h>
#include <cmd.h>

inherit OFFICER;

int get_char_picid()
{
	return 5205;
}
void do_welcome(string arg);

void create()
{
	set_name("Chước Viêm");
	set_real_name("Bãi Luyện Exp");
	set_2("talk",(["welcome":(:do_welcome:)]));
	setup();
}

void do_look(object who)
{
	string result;
	object me;
	
	me=this_object();
	result=sprintf(get_name()+":\n Xin chào vị anh hùng hảo hán đây, ta là Chước Viêm chủ quản Thiên Nguyên Trường, nơi có vô vàn quái vật nguy hiểm mang đầy kinh nghiệm chiến đấu. Phải chăng ngươi muốn thử tài và rèn luyện với chúng?\n");
	result+=sprintf(ESC "Phải! Tiến vào rèn luyện (Tiêu hao 100k ngân lượng)\ntalk %x# welcome.1\n",getoid(me));
	result+=sprintf(ESC "Lượn thôi.");
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),result);
	
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}

void do_welcome2(object me, string arg)
{
	int flag,iTime,iDay,iGio;
	string result;
	object who,xaphu;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);     
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];
		
	who=this_player();
	who->set_time("talk",0);
	flag=to_int(arg);
	
	
	switch(flag)
	{
		case 1:
		    if (who->get_cash() < 100000) 
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Số ngân lượng của bạn không đủ 100.000 !"
				ESC"Rời khỏi",get_name())); 
				return;
			}
			if (who->get_level() < 20) 
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Người chơi trên 20 cấp mới được vào !"
				ESC"Rời khỏi",get_name())); 
				return;
			}
			if (who->get_save_2("timepbexp")==iGio)
			{
			result = me->get_name()+":\n    Bạn đã đi phụ bản rồi, hãy chờ 1 tiếng sau theo để đi tiếp !\n";
			send_user( who, "%c%c%w%s", ':', 3, 9971, result );
			return;
			} 
			who->set_save_2("timepbexp", iGio); 
		    who->add_cash(-100000);
			/*xaphu = new("npc/phuban/xaphu");
			xaphu->add_to_scene(910,52,46); */	
			who->add_to_scene(910,54,44);
			"/inh/user/user"->kicknguoichoi(who,600);				
			send_user( who, "%c%s", ';', HIY"Tiến vào bãi luyện tập thành công! Bạn có 10 phút để luyện cấp! Chúc bạn may mắn! " );
        		break;
	}	
}

