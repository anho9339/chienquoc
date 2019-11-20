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
        return "Túi Quà Cảm Ơn trị giá 200.000.";
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
	TASK_LEGEND_D->check_task_item1(who,"Túi Quà Cảm Ơn",1);
//	TASK_LEGEND_D->check_task_item2(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item3(who,"Túi Quà Cảm Ơn",1); 
//	TASK_LEGEND_D->check_task_item4(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item5(who,"Túi Quà Cảm Ơn",1);
	TASK_LEGEND_D->check_task_item6(who,"Túi Quà Cảm Ơn",1); 
	

	who->add_cash(2000000);
		
		item1 = new("item/tienxu/tuidoanthach");
		item1->set_amount(5);
	k = item1->move2(who,-1);
		item1->add_to_user(k);
	//	item1->set_no_give(1);		
       
		item3 = new("item/test2/TuiPhapBao");
			item3->set_amount(20);
	m = item3->move2(who,-1);
		item3->add_to_user(m);	
		
       item5 = new("item/test2/TuiQuaVoSong");		
	    item5->set_amount(20);
	q = item5->move2(who,-1);
		item5->add_to_user(q);	
      
         item6 = new("item/TuiLinhThach/NgauNhien/5");		
	    item6->set_amount(2);
	w = item6->move2(who,-1);
		item6->add_to_user(w);  
        

}