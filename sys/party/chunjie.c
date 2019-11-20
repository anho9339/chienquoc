/*****************************
	**春节**
*****************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

int *change54 =({ 0010,0011,0050,0051,0052,0053,0100,0101,0102,0150,0151,0152,0200,0201,0202,0250,0251,0252,0300,0301,0302,0303,0304,0350,0351,0352,0400,0401,0402,0450,0500,0502,0550,0551,0552,8010,8011,});
int *nScene = ({1,10,20,30,40,50,60,70,80});
int iStart,iFinish,iFinish2,close_val,open_val;

mapping mpFuww =  ([
//  1:({  ({179,154,3}),({146,102,3}),({146,153,3}),({100,123,3}),  }),
// 10:({  ({130,114,8}),({114,129,8}),({ 64,168,8}),  }),
// 20:({  ({151,109,4}),({239, 67,3}),({175, 93,3}),  }),
// 30:({  ({174, 96,3}),({223, 61,3}),({249,111,2}),  }),
// 40:({  ({265,118,4}),({282,132,3}),({319,125,8}),  }),
// 50:({  ({133,119,2}),({118,134,3}),({ 51,138,2}),  }),
// 60:({  ({202,269,2}),({146,209,3}),({133,189,4}),  }),
// 70:({  ({149,189,6}),({255,192,2}),({171,213,2}),({194,265,2}),  }),
 80:({  ({318,135,4}),  }),
// 80:({  ({328,124,3}),({318,135,4}),({338,153,3}),({290,149,3}),({248,159,3}),({283,179,3}),({338,215,3}),({159, 75,8}),({214,118,4}),  }),
 // 54:({  ({132,116,2}),({106,133,4}),  }),
//165:({  ({106,32,3}),  }),
//269:({  ({258,177,4}),({267,187,4}),  }),
//273:({  ({208,162,4}),  }),
//289:({  ({107, 75,3}),  }),
//324:({  ({ 81,122,2}),  }),
]);

mapping mpFuhh =  ([
//  1:({  ({178,154,3}),({145,102,3}),({145,153,3}),({94,123,3}),  }),
// 10:({  ({134,117,4}),({121,134,4}),({ 69,172,4}),  }),
// 20:({  ({145,105,8}),({236, 65,3}),({228, 94,2}),  }),
// 30:({  ({229, 97,3}),({224, 62,3}),({254,107,6}),  }),
// 40:({  ({270,115,4}),({290,174,4}),({316,127,8}),  }),
// 50:({  ({128,115,2}),({121,171,4}),({ 57,142,2}),  }),
// 60:({  ({196,264,2}),({232,186,4}),({137,185,4}),  }),
// 70:({  ({145,192,2}),({251,189,2}),({227,220,4}),({197,267,2}),  }),
 80:({  ({314,138,4}),  }),
// 80:({  ({327,124,3}),({314,138,4}),({339,153,3}),({291,149,3}),({260,149,3}),({288,175,3}),({333,219,3}),({187, 66,4}),({209,122,4}),  }),
 // 54:({  ({135,119,2}),({114,139,8}),  }),
//165:({  ({105,32,3}),  }),
//269:({  ({261,175,4}),({271,184,4}),  }),
//273:({  ({185,148,3}),({312,159,4}),  }),
//289:({  ({ 77, 73,3}),({ 47, 57,7}),  }),
//324:({  ({111,107,3}),({ 86,125,2}),  }),
]);
object *NianShou,*BaoZhu,*FuWawa;
mapping mpNianshou;

void generate_baozhu();
void destroy_baozhu();
void generate_nianshou();
void destroy_nianshou();
void generate_fuwawa();
void destroy_fuwawa();

// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
	iStart = mktime(2016,2,1,7,0,0);
	iFinish = mktime(2016,2,20,23,0,0); // Năm, Tháng, Ngày, Giờ, Phút, Giây
	iFinish2 = mktime(2016,2,20,23,0,0);
	NianShou = ({});
	BaoZhu = ({});
	mpNianshou = ([]);
	FuWawa = ({});
	if (time()>iStart) generate_fuwawa();
	//call_out("check_time",3);
	call_out("check_time",1);

}

void check_time()
{
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;// khai báo mixTime ( quan trọng, nhớ  có dấu * ở trước )

	remove_call_out("check_time");
	iTime = time();// khai báo Time
	
	mixTime = localtime(iTime);

			if ( iTime > iFinish2 )
			{
				destroy_fuwawa();
				return ;
			}
			if ( iTime > iFinish )
			{
				destroy_baozhu();
				destroy_nianshou();
				return ;
			}
			if ( iTime < iStart )	//没到时间
			{
				call_out("check_time",iStart-iTime);
				return ;
			}
				
			i = 60*(60-mixTime[TIME_MIN]);
			if ( mixTime[TIME_HOUR]%2 == 1 )// == 0 là giờ lẽ, == 1 là giờ chẵn
			{
				call_out("check_time",i);
			}
			else
			{
				if ( mixTime[TIME_HOUR] == 2 || mixTime[TIME_HOUR] == 4 || mixTime[TIME_HOUR] == 6 || mixTime[TIME_HOUR] == 10 || mixTime[TIME_HOUR] == 14 || mixTime[TIME_HOUR] == 18 || mixTime[TIME_HOUR] == 22
				|| (mixTime[TIME_HOUR] == 8 && mixTime[TIME_MIN] > 30) 				//Nếu giờ hiện tại là: 2 , 4, 6, 10, 14, 18, 22h thì Kết thúc hàm -> ko có Niên thú
				|| (mixTime[TIME_HOUR] == 12 && mixTime[TIME_MIN] > 30)    
				|| (mixTime[TIME_HOUR] == 16 && mixTime[TIME_MIN] > 30)   // Nếu ko có dòng > 30 thì 9h59 vẫn sẽ có phỉ còn nếu có thì khi bật GSE lên 9h30 sẽ ko có Niên thú
				|| (mixTime[TIME_HOUR] == 20 && mixTime[TIME_MIN] > 30) 
				|| (mixTime[TIME_HOUR] == 24 && mixTime[TIME_MIN] > 30) )
					call_out("check_time",i+3600);
				else
				{
					generate_nianshou(); // Nếu giờ hiện tại là: 7,9,11,13,15,17,19,21 thì gọi niên thú ra 
					call_out("check_time",i+3600);//( nhưng nếu cùng giờ đó mà số phút lớn hơn 30 - Chỉ tính cái này khi vừa bật GSE -> thì niên thú sẽ đợi sang giờ kế tiếp mới xuất hiện )
				}
			}
		
		
		
	/*
	int iHour,p;
	mixed *mixTime;
	remove_call_out("check_time");
//	if (MAIN_D->get_host_type()==4)		//猫扑除外
//		return ;
	iHour = time();
	switch( open_val )
	{
		case 1 : 
			mixTime = localtime(time());
			iHour = mixTime[TIME_HOUR];
		//	if ( mixTime[TIME_MIN] >= 30 )
		//		call_out("check_time",60*(60-mixTime[TIME_MIN]));
		//	else
		//		call_out("check_time",60*(60-mixTime[TIME_MIN]));
			if (mixTime[TIME_MIN] >= 30 )
				call_out("check_time",120*(60-mixTime[TIME_MIN]));
			else
				call_out("check_time",120*(60-mixTime[TIME_MIN]));
		//	if (iHour==0||iHour==1||iHour==2||iHour==3||iHour==4||iHour==5||iHour==6||iHour==7||iHour==8||iHour==9||iHour==10||iHour==11||iHour==12||iHour==13||iHour==14||iHour==15||iHour==16||iHour==17||iHour==18||iHour==19||iHour==20||iHour==21||iHour==22||iHour==23)	//放Pháo
			if (iHour==7||iHour==9||iHour==11||iHour==13||iHour==15||iHour==17||iHour==19||iHour==21)
			{
			//	generate_baozhu();
				generate_nianshou();
			}

			break;
		case 0 : 
			if ( iHour > iFinish2 )
			{
				destroy_fuwawa();
				return ;
			}
			if ( iHour > iFinish )
			{
				destroy_baozhu();
				destroy_nianshou();
				return ;
			}
			if ( iHour < iStart )	//没到时间
			{
				call_out("check_time",iStart-iHour);
				return ;
			}

			mixTime = localtime(time());
			iHour = mixTime[TIME_HOUR];
			if ( mixTime[TIME_MIN] >= 30 )
				call_out("check_time",120*(60-mixTime[TIME_MIN]));
			else
				call_out("check_time",120*(60-mixTime[TIME_MIN]));

		//	if (iHour==0||iHour==1||iHour==2||iHour==3||iHour==4||iHour==5||iHour==6||iHour==7||iHour==8||iHour==9||iHour==10||iHour==11||iHour==12||iHour==13||iHour==14||iHour==15||iHour==16||iHour==17||iHour==18||iHour==19||iHour==20||iHour==21||iHour==22||iHour==23)	//放Pháo
		 if (iHour==7||iHour==9||iHour==11||iHour==13||iHour==15||iHour==17||iHour==19||iHour==21)
		{
			//	generate_baozhu();
				generate_nianshou();
			}

			break;
	}
	*/
}

// 函数：放入福娃娃
void generate_fuwawa()
{
	int i,size,z,p,x,y,j,count,*nZ,*nXy;
	object *nObj,fw;
	mixed *nPoint;
	nObj = ({});

	nZ = keys(mpFuww);
	for(j=0,count=sizeof(nZ);j<count;j++)
	{
		z = nZ[j];
		nPoint = mpFuww[z];
		for(i=0,size=sizeof(nPoint);i<size;i++)
		{
			fw = new("npc/party/fuww");
			if ( !objectp(fw) )
				continue;
			nXy = nPoint[i];
			fw->add_to_scene(z,nXy[0],nXy[1],nXy[2]);	
			FuWawa += ({ fw });
		}
	}
	
	nZ = keys(mpFuhh);
	for(j=0,count=sizeof(nZ);j<count;j++)
	{
		z = nZ[j];
		nPoint = mpFuhh[z];
		for(i=0,size=sizeof(nPoint);i<size;i++)
		{
			fw = new("npc/party/fuhh");
			if ( !objectp(fw) )
				continue;
			nXy = nPoint[i];
			fw->add_to_scene(z,nXy[0],nXy[1],nXy[2]);	
			FuWawa += ({ fw });
		}
	}

}

// 函数：移除福娃娃
void destroy_fuwawa()
{
	int i,size;

	for(i=0,size=sizeof(FuWawa);i<size;i++)
	{
		if ( !objectp(FuWawa[i]) )
			continue;
		FuWawa[i]->remove_from_scene();
		destruct(FuWawa[i]);
	}
}

/* // Rớt pháo
void generate_baozhu()
{
	int i,size,z,p,x,y,j,count;
	object item;
	
	destroy_baozhu();

	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<180;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new("/item/04/baozhu");
			item->set_amount(10);
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
			BaoZhu += ({ item });
		}
	}

} */

/* //  Hủy rớt Pháo
void destroy_baozhu()
{
	int i,size;

	for(i=0,size=sizeof(BaoZhu);i<size;i++)
	{
		if ( !objectp(BaoZhu[i]) )
			continue;
		BaoZhu[i]->remove_from_scene();
		destruct(BaoZhu[i]);
	}
}
*/

//  Tạo niên thú
void generate_nianshou()
{
	int i,size,z,p,x,y,j,count,amount;
	object *nObj,npc;
	nObj=({});
	destroy_nianshou();
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		nObj = mpNianshou[z];
		if ( !arrayp(nObj) )
			nObj = ({});
		nObj -= ({ 0 });
		amount = 10 - sizeof(nObj);
		nObj = ({});
		for(i=0;i<amount;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			npc = new("/npc/party/nianshou");
			npc->add_to_scene(z,x,y);	
			NianShou += ({ npc });
			nObj += ({ npc });
//			log_file("chunjie.txt",sprintf("%s %d %d %d %d\n",short_time(),i,z,x,y));	
		}
		mpNianshou[z] = nObj;
	}
	CHAT_D->sys_channel(0,HIR "Ngoài thành của các quốc gia lại xuất hiện 1 đám Niên Thú, Các vị anh hùng hãy nhanh nhanh lấy Pháo đuổi chúng đi! Chúng sẽ biến mất sau 15 phút!");
	CHAT_D->sys_channel(0,HIR "Ngoài thành của các quốc gia lại xuất hiện 1 đám Niên Thú, Các vị anh hùng hãy nhanh nhanh lấy Pháo đuổi chúng đi! Chúng sẽ biến mất sau 15 phút!");
	call_out("destroy_nianshou",900); // Sau 15 phút
}

//  Hủy niên thú
void destroy_nianshou()
{
	int i,size;
	for(i=0,size=sizeof(NianShou);i<size;i++)
	{
		if ( !objectp(NianShou[i])	)
			continue;
		NianShou[i]->remove_from_scene();
		destruct(NianShou[i]);
	}
	CHAT_D->sys_channel(0, HIY"Niên Thú đã bị các anh hùng CQTD lùa như lùa vịt, lần lượt tháo chạy về trời!" ); 
}

// 函数：掉宝奖励
void drop_items( object me, object who )
{
        object item, leader;
        string file, owner, id;
        int p, i, rate, size, gold, rate2 ;
        int z, x, y;

        z = get_z(me);  x = get_x(me);  y = get_y(me);
        id = who->get_leader();
        if (!id) owner = who->get_id();
        else
        {
        	if ( leader = find_player(id ) )
        	{
        		owner = leader->get_id();
		}      
		else
			owner = who->get_id();  		
		}
		rate2 = me->correct_drop_rate( me->get_level() - who->get_level() ) * who->get_online_rate() / 100;
        rate = random(10000);

		if( rate < 1 )
		{
		if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
	                {
		                switch( random(2) )
		                {
		               case 0 : item = new( "/item/sell/0032" );  break; 
		               case 1 : item = new( "/item/sell/1032" );  break; 	
						default: break;
		                }
	                        TEAM_D->drop_item(item,who);
							item->set_user_id(owner);
	                        item->add_to_scene(z, p / 1000, p % 1000);
	                        item->set("winner", who);
	                        item->set( "time", time() );
	                }
					
		} 
		else if( rate < 2000 )   // MG BDP
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new("/item/manhghep/bdp");
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(owner);
						item->set_amount(2+random(3));
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
		else if( rate < 6000 )    // MG DT
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new("/item/manhghep/mgdt");
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(owner);
						item->set_amount(2+random(4));
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
		else if( rate < 5000)    // Chiếu thư thiên tử
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new("/item/huyetlong/ghep/mg");
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(owner);
						item->set_amount(1+random(2));
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
		else if( rate < 3000 )    // Tinh Đơn Exp
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                       switch( random(3) )
		                {
		               case 0 : item = new( "/item/exp/tinhdonexp2" );  break; 
		               case 1 : item = new( "/item/exp/tinhdonexp3" );  break; 	
                       case 2 : item = new( "/item/exp/tinhdonexp4" );  break;
						default: break;
		                }
	                        TEAM_D->drop_item(item,who);
				item->set_user_id(owner);
	                        item->add_to_scene(z, p / 1000, p % 1000);
	                        item->set("winner", who);
	                        item->set( "time", time() );
                }
        }
		else if( rate < 2000)    // Kỳ Lân
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new("/item/event/tet/mgnt");
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(owner);
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        }
        if( rate < 1500)    //
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new( "/item/std/0001" );
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(owner);
                        item->set_value( 1000 + random(8000) );
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                        gold ++;
                }
        } 
        if( rate < 10000 )    // Tân Niên Đại Lễ Bao
        {
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new("/item/event/tet/tnlb");
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(owner);
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
        } 
}

// 函数：死亡奖励(在线更新)
void win_bonus_callout( object me, object who )
{
        object owner, *team;
        int exp, exp2 ;
        int i, size ;
        string leader;

        if( !objectp( who = me->get_enemy_4() ) ) return;
        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;
	
	CHAT_D->sys_channel(0, HIY"Nghe nói Niên Thú đã bị "+who->get_name()+" tiêu diệt" ); 
		
	drop_items(me,who);


        if( (leader=who->get_leader()) && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
        {
                team = me->correct_bonus_team(team);
                size = sizeof(team);
        }
        else    size = 1;

        exp=300;

        if( size > 1 )    // 多人
        {
                for( i = 0; i < size; i ++ ) if( team[i] )
                {
                        exp2 = exp*(10+size-1)/10;
                        team[i]->add_exp(exp2);
                }
        }
        else    // 单人
        {
        	who->add_exp(exp);
        }

}

//设置春节活动的开启和关闭
int set_newyear(int open,int close)
{
	open_val = open;
	close_val = close;
	check_time();
	return 1;	
}
