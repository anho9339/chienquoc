#include <item.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>
inherit ITEM;
//inherit COMBINED;

int get_item_value() {return 200 ;}
int get_item_value_2() {return 200 ;}
//int get_item_number() {return 10001029 ;}
int get_item_color() {return 2 ;}
int is_ghepppcanh() { return 1; }
// 修理道具
int is_repair() {return 1 ;} 

// 函数：构造处理
void create()
{
        set_name( "Hổ ấn Bá Vương" );
        set_picid_1(4983);
        set_picid_2(4983);
        set_value(50);
		set_save("ghep",120);
	//	set_amount(1);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng kéo tới Phi Phong hoặc Cánh vĩnh viễn (thường) sẽ \nNâng cấp lên Phi Phong hoặc Cánh \"Bá Vương\" \nhoặc Kéo tới Phi Phong hoặc Cánh (Bá Vương) sẽ \nNâng cấp lên Phi Phong hoặc Cánh  \"VÔ SONG\"."; 
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
	int p;
	string result;
	object equip1;
	if( !equip->is_equip() ) return 0;     
	if ( equip->get_name()!="Bá Vương Hoả Lân Dực" &&
		equip->get_name()!="Bá Vương Sát Thần Giả" &&
		equip->get_name()!="Vương Giả Phi Phong" &&
		equip->get_name()!="Xí Nhiệt Phi Phong" &&
		equip->get_name()!="Thánh Linh Chi Dực·Vàng Nhạt" &&
		equip->get_name()!="Thánh Linh Chi Dực·Trắng Thuần" ) 
	{
		write_user(me, ECHO "Chỉ có thể Nâng Cấp Phi Phong hoặc Cánh vĩnh viễn (thường) và (Bá Vương) !");
		return 1;
	}		
		if(USER_INVENTORY_D->get_free_count(me) < 2 )
			{
				write_user(me, ECHO "Hành trang của bạn không đủ 2 chỗ trống!");
				return 1;
			}
if ( equip->get_name()=="Bá Vương Hoả Lân Dực" )	
{	
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ppvacanh/canh/canh");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	item->remove_from_user();
	destruct( item );
	//item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Bá Vương Hoả Lân Dực"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Bá Vương Sát Thần Giả" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ppvacanh/phiphong/phiphong");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	item->remove_from_user();
	destruct( item );
	//item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Bá Vương Sát Thần Giả"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Vương Giả Phi Phong" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ppvacanh/phiphong/phiphong1");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	item->remove_from_user();
	destruct( item );
	//item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Vương Giả Phi Phong"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Xí Nhiệt Phi Phong" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ppvacanh/phiphong/phiphong1");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	item->remove_from_user();
	destruct( item );
	//item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Xí Nhiệt Phi Phong"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Thánh Linh Chi Dực·Vàng Nhạt" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ppvacanh/canh/canh1");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	item->remove_from_user();
	destruct( item );
	//item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Thánh Linh Chi Dực·Vàng Nhạt"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Thánh Linh Chi Dực·Trắng Thuần" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ppvacanh/canh/canh1");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	item->remove_from_user();
	destruct( item );
	//item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Thánh Linh Chi Dực·Trắng Thuần"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}	
	return 1;
}