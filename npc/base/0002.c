
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 5; }
// 有自己的do_look函数
int is_self_look() { return 1; }
// 函数：获取人物造型
int get_char_picid() { return 5402; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Chủ Tiệm Tạp Hóa");
        set_city_name("Tân Thủ Thôn");

        set_2( "good", ([
                "01" : "/item/std/0401",
                "02" : "/item/std/0407",
                "04" : "/item/std/0409",
                "05" : "/item/std/0413",
                "06" : "/item/std/0591",
                "07" : "/item/32/3231",
                "08" : "/item/98/9871",
                "09" : "/item/std/9808",
		"10" : "/item/std/9819",
		"11" : "/item/std/9820",
		"12" : "/item/49/4900",
		"13" : "/item/std/0410",
		"14" : "/item/08/0010",
		"15" : "/item/08/0011",
		"16" : "/item/08/0012",
		"17" : "/item/44/4403",
		"18" : "/item/44/4406",
//		"19" : "/item/44/4405",
        ]) );
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//        set("level", 0);
//        set("legend", ({ 32*41+11 }));
	set("mpLegend",([5:({32*49+15}),]));
	set("mpLegend2",([0:({32*48+14,32*49+17}),]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me = this_object();
	string result="";
	"/quest/help"->send_help_tips(who, 41);
	result = sprintf(" %s :\n "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	if ( who->get_legend(TASK_48, 13) && !who->get_legend(TASK_48, 14) )
	{
		result = result + sprintf( ESC +HIY+  "Bồ Câu Đưa Thư\ntalk %x# welcome.1\n", getoid(me) );
	}
//	if ( !who->get_legend(TASK_NEWBIE_01, 14) )
	if ( who->get_legend(TASK_48, 14) && !who->get_legend(TASK_48, 15) )
	{
		result = result + sprintf( ESC  +HIY+ "Búa Sắt của Chủ Tiệm Sữa Chữa\ntalk %x# welcome.3\n", getoid(me) );
	}	
	if ( who->get_legend(TASK_NEWBIE_01, 14) && !who->get_legend(TASK_NEWBIE_01, 15) )
	{
		result = result + sprintf( ESC  +HIY+ "Búa Sắt của Chủ Tiệm Sữa Chữa\ntalk %x# welcome.5\n", getoid(me) );
	}
	if ( who->get_level() >=5 && !who->get_legend(TASK_49, 17) )
	{
		result = result + sprintf( ESC +HIY+ "Phiền Não Kiến Con\ntalk %x# welcome.8\n", getoid(me) );
	}
/*	if ( who->get_level() >=5 && !who->get_legend(TASK_41, 11) )
	{
		result = result + sprintf( ESC "运箱子\ntalk %x# welcome.6\n", getoid(me) );
	}*/

	result = result + sprintf( ESC "Giao dịch\nlist %x#\n" ESC "Ta chỉ tiện xem qua\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%s", ':', result );

}

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
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:
//		if ( !who->get_legend(TASK_NEWBIE_01, 12)||who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
		if ( who->get_legend(TASK_48, 13) && !who->get_legend(TASK_48, 14) )
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Khụ....Khụ....Khụ Tín Thơ ư? Mỗi ngày ta đều chờ Xuất Hóa Đơn, ai là người đưa vậy? Là huynh đệ của ta ở Chu Quốc, sau này ngươi sẽ có cơ hội thấy hắn! Tới lấy thù lao đi.\n"ESC"Hoàn Thành Nhiệm Vụ\ntalk %x# welcome.2\n"ESC"Rời khỏi",me->get_name(),getoid(me)));
		break;
	case 2:
//		if ( !who->get_legend(TASK_NEWBIE_01, 12)||who->get_legend(TASK_NEWBIE_01, 13) )
//			return;
		if ( who->get_legend(TASK_48, 13) && !who->get_legend(TASK_48, 14) )
		{
			if( !objectp( item = present("Giấy Xuất Hàng", who, 1, MAX_CARRY) ) || item->is_huodan() != 1 )
			{
				send_user(who,"%c%s",'!',"Giấy Xuất Hàng của ngươi đâu?");
				return;			
			}	
			item->remove_from_user();
			destruct(item);			
			item = new("/item/08/0010");
			p =item->move(who, -1);
                        item->add_to_user(p);	
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48, 14);	
			who->add_exp(290);
			who->add_potential(20);
			who->add_cash(200);
			send_user(who,"%c%s",';',"Dùng Bồ Câu Đưa Thư Kinh Nghiệm 290 Tiềm Năng 20 Ngân Lượng 200 Giám Định Kính thường 1");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,106,"" );
			me->do_welcome(3);
		}
		break;
	case 3:
//		if ( who->get_legend(TASK_NEWBIE_01, 14) )
//			return;		
		if ( who->get_legend(TASK_48, 14) && !who->get_legend(TASK_48, 15) )
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Trước đó vài ngày, Chủ Tiệm Sữa Chữa có tới đây mua 1 cây Búa Sắt, đáng tiếc chỗ ta không có, ở Thanh Khê có hai con Kiến Nhỏ và Ong Mật nghe nói có Búa Sắt trên người chúng, ngươi hãy đi đánh và lấy lại giao cho Chủ Tiệm Sữa Chữa nha.\n    Xong nhiệm vụ bấm Alt + W để về Tân Thủ Thôn！\n"ESC"Tiếp Nhận Nhiệm Vụ\ntalk %x# welcome.4\n"ESC"Rời khỏi",me->get_name(),getoid(me)));
		break;
	case 4:
//		if ( who->get_legend(TASK_NEWBIE_01, 14) )
//			return;
		if ( who->get_legend(TASK_48, 14) && !who->get_legend(TASK_48, 15) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_48, 15);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,107,"Búa Sắt của Chủ Tiệm Sữa Chữa" );
			send_user( who, "%c%s", '!', "Ngươi nhận lấy "HIY"Búa Sắt của Chủ Tiệm Sữa Chữa"NOR" nhiệm vụ.");
		}
		break;	
	case 5:
		if ( who->get_legend(TASK_NEWBIE_01, 14) && !who->get_legend(TASK_NEWBIE_01, 15) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    是他们太强了吗？你可得赶快哦，我答应了修理店老板，可不想失信于他。\n"ESC"Rời khỏi",me->get_name(),));
		break;
        case 6:
        	if ( who->get_level() >=5 && !who->get_legend(TASK_41,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    村外的刘大叔托我买的东西，我已经全部收集齐了，把它们全放在这个箱子里了，你能给我运过去吗？\n    刘大叔就住在往巴丘去的大路旁边，和李老汉是很好的邻居呢，如果你以前往那个方向走过，你应该很容易就找到他的，不过没去过也不要紧，你往那条路上走，见到两个独门独户的房子，就是刘大叔家了。\n"ESC"Tiếp Nhận Nhiệm Vụ\ntalk %x# welcome.7\n"ESC"Rời khỏi", me->get_name(), getoid(me)));
        	break;
	case 7:
        	if ( who->get_level() >=5 && !who->get_legend(TASK_41,11) )
        	{
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			TASK_LEGEND_D->give_item(who,"item/98/0201",1);
        		who->set_legend(TASK_41,11);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,33,"运箱子" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ "HIY"运箱子");
        	}
        	break;			
        case 8:
		if( who->get_level() >=5 && !who->get_legend(TASK_49, 15) )
        		send_user(who,"%c%s",':',sprintf("%s\n    Ta từ nhỏ thích ăn mật ong, một lần trốn ba má lên cây để ăn, rồi khi về để quên. Bị bọn Kiến Nhỏ ở U Cốc lấy ăn mất, ta rất buồn, ngươi hãy đi U Cốc đánh chúng nó đòi lại 10 lọ Mật Ong cho ta, vậy ta có thể an tâm rồi.\n"ESC"Tiếp Nhận Nhiệm Vụ\ntalk %x# welcome.9\n"ESC"Rời khỏi",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_49, 16) && !who->get_legend(TASK_49, 17) )
        		send_user(who,"%c%s",':',sprintf("%s\n    Ngươi đã giết hết Kiến Nhỏ ư? TỐt qua, số tiền này cảm ơn ngươi!\n"ESC"Hoàn Thành Nhiệm Vụ\ntalk %x# welcome.10\n"ESC"Rời khỏi",me->get_name(),getoid(me)));
        	break;
	case 9:
		if ( who->get_level() >=5 && !who->get_legend(TASK_49, 15) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_49, 15);
			who->delete_save("xsc_mayi");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,45,"Phiền Não Kiến Con" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ "HIY"Phiền Não Kiến Con");	
		}
		break;
	case 10:
		if ( who->get_legend(TASK_49, 16) && !who->get_legend(TASK_49, 17) )
		{
			TASK_LEGEND_D->task_finish(who);
			who->delete_save_2("xsc_mayi");
			who->add_exp(150);
			who->add_potential(25);
			who->add_cash(800);
			who->set_legend(TASK_49, 17);
			send_user(who,"%c%s",';',"Phiền Não Kiến Con Kinh Nghiệm 150 Tiềm Năng 25 Ngân Lượng 800");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,45,"" );			
		}
		break;
	}
}
