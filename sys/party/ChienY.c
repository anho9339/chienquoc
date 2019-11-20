#include <ansi.h>
#include <time.h>
#define JINQIAN		"item/test2/ChienY"
#define BAOXIAN		"item/test2/ChienY"

// Phải mở sv từ lúc 12h tối
int iStart,iFinish;
//int *nScene = ({1,2,3,162});
int *nScene = ({2,3,162});
string *nCountry = ({"Chu Quốc","Tề Quốc","Hàn Quốc","Triệu Quốc","Ngụy Quốc","Tần Quốc","Sở Quốc","Yên Quốc",});
void generate_money();
void generate_box();
void generate_gift();

// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
	iStart = mktime(2015,2,2,1,0,0);	
	iFinish = mktime(2015,12,30,0,0,0);	
	
	call_out("check_time",30);
}

void check_time()
{
	int iHour;
	mixed *mixTime;

	remove_call_out("check_time");
	if (MAIN_D->get_host_type()==2)		//台湾除外
		return ;
	iHour = time();
	if ( iHour > iFinish )
		return ;
	if ( iHour < iStart )	//没到时间
	{
		call_out("check_time",iStart - iHour);
		return ;
	}
	call_out("check_time",10800); // Từ lúc mở sv, 3 tiếng/1 lần
	generate_money();
//	generate_box();
	generate_gift();
}

void generate_money()
{
	int i,size,z,p,x,y,j,count;
	object *nObj,item;
	
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<30;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(JINQIAN);
			if ( !objectp(item) )
				continue;
//			item->set_value(40+random(21));
			item->add_to_scene(z,x,y);	
//			log_file("distribute.txt",sprintf("%s money %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt",short_time() + " rớt chiến y.\n" );
	CHAT_D->rumor_channel(0,sprintf(HIY"%s nổi lên một trận cuồng phong, sau trận cuồng phong đó có rất nhiều Chiến Y đột nhiên rớt xuống ở U Cốc, Thanh Khê, Ba Khâu ! nghe nói Thiên Sơn Tướng Quân ở Chu(278,154) đang tìm kiếm vật phẩm này đấy!",nCountry[random(8)]));
}
/*
void generate_box()
{
	int i,size,z,p,x,y,j,count;
	object *nObj,item;
	
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<20;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(BAOXIAN);
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
//			log_file("distribute.txt",sprintf("%s box %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt",short_time() + " rớt chiến y.\n" );
}
*/

void start_it()
{
	
}

void generate_gift()
{
	int i,size,z,p,x,y,j,count,*nPlace=({1,10,20,30,40,50,60,70});
	object *nObj,item;
	
	for(j=0,count=sizeof(nPlace);j<count;j++)
	{
		z = nPlace[j];
		for(i=0;i<40;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new("item/test2/ChienMao");
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
//			log_file("distribute.txt",sprintf("%s box %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt",short_time() + " rớt chiến mão.\n" );
	CHAT_D->sys_channel( 0, HIY" Đột nhiên có rất nhiều Chiến Mão rơi ngoài thành các quốc gia và Tân Thủ Thôn! xảy ra chuyện gì đây, nhanh chóng đi tìm về nào ! nghe nói Thiên Sơn Tướng Quân ở Chu(278,154) đang tìm kiếm vật phẩm này đấy!" ); 
}