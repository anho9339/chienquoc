#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";

#define FASHION_ID	10

int get_item_value() {return 500 ;}
int get_item_value_2() {return 500 ;}
int get_item_color() {return 2 ;}

// 函数：构造处理
void create()
{
        set_name("Trạng Nguyên Phục");
        set_picid_1(0004);
        set_picid_2(0004);
        set_value(500);
		set_hide(0);
}

// 函数：获取描述
string get_desc() 
{ 
	object item=this_object();
	string desc;
	desc = "[Truyền Thống] Áo cưới truyền thống của Nam, thể hiện phong thái tuấn tú. \nNgoại Kháng +5%, Nội Kháng +5%, Bạo Kích +2% \n Nhấn chuột phải để sử dụng.";
	if (item->get_lock_time()==0)
	{
		desc+="\n"+"(Sử dụng trong 3 ngày)";
	}
	return desc;
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;
	if(me->get_gender()!=1)
	{
		return 0;
	}
	//处理时间控制上面的。
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time()+3*24*60*60);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Trang bị đã quá hạn.");
		return 0;		
	}
	if (me->get_save_2("marry_fashion"))
	{
		me->delete_save_2("marry_fashion");
		me->set_hair(3);
		USER_ENERGY_D->count_all_prop(me);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		return 0;
	}
		me->delete_save_2("marry_fashion");
		me->set_save_2("marry_fashion.time", item->get_lock_time());
		me->set_save_2("marry_fashion.code", FASHION_ID);
		me->set_save_2("marry_fashion.type", 2);
		me->set_hair(10);
		me->set_save_2("marry_fashion.dp", 5);
		me->set_save_2("marry_fashion.pp", 5);
		me->set_save_2("marry_fashion.double", 200);
		USER_ENERGY_D->count_dp(me);
		USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_hit_rate(me);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        return 0;
}
