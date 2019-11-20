#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <time.h>
#include <equip.h>

inherit TALISMAN;
int get_talisman_type() { return 1; }
int is_limit_time_item() { return 1; }

int get_item_color() {return 3 ;}
// 函数：构造处理
void create()
{
        set_name("Tế Thiên Chỉ Hoàn");
        set_picid_1(1016);//未确定。
        set_picid_2(1016);
        set_unit("个");
        set_value(50);
        set("time_item",1);
        set("ap_power",4);
        set("cp_power",4);
        set_max_lasting(35099);
        setup();
          
}   
// 函数：获取描述
string get_desc() 
{
    object item = this_object();
//---------------------------------------------------------//新服的
	if(item->get_lock_time()== 0)
	{
		item->set_lock_time(time()+24*3600*14);
	}
	return HIB"Tế thiên chỉ hoàn, chứa đựng nhiều tinh hoa trong nó. \n"HIY"Ngoại Công：+4%\n"HIY"Nội Công：+4%";
}
void start_loop_perform(object me)
{
	object item;
	item = me->get_equip(HAND_TYPE);
	if(time() < item->get_lock_time() || item->get_lock_time() == 0)
	{
//		me->set_save("ap_power",2);
//		me->set_save("cp_power",2);
		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_cp(me);
		CHAR_CHAR_D->init_loop_perform(me);
//		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1,UNDER_FOOT, PF_LOOP );
//		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 21152, 1,UNDER_FOOT, PF_LOOP );
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 36321, 1,UNDER_FOOT, PF_LOOP );
//		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41341, 1,UNDER_FOOT, PF_LOOP );
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41100, 1,UNDER_FOOT, PF_LOOP );
	}
}
void stop_loop_perform(object me)
{
	me->delete_save("ap_power");
	me->delete_save("cp_power");
	USER_ENERGY_D->count_ap(me);
	USER_ENERGY_D->count_cp(me);
	CHAR_CHAR_D->init_loop_perform(me);
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1, UNDER_FOOT, PF_STOP );
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 21152, 1,UNDER_FOOT, PF_STOP );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 36321, 1,UNDER_FOOT, PF_STOP );
//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41341, 1,UNDER_FOOT, PF_STOP );
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 41100, 1,UNDER_FOOT, PF_STOP );
	
}
