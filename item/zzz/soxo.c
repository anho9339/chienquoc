#include <ansi.h>
#include <task.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Túi Quà Xổ Số");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(10);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Phần thưởng nhận được khi tham gia sự kiện tại FanPage."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item,item1,item2,item3;
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
				notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
			}
	gift->add_amount(-1);
	item=new("item/sell/0032");
	p=item->move2(who,-1);
	item->add_to_user(p);
	who->add_cash(1000000);
	send_user(who,"%c%s",';',"Bạn nhận được Sơ Cấp Đoạn Thạch Thạch cùng 100 vạn lượng !");
	CHAT_D->sys_channel(0,"Bằng hữu "+who->get_name()+" tham gia sự kiện tại FanPage đã nhận được phần quà đầy ý nghĩa !");
	return 0;
}

