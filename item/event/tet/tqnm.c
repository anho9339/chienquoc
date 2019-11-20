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
        set_name("Túi Quà Năm Mới");
		set_picid_1(3106);
        set_picid_2(3106);
		set_level(0);
        set_value(5000);
		set_no_give(1);		
 
}

// 函数：获取描述
string get_desc( object me ) 
{
		return "Túi Quà Năm Mới \nKích chuột phải để sử dụng \nTúi quà lì xì cho người chơi CQTD. Chúc các bạn năm mới vui vẻ!\n";
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

	if(USER_INVENTORY_D->get_free_count(who) < 5 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}
	TASK_LEGEND_D->check_task_item1(who,"Túi Quà Năm Mới",1);
	TASK_LEGEND_D->check_task_item2(who,"Túi Quà Năm Mới",1);
	TASK_LEGEND_D->check_task_item3(who,"Túi Quà Năm Mới",1); 
	TASK_LEGEND_D->check_task_item4(who,"Túi Quà Năm Mới",1);
	

	who->add_cash(500000);
		
		item1 = new("item/dtkhoa/0032");;
	k = item1->move2(who,-1);
		item1->add_to_user(k);
		
		item2 = new("item/dtkhoa/1032");
	a = item2->move2(who,-1);
		item2->add_to_user(a);
	
		item3 = new("item/test2/TuiPhapBao");
		item3->set_amount(2);
	m = item3->move2(who,-1);
		item3->add_to_user(m);	
		
       item4 = new("item/test2/TuiQuaVoSong");		
	    item4->set_amount(5);
	q = item4->move2(who,-1);
		item4->add_to_user(q);	
	

}