/********************************************************************************************************************************
		    -----------------------Thien Son Tuong Quan --------------------
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

#define ThienSon 			"npc/boss/bossthienson/thienson"

int BatDau,KetThuc;
void generate_scum();
void destroy_scum();
string *schoolname = ({"Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
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
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time");
	iTime = time();
	
	mixTime = localtime(iTime);

	/*if ( mixTime[TIME_WDAY] == 1 
	|| mixTime[TIME_WDAY] == 2
	|| mixTime[TIME_WDAY] == 3
	|| mixTime[TIME_WDAY] == 4
	|| mixTime[TIME_WDAY] == 5 )
	{
		call_out("check_time",3600*24);
		return ;
	}
	else*/
	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 0 )
		{
			call_out("check_time",i);
		}
		else
		{  // 17h và 19h xuất boss
			if ( mixTime[TIME_HOUR] == 1 || mixTime[TIME_HOUR] == 3 || mixTime[TIME_HOUR] == 5 || mixTime[TIME_HOUR] == 7 || mixTime[TIME_HOUR] == 9 || mixTime[TIME_HOUR] == 11 
			|| mixTime[TIME_HOUR] == 13 || mixTime[TIME_HOUR] == 15  || mixTime[TIME_HOUR] == 21 || mixTime[TIME_HOUR] == 23 )
				call_out("check_time",i+3600);
			else
			{
				generate_scum();
				call_out("check_time",i+3600);
			}
		}
	}

}
//  放入武林败类NPC
void generate_scum()
{
	int i,size,z,p,x,y,j;
	object npc;
	
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 323, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThienSon);
		npc->add_to_scene(323,x,y);	
		Scum += ({ npc });
	}
	call_out("check_time2",18000);
	CHAT_D->sys_channel(0,ECHO"Nghe nói Thiên Sơn Đại Tướng Quân lên cơn say muốn khiêu chiến các vị anh hùng Chiến Quốc Tâm Diện hắn xuất hiện ở Loan Đạo 3, hãy mau thu phục hắn!");
	CHAT_D->sys_channel(0,ECHO"Nghe nói Thiên Sơn Đại Tướng Quân lên cơn say muốn khiêu chiến các vị anh hùng Chiến Quốc Tâm Diện hắn xuất hiện ở Loan Đạo 3, hãy mau thu phục hắn!");
//	CHAT_D->sys_channel(0,ECHO"Kinh Kha đã xuất hiện tại Loan Đạo 3 !");
//	CHAT_D->sys_channel(0,ECHO"Kinh Kha đã xuất hiện tại Loan Đạo 3 !");
//	CHAT_D->sys_channel(0,ECHO"Kinh Kha đã xuất hiện tại Loan Đạo 3 !");
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