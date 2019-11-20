#include <city.h>																													// Code By Nguyen Hieu
#include <map.h>
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

		
int main( object me, string arg )
{
	int p,x,y,i,z,id;
	object item, map, npc, orgnpc;
	
	string result,cmd1,name;	
	
	if( !objectp( item = present("Truyền Tống Phù", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Truyền Tống Phù !");
                return 1;
        }	 
	
	   if ( arg==0 )
	{
		result = sprintf(MAG"Truyền Tống Phù :\nBạn đang sử dụng Truyền Tống Phù, bạn muốn đi đâu ???\n\n		Xin mời bạn hãy lựa chọn : \n" );
		result += ESC HIG"Đi Chu Quốc\ntruyentong Chu\n";
		result += ESC HIG"Đi Tề Quốc\ntruyentong Te\n";
		result += ESC HIG"Đi Hàn Quốc\ntruyentong Han\n";
		result += ESC HIG"Đi Sở Quốc\ntruyentong So\n";
		result += ESC HIG"Đi Tần Quốc\ntruyentong Tan\n";
		result += ESC HIG"Đi Triệu Quốc\ntruyentong Trieu\n";
		result += ESC HIG"Đi Ngụy Quốc\ntruyentong Nguy\n";
		result += ESC HIG"Đi Yên Quốc\ntruyentong Yen\n";
		result += ESC HIY"Đi Tân Thủ Thôn\ntruyentong ttt\n";
		result += ESC HIY"Đi Cự Thú Đảo\ntruyentong ctd\n";
		result += ESC HIY"Về Sư Môn\ntruyentong sm\n";
		result += ESC HIY"Về Bang Phái\ntruyentong bp\n";
	//	result += ESC YEL"\n\n";
	//	result += ESC YEL"\n\n";
	//	result += ESC YEL"\n\n";
		result += ESC WHT"Không muốn đi đâu hết...\n"; 
	//	send_user( me, "%c%s", ':', result);
		send_user( me, "%c%c%w%s", ':', 3, 5401, result);  //4153
                return 1;
	}
	//-----------------> Bắt đầu thực thi
	if ( arg=="bp" )
	{
		if( me->get_org_name() == "" )
        {
        	send_user(me, "%c%s", '!', "Bạn chưa gia nhập Bang phái.");
        	return 0;
        } 
        if( me->get_org_name() == 0 ) 
        {
        	send_user(me, "%c%s", '!', "Bạn chưa gia nhập Bang phái.");
        	return 0;
        } 
        if (me->get_org_position()<1)
        {
        	send_user(me, "%c%s", '!', "Bạn chưa gia nhập Bang phái.");
        	return 0;
        }
		
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }	
		
		name = me->get_org_name();
		orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", name ) );
		if (!objectp(orgnpc)) return;
		map = orgnpc->get("map");        
		if (map==0)
		{
			if( ( z = find_map_flag(NEWBIE_MAP_BEGIN, NEWBIE_MAP_END, 0) ) > 0 )
			{
			p = 886;
			init_virtual_map(z, p);    // 生成虚拟地图
			map = new( "/inh/std/org" );
			map->set_client_id(p);
			set_map_object( map, map->set_id(z) );
			orgnpc->set("map", map);
			orgnpc->set("z", z);
			map->set_name(name);
			"/sys/sys/manager"->init_org_place(z, name, orgnpc);
			}
		else
			return ;
		}
	else
	{
		z = orgnpc->get("z");
	}        
	if (random(2)) p = get_jumpin(z, 11);
	else p = get_jumpin(z, 12);	
        write_user(me, ECHO "Bạn đang đến Bang phái……");

        if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 3, "Trở về Bang……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 3);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả.");
                return 0;
        }	
		return 1;	
	}
	
	if ( arg=="ttt" )   
	{
	
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 01;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Tân Thủ Thôn……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Tân Thủ Thôn……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="Chu" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 80;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Chu Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Chu……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="Te" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 10;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Tề Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Tề……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="Han" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 20;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Hàn Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Hàn……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="So" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 60;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Sở Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Sở……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="Tan" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 50;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Tần Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Tần……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="Trieu" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 30;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Triệu Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Triệu……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="Nguy" )   
	{	
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 40;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Ngụy Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Ngụy……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="Yen" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 70;
        p = get_jumpin(z, 10);	
		write_user(me, ECHO "Bạn đang đến Yên Quốc……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang đến Yên……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="ctd" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		z = 549;
        p = 163137;
		write_user(me, ECHO "Bạn đang đến Cự Thú Đảo……");
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Cự Thú Đảo……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 2);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
	if ( arg=="sm" )   
	{
		if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng");
                return 0;
        }

		if( me->get_save_2("51cuanye.time") )
		{
		send_user(me, "%c%s", '!', "Không thể sử dụng.");
		return 0;
		}
        				
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
        
		if( present("钱票", me, 1, MAX_CARRY) )
        {
                send_user(me, "%c%s", '!', "Mang theo vật phẩm hiếm không thể sử dụng.");
                return 0;
        }
        
		if( present("Vật Phẩm Quý Bấu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Vật Phẩm Quý Bấu không thể sử dụng.");
                return 0;
        }
/*		if( present("Ngân Phiếu", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
//              write_user(me, ECHO "……可是没有任何效果.");
                return 0;
        } */
		
		if( present("Cờ Hiệu Vô Song Thành", me, 1, MAX_CARRY*4) )
        {
                send_user(me, "%c%s", '!', "Mang theo Cờ Hiệu không thể sử dụng.");
                return 0;
        }
		
		if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(me, "%c%s", '!', "Hành động bạn bị ảnh hưởng bởi kẻ lạ.");
                return 0;
        }
		
		switch( me->get_fam_name() )
        {
              default : 
        case "Đào Hoa Nguyên" : z = 289;  p = get_jumpin(z, 20);  break;
          case "Thục Sơn" : z = 273;  p = get_jumpin(z, 20);  break;
        case "Cấm Vệ Quân" : z = 080;  p = get_jumpin(z, 20);  break;
          case "Đường Môn" : z = 324;  p = get_jumpin(z, 20);  break;
          case "Mao Sơn" : z = 269;  p = get_jumpin(z, 20);  break;
        case "Côn Luân" : z = 054;  p = get_jumpin(z, 20);  break;
        case "Vân Mộng Cốc" : z = 165;  p = get_jumpin(z, 20);  break;
		case "Minh Giáo" : z = 802;  p = get_jumpin(z, 20);  break;
        }
		
		write_user(me, ECHO "Bạn đang trở về Sư Môn……");
		
		if( p )
        {
                x = p / 1000;  y = p % 1000;
	        send_user(me, "%c%c%w%s", 0x5a, 0, 3, "Đang về Sư Môn……");	                
	        me->set_2("travel.z", z);
	        me->set_2("travel.p", p);
	        me->set_2("travel.money", 0);
	        set_effect(me, EFFECT_TRAVEL, 3);
                return 1;
        }
        else
        {
                write_user(me, ECHO "……không hiệu quả");
                return 0;
        }
		return 1;	
	}
	
}	