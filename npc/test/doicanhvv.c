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
int get_char_picid() { return 8206; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name("Đổi Ghép Trang Bị");
		set_real_name("Kinh Thiên");
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ta là người có khả năng sửa chữa và tinh chỉnh vạn vật. Nếu ngươi có hứng thú. Ta sẽ cho ngươi hên xui thứ ngươi cần đấy. Còn không cần thì ta lượn nha!\n"	
		ESC "Đổi Dầu Ăn\ntalk %x# gift.10\n"
        ESC "Đổi Dép Lào\ntalk %x# gift.20\n"
        ESC "Ghép Ngọc Bội Tín Vật\ntalk %x# gift.30\n"		
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));	
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
			// Đổi Dầu Ăn
		case 10:
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(me->get_name()+": \nNgươi muốn đổi Phi Phong nào bằng cái Dầu Ăn này?\n"
			ESC"Ta muốn đổi lấy Vương Giả Phi Phong\ntalk %x# gift.11\n"
			ESC"Ta muốn đổi lấy Xí Nhiệt Phi Phong\ntalk %x# gift.12\n"
			ESC"Rời khỏi",id,id,id,id));
			break; 
		case 11:	
		case 12:		
			if ( flag==11 ) bn="item/30/3020";
			else if ( flag==12 ) bn="item/30/3021";
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Dầu Ăn") < 300 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Kinh Thiên:\nVậy là ngươi không có 300 Dầu Ăn? Vậy thì đừng đến đây !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Kinh Thiên:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Dầu Ăn",300);	
			if ( random100() < 30 )
				item=new(bn);
			else
				notify("Đổi thất bại, xin chia buồn!");
			if ( item ) 
			{
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
				CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR"đã đổi thành công "HIY"%s"NOR "!",item->get_name()));
			}
			break;
			// Đổi Dép Lào
	    case 20:
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(me->get_name()+": \nNgươi muốn đổi loại Cánh nào bằng cái Dép Lào này?\n"
			ESC"Ta muốn đổi lấy Thánh Linh Chi Dực Vàng Nhạt\ntalk %x# gift.21\n"
			ESC"Ta muốn đổi lấy Thánh Linh Chi Dực Trắng Thuần\ntalk %x# gift.22\n"
			ESC"Rời khỏi",id,id,id,id));
			break; 
		case 21:	
		case 22:		
		    if ( flag==21 ) bn="item/30/3031";
			else if ( flag==22 ) bn="item/30/3028";
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Dép Lào") < 300 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Kinh Thiên:\nVậy là ngươi không có 300 Dép Lào? Vậy thì đừng đến đây !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Kinh Thiên:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Dép Lào",300);	
			if ( random100() < 30 )
				item=new(bn);
			else
				notify("Đổi thất bại, xin chia buồn!");
			if ( item ) 
			{
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
				CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR"đã đổi thành công "HIY"%s"NOR "!",item->get_name()));
			}
			break;
      case 30:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \n"
				//	ESC HIY"[Kì Lân Ngọc Bội]\ntalk %x# gift.31\n"
					ESC HIY"[Phượng Hoàng Ngọc Bội]\ntalk %x# gift.32\n"
				/*	ESC HIY"[Phượng Vũ Ngọc Bội]\ntalk %x# gift.33\n"
					ESC HIY"[Chu Tước Ngọc Bội]\ntalk %x# gift.34\n"
					ESC HIY"[Uyên Ương Ngọc Bội]\ntalk %x# gift.35\n"
					ESC HIY"[Bạch Hổ Ngọc Bội]\ntalk %x# gift.36\n"
					ESC HIY"[Thiên Ân Ngọc Bội]\ntalk %x# gift.37\n"
					ESC HIY"[Âm Dương Ngọc Bội]\ntalk %x# gift.38\n"
					ESC HIY"[Song Phụng Ngọc Bội]\ntalk %x# gift.39\n" */
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id,id));
			break;
     case 32:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Phượng Hoàng") < 50 )
			{
                write_user(who, ECHO "Ngươi không có đủ 50 Mảnh Ghép Phượng Hoàng !");
                return ;
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Phượng Hoàng",50);
		if ( rate < 54 )		
	    {
		item1 = new("/item/01/0008");
		if ( !item1 )
			return 0;
	    }
	else if ( rate < 12 )	
	{
		tien = 10000+random(2500);
	}
	else if ( rate < 36 )	
	{
		tien = 10000+random(2000);
	}
	else if ( rate < 48 )	
	{
		tien = 10000+random(1500);
	}
	else if ( rate < 14 )
	{
		tien = 10000+random(1000);
	}
	else if ( rate < 72 )
	{
		tien = 10000+random(3000);
	}
	else if ( rate < 84 )
	{
		tien = 10000+random(5000);
	}
	else if ( rate < 93 )
	{
		tien = 10000+random(500);
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
		
		}
}
