
#include <equip.h>

// 函数:命令处理
int main( object me, string arg )
{
        object *inv, obj, who = me;
        string str, result = "";
        int len, i, size;

        if( is_player(me) ) 
        {
                notify( "Bạn không đủ quyền hạn." );
		return 1;
        }

        if( arg && !( who = find_any_char(arg) ) ) 
        {
                notify( "Không tìm thấy người này." );
		return 1;
        }

        tell_user( me, who->get_name() + ": Vật phẩm trên người:" );
        if( objectp( obj = who->get_equip(HEAD_TYPE) ) ) tell_user( me, 
                sprintf( "Nón: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );
        if( objectp( obj = who->get_equip(NECK_TYPE) ) ) tell_user( me, 
                sprintf( "Hạng Liên: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );
        if( objectp( obj = who->get_equip(WEAPON_TYPE) ) ) tell_user( me, 
                sprintf( "Vũ Khí: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );
        if( objectp( obj = who->get_equip(ARMOR_TYPE) ) ) tell_user( me, 
                sprintf( "Y Phục: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );
        if( objectp( obj = who->get_equip(WAIST_TYPE) ) ) tell_user( me, 
                sprintf( "Yêu Đới: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );
        if( objectp( obj = who->get_equip(BOOTS_TYPE) ) ) tell_user( me, 
                sprintf( "Giày: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );
        if( objectp( obj = who->get_equip(HAND_TYPE) ) ) tell_user( me, 
                sprintf( "Pháp Bảo: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );
		if( objectp( obj = who->get_equip(BACK_TYPE) ) ) tell_user( me, 
                sprintf( "Trang bị vai: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );		
		if( objectp( obj = who->get_equip(FASHION_TYPE) ) ) tell_user( me, 
                sprintf( "Ngoại Trang: (%d) %s %x#", get_d(obj), obj->get_name(), getoid(obj) ) );		

        if( !sizeof_inventory(who, 1, MAX_CARRY*4) ) 
        {
                tell_user( me,  "%s ở hành trang không có vật phẩm nào.", who->get_name() );
		return 1;
        }

        inv = all_inventory(who, 1, MAX_CARRY*4);
        size = sizeof(inv);
        for( i = 0, len = 0; i < size; i ++ )
        {
                if( !inv[i]->is_combined() )
                        str = sprintf( "(%d) %s %x#", get_d( inv[i] ), inv[i]->get_name(), getoid( inv[i] ) );
                else    str = sprintf( "(%d) %s:%d %x#", get_d( inv[i] ), inv[i]->get_name(), inv[i]->get_amount(), getoid( inv[i] ) );
                len += strlen(str) + 2;
                if( len >= OUTPUT_WIDTH )
                {
                        len = strlen(str);
                        result = sprintf( "%s\n%s ", result, str );
                }
                else    result = sprintf( "%s%s ", result, str );
        }
        tell_user( me, "%s: Vật phẩm ở hành trang:\n%s", who->get_name(), result );

        return 1;
}
