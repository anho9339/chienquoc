#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 1020 ;}
int get_item_value_2() {return 1020 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Bí Kíp Ngân Lượng");
        set_picid_1(0089);
        set_picid_2(0089);
        set_value(1000);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng sẽ nhận được 20000 Ngân Lượng.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int p;
	object item;
	
	who->add_cash(20000);
	send_user(who,"%c%s",';',"Bạn nhận được "HIY "20000 Ngân Lượng");
//	log_file("sdknb.txt", sprintf("%s : %s (%d) %s sử dụng 2 Kim Bảo\n", short_time(time()), who->get_name(), who->get_number(), who->get_id() ));
	gift->add_amount(-1);
	return 0;
}