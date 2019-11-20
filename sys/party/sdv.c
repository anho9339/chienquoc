

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define SDV 			"npc/boss/0021"

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
	if ( mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 2 || mixTime[TIME_WDAY] == 3 
	|| mixTime[TIME_WDAY] == 4 ) // Thứ 2, thứ 3, thứ 4, thứ 5 ko có SDV
	{
	//	destroy_scum();
		call_out("check_time",3600*24);
		return ;
	}
/*	else if ( mixTime[TIME_HOUR] < 5 || mixTime[TIME_HOUR] > 23 )
	{
		destroy_scum();
		call_out("check_time",3600*24);
		return ;
	}
	else*/
	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 1 ) // Giờ chẵn
		{
			call_out("check_time",i);
		}
		else
		{ // 10h và 20h có boss
			if ( mixTime[TIME_HOUR] == 0 || mixTime[TIME_HOUR] == 2 || mixTime[TIME_HOUR] == 4 || mixTime[TIME_HOUR] == 6 || mixTime[TIME_HOUR] == 8
			|| mixTime[TIME_HOUR] == 12 || mixTime[TIME_HOUR] == 14 || mixTime[TIME_HOUR] == 16 || mixTime[TIME_HOUR] == 18 || mixTime[TIME_HOUR] == 22)
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
	destroy_scum();
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 151, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(SDV);
		npc->add_to_scene(151,x,y);	 // Kênh trịnh quốc 1
		Scum += ({ npc });
	}	
}

void destroy_scum()
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