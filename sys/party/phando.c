/************************************************************************************
			-----------------------Cấm Vệ Quân Phản Đồ--------------------
*************************************************************************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define PhanDo 			"npc/event/phando"

void generate_scum();
void destroy_scum();
int *nScene = ({010,020,030,040,050,060,070});
string *schoolname = ({"Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
string *cityname = ({"Tề Quốc", "Hàn Quốc", "Triệu Quốc", "Ngụy Quốc", "Tần Quốc", "Sở Quốc", "Yên Quốc", });
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
/*	if ( mixTime[TIME_WDAY] == 0 )
	{
		destroy_scum();
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
		if ( mixTime[TIME_HOUR]%2 == 1 )
		{
			call_out("check_time",i);
		}
		else
		{ // Vào lúc 6h 8h 10h 12h 14h 
			if ( mixTime[TIME_HOUR] == 0 || mixTime[TIME_HOUR] == 2 || mixTime[TIME_HOUR] == 4 || 
			mixTime[TIME_HOUR] == 16 || mixTime[TIME_HOUR] == 18 || mixTime[TIME_HOUR] == 20 || mixTime[TIME_HOUR] == 22 )
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

	j = random(7);
	z = nScene[j];
	for(i=0;i<=9;i++)
	{
		if( !( p = efun::get_xy_point( 381, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhanDo);
		npc->add_to_scene(381,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",3300);
	
	CHAT_D->sys_channel(0,HIY"Nghe nói có một đám Phản đồ của Cấm Vệ Quân đang tụ tập bầy mưu tính kế tại Hư Lăng Động!");
	CHAT_D->sys_channel(0,HIY"Nghe nói có một đám Phản đồ của Cấm Vệ Quân đang tụ tập bầy mưu tính kế tại Hư Lăng Động!");
}
//Sau 55 phút từ khi Phản Đồ xuất hiện, Phản Đồ sẽ tự động biến mất 
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
//	CHAT_D->sys_channel(0,HIY"Phản đồ của Cấm Vệ Quân hét lớn : \"Lần sau các ngươi sẽ biết tay ta\" rồi bỏ chạy !");																
}