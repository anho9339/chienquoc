#include <ansi.h>
#include <city.h>
#include <item.h>

inherit ITEM;
// inherit USABLE;

void create()
{
    set_name("Thí Luyện Thạch");

    set_picid_1(8901);
    set_picid_2(8901);

    set_value(50);

    set_no_give(1);
    //        set_no_drop(1);
    set_no_sell(1);
    set_no_save(1);
}

string get_desc()
{
    return "Vật phẩm nhiệm vụ. Sau khi lấp đầy 100 quái vật, đưa nó cho NPC sự kiện để đổi lấy phần thưởng。";
}

//// 函数：使用效果
// int get_use_effect( object me )
//{
//	return __FILE__->get_use_effect_callout(me,this_object());
//}

int get_use_effect_callout(object who, object item) {}
