#include <ansi.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Trọng Dương Lễ Bao");
        set_picid_1(4982);
        set_picid_2(4982);
        set_amount(1);
        set_value(200);
}

int is_usable() {return 1;}

// 函数：获取描述
string get_desc() 
{ 
        return "Quà tặng của Trọng Dương Lão Nhân ngày Tết Cửu Trùng"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,level;
	object item;
       	string *nTmp,tmp,cTmp;
	string *nFamily = ({"Đào Hoa Nguyên","Thục Sơn","Cấm Vệ Quân","Đường Môn","Mao Sơn","Côn Luân","Vân Mộng Cốc"});
	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",';',"Có thể bạn không đủ không gian túi. Vui lòng sắp xếp lại nó。");
    		return 0;
	}
	
	rate = random(100);
	if (rate<30) 
		item = 0;
	else if (rate<40)
	{
		item = new ("item/91/9102");//造化丹
		item->set_amount(5);
	}
	else if (rate<50)
	{
		item = new ("item/91/9121");//活心丹
		item->set_amount(5);
	}
	else if (rate<60)
	{
		item = new ("/item/01/0200");//红木宝箱
		item->set_amount(5);
	}
	else if (rate<70)
	{
		item = new ("/item/01/0201");//青铜宝箱
		item->set_amount(5);
	}
	else if (rate<90)
		item = new ("item/44/4488");//宠物技能丹
	else if (rate<97)
	{
		cTmp = BOOK_FILE->get_book_file();
		item = new (cTmp);//随机门派技能进阶书
	}
	else if (rate<100)//蓝装
	{
		if ((level=who->get_level()+10)>120) level=120;
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],0,level,101+random(6));
		tmp = nTmp[random(sizeof(nTmp))];
		if ( !stringp(tmp) )
			return 0;
		item = new(tmp);
		ITEM_EQUIP_D->init_equip_prop_1(item);
	}
	if ( item )
	{
		send_user(who,"%c%s",'!',"Xin chúc mừng! Bạn đã có gói quà tặng Trọng Dương"+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
	}
	else
	{
		who->add_cash(5000);
		send_user(who,"%c%s",'!',"Xin chúc mừng! Bạn đã mở gói quà tặng Trọng Dương và nhận 5000 vàng");
	}
	gift->add_amount(-1);
	return 0;
}

