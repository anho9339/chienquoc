#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Qùa Tân Thủ");
        set_picid_1(4980);
        set_picid_2(4981);
		set_level(10);
        set_value(10000);
		        set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Túi Qùa Tân Thủ.\n Sau khi sử dụng nhận được :\n" HIC" Túi Hoàng Kim Tân Thủ (Cấp 20)\n" HIC" Phục Dược +20\n" HIC" Trị Dược +20\n "HIR" Hỏa Phù (Khóa) +20\n";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m,n,q;
	object item,item1,item2,item3,item4,item5;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;
	if ( who->get_level() < 10 )
	{
		        send_user(who,"%c%s",'!',"Cấp 10 có thể sử dụng.");
    		return 0;
	}
	if(USER_INVENTORY_D->get_free_count(who) < 4 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}
	TASK_LEGEND_D->check_task_item1(who,"Túi Qùa Tân Thủ",1);
	TASK_LEGEND_D->check_task_item2(who,"Túi Qùa Tân Thủ",1);
	TASK_LEGEND_D->check_task_item3(who,"Túi Qùa Tân Thủ",1);
	TASK_LEGEND_D->check_task_item4(who,"Túi Qùa Tân Thủ",1);

	who->add_cash(5000);
//	who->set_level(10);
	/*cFile = "item/tuiquatanthuhieu/TanThuKiNang";
		item = new(cFile);
			i = item->move2(who,-1);
			item->add_to_user(i); */
		
	/*	item1 = new(sprintf("item/ngoai_trang/ngoaitrang%d",gender));
	k = item1->move2(who,-1);
	item1->add_to_user(k); */
	
	item2 = new("item/tuiquatanthuhieu/0008");
	item2->set_amount(20);
	l = item2->move2(who,-1);
	item2->add_to_user(l);
	item2->set_no_give(1);		

	item3 = new("item/tuiquatanthuhieu/0010");
	item3->set_amount(20);
	m = item3->move2(who,-1);
	item3->add_to_user(m);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR "20 Trị Dược + Phục Dược.");
	item3->set_no_give(1);	

	item4 = new("item/tuiquatanthuhieu/HoaPhuK");
	item4->set_amount(20);	
	n = item4->move2(who,-1);
	item4->add_to_user(n);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR "20 Hỏa Phù (Khóa).");


	item5 = new("item/tuiquatanthuhieu/hk20");		
	q = item5->move2(who,-1);
	item5->add_to_user(q);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR "Túi Hoàng Kim Cấp 20.");
	item5->set_no_give(1);			
        
		
/*		item = new(sprintf("item/tuiquatanthuhieu/cap10"));
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p); */

}