#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

int main(object me, string arg) 
{

    int p, cap, exist, exist2, i, size, iTime;
	string result,arg2,arg3,arg4,*line,*data,username,ten1,ten2,ten3;
    object item, item1, who, *objs, target, map,map1;
	mixed *mixTime;
	iTime = time();
	mixTime = localtime(iTime);	
	//	if ( me->is_user() ) return 1;	
		if( !arg ) return 1;
		if (arg==0) return 1;
		if( sscanf(arg, "%s.%s", arg2, arg3 ) != 2 ) return 1;
		if ( arg2=="?" )
		{
			if( arg3 && !( who = find_any_char(arg3) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nKhông thể tìm thấy người này, hãy chắc chắn rằng người đó đang trực tuyến ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( who==me )
			{
				write_user(me, ECHO "Không thể tự tỷ thý với chính mình !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nKhông thể tự tỷ thý với chính mình ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( !who->is_user() )
			{
				write_user(me, ECHO "Đối phương không phải là người chơi !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nĐối phương hoàn toàn không phải là người chơi ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( who->is_die() )
			{
				write_user(me, ECHO "Đối phương đã tử vong, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nĐối phương đã tử vong, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			}
	/*		map = get_map_object(get_z(me));
			map1 = get_map_object(get_z(who));
			if ( map->get_no_fight() )
			{
				write_user(me, ECHO "Bạn đang ở khu vực an toàn, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nBạn đang ở khu vực an toàn, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( map1->get_no_fight() )
			{
				write_user(me, ECHO "Đối phương đang ở khu vực an toàn, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nĐối phương đang ở khu vực an toàn, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			}  */
			if( !inside_screen_2(me, who) )
			{
                write_user(me, ECHO "Khoảng cách với đối phương quá xa, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nKhoảng cách với đối phương quá xa, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			} 
			me->set("tythyben",who->get_number());
			write_user(me, ECHO"Bạn đã mời "+HIY+who->get_name()+ECHO+" tỷ thý, xin chờ trả lời !");
			send_user(who,"%c%c%w%s",':',3,5205,"Võ Sư : \n Bạn nhận được lời mời tỷ thý của "+me->get_name()+", bạn đồng ý lời khiêu chiến này không ?\n"
			ESC"Tôi đồng ý \ntythy !."+me->get_number()+"\n"
			ESC"Huỷ bỏ");
			return 1;
		}
		if ( arg2=="!" )
		{
			if( arg3 && !( who = find_any_char(arg3) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nKhông thể tìm thấy người này, hãy chắc chắn rằng người đó đang trực tuyến ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( who==me )
			{
				write_user(me, ECHO "Không thể tự tỷ thý với chính mình !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nKhông thể tự tỷ thý với chính mình ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( !who->is_user() )
			{
				write_user(me, ECHO "Đối phương không phải là người chơi !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nĐối phương hoàn toàn không phải là người chơi ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( who->is_die() )
			{
				write_user(me, ECHO "Đối phương đã tử vong, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nĐối phương đã tử vong, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			}
		/*	map = get_map_object(get_z(me));
			map1 = get_map_object(get_z(who));
			if ( map->get_no_fight() )
			{
				write_user(me, ECHO "Bạn đang ở khu vực an toàn, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nBạn đang ở khu vực an toàn, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			}
			if ( map1->get_no_fight() )
			{
				write_user(me, ECHO "Đối phương đang ở khu vực an toàn, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nĐối phương đang ở khu vực an toàn, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			}    */
			if( !inside_screen_2(me, who) )
			{
                write_user(me, ECHO "Khoảng cách với đối phương quá xa, không thể tỷ thý !");
				send_user(me, "%c%c%w%s", ':', 3, 5205, "Võ Sư : \nKhoảng cách với đối phương quá xa, không thể tỷ thý ! \n"ESC"Xác nhận");
				return 1;
			}
			me->set("tythyben",who->get_number());
		//	ten1 = sprintf("%c+%d,%s=%d%c-", '\t', 0xff0000+246, "Võ Sư", me->get_number(), '\t');
		//	ten2 = sprintf("%c+%d,%s=%d%c-", '\t', 0xffffff, me->get_name(), me->get_number(), '\t');
		//	ten3 = sprintf("%c+%d,%s=%d%c-", '\t', 0xffffff, who->get_name(), who->get_number(), '\t');
		//	CHAT_D->sys_channel(0,sprintf("%s : Cuộc tỷ thý của %s và %s đã bắt đầu.",ten1,ten2,ten3));
			write_user(me,ECHO"Tỷ tỷ đã bắt đầu !");
		//	write_user(me,ECHO"Tỷ tỷ đã bắt đầu !");
			write_user(me,ECHO"Tỷ tỷ đã bắt đầu !");
			write_user(who,ECHO"Tỷ tỷ đã bắt đầu !");
			write_user(who,ECHO"Tỷ tỷ đã bắt đầu !");
		//	write_user(who,ECHO"Tỷ tỷ đã bắt đầu !");
			return 1;
		}	
	return 1;
} 