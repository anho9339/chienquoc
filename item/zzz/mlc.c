#include <item.h>
#include <ansi.h>
#include <equip.h>
inherit ITEM;

int get_item_value() {return 200 ;}
int get_item_value_2() {return 200 ;}
int get_item_number() {return 10001025 ;}
int get_item_color() {return 2 ;}

// 修理道具
int is_repair() {return 1 ;} 

// 函数：构造处理
void create()
{
        set_name( "Ma Lực Chùy" );
        set_picid_1(3411);
        set_picid_2(3411);
        set_value(50);
	//	set_save("knb2",20);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Kéo Ma Lực Chùy đến mục trang bị có thể khôi phục độ bền vốn có của trang bị này."; 
}

// 函数：获取简短描述
string get_short() 
{ 
        return "Kéo Ma Lực Chuỳ đến mục trang bị có thể khôi phục độ bền vốn có của trang bị này."; 
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1);
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2);
}

int move_item_callout(object me, object item, object equip, int type)
{
	string file, result;
	int maxlast, last, number;
	file = get_file_name(equip);
	if( !equip->is_equip() ) return 0;
        if( equip->get_equip_type() == FAMILY_TYPE ) return 0;	
        maxlast = file->get_max_lasting();        
	number = equip->get_item_number(); 
	if (equip->get_no_repair())
	{
		result = "Không thể sửa chữa vật phẩm !";
		send_user( me, "%c%s", '!', result);
		return 1;
	}	
	last = equip->get_lasting(); 
	if (type==1)
	{
		result = sprintf("%s có độ bền là %d/%d, bạn muốn khôi phục độ bền không ?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), last/100, equip->get_max_lasting()/100, 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	last = equip->get_max_lasting(); 
	last = maxlast;
	equip->set_max_lasting(last);
	equip->set_lasting(last);
//	item->remove_from_user();
//	destruct( item );
	send_user( me, "%c%s", '!', sprintf("Đã khôi phục độ bền của  %s.", equip->get_name()));
	return 1;
}