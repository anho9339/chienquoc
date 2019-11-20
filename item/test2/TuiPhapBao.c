#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Pháp Bảo");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(10);
	//	set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Túi thần kỳ, có thể mở ra rất nhiều loại Pháp Bảo và vật phẩm đáng giá"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,l;
	object item,doanthach;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	rate = random(100);
	
	if ( rate < 1 )	//Bảo Để Phù
	{
		doanthach = new("item/sell/0034");
		if ( !doanthach )
			return 0;
	}
	else if ( rate < 10 )	//Cao Cấp đoạn thạch
	{
		// mặc định rate 1
		doanthach = new("item/sell/2032");
		if ( !doanthach )
			return 0;
	}
	else if ( rate < 25 )		//Chuông hám thiên
	{
		item = new("item/mop/9562");
		if ( !item )
			return 0;
	}
	else if ( rate < 20 )	//zz
	{
		item = new("item/30/3024");
		if ( !item )
			return 0;
	}
	else if ( rate < 30 )	//Cửu Long Thần HỎa Trảo
	{
		item = new("item/mop/9512");
		if ( !item )
			return 0;
	}
	else if ( rate < 35 )	//Trung Cấp đoạn thạch
	// mặc định rate 31
	{		
		doanthach = new("item/sell/1032");
		if ( !doanthach )
			return 0;
	}
	else if ( rate < 40 )	//Khu Thần Lệnh
	{
		item = new("item/mop/9542");
		if ( !item )
			return 0;
	}
	else if ( rate < 45 )	//Thổ Hành Châu
	{
		item = new("item/mop/9552");
		if ( !item )
			return 0;
	}
	else if ( rate < 50 )	//Linh Tê Hoàn
	{
		item = new("item/mop/9532");
		if ( !item )
			return 0;
	}
	else if ( rate < 55 )	//Sơ Cấp đoạn thạch 
	// mặc định rate 51
	{
		doanthach = new("item/sell/0032");
		if ( !doanthach )
			return 0;
	}
	else if ( rate < 60 )	//Nhiếp hồn linh
	{
		item = new("item/mop/9522");
		if ( !item )
			return 0;
	}
	else if ( rate < 70 )	//法力石
	{
		item = new("item/30/3024f");
		if ( !item )
			return 0;
	}
	else if ( rate < 75 )	//法力石
	{
		item = new(sprintf("item/%d/1075",70+random(6)));
		if ( !item )
			return 0;
	}
	else if ( rate < 80 )	//法力石
	{
		item = new("item/30/3027");
		if ( !item )
			return 0;
	}
	else if ( rate < 85 )	//法力石
	{
		item = new("item/100/10051");
		if ( !item )
			return 0;
	}
	else if ( rate < 90 )	//法力石
	{
		item = new("item/100/11051");
		if ( !item )
			return 0;
	}
	else if ( rate < 95 )	//法力石
	{
		item = new("item/30/3034");
		if ( !item )
			return 0;
	}
	else 			//乾坤袋
	{
		item = new("item/30/3036");
		if ( !item )
			return 0;
	}
/*	else if ( rate < 75 )	//法力石
	{
		item = new(sprintf("/item/93/%d", 9301+random(10)));
		item->set_level(4);
		if ( !item )
			return 0;
	}*/	
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		//USER_D->user_channel(sprintf("Bằng hữu %s mở Túi Pháp Bảo nhận được %s ", who->get_name(),item->get_name() ));	
	}
	else if ( doanthach )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+doanthach->get_name());
		l = doanthach->move2(who);
		doanthach->add_to_user(l);
		USER_D->user_channel(sprintf("Bằng hữu "HIR"%s"NOR" mở Túi Pháp Bảo nhận được "HIY" %s ", who->get_name(),doanthach->get_name() ));	
	}
	return 0;
}

