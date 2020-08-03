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
    set_name("Sô Cô La Chân Thành");

    set_picid_1(0055);
    set_picid_2(0055);

    set_value(1);
}

string get_desc()
{
    return ("Ngụ ý: Ngây thơ và chung tình\nSử dụng gia tăng nội công 30%, trong 60 phút\n" HIR
            "Người sử dụng cần là nam tính");
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
    if (me->get_gender() != 1)
    {
        send_user(me, "%c%s", ';', "Thật xin lỗi, bạn không thể sử dụng nên đạo cụ。");
        return 0;
    }

    send_user(me, "%c%w%w%c", 0x81, 0430, 3600, EFFECT_GOOD);
    write_user(me, ECHO "bạn nhận được" + item->get_user_id() + "chân tình chúc phúc, nội công gia tăng 30%。");
    set_effect(me, EFFECT_USER_CP, 3600);
    me->set_save("cp10#", 30);
    USER_ENERGY_D->count_cp(me);

    return 1;
}

void effect_done(object me)
{
    send_user(me, "%c%w%w%c", 0x81, 0430, 0, EFFECT_GOOD);
}

string get_loop_desc(object me)
{
    return "Tăng thêm nội công 30% trong 1 giờ。\n";
}
