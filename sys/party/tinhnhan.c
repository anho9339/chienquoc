/*****************************
	**Valentine**
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

int *nScene = ({1,10,20,30,40,50,60,70,80});
int iStart,iFinish,iFinish2,close_val,open_val;

object *TinhNhan;
object check_tn(object me, object who);
mapping mpTinhNhan;
void vao_tinhnhan(object me, object who, object user);
void generate_tinhnhan();
void destroy_tinhnhan();

// 函数：生成二进制码
void SAVE_BINARY() { }

void create()
{
	iStart = mktime(2014,2,14,0,0,0);
	iFinish = mktime(2014,2,22,23,59,59);
	TinhNhan = ({});
	mpTinhNhan = ([]);
	call_out("check_time",3);

}

void check_time()
{
	int iHour,p;
	mixed *mixTime;
	remove_call_out("check_time");
	iHour = time();
	switch( open_val )
	{
		case 1 : 
			mixTime = localtime(time());
			iHour = mixTime[TIME_HOUR];
			if ( mixTime[TIME_MIN] >= 30 )
				call_out("check_time",60*(60-mixTime[TIME_MIN]));
			else
				call_out("check_time",60*(30-mixTime[TIME_MIN]));
			if (iHour==0||iHour==1||iHour==2||iHour==3||iHour==4||iHour==5||iHour==6||iHour==7||iHour==8||iHour==9||iHour==10||iHour==11||iHour==12||iHour==13||iHour==14||iHour==15||iHour==16||iHour==17||iHour==18||iHour==19||iHour==20||iHour==21||iHour==22||iHour==23)	//放Pháo
			{
				generate_tinhnhan();
			}

			break;
		case 0 : 
			if ( iHour > iFinish )
			{
				destroy_tinhnhan();
				return ;
			}
			if ( iHour < iStart )
			{
				call_out("check_time",iStart-iHour);
				return ;
			}

			mixTime = localtime(time());
			iHour = mixTime[TIME_HOUR];
			if ( mixTime[TIME_MIN] >= 30 )
				call_out("check_time",60*(60-mixTime[TIME_MIN]));
			else
				call_out("check_time",60*(30-mixTime[TIME_MIN]));

			if (iHour==0||iHour==1||iHour==2||iHour==3||iHour==4||iHour==5||iHour==6||iHour==7||iHour==8||iHour==9||iHour==10||iHour==11||iHour==12||iHour==13||iHour==14||iHour==15||iHour==16||iHour==17||iHour==18||iHour==19||iHour==20||iHour==21||iHour==22||iHour==23)	//放Pháo
			{
				generate_tinhnhan();
			}

			break;
	}
}

//  放入年兽
void generate_tinhnhan()
{
	int i,size,z,p,x,y,j,count,amount;
	object *nObj,npc;
	nObj=({});
	destroy_tinhnhan();
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		nObj = mpTinhNhan[z];
		if ( !arrayp(nObj) )
			nObj = ({});
		nObj -= ({ 0 });
		amount = 30 - sizeof(nObj);
		nObj = ({});
		for(i=0;i<amount;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			npc = new("/npc/event/qvvlt");
			npc->add_to_scene(z,x,y);	
			TinhNhan += ({ npc });
			nObj += ({ npc });	
		}
		mpTinhNhan[z] = nObj;
	}
	CHAT_D->sys_channel(0,HIR "Quái vật Valentine đã xuất hiện ngoài thành các quốc gia, nghe nói tiêu diệt chúng sẽ đạt được Chocolate !");
}

//  移除年兽
void destroy_tinhnhan()
{
	int i,size;
	for(i=0,size=sizeof(TinhNhan);i<size;i++)
	{
		if ( !objectp(TinhNhan[i])	)
			continue;
		TinhNhan[i]->remove_from_scene();
		destruct(TinhNhan[i]);
	}
}
object check_tn(object me, object who)
{
	object *team,user;
	string leader;
/*	if ( !who->get_save_2("marry") )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi hiện tại chưa kết duyên vợ chồng cùng ai hết !");
		return 0;
	}*/
	if ( who->get_level()<40 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đẳng cấp của ngươi chưa đạt 40 cấp !");
		return 0;
	}
	if ( who->get_save("pbtndalam")>0 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi đã từng tham gia tìm kiếm Pháp bảo Tình Nhân rồi !");
		return 0;
	}
	if ( TASK_LEGEND_D->check_task_item_amount(who,"Hoa Hồng Thâu Tâm") < 10 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi không có đủ 10 Hoa Hồng Thâu Tâm, không thể tham gia !");
		return 0;
	}
	if(  !arrayp( team = who->get_team() ) || sizeof(team) == 1 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi muốn tham gia cùng với người nào? Hãy lập tổ đội cùng người đó rồi đến gặp ta !");
		return 0;
	}
	if( sizeof(team) > 2 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Nhóm của ngươi có quá nhiều người !");
		return 0;
	}
	if ( !stringp(leader=who->get_leader()) || to_int(leader) != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Ngươi không phải là trưởng nhóm, không thể tham gia !");
		return 0;
	}
	team -= ({ who });
	user = team[0];
	if (!inside_screen_2(who, user))
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Khoảng cách của ngươi với người kia quá xa !");
		return 0;
	}
	/*if ( user->get_save_2("marry.id") != who->get_number() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đối phương không phải là người từng cùng ngươi kết duyên vợ chồng!");
		return 0;
	}*/
	if ( user->get_gender()==who->get_gender() )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đối phương cùng giới tính với ngươi !");
		return 0;
	}
	if ( user->get_save("pbtndalam")>0 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đối phương đã từng tham gia tìm kiếm Pháp bảo Tình Nhân rồi !");
		return 0;
	}
	if ( user->get_level()<40 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đẳng cấp của đối phương chưa đạt 40 cấp !");
		return 0;
	}
	if ( TASK_LEGEND_D->check_task_item_amount(user,"Hoa Hồng Thâu Tâm") < 10 )
	{
		send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), me->get_name()+":\n Đối phương không có đủ 10 Hoa Hồng Thâu Tâm, không thể tham gia !");
		return 0;
	}
	return user;
}
void do_giftben(object me, object who, string arg)
{
	int flag;
	object user;
	flag = to_int(arg);
	who->set_time( "talk",  0);
	switch(flag)
	{
		case 3:
			if ( !objectp(user=check_tn(me,who)) ) return 0;
			vao_tinhnhan(me,who,user);
			break;	
	}
}
void vao_tinhnhan(object me, object who, object user)
{
	int x,y,z,level,p,d,family,ord,size,i;
	string cityname;
	object map,npc,*team;
	if ( !objectp(user=check_tn(me,who)) ) return 0;
	if( ( z = find_map_flag(1000, 2999, 0) ) <= 0 ) return ;
	x = ( p % 1000000 ) / 1000;  y = p % 1000;
	npc = new( "npc/event/pbtn" );
	if (!npc) return ;
	npc->set("level", who->get_level()); 
	d = 895; cityname = "Đấu Trường";
        init_virtual_map(z, d);		
        map = new( NEWBIE );
        map->set_client_id(d);
        map->set_owner(who);
        set_map_object( map, map->set_id(z) );       
        map->set_name(cityname);    
        p = get_jumpin(z, 1);
	npc->set_char_type(FIGHTER_TYPE_2);
	npc->set_level(who->get_level());
		NPC_ENERGY_D->init_level(npc, who->get_level());
			npc->add_max_hp(npc->get_max_hp()*50);
			npc->add_dp(npc->get_dp()/2);
			npc->add_ap(npc->get_ap()*13/10);
			npc->add_pp(npc->get_pp()/2);
		npc->set_walk_speed(2);
        npc->set_attack_speed(10);
	NPC_ENERGY_D->init_family1(npc);
	x = p/1000, y = p % 1000;
	npc->set("pbtn_z",z);
	npc->set("pbtn_x",x);
	npc->set("pbtn_y",y);
	npc->set("userpbtn", who->get_number());
	npc->set("userpbtn2", user->get_number());
	npc->set("fightpbtn", who);
//	npc->set("fightpbtn", user);
    who->set_2("pbtn.x", get_x(who));
	who->set_2("pbtn.y", get_y(who));
	who->set_2("pbtn.z", get_z(who));  
	user->set_2("pbtn.x", get_x(user));
	user->set_2("pbtn.y", get_y(user));
	user->set_2("pbtn.z", get_z(user));	
	if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        {
                x = p/1000, y = p % 1000;
                who->add_to_scene(z, x+random(1), y+random(1), 3);
				user->add_to_scene(z, x+random(2), y+random(2), 3);
        }	
        who->set_save_2("pbtn.time",time());
        who->set_save_2("pbtn.status", 1);
		user->set_save_2("pbtn.time",time());
        user->set_save_2("pbtn.status", 1);
		who->set_save("pbtndp",user);
		user->set_save("pbtndp",who);
		who->set_save("pbtndpben",user->get_name());
		user->set_save("pbtndpben",who->get_name());
        npc->do_fight(1);
	TASK_LEGEND_D->check_task_item1(who,"Hoa Hồng Thâu Tâm",10);	
	TASK_LEGEND_D->check_task_item1(user,"Hoa Hồng Thâu Tâm",10);	
}
// 函数：掉宝奖励
void drop_items( object me, object who )
{
        object item, leader;
        string file, owner, id;
        int p, i, size, gold ;
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
                if( p = get_valid_xy(z, x, y, IS_ITEM_BLOCK) )
                {
                        item = new("/item/event/chocolate");
                        TEAM_D->drop_item(item,who);
                        item->set_user_id(owner);
                        item->add_to_scene(z, p / 1000, p % 1000);
                        item->set("winner", who);
                        item->set( "time", time() );
                }
		
}
// 函数：死亡奖励(在线更新)
void win_bonus_callout( object me, object who )
{
        object owner, *team, map;
        int exp, exp2 ;
        int i, size ;
        string leader;

        if( !objectp( who = me->get_enemy_4() ) ) return;
        if( owner = who->get_owner() ) who = owner;
        if( who->is_npc() ) return;
	map = get_map_object(get_z(me));
	CHAT_D->sys_channel(0, HIY"Quái Vật Valentine ở "+map->get_name()+" đã bị bằng hữu "+who->get_name()+" tiêu diệt." ); 
		
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