#include <item.h>
#include <effect.h>
#include <skill.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

inherit "/inh/equip/equip";

// 函数:叠加上限
int get_max_combined() { return 1; }
int get_item_color() { return 2; }

// 函数:成品编号
int get_fin_type() { return 1633; }

// 函数:构造处理
void create()
{
        set_name( "Rương Chứa Đồ" );
        set_picid_1(0080);
        set_picid_2(0080);
        set_value(3300);
        set_amount(1);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数:获取描述
string get_desc() 
{ 	
        return "Sử dụng có thể mở ra Kho Chứa Đồ thay cho Quản Khố \n( Để mở rộng Kho hãy tới NPC Quản Khố và chọn Mở rộng Kho ).";
}

// 函数:使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数:使用效果(在线更新)
int get_use_effect_callout( object me )
{
	int type;
	object * objs, target;
	int i, size;	
	
    //    if(time()-me->get("pawn_time")<300)
    //    	return 0;
        	
	if (get_z(me)==001)
	objs = children("/npc/base/0001");
	else if (get_z(me)==010)
	objs = children("/npc/base/1001");
	else if (get_z(me)==020)
	objs = children("/npc/base/2001");
	else if (get_z(me)==030)
	objs = children("/npc/base/3001");
	else if (get_z(me)==040)
	objs = children("/npc/base/4001");
	else if (get_z(me)==050)
	objs = children("/npc/base/5001");
	else if (get_z(me)==060)
	objs = children("/npc/base/6001");
	else if (get_z(me)==070)
	objs = children("/npc/base/7001");
	else if (get_z(me)==080)
	objs = children("/npc/base/8001");
	else if (get_z(me)==549)
	objs = children("/npc/base/0911");
	else
	objs = children("/npc/base/1001");
	size = sizeof(objs);
	if (size==0) return 0;
	for (i=0;i<size;i++)
	{
		if (objectp(objs[i]) )
		{
			target = objs[i];
			break;
		}
	}
	if (!target) return 0;	
	me->set("pawn_time", time());
	"/cmd/std/pawn"->do_list(me, sprintf("%x#", getoid(target)), 1);
        return 0;
}