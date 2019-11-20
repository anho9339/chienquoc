#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 3; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}
inherit BACK;
void create()
{
        set_name("Tiên Đế Chi Dực");
        set_picid_1(3028);
        set_picid_2(3028);

        set_level(0);
		set_bind(0);
        set_value(1000);
        set_max_lasting(21599);
       set("cp+", 600);	
        set("dp+", 550);
        set("hp+", 1500);
		set("mp+", 1500);
		set("sp+", 120);
		set("double", 500);

		set_hide(0);
        setup();

		set_gender(1);
        set_back_type(7);
		set_back2_type(7);
		set_back_color(0x00AACD66);
		set_back2_color(0x00EEEEAF);
}

string get_desc()
{
        return "Đôi cánh của Tiên Đế được tạo ra để che chở thế gian. Uy lực khó lường.";
}

// 函数：使用效果
int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

// Hàm giữ vật phẩm ngay cả khi hết tg
int get_equip_effect_callout( object me, object item )
{
	if (item->get_lock_time()==0) 
	item->set_lock_time(time()+30*24*60*60);
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Hết hạn sử dụng");
		return 0;		
	}
}

string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 30 ngày]\n ";
	}

	return desc;
}