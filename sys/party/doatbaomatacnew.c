/********************************************************************************************************************************
-----------------------Đoạt Bảo Mã Tặc --------------------
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

#define DoatBaoMaTac 			"npc/event/dbmtnpc"

void generate_scum();
void generate_scum1();
void generate_scum2();
void generate_scum3();
void generate_scum4();
void generate_scum5();
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
/*	if ( mixTime[TIME_WDAY] == 0 || mixTime[TIME_WDAY] == 1 || mixTime[TIME_WDAY] == 3 || mixTime[TIME_WDAY] == 5 )
	{
	//	destroy_scum();
		call_out("check_time",3600*24);
		return ;
	} 
	else
	{ */
		i = 60*(60-mixTime[TIME_MIN]);
		if ( mixTime[TIME_HOUR]%2 == 1 ) 
		{
			call_out("check_time",i);
		}
		else
		{
			if ( mixTime[TIME_HOUR] == 2 || mixTime[TIME_HOUR] == 4 || mixTime[TIME_HOUR] == 6
			|| (mixTime[TIME_HOUR] == 8 && mixTime[TIME_MIN] > 30)
			|| (mixTime[TIME_HOUR] == 10 && mixTime[TIME_MIN] > 30) 
			|| (mixTime[TIME_HOUR] == 12 && mixTime[TIME_MIN] > 30) 
			|| (mixTime[TIME_HOUR] == 14 && mixTime[TIME_MIN] > 30) 
			|| (mixTime[TIME_HOUR] == 16 && mixTime[TIME_MIN] > 30) 
			|| (mixTime[TIME_HOUR] == 18 && mixTime[TIME_MIN] > 30) 
			|| (mixTime[TIME_HOUR] == 20 && mixTime[TIME_MIN] > 30) 
			|| (mixTime[TIME_HOUR] == 22 && mixTime[TIME_MIN] > 30) )
				call_out("check_time",i+3600);
			else
			{
				if ( random(10) < 3 ) generate_scum();
				else if ( random(10) < 4 ) generate_scum1();
				else if ( random(10) < 5 ) generate_scum2();
				else if ( random(10) < 6 ) generate_scum3();
				else if ( random(10) < 8 ) generate_scum4();
				else generate_scum5();
				call_out("check_time",i+3600);
			}
		}
	

}
//  Random 1
void generate_scum()
{
	int i,size,z,p,x,y,j;
	int cap;
	object npc;
	cap = ({60,70,80,90,100})[random(5)];
	 
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 041, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(041,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 042, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(042,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 043, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(043,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",1800);
	
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Vô Định Hà, Vô Định Hà 1, Vô Định Hà 2 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Vô Định Hà, Vô Định Hà 1, Vô Định Hà 2 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Vô Định Hà, Vô Định Hà 1, Vô Định Hà 2 !");
}
//  Random 2
void generate_scum1()
{
	int i,size,z,p,x,y,j;
	int cap;
	object npc;
	cap = ({60,70,80,90,100})[random(5)];
	 
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 151, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(151,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 152, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(152,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 153, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(153,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",1800);
	
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Kênh Trịnh Quốc 1, Kênh Trịnh Quốc 2, Kênh Trịnh Quốc 3 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Kênh Trịnh Quốc 1, Kênh Trịnh Quốc 2, Kênh Trịnh Quốc 3 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Kênh Trịnh Quốc 1, Kênh Trịnh Quốc 2, Kênh Trịnh Quốc 3 !");
}
//  Random 3
void generate_scum2()
{
	int i,size,z,p,x,y,j;
	int cap;
	object npc;
	cap = ({60,70,80,90,100})[random(5)];
	 
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 012, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(012,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 013, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(013,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 014, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(014,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",1800);
	
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Đông Hải, Hải Tân 1, Hải Tân 2 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Đông Hải, Hải Tân 1, Hải Tân 2 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Đông Hải, Hải Tân 1, Hải Tân 2 !");
}
//  Random 4
void generate_scum3()
{
	int i,size,z,p,x,y,j;
	int cap;
	object npc;
	cap = ({60,70,80,90,100})[random(5)];
	 
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 163, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(163,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 164, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(164,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 261, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(261,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",1800);
	
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Ranh Giới Đầm Lầy, Địa Giới Đầm Lầy, Chân Núi Đại Biệt !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Ranh Giới Đầm Lầy, Địa Giới Đầm Lầy, Chân Núi Đại Biệt !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Ranh Giới Đầm Lầy, Địa Giới Đầm Lầy, Chân Núi Đại Biệt !");
}
//  Random 5
void generate_scum4()
{
	int i,size,z,p,x,y,j;
	int cap;
	object npc;
	cap = ({60,70,80,90,100})[random(5)];
	 
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 141, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(141,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 142, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(142,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 211, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(211,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",1800);
	
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Mã Lăng Đạo, Bạch Mã Trang, Mã Đạp Hồ !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Mã Lăng Đạo, Bạch Mã Trang, Mã Đạp Hồ !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Mã Lăng Đạo, Bạch Mã Trang, Mã Đạp Hồ !");
}
//  Random 6
void generate_scum5()
{
	int i,size,z,p,x,y,j;
	int cap;
	object npc;
	cap = ({60,70,80,90,100})[random(5)];

	 
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 061, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(061,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 062, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(062,x,y);	
		Scum += ({ npc });
	}
	for(i=0;i<10;i++)
	{
		if( !( p = efun::get_xy_point( 063, IS_CHAR_BLOCK ) ) )
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->set_level(cap);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, cap);
		npc->add_max_hp(npc->get_max_hp()*50);
		npc->add_dp(npc->get_dp()/2);
		npc->add_ap(npc->get_ap()*13/10);
		npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
		npc->add_to_scene(063,x,y);	
		Scum += ({ npc });
	}
	
	call_out("check_time2",1800);
	
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Sở Phương Thành 1, Sở Phương Thành 2, Sở Phương Thành 3 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Sở Phương Thành 1, Sở Phương Thành 2, Sở Phương Thành 3 !");
	CHAT_D->sys_channel(0,"Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Sở Phương Thành 1, Sở Phương Thành 2, Sở Phương Thành 3 !");
}
//Sau 30 phút từ khi Đoạt Bảo xuất hiện sẽ biến mất 
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

void win_bonus_callout( object me, object who )
{
        object owner, *team;
        int level, level2, exp, exp2, pot, alllevel;
        int i, size, status, time, flag, z, x, y, p;
	
        if( !objectp( who = me->get_enemy_4() ) ) return;

        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;
	if(who->get_group_id()) return;

	CHAT_D->sys_channel(0, "Nghe nói tên Đoạt Bảo Mã Tặc hung hãn đã bị bằng hữu "+who->get_name()+" tiêu diệt" ); 
	/*who->delete_save_2("doatbaomatac");
	z = who->get_2("doatbaomatac.z");
	x = who->get_2("doatbaomatac.x");
	y = who->get_2("doatbaomatac.y");	
	if( !( p = get_valid_xy( z, x, y, IS_CHAR_BLOCK ) ) ) return ;
	x = p / 1000;  y = p % 1000;
	who->add_to_scene(z, x, y, 3);  */	
	
        level = me->get_level();
        if( who->get_leader() && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
        {
                team = me->correct_bonus_team(team);
                size = sizeof(team);
        }
        else
        {
        	team = ({who});
            	size = 1;
        }

        alllevel = 0;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
        	alllevel += team[i]->get_level();
        }
	if (alllevel==0) alllevel = 1;        	        		
	exp = level*300;
	pot = level*10;
        for( i = 0; i < size; i ++ ) if( team[i] )
        {
                level2 = level - team[i]->get_level();
                exp2 = exp * team[i]->get_level()/alllevel;                        
                exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;  

                if (exp2<5) exp2 = 5;
                exp2 = exp2 * team[i]->get_online_rate()/100;
                pot = pot * team[i]->get_online_rate()/100;
                team[i]->add_exp(exp2);
                team[i]->add_potential(pot);
				team[i]->add_cash(level*200);
				"sys/sys/test_db"->add_yuanbao(team[i],level*10/size);
				write_user(team[i], sprintf(ECHO "Bạn tiêu diệt Đoạt Bảo Mã Tặc và nhận được %d Kim Bảo !",(level*10/size)/10));
	}
}