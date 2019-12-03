#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Sô Cô La Lãng Tử");
        set_picid_1(0054);
        set_picid_2(0054);
        set_unit("块");
        set_value(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return ("Ngụ ý:Tình trường cao thủ\nSử dụng gia tăng ngoại kháng 30%, trong 60 phút\n"HIR"Người sử dụng cần là nam tính");
}

// 函数：使用效果
int get_use_effect( object me ) {return __FILE__ ->get_use_effect_callout(me,this_object());}

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me , object item )
{
	if(me->get_gender()!=1)
	{
		send_user(me,"%c%s",';',"Thật xin lỗi, bạn không thể sử dụng nên đạo cụ。");
		return 0;
	}
	send_user( me, "%c%w%w%c", 0x81, 0430, 3600, EFFECT_GOOD );
	write_user(me,ECHO"Bạn nhận được"+item->get_user_id()+"chân tình chúc phúc, ngoại kháng gia tăng 30%。");
	me->set_save("03291#", me->get_dp()*30/100);
        set_effect(me, EFFECT_USER_DP, 3600);
        USER_ENERGY_D->count_dp(me);
        return 1;
}

void effect_done(object me)
{
        send_user( me, "%c%w%w%c", 0x81, 0430, 0, EFFECT_GOOD );
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        return "Tăng thêm ngoại kháng 30% trong 1 giờ。\n";
}