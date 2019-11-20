#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Thiên Long Ngọc Bội 2");
        set_picid_1(4246);
        set_picid_2(4246);
        set_value(500);
}

// 函数：获取描述
string get_desc()
{
        return " \n★★★★★★ \nCó thể tăng Tín Vật cấp 6 lên cấp 7。";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	object item2;
	if (me->get_level()<55)
	{
		send_user( me, "%c%s", '!', "Cấp 55 mới được dùng。" );
		return 0;
	}
	item2 = me->get_equip(FAMILY_TYPE);
	if (!item2)
	{
		send_user( me, "%c%s", '!', "Hãy Nhập Phái。" );
		return 0;
	}	
	if (item2->is_newplayer())
	{
		send_user( me, "%c%s", '!', "Không thể thăng cấp Tín Vật của Tân Thủ。" );
		return 0;
	}	
	if (item2->get_item_level()!=6)
	{
		send_user( me, "%c%s", '!', "Cấp bậc của Tín Vật không phù hợp" );
		return 0;
	}	
	send_user(me, "%c%c%w%s", ':', 3, 0, "Thiên Long Ngọc Bội sau khi sử dụng sẽ biến mất \n Bạn muốn sử dụng không???\n"+ESC+"Chấp nhận\n"+sprintf("use ! %x#\n", getoid(item))+ESC+"Hủy bỏ\nCLOSE\n");
	return 0;
}

// 函数：使用效果
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int confirm_use_callout( object me, object item )
{
	object item2;
	if (me->get_level()<55)
	{
		send_user( me, "%c%s", '!', "Cấp 45 mới được dùng。" );
		return 0;
	}
	item2 = me->get_equip(FAMILY_TYPE);
	if (!item2)
	{
		send_user( me, "%c%s", '!', "Bạn không có Tín Vật Sư Môn" );
		return 0;
	}	
	if (item2->is_newplayer())
	{
		send_user( me, "%c%s", '!', "Không thể thăng cấp Tín Vật Tân Thủ được.。" );
		return 0;
	}	
	if (item2->get_item_level()!=6)
	{
		send_user( me, "%c%s", '!', "Cấp bậc của Tín Vật không phù hợp" );
		return 0;
	}	
	item2->set_item_level(7);
	item2->init_familyobj();	
	send_user(me, "%c%d%c", 0x31, getoid(item2), 0);
	"/sys/user/energy"->count_all_prop(me);
	return 1;
}