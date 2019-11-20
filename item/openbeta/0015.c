#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

int get_item_color() { return 2; }
int is_ghepngocboi() { return 1; }
// 函数：构造处理
void create()
{
        set_name("Song Phụng Ngọc Bội");
        set_picid_1(906);
        set_picid_2(906);
        set_value(5000000);
		set_save("ghep",180);
}

// 函数：获取描述
string get_desc()
{
        return " \n★★★★★★★★★ \nNgọc bội đại diện cho đôi uyên ương, tiềm ẩn ma lực vô cùng lớn.\n Khả năng Tín Vật Môn Phái ở cấp 9 tăng lên cấp 10.\n Người chơi phải đợi đạt đến cấp 55 mới có thể sử dụng ngọc bội.";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	object item2;
	if (me->get_level()<55)
	{
		send_user( me, "%c%s", '!', "Cấp 55 mới được dùng" );
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
		send_user( me, "%c%s", '!', "Không thể thăng cấp Tín Vật Tân Thủ được." );
		return 0;
	}	
	if (item2->get_item_level()!=9)
	{
		send_user( me, "%c%s", '!', "Cấp bậc của Tín Vật không phù hợp" );
		return 0;
	}	
	send_user(me, "%c%c%w%s", ':', 3, 0, "Song Phụng Ngọc Bội sau khi sử dụng sẽ biến mất \n Bạn muốn sử dụng không???\n"+ESC+"Chấp nhận\n"+sprintf("use ! %x#\n", getoid(item))+ESC+"Hủy bỏ\nCLOSE\n");
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
		send_user( me, "%c%s", '!', "Cấp 55 mới được dùng" );
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
		send_user( me, "%c%s", '!', "Không thể thăng cấp Tín Vật Tân Thủ được." );
		return 0;
	}	
	if (item2->get_item_level()!=9)
	{
		send_user( me, "%c%s", '!', "Cấp bậc của Tín Vật không phù hợp" );
		return 0;
	}	
	item2->set_item_level(10);
	item2->init_familyobj();	
	send_user(me, "%c%d%c", 0x31, getoid(item2), 0);
	"/sys/user/energy"->count_all_prop(me);
	return 1;
}