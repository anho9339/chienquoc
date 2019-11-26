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
        set_name("Thẻ Bài Hắc Cầu");
        set_picid_1(3565);
        set_picid_2(3565);
        set_unit("只");
        set_value(10);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "World Cup đã tới，hãy dùng thẻ để tham gia dự đoán kết quả。Giá trị：10。\nSử dụng tăng 10% Khí Huyết，trong 60 phút。"; 
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
//	if ( gone_time(who->get("qiupai1")) < 1 ) 
//		return 0;
//	who->set("qiupai1",time());
//	set_effect_2(who, EFFECT_QIUPAI_HP,  1, 3600);
//	USER_ENERGY_D->count_max_hp(who);
//	return 1;
}

void effect_break(object who)
{
//	set_effect(who, EFFECT_QIUPAI_HP, 0);
//	USER_ENERGY_D->count_max_hp(who);
}