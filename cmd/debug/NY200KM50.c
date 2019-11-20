
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
		"sys/sys/test_db"->add_yuanbao(who,48000);	
		who->add_save("tienxu",300);
		who->add_save("diemnapknb",20);	
	log_file("napknb.txt", sprintf("%s : %s (%d) đã nạp %d Kim Bảo cho người chơi %s có số id %d trị giá 200k\n", short_time(time()), me->get_name(), me->get_number(), 4800, who->get_name(), who->get_number() ));	
	tell_user(me, sprintf("%s (%d) đã nhận được 4800 Kim Nguyên Bảo", who->get_name(), who->get_number()));
	tell_user(who, "Bạn đã nạp thành công 4800 Kim Nguyên Bảo và nhận được 20 điểm tích lũy");
        return 1;
}
