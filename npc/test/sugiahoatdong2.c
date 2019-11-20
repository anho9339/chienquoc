/*
Edit by Nguyễn Quang Hiếu
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
void reset();
int get_char_picid() { return 6010; }
int is_seller() { return 7007; }
int is_self_look() { return 1; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name("Sứ Giả Hoạt Động");
		set_real_name(HIR "Sứ Giả Hoạt Động");
		set_2( "good", ([
                "01" : "/item/ngoai_trang/vip101",
                "02" : "/item/ngoai_trang/vip102",
				"03" : "/item/test2/NangCap/ppcanh",	
				"04" : "/item/01/0007",	
				"05" : "/item/01/0008",	
				"06" : "/item/01/0009",	
				"07" : "/item/01/0010",	
				"08" : "/item/01/0011",	
				"09" : "/item/01/0012",	
				"10" : "/item/01/0013",	
				"11" : "/item/01/0014",	
				"12" : "/item/01/0015",	
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn tham gia hoạt động gì?????? \n"
	//	ESC HIC"Nhận hỗ trợ mỗi giờ....\ntalk %x# gift.59\n"
		ESC HIC"Nhận hỗ trợ hằng ngày....\ntalk %x# gift.56\n"
	//	ESC HIY"Thuê trang bị Bá Vương....\ntalk %x# gift.1\n"
	//	ESC HIY"Hợp Thành Vật Phẩm\ntalk %x# gift.2\n"
		ESC HIY"Đổi Cực Hiệu lấy Siêu Cấp\ntalk %x# gift.11\n"
		ESC HIC"Mua 1 chiếc Chìa Khoá May Mắn...\ntalk %x# gift.69\n"		
	//	ESC HIY"Mua đoạn thạch đặc biệt ( 100 kim nguyên bảo )\ntalk %x# gift.500\n"
	//	ESC HIY"Ta muốn đổi Kinh Nghiệm\ntalk %x# gift.12\n"
		ESC HIY"Hợp Thành Vật Phẩm\nlist9 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));	
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien;
	object who,item,item1,item2,item3;
	string *nTmp,cFile,cTmp,cFinal,result;
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
				/*send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn thuê trang bị Bá Vương với giá 500 Kim Nguyên Bảo phải không ???? \nLưu ý : Vật phẩm sau khi Thuê sẽ có thời hạn sử dụng là 20 ngày tính từ lúc mở túi \n"
					ESC HIY"Ừk, tôi muốn thuê...\ntalk %x# gift.67\n"
					ESC"Rời khỏi",get_name(),id,id));*/
			break;
		case 2:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \nNgoại Trang Bá Vương: cần 100 mảnh ghép Ngoại Trang  \nHồ ấn Bá Vương: cần 100 mảnh ghép Vương Giả \n"
				//	ESC HIY"[Vũ Khí Bá Vương]\ntalk %x# gift.28\n"
				//	ESC HIY"[Phi Phong và Cánh]\ntalk %x# gift.3\n"
					ESC HIY"[Ngoại Trang Bá Vương]\ntalk %x# gift.33\n"
					ESC HIY"[Ngọc Bội Tín Vật]\ntalk %x# gift.5\n"
				//	ESC HIY"[Trang bị Bá Vương]\ntalk %x# gift.6\n"
					ESC HIY"[Hổ ấn Bá Vương] (Nâng cấp Phi Phong hoặc Cánh)\ntalk %x# gift.68\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id));
			break;
		case 3:
			break;
		case 5:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \n"
					ESC HIY"[Kì Lân Ngọc Bội]\ntalk %x# gift.35\n"
					ESC HIY"[Phượng Hoàng Ngọc Bội]\ntalk %x# gift.36\n"
					ESC HIY"[Phượng Vũ Ngọc Bội]\ntalk %x# gift.37\n"
					ESC HIY"[Chu Tước Ngọc Bội]\ntalk %x# gift.38\n"
					ESC HIY"[Uyên Ương Ngọc Bội]\ntalk %x# gift.39\n"
					ESC HIY"[Bạch Hổ Ngọc Bội]\ntalk %x# gift.40\n"
					ESC HIY"[Thiên Ân Ngọc Bội]\ntalk %x# gift.41\n"
					ESC HIY"[Âm Dương Ngọc Bội]\ntalk %x# gift.42\n"
					ESC HIY"[Song Phụng Ngọc Bội]\ntalk %x# gift.43\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id,id));
			break;
		case 6:
			//	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \nMỗi loại cần 100 mảnh ghép cho loại đó ?? \n"
			//		ESC HIY"Ghép trang bị [Áo]\ntalk %x# gift.44\n"
			//		ESC HIY"Ghép trang bị [Nón]\ntalk %x# gift.45\n"
			//		ESC HIY"Ghép trang bị [Hạng Liên]\ntalk %x# gift.46\n"
			//		ESC HIY"Ghép trang bị [Yêu Đới]\ntalk %x# gift.47\n"
			//		ESC HIY"Ghép trang bị [Giày]\ntalk %x# gift.48\n"
			//		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
			break;	
		case 11:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Mỗi loại tiêu hao 2 Cực Hiệu cho loại đó !! \n"
					ESC HIY"[Siêu Cấp Khí Huyết]\ntalk %x# gift.60\n"
					ESC HIY"[Siêu Cấp Pháp Lực]\ntalk %x# gift.61\n"
					ESC HIY"[Siêu Cấp Ngoại Công]\ntalk %x# gift.62\n"
					ESC HIY"[Siêu Cấp Nội Công]\ntalk %x# gift.63\n"
					ESC HIY"[Siêu Cấp Ngoại Kháng]\ntalk %x# gift.64\n"
					ESC HIY"[Siêu Cấp Nội Kháng]\ntalk %x# gift.65\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
			break;
		case 12:
			/*	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Điểm tích luỹ Sư Môn của bạn hiện là "HIR "%d "NOR "điểm !! \n"
					ESC HIY"[Dùng 2 điểm đổi lấy Kinh Nghiệm]\ntalk %x# gift.66\n"
					ESC"Rời khỏi",get_name(),who->get_save("diemsumon.score"),id,id));*/
			break;
		case 14:
			break;
		case 15:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\nHồ ấn Bá Vương: cần 30 mảnh ghép Vương Giả.\n"
					ESC HIY"[Hổ ấn Bá Vương]\ntalk %x# gift.68\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id));
			break;	
	/*	case 28:	
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Vũ Khí") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Vũ Khí !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Vũ Khí",100);
	if ( rate < 4 )		
	{
		item1 = new("/item/test2/Ghep/VuKhi/1005");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 20 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-100);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"Vũ Khí Bá Vương"HIY"！！！", who->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;*/
	/*	case 33:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngoại Trang") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Ngoại Trang !");
                return ;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngoại Trang",100);	
	if ( rate < 4 )		
	{
		item1 = new("/item/test2/1005");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-20);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"Ngoại Trang Bá Vương"HIY"！！！", who->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 35:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 40 )
			{
                write_user(who, ECHO "Ngươi không có đủ 40 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",40);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0007");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-20);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 36:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 80 )
			{
                write_user(who, ECHO "Ngươi không có đủ 80 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",80);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0008");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-20);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 37:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 90 )
			{
                write_user(who, ECHO "Ngươi không có đủ 90 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",90);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0009");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-20);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 38:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",100);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0010");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-20);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 39:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 120 )
			{
                write_user(who, ECHO "Ngươi không có đủ 120 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",120);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0011");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-30);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 40:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 130 )
			{
                write_user(who, ECHO "Ngươi không có đủ 130 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",130);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0012");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-35);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 41:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 140 )
			{
                write_user(who, ECHO "Ngươi không có đủ 140 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",140);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0013");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-40);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 42:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 150 )
			{
                write_user(who, ECHO "Ngươi không có đủ 150 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",150);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0014");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-45);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 43:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 155 )
			{
                write_user(who, ECHO "Ngươi không có đủ 155 Mảnh Ghép Ngọc Bội !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",155);
		if ( rate < 4 )		
	{
		item1 = new("/item/01/0015");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-50);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 44:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Áo") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Áo !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Áo",100);
		if ( rate < 4 )		
	{
		item1 = new("/item/set10sao/setbavuong/ao");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-100);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 45:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Nón") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Nón !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Nón",100);
		if ( rate < 4 )		
	{
		item1 = new("/item/set10sao/setbavuong/non");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-100);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 46:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Hạng Liên") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Hạng Liên !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Hạng Liên",100);	
		if ( rate < 4 )		
	{
		item1 = new("/item/set10sao/setbavuong/hanglien");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-100);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 47:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Yêu Đới") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Yêu Đới !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Yêu Đới",100);
		if ( rate < 4 )		
	{
		item1 = new("/item/set10sao/setbavuong/yeudoi");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-100);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;
		case 48:	
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Giày") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Giày !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Giày",100);
		if ( rate < 4 )		
	{
		item1 = new("/item/set10sao/setbavuong/giay");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 12 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-100);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;*/
		case 56:
		if (who->get_save_2("fride.day")==iDay)
		{
			result = me->get_name()+":\n    Hôm nay đã nhận rồi, ngày mai hãy đến !\n";
			send_user( who, "%c%c%w%s", ':', 3, 6010, result );
			return;
		}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}
		who->set_save_2("fride.day", iDay);
			item = new("/item/08/0006");
			i = item->move2(who,-1);
			item->add_to_user(i);
		who->add_cash(20000);
		who->add_exp(10000);
		send_user(who,"%c%s",':',me->get_name()+":\nChiến Quốc Lệnh +1 \nNgân Lượng : 20000 \nKinh nghiệm : 10000 \n"ESC"Rời khỏi.");
		break;
	/*	case 59:
		if (who->get_save_2("fride.gio")==iGio)
		{
			result = me->get_name()+":\n    Đã nhận rồi, hãy đợi tới giờ kế tiếp !\n";
			send_user( who, "%c%c%w%s", ':', 3, 6010, result );
			return;
		}
			who->add_save("hotrohangngay.score",1);
			who->set_save_2("fride.gio", iGio);
			who->add_cash(100000);
			who->add_exp(300000);
			send_user(who,"%c%s",':',me->get_name()+":\nNgân lượng + 100.000 lượng \nKinh nghiệm + 300.000 \n"ESC"Rời khỏi.");
		//	return 0;
		break;*/
		case 60:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Khí Huyết") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Khí Huyết" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Khí Huyết",2);	
		item = new("/item/final/SieuCap/1524");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Khí Huyết để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 61:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Pháp Lực") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Pháp Lực" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Pháp Lực",2);	
		item = new("/item/final/SieuCap/1526");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Pháp Lực để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 62:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Ngoại Công") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Ngoại Công" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Ngoại Công",2);	
		item = new("/item/final/SieuCap/1525");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Ngoại Công để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 63:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Nội Công") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Nội Công" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Nội Công",2);	
		item = new("/item/final/SieuCap/1528");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Nội Công để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 64:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Ngoại Kháng") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Ngoại Kháng" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Ngoại Kháng",2);	
		item = new("/item/final/SieuCap/1527");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Ngoại Kháng để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 65:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Nội Kháng") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Nội Kháng" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Nội Kháng",2);	
		item = new("/item/final/SieuCap/1529");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Nội Kháng để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
	/*	case 68:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Vương Giả") < 100 )
			{
                write_user(who, ECHO "Ngươi không có đủ 100 Mảnh Ghép Vương Giả!");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Vương Giả",100);
	if ( rate < 4 )		
	{
		item1 = new("/item/test2/NangCap/ppcanh");
		if ( !item1 )
			return 0;
	}
	else if ( rate < 20 )	
	{
		tien = 10000;
	}
	else if ( rate < 36 )	
	{
		tien = 10000;
	}
	else if ( rate < 48 )	
	{
		tien = 10000;
	}
	else if ( rate < 54 )
	{
		tien = 10000;
	}
	else if ( rate < 72 )
	{
		tien = 10000;
	}
	else if ( rate < 84 )
	{
		tien = 10000;
	}
	else if ( rate < 93 )
	{
		tien = 10000;
	}
	else 			
	{
		tien = 10000;
	}
	//item2->add_amount(-30);
	if ( tien ) 
{
 who->add_cash(tien);
send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
 }
	else if ( item1 )
	{
		cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"Hổ ấn Bá Vương"HIY"！！！", who->get_name() );
		l = item1->move2(who,-1);
		item1->add_to_user(l);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
	}
		return 0;
		break;	*/
		case 69:
		
		if ( who->get_cash() < 100000000 )
			{
				notify( "Không đủ 100 triệu ngân lượng" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
		who->add_cash(-100000000);
		item = new("/item/sell/0204");
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được "HIY+item->get_name());
		break;
	/*	case 66:
		if ( who->get_save("diemsumon.score") < 2 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 2 điểm tích luỹ Sư Môn!!! \nĐiểm tích luỹ Sư Môn có thể có được 1 điểm sau mỗi lần hoàn thành nhiệm vụ lượt thứ 10 của Sư Môn !!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		who->add_save("diemsumon.score",-2);
		who->add_exp(who->get_level()*10000);
		send_user(who,"%c%s",';',"Bạn nhận được "HIY " kinh nghiệm chúc phúc của Sứ giả hoạt động !!!");
		break;
		case 67:
		
		if ( "sys/sys/test_db"->get_yuanbao(who) < 5000 )
			{
				notify( "Ngươi không đủ 500 Kim Nguyên Bảo" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			"sys/sys/test_db"->add_yuanbao(who,-5000);	
		item = new("/item/set10sao/setbavuongthue/set10sao");
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được "HIY+item->get_name());
		break;
		case 500:
		
		if ( "sys/sys/test_db"->get_yuanbao(who) < 1000 )
			{
				notify( "Ngươi không đủ 100 Kim Nguyên Bảo" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			"sys/sys/test_db"->add_yuanbao(who,-1000);	
		item = new("/item/sell/4032");
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được "HIY+item->get_name());
		break;*/
		}
}
