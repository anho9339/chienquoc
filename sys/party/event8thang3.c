/********************************************************************************************************************************
-----------------------Mother Day 8/3 
Pret Kuzl --------------------
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

#define Mother 			"npc/event/83/mother"

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
	if ( mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 2 || mixTime[TIME_WDAY] == 3 )  // Thứ 2 thứ 3 thứ 4 không có
	{
	//	destroy_scum();
		call_out("check_time",3600*24);
		return ;
	}
	else
	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 0 )  // == 0 là giờ lẽ, == 1 là giờ chẵn
		{
			call_out("check_time",i);
		}
		else
		{
			if ( mixTime[TIME_HOUR] == 1 || mixTime[TIME_HOUR] == 23 ) // Ra vào những giờ lẻ 1,3,5,7 ,... Lúc 12h -> 23h là kết thúc xong lặp lại
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
	for(i=0;i<5+random(2);i++)
	{
		if( !( p = efun::get_xy_point( 10, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(10,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5+random(2);i++)
	{
		if( !( p = efun::get_xy_point( 20, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(20,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5+random(2);i++)
	{
		if( !( p = efun::get_xy_point( 30, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(30,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5+random(2);i++)
	{
		if( !( p = efun::get_xy_point( 40, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(40,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5+random(2);i++)
	{
		if( !( p = efun::get_xy_point( 50, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(50,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++)
	{
		if( !( p = efun::get_xy_point( 60, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(60,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5+random(2);i++)
	{
		if( !( p = efun::get_xy_point( 70, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(70,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5+random(2);i++)
	{
		if( !( p = efun::get_xy_point( 80, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(Mother);
		npc->add_to_scene(80,x,y);	
		Scum += ({ npc });
	}
	call_out("check_time2",1800); // 30 phút biến mất
//	call_out("check_time2",14400);
	
	CHAT_D->sys_channel(0,HIY"Nghe nói ngoài thành các nước xuất hiện rất nhiều bà mẹ đang chờ con, hãy tới xem các mẹ đang cần gì nào, nhanh nhé vì mấy bả chỉ chờ được 30 phút thôi!");
	CHAT_D->sys_channel(0,HIR"Nghe nói ngoài thành các nước xuất hiện rất nhiều bà mẹ đang chờ con, hãy tới xem các mẹ đang cần gì nào, nhanh nhé vì mấy bả chỉ chờ được 30 phút thôi!");
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