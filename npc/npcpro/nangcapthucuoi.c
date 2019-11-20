
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5402; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Nâng Cấp Thú Cưỡi");
		set_real_name("Linh Thần Sư");
        set_2( "talk", ([
				"welcome"          : (: do_welcome :),
        ]));

       setup();
}

// 函数：对话处理
void do_look( object who )
{
	int id = getoid( this_object() );
	send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Mọi thứ đều có quy luật riêng, chúng cần phải được đổi mới để theo kịp thời đại. Trong thời buổi loạn lạc này, chư vị có gì muốn tìm ta?\n"
		ESC"Nâng cấp thú cưỡi\ntalk %x# welcome.80\n"
		ESC"Gia hạn thú cưỡi\ntalk %x# welcome.70\n"
		ESC"Công thức và nguyên liệu nâng cấp thú cưỡi\ntalk %x# welcome.81\n"
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
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Thú cưỡi nâng cấp của ngươi hết hạn? Ở đây ta có thể gia hạn nó! Ngươi cần gia hạn Chiến Thú nào?\n"
				ESC"Gia hạn Độc Thần Ưng\ntalk %x# welcome.701\n"
				ESC"Gia hạn Hoả Hồ Ly\ntalk %x# welcome.702\n"
				ESC"Gia hạn Hoả Đại Hùng\ntalk %x# welcome.703\n"
				ESC"Gia hạn Bổn Bổn Địa\ntalk %x# welcome.704\n"
				ESC"Gia hạn Thuỷ Long Quy\ntalk %x# welcome.705\n"
				ESC"Gia hạn Thần Ác Điểu\ntalk %x# welcome.706\n"
				ESC"Gia hạn Ác Ngựa Máy\ntalk %x# welcome.707\n"
				ESC"Gia hạn Thần Tuần Lộc Tuyết\ntalk %x# welcome.708\n"
				ESC"Gia hạn Thần Thần Thảm Gió\ntalk %x# welcome.709\n"
				ESC"Gia hạn Thần Kiến Chiến Binh\ntalk %x# welcome.710\n"
				ESC"Gia hạn Thần Cá Voi\ntalk %x# welcome.711\n"
				ESC"Thoát\n",id,id,id,id,id,id,id,id,id,id,id));
			break;
			
		case 701:
		case 702:
		case 703:
		case 704:
		case 705:
		case 706:
		case 707:
		case 708:
		case 709:
		case 710:
		case 711:
		if ( flag == 701 )
		{
			cTmp = "Độc Thần Ưng";
			cFile = "item/ride/NangCap/011";
		}
		else if ( flag == 702 )
		{
			cTmp = "Hoả Hồ Ly";
			cFile = "item/ride/NangCap/027";
		}
		else if ( flag == 703 )
		{
			cTmp = "Hoả Đại Hùng";
			cFile = "item/ride/NangCap/029";
		}
		else if ( flag == 704 )
		{
			cTmp = "Bổn Bổn Địa";
			cFile = "item/ride/NangCap/031";
		}
		else if ( flag == 705 )
		{
			cTmp = "Thuỷ Long Quy";
			cFile = "item/ride/NangCap/033";
		}
		else if ( flag == 706 )
		{
			cTmp = "Ác Đà Đà";
			cFile = "item/ride/NangCap/035";
		}
		else if ( flag == 707 )
		{
			cTmp = "Thần Ác Ngựa Máy";
			cFile = "item/ride/NangCap/037";
		}
		else if ( flag == 708 )
		{
			cTmp = "Tiểu Quai Tuyết";
			cFile = "item/ride/NangCap/039";
		}
		else if ( flag == 709 )
		{
			cTmp = "Thần Thảm Gió";
			cFile = "item/ride/NangCap/041";
		}
		else if ( flag == 710 )
		{
			cTmp = "Thần Kiến Chiến Binh";
			cFile = "item/ride/NangCap/043";
		}
		else if ( flag == 711 )
		{
			cTmp = "Thần Cá Voi";
			cFile = "item/ride/NangCap/055";
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
			TASK_LEGEND_D->check_task_item_amount(who,"Bánh Ngọt") < 50 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Đá Thần") < 50 )
		{
			send_user(who,"%c%c%w%s",':',2,me->get_char_picid(),sprintf("Linh Thần Sư:\n Nguyên liệu của ngươi không đủ để gia hạn! Nâng cấp %s cần các loại nguyên liệu:\n "+cTmp+", 50 đá thần, 50 bánh ngọt.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Bánh Ngọt",50);
		TASK_LEGEND_D->check_task_item1(who,"Đá Thần",50);
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
			
		case 80:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Ta có thể nâng cấp toàn bộ thú cưỡi, ta được nữ oa nương nương sai xuống hạ giới cũng chỉ là giúp các ngươi trong thời loạn lạc này mà thôi! Vậy ngươi cần gì ở ta?\n"
				ESC"Nâng cấp Ưng Njnja thành Độc Thần Ưng\ntalk %x# welcome.801\n"
				ESC"Nâng cấp Cáo Tuyết thành Hoả Hồ Ly\ntalk %x# welcome.802\n"
				ESC"Nâng cấp Gấu Trắng thành Hoả Đại Hùng\ntalk %x# welcome.803\n"
				ESC"Nâng cấp Voi Địa thành Bổn Bổn Địa\ntalk %x# welcome.804\n"
				ESC"Nâng cấp Rùa Xanh thành Thuỷ Long Quy\ntalk %x# welcome.805\n"
				ESC"Nâng cấp Ác Điểu thành Thần Ác Điểu\ntalk %x# welcome.806\n"
				ESC"Nâng cấp Ngựa Máy thành Thần Ác Ngựa Máy\ntalk %x# welcome.807\n"
				ESC"Nâng cấp Tuần Lộc Đỏ thành Thần Tuần Lộc Tuyết\ntalk %x# welcome.808\n"
				ESC"Nâng cấp Thảm Bay Vàng thành Thần Thần Thảm Gió\ntalk %x# welcome.809\n"
				ESC"Nâng cấp Kiến Chiến Binh thành Thần Kiến Chiến Binh\ntalk %x# welcome.810\n"
				ESC"Nâng cấp Cá Voi Đom Đóm thành Thần Cá Voi\ntalk %x# welcome.811\n"
				ESC"Thoát\n",id,id,id,id,id,id,id,id,id,id,id));
			break;
		case 81:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Ngươi muốn tìm hiểu gì? Ta sẽ cho ngươi biết mọi thứ về nâng cấp thú cưỡi.\n"
				ESC"Phương pháp tìm nguyên liệu nâng cấp thú cưỡi\ntalk %x# welcome.812\n"
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
		if ( flag == 801 )
		{
			cTmp = "Ưng Njnja";
			cFile = "item/ride/NangCap/011";
		}
		else if ( flag == 802 )
		{
			cTmp = "Cáo Tuyết";
			cFile = "item/ride/NangCap/027";
		}
		else if ( flag == 803 )
		{
			cTmp = "Gấu Trắng";
			cFile = "item/ride/NangCap/029";
		}
		else if ( flag == 804 )
		{
			cTmp = "Voi Địa";
			cFile = "item/ride/NangCap/031";
		}
		else if ( flag == 805 )
		{
			cTmp = "Rùa Xanh";
			cFile = "item/ride/NangCap/033";
		}
		else if ( flag == 806 )
		{
			cTmp = "Ác Điểu";
			cFile = "item/ride/NangCap/035";
		}
		else if ( flag == 807 )
		{
			cTmp = "Ngựa Máy";
			cFile = "item/ride/NangCap/037";
		}
		else if ( flag == 808 )
		{
			cTmp = "Tuần Lộc Đỏ";
			cFile = "item/ride/NangCap/039";
		}
		else if ( flag == 809 )
		{
			cTmp = "Thảm Bay Vàng";
			cFile = "item/ride/NangCap/041";
		}
		else if ( flag == 810 )
		{
			cTmp = "Kiến Chiến Binh";
			cFile = "item/ride/NangCap/043";
		}
		else if ( flag == 811 )
		{
			cTmp = "Cá Voi Đom Đóm";
			cFile = "item/ride/NangCap/055";
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if (who->get_cash() < 100000) {
			send_user(who,"%c%c%w%s",':',2,me->get_char_picid(),sprintf("Linh Thần Sư:\n Ngươi không đủ 100.000 ngân lượng.\n"ESC"Rời khỏi"));
			return ;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Bánh Ngọt") < 150 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Đá Thần") < 150 )
		{
			send_user(who,"%c%c%w%s",':',2,me->get_char_picid(),sprintf("Linh Thần Sư:\n Nguyên liệu của ngươi không đủ nâng cấp! Nâng cấp %s cần các loại nguyên liệu:\n "+cTmp+", 150 đá thần, 150 bánh ngọt.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Bánh Ngọt",150);
		TASK_LEGEND_D->check_task_item1(who,"Đá Thần",150);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(2);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		who->add_cash(-100000);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn nâng cấp thành công "HIR+item->get_name());
			break;
		case 812:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Nâng cấp thú cưỡi thần có Trứng Thú Cưỡi gốc mở Túi Thú Cưỡi mua từ Tiệm Tạp Hóa trong Kĩ Năng -> Bảo Khố.\n Bánh Ngọt và Đá Thần có thể săn boss, đi phụ bản để có.\n"ESC"Thoát ra"));
			break;
		case 813:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Cần có 150 bánh ngọt và 150 đá thần cùng với 100.000 ngân lượng để nâng cấp thú cưỡi, nếu thiếu thần thú không thể tiến hóa được.\n"ESC"Thoát ra"));
			break;
/*		case 831:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Đúc Đao Tử Vân cần 1 Thiên tôn bảo đao, 60 Đá Tương Uyên, 40 Đá Càn Khôn 30 Lỗ Ban.\n Càn Khôn Vô Cấp Côn có thể hợp thành tại nước Chu, Đá Tương Uyên và Đá Càn Khôn co thê tìm thây trong Phong Yêu Kinh. Lỗ Ban có thể mua trong Bảo Khố.\n"ESC"Phản hồi"));
			break;
		case 841:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Đúc Lục Tiên Kiêm cần 1 Ngọc thần bảo kiếm, 60 Đá Tương Uyên, 40 Đá Càn Khôn 30 Lỗ Ban.\n Càn Khôn Vô Cấp Côn có thể hợp thành tại nước Chu, Đá Tương Uyên và Đá Càn Khôn co thê tìm thây trong Phong Yêu Kinh. Lỗ Ban có thể mua trong Bảo Khố.\n"ESC"Phản hồi"));
			break;
		case 851:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Đúc Ngọc La Quyên Thu cần 1 Anh kiệt quyền nhẫn, 60 Đá Tương Uyên, 40 Đá Càn Khôn 30 Lỗ Ban.\n Càn Khôn Vô Cấp Côn có thể hợp thành tại nước Chu, Đá Tương Uyên và Đá Càn Khôn co thê tìm thây trong Phong Yêu Kinh. Lỗ Ban có thể mua trong Bảo Khố.\n"ESC"Phản hồi"));
			break;
		case 861:
			send_user(who,"%c%s",':',sprintf("Linh Thần Sư:\n Đúc Thần Tiên Hạc Kim cần 1 Bích hỏa hàn nguyệt hoàn, 60 Đá Tương Uyên, 40 Đá Càn Khôn 30 Lỗ Ban.\n Càn Khôn Vô Cấp Côn có thể hợp thành tại nước Chu, Đá Tương Uyên và Đá Càn Khôn co thê tìm thây trong Phong Yêu Kinh. Lỗ Ban có thể mua trong Bảo Khố.\n"ESC"Phản hồi"));
			break;   */
        }	
}
