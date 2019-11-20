#include <ansi.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
        int z, x, y, p, i;
	string *cmd = ({ "", "", "", "", "", "", "", "" });
        if( is_player(me) ) 
        {
                notify( "Không đủ quyền." );
		return 1;
        }

        if( !arg )
        {
        	for (i=0;i<8;i++)
        		cmd[i] = sprintf("go2map %d 1\n", 10+i*10);
        	send_user( me, "%c%s", ':', "Ngài muốn tới bản đồ nào?\n"
        		ESC "Tề Quốc\n" + cmd[0] +
        		ESC "Hàn Quốc\n" + cmd[1] +
        		ESC "Triệu Quốc\n" + cmd[2] +
        		ESC "Ngụy Quốc\n" + cmd[3] +
        		ESC "Tần Quốc\n" + cmd[4] +
        		ESC "Sở Quốc\n" + cmd[5] +
        		ESC "Yên Quốc\n" + cmd[6] +
        		ESC "Chu Quốc\n" + cmd[7] +
        		ESC "Rời khỏi\nCLOSE\n");        		        		
		return 1;
        }
        else if( sscanf( arg, "%d %d,%d", z, x, y ) == 3 )
		p = get_valid_xy(z, x, y, IS_CHAR_BLOCK);
        else if( sscanf( arg, "%d %d", z, p ) == 2 )
                p = get_jumpin(z, p);
        else
        {
                z = to_int(arg);
                p = get_jumpin(z, -1);
        }

        if( p )
        {
                x = p / 1000;  y = p % 1000;

                me->set_login_flag(2);    // 跳转保护
                set_invisible(me, 1);
                set_effect(me, EFFECT_USER_LOGIN, 4);

                me->add_to_scene(z, x, y, 3);

                tell_user( me, "Ngài đi tới: %d (%d, %d)。", z, x, y );
		return 1;
        }
        else 
        {
                notify( "Ngài không được tới bản đồ kia." );
		return 1;
        }
}
