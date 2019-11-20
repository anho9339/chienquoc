#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 200 ;}
int get_item_value_2() {return 200 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Thú Cưỡi");
        set_picid_1(3853);
        set_picid_2(3853);
        set_value(1);
		set_amount(1);
		set_save("knb",300);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Túi quà thú cưỡi, mở ra sẽ nhận được thú cưỡi quí hiếm 7 ngày (Dùng trong nâng cấp)."; 
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
	
	if ( rate < 7 )		//战国令
	{
		item = new("item/ride/010");
		item->set_amount(5);
		if ( !item )
			return 0;
	}
	else if ( rate < 14 )	//战国号角
	{
		item = new("item/ride/026");
		item->set_amount(4);
		if ( !item )
			return 0;
	}
	else if ( rate < 24 )	//血石
	{
		item = new("item/ride/028");
		item->set_amount(3);
		if ( !item )
			return 0;
	}
	else if ( rate < 34 )	//血石
	{
		item = new("item/ride/030");
		item->set_amount(2);
		if ( !item )
			return 0;
	}
	else if ( rate < 44 )	//法力石
	{
		item = new("item/ride/032");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else if ( rate < 54 )	//法力石
	{
		item = new("item/ride/034");
		if ( !item )
			return 0;
	}
	else if ( rate < 64 )	//法力石
	{
		item = new("item/ride/036");
		if ( !item )
			return 0;
	}
	else if ( rate < 74 )	//百宝囊
	{
		item = new("item/ride/038");
		if ( !item )
			return 0;
	}
	else if ( rate < 84 )	//百宝囊
	{
		item = new("item/ride/040");
		if ( !item )
			return 0;
	}
	else if ( rate < 94 )	//百宝囊
	{
		item = new("item/ride/044");
		if ( !item )
			return 0;
	}
	else 			//乾坤袋
	{
		item = new("item/ride/042");
		if ( !item )
			return 0;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu %s mở Túi Thần Thú nhận được %s ", who->get_name(),item->get_name() ));	
	}
	return 0;
}

