
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
	object who;
        int i, size, a1, a2, a3, a4;
        if( is_player(me) ) 
        {
                notify( "Ngươi không đủ quyền hạn" );
		return 1;
        }
        if( arg && !( who = find_any_char(arg) ) )
        {
                notify( "Không tìm thấy người này" );
		return 1;
        }
		else if ( arg==0 )
		{
			return 1;
		}
			
	if ( !who->have_title("Y102") )
	{
		who->add_title("Y102");	
		who->show_title("Y102");		
	tell_user(me, sprintf("%s (%d) đã nhận được danh hiệu Sứ giả sự kiện", who->get_name(), who->get_number()));
	tell_user(who, "Bạn đã nhận được danh hiệu Sứ giả sự kiện");
	}
	else
	{
		write_user(me, ECHO"Đối phương đã có danh hiệu này rồi !");
	}	
        return 1;
}
