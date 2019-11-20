#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Lễ Bao Cáo Lỗi");
        set_picid_1(4982);
        set_picid_2(4982);
        set_value(10);
		set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Lễ Bao cáo lỗi đánh Boss không rớt đồ, mở sẽ nhận được random đồ có thể nhận trong Boss. "; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,m,n,b;
	object item, item1, item2, item3, item4;
	
	if(USER_INVENTORY_D->get_free_count(who) < 4 )
		{
				notify( "Hành trang không đủ 4 chỗ trống" );
		return 0;
		}
	// Item 0 nguyên liệu
	switch( random(5) )
		                {
		               case 0 : item = new( "/item/nangcap/banhngot" );  break; 
		               case 1 : item = new( "/item/nangcap/dathan" );  break; 	
                       case 2 : item = new( "/item/nangcap/canhpp/ngoctiende" );  break; 	
                       case 3 : item = new( "/item/nangcap/canhpp/lenhthienton" );  break; 	
                       case 4 : item = new( "/item/nangcap/canhpp/canhthienthan" ); break;  
							default: break;
		                }
	if ( item )
	{		
		p = item->move2(who);
		item->add_to_user(p);			
	}
	// Item 3 nguyên liệu
	switch( random(5) )
		                {
		               case 0 : item3 = new( "/item/nangcap/banhngot" );  break; 
		               case 1 : item3 = new( "/item/nangcap/dathan" );  break; 	
                       case 2 : item3 = new( "/item/nangcap/canhpp/ngoctiende" );  break; 	
                       case 3 : item3 = new( "/item/nangcap/canhpp/lenhthienton" );  break; 	
                       case 4 : item3 = new( "/item/nangcap/canhpp/canhthienthan" ); break;
					default: break;					   
		                }
	if ( item3 )
	{		
		b = item3->move2(who);
		item3->add_to_user(b);			
	}
	
	// Item 2 Đồ phụ
	switch( random(4) )
		                {		            
                       case 0 : item2 = new( "/item/08/0016" );  break;	
                       case 1 : item2 = new( "/item/08/0017" );  break;                   
                       case 2 : item2 = new( "/item/test2/TuiQuaVoSong" );  break; 
		               case 3 : item2 = new( "/item/test2/TuiPhapBao" );  break;
						default: break;
		                }
	if ( item2 )
	{		
		n = item2->move2(who);
		item2->add_to_user(n);			
	}
	
	// Item 1 Đoạn thạch
	switch( random(2) )
		                {
		               case 0 : item1 = new( "/item/sell/0032" );  break; 
		               case 1 : item1 = new( "/item/sell/1032" );  break; 	               
							default: break;
		                }				

	if ( item1 )
	{
		m = item1->move2(who);
		item1->add_to_user(m);	
	}
	
		gift->add_amount(-1);
	
	return 0;
}

