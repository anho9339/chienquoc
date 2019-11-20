
#include <ansi.h>

// 函数: 命令处理
int main( object me, string arg )
{
        object who;
        string name, id;

        if( userp(me) && is_player(me) ) 
        {
                notify( "Người chơi không thể sử dụng." );
		return 1;
        }

	if( !arg ) 
	{
                notify( "Bạn muốn làm gì?" );
                return 1;
	}

        name = sprintf( NAME_LEFT "%s" NAME_RIGHT, me->get_name() );

	if( arg[0] == '#' && ( arg[1] < '0' || arg[1] > '9' ) )
	{
	        arg = arg[1..<1];

                USER_D->gm_channel( sprintf( HIY "%s%s", name, arg ) );
	}
	else if( arg[0] == '*' )
	{
	        arg = arg[1..<1];

                if( sscanf( arg, "%s %s", arg, id ) == 2 )
                {
                        if( id == "i" || id == "me" )
                        {
                                who = me;
                        }
                        else if( !( who = find_char(id) ) )
                        {
                                notify( "Không tìm thấy người này." );
	        	        return 1;
                        }
                        arg = EMOTE_D->do_emote(me, name, arg, who);
                }
                else    arg = EMOTE_D->do_emote(me, name, arg, 0);

                if( !arg ) return 1;

                USER_D->gm_channel( HIY + arg );
	}
	else    USER_D->gm_channel( sprintf( HIY "%s: %s", name, arg ) );

        return 1;
}
