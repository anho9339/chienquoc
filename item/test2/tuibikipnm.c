#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Túi Bí Kíp Nhập Môn");
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
        return "Mở ra có cơ hội nhận được ngẫu nhiên bí kíp nhập môn của các phái."; 
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
	
	gift->add_amount(-1);

	    item = new(BOOK_FILE->get_book_file());
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
	//	USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Túi Bí Kíp Nhập Môn nhận được "HIY "%s "NOR ".", who->get_name(),item->get_name() ));
	
	return 0;
}

