#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_PET; }
//宠物物品
int is_pet_item() { return 1;}
// 函数：构造处理
void create()
{
        set_name("Sủng Vật Cường Hóa Đan");
        set_picid_1(0088);
        set_picid_2(0088);
        set_unit("个");
        set_value(5000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	string desc;
	return desc = "Rút ngắn thời gian triệu hồi thú cưng đã chết\n(Sau khi sử dụng giảm thời gian triệu hồi thú cưng đã chết từ 10 phút xuống 0 phút.）";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__->get_use_effect_call(me, this_object()); }

int get_use_effect_call(object me,object item)
{
	int i,now;
	if ( !me->is_pet() )
		return 0;
	i = me->get_dead_time();
	now = time();
	if ( now - i > 600 )
		return 0;
	me->set_dead_time(0);
	if( me->get_owner() )
		send_user(me->get_owner(),"%c%c%d%d", 0xA1,4,getoid(me),0);
	return 1;	
}