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
int get_char_picid() { return 5801; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name("Người trồng Hoa");
		set_real_name("Sứ Giả Sự Kiện");
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Vào những ngày ý nghĩa, hoa hồng tượng trưng cho tình yêu, tình bạn, tình thầy trò. Để biết ơn thầy, cô đã phí hết tâm huyết dậy dỗ nhiều học trò nên người, có khi còn xuất chúng thành tài, ta được sự cho phép của Chu Vương đến đây giúp những người muốn tỏ lòng kính yêu đến thầy, cô của mình trồng ra những đoá Hoa hồng tươi thắm nhân ngày Nhà giáo Việt Nam 20/11. Nào ! ngươi muốn trồng Hoa hồng không ? \n"
		ESC "Đổi Tàng Hoa Hồng lấy Hoa Hồng\ntalk %x# gift.1\n"
		ESC "Ta muốn trồng Hoa hồng\ntalk %x# gift.2\n"
		ESC "Ta muốn tìm hiểu cách trồng Hoa hồng\ntalk %x# gift.3\n"
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
		   if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Tàng Hoa Hồng") < 100 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Người Trồng Hoa:\n 100 Tàng Hoa Hồng mới có thể đổi được 1 Hoa Hồng .\n"ESC"Rời khỏi"));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,"Tàng Hoa Hồng",100);
		item = new("/item/event/nhagiao/hoahong");
		i = item->move2(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn đã đổi được "HIR+item->get_name());
			break;	
		case 2:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Hạt giống Hoa Hồng") < 1 || 
					TASK_LEGEND_D->check_task_item_amount(who,"Nước Tưới Cây") < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi không có đủ Nguyên liệu, hãy tìm đủ rồi mới đến tìm ta nhé ! \n"
					ESC "Ta biết rồi\ntalk %x# gift.1000\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
					return ;	
				}
			 if (me->get_strength()>=5)
        {
               send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi không có Thể Lực! Hãy chuẩn bị Thể Lực kĩ lưỡng trước khi trồng hoa. \n"
					ESC "Ta hiểu rồi\ntalk %x# gift.1000\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
					return ;
        }
				set_effect(who, EFFECT_PROGRESS2, 10);
				who->set_progress_file(__FILE__);   
				who->add_strength(-5);
				send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang trồng Hoa...");	
				
			break;
		case 3:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Trồng hoa hồng cần 2 thứ :\n1.Hạt giống Hoa Hồng ( có thể tìm thấy khi tiêu diệt Boss trong Phong Yêu Kính )\n2. Nước Tưới Cây ( có thể tìm thấy khi tiêu diệt Boss Tập kích Môn Phái hoặc Chiến Quốc Tống Bảo Tiểu Yêu ) \n+ Khi trồng Hoa Hồng có tỷ lệ nhất định trồng ra Hoa Hồng đặc biệt \n+ Mua một lá Thư Chúc Phúc tại Bảo Khố sẽ đầy ý nghĩa hơn với một lời chúc công khai trên toàn Thế giới. \n"
					ESC "Ta hiểu rồi\ntalk %x# gift.1000\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
			break;	
		}
}
int into_effect( object who , string arg)
{
	int p, rate;
	object item;
	rate = random(100);
	send_user(who, "%c%c%c", 0x5a, 1, 1);
				TASK_LEGEND_D->check_task_item1(who,"Hạt giống Hoa Hồng",1);
				TASK_LEGEND_D->check_task_item1(who,"Nước Tưới Cây",1);
				if ( rate < 4 )
				{
		if( objectp( item = present("Hoa Hồng Đặc Biệt", who, 1, MAX_CARRY*4) ) && item->get_amount() < 10000 )
		{
			item->add_amount(1);				
		}
	
		else
		{
				item = new("/item/event/nhagiao/hoahongdacbiet");
				p = item->move2(who,-1);
				item->add_to_user(p);			
		}		
				send_user(who, "%c%s", ';', sprintf("Bạn đã trồng được %s !", item->get_name()));
				}
				else if ( rate < 51 )
				{
		if( objectp( item = present("Hoa Hồng", who, 1, MAX_CARRY*4) ) && item->get_amount() < 10000 )
		{
			item->add_amount(1);				
		}
		else
		{	
				item = new("/item/event/nhagiao/hoahong");
				p = item->move2(who,-1);
				item->add_to_user(p);
				
		}		
				send_user(who, "%c%s", ';', sprintf("Bạn đã trồng được %s !", item->get_name()));
				}
				else
				{
				who->add_cash(1000);				
				send_user(who, "%c%s", ';', "Bạn trồng Hoa Hồng thất bại. Hãy cố gắng vào lần sau!");
				
				}
	return 1;
}
void effect_break(object me, string arg)
{
	send_user(me, "%c%c%c", 0x5a, 1, 0);
	set_effect(me, EFFECT_PROGRESS2, 0 );	
}