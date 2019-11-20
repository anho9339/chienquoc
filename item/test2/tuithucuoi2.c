#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 150 ;}
int get_item_value_2() {return 150 ;}
int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Túi Thú Cưỡi Đặc Sắc");
        set_picid_1(3853);
        set_picid_2(3853);
        set_value(1);
		set_amount(1);
		set_save("knb",250);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Túi quà thú cưỡi, mở ra sẽ nhận được thú cưỡi bình thường 7 ngày (Tiềm ẩn)."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	
	rate = random(130);
	
	if ( rate < 7 )		//Ưng chiến
	{
		item = new("item/ride/009");
		item->set_amount(5);
		if ( !item )
			return 0;
	}
	else if ( rate < 14 )	//Mèo hề
	{
		item = new("item/ride/013");
		item->set_amount(4);
		if ( !item )
			return 0;
	}
	else if ( rate < 24 )	//Nhện kiến
	{
		item = new("item/ride/014");
		item->set_amount(3);
		if ( !item )
			return 0;
	}
	else if ( rate < 34 )	//Thảm bay
	{
		item = new("item/ride/015");
		item->set_amount(2);
		if ( !item )
			return 0;
	}
	else if ( rate < 44 )	//cá voi máy
	{
		item = new("item/ride/016");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	/*else if ( rate < 54 )	//Xe giáng sinh (Đặc biệt)
	{
		item = new("item/ride/017");
		if ( !item )
			return 0;
	}
	else if ( rate < 64 )	//Hỏa kì lân (Đặc biệt)
	{
		item = new("item/ride/018");
		if ( !item )
			return 0;
	} */
	else if ( rate < 74 )	//Chó Iloveyou
	{
		item = new("item/ride/019");
		if ( !item )
			return 0;
	}
	else if ( rate < 84 )	//Tuần Lộc Địa
	{
		item = new("item/ride/056");
		if ( !item )
			return 0;
	}
	else if ( rate < 94 )	//Hồ Ly Tinh
	{
		item = new("item/ride/057");
		if ( !item )
			return 0;
	}
	else if ( rate < 104 )	//Rùa vàng
	{
		item = new("item/ride/059");
		if ( !item )
			return 0;
	}
	else if ( rate < 114 )	//Ngựa Gỗ Thần Tiên
	{
		item = new("item/ride/061");
		if ( !item )
			return 0;
	}
	else if ( rate < 124 )	//Voi tím
	{
		item = new("item/ride/062");
		if ( !item )
			return 0;
	}
	else 			//Gấu chiến binh 
	{
		item = new("item/ride/060");
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

