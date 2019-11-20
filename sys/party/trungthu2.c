/********************************************************************************************************************************
		    ----------------------- Bắt Thỏ Ngọc - Trung Thu 2 --------------------
********************************************************************************************************************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define ThoNgoc 			"npc/event/trungthu/thongoc"

int iStart,iFinish;
void generate_scum();
void destroy_scum();
object *Scum;
mapping mpNianshou;
// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
//	restore();
	Scum = ({});
	call_out("check_time",1);
}

void check_time()
{
    int iHour;
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time");
	iTime = time();
	if (MAIN_D->get_host_type()==2)		//台湾除外
		return ;
	iHour = time();
	if ( iHour > iFinish )
		return ;
	if ( iHour < iStart )	//没到时间
	{
		call_out("check_time",iStart - iHour);
		return ;
	}
	call_out("check_time",18000); //5h
//	mixTime = localtime(iTime);

/*//	if ( mixTime[TIME_WDAY] == 5 || mixTime[TIME_WDAY] == 6 )
//	{
//		destroy_scum();
//		call_out("check_time",3600*24);
//		return ;
//	}
//	else if ( mixTime[TIME_WDAY] == 0 )
//	{
//		call_out("check_time",3600*24-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
//		return ;
//	}
//	else*/
/*	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 0 )
		{
			call_out("check_time",i);
		}
		else
		{
			if ( mixTime[TIME_HOUR] == 3 || mixTime[TIME_HOUR] == 5 || mixTime[TIME_HOUR] == 7 )
				call_out("check_time",i+3600);
			else
			{
				generate_scum();
				call_out("check_time",i+3600);
			}
		}
	}
*/
} 

//  放入武林败类NPC
void generate_scum()
{
	int i,size,z,p,x,y,j;
	object npc;

//	destroy_scum();
	
	for(i=0;i<=30;i++)
	{
		if( !( p = efun::get_xy_point( 001, IS_CHAR_BLOCK ) ) )
			continue;
		x = ( p % 1000000 ) / 1000;
		y = p % 1000;
		npc = new(ThoNgoc);
		npc->add_to_scene(001,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",3600); // 1 tiếng tự biến mất
	
	CHAT_D->sys_channel(0,HIC "Help! Help! Thỏ Ngọc đang chạy rông tại "HIY "Tân Thủ Thôn "HIC" . Mong các anh hùng mau đến bắt nó về!");
	CHAT_D->sys_channel(0,HIC "Help! Help! Thỏ Ngọc đang chạy rông tại "HIY "Tân Thủ Thôn "HIC" . Mong các anh hùng mau đến bắt nó về!");
//	CHAT_D->sys_channel(0,HIC"Nghe nói Ác Quỷ Vương đã xuất hiện ở ngoài thành Chu Quốc, nếu như bắt được đám Ác Quỷ này thì có thể đến nơi Tiên Cô Thiên Sứ - Tiểu Long Nữ để đổi các phần thưởng quý giá !");
//	CHAT_D->sys_channel(0,HIC"Nghe nói Ác Quỷ Vương đã xuất hiện ở ngoài thành Chu Quốc, nếu như bắt được đám Ác Quỷ này thì có thể đến nơi Tiên Cô Thiên Sứ - Tiểu Long Nữ để đổi các phần thưởng quý giá !");
}

void check_time2()
{
	int i,size;
	
	for(i=0,size=sizeof(Scum);i<size;i++)
	{
		if ( !objectp(Scum[i])	)
			continue;

			Scum[i]->remove_from_scene();
			destruct(Scum[i]);
	}
	Scum -= ({ 0 });		
}