
// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>

inherit OFFICER;

void do_task_start(string arg);
void accept_task();
void join_task();
void do_welcome( string arg );
void do_task_list();

// 函数：获取人物造型
int get_char_picid() { return 6800; }

// 函数：构造处理
void create()
{
        set_name("Vận Tiêu Lão Đầu");
        set_city_name("－－");

        set_2( "talk", ([
                "task"          : (: do_task_start :),
                "accept"        : (: accept_task :),
                "join"		: (: join_task :),
                "welcome"          : (: do_welcome :),
                "tasklist"          : (: do_task_list :),
        ]));      
	set("mpLegend",([30:({32}),]));
        setup();
}

// 函数：对话处理
   void do_look( object who ) { TASK_ESCORT_D->do_look( who, this_object() ); }

// 函数：开始任务
   void do_task_start(string arg) { TASK_ESCORT_D->do_task_start( this_player(), this_object(),arg ); }
// 函数：接受任务
   void accept_task() { TASK_ESCORT_D->accept_task( this_player(), this_object() ); }
// 函数：加入任务
   void join_task() { TASK_ESCORT_D->join_task( this_player(), this_object() ); }

   void do_task_list() { TASK_ESCORT_D->do_task_list( this_player(), this_object() ); }
   
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item;     
        string cmd1, cmd2, cmd3, cmd4, cmd5, result;
        who = this_player();
	if (arg=="cancel")
	{
	        item = who->get_equip(HAND_TYPE);
		if (item && item->get_item_number()==10001078)
		{	
			send_user( who, "%c%c%s", 0x59, 1, sprintf("Ngươi có sử dụng 'Mãn Thiên Quá Hải Phù' để hủy bỏ thời gian chờ nhiệm vụ ko?\n"
	                	ESC "%c\n"ESC"use %x# escort2\n"
	                        , 1, getoid(item) ) );			
			return;
		}		
	}        
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Gần đây Thần Tiên Gia Gia giới thiệu không ít người tới đây nhưng sự thật không phải ai cũng được việc, ta mong ngươi sẽ khá hơn!……\n"ESC"Hoàn Thành Nhiệm Vụ\ntalk %x# welcome.2\n"ESC"Rời đi",me->get_name(),getoid(me)));
		break;
	case 2:
		if ( !who->get_legend(TASK_NEWBIE_00, 13) || who->get_legend(TASK_NEWBIE_00, 14) )
			return;
		TASK_LEGEND_D->task_finish(who);
		who->set_legend(TASK_NEWBIE_00, 14);
		who->add_exp(250);
		who->add_potential(30);
		send_user(who,"%c%s",';',"Tìm Úy Trì Lão Tiêu Đầu Nói Chuyện Kinh nghiệm 250 Tiềm năng 30");
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,2,"" );		
		me->do_welcome(3);
		break;		
	case 3:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Ta sẽ cung cấp cho ngươi cơ hội kiếm tiền, gần đây có bọn chuột nhắt lười biếng ko chịu làm việc, hãy giúp ta hộ tống phiêu ngân lần này, ta sẽ miễn phí lần đầu cho ngươi luôn.\n    Ngươi hãy đem Phiêu Ngân đến bên ngoài thành Hàn, tại Lê Hoa Thôn, giao cho Mã Đại Hán, hãy nhớ trong quá trình vận tiêu thì ko đc dùng dịch tram, kĩ năng hay vật phẩm dịch chuyển, nếu ko nhiệm vụ sẽ thất bại!\n"ESC"Tiếp nhận nhiệm vụ\ntalk %x# welcome.4\n"ESC"Hủy bỏ",me->get_name(),getoid(me)));
		break;		
	case 4:
		if ( who->get_level()>=30 && !who->get_legend(TASK_49,13) && !who->get_quest("escort.flag"))
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			if( sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY )
	                {
	                        send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+":\n    Trên người ngươi nhiều đồ quá, hãy dọn bớt đi.");
	                        return;
	                }
			
	                item = new( "/item/98/0237" );
	                if( p = item->move(who, -1) ) item->add_to_user(p);
			who->set_legend(TASK_49,13);
		        who->set_quest("escort.time", time() );
			send_user( who, "%c%s", '!', "Ngươi đã nhận nhiệm vụ "HIY"Tìm Tòi Thực Hư"NOR".");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"Chu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,15,"Tìm Tòi Thực Hư" );
		}
		break;		
	case 5:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Gần đây Sư Gia giới thiệu không ít người tới đây, nhưng ko phải ai cũng làm được việc, mong rằng ngươi không làm ta thất vọng!\n"ESC"Hoàn Thành Nhiệm Vụ\ntalk %x# welcome.6\n"ESC"Rời đi",me->get_name(),getoid(me)));
		break;
	case 6:
		if ( who->get_legend(TASK_2_00,14) && !who->get_legend(TASK_2_00,15) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,15);
			who->add_exp(300);
			who->add_potential(35);
			who->add_cash(500);
			send_user(who,"%c%s",';',sprintf("Bái Kiến Úy Trì Lão Tiêu Đầu Kinh Nghiệm 300 Tiềm Năng 35 Ngân Lượng 500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,17,"" );
			me->do_welcome(7);
		}
		break;		
	case 7:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Nghe nói gần đây có người có cổ vật Kính CHiếu Yêu Di Vật, bên trong tồn tại Yêu Ma quỷ quái, trong tay Tả Khẩu Minh ở CHu Quốc là kinh diệt yêu, ngươi hãy đi về phía đông, hắn đứng trước cây cổ thụ đấy, hãy hỏi thăm hắn!\n"ESC"Tiếp Nhận Nhiệm Vụ\ntalk %x# welcome.8\n"ESC"Rời đi",me->get_name(),getoid(me)));
		break;		
	case 8:
		if ( who->get_legend(TASK_2_00,15) && !who->get_legend(TASK_2_00,16) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,16);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"Chu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,18,"Bái Kiến Tả Khẩu Minh" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ "HIY" Bái Kiến Tả Khẩu Minh");
		}
		break;	

	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		TASK_ESCORT_D->biaowang(me,who,flag);
		break;

	}
}
