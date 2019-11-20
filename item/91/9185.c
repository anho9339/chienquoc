#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_item_color() { return 2; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：成品编号
int get_fin_type() { return 1824; }

// 函数：构造处理
void create()
{
        set_name( "Sinh Khí Tán" );
        set_picid_1(9985);
        set_picid_2(9985);
        set_unit( "包" );
        set_value(50);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Tăng 18% Khí Huyết.\nTăng 20% Pháp Lực.\nTăng 12% Ngoại Công.\nTăng 12% Ngoại Kháng.\nTăng 12% Nội Công.\nTăng 12% Nội Kháng.";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{

        set_effect(me, EFFECT_USER_HP, 7*24*3600);
		set_effect(me, EFFECT_USER_MP, 7*24*3600);
		set_effect(me, EFFECT_USER_AP, 7*24*3600);
		me->set_save( "ap10#", 12 );
		me->set_save("03291#", me->get_dp()*12/100);
        set_effect(me, EFFECT_USER_DP, 7*24*3600);
		set_effect(me, EFFECT_USER_CP, 7*24*3600);
		me->set_save( "cp10#", 12 );
		set_effect(me, EFFECT_ITEM_9165, 7*24*3600);
		me->set_save( "9165#", 12 );
        USER_ENERGY_D->count_max_hp(me);
        USER_ENERGY_D->count_max_mp(me);
        USER_ENERGY_D->count_ap(me);
        USER_ENERGY_D->count_dp(me);
        USER_ENERGY_D->count_cp(me);
        USER_ENERGY_D->count_pp(me);
		send_user(me,"%c%s",';',"Bạn nhận được hiệu quả Sinh Khí Tán trong 7 ngày.");
        return 0;
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        return "Trong 1 ngày tăng sinh lực!\n";
}