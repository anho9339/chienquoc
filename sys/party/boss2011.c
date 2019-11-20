/*******************************
	**Ben**
*******************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

void generate_scum();
void destroy_scum();
object *Scum; 
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
    if ( mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 2 || mixTime[TIME_WDAY] == 4 || mixTime[TIME_WDAY] == 6 ) // t2, t3, t5, t7 ko có boss
	{
	//	destroy_scum();
		call_out("check_time",3600*24);
		return ;
	}
	else
	{ 
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 0 ) // Gọi ra vào giờ lẻ
		{
			call_out("check_time",i);
		}
		else
		{
		//  1h, 11h và 19h sẽ ra boss
			if ( mixTime[TIME_HOUR] == 3 || mixTime[TIME_HOUR] == 5 || mixTime[TIME_HOUR] == 7 || mixTime[TIME_HOUR] == 9 || mixTime[TIME_HOUR] == 13
			|| mixTime[TIME_HOUR] == 15 || mixTime[TIME_HOUR] == 17 || mixTime[TIME_HOUR] == 21 || mixTime[TIME_HOUR] == 23 )
			// Những giờ này ko cho ra boss
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
		if( !( p = efun::get_xy_point( 503, IS_CHAR_BLOCK ) ) )
			continue;
		x = ( p % 1000000 ) / 1000;  y = p % 1000;
		npc = new("/npc/boss/bosspro/tretrau");// Trẻ trâu
		npc->add_to_scene(503,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<1;i++)
	{
		if( !( p = efun::get_xy_point( 171, IS_CHAR_BLOCK ) ) )
			continue;
		x = ( p % 1000000 ) / 1000;  y = p % 1000;
		npc = new("/npc/boss/bosspro/soivosu");// Sói võ sư
		npc->add_to_scene(171,x,y);	
		Scum += ({ npc });
	}
	// CHAT_D->rumor_channel(0,sprintf(HIY"Bọn Boss 20/11 đã bắt đầu xuất hiện tại Bành Thành và Trường Sơn Bạch. Hãy mau đi tiêu diệt chúng!!!";
}

//  移除武林败类NPC
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

