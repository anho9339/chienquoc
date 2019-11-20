/*
Edit by Nguyễn Quang Hiếu
*/
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>

inherit OFFICER;

// 函数:获取人物造型
void reset();
int get_char_picid() { return 6010; }
int is_seller() { return 7007; }
int is_self_look() { return 1; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name(HIB"Sứ Giả Hoạt Động");
	//	set_real_name(HIR "Sứ Giả Hoạt Động");
		set_2( "good", ([
                "01" : "/item/ngoai_trang/vip101",
                "02" : "/item/ngoai_trang/vip102",
				"03" : "/item/test2/NangCap/ppcanh",	
				"04" : "/item/01/0007",	
				"05" : "/item/01/0008",	
			//	"06" : "/item/01/0009",	
			//	"07" : "/item/01/0010",	
			//	"08" : "/item/01/0011",	
			//	"09" : "/item/01/0012",	
			//	"10" : "/item/01/0013",	
			//	"11" : "/item/01/0014",	
			//	"12" : "/item/01/0015",	
				"06" : "/item/test2/NangCap/TC2",	
				"07" : "/item/test2/NangCap/TC3",	
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn tham gia hoạt động gì?????? \n"
	//	ESC HIC"Nhận hỗ trợ mỗi giờ....\ntalk %x# gift.59\n"
	//	ESC HIC"Nhận hỗ trợ hằng ngày....\ntalk %x# gift.56\n"
		ESC HIY"Đổi Cực Hiệu lấy Siêu Cấp\ntalk %x# gift.11\n"
	//	ESC HIC"Mua 1 chiếc Chìa Khoá May Mắn...\ntalk %x# gift.69\n"		
		ESC HIG"Hợp Thành Vật Phẩm\nlist9 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));	
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien;
	object who,item,item1,item2,item3;
	string *nTmp,cFile,cTmp,cFinal,result;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);     
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
		rate = random(100);
        switch(flag)
        {
       	case 1:
			break;	
		case 11:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Mỗi loại tiêu hao 2 Cực Hiệu cho loại đó !! \n"
					ESC HIY"[Siêu Cấp Khí Huyết]\ntalk %x# gift.60\n"
					ESC HIY"[Siêu Cấp Pháp Lực]\ntalk %x# gift.61\n"
					ESC HIY"[Siêu Cấp Ngoại Công]\ntalk %x# gift.62\n"
					ESC HIY"[Siêu Cấp Nội Công]\ntalk %x# gift.63\n"
					ESC HIY"[Siêu Cấp Ngoại Kháng]\ntalk %x# gift.64\n"
					ESC HIY"[Siêu Cấp Nội Kháng]\ntalk %x# gift.65\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
			break;	
		case 56:
		if (who->get_save_2("fride.day")==iDay)
		{
			result = me->get_name()+":\n    Hôm nay đã nhận rồi, ngày mai hãy đến !\n";
			send_user( who, "%c%c%w%s", ':', 3, 6010, result );
			return;
		}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}
		who->set_save_2("fride.day", iDay);
			item = new("/item/08/0006");
			i = item->move2(who,-1);
			item->add_to_user(i);
		who->add_cash(20000);
		who->add_exp(10000);
		send_user(who,"%c%s",':',me->get_name()+":\nChiến Quốc Lệnh +1 \nNgân Lượng : 20000 \nKinh nghiệm : 10000 \n"ESC"Rời khỏi.");
		break;
	/*	case 59:
		if (who->get_save_2("fride.gio")==iGio)
		{
			result = me->get_name()+":\n    Đã nhận rồi, hãy đợi tới giờ kế tiếp !\n";
			send_user( who, "%c%c%w%s", ':', 3, 6010, result );
			return;
		}
			who->add_save("hotrohangngay.score",1);
			who->set_save_2("fride.gio", iGio);
			who->add_cash(100000);
			who->add_exp(300000);
			send_user(who,"%c%s",':',me->get_name()+":\nNgân lượng + 100.000 lượng \nKinh nghiệm + 300.000 \n"ESC"Rời khỏi.");
		//	return 0;
		break;*/
		case 60:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Khí Huyết") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Khí Huyết" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Khí Huyết",2);	
		item = new("/item/final/SieuCap/1524");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Khí Huyết để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 61:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Pháp Lực") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Pháp Lực" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Pháp Lực",2);	
		item = new("/item/final/SieuCap/1526");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Pháp Lực để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 62:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Ngoại Công") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Ngoại Công" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Ngoại Công",2);	
		item = new("/item/final/SieuCap/1525");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Ngoại Công để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 63:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Nội Công") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Nội Công" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Nội Công",2);	
		item = new("/item/final/SieuCap/1528");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Nội Công để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 64:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Ngoại Kháng") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Ngoại Kháng" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Ngoại Kháng",2);	
		item = new("/item/final/SieuCap/1527");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Ngoại Kháng để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 65:
		
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Nội Kháng") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Nội Kháng" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Nội Kháng",2);	
		item = new("/item/final/SieuCap/1529");
		i = item->move2(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Nội Kháng để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
	/*	case 69:
		
		if ( who->get_cash() < 100000000 )
			{
				notify( "Không đủ 100 triệu ngân lượng" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
		who->add_cash(-100000000);
		item = new("/item/sell/0204");
		i = item->move2(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được "HIY+item->get_name());
		break;*/
		}
}
