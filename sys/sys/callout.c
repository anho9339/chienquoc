#include <ansi.h>

#define MIN2            120
#define MIN3            300
#define HOUR            3600
#define HOUR2           1800
#define UPDATE            "/quest/update.lst"

object *HourItem = ({ });

static int counter = 0;

// 函数:生成二进制码
void SAVE_BINARY() { }

void check_org();

// 函数:获取使命物品
object *get_hour_item() { HourItem -= ({ 0 });  return copy(HourItem); }


object globalseller = 0;

// 函数:获取使命物品
void add_hour_item( object item ) { HourItem = HourItem - ({ item, 0 }) + ({ item }); }

// 函数:构造处理
void create() 
{
	if ( MAIN_D->get_absolute_random_number()==0 ) return ;
        call_out( "min2_callout", ( time() + MIN2 ) / MIN2 * MIN2 - time() );
        call_out( "min3_callout", ( time() + MIN3 ) / MIN3 * MIN3 - time() );
        call_out( "hour_callout", ( time() + HOUR ) / HOUR * HOUR - time() + 15 );    // 滞后 15 秒
        call_out( "hour2_callout", ( time() + HOUR2 ) / HOUR2 * HOUR2 - time() + 30 );    // 滞后 30 秒
    //    call_out( "seller_callout",  15);
        "sys/sys/server"->start_it();
        "sys/task/mine"->check_mine();
        "/sys/item/stuff"->reset_stuff();
        "/sys/item/stuff2"->reset_stuff();
//        "/sys/item/stuff3"->reset_stuff();
        "/sys/item/box"->reset_stuff();	       
	"/sys/school/shouxi"->check_time();
//	"sys/party/football"->check_time();

	"sys/party/phitac"->check_time();
	"sys/party/chaomung"->check_time();
	
//	"/sys/party/treasure"->check_time();
	"sys/party/gold_warrior"->check_time();
	"sys/party/sect_surprise"->check_time();
//	"sys/party/valentine"->check_time();
	"sys/party/chunjie"->check_time(); // Tết
//	"sys/party/qixi"->check_time();
	"/sys/user/plant"->do_nothing();
	"/sys/task/escort"->do_nothing();
//	"/sys/party/burst_equips"->do_activity();
	"/sys/party/guess_true_tiger"->do_nothing();
//	"/sys/party/defence"->check_time();
	"/sys/party/choden"->check_time();
	"sys/party/gumu_check_time"->check_time();
//	"sys/party/chongyang"->check_time();
//	"sys/party/national"->check_time();
//	"sys/party/phando"->check_time();
	"sys/party/CoTuong"->check_time();
	"sys/party/event8thang3"->check_time();
//	"sys/party/tuyetdaicaothu"->check_time();
	"sys/party/acquy"->check_time();
//	"sys/party/kinhkha"->check_time();
	"sys/party/tongbaoyeu"->check_time();
	"sys/party/baothachtieuyeu"->check_time();
	"sys/party/baohop"->check_time();
	"sys/party/haiqua"->check_time();
	"sys/party/doatbaomatacnew"->check_time();
//	"sys/party/christmas"->check_time();
	"sys/party/vstfix"->check_time();
//	"sys/party/tinhnhan"->check_time();
//	"sys/party/HoaHong"->check_time();
	"sys/party/cuunhandothe"->check_time();
	"sys/party/chiakhoavahop"->check_time();
	"sys/party/sdv"->check_time();
	"sys/party/30thang4"->check_time();
	"sys/party/PhoBanSatThanVuongCheckTime"->check_time();
//	"sys/party/qtpn"->check_time();
 //   "sys/party/ChienY"->check_time();
//	"sys/party/tethien"->check_time();
//	"sys/party/bossmonphai"->check_time();
	"sys/party/truylungtutu"->check_time();
//	"sys/party/halloween"->check_time();
 //   "sys/party/thienson"->check_time();
	 "sys/party/bonboss"->check_time();
//	 "sys/party/bossthatphai"->check_time();
//	  "sys/party/boss2011"->check_time();
//    "sys/party/trungthu"->check_time();
//    "sys/party/trungthu2"->check_time();
//      "sys/party/event2011"->check_time();	  
}
void check_update()
{
        string text, *line, *key;
        int i, size;
        object obj;
        text = read_file( UPDATE );	
        if (!text || text=="") return;
        rm(UPDATE);
        line = explode(text, "\n");
        size = sizeof(line);
        for (i=0;i<size;i++)
        {
        	key = explode(line[i], " ");
        	if (sizeof(key)==2)
        	{
        		// 更新 code dll
        		if (key[0]=="code")
        		{
        			"/cmd/sys/code"->set_crypt_code(to_int(key[1]));        			
        			log_file( "update.dat", sprintf( "%s 设置加密方式%d\n", short_time(), "/cmd/sys/code"->get_crypt_code()) );
        		}
        		continue;
        	}
	        if( obj = find_object(line[i]) ) 
	        {
	                obj->before_destruct();
	                destruct(obj);
	        }	
		obj = load_object(line[i]);
		if (obj)
		{
		        call_other( line[i], "???" ) ;        	
		        log_file( "update.dat", sprintf( "%s 更新%s成功\n", short_time(), line[i]) );
		}
		else
			log_file( "update.dat", sprintf( "%s 更新%s失败\n", short_time(), line[i]) );
        }        
}

// 函数:公告提示(２分钟)
void min2_callout()
{
        remove_call_out( "min2_callout" );
        call_out( "min2_callout", ( time() + 10 + MIN2 ) / MIN2 * MIN2 - time() );
       	TIPS_D->send_tips_to_user();
        check_update();
}

// 函数:(5分钟)
void min3_callout()
{
	object * user;
	int size;
        user =  USER_D->get_user();
        size = sizeof(user);	
        remove_call_out( "min3_callout" );
        call_out( "min3_callout", ( time() + 10 + MIN3 ) / MIN3 * MIN3 - time() );
        "/sys/sys/id"->add_usercount(size);
        if (MAIN_D->get_host_type()!=4)
		db_sys_info( sprintf( MAIN_D->get_php_ip()+":80\n"
			"GET /xq2/online.php?time=%d&region=%d&host=%d&online=%d\r\n", time(), MAIN_D->get_region(), MAIN_D->get_host(), size ) ); 
	else
	{
		db_sys_info( sprintf( MAIN_D->get_php_ip()+":80\n"
			"GET http://%s/online.php?t=%s&r=%d&h=%d&u=%d\r\n", MAIN_D->get_php_ip(), short_time_2(), MAIN_D->get_region(), MAIN_D->get_host(), size ) ); 	
//log_file("php.dat", 	sprintf( MAIN_D->get_php_ip()+":80\n"
//			"GET http://%s/online.php?t=%s&r=%d&h=%d&u=%d\r\n", MAIN_D->get_php_ip(), short_time_2(), MAIN_D->get_region(), MAIN_D->get_host(), size ) ); 			
	}
	"/sys/sys/count"->check_command();		
}

// 函数:复位处理(１小时)
void hour_callout()
{
        int i, size, level;
        object *user;
        int * count = ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, });

        remove_call_out( "hour_callout" );
        call_out( "hour_callout", ( time() + 10 + HOUR ) / HOUR * HOUR - time() + 15 );

        HourItem -= ({ 0 });
        for( i = 0, size = sizeof(HourItem); i < size; i ++ ) if( HourItem[i] ) HourItem[i]->reset();
        user =  USER_D->get_user();
        size = sizeof(user);
        if (size>0)
        {
        	for (i=0;i<size;i++)
        	{
        		if (!is_player(user[i])) continue;
        		if (user[i]->get_gender()==1) count[0] += 1;
        		else count[1] += 1;
        		level = user[i]->get_level();
        		level = 2 + level/10;
        		if (level>=15) level = 14;
        		count[level] += 1;
        	}
        	log_file( "users.dat", sprintf( "%s %d", short_time(), sizeof(user)) );
        	for (i=0;i<15;i++)
        		log_file( "users.dat", sprintf( " %d", count[i]));
		log_file( "users.dat", "\n");        		
        }
        if ("/sys/sys/id"->get_quit_count()>0||"/sys/sys/id"->get_reconnect_count()>0||"/sys/sys/id"->get_netdead_count()>0||"/sys/sys/id"->get_kick_count()>0)
        {
        	log_file("quit.dat", sprintf("normal:%d reconnect:%d netdead=%d kickout=%d\n", "/sys/sys/id"->get_quit_count(), "/sys/sys/id"->get_reconnect_count(), "/sys/sys/id"->get_netdead_count(), "/sys/sys/id"->get_kick_count()));
        	"/sys/sys/id"->set_quit_count(0);
        	"/sys/sys/id"->set_reconnect_count(0);
        	"/sys/sys/id"->set_netdead_count(0);
        	"/sys/sys/id"->set_kick_count(0);
        }
        check_org();
}

// 函数:php记录(半小时)
void hour2_callout()
{
        int i, size, level;
        object *user;

        remove_call_out( "hour2_callout" );
        call_out( "hour2_callout", ( time() + 10 + HOUR2 ) / HOUR2 * HOUR2 - time() + 30 );
	"/cmd/std/look"->php_log();
}


// 函数:复位处理(半小时)
void seller_callout()
{
        remove_call_out( "seller_callout" );
//     	if ( objectp(globalseller) )
//	{
//	     	globalseller->remove_from_scene();
//		destruct(globalseller);
//	}
        if (globalseller==0)
        {
                globalseller = new ("/npc/task/8808");
                if (globalseller==0) return;                                        
        }                        
        globalseller->reset();
        call_out( "seller_callout", 1800 );
}

void seller_wait_callout()
{
        remove_call_out( "seller_callout" );
        call_out( "seller_callout", 1800 );
}

void check_org()
{
	int i, j, k, size, size2, number, max, grade, favour, gold, stable, store, time, level, *search;
	string *name, *name2, result, id;
	mapping org, skls;
	object file, orgnpc, user, *orgmember, city;
	counter ++;
	for (j=1;j<8;j++)
	{
		file = load_object(sprintf("/map/city/%02d", j));
		if (file)
		{
			if( mapp( org = file->get_save_2("org") ) )
			{
				name = keys(org);
				for( i = 0, size = sizeof(name); i < size; i ++ )
				{
					orgnpc = "/map/city/08"->get_2( sprintf( "org.%s", name[i] ) );
					if (!objectp(orgnpc)) continue;				
					if (orgnpc->get_stable()==0 && orgnpc->get_favour()==0)
					{
						// 帮派解散，处理帮众
			                        size2 = orgnpc->sizeof_member_dbase();
			                        name2 = orgnpc->get_all_member();

			                        for( k = 0; k < size2; k ++ )
			                        {
			                        	number = to_int(name2[k]);
			                        	id = orgnpc->get_meber_id(number);
			                        	if( objectp( user = find_player(name2[k]) ) )
			                                {
			                                	user->delete_tile("C001");
			                                	user->delete_tile("C002");
			                                	user->delete_tile("C003");
			                                	user->delete_tile("C004");
			                                	user->delete_tile("C005");
			                                	user->delete_tile("C006");
			                                	user->delete_tile("C007");
			                                	user->delete_tile("C008");
			                                	user->hide_title();
			                                	user->set_org_name("");
			                                	user->set_org_position(0);
			                                	user->set_org_title("");
			                                	send_user( user, "%c%c%c%c", 0x3d, 49, 0, 0 ); 
			                                }
			                                "/inh/user/mail"->sys_mail(id, number, sprintf("Bởi vì Bang Phái %s tình hình khó khăn, vì thế Bang Phái giải tán", name[i]));
			                        }
			                        file->delete_save_2("org."+name[i]);
			                        "/map/city/08"->delete_2( sprintf( "org.%s", name[i] ) );
			                        if(  city = CITY_D->get_city_object(orgnpc) ) 
			                        {
			                        	orgmember = city->get("manager");
			                        	orgmember -= ({ orgnpc });
			                        	city->set("manager", orgmember );
			                        }
			                        destruct(orgnpc);
			                        CHAT_D->rumor_channel(0,HIR+sprintf("Nghe nói Bang Phái %s tình hình khó khăn, bị bắt buộc phải giải tán", name[i]));
					}
					else
					{
						grade = orgnpc->get_grade();
						orgmember = FAMILY_D->get_org(name[i]);
						number = sizeof(orgmember);
						max = orgnpc->get_max_number();
						if (number<max/20) 
						{
							favour = -5;
							stable = -5;
						}
						else
						if (number<max*15/100) 
						{
							favour = 0;
							stable = 0;
						}
						else
						if (number<max *3/10) 
						{
							favour = 5;
							stable = 5;
						}
						else 
						{
							favour = 10;
							stable = 10;
						}
//						orgnpc->add_favour(favour);
//						orgnpc->add_stable(stable);

						
						// 检查技能
						skls = orgnpc->get_researchs();
						search = keys(skls);
						size2 = sizeof(search);
						if (size2>0)
						{
							for (k=0;k<size2;k++)
							{
								level =  skls[search[k]];
								if (search[k]>0 &&level>0)
								{
									switch(level)
									{
									case 1: gold = 24000; break;
									case 2: gold = 48000; break;
								       default: gold = 96000; break;
									}
									if (orgnpc->get_store()>=level && orgnpc->get_gold()>=gold)
									{
										orgnpc->improve_skill(search[k], 400 + level*400);
										orgnpc->add_gold(-gold);
										orgnpc->add_store(-level);
									}									
								}
							}
						}
/*						
						time = orgnpc->get_research();
						if (time>0)
						{
							level = orgnpc->get_research_level();
							switch(level)
							{
							case 1: gold = 24000; break;
							case 2: gold = 48000; break;
						       default: gold = 96000; break;
							}
							if (orgnpc->get_store()>=level && orgnpc->get_gold()>=gold)
							{
								orgnpc->improve_skill(time, 400 + level*400);
								orgnpc->add_gold(-gold);
								orgnpc->add_store(-level);
							}
						}
*/						
						time = orgnpc->get_traintime();
						if (time>0 && time()>time)
						{
							orgnpc->set_traintime(0);
							orgnpc->set_train(orgnpc->get_train()+1);
						}
						time = orgnpc->get_sciencetime();
						if (time>0 && time()>time)
						{
							orgnpc->set_sciencetime(0);
							orgnpc->set_science(orgnpc->get_science()+1);
							FAMILY_D->org_channel( name[i], 0, sprintf( HIR "Trải qua bao nhiêu cố gắng, lực Nghiên cứu của Bang Phái đã tăng thêm 1 điểm, hiện tại lực Nghiên cứu là %d điểm",
                                         			orgnpc->get_science() ) );
						}
						time = orgnpc->get_gradetime();
						if (time>0 && time()>time)
						{
							orgnpc->set_gradetime(0);
							orgnpc->set_grade(grade+1);
							FAMILY_D->org_channel( name[i], 0, sprintf( HIR "Quy mô Bang Phái tăng thêm 1 điểm, hiện tại Quy mô Bang Phái là %d .",
								orgnpc->get_grade() ) );
						}						
						time = orgnpc->get_demisstime();
						if (time>0 )
						{		
							if (time()>time)					
								"/sys/city/manager"->do_demise2(orgnpc, orgnpc->get_demissnumber());							
							else
							{
								time = (time - time())/3600;
								if (time % 2 ==0)
								{
									number = orgnpc->get_demissnumber();
						                        FAMILY_D->org_channel( name[i], 0, sprintf( HIR "Bang chủ %s đối với %s(%d) có sự ưu ái nên quyết định nhường chức, sau %d giờ sẽ hoàn tất việc nhường chức.",
						                                orgnpc->get_master_name(), orgnpc->get_member_name(number), number, time ) );									
								}
							}
						}
//						if (counter%24==0) orgnpc->add_stable(-10);	
						if (counter % 2==0)
						{
							switch(grade)
							{
							case 1: gold = 2000; break;
							case 2: gold = 4000; break;
							case 3: gold = 8000; break;
							case 4: gold = 12000; break;
							case 5: gold = 25000; break;
							}
							store = ( grade - 1 ) * 2;
							if (orgnpc->get_gold()<gold||orgnpc->get_store()<store)
							{
								if (orgnpc->get_gold()<gold)
									result = "Bang Phái Tổng Quản: Bổn bang hiện tại Tài chính không đủ, khiến độ An Định giảm xuống, mong mọi thành viên trong Bang cố gắng hơn !!\n";
								else
									result = "Bang Phái Tổng Quản: Bồn bang dự trữ không đủ, khiến độ An Định giảm xuống, mong mọi thành viên trong Bang cố gắng hơn !!\n";
								FAMILY_D->org_channel( name[i], 0, HIR +result );
								switch(grade)
								{
								case 1: orgnpc->set_stable(orgnpc->get_stable()-10); break;
								case 2: orgnpc->set_stable(orgnpc->get_stable()-20); break;
								case 3: orgnpc->set_stable(orgnpc->get_stable()-40); break;
								case 4: orgnpc->set_stable(orgnpc->get_stable()-70); break;
								case 5: orgnpc->set_stable(orgnpc->get_stable()-100); break;
								}
							}
							else
							{
								orgnpc->add_gold(-gold);
								orgnpc->set_store(orgnpc->get_store()-store);								
								result = sprintf("Bang Phái Tổng Quản: Lần này Bang phái hằng ngày giữ gìn, tổng cộng tiêu hao Tài chính %d lượng cùng %d điểm Dự trữ. Tài chính Bang Phái vẫn còn thừa %d lượng, điểm Dự trữ vẫn còn thừa %d điểm.", gold, store, orgnpc->get_gold(), orgnpc->get_store() );
								FAMILY_D->org_channel( name[i], 0, HIR +result );
							}
						}							
						orgnpc->save();
					}
				}
			}
			file->save();
		}

	}
}
