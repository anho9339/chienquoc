/********************************************************************************************************************************
		    -----------------------Chợ đen by Pret--------------------
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

#define CHODENNPC 			"npc/npcpro/choden"

int BatDau,KetThuc;
void generate_scum();
void destroy_scum();
string *schoolname = ({"Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
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
    // Xuất hiện t7,CN
	if ( mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 2|| mixTime[TIME_WDAY] == 3|| mixTime[TIME_WDAY] == 4 || mixTime[TIME_WDAY] == 5 )
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
		// 9 giờ và 19 giờ tối
			if ( mixTime[TIME_HOUR] == 1 || mixTime[TIME_HOUR] == 3 || mixTime[TIME_HOUR] == 5 || mixTime[TIME_HOUR] == 7 || mixTime[TIME_HOUR] == 11 
			|| mixTime[TIME_HOUR] == 13 || mixTime[TIME_HOUR] == 15 || mixTime[TIME_HOUR] == 17 || mixTime[TIME_HOUR] == 21 || mixTime[TIME_HOUR] == 23)
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
		if( !( p = efun::get_xy_point(80, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(CHODENNPC);
		npc->add_to_scene(80,290,129);	
		Scum += ({ npc });
	}
	call_out("check_time2",900); // Biến mất sau 15 phút
	CHAT_D->sys_channel( 0, HIG" Nghe nói ở Chu Quốc (290,129) xuất hiện Thương Nhân Chợ Đen có đủ thứ loại mặt hàng quý giá trên đời. Mau mau tới xem thử vì hắn chỉ nán lại 15 phút thôi!" ); 
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