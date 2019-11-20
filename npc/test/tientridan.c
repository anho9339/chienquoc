
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 8273; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Tiên Tri Đàn");
		set_real_name("Thần Thạch");
        set_2( "talk", ([
				"welcome"          : (: do_welcome :),
        ]));

       setup();
}

// 函数：对话处理
void do_look( object who )
{
	int id = getoid( this_object() );
	send_user(who,"%c%s",':',sprintf("Tiên Tri Đàn:\n Ta có thể tiên đoán vạn vật trên thế giới, nhưng không thể đoán nổi chỉ số sức mạnh của Huyết Long thần trang.\n"
		ESC"Đổi trang bị Huyết Long\ntalk %x# welcome.80\n"
		ESC"Cách thức đổi trang bị\ntalk %x# welcome.81\n"
		ESC"Rời khỏi\n",id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,p,rate;
	object who,item;
	string cTmp,cFinal,cFile;
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
		rate = random(100);
		
        switch(flag)
        {
		case 80:
			send_user(who,"%c%s",':',sprintf("Tiên Tri Đàn:\n Hãy chọn một trang bị mà ngươi muốn đi.\n"
				ESC"Đổi Huyết Long Khôi\ntalk %x# welcome.801\n"
				ESC"Đổi Huyết Long Giáp\ntalk %x# welcome.802\n"
				ESC"Đổi Huyết Long Hạng Liên\ntalk %x# welcome.803\n"
				ESC"Đổi Huyết Long Yêu Đới\ntalk %x# welcome.804\n"
				ESC"Đổi Huyết Long Hài\ntalk %x# welcome.805\n"
				ESC"Thoát ra\n",id,id,id,id,id,id));
			break;
		case 81:
			send_user(who,"%c%s",':',sprintf("Tiên Tri Đàn:\n Ngươi muốn biết về cách thức hay cách tìm ra trang bị Huyết Long?.\n"
				ESC"Cách thức đổi trang bị\ntalk %x# welcome.811\n"
				ESC"Cách tìm trang bị\ntalk %x# welcome.821\n"
				ESC"Thoát ra\n",id,id,id,id,id,id));
			break;
		case 801:
		case 802:
		case 803:
		case 804:
		case 805:
		case 806:
		if ( flag == 801 )
		{
			if (who->get_fam_name()=="Đào Hoa Nguyên"||!who->get_fam_name("Đào Hoa Nguyên"))
			{
				cFile = "item/huyetlong/1/non";
			}
			else if (who->get_fam_name()=="Thục Sơn"||!who->get_fam_name("Thục Sơn"))
			{
				cFile = "item/huyetlong/2/non";
			}
			else if (who->get_fam_name()=="Cấm Vệ Quân"||!who->get_fam_name("Cấm Vệ Quân"))
			{
				cFile = "item/huyetlong/3/non";
			}
			else if (who->get_fam_name()=="Đường Môn"||!who->get_fam_name("Đường Môn"))
			{
				cFile = "item/huyetlong/4/non";
			}
			else if (who->get_fam_name()=="Mao Sơn"||!who->get_fam_name("Mao Sơn"))
			{
				cFile = "item/huyetlong/5/non";
			}
			else if (who->get_fam_name()=="Côn Luân"||!who->get_fam_name("Côn Luân"))
			{
				cFile = "item/huyetlong/6/non";
			}
			else if (who->get_fam_name()=="Vân Mộng Cốc"||!who->get_fam_name("Vân Mộng Cốc"))
			{
				cFile = "item/huyetlong/7/non";
			}
		}
		else if ( flag == 802 )
		{
			if (who->get_fam_name()=="Đào Hoa Nguyên"||!who->get_fam_name("Đào Hoa Nguyên"))
			{
				cFile = "item/huyetlong/1/ao";
			}
			else if (who->get_fam_name()=="Thục Sơn"||!who->get_fam_name("Thục Sơn"))
			{
				cFile = "item/huyetlong/2/ao";
			}
			else if (who->get_fam_name()=="Cấm Vệ Quân"||!who->get_fam_name("Cấm Vệ Quân"))
			{
				cFile = "item/huyetlong/3/ao";
			}
			else if (who->get_fam_name()=="Đường Môn"||!who->get_fam_name("Đường Môn"))
			{
				cFile = "item/huyetlong/4/ao";
			}
			else if (who->get_fam_name()=="Mao Sơn"||!who->get_fam_name("Mao Sơn"))
			{
				cFile = "item/huyetlong/5/ao";
			}
			else if (who->get_fam_name()=="Côn Luân"||!who->get_fam_name("Côn Luân"))
			{
				cFile = "item/huyetlong/6/ao";
			}
			else if (who->get_fam_name()=="Vân Mộng Cốc"||!who->get_fam_name("Vân Mộng Cốc"))
			{
				cFile = "item/huyetlong/7/ao";
			}
		}
		else if ( flag == 803 )
		{
			if (who->get_fam_name()=="Đào Hoa Nguyên"||!who->get_fam_name("Đào Hoa Nguyên"))
			{
				cFile = "item/huyetlong/1/hanglien";
			}
			else if (who->get_fam_name()=="Thục Sơn"||!who->get_fam_name("Thục Sơn"))
			{
				cFile = "item/huyetlong/2/hanglien";
			}
			else if (who->get_fam_name()=="Cấm Vệ Quân"||!who->get_fam_name("Cấm Vệ Quân"))
			{
				cFile = "item/huyetlong/3/hanglien";
			}
			else if (who->get_fam_name()=="Đường Môn"||!who->get_fam_name("Đường Môn"))
			{
				cFile = "item/huyetlong/4/hanglien";
			}
			else if (who->get_fam_name()=="Mao Sơn"||!who->get_fam_name("Mao Sơn"))
			{
				cFile = "item/huyetlong/5/hanglien";
			}
			else if (who->get_fam_name()=="Côn Luân"||!who->get_fam_name("Côn Luân"))
			{
				cFile = "item/huyetlong/6/hanglien";
			}
			else if (who->get_fam_name()=="Vân Mộng Cốc"||!who->get_fam_name("Vân Mộng Cốc"))
			{
				cFile = "item/huyetlong/7/hanglien";
			}
		}
		else if ( flag == 804 )
		{
			if (who->get_fam_name()=="Đào Hoa Nguyên"||!who->get_fam_name("Đào Hoa Nguyên"))
			{
				cFile = "item/huyetlong/1/yeudoi";
			}
			else if (who->get_fam_name()=="Thục Sơn"||!who->get_fam_name("Thục Sơn"))
			{
				cFile = "item/huyetlong/2/yeudoi";
			}
			else if (who->get_fam_name()=="Cấm Vệ Quân"||!who->get_fam_name("Cấm Vệ Quân"))
			{
				cFile = "item/huyetlong/3/yeudoi";
			}
			else if (who->get_fam_name()=="Đường Môn"||!who->get_fam_name("Đường Môn"))
			{
				cFile = "item/huyetlong/4/yeudoi";
			}
			else if (who->get_fam_name()=="Mao Sơn"||!who->get_fam_name("Mao Sơn"))
			{
				cFile = "item/huyetlong/5/yeudoi";
			}
			else if (who->get_fam_name()=="Côn Luân"||!who->get_fam_name("Côn Luân"))
			{
				cFile = "item/huyetlong/6/yeudoi";
			}
			else if (who->get_fam_name()=="Vân Mộng Cốc"||!who->get_fam_name("Vân Mộng Cốc"))
			{
				cFile = "item/huyetlong/7/yeudoi";
			}
		}
		else if ( flag == 805 )
		{
			if (who->get_fam_name()=="Đào Hoa Nguyên"||!who->get_fam_name("Đào Hoa Nguyên"))
			{
				cFile = "item/huyetlong/1/giay";
			}
			else if (who->get_fam_name()=="Thục Sơn"||!who->get_fam_name("Thục Sơn"))
			{
				cFile = "item/huyetlong/2/giay";
			}
			else if (who->get_fam_name()=="Cấm Vệ Quân"||!who->get_fam_name("Cấm Vệ Quân"))
			{
				cFile = "item/huyetlong/3/giay";
			}
			else if (who->get_fam_name()=="Đường Môn"||!who->get_fam_name("Đường Môn"))
			{
				cFile = "item/huyetlong/4/giay";
			}
			else if (who->get_fam_name()=="Mao Sơn"||!who->get_fam_name("Mao Sơn"))
			{
				cFile = "item/huyetlong/5/giay";
			}
			else if (who->get_fam_name()=="Côn Luân"||!who->get_fam_name("Côn Luân"))
			{
				cFile = "item/huyetlong/6/giay";
			}
			else if (who->get_fam_name()=="Vân Mộng Cốc"||!who->get_fam_name("Vân Mộng Cốc"))
			{
				cFile = "item/huyetlong/7/giay";
			}
		}
		if (who->get_fam_name()==""||!who->get_fam_name())
	   {
		send_user(who, "%c%s", '!', "Ngươi chưa gia nhập môn phái sao?");
		return 0;
	   }
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if( who->get_cash() < 100000 )
		{
			send_user(who,"%c%s",'!',"Ngươi không đủ 100.000 ngân lượng.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Chiếu Thư Thiên Tử") < 100 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Tiên Tri Đàn:\n Chiếu Thư Thiên Tử của ngươi không đủ 100, làm sao ta có thể xin Thiên Tử lấy Huyết Long cho ngươi đây?.\n"ESC"Rời khỏi"));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,"Chiếu Thư Thiên Tử",100);
		if ( random100() <	40 ) {
		item = new(cFile);
		} else {
			notify("Ghép thất bại, bạn nhận được khoản tiền an ủi!");
			who->add_cash(100000+random(20000));
			//send_user(who,"%c%s",';',"Ghép thất bại, bạn nhận được khoản tiền an ủi");
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR " ghép Thần Trang thất bại, xin chia buồn.", who->get_name() ));
		}
	//	item->set_hide(0);
	//	item->set_bind(1);	
		if ( item ) 
			{
		who->add_cash(-100000);
		i = item->move2(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn đạt được thần trang"HIR+item->get_name());
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR " ghép thành công thần trang "HIR" %s ", who->get_name(),item->get_name() ));
			}
			break;
		case 811:
			send_user(who,"%c%s",':',sprintf("Tiên Tri Đàn:\n Để đổi trang bị, ta cần phải xin phép Thiên Tử cho ta lấy trang bị cho ngươi vì thế ta cần '100 Chiếu Thư Thiên Tử' và 100.000 ngân lượng để làm điều đó.\n"ESC"Thoát ra"));
			break;
		case 821:
			send_user(who,"%c%s",':',sprintf("Tiên Tri Đàn:\n Chiếu Thư Thiên Tử có thể tìm thông qua Thủ Thành và một số hoạt động event khác (Thông báo trên Group CQTD).\n"ESC"Thoát ra"));
			break;
        }	
}
