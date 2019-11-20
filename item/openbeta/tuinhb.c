#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
int get_item_color() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Túi Nhẫn Huyền Băng");
        set_picid_1(4980);
        set_picid_2(4981);
		set_level(1);
        set_value(1000000);	    
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Mở ra nhận 200 nhẫn huyền băng.";
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
	if ( who->get_level() < 1 )
	{
		        send_user(who,"%c%s",'!',"Cần đạt cấp 1.");
    		return 0;
	}
	if ( TASK_LEGEND_D->check_task_item_amount(who,"Túi Nhẫn Huyền Băng") < 1 )
			{
				notify( "Ở hành trang 1 thì tui thẻ mới có thể sử dụng" );
				return ;	
			}
	TASK_LEGEND_D->check_task_item1(who,"Túi Nhẫn Huyền Băng",1);
		
		item = new("item/event/huyenbangnhan");
			item->set_amount(200);
	m = item->move2(who,-1);
		item->add_to_user(m);

}