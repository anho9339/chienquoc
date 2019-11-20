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
int get_char_picid() { return 8200; }
void do_gift( string arg );
// 函数：小贩识别
int is_seller() { return 4; }
// 有自己的do_look函数
int is_self_look() { return 1; }

void create()
{
        set_real_name("Tiên Ông");
		set_name("Sứ Giả Năm Mới");
		set_2( "good", ([
                "01" : "/item/event/tet/phaonl",
       //         "02" : "/item/ngoai_trang/vip102",			
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
	object me = this_object();
	string result;
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ta được lệnh xuống đây để giúp đỡ mọi người trong năm mới, hãy nói xem, các vị anh hùng đây muốn gì ở ta? \n"
		ESC "Mua Pháo (Bằng Ngân Lượng)\nlist %x#\n"
		ESC "Ghép Hỏa Kỳ Lân\ntalk %x# gift.11\n"
		ESC "Ghép Niên Thú\ntalk %x# gift.12\n"		
	//	ESC "Nhận Túi Quà Năm Mới\ntalk %x# gift.13\n"									
		ESC"Rời khỏi",get_name(),id,id,id,id,id));	
		
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien,ben, tet1=0,tet2=0, tet3, tet4,bennhat2,bn2,level;
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
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Hỏa Kỳ Lân") < 30 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông :\nNgươi không có đủ 30 Mảnh Ghép Hỏa Kỳ Lân !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Hỏa Kỳ Lân",30);	
			if ( random100() <	30 )
				item=new("item/event/tet/hkl");
			else
				notify("Ghép thất bại !");
			if ( item ) 
			{
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
			CHAT_D->sys_channel(0,sprintf(HIY"Xin chúc mừng "HIB"%s "NOR" đã ghép thành công "HIG" Hỏa Kỳ Lân "NOR"!",who->get_name()));
			}
			break;	
		case 12:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Niên Thú") < 20 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông :\nNgươi không có đủ 20 Mảnh Ghép Niên Thú !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Niên Thú",20);	
			if ( random100() < 50 )
				item=new("item/08/1001");
			else
				notify("Ghép thất bại !");
			if ( item ) 
			{
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
			CHAT_D->sys_channel(0,sprintf(HIR"Xin chúc mừng "HIB"%s "NOR" đã ghép thành công "HIG" Niên Thú "NOR"!",who->get_name()));
			}
			break; 	 
		/*case 13:
			if ( who->get_level() < 80 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông:\nNgươi chưa đạt cấp 80, không thể nhận Túi Quà Năm Mới!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
			return;
			}
			if ( who->get_save("tqnm")> 0 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông :\nNgươi đã nhận Túi Quà Năm Mới rồi!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			
			who->set_save("tqnm",1);
			item = new("/item/event/tet/tqnm");
			p = item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Tiên Ông :\nNgươi đã nhận thành công 1 Túi Quà Năm Mới !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			break;	 */	
		}
}
