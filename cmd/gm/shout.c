
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        string result;

        if( is_player(me) ) 
        {
                notify( "Bạn không đủ quyền。" );
		return 1;
        }

	if( !arg || arg == "" ) 
	{
                notify( "Bạn muốn nói gì？" );
                return 1;
	}

        result = sprintf( HIY "%s hét lớn：%s", me->get_name(), arg );
        USER_D->user_channel(result);

        return 1;
}
