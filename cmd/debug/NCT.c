#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main(object me, string arg) 
{

    int p, cap, chiso, i;
	string result,arg2,arg3,ngoc;
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
                write_user(me, ECHO "Không tìm thấy vật phẩm này !");
				return 1;
			}
		if( !item->is_equip() )
		{
			write_user(me, ECHO "Chỉ có thể sửa đổi chỉ số của trang bị và vũ khí !");
			return 1;
		}
			if( arg3 && !( who = find_any_char(arg3) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				return 1;
			}	
			item->set_product_id(who->get_name());
			item->add_to_user(get_d(item));
			write_user(me,ECHO"Vật phẩm "+HIY+item->get_name()+ECHO+" đã thêm vào "HIG"Người chế tác : "+HIC+who->get_name()+ECHO+".");
		
	return 1;
} 