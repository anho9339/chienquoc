#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 300 ;}
int get_item_value_2() {return 300 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Đoạn Thạch");
        set_picid_1(7108);
        set_picid_2(7108);
        set_value(10);
	//	set_save("knb",300);
		set_amount(1);
		set_save("tienxu",10);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra để nhận Đoạn Thạch ngẫu nhiên, ngoài ra còn có cơ hội nhận Đoạn Thạch "HIY"Kết Dính "NOR"và "HIR"Cường, Thượng."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	rate = random(100);
	
	if ( rate < 1 )	//Đặc biệt
	{
		 switch( random(2) )
		{
		case 1: item = new("item/sell/3032_1"); break;  //10% tính cả vip
		case 2: item = new("item/sell/3032_2"); break;  //20% tính cả vip
		}	
		if ( !item )
			return 0;
	}
	else if ( rate < 11 )	
	{
		item = new("item/sell/3032");
		if ( !item )
			return 0;
	}
	else if ( rate < 10 )	
	{
		item = new("item/sell/0034");
		if ( !item )
			return 0;
	}
	else if ( rate < 40 ) 		
	{
	 item = new("item/sell/2032");
		if ( !item )
			return 0;
	}
	else if ( rate < 60 ) 		
	{
	 item = new("item/sell/1032");
		if ( !item )
			return 0;
	}		
	else 			
	{		
		 item = new("item/sell/0032");     		
		if ( !item )
			return 0;
	} 
	
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu %s mở Túi Đoạn Thạch nhận được %s ", who->get_name(),item->get_name() ));	
	}
	return 0;
}

