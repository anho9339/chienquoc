/*******************************
	**CQ Pro - Pretkuzl Truy lùng Bảo Thạch Tiểu Yêu event**
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
int *nScene = ({80,10,20,30,40,50,60,70});
string *nCountry = ({"Chu Quốc","Tề Quốc","Hàn Quốc","Triệu Quốc","Ngụy Quốc","Tần Quốc","Sở Quốc","Yên Quốc",});
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

		i = 60*(60-mixTime[TIME_MIN]);
		
		call_out("check_time",i);
	/*	if ( mixTime[TIME_HOUR]%2 == 0 ) // Giờ lẻ
		{
			call_out("check_time",i);
		}
		else
		{ */
		// Giờ xuất hiện event 1,9,11,15,17,19,20,21,23
			if ( mixTime[TIME_HOUR] == 1 || mixTime[TIME_HOUR] == 9 || mixTime[TIME_HOUR] == 11 || mixTime[TIME_HOUR] == 15 || mixTime[TIME_HOUR] == 17 || mixTime[TIME_HOUR] == 19 
			 || mixTime[TIME_HOUR] == 20 || mixTime[TIME_HOUR] == 21 || mixTime[TIME_HOUR] == 23 ) 
			 {
				generate_scum();
				call_out("check_time",i+3600);
			 }
			else
			{
				call_out("check_time",i+3600);
			}
}


//  放入武林败类NPC
void generate_scum()
{
	int i,size,z,p,x,y,j;
	object npc;

	j = random(8);
	z = nScene[j];
	for(i=0;i<=10+random(5);i++)
	{
		if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new("/npc/event/thachtieuyeu");
		npc->add_to_scene(z,x,y);	
		Scum += ({ npc });
	}
	call_out("check_time2",900); // Sau 15 phút
	
	CHAT_D->sys_channel(0,HIR "Bảo Thạch Tiểu Yêu đã xuất hiện Ngẫu Nhiên ở "HIY "Thất Quốc"HIC" các vị anh hùng hãy nhanh tay đi giết chúng để lấy Mảnh Ghép Đoạn Thạch chúng mang trên người nào.");
	CHAT_D->sys_channel(0,HIC "Bảo Thạch Tiểu Yêu đã xuất hiện Ngẫu Nhiên ở "HIY "Thất Quốc"HIC" các vị anh hùng hãy nhanh tay đi giết chúng để lấy Mảnh Ghép Đoạn Thạch chúng mang trên người nào.");
}

//  移除武林败类NPC
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
	CHAT_D->sys_channel(0,HIB"Bọn Bảo Thạch Tiểu Yêu đã lặng lẽ biến mất, bên ngoài thành lại yên bình trở lại!!!");
}


