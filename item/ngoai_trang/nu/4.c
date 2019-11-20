#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit "/inh/equip/fashion";;

int get_item_value() {return 550 ;}
int get_item_value_2() {return 550 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Đạo Nhân Y (Nữ)");
        set_picid_1(11055);
        set_picid_2(11055);

        set_level(1);
		set_bind(0);
        set_value(100);
        set_max_lasting(35099);
        set_save("nhb",50);
//		set("time_item", 1);

         set("dp+", 200);
        set("pp+", 200);
        set("hp+", 350);
	//	set("hp%+", 50);
		set("mp+", 400);
	//	set("mp%+", 100);
		set("!%+", 500);
		set("?%+", 200);

        setup();

        set_gender(2);

		set_fashion_code(55);
}

// 函数：获取描述
string get_desc()
{
        return "★★★★★★★★★";
}

// 函数：使用效果
int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

// 函数：使用效果(在线更新)
int get_equip_effect_callout( object me, object item )
{
	//处理时间控制上面的。
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time()+14*24*60*60);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
}

//
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
