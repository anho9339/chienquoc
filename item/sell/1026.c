#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <city.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() {return 999 ;}
int get_item_value_2() {return 888 ;}
int get_item_number() {return 10001021 ;}
int get_item_color() {return 1 ;}


// 函数：构造处理
void create()
{
        set_name("Định Bang Thần Châm");
        set_picid_1(3562);
        set_picid_2(3562);
        set_value(150000);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Thời cổ đại lưu truyền một loại châm thần bí. \n Khi Ổn Định thấp hơn 1000, sử dụng có thể giúp bang phái hồi lại 1000 độ Ổn Định. Thời gian hồi 2 giây."; 
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
		send_user(who,"%c%s",'!',"Chỉ có thành viên bang phái mới có thể dùng.");
		return 0;	
	}
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("Sử dụng đạo cụ bang phái của ngươi sẽ tăng 1000 điểm Ổn Định, ngươi có muốn sử dụng ko?\n"ESC"Xác Nhận\nuse ! %x#\n"ESC"Hủy Bỏ",getoid(item))); 
	return 0;
}

string get_loop_desc(object me)
{
	return "Sử dụng tăng Ổn Định bang phái thêm 1000 điểm.";
}
// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	object org;

	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"Chỉ có thành viên bang phái mới có thể dùng.");
		return 0;	
	}
	if ( gone_time(who->get("use0026")) <= 2 )
	{
		send_user(who,"%c%s",'!',"Không được sử dụng thường xuyên!");
		return 0;	
	}
	who->set("use0026",time());
	org = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
	if ( !org )
		return 0;
	if ( org->get_stable() >= 1000 )
	{
		send_user(who,"%c%s",'!',"Xin lỗi, bang ngươi không cần sử dụng nữa.");
		return 0;	
	}
	org->add_stable(1000);
	org->save();
	return 1;
}