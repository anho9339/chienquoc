#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <city.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() {return 999 ;}
int get_item_value_2() {return 888 ;}
int get_item_number() {return 10001022 ;}
int get_item_color() {return 1 ;}


// 函数：构造处理
void create()
{
        set_name("Nhân Khí Vương");
        set_picid_1(4904);
        set_picid_2(4904);
        set_value(150000);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Thời cổ đại lưu truyền một loại dược tên Nhân Khí Vương tượng người gỗ \n Khi Nhân Khí thấp hơn 1000, sử dụng có thể giúp bang phái hồi lại 1000 chân khí. Thời gian hồi 2 giây."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( !sizeof(who->get_org_name()) )
	{
		send_user(who,"%c%s",'!',"Ngươi không có bang phái!");
		return 0;	
	}
	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"Nhân Khí Vương chỉ có thành viên bang phái mới có thể dùng.");
		return 0;	
	}
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("Sử dụng đạo cụ bang phái của ngươi sẽ tăng 1000 điểm Nhân Khí, ngươi có muốn sử dụng ko?\n"ESC"Xác Nhận\nuse ! %x#\n"ESC"Hủy Bỏ",getoid(item))); 
	return 0;
}

string get_loop_desc(object me)
{
	return "Sử dụng khiến cho bang phái ngươi gia tăng 1000 nhân khí.";
}
// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	object org;

	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"Nhân Khí Vương chỉ có thành viên bang phái mới sử dụng được. ");
		return 0;	
	}
	if ( gone_time(who->get("use0027")) <= 2 )
	{
		send_user(who,"%c%s",'!',"Không được sử dụng thường xuyên!");
		return 0;	
	}
	who->set("use0027",time());
	org = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
	if ( !org )
		return 0;
	if ( org->get_favour() >= 1000 )
	{
		send_user(who,"%c%s",'!',"Xin lỗi, bang ngươi không cần sử dụng nữa.");
		return 0;	
	}
	org->add_favour(1000);
	org->save();
	return 1;
}