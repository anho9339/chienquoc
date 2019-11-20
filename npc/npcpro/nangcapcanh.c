
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
		set_real_name("Thiên Linh Sư");
        set_2( "talk", ([
				"welcome"          : (: do_welcome :),
        ]));

       setup();
}

// 函数：对话处理
void do_look( object who )
{
	int id = getoid( this_object() );
	send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Vạn vật luân hồi, chúng cần phải được đổi mới để theo kịp thời đại. Trong thời buổi loạn lạc này, càng mạnh thì càng có thế, vậy ngươi tìm ta có chuyện gì không?\n"
		ESC"Nâng cấp Cánh\ntalk %x# welcome.70\n"
		ESC"Nâng cấp Phi Phong\ntalk %x# welcome.80\n"
		ESC"Gia hạn Cánh\ntalk %x# welcome.50\n"
		ESC"Gia hạn Phi Phong\ntalk %x# welcome.60\n"
		ESC"Công thức và nguyên liệu nâng cấp\ntalk %x# welcome.81\n"
		ESC"Rời khỏi\n",id,id,id,id,id,id));
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
		// Gia Hạn
		case 50:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC"Gia hạn Cánh Nam\ntalk %x# welcome.51\n"
				ESC"Gia hạn Cánh Nữ\ntalk %x# welcome.52\n"
				ESC"Thoát\n",id,id,id));
			break;
		case 60:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC"Gia hạn Phi Phong Nam\ntalk %x# welcome.61\n"
				ESC"Gia hạn Phi Phong Nữ\ntalk %x# welcome.62\n"
				ESC"Thoát\n",id,id,id));
			break;
		case 51:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Gia hạn Hoả Lân Chi Dực\ntalk %x# welcome.601\n"
				ESC"Gia hạn Thanh Long Chi Dực\ntalk %x# welcome.602\n"
				ESC"Gia hạn Nghịch Giới Chi Dực\ntalk %x# welcome.609\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 52:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Gia hạn Huyết Phụng Chi Dực\ntalk %x# welcome.603\n"
				ESC"Gia hạn Huyết Thần Chi Dực\ntalk %x# welcome.604\n"
				ESC"Gia hạn Tru Tiên Chi Dực\ntalk %x# welcome.610\n"		
				ESC"Thoát\n",id,id,id,id));
			break;
		case 61:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Gia hạn Sát Thần Phi Phong\ntalk %x# welcome.605\n"
				ESC"Gia hạn Vương Tử Phi Phong\ntalk %x# welcome.606\n"
				ESC"Gia hạn Thiên Tôn Phi Phong\ntalk %x# welcome.611\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 62:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Gia hạn Linh Quy Phi Phong\ntalk %x# welcome.607\n"
				ESC"Gia hạn Vương Mẫu Phi Phong\ntalk %x# welcome.608\n"
				ESC"Gia hạn Nữ Thần Phi Phong\ntalk %x# welcome.612\n"				
				ESC"Thoát\n",id,id,id,id));
			break;
		case 601:
		case 602:
		case 603:
		case 604:
		case 605:
		case 606:
		case 607:
		case 608:
		case 609:
		case 610:
		case 611: 
		case 612:
		//Cánh lv 1 2
		if ( flag == 601 )
		{
			cTmp = "Hoả Lân Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv1";
		}
		else if ( flag == 602 )
		{
			cTmp = "Thanh Long Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv2";
		}
		else if ( flag == 603 )
		{
			cTmp = "Huyết Phụng Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv1";
		}
		else if ( flag == 604 )
		{
			cTmp = "Huyết Thần Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv2";
		}
		//Pp lv 1 2
		else if ( flag == 605 )
		{
			cTmp = "Sát Thần Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv1";
		}
		else if ( flag == 606 )
		{
			cTmp = "Vương Tử Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv2";
		}
		else if ( flag == 607 )
		{
			cTmp = "Linh Quy Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv1";
		}
		else if ( flag == 608 )
		{
			cTmp = "Vương Mẫu Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv2";
		}
		//Cánh lv 3
		else if ( flag == 609 )
		{
			cTmp = "Nghịch Giới Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv3";
		}
		else if ( flag == 610 )
		{
			cTmp = "Tru Tiên Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv3";
		}
		//PP lv 3
		else if ( flag == 611 )
		{
			cTmp = "Thiên Tôn Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv3";
		}
		else if ( flag == 612 )
		{
			cTmp = "Nữ Thần Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv3";
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if (who->get_cash() < 300000) {
			send_user(who,"%c%c%w%s",':',2,me->get_char_picid(),sprintf("Linh Thần Sư:\n Ngươi không đủ 300.000 ngân lượng.\n"ESC"Rời khỏi"));
			return ;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Cánh Thiên Thần") < 30 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Lệnh Thiên Tôn") < 30 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Ngọc Tiên Đế") < 20 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thiên Linh Sư:\n Nguyên liệu của ngươi không đủ nâng cấp! Nâng cấp %s cần các loại nguyên liệu:\n "+cTmp+", 30 cánh thiên thần, 30 lệnh thiên tôn và 20 ngọc tiên đế.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Cánh Thiên Thần",30);
		TASK_LEGEND_D->check_task_item1(who,"Lệnh Thiên Tôn",30);
		TASK_LEGEND_D->check_task_item1(who,"Ngọc Tiên Đế",20);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(2);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		who->add_cash(-300000);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn gia hạn thành công "HIR+item->get_name());
		break;
			
			
		// Nâng Cấp
		case 70:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC"Cánh Nam\ntalk %x# welcome.75\n"
				ESC"Cánh Nữ\ntalk %x# welcome.76\n"
				ESC"Thoát\n",id,id,id));
			break;
		case 75:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Thánh Linh Chi Dực·Vàng Nhạt\ntalk %x# welcome.801\n"
				ESC"Nâng cấp Hoả Lân Chi Dực\ntalk %x# welcome.802\n"
				ESC"Nâng cấp Thanh Long Chi Dực\ntalk %x# welcome.809\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 76:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Thánh Linh Chi Dực·Trắng Thuần\ntalk %x# welcome.803\n"
				ESC"Nâng cấp Huyết Phụng Chi Dực\ntalk %x# welcome.804\n"
				ESC"Nâng cấp Huyết Thần Chi Dực\ntalk %x# welcome.810\n"		
				ESC"Thoát\n",id,id,id,id));
			break;
		case 80:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC"Phi Phong Nam\ntalk %x# welcome.85\n"
				ESC"Phi Phong Nữ\ntalk %x# welcome.86\n"				
				ESC"Thoát\n",id,id,id));
			break;
		case 85:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Vương Giả Phi Phong\ntalk %x# welcome.805\n"
				ESC"Nâng cấp Sát Thần Phi Phong\ntalk %x# welcome.806\n"
				ESC"Nâng cấp Vương Tử Phi Phong\ntalk %x# welcome.811\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 86:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Xí Nhiệt Phi Phong\ntalk %x# welcome.807\n"
				ESC"Nâng cấp Linh Quy Phi Phong\ntalk %x# welcome.808\n"
				ESC"Nâng cấp Vương Mẫu Phi Phong\ntalk %x# welcome.814\n"				
				ESC"Thoát\n",id,id,id,id));
			break;
		case 81:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Ngươi muốn tìm hiểu gì? Ta sẽ cho ngươi biết mọi thứ về nâng cấp thú cưỡi.\n"
				ESC"Nơi tìm nguyên liệu?\ntalk %x# welcome.812\n"
      			ESC"Số lượng nguyên liệu cần có\ntalk %x# welcome.813\n"
//				ESC"Phương pháp ren thần binh Đao Tử Vân và nguyên liệu tương ưng\ntalk %x# welcome.831\n"
//				ESC"Phương pháp ren thần binh Lục Tiên Kiêm và nguyên liệu tương ưng\ntalk %x# welcome.841\n"
//				ESC"Phương pháp ren thần binh Ngọc La Quyên Thu và nguyên liệu tương ưng\ntalk %x# welcome.851\n"
//				ESC"Phương pháp ren thần binh Thần Tiên Hạc Kim và nguyên liệu tương ưng\ntalk %x# welcome.861\n"
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
		//Cánh lv 1 2
		if ( flag == 801 )
		{
			cTmp = "Thánh Linh Chi Dực·Vàng Nhạt";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv1";
		}
		else if ( flag == 802 )
		{
			cTmp = "Hoả Lân Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv2";
		}
		else if ( flag == 803 )
		{
			cTmp = "Thánh Linh Chi Dực·Trắng Thuần";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv1";
		}
		else if ( flag == 804 )
		{
			cTmp = "Huyết Phụng Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv2";
		}
		//Pp lv 1 2
		else if ( flag == 805 )
		{
			cTmp = "Vương Giả Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv1";
		}
		else if ( flag == 806 )
		{
			cTmp = "Sát Thần Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv2";
		}
		else if ( flag == 807 )
		{
			cTmp = "Xí Nhiệt Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv1";
		}
		else if ( flag == 808 )
		{
			cTmp = "Linh Quy Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv2";
		}
		//Cánh lv 3
		else if ( flag == 809 )
		{
			cTmp = "Thanh Long Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv3";
		}
		else if ( flag == 810 )
		{
			cTmp = "Huyết Thần Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv3";
		}
		//PP lv 3
		else if ( flag == 811 )
		{
			cTmp = "Vương Tử Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv3";
		}
		else if ( flag == 814 )
		{
			cTmp = "Vương Mẫu Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv3";
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if (who->get_cash() < 200000) {
			send_user(who,"%c%c%w%s",':',2,me->get_char_picid(),sprintf("Linh Thần Sư:\n Ngươi không đủ 200.000 ngân lượng.\n"ESC"Rời khỏi"));
			return ;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Cánh Thiên Thần") < 120 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Lệnh Thiên Tôn") < 120 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Ngọc Tiên Đế") < 100 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thiên Linh Sư:\n Nguyên liệu của ngươi không đủ nâng cấp! Nâng cấp %s cần các loại nguyên liệu:\n "+cTmp+", 120 cánh thiên thần, 120 lệnh thiên tôn và 100 ngọc tiên đế.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Cánh Thiên Thần",120);
		TASK_LEGEND_D->check_task_item1(who,"Lệnh Thiên Tôn",120);
		TASK_LEGEND_D->check_task_item1(who,"Ngọc Tiên Đế",100);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(2);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		who->add_cash(-200000);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn nâng cấp thành công "HIR+item->get_name());
			break;
		case 812:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Nâng cấp cánh ngươi có thể đổi cánh bằng vô song điểm phiếu tại Quân Sư Vô Song Thành Chu (282,180).\n Cánh Thiên THần, Lệnh Thiên Tôn và Ngọc Tiên Đế có thể săn boss, đi phụ bản mà có.\n"ESC"Thoát ra"));
			break;
		case 813:
			send_user(who,"%c%s",':',sprintf("Thiên Linh Sư:\n Cần có 120 Cánh Thiên Thần, 120 Lệnh Thiên Tôn và 100 Ngọc Tiên Đế, nếu thiếu 1 trong 3 thì không thể nâng cấp được.\n"ESC"Thoát ra"));
			break;
        }	
}
