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
int get_char_picid() { return 5801; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_real_name("Event Giải Phóng Lao Động");
		set_name("Nông Dân");
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Nghe đồn hôm nay là 30/4 sắp tới là 1/5 thì phải..hihi \n"
		ESC "Đổi chữ 30 tháng 4\ntalk %x# gift.1\n"
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
		case 1:
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s :\n Hôm nay là 30/4 , dân tình cứ xồn xồn lên nhỉ, bà con tìm ta có chuyện gì? \n"
			ESC"Đổi chữ Giải + Phóng + Lao + Động\ntalk %x# gift.11\n"
			ESC"Đổi chữ đặc biệt Giải Phóng Lao Động\ntalk %x# gift.12\n"
			ESC"Rời khỏi",me->get_name(),id,id));
			break;	
		case 11:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Giải") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Phóng") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Lao") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Động") < 1 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nông Dân:\nNgươi không có đủ chữ để ghép, cần mỗi loại 1 chữ!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nông Dân:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
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
		case 12:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Giải Phóng Lao Động") < 1 )
			{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nông Dân:\nNgươi không có chữ đặc biệt Giải Phóng Lao Động!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
			}			
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nông Dân:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Giải Phóng Lao Động",1);
			item=new("item/event/304/specialprize");
			p=item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");			
			break;	
		
		}
}
