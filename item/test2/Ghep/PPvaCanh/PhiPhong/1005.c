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
        set_name("Phi Phong Bá Vương");
        set_picid_1(4980);
        set_picid_2(4981);
		set_level(0);
        set_value(10000);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng nhận được Phi Phong Bá Vương\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m;
	object item,item1,item2,item3;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;
	if ( who->get_level() < 0 )
	{
		        send_user(who,"%c%s",'!',"Cấp 0 có thể sử dụng.");
    		return 0;
	}

	gift->remove_from_user();
	destruct(gift);
		
		item1 = new(sprintf("item/ppvacanh/phiphong/phiphong%d",gender));
	k = item1->move2(who,-1);
	item1->add_to_user(k);

		send_user(who,"%c%s",';',"Bạn nhận được "HIY"Phi Phong Bá Vương");

}