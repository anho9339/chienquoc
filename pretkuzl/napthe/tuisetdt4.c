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
         set_name("Set Đoạn Thạch");
        set_picid_1(4980);
        set_picid_2(4981);
		set_level(10);
        set_value(10000);
	//    set_no_give(1);		
    //    set_no_sell(1);
	//	set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Set bao gồm 4 đoạn thạch mỗi loại.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,z,x,c,v,b,n,m,a,s,d,f,g,h,j,k,l;
	object item,item1,item2,item3,item4,item5,item6,item7,item8,item9,item10,item11,item12,item13,item14,item15,item16,item17,item18,item19,item20;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;

	if(USER_INVENTORY_D->get_free_count(who) < 16 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}
	TASK_LEGEND_D->check_task_item1(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item2(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item3(who,"Set Đoạn Thạch",1); 
	TASK_LEGEND_D->check_task_item4(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item5(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item6(who,"Set Đoạn Thạch",1); 
	TASK_LEGEND_D->check_task_item7(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item8(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item9(who,"Set Đoạn Thạch",1);  
	TASK_LEGEND_D->check_task_item10(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item11(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item12(who,"Set Đoạn Thạch",1); 
	TASK_LEGEND_D->check_task_item13(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item14(who,"Set Đoạn Thạch",1);
	TASK_LEGEND_D->check_task_item15(who,"Set Đoạn Thạch",1); 
	TASK_LEGEND_D->check_task_item16(who,"Set Đoạn Thạch",1);

	// 4 sơ cấp
		item1 = new("item/sell/0032");
	z = item1->move2(who,-1);
		item1->add_to_user(z);
		

        item2 = new("item/sell/0032");
	x = item2->move2(who,-1);
		item2->add_to_user(x);
		
		item3 = new("item/sell/0032");
	c = item3->move2(who,-1);
		item3->add_to_user(c);
		
		item4 = new("item/sell/0032");
	v = item4->move2(who,-1);
		item4->add_to_user(v);
		
		// 4 trung cấp
		item5 = new("item/sell/1032");
	b = item5->move2(who,-1);
		item5->add_to_user(b);
		
		
		item6 = new("item/sell/1032");
	n = item6->move2(who,-1);
		item6->add_to_user(n);
		
		item7 = new("item/sell/1032");
	m = item7->move2(who,-1);
		item7->add_to_user(m);
		
		item8 = new("item/sell/1032");
	a = item8->move2(who,-1);
		item8->add_to_user(a);
	
		// 4 cao cấp
		item9 = new("item/sell/2032");
	s = item9->move2(who,-1);
		item9->add_to_user(s);
	
		
		item10 = new("item/sell/2032");
	d = item10->move2(who,-1);
		item10->add_to_user(d);
		
		item11 = new("item/sell/2032");
	f = item11->move2(who,-1);
		item11->add_to_user(f);
	
		item12 = new("item/sell/2032");
	g = item12->move2(who,-1);
		item12->add_to_user(g);
		
		// 4 bảo để
		item13 = new("item/sell/0034"); 
	h = item13->move2(who,-1);
		item13->add_to_user(h);

		
		item14 = new("item/sell/0034"); 
	j = item14->move2(who,-1);
		item14->add_to_user(j);

		
		item15 = new("item/sell/0034"); 
	k = item15->move2(who,-1);
		item15->add_to_user(k);
		
		item16 = new("item/sell/0034"); 
	l = item16->move2(who,-1);
		item16->add_to_user(l);

}