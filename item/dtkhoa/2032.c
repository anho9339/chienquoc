#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

// 函数：宝石识别
int is_diamond_2() { return 1; }

// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

int get_item_color() {return 3 ;}

// 函数：宝石识别
int get_item_type() { return ITEM_TYPE_DIAMOND_3; }

// 函数：宝石属性
string get_diamond_type() { return "forge"; }

// 宝石锻造的辩别标志
string get_forge_index() {return "3";}

int is_specal_move() {return 1;}

// 函数：构造处理
void create()
{
        set_name("Cao Cấp Đoạn Thạch");
        set_real_name("Đoạn Thạch");
        set_picid_1(4273);
        set_picid_2(4273);
        set_unit("块");
		set_no_give(1);
		set_no_sell(1);
        set_value(8000);
        set_level(1);
}

string get_desc() 
{
	return "Chỉ có thể luyện trang bị 4 sao hoặc cao hơn nữa, có thể tăng cường thuộc tính của trang bị.\n Nếu như luyện thất bại, trang bị sẽ giảm xuống 0 sao.\n Trang bị sẽ ngày càng cao theo số lần luyện, tỷ lệ thành công sẽ ngày càng thấp.";
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1 );
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2 );
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result, forge;
	object item2;
	int i, p, level, rate;	
	if( equip->is_equip()==0 && equip->get_real_name()!="Đoạn Thạch" )  return 0;
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE)
			return 0;
	}
	if (equip->get_real_name()=="Đoạn Thạch" )
	{
		if (item->get_forge_index()!=equip->get_forge_index())
			notify( "Cấp bậc không phù hợp, không thể hợp thành." );
		else
			notify( "Cao Cấp Đoạn Thạch không cần hợp thành." );
		return 1;
	}
	forge = equip->get("forge");
	if (forge==0) level = 0;
	else level = strlen(forge);
	if (level<4)
	{
		notify( "Cao Cấp Đoạn Thạch chỉ rèn được trang bị 4 sao trở lên." );
		return 1;
	}	
	if (level>=7)
	{
		notify( "Chỉ có thể rèn được tối đa 7 sao." );
		return 1;
	}
	rate = 10000;		
	for (i=4;i<=level;i++)
	{
		rate = rate * 3 / 5; 
	}
	rate /= 100;
	if ( me->get_vip() && !me->get_save_2("vip_package.trial") )
		rate += 5;
	if (rate>100) rate = 100;	
	if (type==1)
	{
		result = sprintf("Trang bị nếu rèn thất bại sẽ giảm xuống 0 sao, Tỷ lệ thành công là"HIR " %d%%"NOR "，\nNgươi xác định phải rèn %s không?\n"
			ESC "Chấp nhận\nmix3 0# %x# %x#\n"
			ESC "Hủy bỏ",
			rate, equip->get_name(), getoid(equip), getoid(item) );
		send_user(me, "%c%c%w%s", ':', 3, 0, result);			       			
		return 1;
	}		
	return 1;
}