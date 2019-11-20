/********************************************************************************************************************************
		    -----------------------Dị Long--------------------
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

#define DILONG 			"npc/bossnew/dilong"

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
    // Xuất hiện t6,t7,CN
	if ( mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 2|| mixTime[TIME_WDAY] == 3|| mixTime[TIME_WDAY] == 4 )
	{
		call_out("check_time",3600*24);
		return ;
	}
	else
	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 0 ) // Giờ lẻ
		{
			call_out("check_time",i);
		}
		else
		{
		// 13 giờ và 23 giờ tối
			if ( mixTime[TIME_HOUR] == 1 || mixTime[TIME_HOUR] == 3 || mixTime[TIME_HOUR] == 5 || mixTime[TIME_HOUR] == 7  || mixTime[TIME_HOUR] == 9 
			|| mixTime[TIME_HOUR] == 11 || mixTime[TIME_HOUR] == 15 || mixTime[TIME_HOUR] == 17 || mixTime[TIME_HOUR] == 19 || mixTime[TIME_HOUR] == 21)
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
		if( !( p = efun::get_xy_point( 71, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DILONG);
		npc->add_to_scene(71,x,y);	
		Scum += ({ npc });
	}
	call_out("check_time2",10800); // Sau 2 tiếng biến mất
//	CHAT_D->sys_channel(0,ECHO"Sát Thần đã xuất hiện tại Bành Thành !");
//	CHAT_D->sys_channel(0,ECHO"Sát Thần đã xuất hiện tại Bành Thành !");
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