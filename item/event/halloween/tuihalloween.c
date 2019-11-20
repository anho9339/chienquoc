#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Quà Halloween");
        set_picid_1(3105);
        set_picid_2(3105);
        set_value(10);
		set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Túi quà Halloween chứa những thứ thần bí và nguy hiểm."; 
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
	rate = random(10000);
	
	if ( rate < 100 )		//Sơ cấp
	{
		item = new("item/sell/0032");
		if ( !item )
			return 0;
	}
	else if ( rate < 500 )	//TLT 2
	{
		item = new("item/TuiLinhThach/NgauNhien/2");
		if ( !item )
			return 0;
	}
	else if ( rate < 1000 )	// DAo Nhan Y 7 ngay
	{
		item = new("item/event/halloween/daonhany");
		if ( !item )
			return 0;
	}
	else if ( rate < 1100 )	// DAo Nhan Y Nữ 7 ngay
	{
		item = new("item/event/halloween/daonhanynu");
		if ( !item )
			return 0;
	}
	else if ( rate < 4000 )	//KNB 2
	{
		item = new("item/bikipknb/knb3");
		if ( !item )
			return 0;
	}
	else if ( rate < 6000 )	//10k Ngan luong
	{
		item = new("item/event/halloween/bikipnganluong");
		if ( !item )
			return 0;
	}
	else if ( rate < 2000 )	//TSD
	{
		item = new("item/91/9167");
		if ( !item )
			return 0;
	}
	else if ( rate < 7000 )	//2 KNB
	{
		item = new("item/bikipknb/knb2");
		if ( !item )
			return 0;
	}
	else 			
	{
		item = new("item/bikipknb/knb1");
		if ( !item )
			return 0;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
	//	USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Đại Lễ Bao nhận được "HIY "%s "NOR ".", who->get_name(),item->get_name() ));
	}
	return 0;
}

