#include <ansi.h>
// 函数：命令处理
int main( object me, string arg )
{
        object item,*inv;
		string ben,ben1;
	int i,nhat;
        if( is_player(me) ) 
        {
                notify( "Bạn không đủ quyền hạn." );
		return 1;
        }

	if( !arg ) return 1;
	if( arg==0 ) return 1;
	if ( sscanf(arg, "%s %s", ben, ben1)==2 )
	{
        if( !( item = find_any_object(ben) ) )
        {
                notify( "Không tìm thấy." );
                return 1;
        }
        if( item == me )
        {
                notify( "Bạn muốn gì ?" );
		return 1;
        }
		switch(ben1)
		{
			case "kim":
			item->set_nh(1);
			item->add_to_user(get_d(item));
			tell_user( me, "Thuộc tính ngũ hành của %s là "HIY"Kim.", item->get_name() );
			break;
			case "moc":
			item->set_nh(2);
			item->add_to_user(get_d(item));
			tell_user( me, "Thuộc tính ngũ hành của %s là "HIG"Mộc.", item->get_name() );
			break;
			case "tho":
			item->set_nh(3);
			item->add_to_user(get_d(item));
			tell_user( me, "Thuộc tính ngũ hành của %s là "WHT"Thổ.", item->get_name() );
			break;
			case "thuy":
			item->set_nh(4);
			item->add_to_user(get_d(item));
			tell_user( me, "Thuộc tính ngũ hành của %s là "HIC"Thuỷ.", item->get_name() );
			break;
			case "hoa":
			item->set_nh(5);
			item->add_to_user(get_d(item));
			tell_user( me, "Thuộc tính ngũ hành của %s là "HIR "Hoả.", item->get_name() );
			break;
		}
	}
        return 1;
}
