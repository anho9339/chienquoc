#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <city.h>

inherit COMBINED;
inherit ITEM;

int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}
//int get_item_number() {return 10001021 ;}
int get_item_color() {return 1 ;}


// 函数：构造处理
void create()
{
        set_name("Bang Hội Quy Mô Châm");
        set_picid_1(3562);
        set_picid_2(3562);
        set_value(180);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng sẽ tăng Quy Mô Bang Phái thêm 1 điểm。"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	if ( !sizeof(who->get_org_name()) )
	{
		send_user(who,"%c%s",'!',"Ngươi chưa gia nhập Bang, không thể sử dụng");
		return 0;	
	}
	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"Ngươi chưa gia nhập Bang, không thể sử dụng");
		return 0;	
	}
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("Sử dụng sẽ tăng Quy Mô Bang Phái thêm 1 điểm, muốn sử dụng không ?\n"ESC"Xác nhận\nuse ! %x#\n"ESC"Huỷ bỏ",getoid(item))); 
	return 0;
}

string get_loop_desc(object me)
{
	return "Sau khi sử dụng gia tăng Quy Mô thêm 1 điểm";
}
// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object who, object item )
{
	object org;

	if( who->get_org_position() < 1 ) 
	{
		send_user(who,"%c%s",'!',"Ngươi chưa gia nhập Bang, không thể sử dụng");
		return 0;	
	}
	if ( gone_time(who->get("use0026")) < 2 )
	{
		send_user(who,"%c%s",'!',"Không nên sử dụng thường xuyên !");
		return 0;	
	}
	org = CITY_ZHOU->get_2( sprintf( "org.%s", who->get_org_name() ) );
	if ( !org )
	{
		send_user(who,"%c%s",'!',"Bang Phái số liệu lầm");
		return 0;	
	}	
	who->set("use0026",time());

	org->add_grade(1);
	org->save();
	return 1;
}