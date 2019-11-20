/*******************************
	**门派偷袭战**
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
int *nScene = ({289,273,80,324,269,54,165});
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

/*//	if ( mixTime[TIME_WDAY] == 5 || mixTime[TIME_WDAY] == 6 )
//	{
//		destroy_scum();
//		call_out("check_time",3600*24);
//		return ;
//	}
//	else if ( mixTime[TIME_WDAY] == 0 )
//	{
//		call_out("check_time",3600*24-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
//		return ;
//	}
//	else*/
	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 1 )
		{
			call_out("check_time",i);
		}
		else
		{
			if ( mixTime[TIME_HOUR] == 2 || mixTime[TIME_HOUR] == 4 ||
			mixTime[TIME_HOUR] == 6 || mixTime[TIME_HOUR] == 8 || mixTime[TIME_HOUR] == 10 || 
			mixTime[TIME_HOUR] == 12 || mixTime[TIME_HOUR] == 14 )
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

	j = random(7);
	z = nScene[j];
//	for(i=0;i<=1;i++)
//	{
//		if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
//			continue;
//		x = p / 1000;
//		y = p % 1000;
		npc = new("/npc/event/KinhKha2");
		npc->add_to_scene(071,72,79);	
		Scum += ({ npc });
//	}

	CHAT_D->sys_channel(0,HIC "Tuyệt đại Cao Thủ "HIG"Song Nhi"HIC" đã xuất hiện tại "HIY "Yên Trường Thành 1 "HIC"(72,79).");
}

//  移除武林败类NPC
void destroy_scum()
{
	int i,size;
	for(i=0,size=sizeof(Scum);i<size;i++)
	{
		if ( !objectp(Scum[i])	)
			continue;
		if (!Scum[i]->get("busy"))
		{
			Scum[i]->remove_from_scene();
			destruct(Scum[i]);
		}
		else
			Scum[i]->set("overdue",1);
	}
	Scum -= ({ 0 });
}

