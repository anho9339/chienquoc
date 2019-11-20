#include <ansi.h>
#include <time.h>
#define JINQIAN		"item/test2/CoTuong"
#define BAOXIAN		"item/test2/CoTuong"

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
	iStart = mktime(2016,2,4,7,0,0);	 // Năm , tháng , ngày , giờ
	iFinish = mktime(2016,3,1,22,0,0);	
	
//	iStart = mktime(2007,1,17,13,0,0);	
//	iFinish = mktime(2007,1,17,17,0,0);		
	call_out("check_time",30);  // Open sv sau 30 rớt item
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
	call_out("check_time",7200); //2h gọi ra 1 lần
	generate_gift();
}
/*
void generate_money()
{
	int i,size,z,p,x,y,j,count;
	object *nObj,item;
	
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<40;i++)
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
	log_file("distribute.txt",short_time() + " 放金钱\n" );
	CHAT_D->rumor_channel(0,sprintf(HIY"%s nổi lên một trận cuồng phong, sau trận cuồng phong đó có rất nhiều Chiến Y đột nhiên rớt xuống ở U Cốc, Thanh Khê, Ba Khâu ! Nghe nói Sứ Giả Hoạt Động đang tìm kiếm vật phẩm này đấy !",nCountry[random(8)]));
}

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
	log_file("distribute.txt",short_time() + " 放大礼包\n" );
}
*/
void start_it()
{
	
}

void generate_gift()
{
	int i,size,z,p,x,y,j,count,*nPlace=({10,20,30,40,50,60,70});
	object *nObj,item;
	
	for(j=0,count=sizeof(nPlace);j<count;j++)
	{
		z = nPlace[j];
		for(i=0;i<70;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new("item/test2/CoTuong");
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
//			log_file("distribute.txt",sprintf("%s box %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("distribute.txt",short_time() + " rớt cờ tướng.\n" );
	CHAT_D->sys_channel( 0, " Rất nhiều Cờ Tướng đã rơi xuống Tân Thủ Thôn và ngoài thành 7 Quốc Gia, Nghe nói Tiên Cô Thiên Sứ - Tiểu Long Nữ đang tìm kiếm những cái Cờ Tướng này !" ); 
}