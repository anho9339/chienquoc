#include <item.h>
#include <effect.h>
#include <skill.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";  
 int is_ridepk() { return 1; }

#define RIDE_ID	17
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int get_item_color() { return 2; }
// 函数：nh9h构造处理
void create()
{
        set_name( "Xe Giáng Sinh" );
        set_picid_1(10);
        set_picid_2(10);
        set_value(500);
        set_hide(0);
        set_bind(1);
}

// 函数：nh9h获取描述
string get_desc() 
{ 
        return "\n★ \n"HIC"Thuộc tính Chiến Thú sau khi cưỡi : \n"HIY"Ngoại Kháng: "NOR "+ 100 \n"HIY"Nội Kháng: "NOR "+ 100 \n"HIY"Thân Thủ : "NOR "+ 50\n";
}

// 函数：nh9h使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：nh9h使用效果(在线更新)
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
	/* me->set_2("thucuoi.ap", 0);
	me->set_2("thucuoi.cp", 0); */
	me->set_2("thucuoi.dp", 0);
	me->set_2("thucuoi.pp", 0);
	me->set_2("thucuoi.sp", 0);
	/* USER_ENERGY_D->count_ap(me);
	USER_ENERGY_D->count_cp(me); */
	USER_ENERGY_D->count_dp(me);
	USER_ENERGY_D->count_pp(me);
	USER_ENERGY_D->count_sp(me);
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	if (me->set_ride(17))
	{
/*	me->set_2("thucuoi.ap", 500);
	me->set_2("thucuoi.cp", 500); */
	me->set_2("thucuoi.dp", 100);
	me->set_2("thucuoi.pp", 100);
	me->set_2("thucuoi.sp", 50);
	/* USER_ENERGY_D->count_ap(me);
	USER_ENERGY_D->count_cp(me); */
	USER_ENERGY_D->count_dp(me);
	USER_ENERGY_D->count_pp(me);
	USER_ENERGY_D->count_sp(me);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	
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