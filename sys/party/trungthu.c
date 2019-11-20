/*******************************
	**Trung Thu Pret Kuzl**
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

#define ThoCon 			"npc/event/trungthu/quaivattho"

int iStart,iFinish;
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

/* void check_time()
{
    int iHour;
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time");
	iTime = time();
	iHour = time();
	if ( iHour > iFinish )
		return ;
	if ( iHour < iStart )	//没到时间
	{
		call_out("check_time",iStart - iHour);
		return ;
	}
	call_out("check_time",10800);//3h
//	mixTime = localtime(iTime);

/*/ //	if ( mixTime[TIME_WDAY] == 5 || mixTime[TIME_WDAY] == 6 )
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
/*	{
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 0 )
		{
			call_out("check_time",i);
		}
		else
		{
			if ( mixTime[TIME_HOUR] == 3 || mixTime[TIME_HOUR] == 5 || mixTime[TIME_HOUR] == 7 )
				call_out("check_time",i+3600);
			else
			{
				generate_scum();
				call_out("check_time",i+3600);
			}
		}
	}

} */  

void check_time()
{
	int iHour;
	mixed *mixTime;

	remove_call_out("check_time");
	/*if (MAIN_D->get_host_type()==2)		//台湾除外
		return ; */
	iHour = time();
	if ( iHour > iFinish )
		return ;
	if ( iHour < iStart )	//没到时间
	{
		call_out("check_time",iStart - iHour);
		return ;
	}
	call_out("check_time",10);//2h30
//	generate_money();
//	generate_box();
//	generate_gift();
}

void generate_scum()
{
	int i,size,z,p,x,y,j;
	object npc; 
	for(i=0;i<5;i++) // Kênh Trịnh Quốc 2
	{
		if( !( p = efun::get_xy_point( 152, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(152,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5;i++)  // Địa ngục ma quật tầng 1
	{
		if( !( p = efun::get_xy_point( 533, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(533,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5;i++) // Cự thú đảo
	{
		if( !( p = efun::get_xy_point( 549, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(549,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<5;i++) //Thiên ngoại ảo cảnh tầng 1
	{
		if( !( p = efun::get_xy_point( 541, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(541,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++) //Thủ Dương Sơn
	{
		if( !( p = efun::get_xy_point( 081, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(081,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++) // Tương Lăng
	{
		if( !( p = efun::get_xy_point( 021, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(021,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++) // Thái Hành sơn
	{
		if( !( p = efun::get_xy_point( 132, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(132,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<6;i++) // Chân Núi Thái Sơn
	{
		if( !( p = efun::get_xy_point( 112, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(ThoCon);
		npc->add_to_scene(112,x,y);	
		Scum += ({ npc });
	}
	call_out("check_time2",7200); // 2 tiếng tự biến mất
	
	CHAT_D->sys_channel(0,HIC "Bọn Thỏ Con đang ăn cắp bánh trung thu tại "HIY "Kênh Trịnh Quốc, Địa Ngục Ma Quật, Cự Thú Đảo, Thiên Ngoại Ảo Cảnh, Thủ Dương Son,...."HIC" . Mong các anh hùng mau đến tương trợ!");
	CHAT_D->sys_channel(0,HIC "Bọn Thỏ Con đang ăn cắp bánh trung thu tại "HIY "Kênh Trịnh Quốc, Địa Ngục Ma Quật, Cự Thú Đảo, Thiên Ngoại Ảo Cảnh, Thủ Dương Son,...."HIC" . Mong các anh hùng mau đến tương trợ!");
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
