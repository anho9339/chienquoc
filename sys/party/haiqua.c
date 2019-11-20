

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define CayNayMam 			"npc/event/haiqua0"
#define CayNayMam2 			"npc/event/haiqua1"
#define CayThuong 			"npc/event/haiqua"
#define CayHoangKim 		"npc/event/haiqua_2"

void generate_scum();
void destroy_scum();
object *Scum,*Scum2;

// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
//	restore();
	Scum = ({});
	Scum2 = ({});
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
/*	if ( mixTime[TIME_WDAY] == 5 || mixTime[TIME_WDAY] == 6 || mixTime[TIME_WDAY] == 0 )
	{
	//	destroy_scum();
		call_out("check_time",3600*24);
		return ;
	}
	else if ( mixTime[TIME_HOUR] < 5 || mixTime[TIME_HOUR] > 23 )
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
		{
			if ( mixTime[TIME_HOUR] == 2 ||
			(mixTime[TIME_HOUR] == 4 && mixTime[TIME_MIN] > 5) || 	
			mixTime[TIME_HOUR] == 6 || 
			(mixTime[TIME_HOUR] == 8 && mixTime[TIME_MIN] > 5) ||
			mixTime[TIME_HOUR] == 10 || 
			(mixTime[TIME_HOUR] == 12 && mixTime[TIME_MIN] > 5) ||
			mixTime[TIME_HOUR] == 14 || 
			(mixTime[TIME_HOUR] == 16 && mixTime[TIME_MIN] > 5) ||
			mixTime[TIME_HOUR] == 18 || 
			(mixTime[TIME_HOUR] == 20 && mixTime[TIME_MIN] > 5) ||
			mixTime[TIME_HOUR] == 22 ||
			(mixTime[TIME_HOUR] == 0 && mixTime[TIME_MIN] > 5) )
			// Xuất hiện vào lúc 0h -> 24h 4 tiếng / 1 lần
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
	// cây thường
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam);
		npc->add_to_scene(042,384,163);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam);
		npc->add_to_scene(042,382,163);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam);
		npc->add_to_scene(042,380,163);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam);
		npc->add_to_scene(042,378,163);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam);
		npc->add_to_scene(042,375,163);	
		Scum += ({ npc });
	}
	// cây hoàng kim
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam2);
		npc->add_to_scene(042,375,156);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam2);
		npc->add_to_scene(042,384,156);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam2);
		npc->add_to_scene(042,378,154);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam2);
		npc->add_to_scene(042,382,157);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayNayMam2);
		npc->add_to_scene(042,382,153);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",300);
	
	CHAT_D->sys_channel(0,HIY"Nghe nói tại Vô Định Hà 1 ( 384, 163 ) đã mọc lên rất nhiều cây vừa nảy mầm!");
	CHAT_D->sys_channel(0,HIY"Nghe nói tại Vô Định Hà 1 ( 384, 163 ) đã mọc lên rất nhiều cây vừa nảy mầm!");
	CHAT_D->sys_channel(0,HIY"Nghe nói tại Vô Định Hà 1 ( 384, 163 ) đã mọc lên rất nhiều cây vừa nảy mầm!");
}
//Sau 5 phút từ khi Cây nảy nầm xuất hiện 
void check_time2()
{
	int i,size,z,p,x,y,j;
	object npc;
	
	for(i=0,size=sizeof(Scum);i<size;i++)
	{
		if ( !objectp(Scum[i])	)
			continue;

			Scum[i]->remove_from_scene();
			destruct(Scum[i]);
	}
	Scum -= ({ 0 });
	// cây thường
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayThuong);
		npc->add_to_scene(042,384,163);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayThuong);
		npc->add_to_scene(042,382,163);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayThuong);
		npc->add_to_scene(042,380,163);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayThuong);
		npc->add_to_scene(042,378,163);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayThuong);
		npc->add_to_scene(042,375,163);	
		Scum2 += ({ npc });
	}
	// cây hoàng kim
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayHoangKim);
		npc->add_to_scene(042,375,156);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayHoangKim);
		npc->add_to_scene(042,384,156);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayHoangKim);
		npc->add_to_scene(042,378,154);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayHoangKim);
		npc->add_to_scene(042,382,157);	
		Scum2 += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CayHoangKim);
		npc->add_to_scene(042,382,153);	
		Scum2 += ({ npc });
	}
	
	call_out("check_time3",120);
	CHAT_D->sys_channel(0,HIY"Cây đã đâm hoa kết trái và đã đến lúc hái quả, thời gian hái quả là 2 phút, các vị bằng hữu hãy nhanh tay hái quả !");				
	CHAT_D->sys_channel(0,HIY"Cây đã đâm hoa kết trái và đã đến lúc hái quả, thời gian hái quả là 2 phút, các vị bằng hữu hãy nhanh tay hái quả !");				
	CHAT_D->sys_channel(0,HIY"Cây đã đâm hoa kết trái và đã đến lúc hái quả, thời gian hái quả là 2 phút, các vị bằng hữu hãy nhanh tay hái quả !");				
}
//Sau 2 phút từ khi Cây thường và Cây hoàng kim xuất hiện 
void check_time3()
{
	int i,size,z,p,x,y,j;
	object npc;
	
	for(i=0,size=sizeof(Scum2);i<size;i++)
	{
		if ( !objectp(Scum2[i])	)
			continue;

			Scum2[i]->remove_from_scene();
			destruct(Scum2[i]);
	}
	Scum2 -= ({ 0 });				
}