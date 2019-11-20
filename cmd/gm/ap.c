
#include <ansi.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who = me;
        string type, result;

        if( is_player(me) ) 
        {
                notify( "Bạn không đủ quyền。" );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "Không thấy người này。" );
		return 1;
        }

        if( who->is_npc() )
                result = sprintf( "Quân đội：%s\n", who->get_name() );
        else    result = sprintf( "Quân đội：%s(%d)\n", who->get_name(), who->get_number() );

        switch( who->get_army_type() )
        {
      default : type = "Bộ binh";  break;
       case 1 : type = "Cung thủ";  break;
       case 2 : type = "Xe binh";  break;
        }

        result += sprintf( "Vũ khí：%-4s  Số lượng：%4d  Trang bị：%4d  Đào tạo：%4d  Tinh thần：%4d  Điều động：%4d", type, 
                who->get_army_amount(), who->get_army_armor(), who->get_army_train(), 
                who->get_army_morale(), who->get_army_power() );

        tell_user(me, result);

        return 1;
}
