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
        set_name("Túi Pháp Bảo Vương Giả");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(4000000);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng sẽ nhận được 3 loại "HIY "Pháp Bảo Vương Giả"NOR " \nNhiếp Hồn Linh Vương \nChuông Hám Thiên Vương \nCửu Long Thần Hoả Trảo Vương";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p,gender,family,type;
	object item,weapon,armor,head,neck,waist,boots;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 0 : 1;
/*	if (who->get_fam_name() == "")
	{
	send_user(who,"%c%s",'!',"Xin hãy gia nhập phái.");
    		return 0;
	}*/
	if(USER_INVENTORY_D->get_free_count(who) < 3 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ 3 chỗ.");
    		return 0;
	}

/*	if(who->get_fam_name() == "Đào Hoa Nguyên") family = 1;
	else if(who->get_fam_name() == "Thục Sơn") family = 2;
	else if(who->get_fam_name() == "Cấm Vệ Quân") family = 3;
	else if(who->get_fam_name() == "Đường Môn") family = 4;
	else if(who->get_fam_name() == "Mao Sơn") family = 5;
	else if(who->get_fam_name() == "Côn Luân") family = 6;
	else if(who->get_fam_name() == "Vân Mộng Cốc") family = 7;
*/
	gift->remove_from_user();
	destruct(gift);
	
	item = new(sprintf("item/phapbaoHK/phapbaovuong/NHL"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/phapbaoHK/phapbaovuong/CHT"));
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/phapbaoHK/phapbaovuong/CLTHT"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	
	return 0;
}