#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 200 ;}
int get_item_value_2() {return 200 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Linh Thạch");
        set_picid_1(7108);
        set_picid_2(7108);
        set_value(10);
		set_save("knb",100);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra sẽ nhận được ngẫu nhiên Linh Thạch từ cấp 1 đến cấp 6"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item,capcao;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	rate = random(100);
	
	if ( rate < 1 )		//战国令
	{
		capcao = new(sprintf("/item/93/%d", 9301+random(10)));
		capcao->set_level(6);
		if ( !capcao )
			return 0;
	}
	else if ( rate < 11 )	//战国号角
	{
		capcao = new(sprintf("/item/93/%d", 9301+random(10)));
		capcao->set_level(5);
		if ( !capcao )
			return 0;
	}
	else if ( rate < 31 )	//战国号角
	{
		capcao = new(sprintf("/item/93/%d", 9301+random(10)));
		capcao->set_level(4);
		if ( !capcao )
			return 0;
	}
	else if ( rate < 65 )	//战国号角
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(3);
		if ( !item )
			return 0;
	}
	else if ( rate < 85 )	//战国号角
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
	if ( capcao )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+capcao->get_name());
		p = capcao->move2(who);
		capcao->add_to_user(p);	
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Túi Linh Thạch nhận được "HIY "%s "NOR ".", who->get_name(),capcao->get_name() ));
	}
	if (item ) 
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
	}
	return 0;
}

