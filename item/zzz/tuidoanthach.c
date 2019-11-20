#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Đoạn Thạch");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra sẽ nhận được một loại Đoạn Thạch bất kỳ."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	
	rate = random(30);
	
	if ( rate < 10 )		//Sơ
	{
		item = new("item/sell/0032");
		if ( !item )
			return 0;
	}
	else if ( rate < 20 ) // Trung
	{
		item = new("item/sell/1032");
		if ( !item )
			return 0;
	}
	else 			// Cao
	{
		item = new("item/sell/2032");
		if ( !item )
			return 0;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Túi Đoạn Thạch nhận được "HIY "%s "NOR ".", who->get_name(),item->get_name() ));
	}
	return 0;
}

