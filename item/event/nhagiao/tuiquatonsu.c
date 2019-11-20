#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 2; }


void create()
{
        set_name("Túi Tôn Sư Trọng Đạo");
        set_picid_1(9995);
        set_picid_2(9995);
        set_amount(1);
        set_value(5000);
}

int is_usable() {return 1;}


int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc()
{ 
        return "Túi quà tôn sư trọng đạo, tham gia event có được. Bên trong có nhiều vật phẩm quí."; 
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
	string *nFamily = ({"Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
	int *bian=({1267,1238,1225,1201,1200});
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",';',"Hành trang của bạn đã đầy, xin vui lòng dọn sạch rồi hãy sử dụng");
    		return 0;
	}
	rate = random(100);
	
	 if (rate<3)
		item = new ("/item/sell/0032");	
	else if (rate<8)
		item = new ("item/test2/TuiPhapBao");	
	else if (rate<10)
		item = new ("item/TuiLinhThach/NgauNhien/2");
	else if (rate<20) 
	   item = new ("item/08/0001");
	else if (rate<30)
		item = new ("item/TuiLinhThach/NgauNhien/1");
    else if (rate<50) 
	   item = new ("/item/event/huyenbangnhan");
	else if (rate<60) 
	   item = new ("item/sell/0009");
	else if (rate<70) 
	   item = new ("item/sell/0007");
	else if (rate<80)
		who->add_cash(5000);
	else if (rate<100)
		who->add_exp(12345);

	
	if ( item )
	{
		CHAT_D->sys_channel(0,sprintf(HIY"%s"HIG" mở túi hi vọng ,đạt được "HIY"%s"HIG"！",who->get_name(),item->get_name()));
		p = item->move2(who);
		item->add_to_user(p);	
	}
	else if (who->add_cash(1000))
	{
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được 1000 vàng",cash));
	}		
	else if (who->add_exp(1000))
	{
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được 1000 kinh nghiệm",exp));
	}
	gift->add_amount(-1);
	return 0;
}