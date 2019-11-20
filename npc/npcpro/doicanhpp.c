
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <item.h>
#include <equip.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5301; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Trao Đổi Trang Bị");
		set_real_name("Huyễn Thiên");
        set_2( "talk", ([
				"welcome"          : (: do_welcome :),
        ]));

       setup();
}

// 函数：对话处理
void do_look( object who )
{
	int id = getoid( this_object() );
	send_user(who,"%c%s",':',sprintf("Huyễn Thiên:\n Nếu có nhu cầu về trao đổi vật phẩm vai qua lại như cánh sang phi phong, phi phong sang cánh thì ta luôn sẵn sàng giúp các ngươi?\n"
		ESC"Đổi Vương Giả Phi Phong\ntalk %x# welcome.70\n"
		ESC"Đổi Xí Nhiệt Phi Phong\ntalk %x# welcome.71\n"
		ESC"Đổi Thánh Linh Chi Dực·Vàng Nhạt\ntalk %x# welcome.72\n"
		ESC"Đổi Thánh Linh Chi Dực·Trắng Thuần\ntalk %x# welcome.73\n"
		//ESC"Công thức và nguyên liệu nâng cấp\ntalk %x# welcome.81\n"
		ESC"Rời khỏi\n",id,id,id,id,id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,p;
	object who,item,item2;
	string cTmp,cFinal,cFile;
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
		case 70:
			send_user(who,"%c%s",':',sprintf("Huyễn Thiên:\n Nếu có nhu cầu về trao đổi vật phẩm vai qua lại như cánh sang phi phong, phi phong sang cánh thì ta luôn sẵn sàng giúp các ngươi, ngươi cần gì nào?\n"
				ESC"Đổi thành Xí Nhiệt Phi Phong\ntalk %x# welcome.801\n"
				ESC"Đổi thành Thánh Linh Chi Dực·Vàng Nhạt\ntalk %x# welcome.802\n"
				ESC"Đổi thành Thánh Linh Chi Dực·Trắng Thuần\ntalk %x# welcome.803\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 71:
			send_user(who,"%c%s",':',sprintf("Huyễn Thiên:\n Nếu có nhu cầu về trao đổi vật phẩm vai qua lại như cánh sang phi phong, phi phong sang cánh thì ta luôn sẵn sàng giúp các ngươi, ngươi cần gì nào?\n"
				ESC"Đổi thành Vương Giả Phi Phong\ntalk %x# welcome.804\n"
				ESC"Đổi thành Thánh Linh Chi Dực·Vàng Nhạt\ntalk %x# welcome.805\n"
				ESC"Đổi thành Thánh Linh Chi Dực·Trắng Thuần\ntalk %x# welcome.806\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 72:
			send_user(who,"%c%s",':',sprintf("Huyễn Thiên:\n Nếu có nhu cầu về trao đổi vật phẩm vai qua lại như cánh sang phi phong, phi phong sang cánh thì ta luôn sẵn sàng giúp các ngươi, ngươi cần gì nào?\n"
				ESC"Đổi thành Vương Giả Phi Phong\ntalk %x# welcome.807\n"
				ESC"Đổi thành Xí Nhiệt Phi Phong\ntalk %x# welcome.808\n"
				ESC"Đổi thành Thánh Linh Chi Dực·Trắng Thuần\ntalk %x# welcome.809\n"
				ESC"Thoát\n",id,id,id,id));
			break;
		case 73:
			send_user(who,"%c%s",':',sprintf("Huyễn Thiên:\n Nếu có nhu cầu về trao đổi vật phẩm vai qua lại như cánh sang phi phong, phi phong sang cánh thì ta luôn sẵn sàng giúp các ngươi, ngươi cần gì nào?\n"
				ESC"Đổi thành Vương Giả Phi Phong\ntalk %x# welcome.810\n"
				ESC"Đổi thành Xí Nhiệt Phi Phong\ntalk %x# welcome.811\n"
				ESC"Đổi thành Thánh Linh Chi Dực·Vàng Nhạt\ntalk %x# welcome.812\n"
				ESC"Thoát\n",id,id,id,id));
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
		case 812: 
		// Đổi VGPP thành cái khác
		if ( flag == 801 ) // Xí Nhiệt Phi Phong
		{
			cTmp = "Vương Giả Phi Phong";
			cFile = "item/30/3021";
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break; 
		if ( flag == 802 ) // Thánh Linh Chi Dực·Vàng Nhạt
		{
			cTmp = "Vương Giả Phi Phong";
			cFile = "item/30/3031"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item2_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item2(who,cTmp,1);
		if (item2->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
		item2 = new(cFile);
		item2->set_hide(0);
		item2->set_bind(2);
		i = item2->move(who,-1);
		if ( !i )
		{
			destruct(item2);
			return ;	
		}
		item2->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item2->get_name());
			break; 
	/*	if ( flag == 803 ) // Thánh Linh Chi Dực·Trắng Thuần
		{
			cTmp = "Vương Giả Phi Phong";
			cFile = "item/30/3028"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break; 
			
		// Đổi XNPP thành cái khác
		if ( flag == 804 ) // Vương Giả Phi Phong
		{
			cTmp = "Xí Nhiệt Phi Phong"; 
			cFile = "item/30/3020";
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break; 
		if ( flag == 805 ) //Thánh Chi Linh Dực·Vàng Nhạt
		{
			cTmp = "Xí Nhiệt Phi Phong";
			cFile = "item/30/3031"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break; 
		if ( flag == 806 ) // Thánh Linh Chi Dực·Trắng Thuần
		{
			cTmp = "Xí Nhiệt Phi Phong";
			cFile = "item/30/3028"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break;
		// Đổi Cánh Nam thành cái khác
		if ( flag == 807 ) // Vương Giả Phi Phong
		{
			cTmp = "Thánh Chi Linh Dực·Vàng Nhạt";
			cFile = "item/30/3020"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break;
		if ( flag == 808 ) // Xí Nhiệt Phi Phong
		{
			cTmp = "Thánh Chi Linh Dực·Vàng Nhạt";
			cFile = "item/30/3021"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break;
		if ( flag == 809 ) // Thánh Chi Linh Dực·Trắng Thuần
		{
			cTmp = "Thánh Chi Linh Dực·Vàng Nhạt";
			cFile = "item/30/3028"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break;
		// Đổi Cánh Nữ thành cái khác
		if ( flag == 810 ) // Vương Giả Phi Phong
		{
			cTmp = "Thánh Chi Linh Dực·Trắng Thuần";
			cFile = "item/30/3020"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break;
		if ( flag == 811 ) //Xí Nhiệt Phi Phong
		{
			cTmp = "Thánh Chi Linh Dực·Trắng Thuần";
			cFile = "item/30/3021"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break;
		if ( flag == 812 ) // Thánh Chi Linh Dực·Vàng Nhạt
		{
			cTmp = "Thánh Chi Linh Dực·Trắng Thuần";
			cFile = "item/30/3031"; 
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Huyễn Thiên:\n Ngươi không có "+cTmp+" trong túi làm sao để đổi đây?.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item(who,cTmp,1);
		if (item->get_bind()!=1) 
	   {
		send_user(who,"%c%s",'!',"Trang bị đang ở trạng thái phong ấn, hãy giải trừ trước khi đổi.");
			return 0;
	    }
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
		send_user(who,"%c%s",';',"Bạn đã đổi thành công "HIR+item->get_name());
			break; */
        }	
}
