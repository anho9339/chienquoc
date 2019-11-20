#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Trang bị Tử Kim cấp 85 [Áo]");
        set_picid_1(3104);
        set_picid_2(3104);
        set_value(2);
		set_no_give(0);		
        set_no_sell(0);
		set_no_drop(0);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi mở ra sẽ nhận được trang bị [Áo] \nTử Kim cấp 85.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int i,p,gender,level;
	object item;
	string *nTmp,cFile,forge="";
	//level = 160;

	if (who->get_fam_name()==""||!who->get_fam_name())
	{
		send_user(who, "%c%s", '!', "Phải gia nhập Phái mới sử dụng được.");
		return 0;
	}
		item = new(sprintf("item/56/%d085",who->get_fam_type()));
		for (i = 0; i< 10; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(item);
			forge += "1";
			item->set("forge", forge);
		}
		item->set_item_color(3);
		item->set_hide(0);
		item->set_bind(1);
		p = item->move2(who,-1);
		item->add_to_user(p);
	gift->remove_from_user();
	destruct(gift);
	return 0;
}