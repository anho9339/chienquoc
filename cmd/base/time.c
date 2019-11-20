
string get_time_string( int time );

// 函数:命令处理
int main( object me, string arg )
{
        int time = gone_time( me->get_login_time() );
        string abc = "12345";
        if ( arg )
        {
        	tell_user( me, "Đưa vào thời gian: %s.", short_time( to_int(arg) ) );	
        	return 1;
        }

        tell_user( me, "Thời gian hiện tại: %s.", short_time( time() ) );
        tell_user( me, GAME_NAME " đã chạy được %s.", get_time_string( uptime() ) );
        tell_user( me, "Hiện tại " GAME_NAME " đang hoàn thành: %s, thời gian trực tuyến: %s.",
                get_time_string( me->get_game_time() + time ), get_time_string( me->get_online_time() ) );
	if (me->get_double_time()-time-me->get_game_time()>0)
		tell_user( me, "Thời gian nhân đôi kinh nghiệm đóng băng còn %d giây",  me->get_double_time()-time-me->get_game_time() );
        tell_user( me, "Sinh nhật của bạn: %s." ,short_time( me->get_birthday() ) );
        return 1;
}

// 函数:获取时间字串
string get_time_string( int time )
{
        int day, hour, min, sec;
        string result = "";

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;   time /= 60;
        hour = time % 24;  time /= 24;
        day = time;

        if( day ) result += sprintf( " %d Ngày", day );
        if( hour ) result += sprintf( " %d Giờ", hour );
        if( min ) result += sprintf( " %d Phút", min );
        result += sprintf( " %d Giây", sec );

        return result;
}

// 函数:获取时间字串(简短)
string get_time_string_2( int time )
{
        int min, sec;
        string result = "";

        time = abs(time);

        sec = time % 60;   time /= 60;
        min = time % 60;

        if( min ) result += sprintf( " %d Phút", min );
        result += sprintf( " %d Giây", sec );

        return result;
}
