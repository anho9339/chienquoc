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
        return "Túi Quà Cảm Ơn trị giá 4.000.000.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,z,x,c,v,b,n,m,a,s,d,f,g,h,j,k,l;
	object item,item1,item2,item3,item4,item5,item6,item7,item8,item9,item10,item11,item12,item13,item14,item15,item16,item17,item18,item19,item20;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 1 : 2;

	if(USER_INVENTORY_D->get_free_count(who) < 10 )
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

	who->add_cash(4000000);

		// Set túi đoạn thạch
		item1 = new("pretkuzl/napthe/tuisetdt4");
	a = item1->move2(who,-1);
		item1->add_to_user(a);
		
		// Sơ cấp đặc biệt
		item2 = new("item/sell/4032");
	s = item2->move2(who,-1);
		item2->add_to_user(s);
		
		// Hihi
		item3 = new("item/huyetlong/ghep/mg"); 
		item3->set_amount(40);
	d = item3->move2(who,-1);
		item3->add_to_user(d);
	
		item4 = new("item/manhghep/mgphnb");
		item4->set_amount(20);
	f = item4->move2(who,-1);
		item4->add_to_user(f);
		
	// zzzz
	item5 = new("item/test2/tuithucuoi");
		 item5->set_amount(10);
	g = item5->move2(who,-1);
		item5->add_to_user(g);
		
     
		item6 = new("item/test2/TuiPhapBao");
		item6->set_amount(10);
	h = item6->move2(who,-1);
		item6->add_to_user(h);
		

       item7 = new("item/08/0006");	
       item7->set_amount(10);	   
	j = item7->move2(who,-1);
		item7->add_to_user(j);
		
		
       item8 = new("item/test2/TuiQuaVoSong");		
	    item8->set_amount(10);
	k = item8->move2(who,-1);
		item8->add_to_user(k);
			
      
         item9 = new("item/TuiLinhThach/NgauNhien/6");		
	    item9->set_amount(4);
	l = item9->move2(who,-1);
		item9->add_to_user(l);	  
        

}