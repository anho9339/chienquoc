#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;
object npc;
int iStart,iFinish;
// 函数：获取人物造型
int get_char_picid() { return 6009; }
void do_welcome(string arg);
// 函数：构造处理
void create()
{
        set_name("Sứ Giả Hoạt Động Chiến Quốc");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
        ]) );
	iStart = mktime(2016,2,1,7,0,0);
	iFinish = mktime(2016,2,4,24,0,0);
        setup();
}

void do_look(object who)
{
	int id = getoid(this_object()),iTime=time();
	if ( iTime > iFinish )
	{
		this_object()->remove_from_scene();
		destruct(this_object());
		return ;	
	}
	send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Sứ Giả Hoạt Động Chiến Quốc：\n    Xin chào %s, ta đc thiên đế Pretkuzl phái xuống. Hôm nay là 21 tháng 3 tức hoạt động 321 đc mở ra, lúc 10 giờ ~ 22 giờ khoản thời gian đó hãy đến chỗ ta để nhận 4 giờ "HIR"321 du hành gấp đôi kinh nghiệm"NOR". Nhưng nếu qua 22 giờ thì sẽ ko có cơ hội nhận! Hãy nhanh nhận nào!\n"ESC"Nhận “321 du hành gấp đôi kinh nghiệm”\ntalk %x# welcome.0\n"ESC"Đọc kĩ quy tắc\ntalk %x# welcome.5\n"ESC"Rời khỏi",who->get_name(),id,id));
}


void do_welcome( string arg )
{
        object me = this_object();
        if ( time() > iFinish )
	{
		me->remove_from_scene();
		destruct(me);
		return ;	
	}
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id;
       	object who;   
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 0:
        	i = 4-who->get_save("double321");
//        	if ( i > 3 )
//			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Sứ Giả Hoạt Động Chiến Quốc：\n    321 du hành nhân đôi kinh nghiệm có thể nhận đc 4 giờ, nhưng thời gian nhận chỉ tồn tại trong 10h~22h. Ngươi còn có %d giờ gấp đôi kinh nghiệm. Ngươi muốn nhận bao lâu 321 du hành gấp đôi kinh nghiệm?\n"ESC"Một giờ\ntalk %x# welcome.1\n"ESC"Hai giờ\ntalk %x# welcome.2\n"ESC"Ba giờ\ntalk %x# welcome.3\n"ESC"Bốn giờ\ntalk %x# welcome.4\n"ESCRời khỏi",i,id,id,id,id));
//		else if ( i > 2 )
//			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Sứ Giả Hoạt Động Chiến Quốc：\n    321 du hành nhân đôi kinh nghiệm có thể nhận đc 4 giờ, nhưng thời gian nhận chỉ tồn tại trong 10h~22h. Ngươi còn có %d giờ gấp đôi kinh nghiệm. Ngươi muốn nhận bao lâu 321 du hành gấp đôi kinh nghiệm?\n"ESC"Một giờ\ntalk %x# welcome.1\n"ESC"Hai giờ\ntalk %x# welcome.2\n"ESC"Ba giờ\ntalk %x# welcome.3\n"ESC"Rời khỏi",i,id,id,id));
		if ( i > 1 )
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Sứ Giả Hoạt Động Chiến Quốc：\n    321 du hành nhân đôi kinh nghiệm có thể nhận đc 4 giờ, nhưng thời gian nhận chỉ tồn tại trong 7h~24h. Ngươi còn có %d giờ gấp đôi kinh nghiệm. Ngươi muốn nhận bao lâu 321 du hành gấp đôi kinh nghiệm?\n"ESC"Một giờ\ntalk %x# welcome.1\n"ESC"Hai giờ\ntalk %x# welcome.2\n"ESC"Rời khỏi",i,id,id,));
		else if ( i == 1 )
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Sứ Giả Hoạt Động Chiến Quốc：\n    321 du hành nhân đôi kinh nghiệm có thể nhận đc 4 giờ, nhưng thời gian nhận chỉ tồn tại trong 7h~24h. Ngươi còn có %d giờ gấp đôi kinh nghiệm. Ngươi muốn nhận bao lâu 321 du hành gấp đôi kinh nghiệm?\n"ESC"Một giờ\ntalk %x# welcome.1\n"ESC"Rời khỏi",i,id,));
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Sứ Giả Hoạt Động Chiến Quốc：\n    Ngài đã không thể nhận thêm kinh nghiệm nhân đôi");
		break;
	case 1..2:
        	if ( who->get_save("double321") >= 4 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Sứ Giả Hoạt Động Chiến Quốc：\n   Ngài không có kinh nghiệm gấp đôi!");
        		return ;	
        	}
        	if ( who->get_save("double321") + flag > 4 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Sứ Giả Hoạt Động Chiến Quốc：\n    Không thể nhận quá nhiều thời gian nhân đôi");
        		return ;	
        	}
        	i = gone_time( who->get_login_time() );
		if ( i+ who->get_game_time()<who->get_double_time())
		{
		        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		        	sprintf("%s：\n     Gấp đôi kinh nghiệm của ngài còn %d giây, không thể nhận\n"
		                ESC "Thoát\nCLOSE\n", me->get_name(), who->get_double_time() - i - who->get_game_time() ) );			
			return;		               
		}
		
        	who->add_save("double321",flag);
		who->set_double_time(i+ who->get_game_time()+3600*flag);
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "" ); 
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Hỗ trợ trò chơi" ); 
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Gấp đôi kinh nghiệm" ); 

		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Sứ Giả Hoạt Động Chiến Quốc：\n    Ngài nhận %d giờ gấp đôi kinh nghiệm, chúc ngài vui vẻ!",flag));
        	break;
        case 5:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Sứ Giả Hoạt Động Chiến Quốc：\n    "HIR"321 nhân đôi kinh nghiệm "NOR"là vào ngày hôm nay "HIR"7 giờ~24 giờ"NOR", đang trong lúc hoạt động, ngươi có thể nhận gấp đôi kinh nghiệm. Nhưng 321 gấp đôi kinh nghiệm "HIR"không thể xài cùng với gấp đôi kinh nghiệm khác"NOR", nếu như ngươi đã có gấp đôi kinh nghiệm, thì phải chờ hết thời gian gấp đôi đó rồi hãy nhận gấp đôi này.\n"ESC"Rời khỏi",));
		break; 
        }
        
}

void set_open(object who)
{
	if ( time() >= iFinish )
	{
		send_user(who,"%c%s",'!',"Thời gian hoạt động đã qua, ko thể mở");
		return ;
	}
	if ( objectp(npc) )
		return ;
	npc = new("npc/party/0026");
	npc->add_to_scene(80,285,177,4);
	call_out("gonggao",5);
	send_user(who,"%c%s",'!',"Hoạt động đã mở");
}

void set_close(object who)
{
	remove_call_out("gonggao");
	if ( objectp(npc) )
	{
		npc->remove_from_scene();
		destruct(npc);	
	}
	send_user(who,"%c%s",'!',"Hoạt động đã đóng");
}

void gonggao()
{
	remove_call_out("gonggao");
	if ( time() > iFinish )
	{
		if ( objectp(npc) )
		{
			npc->remove_from_scene();
			destruct(npc);	
		}
		return ;
	}
	call_out("gonggao",900);
	CHAT_D->sys_channel(0,HIR"321 du hành nhân đôi kinh nghiệm "NOR" hoạt động hiện đang tiến hành, các người chơi lúc 7h ~ 24h hãy tới Chu Quốc tìm Sứ Giả Hoạt Động Chiến Quốc nhận "HIR"321 du hành nhân đôi kinh nghiệm"NOR". Còn chờ gì nữa? Hãy đi đi!");
}