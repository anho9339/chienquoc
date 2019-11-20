#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }
int get_max_combined() { return 100; }

void create()
{
        set_name("Sổ Xố Cao");
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
        return "Sử dụng có thể nhận được EXP, tiền, nguyên liệu và các item khác."; 
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
	if (rate<1)
	switch( random(2) )
		                {
						case 0 : item = new ("/item/bikipknb/knb2"); break;
						case 1 : item = new ("/item/bikipknb/knb1");  break;					                          						  					   
		                }
	else if (rate<20)
			    who->add_exp(600+random(100));				   			   
	else if (rate<60) {
		who->add_cash(1200+random(1000));
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được lượng lớn ngân lượng."));
		}
	else if (rate<70)
		who->add_exp(1200+random(1000));
	else if (rate<80) {
		who->add_cash(600+random(100));
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được một ít ngân lượng."));
		}
	else if (rate<90)
		switch( random(5) )
		                {
						case 0 : item = new( "/item/nangcap/banhngot" );  break; 
						case 1 : item = new( "/item/nangcap/dathan" );  break;
						case 2 : item = new( "/item/nangcap/canhpp/ngoctiende" );  break; 
						case 3 : item = new( "/item/nangcap/canhpp/canhthienthan" );  break;
						case 4 : item = new( "/item/nangcap/canhpp/lenhthienton" );  break;	
						}

	if ( item )
	{
	//	CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG" vừa trúng sổ xố 3 ,đã nhận được 1 "HIY"%s"HIG".Xin chúc mừng！",who->get_name(),item->get_name()));
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được vật phẩm %s từ sổ xố 3.",item->get_name()));
		p = item->move2(who);
		item->add_to_user(p);	
	}
	/*else if (who->add_cash(300))
	{
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d vàng",cash));
	}		
	else if (who->add_exp(300))
	{
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d kinh nghiệm",exp));
	} */
	gift->add_amount(-1);
	return 0;
}