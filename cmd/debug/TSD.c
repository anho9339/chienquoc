#include <npc.h>
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

// 函数：命令处理
int main( object me, string arg )
{
	object who, item;
	string result,arg2;
        int i, size, a1, a2, a3, a4, p, diem;
        if( is_player(me) ) 
        {
                notify( "Ngươi không đủ quyền hạn" );
		return ;
        }
		if( !arg ) return 1;
		if( sscanf(arg, "%s %d", arg2, diem) == 2 )
		{
			if( arg2 && !( who = find_any_char(arg2) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				return 1;
			}
		else if ( arg==0 )
		{
			return 1;
		}
        if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang đối phương không đủ 1 chỗ trống" );
		return ;
		}
		item = new("item/91/9167");	
		p = item->move2(who,-1);
		item->set_amount(diem);
		item->add_to_user(p);
			
	tell_user(me, sprintf("%s (%d) đã nhận được %d Tử Sâm Đơn", who->get_name(), who->get_number(), diem));
	tell_user(who, sprintf("Bạn đã nhận được %d Tử Sâm Đơn", diem ));
	}
        return 1;
   }
