#include <ansi.h>
#include <city.h>
#include <item.h>

inherit ITEM;
inherit USABLE;

int get_item_type()
{
    return ITEM_TYPE_SPECIAL;
}

void create()
{
    set_name("Bang Phái Tín Vật");

    set_picid_1(80);
    set_picid_2(80);

    set_value(1);

    set_no_give(1);
    set_no_drop(1);
    set_no_sell(1);
}

string get_desc()
{
    string name;
    int Gold, iFavour, iStable, iStore;

    name = get("special");

    if (name == 0)
        return "";

    sscanf(name, "%d|%d|%d|%d", Gold, iFavour, iStable, iStore);
    return sprintf(
        "Bang phái cần bổ sung thêm vật phẩm cần thiết，thành viên mới có thể nhận，\nNhấp chuột phải sử dụng để nhận "
        "các vật phẩm bổ sung \nchỉ đc sử dụng sau ngày 04 tháng 1 2007。\nTài Chính：%d\nNhân Khí：%d\nAn "
        "Định：%d\nDự Trữ：%d\n",
        Gold, iFavour, iStable, iStore);
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object item)
{
    string name, result;
    object orgnpc;
    int Gold, iFavour, iStable, iStore;

    if (time() < mktime(2007, 1, 4, 0, 0, 0))
    {
        send_user(who, "%c%s", '!', "Vui lòng sử dụng sau ngày 4 tháng 1 năm 2007。");
        return 0;
    }

    name = item->get("special");

    if (!name)
        return 0;

    if (sscanf(name, "%d|%d|%d|%d", Gold, iFavour, iStable, iStore) != 4)
        return 0;

    name = who->get_org_name();

    if (sizeof(name) == 0)
        return;

    orgnpc = CITY_ZHOU->get_2(sprintf("org.%s", name));

    if (!orgnpc)
        return 0;

    orgnpc->add_gold(Gold);
    orgnpc->add_favour(iFavour);
    orgnpc->add_stable(iStable);
    orgnpc->add_store(iStore);

    result = sprintf("Sử dụng Bang Phái Tín Vật, Tài Chính：+%d，Nhân Khí：+%d，An Định：+%d，Dự Trữ：+%d。", Gold,
                     iFavour, iStable, iStore);
    send_user(who, "%c%s", '!', "你" + result);
    FAMILY_D->org_channel( name, 0, HIR + who->get_name() + result);

    return 1;
}
