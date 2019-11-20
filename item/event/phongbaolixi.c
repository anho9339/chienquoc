#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Túi Quà May Mắn");
        set_picid_1(9985);
        set_picid_2(9985);
        set_value(10);
	//	set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Túi quà tặng cho bằng hữu Chiến Quốc, sử dụng sẽ nhận được các phần quà ý nghĩa."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object me,object gift) 
{
	int rate,p,cash,exp;
	object item;
	gift->add_amount(-1);
			if(USER_INVENTORY_D->get_free_count(me) < 2 )
			{
			send_user(me,"%c%c%w%s",':',3,6010,"Sứ Giả Năm Mới :\nHành trang của ngươi không đủ 2 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return 0;
			}
	if ( random100() < 30 )
	{
	me->add_exp(100000);
	send_user(me, "%c%s", ';', sprintf("Bạn đã nhận được %d kinh nghiệm, xin chúc mừng !",100000));
	}
	else if ( random100() < 50 )
	{
	"/sys/sys/test_db"->add_yuanbao(me,50);
	send_user(me, "%c%s", ';', sprintf("Bạn đã nhận được %d Kim Bảo, xin chúc mừng !",5));
	}
	else if ( random100() < 65 )
	{
	me->add_cash(120000);
	send_user(me, "%c%s", ';', sprintf("Bạn đã nhận được %d ngân lượng, xin chúc mừng !",120000));
	}
	else if ( random100() < 75 )
	{
	me->add_cash(100000);
	send_user(me, "%c%s", ';', sprintf("Bạn đã nhận được %d ngân lượng, xin chúc mừng !",100000));
	}
	else if ( random100() < 90 )
	{
	me->add_cash(50000);
	send_user(me, "%c%s", ';', sprintf("Bạn đã nhận được %d ngân lượng, xin chúc mừng !",50000));
	}
	else
	{
	item = new("item/sell/0002");
	p = item->move2(me,-1);
	item->add_to_user(p);
	item = new("item/sell/0004");
	p = item->move2(me,-1);
	item->add_to_user(p);
	send_user(me, "%c%s", ';', "Bạn đã nhận được Đại Huyết Thạch và Đại Pháp Lực Thạch, xin chúc mừng !");
	}
	CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" đã mở Túi Quà May Mắn và nhận được phần quà đầy ý nghĩa !");
	return 0;
}

