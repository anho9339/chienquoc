#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";

#define PICID	3023

int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}
int get_item_color() { return 1;};
void create()
{
	set_name("Song Tử Anh Minh");
	set_picid_1(4262);
        set_picid_2(4262);
        set_bind(4);
        set_value(50);
	//	set_save("knb2",1000);
	set_no_sell(1);
	setup();
}
string get_desc()
{
	return "Song Tử là 1 trong 12 cung Hoàng Đạo. Khi được triệu hồi, sẽ giúp chủ nhân gia tăng thêm 5% Ngoại Kháng, 5% Nội Kháng, 5% Khí Huyết, 5% Bạo Kích, 5% Ngoại Công, 5% Nội Công.";
}
string get_short()
{
	return "Song Tử là 1 trong 12 cung Hoàng Đạo. Khi được triệu hồi, sẽ giúp chủ nhân gia tăng thêm 5% Ngoại Kháng, 5% Nội Kháng, 5% Khí Huyết, 5% Bạo Kích, 5% Ngoại Công, 5% Nội Công, Thời gian giới hạn 14 ngày. nhận được sẽ tự phong ấn.";
}
// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	object *obj,zombie,npc;
	int size,index,p,z,x,y;
	if (item->get_lock_time()==0) item->set_lock_time(time()+14*24*60*60);//处理时间控制上面的。
	obj = me->get("zombie");
	size = sizeof(obj);
	if(size)
	{
		for(index = 0; index < size; index++)
		{
			zombie = obj[index];
			if (!objectp(zombie)) continue;
			send_user( get_scene_object_2(zombie, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, get_x(zombie), get_y(zombie), 9414, 1, OVER_BODY, PF_ONCE );
			send_user(me, "%c%c%d", 0x2c, 0, getoid(zombie));
			zombie->remove_from_scene();
			destruct(zombie);
		}
		item->set_no_drop(0);
		item->set_no_get(0);
	        me->delete("12pet_item");
		me->delete("zombie");
		me->delete_2("jiguan");
		USER_ENERGY_D->count_all_prop(me);
		return 0;
	}
	if(item->get_lock_time() < time())
	{
		send_user(me,"%c%s",'!',"Vật phẩm đã hết hạn sử dụng");
		return;
	}
	item->set_no_drop(1);
	item->set_no_get(1);
	npc = new ("/npc/std/jiguan");
	npc->set_name(get_name());
	npc->set_char_picid(PICID);
	npc->upgrade_level(1);
        npc->set_owner(me);
        npc->set_action_mode(2);
	z = get_z(me); x = get_x(me); y = get_y(me);
	p = get_valid_xy(z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK) ;
	x = p / 1000;  y = p % 1000;
	npc->add_to_scene( z, x, y, 3);
	npc->set("jg_effect_buff",1);
//        npc->set_life(item->get_lock_time()-time());
        me->add("zombie", ({ npc }) );
        me->set("12pet_item", item );
        me->delete_2("jiguan");
        me->set_2("jiguan.dp", 5);
        me->set_2("jiguan.ap", 5);
        me->set_2("jiguan.pp", 5);
        me->set_2("jiguan.hp", 5);
        me->set_2("jiguan.cp", 5);
        me->set_2("jiguan.do", 500);	//	爆击+
        USER_ENERGY_D->count_max_hp(me);
        USER_ENERGY_D->count_dp(me);
        USER_ENERGY_D->count_ap(me);
        USER_ENERGY_D->count_pp(me);
        USER_ENERGY_D->count_sp(me);
        USER_ENERGY_D->count_cp(me);
        me->set_2("jg_effect_buff.sz3",30000);        
        send_user( me, "%c%w%w%c", 0x81, 4033, 30000, EFFECT_GOOD );
	return 0;
}

string get_pet_desc() {
	return "Chủ nhân gia tăng 5% Ngoại Kháng, 5% Nội Kháng, 5% Khí Huyết, 5% Bạo Kích, 5% Ngoại Công, 5% Nội Công";
}