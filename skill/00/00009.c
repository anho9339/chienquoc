
// 召唤技能  TIPS:[PF_CALL]

#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>
#include <equip.h>

#define THIS_PERFORM    00009
#define PF_START       "00009"
#define PF_NAME        "Tuyết Ngoại Nhi"

#define SKILL_LEVEL     60

#define INIT_HP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 339, 4)    // 警告：me 得准备好
#define INIT_AP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 50, 19)    // 警告：me 得准备好
#define INIT_DP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 95, 29)    // 警告：me 得准备好
#define INIT_PP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 82, 33)    // 警告：me 得准备好
#define INIT_SP         me->get_pf_value(THIS_SKILL, SKILL_LEVEL_SQUARE, 93, 33)    // 警告：me 得准备好

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

#define MAX_ZOMBIE      5

// 函数：获取符法效果
int get_cast_seal() { return 9103; }    // 符纸逆旋

// 函数：获取描述
string get_desc( object me )
{
 //       int cur_level;
        string result;
 //       if (level<SKILL_LEVEL)
        	return HIR + PF_NAME +"\n Võ công yêu cầu: 60 cấp\n Vật phẩm tiêu hao: Bùa Thần Tiên\n    (Ngoại) Triệu hồi Tuyết Nhi hỗ trợ, có tỉ lệ nhất định làm choáng mục tiêu.";
//        cur_level = (level - SKILL_LEVEL)/10 + 1;
        result = sprintf(HIC" %s (Cấp 60 )\n " NOR "Võ công yêu cầu: Cấp 60 \n Vật phẩm tiêu hao: Bùa Thần Tiên\n Tái sử dụng sau: %d giây\n   (Ngoại) Triệu hồi Tuyết Nhi hỗ trợ chiến đấu. Khi Tuyết Nhi đánh có tỉ lệ nhất định làm choáng mục tiêu.\n ",
        	PF_NAME, 2 );
	return result;
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *user, tienlinh, item, item2;
        int level, mp, size;

    //    if( ( level = me->get_skill(THIS_SKILL) ) < SKILL_LEVEL ) return 1;

        if( me->get_perform(PF_START) == time() ) return 1;

        if( !objectp( item2 = present("Bùa Thần Tiên", me, 1, MAX_CARRY*4) ) )
        {
                printf( ECHO "Phải có Bùa Thần Tiên mới có thể sử dụng \"" PF_NAME "\"." );
                return 1;
        } 
		// Phái ngoại
	if (me->get_fam_name()=="Mao Sơn")
	{
	    printf( ECHO "Phái Mao Sơn đã có pet riêng rồi." );
		return 1;
	} 
	if (me->get_fam_name()=="Vân Mộng Cốc")
	{
	    printf( ECHO "Phái của bạn là phái nội mà?" );
		return 1;
	} 
    	if ( get_z(me)==885 )
		{	
			notify(HIY"Không thể gọi Linh Thú ở bản đồ này!");
			return 1;	
		} 
		if ( get_z(me)==888 )
		{	
			notify(HIY"Không thể gọi Linh Thú ở bản đồ này!");
			return 1;	
		}
		if ( get_z(me)==889 )
		{	
			notify(HIY"Không thể gọi Linh Thú ở bản đồ này!");
			return 1;	
		}
       tienlinh = me->get("tienlinh");
        if( objectp(tienlinh) )
        {
                printf( ECHO "Bạn đã gọi Tiên Linh rồi." );
                return 1;
        }  

        send_user( me, "%c%w%c%w", 0x50, 0, 0xff, 2 );    // Sau 2 giây có thể sử dụng lại chiêu
        me->set_time( "pf", time() );

        user = get_scene_object_2(me, USER_TYPE);
        send_user( user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_BEGIN );
        send_user( me, "%c%d%w%c%c%c", 0x6f, getoid(me), get_cast_seal(), 2, UNDER_FOOT, PF_LOOP );

 //       me->add_mp(-mp);
//      item->add_amount(-1);
        item2->add_amount(-1);

        set_heart_state(me, MAGIC_STAT);
        set_heart_count_2(me, 9);
        me->add_2("go_count.count2",9);
        me->set_cast_file(__FILE__);
        me->set_cast_arg( sprintf( "%d", level ) );

        return 1;
}

// 函数：法术处理
int cast_done( object me )
{
        object npc;
        string arg;
        int z, x, y, x0, y0, p;
        int level, cp, pp, i, size;

        if( !stringp( arg = me->get_cast_arg() ) ) return 1;
        me->set_perform( PF_START, time() );
        level = to_int(arg);
        
        send_user(me, "%c%c%w%s", 0x5a, 0, 3, "Gọi Tiên Linh……"); // 3 giây gọi tiên linh	                
        me->set_2("conjure.type", 4140);
        me->set_2("conjure.level", level);
        set_effect(me, EFFECT_CONJURE, 3);      // 3 giây gọi tiên linh            

        return 2;    // 执行成功
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME_7; }

// 函数：能否使用特技
/*
void can_perform( object me )
{
        if( me->get_skill(THIS_SKILL) < SKILL_LEVEL ) 
                send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
        else    send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, 0, 1, MAGIC_ACT_BEGIN, 0, 9, "Bùa Thần Tiên");
}  */

void can_perform( object me )
{
       send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
//	send_user(me, "%c%w%w%c%c%c%c%c%s", 0x64, THIS_PERFORM, 0, 1, MAGIC_ACT_BEGIN, 0, 9, "Bùa Thần Tiên");
}