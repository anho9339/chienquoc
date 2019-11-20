#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Hàng");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(10);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra sẽ nhận được các phần thưởng bất ngờ."; 
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
	
	if ( rate < 1 )		
		item = new("item/dtkhoa/2032");
	
	else if (rate<5) {
		 switch( random(2) )
		                {
						case 0 : item = new( "/item/dtkhoa/0032" );  break; 
						case 1 : item = new( "/item/dtkhoa/1032" );  break;	
					//	case 2 : item = new( "/item/dtkhoa/2032" );  break;	
						} 
	}
	
	else if ( rate < 60 ) {
	switch( random(2) )
				{
				case 0 : item = new( "item/bikipknb/knb1" );  break; 
				case 1 : item = new( "item/bikipknb/knb2" );  break;		
				} 
	}
	else if ( rate < 70 ) {
	who->add_exp(1000+random(9000));	
	}
	else if ( rate < 90 ) {
	switch( random(4) )
		                {
						case 0 : item = new( "/item/manhghep/mgdt" );  break; 
						case 1 : item = new( "/item/manhghep/bdp" );  break;	
						case 2 : item = new("item/test/vosongdiemphieu"); break;
						case 3: item = new("item/event/huyenbangnhan"); break;
						}
						item->set_amount(1+random(2));
	}

	else 			//乾坤袋
	{
		who->add_cash(1000+random(9000));
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Túi Hàng nhận được "HIY "%s "NOR ".", who->get_name(),item->get_name() ));
	}
	return 0;
}

