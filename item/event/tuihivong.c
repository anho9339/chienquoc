#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }


void create()
{
        set_name("Túi Hi Vọng");
        set_picid_1(9995);
        set_picid_2(9995);
        set_amount(1);
        set_value(200);
}

int is_usable() {return 1;}


int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{ 
        return "Quà của thần tiên ban tặng nông dân ngày xưa thường sử dụng để giúp người dân có thêm hi vọng trong cuộc sống."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,level,exp,cash;
	object item;
  
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",';',"Hành trang của bạn đã đầy, xin vui lòng dọn sạch rồi hãy sử dụng");
    		return 0;
	}
	rate = random(100);

	if (rate<5) 
		 switch( random(3) )
		                {
						case 0 : item = new( "/item/dtkhoa/0032" );  break; 
						case 1 : item = new( "/item/dtkhoa/1032" );  break;	
						case 2 : item = new( "/item/dtkhoa/2032" );  break;	
						} 
		
	/*else if (rate<20) 
		 switch( random(3) )
		                { 
						case 0 : item = new ("/item/nangcap2/canhpp/dathienmenh");  break; 
						case 1 : item = new ("/item/nangcap2/canhpp/longhuyenvu");  break; 
						case 2 : item = new ("/item/nangcap2/canhpp/vaithienthan");  break; 	
						}  */
	else if (rate<20) 
		 switch( random(2) )
		                { 
						case 0 : item = new( "/item/bikipknb/knb3" );  break;	
						case 1 : item = new( "/item/bikipknb/knb5" );  break;	
						} 
							
	/*else if (rate<40) 
		 switch( random(5) )
		                { 
						case 0 : item = new ("/item/nangcap/banhngot"); break;
						case 1 : item = new ("/item/nangcap/dathan"); break;
						case 2 : item = new ("/item/nangcap/canhpp/canhthienthan"); break;
						case 3 : item = new ("/item/nangcap/canhpp/lenhthienton"); break;
						case 4 : item = new ("/item/nangcap/canhpp/ngoctiende"); break;	 
						} */
	else if (rate<40) 
		 switch( random(3) )
		                { 
						case 0 : item = new( "/item/test/datuonguyen" );  break;	
						case 1 : item = new( "/item/test/dacankhon" );  break;
						case 2 : item = new( "/item/sell/0033" );  break;
						}  
	else if (rate<50) {
	item = new ("/item/event/huyenbangnhan");
	item->set_amount(2+random(2));
	}
	else if (rate<60) {
			who->add_cash(2000+random(1000));
			send_user(who,"%c%s",'!',sprintf("Bạn nhận được lượng lớn ngân lượng."));
		}
	else if (rate<70)
		who->add_exp(2000+random(1000));
	else if (rate<80) {
			who->add_cash(800+random(100));
			send_user(who,"%c%s",'!',sprintf("Bạn nhận được một ít ngân lượng."));
		}
	else if (rate<90)	
		who->add_exp(800+random(100));
	
	if ( item )
	{
		CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG" mở túi hi vọng ,đạt được "HIY"%s"HIG"！",who->get_name(),item->get_name()));
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được vật phẩm %s từ Túi Hi Vọng.",item->get_name()));
		p = item->move2(who);
		item->add_to_user(p);	
	}

	gift->add_amount(-1);
	return 0;
}