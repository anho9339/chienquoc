
#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>
inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 8299; }
void do_welcome(string arg);
void do_nhannv(string arg);
void do_accept(string arg);
void create()
{	  
        set_name("Thao Tác Đoạn Thạch");
		set_real_name("Phàm Chân");
		set_2( "talk", ([
                "welcome"	:( : do_welcome :),
				"giaotrangbi"         : (: do_accept :),
				"nhannv"         : (: do_nhannv :),
             ]));
        setup();

}

void do_welcome( string arg )
{
	__FILE__->do_welcome2(this_object(),arg);
}
void do_welcome2( object npc, string arg )
{
	int flag,p,i,size,sao,ben,ben123,s,id,tien,l,rate;
	object player  = this_player(),item,item1,item2,item3, who,me;
	string name,name2,name3,name4,thanbinh,ss,forge="",nhat123,nhat1234;
    string *nTmp,cFile,cTmp,cFinal,result,bennhat,bn;
	flag = to_int(arg);
	 who = this_player();
//	id = getoid(me);
 //      who->set_time( "talk",  0);
	 rate = random(100);
	switch(flag)
	{
		case 1:
		send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),sprintf(npc->get_name() + ":\n"+"Ta sẽ giúp ngươi tách Đoạn Thạch cấp cao thành cấp thấp nếu ngươi cảm thấy có quá nhiều Đoạn Thạch cấp cao. (Lưu ý Cao Cấp kể cả khóa hay không khi tách ra cũng sẽ là khóa hết) ! Nào ngươi muốn tham gia chức năng này không ?\n" 
			ESC "Tách Cao Cấp Thành 2 Trung Cấp\ntalk %x# welcome.601\n"
			ESC "Tách Trung Cấp Thành 2 Sơ Cấp\ntalk %x# welcome.602\n"
			ESC "Thoát ra\nCLOSE\n",getoid(npc),getoid(npc),getoid(npc),getoid(npc),getoid(npc),getoid(npc)));
			break; 
		case 2:
		 //   if ( flag==11 ) bn="item/30/3020";
		//	else if ( flag==12 ) bn="item/30/3021";
			if ( TASK_LEGEND_D->check_task_item_amount(who,"MG Bảo Để Phù") < 50 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Phàm Chân:\nVậy là ngươi không có 50 MG Bảo Để Phù? Vậy đến đây làm gì vậy !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}
			if (who->get_cash() < 100000 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Phàm Chân:\n Ngươi không đủ 100.000 ngân lượng! \n"ESC"Xác Nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Phàm Chân:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"MG Bảo Để Phù",50);	
			if ( random100() < 80 )
				item=new("item/sell/0034");
			else
				notify("Ghép thất bại, xin chia buồn cùng các hạ!");
			if ( item ) 
			{
				who->add_cash(-100000);
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
				CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR"đã đổi thành công "HIY"%s"NOR "!",item->get_name()));
			}
			break;
		case 601:	
		case 602:		
			if ( flag==601 ){ben123=1;nhat123="Cao Cấp Đoạn Thạch";nhat1234="item/dtkhoa/1032";}
			else if ( flag==602 ){ben123=1;nhat123="Trung Cấp Đoạn Thạch";nhat1234="item/dtkhoa/0032";}
			if( USER_INVENTORY_D->get_free_count(player) < 2 )
			{
				send_user(player,"%c%c%w%s",':',3,8299, "Phàm Chân: \nHành trang của ngươi không đủ 2 ô trống, hãy thu xếp hành trang rồi đến gặp ta ! \n"ESC"Xác nhận");
				return;
			}
			if ( TASK_LEGEND_D->check_task_item_amount(player,nhat123) < ben123 )
			{
				send_user(player,"%c%c%w%s",':',3,8299, "Phàm Chân: \nNgươi không có đủ "+nhat123+"  ! \n"ESC"Xác nhận");
				return;
			}
			TASK_LEGEND_D->check_task_item1(player,nhat123,ben123); 
			item=new(nhat1234);
			p=item->move2(player,-1);
			//item->set_no_give(1);
			item->add_to_user(p);

			item2=new(nhat1234);
			s=item2->move2(player,-1);
		//	item->set_no_give(1);
			item2->add_to_user(s);
			send_user(player,"%c%c%w%s",':',3,8299, "Phàm Chân: \nNgươi đã Tách thành công! Chúc mừng!\n"ESC"Xác nhận");
			break; 
			
		case 3:
		send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),sprintf(npc->get_name() + ":\n"+"Ta sẽ giúp ngươi ghép đoạn thạch, tỉ lệ là 80 phần trăm thành công, ngươi có thật sự muốn thử vận may không?\n" 
			ESC "20 mảnh ghép Sơ Cấp Đoạn Thạch \ntalk %x# welcome.301\n"
			ESC "30 mảnh ghép Trung Cấp Đoạn Thạch \ntalk %x# welcome.302\n"
			ESC "50 mảnh ghép Cao Cấp Đoạn Thạch \ntalk %x# welcome.303\n"
			ESC "Thoát ra\nCLOSE\n",getoid(npc),getoid(npc),getoid(npc),getoid(npc),getoid(npc),getoid(npc)));
			break; 
		case 301:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Đoạn Thạch") < 20 )
			{
				write_user(who, ECHO "Ngươi không có đủ 20 Mảnh Ghép Đoạn Thạch!");
				return ;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
				notify( "Hành trang không đủ 1 chỗ trống" );
			return ;
			}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Đoạn Thạch",20);
			if ( rate < 80 )		
			{
			item1 = new("/item/sell/0032");
			if ( !item1 )
			return 0;
			}
			else if ( rate < 10 )	
			{
			tien = 10000+random(2500);
			}
			else if ( rate < 20 )	
			{
			tien = 9000+random(2000);
			}
			else if ( rate < 30 )	
			{
			tien = 8000+random(1500);
			}
			else if ( rate < 40)
			{
			tien = 7000+random(1000);
			}
			else if ( rate < 50 )
			{
			tien = 6000+random(3000);
			}
			else if ( rate < 60 )
			{
			tien = 5000+random(5000);
			}
			else if ( rate < 90 )
			{
			tien = 4000+random(500);
			}
			else 			
			{
			tien = 3000+random(500);
			}
			if ( tien ) 
			{
			who->add_cash(tien);
			send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
			}
			else if ( item1 )
			{
		//	cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIR"%s "HIY" đã Hợp Thành \"thành công\".Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
			l = item1->move2(who,-1);
			item1->add_to_user(l);
		//	send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
			send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
			}
			return 0;
			break;	
		case 302:	
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Đoạn Thạch") < 30 )
			{
				write_user(who, ECHO "Ngươi không có đủ 30 Mảnh Ghép Đoạn Thạch!");
				return ;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
				notify( "Hành trang không đủ 1 chỗ trống" );
			return ;
			}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Đoạn Thạch",30);
			if ( rate < 80 ) // 70%
			{
			item1 = new("/item/sell/1032");
			if ( !item1 )
			return 0;
			}
			else if ( rate < 10 )	
			{
			tien = 10000+random(2500);
			}
			else if ( rate < 20 )	
			{
			tien = 9000+random(2000);
			}
			else if ( rate < 30 )	
			{
			tien = 8000+random(1500);
			}
			else if ( rate < 40 )
			{
			tien = 7000+random(1000);
			}
			else if ( rate < 50 )
			{
			tien = 6000+random(3000);
			}
			else if ( rate < 60 )
			{
			tien = 5000+random(5000);
			}
			else if ( rate < 70 )
			{
			tien = 4000+random(500);
			}
			else 			
			{
			tien = 3000+random(500);
			}
			if ( tien ) 
			{
			who->add_cash(tien);
			send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
			}
			else if ( item1 )
			{
		//	cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIR"%s "HIY" đã Hợp Thành \"thành công\".Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
			l = item1->move2(who,-1);
			item1->add_to_user(l);
		//	send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
			send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
			}
			return 0;
			break;	
		case 303:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Đoạn Thạch") < 50 )
			{
				write_user(who, ECHO "Ngươi không có đủ 50 Mảnh Ghép Đoạn Thạch!");
				return ;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
				notify( "Hành trang không đủ 1 chỗ trống" );
			return ;
			}		
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Đoạn Thạch",50);
			if ( rate < 80 )	// 50%	
			{
			item1 = new("/item/sell/2032");
			if ( !item1 )
			return 0;
			}
			else if ( rate < 10 )	
			{
			tien = 10000+random(2500);
			}
			else if ( rate < 20 )	
			{
			tien = 9000+random(2000);
			}
			else if ( rate < 30 )	
			{
			tien = 8000+random(1500);
			}
			else if ( rate < 40 )
			{
			tien = 7000+random(1000);
			}
			else if ( rate < 60 )
			{
			tien = 6000+random(3000);
			}
			else if ( rate < 70 )
			{
			tien = 5000+random(5000);
			}
			else if ( rate < 50 )
			{
			tien = 4000+random(500);
			}
			else 			
			{
			tien = 3000+random(500);
			}
			if ( tien ) 
			{
			who->add_cash(tien);
			send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
			}
			else if ( item1 )
			{
			cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\".Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
			l = item1->move2(who,-1);
			item1->add_to_user(l);
			send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
			send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
			}
			return 0;
			break;	

	}
}

void do_look( object player )
{
	object npc = this_object();
	
	send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf( "%s :\n"+"Phàm người sinh ra trên đời, có dư thì sẽ có thiếu, dư cái này sẽ thiếu cái kia. Chân lí đó ai cũng hiểu, ta hiểu chân lí đó nên ta xuất hiện nơi đây, giúp mọi người giải quyết vấn đề đó. Vấn đề của ngươi là gì? \n"
		ESC "Tách Đoạn Thạch\ntalk %x# welcome.1\n"
		ESC "Ghép Bảo Để Phù\ntalk %x# welcome.2\n"
		ESC "Ghép Đoạn Thạch\ntalk %x# welcome.3\n"
        ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc), getoid(npc) ) );
}
