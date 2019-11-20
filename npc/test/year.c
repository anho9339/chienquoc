/*
Code by Ben
*/
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>

inherit OFFICER;

// 函数:获取人物造型
int get_char_picid() { return 6010; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_real_name("Sứ Giả Phát Thưởng");
		set_name("Ghép Sổ Xố");
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Hãy đến với ta ngươi sẽ nhận được những phần quà hấp dẫn... \n"
		ESC "Nhận Túi Quà May Mắn\ntalk %x# gift.11\n"		
		ESC "Tham gia Con số may mắn\ntalk %x# gift.12\n"		
		ESC "Đổi thưởng Tích luỹ Cứu thế\ntalk %x# gift.13\n"				
	//	ESC "Đổi Phi Phong và Cánh\ntalk %x# gift.20\n"				
	//	ESC "Gói quà Quốc Tế Phụ Nữ\ntalk %x# gift.50\n"	
		ESC "Đổi Sổ Xố Đặc Biệt\ntalk %x# gift.30\n"
		ESC HIY"Ghép Chìa Khóa và Hộp\ntalk %x# gift.60\n"
	//	ESC HIY"Đổi chữ 30 tháng 4\ntalk %x# gift.40\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id));	
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien,ben, tet1=0,tet2=0, tet3, tet4,bennhat2,bn2;
	object who,item,item1,item2,item3;
	string *nTmp,cFile,cTmp,cFinal,result,bennhat,bn;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);     
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
		rate = random(100);
        switch(flag)
        {
       	case 1:
			break;	
		case 11:
			if ( who->get_level() < 55 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nNgươi chưa đạt cấp 55, không thể nhận Túi Quà May Mắn !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
			return;
			}
			if ( mxTime[TIME_WDAY] != 6 &&mxTime[TIME_WDAY] != 0 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nChỉ có thể nhận Túi Quà May Mắn vào thứ bảy và chủ nhật !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
			return;
			}
			if ( (mxTime[TIME_WDAY] == 6||mxTime[TIME_WDAY] == 0) && (mxTime[TIME_HOUR] < 10 || mxTime[TIME_HOUR] >= 22) )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nThời gian có thể nhận Túi Quà May Mắn chưa tới !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
			return;
			}
			if ( who->get_save("pblx")>0 )
			{
				if ( who->get_save("pblx")>=3600 )
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("Sứ Giả Phát Thưởng :\nMuốn nhận Túi Quà May Mắn phải chờ thêm %d giờ %d phút nữa !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save("pblx")/3600,(who->get_save("pblx")-3600)/60));
				else if ( who->get_save("pblx")>=60 )
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("Sứ Giả Phát Thưởng :\nMuốn nhận Túi Quà May Mắn phải chờ thêm %d phút nữa !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save("pblx")/60));
				else if ( who->get_save("pblx")<60 )
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("Sứ Giả Phát Thưởng :\nMuốn nhận Túi Quà May Mắn phải chờ thêm %d giây nữa !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save("pblx")));	
			return;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}	
			who->set_save("pblx2",1);
			who->set_save("pblx",5400);
			item = new("/item/event/phongbaolixi");
			p = item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nNgươi đã nhận thành công 1 Túi Quà May Mắn !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			break;	
		case 12:
			if ( who->get_save("csmm1")>0 && who->get_save("csmm2")>0 )
			{
			if ( !is_god(who) )
			{	
				if ( random(1000) < 1 ) ben = 1;
				else ben = random(1000);
			}
			else ben = who->get_save("csmm1")+10;	
				if ( abs(who->get_save("csmm1")-ben)<11 ) { tet1 = 1; tet3 = who->get_save("csmmm")*10; }
				if ( abs(who->get_save("csmm2")-ben)<11 ) { tet2 = 1; tet4 = who->get_save("csmmm")*10; }
				if ( tet1 ==1 && tet2==1 )
				{
				who->add_cash(tet3);
				who->add_cash(tet4);
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi đã trúng cả 2 số !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng cả 2 con số, xin chúc mừng !");
				return ;
				}
				else if ( tet1 ==1 )
				{
				who->add_cash(tet3);
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi đã trúng con số thứ 1 !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng được con số đầu tiên, xin chúc mừng !");
				return ;
				}
				else if ( tet2 ==1 )
				{
				who->add_cash(tet4);
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi đã trúng con số thứ 2 !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng được con số thứ hai, xin chúc mừng !");
				return ;
				}
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi không trúng số nào !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			if ( who->get_save("csmmm")<1 )
			send_user( who, "%c%c%d%s", '?', 16, 10, "Xin nhập số tiền muốn tham   gia trò chơi con số may mắn:\n" ESC "csmm ? %s\n" );
			else if ( who->get_save("csmm1")<1 )
			send_user( who, "%c%c%d%s", '?', 16, 3, "Bạn đặt "+who->get_save("csmmm")+" lượng \nXin nhập con số may mắn:\n" ESC "csmm a "+who->get_save("csmmm")+" %s\n" );
			else if ( who->get_save("csmm2")<1 )
			send_user( who, "%c%c%d%s", '?', 16, 3, "Bạn đặt "+who->get_save("csmmm")+" lượng \nCon số đầu tiên : "+who->get_save("csmm1")+"\nXin nhập con số may mắn:\n" ESC "csmm b "+who->get_save("csmmm")+" "+who->get_save("csmm1")+" %s\n" );
			break;
		case 13:
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \nĐiểm tích luỹ Cứu Thế của bạn hiện tại là %d điểm. \nBạn muốn nhận phần thưởng nào? Xin hãy lựa chọn : \n"
			ESC"20 điểm tích lấy Túi Hoàng Kim ( tỷ lệ đổi thành công là 70%% )\ntalk %x# gift.14\n" // Tỉ lệ thành công trước là 10
			ESC"15 điểm tích lấy Túi Kim Bảo ( tỷ lệ đổi thành công là 70%% )\ntalk %x# gift.15\n" // Tỉ lệ thành công trước là 20
			ESC"10 điểm tích lấy Túi Ngân Lượng ( tỷ lệ đổi thành công là 70%% )\ntalk %x# gift.16\n"  // Tỉ lệ thành công trước là 20
		//	ESC"20 điểm tích lấy Mảnh ghép Vương Giả ( tỷ lệ đổi thành công là 15%% )\ntalk %x# gift.17\n"
			ESC"Rời khỏi",me->get_name(),who->get_save("diemcuudoi"),id,id,id,id,id));
			break;
		case 14:
		case 15:
		case 16:
		case 17:
			if ( flag==14 ) {bennhat="item/event/tuihoangkim";bennhat2=20;bn2=70;} // Tỉ lệ thành công trước là 10
			else if ( flag==15 ) {bennhat="item/event/tuikimbao";bennhat2=15;bn2=70;}  // Tỉ lệ thành công trước là 20
			else if ( flag==16 ) {bennhat="item/event/tuinganluong";bennhat2=10;bn2=70;}  // Tỉ lệ thành công trước là 20
		//	else if ( flag==17 ) {bennhat="item/event/manhvuonggia";bennhat2=20;bn2=15;}
			if ( who->get_save("diemcuudoi") < bennhat2 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nNgươi không có đủ "+bennhat2+" điểm tích luỹ Cứu Thế !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			who->add_save("diemcuudoi",-bennhat2);
			if ( random100() < bn2 )
				item=new(bennhat);
			else
				notify("Đổi thất bại !");
			if ( item ) 
			{
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
			}
			break;
	/*	case 20:
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(me->get_name()+": \nNgươi muốn đổi Phi Phong hay Cánh ?\n"
			ESC"Ta muốn đổi lấy Vương Giả Phi Phong\ntalk %x# gift.21\n"
			ESC"Ta muốn đổi lấy Xí Nhiệt Phi Phong\ntalk %x# gift.22\n"
			ESC"Ta muốn đổi lấy Thánh Linh Chi Dực Vàng Nhạt\ntalk %x# gift.23\n"
			ESC"Ta muốn đổi lấy Thánh Linh Chi Dực Trắng Thuần\ntalk %x# gift.24\n"
			ESC"Rời khỏi",id,id,id,id));
			break; 
		case 21:	
		case 22:	
		case 23:	
		case 24:	
			if ( flag==21 ) bn="item/30/3020";
			else if ( flag==22 ) bn="item/30/3021";
			else if ( flag==23 ) bn="item/30/3031";
			else if ( flag==24 ) bn="item/30/3028";
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Vương Giả") < 10 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nNgươi không có đủ 10 Mảnh Vương Giả !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Vương Giả",10);	
			if ( random100() < 10 )
				item=new(bn);
			else
				notify("Đổi thất bại !");
			if ( item ) 
			{
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
			}
			break;
		case 50:
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s :\n Ngươi muốn gói quà thường hay quà đặc biệt ? \n"
			ESC"Gói quà thường \ntalk %x# gift.51\n"
			ESC"Gói quà đặc biệt \ntalk %x# gift.52\n"
			ESC"Rời khỏi",me->get_name(),id,id));
			break;	
		case 51:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Quà") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Giấy Gói Quà") < 1 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có 1 giấy Gói quà và hộp quà !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Quà",1);
			TASK_LEGEND_D->check_task_item1(who,"Giấy Gói Quà",1);
			item=new("item/event/quanho");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
			break;
		case 52:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Quà ") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Giấy Gói Quà") < 1 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có 1 giấy Gói quà và hộp quà hoàng kim !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Quà ",1);
			TASK_LEGEND_D->check_task_item1(who,"Giấy Gói Quà",1);
			item=new("item/event/quato");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
			break;	*/
		case 30:
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s :\n Ngươi muốn đổi Sổ Xố Đặc Biệt loại 1 hay 2? \n"
			ESC"Sổ Xố Đặc Biệt 1\ntalk %x# gift.31\n"
			ESC"Sổ Xố Đặc Biệt 2\ntalk %x# gift.32\n"
			ESC"Rời khỏi",me->get_name(),id,id));
			break;	
		case 31:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Sổ Xố Sơ") < 10 || TASK_LEGEND_D->check_task_item_amount(who,"Sổ Xố Trung") < 10 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có 10 Sổ Xố Sơ và 10 Sổ Xố Trung!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Sổ Xố Sơ",10);
			TASK_LEGEND_D->check_task_item1(who,"Sổ Xố Trung",10);
			item=new("item/soxo/soxodb1");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
			break;
		case 32:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Sổ Xố Cao") < 10 || TASK_LEGEND_D->check_task_item_amount(who,"Sổ Xố Cực") < 10 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có 10 Sổ Xố Cao và 10 Sổ Xố Cực!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Sổ Xố Cao",10);
			TASK_LEGEND_D->check_task_item1(who,"Sổ Xố Cực",10);
			if ( random100() < 90 )
				item=new("item/soxo/soxodb2");
			else
				notify("Đổi thất bại, chúc bạn may mắn lần sau!");
				who->add_cash(20000);
			if ( item ) 
			{
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
			}
			break;	
		case 40:
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s :\n Hôm nay là 30/4 , dân tình cứ xồn xồn lên nhỉ, bà con tìm ta có chuyện gì? \n"
			ESC"Đổi chữ Giải + Phóng + Lao + Động\ntalk %x# gift.41\n"
			ESC"Đổi chữ đặc biệt Giải Phóng Lao Động\ntalk %x# gift.42\n"
			ESC"Rời khỏi",me->get_name(),id,id));
			break;	
		case 41:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Giải") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Phóng") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Lao") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Động") < 1 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có đủ chữ để ghép, cần mỗi loại 1 chữ!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Giải",1);
			TASK_LEGEND_D->check_task_item1(who,"Phóng",1);
			TASK_LEGEND_D->check_task_item1(who,"Lao",1);
			TASK_LEGEND_D->check_task_item1(who,"Động",1);
			item=new("item/event/304/normalprize");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
			break;
		case 42:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Giải Phóng Lao Động") < 1 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có chữ đặc biệt Giải Phóng Lao Động!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Giải Phóng Lao Động",1);
			item=new("item/event/304/specialprize");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");			
			break;
		case 60:
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s :\n Chà, các ngươi hẳn là có Chìa Khóa và Hộp quý hiếm, hãy đưa ta và nhận lại Chìa Khóa và Hộp Đặc Biệt nhoa! \n"
			ESC"Ghép Chìa Khóa\ntalk %x# gift.61\n"
			ESC"Ghép Hộp\ntalk %x# gift.62\n"
			ESC"Rời khỏi",me->get_name(),id,id));
			break;	
		case 61:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Chìa Khóa") < 3  )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có đủ Mảnh Chìa Khóa, cần 3 mảnh cơ mà!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Chìa Khóa",3);
			item=new("item/01/0203");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn ghép thành công "+item->get_name()+", xin chúc mừng !");
			break;
		case 62:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Hộp") < 3 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nNgươi không có đủ Mảnh Hộp, cần 3 mảnh cơ mà!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Hộp",3);
			item=new("item/sell/0203");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn ghép thành công "+item->get_name()+", xin chúc mừng !");			
			break;
		}
}
