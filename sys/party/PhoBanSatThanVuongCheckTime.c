/*******************************
	**古墓探险**
*******************************/

#include <time.h>
#include <ansi.h>

inherit DBASE_F;
inherit SAVE_F;	

#define FILE_NPC "npc/event/BaVuongXaPhu"
#define PLAYER_EXIT "sys/party/PhoBanSatThanVuong"
#define FILE_SAVE "data/party"SAVE_EXTENSION
#define DEBUG(arg) if(find_char("9")) tell_user(find_char("9"),arg);
	

int gumu=0;
int gumu_party=1;


// 函数：生成二进制码
void SAVE_BINARY() { }

//活动开启状态保存
string get_save_file()	
{
	 return FILE_SAVE;
}
void create()
{
	restore();
	gumu=0;
	call_out("check_time",3);
}

void check_time()
{
	int iTime,i; 
	mixed *mixTime;
	
	remove_call_out("check_time");
	iTime = get_party_time();
	if(!gumu_party) return;
	mixTime = localtime(iTime);
	if (mixTime[TIME_HOUR]>23)
	{
		call_out("check_time",3600*24-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
		return;
	}
	if ( mixTime[TIME_HOUR] <1 )
	{
		call_out("check_time",1*3600-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
		return ;
	}
	if ( mixTime[TIME_HOUR] ==1 && mixTime[TIME_MIN]<30 )
	{
		call_out("check_time1",60*(30-mixTime[TIME_MIN]));
		return;
	}
	else
		call_out("check_time1",1);
}

void check_time1()
{
	
	int i;
	mixed *mixTime;
	mixTime=localtime(get_party_time());
	if(gumu_party)
	{
		for(i=0;i<3;i++)
		CHAT_D->sys_channel(0,HIR "Phó bản Bá Vương Chiến Quốc đã bắt đầu, anh em hãy mau mau tới báo danh !!");
	}
	gumu=1;
	call_out("check_time2",23*3600-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
}

void check_time2()
{	int i;
	mixed *mixTime;
	mixTime=localtime(get_party_time());
	remove_call_out("check_time2");
	if(gumu_party)
	{   
	   for(i=0;i<3;i++)
	   CHAT_D->sys_channel(0,HIR "Phó bản Bá Vương Chiến Quốc đã kết thúc lúc 11h tối, anh em hãy quay lại vào ngày mai !!");
	}
	gumu=0;
	call_out("player_exit",24*3600-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
	call_out("check_time",24*3600-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
}

int get_gumu_open()
{
	return gumu;
} 

void set_gumu_party_open( int party,int test)
{
	if(party==0)
	{	
		if(test) 
		{
			USER_D->gm_channel(HIY"测试活动关闭");
			gumu=0;
	   	}
	   	USER_D->gm_channel(HIY"ＧＭ正常关闭活动");
	   	
	}
	else
	{
	      	if(test) 
	      	{
	      		USER_D->gm_channel(HIY"测试活动开启") ;
	      		gumu=1;
	      	}
	      	USER_D->gm_channel(HIY"ＧＭ正常开启活动") ;   
        }
        gumu_party=party;
        __FILE__->check_time();
        save();
}

int get_gumu_party_open()
{
	return gumu_party;	
}

string get_party_statue()
{
	if(get_gumu_party_open()&&get_gumu_open())
	return "Phó bản Bá Vương Chiến Quốc đang bắt đầu";
	else if(get_gumu_party_open())
		return "Phó bản Bá Vương Chiến Quốc đã bắt đầu";
	return "Phó bản Bá Vương Chiến Quốc đã kết thúc";
}

//void add_npc(int z,int x,int y)
//{
//	object npc,map;
//	npc=new(FILE_NPC);
//	if(!npc) return;
//	if(!z&&!x&&!y) return;
//	if(!objectp(map=get_map_object(z))) return;
//	npc->add_to_scene(z,x,y,4,9413);
//	map->set("npc",npc);
//}
//
//void delete_npc(int z)
//{
//	object map,npc;
//	if(!z) return;
//	if(!objectp(map=get_map_object(z))) return;
//	npc=map->get("npc");
//	npc->remove_from_scene();
//	destruct(npc);
//	map->delete("npc");
//	
//}

void player_exit()
{
	PLAYER_EXIT->player_exit();
}