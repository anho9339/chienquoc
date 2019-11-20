/*******************************
	**30-4 , 1-5 Pret kuzl **
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

/*	if ( mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 2  || mixTime[TIME_WDAY] == 3 || mixTime[TIME_WDAY] == 4) // 2 3 4 5 không có Tử Tù
	{
	//	destroy_scum();
		call_out("check_time",3600*24);
		return ;
	}
	else
	{ */
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 0 ) // Giờ lẻ
		{
			call_out("check_time",i);
		}
		else
		{
		// 1,3,5,13h ko có event
			if ( mixTime[TIME_HOUR] == 1 || mixTime[TIME_HOUR] == 3 || mixTime[TIME_HOUR] == 5 || mixTime[TIME_HOUR] == 13 )
				call_out("check_time",i+3600);
			else
			{
				generate_scum();
				call_out("check_time",i+3600);
			}
		}
	}


//  放入武林败类NPC
void generate_scum()
{
	int i,size,z,p,x,y,j,count,*nPlace=({80,10,20,30,40,50,60,70});
	object npc;
	
	for(j=0,count=sizeof(nPlace);j<count;j++)
	{
		z = nPlace[j];
		for(i=0;i<80;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  
			y = p % 1000;
			npc = new("/npc/event/304/trebo");
			npc->add_to_scene(z,x,y);	
			Scum += ({ npc });	
		}
	}
	call_out("check_time2",1800); // Sau 30 phút
	
	CHAT_D->sys_channel(0,HIB "Bọn Trẻ Trâu đã xuất hiện ở "HIY "Thất Quốc"HIC" các vị anh hùng hãy nhanh tay đi tìm và tiêu diệt chúng đi nào.");
	CHAT_D->sys_channel(0,HIC "Bọn Trẻ Trâu đã xuất hiện ở "HIY "Thất Quốc"HIC" các vị anh hùng hãy nhanh tay đi tìm và tiêu diệt chúng đi nào.");
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
	CHAT_D->sys_channel(0,HIB"Bọn Trẻ Bò đã hết dám lộng hành, cảm ơn chư vị huynh đệ đã tương trợ");
}


