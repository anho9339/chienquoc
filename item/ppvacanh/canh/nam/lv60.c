#include <ansi.h>
#include <equip.h>


inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Thánh Linh Vân Sương");
        set_picid_1(3028);
        set_picid_2(3028);

        set_level(0);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
        set("cp+", 700);
        set("dp+", 700);
		set("pp+", 700);
        set("hp+", 1400);
		set("mp+", 1400);
		set("sp+", 300);
		set("double", 200);

        setup();

        set_gender(1);
        set_back_type(7);
		set_back2_type(7);
		set_back_color(0xffff);
		set_back2_color(0xffff);
}

// 函数：获取描述
string get_desc()
{
        return "★★★★★";
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
		item->set_lock_time(time()+30*24*60*60);
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
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 30 ngày]\n ";
	}

	return desc;
}