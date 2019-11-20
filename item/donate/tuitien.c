#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Tiền");
        set_picid_1(4982);
        set_picid_2(4982);
		set_level(5);
        set_value(100);	               
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Mở ra nhận được 100000 tiền\n" NOR " \n*************\n"HIG "(Lưu ý : Túi này không thể vứt đi)"NOR "" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m;
	object item,item1,item2,item3;
	string cTmp,cFile,p;
	if ( who->get_level() < 10 )
	{
		        send_user(who,"%c%s",'!',"Cần đạt cấp 10.");
    		return 0;
	}
	if ( TASK_LEGEND_D->check_task_item_amount(who,"Túi Tiền") < 1 )
			{
				notify( "Ở hành trang 1 thì túi quà mới có thể sử dụng" );
				return ;	
			}
	TASK_LEGEND_D->check_task_item1(who,"Túi Tiền",1);

	who->add_cash(100000);

}