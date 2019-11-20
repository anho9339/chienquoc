
#include <effect.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：成品编号
int get_fin_type() { return 1826; }

// 函数：构造处理
void create()
{
        set_name( "Tử Tâm Đơn" );
        set_picid_1(9164);
        set_picid_2(9164);
        set_unit( "粒" );
        set_value(50);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Trong vòng một giờ tăng 10% Nội Công";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
/*      if( gone_time( me->get_time("eat") ) < 1 )
        {
                me->set_time( "eat", time() );
                return 0;
        }
        me->set_time( "eat", time() );  */

        set_effect(me, EFFECT_USER_CP, 3600);
	me->set_save( "cp10#", 10 );
        USER_ENERGY_D->count_cp(me);

        return 1;
}
