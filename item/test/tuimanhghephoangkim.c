#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 40 ;}
int get_item_value_2() {return 40 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Rương Mảnh Ghép Hoàng Kim");
        set_picid_1(9913);//0080
        set_picid_2(9913);
        set_value(1);
	//	set_save("knb",40);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra có thể nhận được các loại Mảnh Ghép khác nhau \ndùng cho Sự kiện Hợp Thành Vật Phẩm."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,z,x,y;
	object item;
	
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return 0;
		}
	rate = random(100);
	
	if ( rate < 20 )	//血石
	{
		item = new("item/test2/1007");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else if ( rate < 40 )	//血石
	{
		item = new("item/test2/1008");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else if ( rate < 70 )	//血石
	{
		item = new("item/test2/1012");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else 			//乾坤袋
	{
		item = new("item/test2/1013");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
	}
	return 0;
}

