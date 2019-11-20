#include <item.h>
#include <ansi.h>
#include <task.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 2500 ;}
int get_item_value_2() {return 2500 ;}
//int get_item_number() {return 10001029 ;}
int get_item_color() {return 3 ;}

// 修理道具
int is_repair() {return 1 ;} 

// 函数：构造处理
void create()
{
        set_name( "Ngọc Tử Kim" );
        set_picid_1(8900);
        set_picid_2(8900);
        set_value(50);
		set_amount(1);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng kéo tới 1 trong 6 loại vũ khí gốc (nguyên liệu đúc Thần binh cấp 75) \nsẽ Nâng cấp lên Thần Binh cấp 75 \nhoặc Kéo tới Thần Binh cấp 75 sẽ \nNâng cấp lên Thần Binh cấp 100 \nhoặc Kéo tới Thần Binh cấp 100 sẽ \nNâng cấp lên Siêu Thần Binh cấp 130."; 
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
	int p,cap,i;
	string result,sao,forge="";
	object equip1;
	if( !equip->is_equip() ) return 0;     
	if (equip->get_name()!="Thạch Điêu Quyền Nhẫn" &&
		equip->get_name()!="Nguyệt Hoàn" &&
		equip->get_name()!="Kim Đao" &&
		equip->get_name()!="Ngọc Kiếm" &&
		equip->get_name()!="Xích Anh Thương" &&
		equip->get_name()!="Cổ Phương Côn" && 
		equip->get_name()!="Anh Kiệt Quyền Nhẫn" && 
		equip->get_name()!="Bích Hỏa Hàn Nguyệt Hoàn" && 
		equip->get_name()!="Thiên Tôn Bảo Đao" && 
		equip->get_name()!="Ngọc Thần Bảo Kiếm" && 
		equip->get_name()!="Chân Quân Xí Diệm Thương" && 
		equip->get_name()!="Càn Khôn Vô Cấp Côn" && 
		equip->get_name()!="Ngọc La Quyền Thủ" && 
		equip->get_name()!="Thần Tiên Hạc Kim" && 
		equip->get_name()!="Đao Tử Vân" && 
		equip->get_name()!="Lục Tiên Kiếm" && 
		equip->get_name()!="Lục Thần Thương" && 
		equip->get_name()!="Phàn Thiên Côn") 
	{
		write_user(me, ECHO "Chỉ có thể nâng cấp Thần Binh cấp 75 hoặc 100 !");
		return 1;
	}	
		if(USER_INVENTORY_D->get_free_count(me) < 2 )
			{
				write_user(me, ECHO "Hành trang của bạn không đủ 2 chỗ trống!");
				return 1;
			}
	sao = equip->get("forge");
	cap = strlen(sao);		
if ( equip->get_name()=="Thạch Điêu Quyền Nhẫn" )	
{	
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/70/9075");
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Thạch Điêu Quyền Nhẫn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Nguyệt Hoàn" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/71/9075");
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Nguyệt Hoàn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Kim Đao" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/72/9075");
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Kim Đao"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Ngọc Kiếm" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/73/9075");
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Ngọc Kiếm"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Xích Anh Thương" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/74/9075");
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Xích Anh Thương"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Cổ Phương Côn" )
{
	if (type==1)
	{
		result = sprintf("Bạn muốn nâng cấp "HIB"%s"NOR " không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			, equip->get_name(), 1, getoid(item), get_d(equip) );
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}
	equip1 = new("item/75/9075");
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Cổ Phương Côn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Anh Kiệt Quyền Nhẫn" )
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
	equip1 = new("item/70/9100");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Anh Kiệt Quyền Nhẫn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Bích Hỏa Hàn Nguyệt Hoàn" )
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
	equip1 = new("item/71/9100");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Bích Hoả Hàn Nguyệt Hoàn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Thiên Tôn Bảo Đao" )
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
	equip1 = new("item/72/9100");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Thiên Tôn Bảo Đao"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Ngọc Thần Bảo Kiếm" )
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
	equip1 = new("item/73/9100");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Ngọc Thần Bảo Kiếm"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Chân Quân Xí Diệm Thương" )
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
	equip1 = new("item/74/9100");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Chân Quân Xí Diệm Thương"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Càn Khôn Vô Cấp Côn" )
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
	equip1 = new("item/75/9100");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Càn Khôn Vô Cấp Côn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Ngọc La Quyền Thủ" )
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
	equip1 = new("item/70/9130");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Ngọc La Quyền Thủ"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Thần Tiên Hạc Kim" )
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
	equip1 = new("item/71/9130");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Thần Tiên Hạc Kim"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}	
else if ( equip->get_name()=="Đao Tử Vân" )
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
	equip1 = new("item/72/9130");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Đao Tử Vân"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Lục Tiên Kiếm" )
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
	equip1 = new("item/73/9130");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Lục Tiên Kiếm"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Lục Thần Thương" )
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
	equip1 = new("item/74/9130");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Lục Thần Thương"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
else if ( equip->get_name()=="Phàn Thiên Côn" )
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
	equip1 = new("item/75/9130");
		for (i = 0; i< cap; i++)
		{
			"/sys/item/equip"->init_equip_prop_5(equip1);
			forge += "1";
			equip1->set("forge", forge);
		}
	equip1->set_hide(0);
	p = equip1->move2(me,-1);
	equip1->add_to_user(p);
	
	equip->remove_from_user();
	destruct( equip );
	
	//item->remove_from_user();
	//destruct( item );
	item->add_amount(-1);
	send_user(me,"%c%s",';',sprintf("Bạn nhận được "HIY"%s "NOR " !!!",equip1->get_name() ));
	USER_D->user_channel(sprintf("Bằng hữu "HIY "%s" NOR " vừa Nâng Cấp thành công "HIR "Phàn Thiên Côn"NOR " và nhận được "HIY"%s "NOR ". ", me->get_name(),equip1->get_name() ));
	return 1;
}
	return 1;
}