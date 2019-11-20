/********************************************************************************************************************************
-----------------------Cứu Nhân Độ Thế --------------------
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

#define DanChung 			"npc/event/danchung"

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
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time");
	iTime = time();
	
	mixTime = localtime(iTime);
	// T2, t4, t6, Cn có
	if ( mixTime[TIME_WDAY] == 2 || mixTime[TIME_WDAY] == 4 || mixTime[TIME_WDAY] == 6 )  // Thứ 3, thứ 5, thứ 7 ko có 
	{
	//	destroy_scum();
		call_out("check_time",3600*24);
		return ;
	}
	else
	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 1 )  // == 0 là giờ lẽ, == 1 là giờ chẵn
		{
			call_out("check_time",i);
		}
		else
		{
			if ( mixTime[TIME_HOUR] == 0 || mixTime[TIME_HOUR] == 22 ) // Ra vào những giờ chẵn 2,4,6,8 ,... Lúc 12h -> 22h là kết thúc xong lặp lại
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
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 062, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(062,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 321, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(321,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 173, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(173,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 032, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(032,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 011, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(011,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 081, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(081,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 072, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(072,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 052, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DanChung);
		npc->add_to_scene(052,x,y);	
		Scum += ({ npc });
	}
	call_out("check_time2",5400); // 1 tiếng 30' biến mất
//	call_out("check_time2",14400);
	
	CHAT_D->sys_channel(0,HIR"Nghe nói ngoài thành các nước xuất hiện rất nhiều dân bị nạn, các vị bằng hữu hãy giúp đỡ họ vượt qua cơn hiểm nghèo !");
	CHAT_D->sys_channel(0,HIR"Nghe nói ngoài thành các nước xuất hiện rất nhiều dân bị nạn, các vị bằng hữu hãy giúp đỡ họ vượt qua cơn hiểm nghèo !");
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