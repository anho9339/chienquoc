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
        set_name("Túi Quà Pret");
		set_picid_1(3106);
        set_picid_2(3106);
		set_level(0);
        set_value(5000);
		set_no_give(1);		
 
}

// 函数：获取描述
string get_desc( object me ) 
{
		return "Túi Quà Pret \nKích chuột phải để sử dụng \nTúi quà tri ân người chơi CQTD.\n";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m,n,q,w,a,s,d,j;
	object item,item1,item2,item3,item4,item5,item6,item7,item8,item9,item10;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;

	if(USER_INVENTORY_D->get_free_count(who) < 9 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}
	TASK_LEGEND_D->check_task_item1(who,"Túi Quà Pret",1);
	TASK_LEGEND_D->check_task_item2(who,"Túi Quà Pret",1);
	TASK_LEGEND_D->check_task_item3(who,"Túi Quà Pret",1); 
	TASK_LEGEND_D->check_task_item4(who,"Túi Quà Pret",1);
	TASK_LEGEND_D->check_task_item5(who,"Túi Quà Pret",1);
	TASK_LEGEND_D->check_task_item6(who,"Túi Quà Pret",1); 
	TASK_LEGEND_D->check_task_item7(who,"Túi Quà Pret",1);
	TASK_LEGEND_D->check_task_item7(who,"Túi Quà Pret",1);
	

	who->add_cash(500000);

		
		item1 = new("item/dtkhoa/0032");
		//item1->set_no_give(1);
		//	item1->set_amount(20);
	k = item1->move2(who,-1);
		item1->add_to_user(k);


		item7 = new("item/dtkhoa/1032");
		//item7->set_no_give(1);
		//	item1->set_amount(20);
	a = item7->move2(who,-1);
		item7->add_to_user(a);


		item2 = new("item/dtkhoa/2032");
		//item2->set_no_give(1);
		//	 item2->set_amount(2);
	l = item2->move2(who,-1);
		item2->add_to_user(l);
			

		item3 = new("item/test2/TuiPhapBao");
		item3->set_no_give(1);
		item3->set_amount(5);
	m = item3->move2(who,-1);
		item3->add_to_user(m);


		item4 = new("item/08/0006");	
		item4->set_no_give(1);	
		item4->set_amount(4);	   
	n = item4->move2(who,-1);
		item4->add_to_user(n);


		item5 = new("item/test2/TuiQuaVoSong");	
		item5->set_no_give(1);		   
		item5->set_amount(5);
	q = item5->move2(who,-1);
		item5->add_to_user(q);


		item6 = new("item/TuiLinhThach/NgauNhien/3");
		item6->set_no_give(1);		 
		//    item6->set_amount(2);
	w = item6->move2(who,-1);
		item6->add_to_user(w);


		item9 = new("item/TuiLinhThach/NgauNhien/4");
		item9->set_no_give(1);		   
		//    item6->set_amount(2);
	j = item9->move2(who,-1);
		item9->add_to_user(j);


		item8 = new("item/sell/0034");	
		item8->set_no_give(1);		
		//    item6->set_amount(2);
	d = item8->move2(who,-1);
		item8->add_to_user(d);
		


}