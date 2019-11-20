#include <item.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
//inherit COMBINED;

int get_item_value() {return 5000 ;} 
int get_item_value_2() {return 5000 ;}
int get_item_color() {return 2 ;}
int is_ghepthucuoi() { return 1; }
// 修理道具
int is_repair() {return 1 ;} 

// 函数：构造处理
void create()
{
        set_name( "Chiến Thú Lệnh cấp 3" );
        set_picid_1(4984);
        set_picid_2(4984);
        set_value(50);
		set_save("ghep",600);
		//set_amount(1);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng kéo tới Trứng Thú Cưỡi hoặc Trứng Chiến Thú \nsẽ Nâng Cấp lên Trứng Chiến Thú cấp 5."; 
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
    
	if ( equip->get_name()!="Trứng Tiểu Quai" &&
		equip->get_name()!="Trứng Đinh Đang" &&
		equip->get_name()!="Trứng Đà Đà" &&
		equip->get_name()!="Trứng Bọ Hung" &&
		equip->get_name()!="Trứng Bàn Bàn" &&
		equip->get_name()!="Trứng Tử Mao" &&
		equip->get_name()!="Trứng Bổn Bổn" &&
		equip->get_name()!="Trứng Thần Ngư" &&
		equip->get_name()!="★ Chiến Thú Tiểu Quai ★" &&
		equip->get_name()!="★ Chiến Thú Đinh Đang ★" &&
		equip->get_name()!="★ Chiến Thú Đà Đà ★" &&
		equip->get_name()!="★ Chiến Thú Bọ Hung ★" &&
		equip->get_name()!="★ Chiến Thú Bàn Bàn ★" &&
		equip->get_name()!="★ Chiến Thú Tử Mao ★" &&
		equip->get_name()!="★ Chiến Thú Bổn Bổn ★" &&
		equip->get_name()!="★ Chiến Thú Thần Ngư ★" &&
		equip->get_name()!="★ Chiến Thú Tiểu Quai cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Đinh Đang cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Đà Đà cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Bọ Hung cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Bàn Bàn cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Tử Mao cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Bổn Bổn cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Thần Ngư cấp 2 ★" &&
		equip->get_name()!="★ Chiến Thú Tiểu Quai cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Đinh Đang cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Đà Đà cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Bọ Hung cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Bàn Bàn cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Tử Mao cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Bổn Bổn cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Thần Ngư cấp 3 ★" &&
		equip->get_name()!="★ Chiến Thú Tiểu Quai cấp 4 ★" &&
		equip->get_name()!="★ Chiến Thú Đinh Đang cấp 4 ★" &&
		equip->get_name()!="★ Chiến Thú Đà Đà cấp 4 ★" &&
		equip->get_name()!="★ Chiến Thú Bọ Hung cấp 4 ★" &&
		equip->get_name()!="★ Chiến Thú Bàn Bàn cấp 4 ★" &&
		equip->get_name()!="★ Chiến Thú Tử Mao cấp 4 ★" &&
		equip->get_name()!="★ Chiến Thú Bổn Bổn cấp 4 ★" &&
		equip->get_name()!="★ Chiến Thú Thần Ngư cấp 4 ★" ) 
	{
		write_user(me, ECHO "Chỉ có thể Nâng Cấp Thú Cưỡi và Chiến Thú dưới cấp 5!");
		return 1;
	}
	if ( equip->get_lock_time() && equip->get_lock_time() < time() ) 
	{
		write_user(me, ECHO "Đã hết hạn sử dụng, không thể nâng cấp !");
		return 1;
	}
			if(USER_INVENTORY_D->get_free_count(me) < 2 )
			{
				write_user(me, ECHO "Hành trang của bạn không đủ 2 chỗ trống!");
				return 1;
			}
if ( equip->get_name()=="Trứng Tiểu Quai" ||
	equip->get_name()=="★ Chiến Thú Tiểu Quai ★" ||	
	equip->get_name()=="★ Chiến Thú Tiểu Quai cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Tiểu Quai cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Tiểu Quai cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/001_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}
if ( equip->get_name()=="Trứng Đinh Đang" ||
	equip->get_name()=="★ Chiến Thú Đinh Đang ★" ||	
	equip->get_name()=="★ Chiến Thú Đinh Đang cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Đinh Đang cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Đinh Đang cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/002_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}
if ( equip->get_name()=="Trứng Đà Đà" ||
	equip->get_name()=="★ Chiến Thú Đà Đà ★" ||	
	equip->get_name()=="★ Chiến Thú Đà Đà cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Đà Đà cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Đà Đà cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/003_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}
if ( equip->get_name()=="Trứng Bọ Hung" ||
	equip->get_name()=="★ Chiến Thú Bọ Hung ★" ||	
	equip->get_name()=="★ Chiến Thú Bọ Hung cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Bọ Hung cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Bọ Hung cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/004_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}
if ( equip->get_name()=="Trứng Bàn Bàn" ||
	equip->get_name()=="★ Chiến Thú Bàn Bàn ★" ||	
	equip->get_name()=="★ Chiến Thú Bàn Bàn cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Bàn Bàn cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Bàn Bàn cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/005_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}
if ( equip->get_name()=="Trứng Tử Mao" ||
	equip->get_name()=="★ Chiến Thú Tử Mao ★" ||	
	equip->get_name()=="★ Chiến Thú Tử Mao cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Tử Mao cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Tử Mao cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/006_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}
if ( equip->get_name()=="Trứng Bổn Bổn" ||
	equip->get_name()=="★ Chiến Thú Bổn Bổn ★" ||	
	equip->get_name()=="★ Chiến Thú Bổn Bổn cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Bổn Bổn cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Bổn Bổn cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/007_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}
if ( equip->get_name()=="Trứng Thần Ngư" ||
	equip->get_name()=="★ Chiến Thú Thần Ngư ★" ||	
	equip->get_name()=="★ Chiến Thú Thần Ngư cấp 2 ★" ||	
	equip->get_name()=="★ Chiến Thú Thần Ngư cấp 3 ★" ||	
	equip->get_name()=="★ Chiến Thú Thần Ngư cấp 4 ★"	)	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/055_5");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "%s"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip->get_name(),equip1->get_name() ));
	
	equip->remove_from_user();
	destruct( equip );
	 
    //item->add_amount(-1);
    item->remove_from_user();
    destruct( item );
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	return 1;
}		
	return 1;
}