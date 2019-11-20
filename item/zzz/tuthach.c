#include <ansi.h>
#include <time.h>
#include <task.h>
inherit ITEM;

//int is_usable() { return 1; }
int get_item_color() { return 3; }
// 函数:构造处理
void create()
{
        set_name("Tử Thạch");
        set_picid_1(8900);
        set_picid_2(8900);
        set_unit("个");
        set_value(1);
        set_no_give(1);
        set_no_get(1);
        set_no_drop(1);
        set_no_sell(1); 
}

// 函数:获取描述
string get_desc() 
{ 
	object me = this_player();
	if (me)
        	return sprintf("Vật phẩm nhiệm vụ nâng cấp Tuyệt thế thần binh.\nTiêu diệt quái vật: %d/10000 \nTiêu diệt Hổ Vương: %d/1 \nTiêu diệt Âm Gian Bạn Đồ: %d/1 \nTiêu diệt Uy Võ Đại Tướng Quân: %d/1 \nTiêu diệt Khuyển Thái Lan: %d/1 ", 
			me->get_save_2("cantuong.count"),
			me->get_save_2("cantuong.hv"),me->get_save_2("cantuong.agbd"),
			me->get_save_2("cantuong.uvdtq"),me->get_save_2("cantuong.ktl")) ;
        else
        	return "Vật phẩm nhiệm vụ, yêu cầu phải hoàn thành." ;
}