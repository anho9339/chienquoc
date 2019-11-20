#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Đại Lễ Bao");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(10);
		set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Lễ bao chúc phúc, do Niên Thú cất giữ, nghe nói có chứa nhiều bảo vật quý hiếm. "; 
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
	
	if ( rate < 10 )		//战国令
	{
		item = new("item/TuiLinhThach/NgauNhien/4");
		if ( !item )
			return 0;
	}
	
	if ( rate < 100 )		//战国令
	{
		switch( random(6) )
		                {
		               case 0 : item = new( "item/final/15/1525" );  break; 
		               case 1 : item = new( "item/final/15/1528" );  break; 	
                       case 2 : item = new( "item/final/15/1527" );  break;
                       case 3 : item = new( "item/final/15/1529" );  break;
                       case 4 : item = new( "item/final/15/1524" );  break;  
	                   case 5 : item = new( "item/final/15/1526" );  break;	
						default: break;
		                }
		if ( !item )
			return 0;
	}
	else if ( rate < 1000 )	//战国号角
	{
		switch( random(3) )
		                {
		               case 0 : item = new( "item/TuiLinhThach/NgauNhien/1" );  break; 
		               case 1 : item = new( "item/TuiLinhThach/NgauNhien/2" );  break; 	
                       case 2 : item = new( "item/TuiLinhThach/NgauNhien/3" );  break; 
						default: break;
		                }
		if ( !item )
			return 0;
	}
	else if ( rate < 5000)	//战国号角
	{
		switch( random(5) )
		                {
		               case 0 : item = new( "/item/nangcap/banhngot" );  break; 
		               case 1 : item = new( "/item/nangcap/dathan" );  break; 	
                       case 2 : item = new( "/item/nangcap/canhpp/ngoctiende" );  break; 	
                       case 3 : item = new( "/item/nangcap/canhpp/lenhthienton" );  break; 	
                       case 4 : item = new( "/item/nangcap/canhpp/canhthienthan" ); break;   
						default: break;
		                }
						item->set_amount(1+random(2));
		if ( !item )
			return 0;
	}
	else if ( rate < 6000 )	//战国号角
	{
		switch( random(4) )
		                {		            
                       case 0 : item = new( "/item/08/0016" );  break;	
                       case 1 : item = new( "/item/08/0017" );  break;                   
                       case 2 : item = new( "/item/test2/TuiQuaVoSong" );  break; 
		               case 3 : item = new( "/item/test2/TuiPhapBao" );  break; 
						default: break;
		                }
						item->set_amount(1+random(2));
		if ( !item )
			return 0;
	}
	else if ( rate < 7000 )	//战国号角
	{
		item = new("item/event/tet/mghkl");
		item->set_amount(1+random(3));
		if ( !item )
			return 0;
	}
	else 			//乾坤袋
	{
		item = new("item/TuiLinhThach/NgauNhien/1");
		if ( !item )
			return 0;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Đại Lễ Bao nhận được "HIY "%s "NOR ".", who->get_name(),item->get_name() ));
	}
	return 0;
}

