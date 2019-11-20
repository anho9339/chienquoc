#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Hên Xui");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Mở ra sẽ nhận được hên xui các vật phẩm cường hóa và KNB."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	
	rate = random(150);
	
	if ( rate < 35 )		//战国令
	{
		item = new("item/final/15/1525");
		if ( !item )
			return 0;
	}
	else if ( rate < 45 )	//战国号角
	{
		item = new("item/final/15/1528");
		if ( !item )
			return 0;
	}
	else if ( rate < 55 )	//战国号角
	{
		item = new("item/final/15/1527");
		if ( !item )
			return 0;
	}
	else if ( rate < 65 )	//战国号角
	{
		item = new("item/final/15/1529");
		if ( !item )
			return 0;
	}
	else if ( rate < 75 )	//战国号角
	{
		item = new("item/final/15/1524");
		if ( !item )
			return 0;
	}
	else if ( rate < 85 )	//战国号角
	{
		item = new("item/final/15/1526");
		if ( !item )
			return 0;
	}
	else if ( rate < 95 )	//战国号角
	{
		item = new("item/test2/TichLuy/BiKipKNB5");
		if ( !item )
			return 0;
	}
/*	else if ( rate < 105 )	//战国号角
	{
		item = new("item/test/tuihoangkimtanthucap100");
		if ( !item )
			return 0;
	}
	else if ( rate < 115 )	//战国号角
	{
		item = new("item/test/tuihoangkimtanthucap80");
		if ( !item )
			return 0;
	}
	else if ( rate < 125 )	//战国号角
	{
		item = new("item/test/tuihoangkimtanthucap60");
		if ( !item )
			return 0;
	} */
	else 			//乾坤袋
	{
		item = new("item/01/0202");
		if ( !item )
			return 0;
	}
	gift->add_amount(-1);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Túi Hên Xui nhận được "HIY "%s "NOR ".", who->get_name(),item->get_name() ));
	}
	return 0;
}

