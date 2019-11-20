#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Hộp Quà Thường");
        set_picid_1(3108);
        set_picid_2(3108);
        set_value(10);
	//	set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Hộp Quà Thường tham gia event 30/4 - 1/5 sẽ có"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,l;
	object item;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	rate = random(100);
	
	if ( rate < 10 )	//Bảo Để Phù
	{
		item = new("item/sell/0034");
		if ( !item )
			return 0;
	}
	else if ( rate < 20 )	//Cao Cấp đoạn thạch
	{
		// mặc định rate 1
		item = new("item/sell/2032");
		if ( !item )
			return 0;
	}
	else if ( rate < 30 )	//Trung Cấp đoạn thạch
	// mặc định rate 31
	{		
		item = new("item/sell/1032");
		if ( !item )
			return 0;
	}
	else if ( rate < 50 )	//Sơ Cấp đoạn thạch 
	// mặc định rate 51
	{
		item = new("item/sell/0032");
		if ( !item )
			return 0;
	}
	else if ( rate < 90 )	//法力石
	{
		who->add_save("tienxu",1+random(3));
	}
	else if ( rate < 95 )	//法力石
	{
		"sys/sys/test_db"->add_yuanbao(who,2+random(20)*10);	
	}
	else 			//乾坤袋
	{
		who->add_cash(100000+random(100000)) ;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu %s mở Hộp Quà Thường nhận được "HIY"%s ", who->get_name(),item->get_name() ));	
	}
	return 0;
}

