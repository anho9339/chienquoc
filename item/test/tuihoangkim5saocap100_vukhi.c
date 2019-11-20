#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

// 函数：构造处理
void create()
{
        set_name("Túi Hoàng Kim 5 sao cấp 100 (Vũ Khí)");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(100);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi mở có thể nhận được Vũ Khí Hoàng Kim 5 sao cấp 100.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int p,gender,level;
	object item;
	string *nTmp,cFile;
	level = 100;

	if (who->get_fam_name()==""||!who->get_fam_name())
	{
		send_user(who, "%c%s", '!', "Hãy gia nhập phái");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);
	nTmp = WEAPON_FILE->get_family_equip( who->get_fam_name(),who->get_gender(),level,WEAPON_TYPE );
	cFile = nTmp[random(sizeof(nTmp))];
	if( load_object(cFile) )
	{
		item = new(cFile);
		"/sys/item/equip"->init_equip_prop_3(item);
		"/sys/item/equip"->init_equip_prop_5(item);
		"/sys/item/equip"->init_equip_prop_5(item);
		"/sys/item/equip"->init_equip_prop_5(item);
		"/sys/item/equip"->init_equip_prop_5(item);
		"/sys/item/equip"->init_equip_prop_5(item);
		item->set_item_color(2);
		item->set_hide(0);
		item->set("forge", "11111");
		p = item->move2(who,-1);
		item->add_to_user(p);
	}
	return 0;
}