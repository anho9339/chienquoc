#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit OFFICER;
int host_type;

// 函数：获取人物造型
int get_char_picid() { return 650; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// 函数：构造处理
void create()
{
	object me=this_object();
        set_name("Thảo Nghịch Tướng Quân");
        set_2( "noichuyen", ([
                 "chaomung"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        setup();
	host_type = MAIN_D->get_host_type();
}

void do_look(object who)
{
	int id;
	object me=this_object();

	id = getoid(me);
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "Bản sao chưa được mở ra");
		return;
	}	
	if (who->get_level()>60 && !who->get_vip() )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Thành Kiều là nơi mà bọn phản loạn nghịch tặc phản quốc ẩn nấu, ta đang chiêu mộ dũng sĩ để thu thập bọn nghịch tặc, ngươi muốn vào không ?\n"ESC"Thành Kiều quân doanh là gì ?\nnoichuyen %x# chaomung.100\n"ESC"Quy tắc Quân doanh?\nnoichuyen %x# chaomung.200\n"ESC"Sử dụng Hạt Mè Khai Môn tiến vào Thành Kiều\nnoichuyen %x# chaomung.300\n"ESC"Rời khỏi",id,id,id));
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Thành Kiều là nơi mà bọn phản loạn nghịch tặc phản quốc ẩn nấu, ta đang chiêu mộ dũng sĩ để thu thập bọn nghịch tặc, ngươi muốn vào không ?\n"ESC"Thành Kiều quân doanh là gì ?\nnoichuyen %x# chaomung.100\n"ESC"Quy tắc Quân doanh?\nnoichuyen %x# chaomung.200\n"ESC"Tiến vào Thành Kiều\nnoichuyen %x# chaomung.300\n"ESC"Rời khỏi",id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy, level;
       	object who, item, item2, map;
       	string legend, legend2 ;
        who = this_player();
        flag = to_int(arg);
        level = who->get_level();
        who->set_time( "noichuyen",  0);
        id = getoid(me);
	if (MAIN_D->get_host_type()==6012)
	{
		send_user(who, "%c%s", '!', "Bản sao chưa được mở ra");
		return;
	}        
        switch(flag)
        {
        case 100:
        	if (level>60 && !who->get_vip())
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Thành Kiều quân doanh hội tụ rất nhiều quái vật cao cấp, nghe nói trang bị rớt ra từ quái vật cũng là cao cấp !\n"ESC"Quy tắc Quân doanh?\nnoichuyen %x# chaomung.200\n"ESC"Sử dụng Hạt Mè Khai Môn tiến vào Thành Kiều\nnoichuyen %x# chaomung.300\n"ESC"Rời khỏi",id,id,));
		else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Thành Kiều quân doanh hội tụ rất nhiều quái vật cao cấp, nghe nói trang bị rớt ra từ quái vật cũng là cao cấp !\n"ESC"Quy tắc Quân doanh?\nnoichuyen %x# chaomung.200\n"ESC"Tiến vào Thành Kiều\nnoichuyen %x# chaomung.300\n"ESC"Rời khỏi",id,id,));
        	break;
        case 200:
        	if (level>60 && !who->get_vip())
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Thành Kiều chỉ cho phép tối đa 5 người trong 1 nhóm tiến vào, tất nhiên một nhóm sẽ vào Thành Kiều khác với nhóm khác, Thành Kiều yêu cầu nhân vật cấp 40 - 60 và Lệnh PretKuzl mới có thể vào !\n"ESC"Sử dụng Hạt Mè Khai Môn tiến vào Thành Kiều\nnoichuyen %x# chaomung.300\n"ESC"Rời khỏi",id,));
		else
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Thành Kiều chỉ cho phép tối đa 5 người trong 1 nhóm tiến vào, tất nhiên một nhóm sẽ vào Thành Kiều khác với nhóm khác, Thành Kiều yêu cầu nhân vật cấp 40 - 60 và Lệnh PretKuzl mới có thể vào !\n"ESC"Tiến vào Thành Kiều\nnoichuyen %x# chaomung.300\n"ESC"Rời khỏi",id,));
        	break; 
        case 300:        	
        	if (level>60 && !who->get_vip() )
        	{
        		item = present("Hạt Mè Khai Môn", who, 1, MAX_CARRY);
        	}
        	
			if ( who->get_level() < 40 || (who->get_level() > 60 && !who->get_vip()) )
		{
		   item2 = present("Lệnh PretKuzl", who, 1, MAX_CARRY);
		}
		
		if ( who->get_level() < 40 && !item2 || (who->get_level() > 60 && !item && !who->get_vip()) )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Nhân vật cấp 40 - 60 có thể tiến vào Thành Kiều. Nhưng nếu cấp bậc đã trên 60 phải sử dụng Hạt Mè Khai Môn mới có thể tiến vào.\n"));
			return ;	
		}     
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Phải lập tổ đội mới được vào Thành Kiều.\n"));
			return;
		}
		if (level>60 && !who->get_vip() && item && item2 )
		{
			send_user( who, "%c%c%s", 0x59, 1, sprintf("Sử dụng "HIR "Hạt Mè Khai Môn"NOR " và "HIB "Lệnh PretKuzl"NOR " tiến vào Thành Kiều.\n"
	                        ESC "%c\n"ESC"noichuyen %x# chaomung.4\n"
				, 1, getoid(me) ) );				
			return;
		}
		// Check coi có Lệnh PK ko
         item2 = present("Lệnh PretKuzl", who, 1, MAX_CARRY);        	
		if ( !item2 )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Phải sử dụng thêm Lệnh PretKuzl mới có thể tiến vào Thành Kiều. Lệnh PretKuzl có thể mua tại tạp hóa Chu Quốc.\n"));
			return ;	
		} 
          legend2 = sprintf("进入副本使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), item2->get_name(), "/sys/item/item"->get_pawn_save_string(item2), 1, item2->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend2);
	//	item2->remove_from_user();
	//	destruct(item2);	
	    item2->add_amount(-1);
		
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_BARRACK);
        		if ( !map )	//创建副本
        		{
        			map = "sys/copy/barrack"->new_copy(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance");
//        		who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 4, "Truyền tống……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 4);
        	}
		break;
        case 4:        	
        	item = present("Hạt Mè Khai Môn", who, 1, MAX_CARRY);        	
		if ( !item )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Nhân vật cấp 40 - 60 có thể tiến vào Thành Kiều. Nhưng nếu cấp bậc đã trên 60 phải sử dụng Hạt Mè Khai Môn mới có thể tiến vào.\n"));
			return ;	
		}
		
        item2 = present("Lệnh PretKuzl", who, 1, MAX_CARRY);        	
		if ( !item2 )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Phải sử dụng thêm Lệnh PretKuzl mới có thể tiến vào Thành Kiều. Lệnh PretKuzl có thể mua tại tạp hóa Chu Quốc.\n"));
			return ;	
		} 
		
		tId = who->get_team_id();
		if (!tId) 
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("Thảo Nghịch Tướng Quân：\n    Phải lập tổ đội mới được vào Thành Kiều.\n"));
			return;
		}
		legend = sprintf("进入副本使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend);
		// Nếu dùng hàm này sẽ mất hết vp 
	/*	item->remove_from_user();
	destruct(item);	  */
          item->add_amount(-1);
		  
        legend2 = sprintf("进入副本使用 %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", who->get_name(), who->get_number(), get_ip_name(who), who->get_id(), me->get_name(), item2->get_name(), "/sys/item/item"->get_pawn_save_string(item2), 1, item2->get_user_id(), get_z(who), get_x(who), get_y(who) );
		"/sys/user/cmd"->log_item(legend2);
	//	item2->remove_from_user();
	//	destruct(item2);
          item2->add_amount(-1);	
		
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_BARRACK);
        		if ( !map )	//创建副本
        		{
        			map = "sys/copy/barrack"->new_copy(me,who);
        		}
        		if ( !map )
        			return ;
        		nXy = map->get("entrance");
//        		who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
	        	send_user(who, "%c%c%w%s", 0x5a, 0, 4, "Truyền tống……");
		        who->set_2("travel.z", map->get_id());
		        who->set_2("travel.p", nXy[0]*1000+nXy[1]);
		        set_effect(who, EFFECT_TRAVEL, 4);
        	}
		break;		
	}
}


