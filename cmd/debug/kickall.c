
#include <ansi.h>
#include <cmd.h>
#include <city.h>
int tatgame();
// 函数：命令处理
int main( object me, string arg )
{
	object * user, who;
        int z, x, y, x0, y0, p, i, size, number;

        if( is_player(me) ) 
        {
                notify( "Không đủ quyền hạn." );
		return 1;
        }
if ( arg==0 )
{
        if( !arrayp( user = USER_D->get_user() ) ) return 1;
        user -= ({ me });
        size = sizeof(user);
        if (size==0) 
        {
        	tell_user( me, HIY "Không có người chơi nào trực tuyến." );
        	return 1;
        }
	number = 0;
	for (i=0;i<size;i++)
	{
		who = user[i];
		if (!who) continue;	
		who->save();
		QUIT_CMD->main( who, "" );
		number ++;
	}	       
		tell_user( me, HIY "Bạn đã đuổi "+number+" người chơi ra khỏi trò chơi." );
        return 1;
}
if ( arg=="tg" )
{
	"cmd/sys/saveall"->main(me,"");
	"cmd/debug/kickall"->main(me,0);
		call_out("tatgame",5);
		
}	
	return 1;
}
int tatgame()
{
        USER_D->user_channel( HIR "Tắt trò chơi..." );

        USER_D->save_all_data(); 
        "/sys/sys/count"->hour_callout();

        shutdown(0);

        return 1;
}
