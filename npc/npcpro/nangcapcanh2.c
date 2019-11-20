
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5405; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Nâng Cấp Cánh Phi Phong");
		set_real_name("Thiên Đế Sư");
        set_2( "talk", ([
				"welcome"          : (: do_welcome :),
        ]));

       setup();
}

// 函数：对话处理
void do_look( object who )
{
	int id = getoid( this_object() );
	send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Thế giới này luôn thay đổi và hỗn loạn, ta tự xưng là Thiên Đế Sư hiệu là Đế Pháp, anh trai của Thiên Linh Sư, vậy ngươi tìm ta có chuyện gì không?\n"
		ESC"Nâng cấp cánh\ntalk %x# welcome.70\n"
		ESC"Nâng cấp phi phong\ntalk %x# welcome.80\n"
		ESC"Công thức và nguyên liệu nâng cấp\ntalk %x# welcome.81\n"
		ESC"Rời khỏi\n",id,id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,p;
	object who,item;
	string cTmp,cFinal,cFile;
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
		case 70:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC"Cánh Nam\ntalk %x# welcome.75\n"
				ESC"Cánh Nữ\ntalk %x# welcome.76\n"
				ESC"Thoát\n",id,id,id));
			break;
		case 75:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Nghịch Giới Chi Dực\ntalk %x# welcome.801\n"
			//	ESC"Nâng cấp Hoả Lân Chi Dực\ntalk %x# welcome.802\n"
			//	ESC"Nâng cấp Thần Long Chi Dực\ntalk %x# welcome.809\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 76:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Tru Tiên Chi Dực\ntalk %x# welcome.803\n"
			//	ESC"Nâng cấp Huyết Phụng Chi Dực\ntalk %x# welcome.804\n"
			//	ESC"Nâng cấp Huyết Thần Chi Dực\ntalk %x# welcome.810\n"		
				ESC"Thoát\n",id,id,id,id));
			break;
		case 80:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC"Phi Phong Nam\ntalk %x# welcome.85\n"
				ESC"Phi Phong Nữ\ntalk %x# welcome.86\n"				
				ESC"Thoát\n",id,id,id));
			break;
		case 85:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Thiên Tôn Phi Phong\ntalk %x# welcome.805\n"
			//	ESC"Nâng cấp Sát Thần Phi Phong\ntalk %x# welcome.806\n"
			//	ESC"Nâng cấp Vương Tử Phi Phong\ntalk %x# welcome.811\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 86:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Nữ Thần Phi Phong\ntalk %x# welcome.807\n"
			//	ESC"Nâng cấp Linh Quy Phi Phong\ntalk %x# welcome.808\n"
			//	ESC"Nâng cấp Vương Mẫu Phi Phong\ntalk %x# welcome.814\n"				
				ESC"Thoát\n",id,id,id,id));
			break;
		case 81:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Ngươi muốn tìm hiểu gì? Ta sẽ cho ngươi biết mọi thứ về nâng cấp thú cưỡi.\n"
				ESC"Tìm nguyên liệu ở đâu?\ntalk %x# welcome.812\n"
      			ESC"Số lượng nguyên liệu cần có\ntalk %x# welcome.813\n"
			    ESC"Tiểu sử về Thần Dực và Thần Phong cấp 4!?\ntalk %x# welcome.831\n"		
				ESC"Thoát\n",id,id));
			break;
		case 801:
		case 802:
		case 803:
		case 804:
		case 805:
		case 806:
		case 807:
		case 808:
		case 809:
		case 810:
		case 811: 
		case 814:
		//Cánh lv 4
		if ( flag == 801 )
		{
			cTmp = "Nghịch Giới Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv4";
		}
		else if ( flag == 802 )
		{
			cTmp = "Hoả Lân Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv2";
		}
		else if ( flag == 803 )
		{
			cTmp = "Tru Tiên Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv4";
		}
		else if ( flag == 804 )
		{
			cTmp = "Huyết Phụng Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv2";
		}
		//Pp lv 4
		else if ( flag == 805 )
		{
			cTmp = "Thiên Tôn Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv4";
		}
		else if ( flag == 806 )
		{
			cTmp = "Sát Thần Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv2";
		}
		else if ( flag == 807 )
		{
			cTmp = "Nữ Thần Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv4";
		}
		else if ( flag == 808 )
		{
			cTmp = "Linh Quy Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv2";
		}
		/*
		else if ( flag == 809 )
		{
			cTmp = "Thần Long Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv3";
		}
		else if ( flag == 810 )
		{
			cTmp = "Huyết Thần Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv3";
		}
	
		else if ( flag == 811 )
		{
			cTmp = "Vương Tử Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv3";
		}
		else if ( flag == 814 )
		{
			cTmp = "Vương Mẫu Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv3";
		} */
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Vải Thiên Thần") < 50 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Đá Thiên Mệnh") < 50 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Lông Huyền Vũ") < 50 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thiên Đế Sư:\n Nguyên liệu của ngươi không đủ nâng cấp! Nâng cấp %s cần các loại nguyên liệu:\n "+cTmp+", 50 Vải Thiên Thần, 50 Lông Huyền Vũ và 50 Đá Thiên Mệnh.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Vải Thiên Thần",50);
		TASK_LEGEND_D->check_task_item1(who,"Đá Thiên Mệnh",50);
		TASK_LEGEND_D->check_task_item1(who,"Lông Huyền Vũ",50);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(2);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn nâng cấp thành công "HIR+item->get_name());
			break;
		case 812:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Nâng cấp Thần Phong và Thần dực rất khó tìm nguyên liệu. Hãy tham gia event tử tù nhận Túi Hi Vọng và mở ra có cơ hội nhận đc nguyên liệu!\n"ESC"Thoát ra"));
			break;
		case 813:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Cần có 50 Vải Thiên Thần, 50 Lông Huyền Vũ và 50 Đá Thiên Mệnh, nếu thiếu 1 trong 3 thì không thể nâng cấp được.\n"ESC"Thoát ra"));
			break;
		case 831:
			send_user(who,"%c%s",':',sprintf("Thiên Đế Sư:\n Thế giới ko ngừng đổi thay, nay đã tới hồi 5 của CQ Pro, ta phụng mệnh Tiên Đế xuống đây giúp em ta là Thiên Linh Sư về nâng cấp trang bị Thần cho các chư vị. Liệu các chư vị có thứ gì muốn nhờ ta chăng? Ta có thể làm mọi thứ đấy!\n"ESC"Thoát ra"));
			break;
        }	
}
