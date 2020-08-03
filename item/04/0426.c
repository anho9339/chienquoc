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
    set_name("Bông Hồng Trắng Tinh Khiết");

    set_picid_1(0051);
    set_picid_2(0051);

    set_value(1);
}

string get_desc()
{
    return ("Hoa nói：Trong sáng và ngây thơ\nSử dụng gia tăng nội kháng 30%，trong 60 phút\n" HIR
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
               ECHO "Bạn nhận được" + item->get_user_id() + "chân tình chúc phúc, phòng ngự nội kháng gia tăng 30%。");
    send_user(me, "%c%w%w%c", 0x81, 0426, 3600, EFFECT_GOOD);
    set_effect(me, EFFECT_ITEM_9165, 3600);
    me->set_save("9165#", 30);
    USER_ENERGY_D->count_pp(me);

    return 1;
}

void effect_done(object me)
{
    send_user(me, "%c%w%w%c", 0x81, 0426, 0, EFFECT_GOOD);
}

string get_loop_desc(object me)
{
    return "一Tăng nội kháng thêm 30% trong vài giờ。\n";
}
