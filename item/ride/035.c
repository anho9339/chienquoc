#include <item.h>
#include <effect.h>
#include <skill.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";  
 int is_ridepk() { return 1; }

#define RIDE_ID	35

// 函数：构造处理
void create()
{
        set_name( "Ác Đà Đà" );
        set_picid_1(10);
        set_picid_2(10);
        set_value(500);
        set_hide(0);
        set_bind(2);
}

// 函数：获取描述
string get_desc() 
{ 
        return "\n★★★★★★ \n"HIC"Thuộc tính Chiến Thú sau khi cưỡi : \n"HIY"Ngoại Kháng: "NOR "+ 200 \n"HIY"Nội Kháng: "NOR "+ 200 \n"HIY"Thân Thủ : "NOR "+ 100\n";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;	
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
	if (me->set_ride(35))
	{
/*	me->set_2("thucuoi.ap", 500);
	me->set_2("thucuoi.cp", 500); */
	me->set_2("thucuoi.dp", 200);
	me->set_2("thucuoi.pp", 200);
	me->set_2("thucuoi.sp", 100);
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
	/*if (item->get_bind()==1)
	{
		item->set_bind(2);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}*/
        return 0;
}
