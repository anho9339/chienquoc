#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 150 ;}
int get_item_value_2() {return 120 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name( "Kim Cương Bất Hoại Đơn" );
        set_picid_1(0088);
        set_picid_2(0088);
        set_unit( "粒" );
        set_value(50);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi sẽ dụng sẽ ở vào trạng thái bất tử trong 5 giây, tái sử dụng sau 2 phút.";
}
string get_loop_desc( object me )
{
	return "Kim Cương Bất Hoại Đơn: \nTrạng thái của tiên nhân bất tử, sẽ không bị tử vong.";
}
// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me,this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	object *user;	
		if (gone_time(me->get_save("battudon")) < 120)
      	{
      		send_user( me, "%c%s", '!', sprintf("Tái sử dụng sau %d giây", 120-gone_time(me->get_save("battudon"))) );
              	return 0;
      	}        
      	me->set_save("battudon",time());
		user = get_scene_object_2(me, USER_TYPE);
        set_effect_2(me, BAT_TU_DON, 1, 5);
        send_user( me, "%c%w%w%c", 0x81, 653, get_effect_3(me, BAT_TU_DON), EFFECT_GOOD );
        send_user( user - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 653, 1, EFFECT_GOOD );
		item->add_amount(-1);
        //return 1;
}
