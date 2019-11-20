
#include <ansi.h>

string status_color( int num, int max );

// 函数：命令处理
int main( object me, string arg )
{
        object who;
        string arg2;
        int time, i;

        if( is_player(me) )
        {
                notify( "Ngươi không đủ quyền." );
		return 1;
        }
	if (sscanf(arg, "%s %d", arg2, time)!=2) return 1;
	if (time<0) return 1;
        if( !( who = find_player(arg2) ) )
        {
                notify( "Không tìm thấy đối tượng." );
		return 1;
        }
	i = gone_time( who->get_login_time() );
	if ( who->get_double_time()< i + who->get_game_time())
	{
		who->set_double_time(i+who->get_game_time()+time*3600);
	}
	else
		who->set_double_time(who->get_double_time()+time*3600);
	send_user( who, "%c%c%c%w%c", 0x51, 1, 1,0001, 0 );
	send_user( who, "%c%c%c%w%w%c", 0x51, 1, 2, 0001, 1, 0 );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Viện Trợ trò chơi" );
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Thời Gian Nhân Đôi" );
	"/sys/task/task"->send_task_intro(who, 1, 1, 1);
	if (me==who) tell_user(me, "Ban đã tăng %d thời gian nhân đôi cho bản thân.", time);
	else
	{
		tell_user(me, "Ngài tặng %s thêm %d tiếng nhân đôi.", who->get_name(), time);
		tell_user(who, "%s tặng cho ngài %d tiếng nhân đôi.", me->get_name(), time);
	}
        return 1;
}

