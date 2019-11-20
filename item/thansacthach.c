#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 400 ;}
int get_item_value_2() {return 400 ;}

// 函数：构造处理
void create()
{
        set_name("Thần Sắc Thạch");
		set_picid_1(4109);
        set_picid_2(4109);
		set_level(0);
        set_value(5000);
		//set_no_give(1);		
     //   set_no_sell(1);
	//	set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me  ) 
{		
		object item=this_object();
	string desc;
	desc = "Một viên đá thần kì đa sắc màu. Dùng để đổi màu Cánh hoặc Phi Phong.";
	if (item->get_lock_time()==0)
	{
		desc+="\n"+"(Sử dụng trong 14 ngày)";
	}
	return desc;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}


int get_use_effect_callout( object me,object gift , object item ) 
{
	string arg;
	
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time()+14*24*60*60);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Trang bị đã quá hạn.");
		return 0;		
	}
	
	"cmd/user/doimau"->main(me,arg);
	return 0;
}
