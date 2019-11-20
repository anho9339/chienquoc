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
        set_name("Túi Quà Gắn Bó");
        set_picid_1(4980);
        set_picid_2(4981);
		set_level(10);
        set_value(10000);
	//    set_no_give(1);		
    //    set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Cảm ơn những người chơi đã gắn bó với server trong suốt thời gian qua.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m,n,q,w,a,s,d;
	object item,item1,item2,item3,item4,item5,item6,item7,item8,item9,item10;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;

	if(USER_INVENTORY_D->get_free_count(who) < 5 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}
	
	TASK_LEGEND_D->check_task_item1(who,"Túi Quà Gắn Bó",1);
	TASK_LEGEND_D->check_task_item2(who,"Túi Quà Gắn Bó",1);
	TASK_LEGEND_D->check_task_item3(who,"Túi Quà Gắn Bó",1); 
	TASK_LEGEND_D->check_task_item4(who,"Túi Quà Gắn Bó",1);
	TASK_LEGEND_D->check_task_item5(who,"Túi Quà Gắn Bó",1);
//	TASK_LEGEND_D->check_task_item6(who,"Túi Quà Cảm Ơn",1); 
	

	who->add_cash(100000);
    "sys/sys/test_db"->add_yuanbao(who, 500);
	
	item1 = new("item/sell/2032");
		//	item1->set_amount(10);
	i = item1->move2(who,-1);
		item1->add_to_user(i);
		item1->set_no_give(1);
		
	item2 = new("item/tuiquatanthuhieu/0008");
			item2->set_amount(10);
	l = item2->move2(who,-1);
		item2->add_to_user(l);
		item2->set_no_give(1);		
       
		item3 = new("item/tuiquatanthuhieu/0010");
			item3->set_amount(10);
	m = item3->move2(who,-1);
		item3->add_to_user(m);
		item3->set_no_give(1);
       
      item4 = new("item/test/vosongdiemphieu");
			item4->set_amount(100);
	k = item4->move2(who,-1);
		item4->add_to_user(k);
		item4->set_no_give(1);	 
       
      item5 = new("item/sell/0042");
	 item5->set_amount(10); // Thiên Nguyên Đan
	q = item5->move2(who,-1);
		item5->add_to_user(q);
		item5->set_no_give(1);		   
		

}