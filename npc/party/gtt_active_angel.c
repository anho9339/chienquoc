/*-----------------------------------------------------------------------------------------*\
	《真假虎王》活动配置NPC ---- Thiên Sứ Hoạt Động
	由cjxx创建
	使用此文件时需要配合活动主控文件。
\*-----------------------------------------------------------------------------------------*/
#include <npc.h>
#include <ansi.h>

inherit SAVE_F;
inherit OFFICER;

#define GUESS_TRUE_TIGER	"/sys/party/guess_true_tiger"
#define _DEBUG(str) 		;//if(objectp(find_char("1"))) {tell_user(find_char("1"),str);}

void do_tiger_active(string arg);	//	真假虎王相关对话操作

int get_char_picid() { return 0951; }

void create() {
	set_name("Thiên Sứ Hoạt Động");
	
	set_2("talk", ([
		"tiger" : (: do_tiger_active :),
	]));
	setup();
}

//	玩家点击NPC
void do_look(object who) {
	__FILE__->do_look_reflash(who,this_object());
}
//	do_look 的在线更新函数
void do_look_reflash(object who,object me) {
	int id = getoid(me);
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf(
		"%s: \n Hihi, ta là thiên sứ hoạt động siêu dễ thương, tên thiên sứ ở Tân Thủ Thôn xấu xí hơn ta nhiều, từ xưa tới nay ta phụ trách nhiều hoạt động lớm, nếu như ngươi không rõ thứ gì, có thể tới hỏi thăm ta!\n"
		ESC"Hổ Vương Thật Giả\ntalk %x# tiger.1\n"
		ESC"Rời Đi",me->get_name(),id
	));
}
//	调用下一关的函数
void play_next_stage(object who,int level) {
	GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
	GUESS_TRUE_TIGER->active_main_logic(who,level);
	who->set("now_call_out_next_stage",0);
}
//	玩家放弃活动
void give_up_the_activity(object who) {
	string *active_bonus,say_word;
	int level = who->get_save("guess_true_tiger");	
	if(level > 0) {
		active_bonus = active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
		if(level > 1) {		
			say_word = sprintf("Ngươi vượt ải thành công, nhận được %s ngân lượng cùng với danh hiệu “"HIR"%s"NOR"”, hãy đi tới Thiên Sứ Hoạt Động để đổi phần thưởng.",active_bonus[2],active_bonus[1]);
		} else {			
			say_word = sprintf("Ngươi vượt ải thành công, đạt được danh hiệu “"HIR"%s"NOR"” , hãy đi tới Thiên Sứ Hoạt Động để đổi phần thưởng.",active_bonus[1]);
		}
		GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
		send_user(who,"%c%s",';',say_word);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),say_word);
		who->delete("guess_true_tiger_map");
	} else {
		_DEBUG("DEBUG -- Lỗi! Người chơi không nhận được phần thưởng qua ải");
	}
}
//	隔段时间回调下一关
void call_out_next_stage(object who) {	
	string *active_bonus,say_word;
	int level = who->get_save("guess_true_tiger");
	if(level >=6) {
		active_bonus = active_bonus = GUESS_TRUE_TIGER->get_active_bonus(level);
		say_word = sprintf("Ngươi vượt ải thành công, nhận được %s ngân lượng cùng với danh hiệu “"HIR"%s"NOR"”, hãy đi tới Thiên Sứ Hoạt Động để đổi phần thưởng.",active_bonus[2],active_bonus[1]);
		send_user(who,"%c%s",';',say_word);
		MAILBOX->sys_mail(who->get_id(),who->get_number(),say_word);		
	} else {
		if(get_z(who) == who->get("guess_true_tiger_map")) {
			if(who->get("guess_true_tiger_nojump")) {
				return;
			}
			GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
			if(!who->get("now_call_out_next_stage")) {
				send_user(who,"%c%s",'!',sprintf("5 giây sau tiến vào ải thứ %d .",level+1));
				call_out("play_next_stage",5,who,level+1);
				who->set("now_call_out_next_stage",1);
			} else {
				who->add("define_tiger_attacking",1);
				if(who->get("define_tiger_attacking")>5) {
					play_next_stage(who,7);
					who->set("define_tiger_attacking",0);
				}
			}
		} else {
			_DEBUG("DEBUG -- 玩家已经不在活动场地");
			GUESS_TRUE_TIGER->delete_tigers_on_player(who,0);
			play_next_stage(who,7);
		}
	}
}
//	《真假虎王》过一关后的对白操作
void do_next_stage(object who) {
	__FILE__->do_next_stage_reflash(who,this_object());
}
//	do_next_stage 的在线更新函数
void do_next_stage_reflash(object who,object me) {
	int id = getoid(me);
	int level = who->get_save("guess_true_tiger");
	if(level>0) {
		if(level < 6) {
			send_user(who, "%c%s", ':',sprintf("Ngươi đã qua ải thành công, có muốn tiếp tục ải thứ %d ? Nếu như thất bại, ngươi mất tất cả phần thưởng, nhưng nếu thành công phần thưởng sẽ vô cùng phong phú.\n"
				ESC"Tiếp Tục\ndesc tiger_next\n"
				ESC"Rời đi\ndesc tiger_drop\n",level+1
			));
		} else {
			give_up_the_activity(who);
		}
	}
}
//	《真假虎王》相关对话操作
void do_tiger_active(string arg) {
	__FILE__->do_tiger_active_reflash(this_object(),arg);
}
//	《真假虎王》活动在线更新函数
void do_tiger_active_reflash(object me, string arg) {
	object who,*tmp_team,vpcanthiet;
	string say_word;
	int flag,id,level;
	who  = this_player();
	flag = to_int(arg);	
	id   = getoid(me);
	switch(flag) {
		case 1:	//	主对白
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \nHổ Vương Thật Giả là một hoạt động như một bài kiểm tra, ngươi có thể ở lại đây ta giải thích cặn kẽ cho.\n"
				ESC"Nói rõ về hoạt động\ntalk %x# tiger.2\n"
				ESC"Tham gia hoạt động\ntalk %x# tiger.3\n"
				ESC"Rời Khỏi",me->get_name(),id,id
			));
			break;
		case 2:	//	活动说明
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \nHổ Vương Thật Giả là hoạt động một người tham gia, không thể tổ đội, ta sẽ thu 10000 ngân lượng như tiền vé vào cửa.\n    Tiến vào bên trong hoạt động, trước mặt ngươi sẽ xuất hiện 7 con hổ vương giống nhau nhưng năng lực khác nhau, ngươi phải chọn 1 con để chiến đấu, đánh bại nó sẽ qua ải....Còn nữa..\n"
				ESC"Đọc tiếp\ntalk %x# tiger.20\n"
				ESC"Rời Khỏi",me->get_name(),id,id
			));
			break;
		case 20:	//	活动说明
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \nCửa thứ nhất trong 7 con chỉ có 1 con có sức mạnh siêu hạng, 6 con còn lại có thể đánh bại dễ dàng, cửa thứ 2 thì có 2 con có sức mạnh siêu hạng, còn lại 5 con có thể đánh bại dễ dàng, cứ như thế cho tới cửa thứ 6 là cửa cuối cùng.\n    Nếu như ngươi có thể vượt qua 6 ải, ngươi có thể nhận được phần thưởng cực lớn, dĩ nhiên, ngươi cũng có thể bỏ cuộc giữa chừng và nhận được phần thưởng tại mốc mà ngươi vượt qua, nhưng nếu tiếp tục qua ải và thất bại, ngươi sẽ mất tất cả.\n"
				ESC"Rời Khỏi",me->get_name()
			));
			break;
		case 3:	//	参加活动
			if(GUESS_TRUE_TIGER->is_in_active_area()) {
				level= who->get_save("guess_true_tiger");
				if(level >1) {
					say_word = "Lần trước ngươi vượt ải không nhận phần thưởng, lần này tiếp tục khiêu chiến sẽ mất phần thưởng lần trước đó?";
				} else {
					say_word = "Khiêu chiến hổ vương cần 10.000 ngân lượng và Phiếu Trò Chơi, ngươi vào bên trong có thể triệu hồi bằng hữu trợ giúp!";
				}
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \n%s\n"
					ESC"Khiêu Chiến\ntalk %x# tiger.4\n"
					ESC"Rời Khỏi",me->get_name(),say_word,id
				));
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \nBây giờ không thể tham gia hoạt động Hổ Vương Thật Giả, %s mới có thể bắt đầu.\n"
					ESC"Rời Khỏi",me->get_name(),GUESS_TRUE_TIGER->get_active_time()
				));
			}
			break;
		case 4:	//	选择Khiêu Chiến
			vpcanthiet = present("Phiếu Trò Chơi", who, 1, MAX_CARRY);  
			if(GUESS_TRUE_TIGER->is_in_active_area()) {
				tmp_team = who->get_team();
				if(tmp_team != 0 && sizeof(tmp_team)>1) {
					send_user(who, "%c%s", '!', "Ngài ở trong đội ngũ, không thể tham gia hoạt động.");
				} else {
					if(who->get_cash() >= 10000 && vpcanthiet) {
						GUESS_TRUE_TIGER->active_main_logic(who,1);
					} else if (!vpcanthiet) {
						send_user(who, "%c%s", '!', "Ngươi không có Phiếu Trò Chơi");
					} else {
						send_user(who, "%c%s", '!', "Ngươi không đủ 10000 ngân lượng");
					}
				}
			} else {
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \nBây giờ không thể tham gia hoạt động Hổ Vương Thật Giả, %s mới có thể bắt đầu.\n"
					ESC"Rời Khỏi",me->get_name(),GUESS_TRUE_TIGER->get_active_time()
				));				
			}
			break;
	}
}