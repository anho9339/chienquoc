#include <item.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 5000 ;} 
int get_item_value_2() {return 5000 ;}
int get_item_color() {return 2 ;}

// 修理道具
int is_repair() {return 1 ;} 

// 函数：构造处理
void create()
{
        set_name( "Chiến Thú Lệnh" );
        set_picid_1(4984);
        set_picid_2(4984);
        set_value(50);
	//	set_save("knb",5000);
		set_amount(1);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng kéo tới Trứng Thú Cưỡi sẽ \nNâng cấp lên Trứng Chiến Thú \nhoặc kéo tới Trứng Chiến Thú sẽ \nNâng cấp lên Trứng Chiến Thú cấp cao hơn..\n...Có thể nâng cấp tối đa lên Trứng Chiến Thú cấp 3."; 
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
		equip->get_name()!="★ Chiến Thú Thần Ngư cấp 2 ★" ) 
	{
		write_user(me, ECHO "Chỉ có thể Nâng Cấp Thú Cưỡi và Chiến Thú hoặc Chiến Thú cấp 2!");
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
if ( equip->get_name()=="Trứng Tiểu Quai" )	
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/001");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Tiểu Quai"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}	
else if ( equip->get_name()=="Trứng Đinh Đang" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/002");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Đinh Đang"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Trứng Đà Đà" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/003");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Đà Đà"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Trứng Bọ Hung" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/004");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Bọ Hung"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Trứng Bàn Bàn" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/005");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Bàn Bàn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Trứng Tử Mao" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/006");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Tử Mao"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Trứng Bổn Bổn" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/007");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Bổn Bổn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Trứng Thần Ngư" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/ride/NangCap/055");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Trứng Thần Ngư"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Tiểu Quai ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/001_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Tiểu Quai ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Đinh Đang ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/002_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Đinh Đang ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Đà Đà ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/003_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Đà Đà ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Bọ Hung ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/004_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Bọ Hung ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Bàn Bàn ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/005_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Bàn Bàn ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Tử Mao ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/006_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Tử Mao ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Bổn Bổn ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/007_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Bổn Bổn ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Thần Ngư ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 500 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 5000 ) {
		write_user(me, ECHO"Bạn không đủ 500 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-5000);
	equip1 = new("item/ride/NangCap/055_2");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Thần Ngư ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Tiểu Quai cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/001_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Tiểu Quai cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Đinh Đang cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/002_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Đinh Đang cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Đà Đà cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/003_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Đà Đà cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Bọ Hung cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/004_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Bọ Hung cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Bàn Bàn cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/005_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Bàn Bàn cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Tử Mao cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/006_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Tử Mao cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Bổn Bổn cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/007_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Bổn Bổn cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="★ Chiến Thú Thần Ngư cấp 2 ★" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn dùng 1000 Kim Bảo để nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	if ( "sys/sys/test_db"->get_yuanbao(me) < 10000 ) {
		write_user(me, ECHO"Bạn không đủ 1000 Kim Nguyên Bảo để nâng cấp");
		return 1;
	}
	"sys/sys/test_db"->add_yuanbao(me,-10000);
	equip1 = new("item/ride/NangCap/055_3");
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user(); 
     //destruct( item ); 
    item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "★ Chiến Thú Thần Ngư cấp 2 ★"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}	
	return 1;
}