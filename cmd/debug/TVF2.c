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
			if(USER_INVENTORY_D->get_free_count(who) < 1)
			{
				notify( "Hành trang đối phương không đủ 1 chỗ trống" );
			return 1;
			}
	switch ( arg3 )
	{
	case "2":
			item = new("item/01/0007");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;
	case "3":
			item = new("item/01/0008");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;
	case "4":
			item = new("item/01/0009");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;
	case "5":
			item = new("item/01/0010");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;		
	case "6":
			item = new("item/01/0011");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;
	case "7":
			item = new("item/01/0012");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;
	case "8":
			item = new("item/01/0013");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;
	case "9":
			item = new("item/01/0014");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;
	case "10":
			item = new("item/01/0015");	
			p = item->move2(who,-1);
			item->add_to_user(p);
			write_user(me, sprintf(ECHO"%s(%d) đã nhận được %s", who->get_name(), who->get_number(), item->get_name() ));
			send_user(who,"%c%s",';', sprintf("Bạn đã nhận được %s",item->get_name()));
			return 1;
			break;		
	}		
		
	return 1;
} 