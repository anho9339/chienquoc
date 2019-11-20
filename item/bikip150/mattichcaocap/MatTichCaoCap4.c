#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name( "Mật Tịch Cao Cấp phái Đường Môn" );
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(5000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi sử dụng sẽ nhận được kỹ năng Tuyệt Kĩ của phái Đường Môn \n+++++ "HIY " Thần Công Vô Địch "NOR " +++++ ";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p;
	object item;

	if (who->get_fam_name() == "")
	{
	send_user(who,"%c%s",'!',"Gia Nhập Phái đi Bạn.");
    		return 0;
	}
	if(USER_INVENTORY_D->get_free_count(who) < 2 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}

//	item = new("item/skill/02610");
	item = new("item/skill/DM");
	gift->remove_from_user();
	destruct(gift);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR " Mật Tịch Cao Cấp Đường Môn - Thần Công Vô Địch");
	p = item->move2(who,-1);
	item->add_to_user(p);
	return 0;
}