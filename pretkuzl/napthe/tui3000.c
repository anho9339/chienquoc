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
        set_name("Túi Quà Cảm Ơn");
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
        return "Túi Quà Cảm Ơn trị giá 3.000.000.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m,n,q,w,a,s,d,o,y,h,v,aa,bb,cc,dd,ee,ff,gg;
	object item,item1,item2,item3,item4,item5,item6,item7,item8,item9,item10,item11,item12,item13,item14,item15,item16,item17,item18,item19,item20;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;

	if(USER_INVENTORY_D->get_free_count(who) < 11 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}
	TASK_LEGEND_D->check_task_item1(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item2(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item3(who,"Túi Quà Cảm Ơn",1); 
	TASK_LEGEND_D->check_task_item4(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item5(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item6(who,"Túi Quà Cảm Ơn",1); 
	TASK_LEGEND_D->check_task_item7(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item8(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item9(who,"Túi Quà Cảm Ơn",1); 
	TASK_LEGEND_D->check_task_item10(who,"Túi Quà Cảm Ơn",1); 
	TASK_LEGEND_D->check_task_item11(who,"Túi Quà Cảm Ơn",1); 

	who->add_cash(30000000);

		
		item1 = new("item/tienxu/tuidoanthach");
		item1->set_amount(20);
	k = item1->move2(who,-1);
		item1->add_to_user(k);
	//	item1->set_no_give(1);	

		item2 = new("item/huyetlong/ghep/mg");
		item2->set_amount(30);
	i = item2->move2(who,-1);
		item2->add_to_user(i);
       
		item3 = new("item/test2/TuiPhapBao");
		item3->set_amount(80);
	m = item3->move2(who,-1);
		item3->add_to_user(m);	
		
		// 1
		item4 = new("item/sell/0034"); 
	v = item4->move2(who,-1);
		item4->add_to_user(v);
		
       item5 = new("item/test2/TuiQuaVoSong");		
	    item5->set_amount(80);
	q = item5->move2(who,-1);
		item5->add_to_user(q);
      
         item6 = new("item/TuiLinhThach/NgauNhien/7");		
	    item6->set_amount(2);
	w = item6->move2(who,-1);
		item6->add_to_user(w);
		
		// 2
		item7 = new("item/sell/0034"); 
	s = item7->move2(who,-1);
		item7->add_to_user(s);
		
		//3 
		item8 = new("item/sell/0034"); 
	d = item8->move2(who,-1);
		item8->add_to_user(d);
		
		//4 
		item9 = new("item/sell/0034"); 
	o = item9->move2(who,-1);
		item9->add_to_user(o);
		
		//5
		item10 = new("item/sell/0034"); 
	y = item10->move2(who,-1);
		item10->add_to_user(y);
		
		//6
		item11 = new("item/sell/0034"); 
	h = item11->move2(who,-1);
		item11->add_to_user(h);
	  
        

}