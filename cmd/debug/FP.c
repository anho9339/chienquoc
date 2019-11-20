
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
	object who, item;
        int i, size, a1, a2, a3, a4, p;
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
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang đối phương không đủ 1 chỗ trống" );
		return 1;
		}
		item = new("/item/zzz/fp");
		p = item->move2(who,-1);
		item->add_to_user(p);			
	log_file("tuiquaevent.txt", sprintf("%s (%d) đã chuyển cho %s (%d) Túi quà Event\n", me->get_name(), me->get_number(), who->get_name(), who->get_number() ));	
	tell_user(me, sprintf("%s (%d) đã nhận được Túi quà Event", who->get_name(), who->get_number()));
	tell_user(who, "Bạn đã nhận được Túi quà Event");	
        return 1;
}
