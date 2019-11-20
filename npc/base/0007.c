
// 自动生成：/make/npc/make0007
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>

inherit OFFICER;

// 函数：修理师傅
int is_repairer() { return 1; }
void do_welcome( string arg );

// 函数：获取人物造型
int get_char_picid() { return 5407; }

// 函数：构造处理
void create()
{
        set_name("Chủ Tiệm Sửa Chữa");
        set_city_name("Tân Thủ Thôn");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//        set("level", 5);
//        set("legend", ({ 49 }));
	set("mpLegend",([5:({32*40+20,32*49+24}),]));
	set("mpLegend2",([0:({32*48+17,}),0:({32*49+26,})]));
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	int id;
	string tmp="";
	object me=this_object();
	id = getoid(me);

	"/quest/help"->send_help_tips(who, 52);
	if ( who->get_legend(TASK_48, 16) && !who->get_legend(TASK_48, 17) )
               		tmp += sprintf(ESC  +HIY+ "Thu mua búa\ntalk %x# welcome.1\n",id) ;	
	if ( who->get_legend(TASK_48, 17) && !who->get_legend(TASK_48, 18) )
               		tmp +=sprintf(ESC  +HIY+ "Yêu Ngôn Mị Dân\ntalk %x# welcome.11\n",id) ;	

//	if ( who->get_level()>=5&&(!who->get_legend(TASK_NEWBIE_01, 17)||!who->get_legend(TASK_NEWBIE_01, 18)) )
//               		tmp += sprintf(ESC "破损的铁锹\ntalk %x# welcome.3\n",id) ;	

	if ( who->get_level()>=5 && !who->get_legend(TASK_40, 20) )
		tmp +=	 sprintf(ESC +HIY+ "Cô Độc\ntalk %x# welcome.5\n",id) ;	
	if ( (who->get_level()>=5&&!who->get_legend(TASK_49,24)) ||( who->get_legend(TASK_49,25) && !who->get_legend(TASK_49,26) ) )
		tmp +=  sprintf(ESC +HIY+ "Đi Đường Khó Khăn\ntalk %x# welcome.13\n",getoid(me));

	if ( sizeof(tmp) )
	{
        	send_user( who, "%c%c%w%s", ':', 3, who->get_char_picid(),
	                " " + get_name() + " :\n "+"/quest/word"->get_normal_word(this_object()) 
	                        + sprintf("\n"ESC"Tu sửa và đánh giá\ntalk %x# welcome.99\n",getoid(this_object())) 
	                        + tmp +
	                        ESC "Rời khỏi");
	}	
	else	
        	REPAIR_CMD->main( who, sprintf( "%x#", getoid( this_object() ) ) );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,p,i,b;
        object who, item, *inv;
        string result;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
	case 1:	
		if ( who->get_legend(TASK_48, 16) && !who->get_legend(TASK_48, 17) )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s :\n Chủ Tiệm Tạp Hóa thật là đáng tin cậy, phái người đến cho ta nhanh\n như thế, vất vả cho ngươi rồi, %s , làm ngươi vật vả thế,\n thù lao đây ngươi hãy cầm lấy!\n Ta vẫn có thể tu sửa đặc biệt trang bị trên người ngươi một lần nữa\n.\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.2\n"ESC"Rời khỏi",me->get_name(),NPC_RANK_D->get_respect_2(who),getoid(me)));
		break;
	case 2:
		if ( who->get_legend(TASK_48, 16) && !who->get_legend(TASK_48, 17) )
		{
			if( !objectp( item = present("Búa Sắt", who, 1, MAX_CARRY) ) || item->is_tiecui() != 1 )
			{
				send_user(who,"%c%s",'!',"Búa Sắt của ngươi đâu?");
				return;	
			}
			item->remove_from_user();
			destruct(item);		
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_48, 17);
			who->add_exp(550);
			who->add_potential(50);
			who->add_cash(2500);
     
	 
		/*	inv=who->get_all_equip();
			for( i = 0 ; i < sizeof(inv)-1; i ++ )
			{
				if (inv[i]==0) continue;
				b=inv[i]->get_max_lasting();
				inv[i]->set_lasting(b);
			} */
			
			send_user(who,"%c%s",';'," Kinh nghiệm 550, Tiềm năng 50, Ngân lượng 2500.");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,107,"" );		
			me->do_welcome(11);
		}
		break;
	case 3:
		if ( who->get_level()>=5 && !who->get_legend(TASK_NEWBIE_01, 17)) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Mấy ngày trước, Ngưu Nhi đã giao lại cái này cho ta, thật sự là ta chưa có thời gian trả, giờ người trả cái này lại cho Ngưu Nhị hộ ta được không? Ngưu Nhị ở Tân THủ Thôn đấy!\n"ESC"Tiếp Nhận\ntalk %x# welcome.4\n"ESC"Rời đi",me->get_name(),getoid(me)));
		else   if (!who->get_legend(TASK_NEWBIE_01, 18)) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Bảo ngươi đi đến chỗ Ngưu Nhị trả đồ cơ mà? Đừng chậm trễ nữa! \n"ESC"Rời đi",me->get_name()));
		break;
	case 4:
		if ( who->get_level() < 5 || who->get_legend(TASK_NEWBIE_01, 17) )  
			return ;
		item = new( "/item/98/9883" );
		if ( !item )
			return ;
                p =item->move(who, -1);
                if ( p == 0 )
                {
                	destruct(item); 
                	send_user( who, "%c%s", '!', "Trên người ngươi không đủ chỗ trống!");
                	return ;
                }	
                item->add_to_user(p);
		who->set_legend(TASK_NEWBIE_01, 17);
		send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,9,"Xẻng Hư Hại" );
		send_user( who, "%c%s", '!', "Ngươi nhận nhiện vụ "HIY"Xẻng Hư Hại"NOR".");
		break;
        case 5:
        	if ( who->get_level()>=5 && !who->get_legend(TASK_40, 20) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Cô độc, luôn cô độc. \n    Ta đã theo sư phụ từ nhỏ học tập sữa chữa Vũ Khí, Y Phục.\n    Nay tưởi tác đã già, làm ăn cũng khá giả, nhưng chỉ còn 1 thân 1 mình, không biết bạn đồng lứa ra sao, giờ ta muốn ngươi đem Tín Thơ đến Thanh Khê đưa cho Khổng Lão Đầu giúp ta?\n"ESC"Tiếp Nhận Nhiệm Vụ\ntalk %x# welcome.6\n"ESC"Rời đi", me->get_name(),getoid(me)));
	       	break;
        case 6:
        	if ( who->get_level()>=5 && !who->get_legend(TASK_40, 20) )
        	{
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
        			return ;
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			TASK_LEGEND_D->give_item(who,"item/98/0197",1);
        		who->set_legend(TASK_40,20);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,34,"Cô Độc" );
			send_user( who, "%c%s", '!', "Ngươi nhận nhiệm vụ "HIY"Cô Độc");
        	}
        	break;
        case 11:
		if ( who->get_legend(TASK_48, 17) && !who->get_legend(TASK_48, 18) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    U Cốc đám tiểu quái vật kia rất vui vẻ, chúng ta thường hay chơi cùng chúng.\n    Nhưng giờ tất cả đã thay đổi, bọn chúng tấn công loài người, như kiểu bị yêu ma khống chế, ngươi hãy đi tới U Cốc giết Ong Mật, Kiến Nhỏ, Ếch Đốm rồi đi báo cho Vệ Đội Trưởng xem hắn xử lí thế nào!\n    Làm xong nhiệm vụ, bấm Alt+W sử dụng tín vật để về TTT nha!\n"ESC"Tiếp Nhận Nhiệm Vụ\ntalk %x# welcome.12\n"ESC"Rời khỏi", me->get_name(),getoid(me)));
        	break;
        case 12:
		if ( who->get_legend(TASK_48, 17) && !who->get_legend(TASK_48, 18) )
		{
	                if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
	                who->set_legend(TASK_48, 18);
	                who->delete_save("new_chy");
	                send_user( who, "%c%s", '!', "Chọn nhiệm vụ "HIY"Yêu Ngôn Mị Dân"NOR"!");
	                send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
	                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,108,"Yêu Ngôn Mị Dân" );
		}
                break;   
        case 13:
		if( who->get_level()>=5 && !who->get_legend(TASK_49, 24) )
        		send_user(who,"%c%s",':',sprintf("%s\n    Tân Thủ Thôn phía Bắc Ba Khâu có Động Đình Hồ, người ta lui tới thường xuyên không biết thế nào, nơi đó có Kiến Đen, Ếch Tử Mẫu bắt đầu tập kích người làm ko ai tới lui được, ngươi hãy đi Ba Khâu giết Ếch Tử Mẫu, Kiến Đen và Người Rơm để giải quyết nhé.\n"ESC"Tiếp nhận nhiệm vụ\ntalk %x# welcome.14\n"ESC"Rời đi",me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_49, 25) && !who->get_legend(TASK_49, 26) )
        		send_user(who,"%c%s",':',sprintf("%s\n    Lần này tốt lắm, Bằng Hữu rốt cuộc cũng có thể tới thăm ta, có ngươi giúp một tay, muốn sửa đồ gì cứ tới gặp ta!\n"ESC"Hoàn Thành Nhiệm Vụ\ntalk %x# welcome.15\n"ESC"Rời đi",me->get_name(),getoid(me)));
        	break;
	case 14:
		if( who->get_level()>=5 && !who->get_legend(TASK_49, 24) )
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_49, 24);
			who->delete_save("xiuli_zimuwa");
			who->delete_save("xiuli_chy");
			who->delete_save("xiuli_cscr");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"Tân Thủ Thôn" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,48,"Đi Đường Khó Khăn" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ  "HIY"Đi Đường Khó Khăn");	
		}
		break;
	case 15:
		if ( who->get_legend(TASK_49, 25) && !who->get_legend(TASK_49, 26) )
		{
			TASK_LEGEND_D->task_finish(who);
			who->delete_save("xiuli_zimuwa");
			who->delete_save("xiuli_chy");
			who->delete_save("xiuli_cscr");
			who->add_exp(250);
			who->add_potential(40);
			who->add_cash(600);
			who->set_legend(TASK_49, 26);
			send_user(who,"%c%s",';',"Đi Đường Khó Khăn Kinh Nghiệm 250 Tiềm Năng 40 Ngân Lượng 600");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,48,"" );			
		}
		break;
        case 99:
        	REPAIR_CMD->main( who, sprintf( "%x#", getoid( me ) ) );
        	break;
	}
}  	
