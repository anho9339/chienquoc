#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("★★★ VÔ SONG ★★★");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(0);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
        set("ap+", 750);
		set("cp+", 750);
		set("dp+", 750);
        set("pp+", 750);
        set("hp+", 2550);
		set("mp+", 2550);
		set("sp+", 440);
		set("double", 700);
		set_hide(0);
        setup();

    //    set_gender(1);
        set_back_type(1);
		set_back_color(0x00EEEEAF);
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
		item->set_lock_time(time()+31*24*60*60);
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
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 31 ngày]\n ";
	}

	return desc;
}