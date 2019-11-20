#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi quà Sự kiện");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(1);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Túi quà có được khi tham gia sự kiện, \n2 quyển Bí kíp Nhập môn, Sơ Trị Dược và Sơ Phục Dược."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item,item1,item2,item3;
	
	if(USER_INVENTORY_D->get_free_count(who) < 5 )
		{
				notify( "Hành trang không đủ 5 chỗ trống" );
		return 0;
		}
	gift->add_amount(-1);
		/*cash = 500000+random(1500000);
		who->add_cash(cash);*/
		item1 = new(BOOK_FILE->get_book_file());
		p = item1->move2(who);
		item1->add_to_user(p);
		item2 = new(BOOK_FILE->get_book_file());
		p = item2->move2(who);
		item2->add_to_user(p);
		/*item3 = new(BOOK_FILE->get_book_file());
		p = item3->move2(who);
		item3->add_to_user(p);*/
		item = new("/item/sell/0007");
		item->set_amount(10);
		p = item->move2(who);
		item->add_to_user(p);
		item = new("/item/sell/0009");
		item->set_amount(10);
		p = item->move2(who);
		item->add_to_user(p);
	send_user(who,"%c%s",';',sprintf("Bạn nhận được %s, %s, 10 Sơ Trị Dược, 10 Sơ Phục Dược.", item1->get_name(), item2->get_name()()));	
//	USER_D->user_channel(sprintf("Bằng hữu %s tham gia sự kiện mở Túi quà Sự kiện nhận được rất nhiều vật phẩm quý giá !", who->get_name() ));
//	USER_D->user_channel(sprintf("Bằng hữu %s tham gia sự kiện mở Túi quà Sự kiện nhận được rất nhiều vật phẩm quý giá !", who->get_name() ));
	return 0;
}

