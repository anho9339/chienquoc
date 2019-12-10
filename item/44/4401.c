
// 自动生成：/make/item/make31c
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
        set_name("Cao Cấp Sủng Vật Gia Quả");
        set_picid_1(9978);
        set_picid_2(9978);
        set_unit("个");
        set_value(1700);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	string desc;
	return desc = "Một loại quả cho thú nuôi,khi được tiêu thụ,tuổi thọ của chúng sẽ tăng lên\nTuổi thọ tăng thêm là 50,bị ngộ độc 1%";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__->get_use_effect_call(me, this_object()); }

int get_use_effect_call(object me,object item)
{
	object owner;
	if ( !me->is_pet() )
		return 0;
	me->add_life(50);
	owner = me->get_owner();
	tell_user(owner,"của bạn"+me->get_name()+"Tuổi thọ gia tăng 50 điểm");
	if( !random100() )
	{
		me->add_life(-200);
		send_user(owner,"%c%s",'!',"của bạn"+me->get_name()+"bị ngộ độc!");
	}
	return 1;	
}