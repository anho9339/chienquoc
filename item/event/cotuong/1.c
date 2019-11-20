#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/fashion";;

int get_item_value() {return 300 ;}
int get_item_value_2() {return 300 ;}
int get_item_color() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Anh Hùng Chiến Y Hoàn Mỹ(Nam)");
        set_picid_1(10052);
        set_picid_2(10052);

        set_level(1);
		set_bind(1);
        set_value(500);
        set_max_lasting(35099);

		set("time_item", 1);

         set("dp+", 350);
        set("pp+", 350);
        set("hp+", 600);
	//	set("hp%+", 50);
		set("mp+", 600);
	//	set("mp%+", 100);
		set("!%+", 1200);
		set("?%+", 600);

        setup();

        set_gender(1);

		set_fashion_code(52);
}

// 函数：获取描述
string get_desc()
{
        return "Chí anh hùng ngạo giữa thế gian, tình hiệp khách lang thang gió lạnh.";
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
		item->set_lock_time(time()+3*24*60*60);
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
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 3 ngày]\n ";
	}

	return desc;
}
