#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 2500 ;}
int get_item_value_2() {return 2500 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Nâng cấp Thần Binh");
        set_picid_1(3101);
        set_picid_2(3101);
        set_value(50000);
	//	set_save("knb",2500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng sẽ nhận được một viên Ngọc Tử Kim (Ngọc nâng cấp vũ khí Tử Kim) \nvà một trong 6 loại vũ khí gốc tự chọn (nguyên liệu đúc Thần binh cấp 75).";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p,gender,family,type;
	object item;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 0 : 1;
	if(USER_INVENTORY_D->get_free_count(who) < 2 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ 2 chỗ.");
    		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	item = new(sprintf("item/test2/NangCap/vktk"));		
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/test2/NangCap/vktk2"));	
	p = item->move2(who,-1);
	item->add_to_user(p);
	send_user(who,"%c%s",';',"Bạn nhận được "HIY"Ngọc Tử Kim "NOR "và "HIY"Túi Nguyên Liệu Thần Binh"NOR " !!!");
	
	return 0;
}