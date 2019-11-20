#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 3 ;}
int get_item_value_2() {return 3 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Rương Mảnh Ghép Hoàng Kim");
        set_picid_1(0080);
        set_picid_2(0080);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Rương Mảnh Ghép Hoàng Kim \nMở ra có thể nhận được Mảnh Ghép"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	
	rate = random(100);
	
	if ( rate < 10 )		//战国令
	{
		item = new("item/test2/1011");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else if ( rate < 30 )	//血石
	{
		item = new("item/test2/1008");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else if ( rate < 50 )	//血石
	{
		item = new("item/test2/1012");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else if ( rate < 70 )	//法力石
	{
		item = new("item/test2/1013");
		item->set_amount(1);
		if ( !item )
			return 0;
	}
	else if ( rate < 85 )
	{
		cash = 150000;
	}
	else 			//乾坤袋
	{
		cash = 200000;
	}
//	gift->remove_from_user();
//	destruct(gift);
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Rương Mảnh Ghép nhận được "HIR "%s "NOR " . ", who->get_name(),item->get_name() ));	
	}
	else if (  cash )
	{
		who->add_cash(cash);
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d ngân lượng",cash));
	}
	return 0;
}

