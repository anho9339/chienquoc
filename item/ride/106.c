#include <item.h>
#include <effect.h>
#include <skill.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";   
int is_ridepk() { return 1; }

#define RIDE_ID	8287

// 函数：构造处理
void create()
{
        set_name( "ZZZ" );
        set_picid_1(8287);
        set_picid_2(8287);
        set_value(500);
        set_hide(0);
        set_bind(1);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "Thú cưỡi bình thường. Sau khi sử dụng sẽ phong ấn vào nhân vật.\n";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;	
	//Time
	if (item->get_lock_time()==0) item->set_lock_time(time()+7*24*60*60);
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Hết hạn sử dụng");
		return 0;		
	}
	
	if (me->get_ride())
	{
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	if (item->get_bind()==1)
	{
		item->set_bind(2);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
        return 0;
}
// Time
string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 7 ngày]\n ";
	}

	return desc;
}