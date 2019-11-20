#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_max_combined() { return 10000; }
int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Chén Bạc Hoàng Kim Phú Quý");
        set_picid_1(3507);
        set_picid_2(3507);
		set_level(10);
        set_value(10000);
		        set_no_give(0);		
        set_no_sell(0);
				set_no_drop(0);
		set_amount(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Chén Bạc Hoàng Kim của Quang Hiếu sáng chế.\n Sử dụng sẽ nhận được "HIY " 1 tỷ 700 triệu ngân lượng "NOR " ngay tức khắc." ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,exp,type;
	object item,item1;
	string cTmp,cFile,p;
		if ( who->get_level() < 10 )
		{
		send_user(who,"%c%s",'!',"Cấp 10 mới có thể sử dụng.");
		    		return 0;

		}
//		TASK_LEGEND_D->check_task_item1(who,"Chén Bạc Hoàng Kim Phú Quý",1);


					who->add_exp(1000);
					who->add_cash(1700000000);
				gift->add_amount(-1);
}