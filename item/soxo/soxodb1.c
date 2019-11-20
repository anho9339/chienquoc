#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 3; }
int get_max_combined() { return 99; }

void create()
{
        set_name("Sổ Xố Đặc Biệt 1");
        set_picid_1(8503);
        set_picid_2(8503);
        set_amount(1);
        set_value(100);
}

int is_usable() {return 1;}


int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{ 
        return "Vé Số Đặc Biệt 1, có tỉ lệ ra được vật phẩm đặc biệt và ngân lượng cao."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,level,exp,cash;
	object item;
       	string *nTmp,tmp,cTmp,chat;
	string *nFamily = ({"Đào Hoa Nguyên","Thục Sơn","Cấm Vệ Quân","Đường Môn","Mao Sơn","Côn Luân","Vân Mộng Cốc"});
	int *bian=({1267,1238,1225,1201,1200});
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",';',"Hành trang của bạn đã đầy,xin vui lòng dọn sạch rồi hãy sử dụng");
    		return 0;
	}
	rate = random(100);
	if (rate<5)
	switch( random(3) )
		                {
						case 0 : item = new ("/item/dtkhoa/0032"); break;
						case 1 : item = new ("/item/dtkhoa/1032");  break;	
						case 2 : item = new ("/item/dtkhoa/2032");  break;
		                }	
	else if (rate < 20)  
		item = new( "/item/manhghep/mgbdp" );		
	else if (rate < 40) {
	item = new( "/item/manhghep/mgdt" );  
	item->set_amount(1+random(2));	
	}
	else if (rate<50) {
		who->add_cash(12000+random(1000));
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được lượng lớn ngân lượng."));
		}
		
	else if (rate<70)
		who->add_exp(12000+random(1000));
	
	else if (rate<80) {
		who->add_cash(10000+random(1000));
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được một ít ngân lượng."));
		}
		
	else if (rate<90)
	    who->add_exp(10000+random(1000));
	
	if ( item )
	{
		CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG" vừa mở Sổ Xố đặc biệt 1 ,đã nhận được "HIY"%s"HIG".Xin chúc mừng！",who->get_name(),item->get_name()));
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được vật phẩm %s từ sổ xố đặc biệt.",item->get_name()));
		p = item->move2(who);
		item->add_to_user(p);	
	}
	gift->add_amount(-1);
	return 0;
}