
#include <ansi.h>

#define SUMMON_LOG      "gm/summon.txt"         // 召唤日志文件

// 函数：命令处理
int main1( object me, string arg )
{
	object who;
        int z, x, y, x0, y0, p;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

	if( !arg ) 
        {
                send_user( me, "%c%c%d%s", '?', 16, 10, sprintf( "邀请人物过来。\n\n请输入对方的数字ＩＤ：\n"
                        ESC "summon %%s\n" ) );
                return 1;
        }

	if( !( who = find_any_char(arg) ) )
        {
                notify( "您无法找到这个人。" );
		return 1;
        }
        else if( !clonep(who) )
        {
                notify( "无法召唤这个人物。" );
		return 1;
        }
        else if( who == me )
        {
                notify( "您不能自己抓自己。" );
		return 1;
        }

        z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

        if( p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK) )
        {
                x = p / 1000;  y = p % 1000;
                who->add_to_scene( z, x, y, get_front_xy(x, y, x0, y0), 40971, 0, 40971, 0 );
                tell_user( me, HIY "您邀请%s来这儿。", who->get_name() );
                write_user( who, HIY "%s邀请您来这儿。", me->get_name() );

                if( userp(who) ) log_file( "gm/gm3.dat", sprintf( "%s %s 邀请 %s(%s)到 %d (%d,%d)。\n", 
                        short_time(), me->get_id(), who->get_name(), who->get_id(), z, x, y ) );

		return 1;
        }
        else 
        {
                notify( who->get_name() + "来不了您这里。" );
		return 1;
        }

        return 1;
}

int main( object me, string arg )
{
	int i,size;
	string *player;
	
        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }
        player = explode(arg,",");
        if ( (size=sizeof(player)) == 0 )
        {
        	main1(me,arg);	
        	return 1;
        }
        for(i=0;i<size;i++)
        {
        	main1(me,player[i]);
        }
        return 1;
}