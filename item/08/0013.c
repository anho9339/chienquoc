#include <ansi.h>
#include <skill.h>

inherit COMBINED;
inherit ITEM;

int get_item_value()
{
    return 450;
}

int get_item_value_2()
{
    return 380;
}

int get_item_number()
{
    return 13;
}

int get_item_color()
{
    return 1;
}

void create()
{
    set_name("Chiến Quốc Lệnh");

    set_picid_1(0096);
    set_picid_2(0096);

    set_value(10);

    set_no_give(1);
    set_no_sell(1);

    set_amount(1);

    set_record(1);
}
int is_usable()
{
    return 1;
}

string get_desc()
{
    return "Lệnh bài thần kì, sau khi sử dụng có thể tiếp tục duy trì trong vòng 1 tiếng đồng hồ mới mất đi\n giết "
           "quái vật có thể đạt được gấp bốn Kinh nghiệm. (Hiệu quả của lệnh bài không thể lặp lại)";
}

string get_loop_desc(object me)
{
    return "Trong một tiếng đồng hồ có thể đạt được Kinh nghiệm nhân bốn.";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object item)
{
    int i, iWeek;

    if (gone_time(who->get_login_time()) + who->get_game_time() < who->get_extra_double_time())
    {
        send_user(
            who, "%c%c%w%s", ':', 3, 0,
            sprintf("Bạn đã sử dụng Chiến Quốc Lệnh hiện tại.Bạn có chắc chắn muốn ghi đè hiệu lực của nó không？\n" ESC
                    "Xác nhận\nuse ! %x#\n" ESC "Hủy bỏ",
                    getoid(item)));
        return 0;
    }

    iWeek = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);

    if (who->get_save_2("double_time.week") != iWeek)
    {
        who->set_save_2("double_time.week", iWeek);
        who->set_save_2("double_time.time", 0);
        who->set_save_2("double_time.time1", 0);
        who->set_save_2("double_time.time2", 0);
    }

    if (who->get_save_2("double_time.time1") >= 25)
    {
        send_user(who, "%c%s", '!', "Bạn đã sử dụng tối đa Lệnh Chiến Quốc trong tuần này。");
        return 0;
    }

    who->add_save_2("double_time.time1", 1);
    i = gone_time(who->get_login_time());
    who->set_extra_double_time(i + who->get_game_time() + 3600);
    send_user(who, "%c%w%w%c", 0x81, 9998, 3600, EFFECT_GOOD);

    return 1;
}

int confirm_use(object me)
{
    return __FILE__->confirm_use_callout(me, this_object());
}

int confirm_use_callout(object who, object item)
{
    int i, iWeek;

    iWeek = (time() - 4 * 24 * 3600 + 8 * 3600) / (7 * 24 * 3600);

    if (who->get_save_2("double_time.week") != iWeek)
    {
        who->set_save_2("double_time.week", iWeek);
        who->set_save_2("double_time.time", 0);
        who->set_save_2("double_time.time1", 0);
        who->set_save_2("double_time.time2", 0);
    }

    if (who->get_save_2("double_time.time1") >= 25)
    {
        send_user(who, "%c%s", '!', "Bạn đã sử dụng tối đa Lệnh Chiến Quốc trong tuần này。");
        return 0;
    }

    who->add_save_2("double_time.time1", 1);
    i = gone_time(who->get_login_time());
    who->set_extra_double_time(i + who->get_game_time() + 3600);
    send_user( who, "%c%w%w%c", 0x81, 9998, 3600, EFFECT_GOOD );

    return 1;
}
