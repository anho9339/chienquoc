#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;

int confirm_sell_item()
{
    return 1;
}

void create()
{
    set_name("Bông Hồng Xanh Biếc");

    set_picid_1(0050);
    set_picid_2(0050);

    set_value(1);
}

string get_desc()
{
    return ("Hoa nói：Đôn hậu và thiện lương\nSử dụng gia tăng ngoại kháng 30%,trong 60 phút\n" HIR
            "Người sử dụng cần là nữ tính");
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
    if (me->get_gender() == 1)
    {
        send_user(me, "%c%s", ';', "Thật xin lỗi, bạn không thể sử dụng nên đạo cụ。");
        return 0;
    }

    write_user(me,
               ECHO "Bạn nhận được" + item->get_user_id() + "chân tình chúc phúc,phòng ngự ngoại kháng gia tăng 30%。");
    send_user(me, "%c%w%w%c", 0x81, 0426, 3600, EFFECT_GOOD);
    me->set_save("03291#", me->get_dp() * 30 / 100);
    set_effect(me, EFFECT_USER_DP, 3600);
    USER_ENERGY_D->count_dp(me);

    return 1;
}

void effect_done(object me)
{
    send_user(me, "%c%w%w%c", 0x81, 0426, 0, EFFECT_GOOD);
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
    return "Tăng thêm ngoại kháng 30% trong một giờ。\n";
}
