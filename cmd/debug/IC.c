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
			if( arg2 && !( item = find_any_object(arg2) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				return 1;
			}
			if( item == me )
			{
				write_user(me, ECHO "What Dờ Fắc !");
				return 1;
			}
			if (item->get_equip_type()==0)
			{
                write_user(me, ECHO "What Dờ Fắc !");
                return 1;
			}
	switch ( arg3 )
	{
	case "0":
			item->set_item_color(0);
			item->add_to_user(get_d(item));
			write_user(me, sprintf(ECHO"%s đã trở thành trang bị Bạch Kim", item->get_name() ));
			return 1;
			break;
	case "1":
			item->set_item_color(1);
			item->add_to_user(get_d(item));
			write_user(me, sprintf(ECHO"%s đã trở thành trang bị Lam Kim", item->get_name() ));
			return 1;
			break;
	case "2":
			item->set_item_color(2);
			item->add_to_user(get_d(item));
			write_user(me, sprintf(ECHO"%s đã trở thành trang bị Hoàng Kim", item->get_name() ));
			return 1;
			break;
	case "3":
			item->set_item_color(3);
			item->add_to_user(get_d(item));
			write_user(me, sprintf(ECHO"%s đã trở thành trang bị Tử Kim", item->get_name() ));
			return 1;
			break;
	case "4":
			item->set_item_color(4);
			item->add_to_user(get_d(item));
			write_user(me, sprintf(ECHO"%s đã trở thành trang bị Lục Kim", item->get_name() ));
			return 1;
			break;		
	}		
		
	return 1;
} 