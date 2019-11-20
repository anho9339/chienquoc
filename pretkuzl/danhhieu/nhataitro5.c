#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 1020 ;}
int get_item_value_2() {return 1020 ;}
int get_item_color() { return 3; }

// 函数：构造处理
void create()
{
        set_name("Nhà Tài Trợ Chính");
        set_picid_1(0089);
        set_picid_2(0089);
        set_value(1000);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng sẽ nhận được danh hiệu Nhà Tài Trợ cấp 5 tăng 250 nội/ngoại kháng.";
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
//	TASK_LEGEND_D->check_task_item1(who,"Chén Bạc Võ Lâm Minh Chủ",1);
					who->add_title("T011");
			gift->add_amount(-1);
}