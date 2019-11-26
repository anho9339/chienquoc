#include <effect.h>
inherit ITEM;
inherit COMBINED;

int is_usable() { return 1; }
// 函数：叠加上限
int get_max_combined() { return 30; }

int is_worldcup() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Thẻ Bài Hồng Cầu");
        set_picid_1(3567);
        set_picid_2(3567);
        set_unit("只");
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "World Cup đã tới，hãy dùng thẻ để tham gia dự đoán kết quả。Giá trị：10。\nSử dụng tăng 8% lực Công Kích，trong 60 phút。"; 
}

int get_use_effect(object who) { return __FILE__->get_use_effect_callout(who,this_object()); }

int get_use_effect_callout(object who,object item)
{
	if ( time() > mktime(2006,7,9,0,0,0) )	
	{
		item->remove_from_user();
		destruct(item);
		return 0;
	}
//	if ( gone_time(who->get("qiupai3")) < 1 ) 
//		return 0;
//	who->set("qiupai3",time());
//	set_effect_2(who, EFFECT_QIUPAI_AP,  1, 3600);
//	USER_ENERGY_D->count_ap(who);
//	return 1;
}

void effect_break(object who)
{
//	set_effect(who, EFFECT_QIUPAI_AP, 0);
//	USER_ENERGY_D->count_ap(who);
}