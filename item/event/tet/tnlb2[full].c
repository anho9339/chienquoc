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
        return "Lễ bao chúc phúc, do Niên Thú cất giữ, có thể mở ra rất nhiều bảo vật quý hiếm. "; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,m,n,b,k;
	object item, item1, item2, item3, item4;
	
	if(USER_INVENTORY_D->get_free_count(who) < 5 )
		{
				notify( "Hành trang không đủ 5 chỗ trống" );
		return 0;
		}
		
		//Random tiền
	//	who->add_cash(10000+random(30000));
			
	// Item 0 nguyên liệu
	item = new("item/event/tet/mghkl");
		item->set_amount(1+random(4));
	k = item->move2(who,-1);
		item->add_to_user(k);
   // Item 1 Đoạn thạch
/*	switch( random(3) )
		                {
		               case 0 : item1 = new( "/item/sell/0032" );  break; 
		               case 1 : item1 = new( "/item/sell/1032" );  break; 	
                       case 2 : item1 = new( "/item/sell/2032" );  break;                 					   
		                }				

	if ( item1 )
	{
		m = item1->move2(who);
		item1->add_to_user(m);
         USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Đại Lễ Bao nhận được "HIY "%s "NOR ".", who->get_name(),item1->get_name() ));		
	}
	*/
	// Item 2 Đồ phụ
	switch( random(4) )
		                {		            
                       case 0 : item2 = new( "/item/08/0016" );  break;	
                       case 1 : item2 = new( "/item/08/0017" );  break;                   
                       case 2 : item2 = new( "/item/test2/TuiQuaVoSong" );  break; 
		               case 3 : item2 = new( "/item/test2/TuiPhapBao" );  break; 					   
		                }
	if ( item2 )
	{		
		n = item2->move2(who);
		item2->add_to_user(n);			
	}

	// Item 3 nguyên liệu
	switch( random(5) )
		                {
		               case 0 : item3 = new( "/item/nangcap/banhngot" );  break; 
		               case 1 : item3 = new( "/item/nangcap/dathan" );  break; 	
                       case 2 : item3 = new( "/item/nangcap/canhpp/ngoctiende" );  break; 	
                       case 3 : item3 = new( "/item/nangcap/canhpp/lenhthienton" );  break; 	
                       case 4 : item3 = new( "/item/nangcap/canhpp/canhthienthan" ); break;     					   
		                }
	if ( item3 )
	{		
		b = item3->move2(who);
		item3->add_to_user(b);			
	}

	// Item 4 Tinh thạch
	switch( random(2) )
		                {
		               case 0 : item4 = new( "item/TuiLinhThach/NgauNhien/2" );  break; 
		               case 1 : item4 = new( "item/TuiLinhThach/NgauNhien/3" );  break; 	
          //             case 2 : item4 = new( "item/TuiLinhThach/NgauNhien/4" );  break; 	                                     					   
		                }
	if ( item4 )
	{		
		b = item4->move2(who);
		item4->add_to_user(b);	
        USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Đại Lễ Bao nhận được "HIY "%s "NOR ".", who->get_name(),item4->get_name() ));		
	}

		gift->add_amount(-1);
	
	return 0;
}
