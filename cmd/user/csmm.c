#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

int main(object me, string arg) 
{

    int p, cap, exist, exist2, i, size, iTime,ben,tet1=0,tet2=0,tet3,tet4,arg2,arg3,arg4;
	string result,*line,*data,username;
    object item, item1, who, *objs, target;
	mixed *mixTime;
	iTime = time();
	mixTime = localtime(iTime);	
		if( !arg ) return 1;
		if (arg==0) return 1;
		if( sscanf(arg, "? %d", arg2 ) == 1 ) 
		{
			if ( arg2 < 1 ) return 1;
			if ( arg2 > me->get_cash() ) return 1;
			send_user( me, "%c%c%d%s", '?', 16, 3, "Bạn đặt "+arg2+" lượng \nXin nhập con số may mắn:\n" ESC "csmm a "+arg2+" %s\n" );	
			me->set_save("csmmm",arg2);
			me->add_cash(-me->get_save("csmmm"));
		}
		else if( sscanf(arg, "a %d %d", arg2, arg3 ) == 2 ) 
		{
			if ( me->get_save("csmmm") < 1 ) return 1;
			if ( arg2 < 1 ) return 1;
		//	if ( arg2 > me->get_cash() ) return 1;
			if ( arg3 < 1 ) return 1;
			send_user( me, "%c%c%d%s", '?', 16, 3, "Bạn đặt "+arg2+" lượng \nCon số đầu tiên : "+arg3+"\nXin nhập con số may mắn:\n" ESC "csmm b "+arg2+" "+arg3+" %s\n" );
			me->set_save("csmm1",arg3);
			
		}	
		else if( sscanf(arg, "b %d %d %d", arg2, arg3, arg4 ) == 3 ) 
		{
			if ( me->get_save("csmmm") < 1 ) return 1;
			if ( me->get_save("csmm1") < 1 ) return 1;
			if ( arg2 < 1 ) return 1;
		//	if ( arg2 > me->get_cash() ) return 1;
			if ( arg3 < 1 ) return 1;
			if ( arg4 < 1 ) return 1;
			send_user(me, "%c%c%w%s",':',3,6010,"Sứ Giả Năm Mới :\nBạn đã đặt "+HIR+arg2+" lượng"NOR " cho con số may mắn "+HIR+arg3+NOR " và "+HIR+arg4+NOR " ! \n"ESC"Xác nhận \ncsmm kq\n"ESC"Rời khỏi");
			me->set_save("csmm2",arg4);	
		}
		if ( arg=="kq" )
		{
			if ( me->get_save("csmm1")>0 && me->get_save("csmm2")>0 )
			{
			if ( !is_god(me) )
			{	
				if ( random(1000) < 1 ) ben = 1;
				else ben = random(1000);
			}
			else ben = me->get_save("csmm1")+10;
				if ( abs(me->get_save("csmm1")-ben)<11 ) { tet1 = 1; tet3 = me->get_save("csmmm")*10; }
				if ( abs(me->get_save("csmm2")-ben)<11 ) { tet2 = 1; tet4 = me->get_save("csmmm")*10; }
				if ( tet1 ==1 && tet2==1 )
				{
				me->add_cash(tet3);
				me->add_cash(tet4);
				send_user(me,"%c%c%w%s",':',3,6010,"Sứ Giả Năm Mới :\nCon số may mắn là "+ben+", ngươi đã trúng cả 2 số !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				me->delete_save("csmm1");
				me->delete_save("csmm2");
				me->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng cả 2 con số, xin chúc mừng !");
				return ;
				}
				else if ( tet1 ==1 )
				{
				me->add_cash(tet3);
				send_user(me,"%c%c%w%s",':',3,6010,"Sứ Giả Năm Mới :\nCon số may mắn là "+ben+", ngươi đã trúng con số thứ 1 !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
				me->delete_save("csmm1");
				me->delete_save("csmm2");
				me->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng được con số đầu tiên, xin chúc mừng !");
				return ;
				}
				else if ( tet2 ==1 )
				{
				me->add_cash(tet4);
				send_user(me,"%c%c%w%s",':',3,6010,"Sứ Giả Năm Mới :\nCon số may mắn là "+ben+", ngươi đã trúng con số thứ 2 !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				me->delete_save("csmm1");
				me->delete_save("csmm2");
				me->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng được con số thứ hai, xin chúc mừng !");
				return ;
				}
				me->delete_save("csmm1");
				me->delete_save("csmm2");
				me->delete_save("csmmm");
				send_user(me,"%c%c%w%s",':',3,6010,"Sứ Giả Năm Mới :\nCon số may mắn là "+ben+", ngươi không trúng số nào !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		}
	return 1;
} 