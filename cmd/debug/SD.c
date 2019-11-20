
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who,map,ben;

        if( is_player(me) ) 
        {
                notify( "Bạn không đủ quyền hạn." );
		return 1;
        }

	if( !arg ) 
	{
                notify( "Bạn muốn giết người nào ?" );
                return 1;
	}

        if( !( who = find_any_char(arg) ) )
        {
                notify( "Không tìm thấy người này." );
                return 1;
        }
        if( who == me )
        {
                notify( "Bạn không thể tự giết chính mình." );
		return 1;
        }
		if ( who->is_die() )
		{
			write_user(me, ECHO"Đối phương đã chết rồi.");
			return 1;
		}
		map = get_map_object(get_z(who));	
		ben = new("/npc/event/loithan");
        if ( map )
		{
			tell_user( me, HIR "Bạn đã tấn công " + who->get_name() + " !" );
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 25163, 1, OVER_BODY, PF_ONCE );
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 25164, 1, OVER_BODY, PF_ONCE );
			CHAR_DIE_D->is_enemy_die( ben, who, who->get_hp() );
		}
		else
		{
			if ( !who->is_user() ) 
			{
			tell_user( me, HIR "Bạn đã tấn công " + who->get_name() + " !" );
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 25163, 1, OVER_BODY, PF_ONCE );
			send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 25164, 1, OVER_BODY, PF_ONCE );
			CHAR_DIE_D->is_enemy_die( ben, who, who->get_hp() );
			}
		}
        return 1;
}
