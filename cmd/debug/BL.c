#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main(object me, string arg) 
{

    int p, cap;
	string result,arg2,arg3;
    object item, item1, who;
		if( is_player(me) ) 
        {
            write_user(me, ECHO "Bạn không đủ quyền hạn !");
			return 1;
        }

		if( !arg ) return 1;
		if (arg==0) return 1;
		if( sscanf(arg, "%s %s", arg2 , arg3 ) != 2 ) return 1;
			if( arg2 && !( who = find_any_char(arg2) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				return 1;
			}
	switch ( arg3 )
	{
	case "yeah":
			if ( get_z(who)!=704 )
			{
			who->set_save("gietnguoi",1);
			who->set_save("vaotu",31*24*3600);
				who->set_login_flag(2); 
                set_invisible(who, 1);
                set_effect(who, EFFECT_USER_LOGIN, 4);
				who->add_to_scene(704, 35, 25);
				send_user( who, "%c%c%w%s", ':', 3, 9963, "Giám Ngục Quan :\nNgươi đã bị G M nhốt vào Tù 1 tháng, hãy cảm nhận !\n"
                        ESC "Xác nhận\nCLOSE\n" );
send_user(me, "%c%s", ';', sprintf("%s (%d) đã bị Nhốt vào tù 1 tháng",who->get_name(), who->get_number() ) );
CHAT_D->rumor_channel( 0, CHAT+sprintf(HIM"Bằng hữu %s (%d) đã bị Gờ Mờ nhốt vào tù 1 tháng !!", who->get_name(), who->get_number() ));			
			return 1; 
			}
			else
			{
				write_user(me, ECHO "Đối phương đang ở trong Nhà ngục !");
				return 1;
			}
			break;
	case "ohno":
				who->delete_save("vaotu");
				who->set_save("gietnguoi",0);
				who->set_login_flag(2); 
                set_invisible(who, 1);
                set_effect(who, EFFECT_USER_LOGIN, 4);
				who->add_to_scene(80, 292, 184);
CHAT_D->rumor_channel( 0, CHAT+sprintf(HIM"Bằng hữu %s (%d) biết ăn năn hối cải nên đã được Gờ Mờ thả ra !!", who->get_name(), who->get_number() ));				
			break;		
	}		
		
	return 1;
} 