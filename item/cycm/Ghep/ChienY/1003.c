#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 150 ;}
int get_item_value_2() {return 150 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Linh Thạch");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra sẽ nhận được ngẫu nhiên Linh Thạch từ cấp 1 đến cấp 4"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	
	rate = random(100);
	
	if ( rate < 15 )		//战国令
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(4);
		if ( !item )
			return 0;
	}
	else if ( rate < 35 )	//战国号角
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(3);
		if ( !item )
			return 0;
	}
	else if ( rate < 55 )	//战国号角
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(2);
		if ( !item )
			return 0;
	}
	else if ( rate < 75 )	//战国号角
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(2);
		if ( !item )
			return 0;
	}
	else if ( rate < 95 )	//战国号角
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(2);
		if ( !item )
			return 0;
	}
	else 			//乾坤袋
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(1);
		if ( !item )
			return 0;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Túi Linh Thạch nhận được "HIY "%s "NOR ".", who->get_name(),item->get_name() ));
	}
	return 0;
}

