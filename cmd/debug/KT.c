
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
	object *user, who, map;
	string *ids = ({ }), id, result, infoitem, infonpc,nhat,ben,ben1="Chưa có",ben2,ben3;
    int i, size, a1, a2, a3, a4, phai, len, flag, gioitinh;
		
        if( is_player(me) ) 
        {
                notify( "Ngươi không đủ quyền hạn" );
		return 1;
        }
        if( arg && !( who = find_any_object(arg) ) )//find_any_char
        {
                notify( "Không tìm thấy" );
		return 1;
        }
		else if ( arg==0 )
		{
			return 1;
		}
	if ( who->is_user() )
	{
		map = get_map_object(get_z(who));
		phai = who->get_fam_name()=="" ? "Vô Môn Phái" : who->get_fam_name();
		nhat = sprintf("%c+%d,%s=%d%c-", '\t', 0x000000, who->get_id(), who->get_number(), '\t');
		ben3 = sprintf("%c+%d,%s=%d%c-", '\t', 0x0c40ff, who->get_name(), who->get_number(), '\t');
		if( who->get_save("nguhanh")==1 ) ben1="Kim";
		else if( who->get_save("nguhanh")==2 ) ben1="Mộc";
		else if( who->get_save("nguhanh")==3 ) ben1="Thổ";
		else if( who->get_save("nguhanh")==4 ) ben1="Thuỷ";
		else if( who->get_save("nguhanh")==5 ) ben1="Hoả";
		result = get_ip_name(who);
		if( !result || result == "" || result == "0" ) return 1;

        user = filter_array( USER_D->get_user(), (: get_ip_name($1) == $2 :), result );
        for( i = 0, size = sizeof(user); i < size; i ++ )
		{
            ben = sprintf("%c+%d,%s=%d%c-", '\t', 0x000000, user[i]->get_id(), user[i]->get_number(), '\t');
			ben2 = sprintf("%c+%d,%s=%d%c-", '\t', 0x000000, user[i]->get_name(), user[i]->get_number(), '\t');
			ids += ({ sprintf( "%s(%d)-%s", ben2, user[i]->get_number(), ben ) });
		}	
        if( size = sizeof(ids) ) 
        {
                result = "Nhân vật có cùng IP :\n";
                for( i = 0, len = 0; i < size; i ++ )
                {
                        len += strlen( ids[i] ) + 2;
                        if( len >= OUTPUT_WIDTH )
                        {
                                len = strlen( ids[i] );
                                result = sprintf( "%s\n%s, ", result, ids[i] );
                        }
                        else    result = sprintf( "%s%s, ", result, ids[i] );
                }     
		
		if ( map ) {
		send_user(me,"%c%s",':',sprintf(HIB"%s "HIR "( %d ) "NOR " : \nKim Bảo: %d , Chiến Tích: %d , Ngân Lượng: %d , \nĐiểm PK: %d , Cống hiến Phái: %d , Đẳng cấp hiện tại: %d ,\nMôn phái hiện tại : %s \nNgũ Hành : %s , Tài khoản : %s ,\nIP hiện tại : %s , Giới tính : %s ,\nID Get : %x# , Chức vụ : %s , Bang phái :  %s , Điểm Nạp KNB :  %d ,\nVị trí hiện tại : %s   --->   %d ( %d, %d ). %s \n"
		ESC"Đã kiểm tra xong...\nCLOSE\n"
		ESC"Rời khỏi\nCLOSE\n",
		ben3,who->get_number(),"sys/sys/test_db"->get_yuanbao(who)/10,
		who->get_save_2("changping.score"),who->get_cash(),who->get_pk(),
		who->get_fam_contribute(),who->get_level(),phai,ben1,nhat,
		get_ip_name(who),who->get_gender() == 1 ? "Nam" : "Nữ",
		getoid(who),get_class(who),who->get_org_name() == "" ? "Chưa có" : who->get_org_name(), who->get_save("diemnapknb"),
		map->get_name(),get_z(who),get_x(who),get_y(who),"\n" + result ));	
		}
		else {
		send_user(me,"%c%s",':',sprintf(HIB"%s "HIR "( %d ) "NOR " : \nKim Bảo: %d , Chiến Tích: %d , Ngân Lượng: %d , \nĐiểm PK: %d , Cống hiến Phái: %d , Đẳng cấp hiện tại: %d ,\nMôn phái hiện tại : %s \nNgũ Hành : %s , Tài khoản : %s ,\nIP hiện tại : %s , Giới tính : %s ,\nID Get : %x# , Chức vụ : %s , Bang phái : %s , Điểm Nạp KNB :  %d ,\nVị trí hiện tại : Bản đồ vô danh   --->   %d ( %d, %d ). %s \n"
		ESC"Đã kiểm tra xong...\nCLOSE\n"
		ESC"Rời khỏi\nCLOSE\n",
		ben3,who->get_number(),"sys/sys/test_db"->get_yuanbao(who)/10,
		who->get_save_2("changping.score"),who->get_cash(),who->get_pk(),
		who->get_fam_contribute(),who->get_level(),phai,ben1,nhat,
		get_ip_name(who),who->get_gender() == 1 ? "Nam" : "Nữ",
		getoid(who),get_class(who),who->get_org_name() == "" ? "Chưa có" : who->get_org_name(), who->get_save("diemnapknb"),
		get_z(who),get_x(who),get_y(who),"\n" + result ));
		}
		}
	}
	else if ( who->is_item() )
	{
		infoitem = sprintf( "Đường dẫn: %O [%d]\n", who, sizeof( children( get_file_name(who) + ".c" ) ) );
		send_user(me,"%c%s",':',sprintf(HIB"%s "HIR "( %x# ) "NOR " : \n%s \n"
		ESC"Đã kiểm tra xong...\nCLOSE\n"
		ESC"Rời khỏi\nCLOSE\n",
		who->get_name(),getoid(who),infoitem ));
	}
	else if ( who->is_npc() )
	{
		infonpc = sprintf( "Đường dẫn: %O [%d]\n", who, sizeof( children( get_file_name(who) + ".c" ) ) );
		send_user(me,"%c%s",':',sprintf(HIB"%s "HIR "( %x# ) "NOR " : \n%s \n"
		ESC"Đã kiểm tra xong...\nCLOSE\n"
		ESC"Rời khỏi\nCLOSE\n",
		who->get_name(),getoid(who),infonpc ));
	}
        return 1;
}
