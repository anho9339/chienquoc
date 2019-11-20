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
        set_name("Truyền Tống Phù");
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
	return "Một viên đá kì quặc. Nghe đồn được phái Mao Sơn sử dụng như 1 lá bùa đầy quyền năng.\n Sử dụng nó giúp người chơi dịch chuyển được khắp nơi trên thất quốc.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object me,object item ) 
{
	string arg;
	
	int i, size, x, y, z, p;	
	//Time
	if (item->get_lock_time()==0) item->set_lock_time(time()+14*24*60*60);
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Hết hạn sử dụng");
		return 0;		
	}
	
	"cmd/user/truyentong"->main(me,arg);
	return 0;
}

// Time
string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 14 ngày]\n ";
	}

	return desc;
}
