/* Song Tu - by Ben */
#include <ansi.h>
object check_st(object me, object who);
void songtu(object npc,object who,object user);
object check_st(object me, object who)
{
	object *team,user;
	string leader;
	if ( who->get_level()<20 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi hiện tại chưa đạt 20 cấp để có thể Song Tu cùng người chơi khác !");
		return 0;
	}
	if ( who->get_save_2("songtu.time")<1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi hiện tại đã hết thời hạn Song Tu, khi khác hãy đến !");
		return 0;
	}
	if(  !arrayp( team = who->get_team() ) || sizeof(team) == 1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi muốn Song Tu cùng với người nào? Hãy lập tổ đội cùng người đó rồi đến gặp ta !");
		return 0;
	}
	if( sizeof(team) > 2 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Nhóm của ngươi có quá nhiều người, ta không phân biệt được người mà ngươi muốn cùng Song Tu !");
		return 0;
	}
	if ( !stringp(leader=who->get_leader()) || to_int(leader) != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi không phải là trưởng nhóm, không thể nhận Song Tu !");
		return ;
	}
	team -= ({ who });
	user = team[0];
	if (!inside_screen_2(who, user))
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Khoảng cách của ngươi với người muốn cùng Song Tu quá xa !");
		return 0;
	}
	if ( user->get_level()<20 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đối phương hiện tại chưa đạt 20 cấp để có thể Song Tu cùng ngươi !");
		return 0;
	}
	if ( user->get_save_2("songtu.time")<1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đối phương hiện tại đã hết thời hạn Song Tu, khi khác hãy đến !");
		return 0;
	}
	return user;
}
void do_gift(object me, object who, string arg)
{
	int flag;
	object user;
	flag = to_int(arg);
	who->set_time( "talk",  0);
	switch(flag)
	{
		case 2:
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			me->get_name()+":\n Ngươi có chắc chắn muốn Song Tu để nhận được kinh nghiệm không ?\n"
			+ sprintf(ESC"Xác nhận\ntalk %x# gift.3\n",getoid(me))
			+ESC"Rời khỏi"
			);
			break;
		case 3:
			if ( !objectp(user=check_st(me,who)) ) return 0;
			send_user( user, "%c%c%w%s", ':', 3, me->get_char_picid(), 
			sprintf("%s:\n %s, ngươi khác nhận phải Song Tu cùng với %s phải không ?\n",me->get_name(),user->get_gender()==1?"Vị huynh đài này":"Vị cô nương này",who->get_name())
			+ sprintf(ESC"Xác nhận\ntalk %x# gift.4\n"ESC"Rời khỏi",getoid(me)));
			send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Xin chờ đợi đối phương xác nhận !");
			who->set("songtu.cho",user);	
			user->set("songtu.traloi",who);
			break;
		case 4:
			user = who;
			if( !objectp(who=user->get("songtu.traloi")) )
			return 0;
			if ( user != who->get("songtu.cho") )
			return 0;
			who->delete("songtu.cho");	
			user->delete("songtu.traloi");
			if ( !objectp(user=check_st(me,who)) )
			return 0;
			songtu(me,who,user);	
			break;
		case 99:
			if ( who->get_level()<20 ) 
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Cấp bậc chưa đạt 20 cấp, chưa thể tham gia chức năng Song Tu !");
				return 0;
			}
			if ( who->get_save_2("songtu.time")<7200 )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(me->get_name()+":\n Thời gian Song Tu của ngươi là %s. \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save_2("songtu.time")>=3600?sprintf("%d giờ %d phút",who->get_save_2("songtu.time")/3600,((who->get_save_2("songtu.time")-3600)/60)):who->get_save_2("songtu.time")>=60?sprintf("%d phút",who->get_save_2("songtu.time")/60):sprintf("%d giây",who->get_save_2("songtu.time"))));
			else if ( who->get_save_2("songtu.time")<86400 )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(me->get_name()+":\n Thời gian Song Tu của ngươi là %d giờ. \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save_2("songtu.time")/3600));
			else 
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(me->get_name()+":\n Thời gian Song Tu của ngươi là %d ngày %d giờ. \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save_2("songtu.time")/86400,(who->get_save_2("songtu.time")-86400)/3600));
			break;
		case 100:
			if ( who->get_level()<20 ) 
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Cấp bậc chưa đạt 20 cấp, chưa thể tham gia chức năng Song Tu !");
				return 0;
			}	
			if ( who->get_save_2("songtu.time")>129600 )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Thời gian Song Tu của ngươi còn quá nhiều, không thể tích trữ thêm !");
				return 0;
			}
			if ( "sys/sys/test_db"->get_yuanbao(who) < 500 )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Kim bảo của ngươi không đủ con số 50, không thể mua thêm thời gian Song Tu !");
				return 0;
			}
			"sys/sys/test_db"->add_yuanbao(who, -500);
			who->add_save_2("songtu.time",1800);
			send_user(who,"%c%s",';', "Bạn đã mua thêm "HIR "30 phút Song Tu" NOR ", bạn bị trừ đi 50 Kim bảo !");
			break;
		case 101:
			if ( who->get_level()<20 ) 
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Cấp bậc chưa đạt 20 cấp, chưa thể tham gia chức năng Song Tu !");
				return 0;
			} 
			if ( !who->get_save_2("songtu.ten") )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Hiện tại ngươi chưa từng chấp nhận Song Tu với người nào hết !");
				return 0;
			}
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(me->get_name()+":\n Hiện tại người đã cùng ngươi chấp nhận Song Tu là %s (%d). \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save_2("songtu.ten"),who->get_save_2("songtu.id")));
			break;	
	}
}
void songtu(object me, object who, object user)
{
	if ( !objectp(user=check_st(me,who)) ) return 0;
	who->set_save_2("songtu.ten",user->get_name());
	who->set_save_2("songtu.id",user->get_number());
	who->set_save_2("songtu.tk",user->get_id());
	user->set_save_2("songtu.ten",who->get_name());
	user->set_save_2("songtu.id",who->get_number());
	user->set_save_2("songtu.tk",who->get_id());
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Ngươi đã nhận Song Tu cùng "+user->get_name()+", thời gian Song Tu sẽ bắt đầu được tính khi cả 2 người ngồi gần nhau !");
	send_user(user,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n Ngươi đã nhận Song Tu cùng "+who->get_name()+", thời gian Song Tu sẽ bắt đầu được tính khi cả 2 người ngồi gần nhau !");
	send_user(who,"%c%s",';',"Bạn đã nhận Song Tu cùng "+user->get_name()+", thời gian bắt đầu tính khi cả 2 cùng ngồi gần nhau !");
	send_user(user,"%c%s",';',"Bạn đã nhận Song Tu cùng "+who->get_name()+", thời gian bắt đầu tính khi cả 2 cùng ngồi gần nhau !");
}