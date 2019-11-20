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
        set_name("Đổi Mini Game");
		set_real_name(HIR "Kiều Nương");
		set_2( "good", ([
                "01" : "/item/ngoai_trang/vip101",
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi có điểm "HIB" Mini Game "NOR" có thể tới chỗ ta để đổi. Sao? Ngươi muốn gì ở đây? \n"
		ESC "10 điểm đổi 5 KNB\ntalk %x# gift.1\n"
		ESC "10 điểm đổi Nguyên liệu up thú (5)\ntalk %x# gift.2\n"
		ESC "10 điểm đổi Nguyên liệu up cánh pp (5)\ntalk %x# gift.3\n"
		ESC "20 điểm đổi 300.000 ngân lượng\ntalk %x# gift.4\n"
		ESC "20 điểm đổi 10 Vô Song Điểm Phiếu\ntalk %x# gift.5\n"
		ESC "50 điểm đổi Sơ Cấp (Khóa)\ntalk %x# gift.6\n"
		ESC "90 điểm đổi Trung Cấp (Khóa)\ntalk %x# gift.7\n"
		ESC "70 điểm đổi Sơ Cấp (Không Khóa)\ntalk %x# gift.8\n"
		ESC "130 điểm đổi Trung Cấp (Không Khóa)\ntalk %x# gift.9\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id,id,id,id));	
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
		if ( who->get_save("diemgame") < 10 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 10 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		who->add_save("diemgame",-10);
		"sys/sys/test_db"->add_yuanbao(who, 50);	
		send_user(who,"%c%s",';',"Bạn nhận được "HIY " 5 "NOR" KNB !!!");
		break;
		
		case 2:
		if ( who->get_save("diemgame") < 10 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 10 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 2 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Văn Ương :\nHành trang của ngươi không đủ 2 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		who->add_save("diemgame",-10);
		item = new("/item/nangcap/tuibanhngot5");
		i = item->move(who,-1);
		item->add_to_user(i);
		
		item2 = new("/item/nangcap/tuidathan5");
		p = item2->move(who,-1);
		item2->add_to_user(p);
		send_user(who,"%c%s",';',"Bạn nhận được Gói Nguyên Liệu Nâng Cấp Thú");
		break;
		
		case 3:
		if ( who->get_save("diemgame") < 10 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 10 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 2 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Văn Ương :\nHành trang của ngươi không đủ 3 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		who->add_save("diemgame",-10);
		item = new("/item/nangcap/canhpp/tuicanhtt5");
		i = item->move(who,-1);
		item->add_to_user(i);
		
		item2 = new("/item/nangcap/canhpp/tuilenhtt5");
		p = item2->move(who,-1);
		item2->add_to_user(p);
		
		item3 = new("/item/nangcap/canhpp/tuingoctiende5");
		l = item3->move(who,-1);
		item3->add_to_user(l);
		send_user(who,"%c%s",';',"Bạn nhận được Gói Nguyên Liệu Nâng Cấp Cánh́");
		break;
		
		case 4:
		if ( who->get_save("diemgame") < 20 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 20 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		who->add_save("diemgame",-20);
		who->add_cash(300000);
		send_user(who,"%c%s",';',"Bạn nhận được 300.000 ngân lượng");
		break;
		
		case 5:
		if ( who->get_save("diemgame") < 20 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 20 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Văn Ương :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		who->add_save("diemgame",-20);
		item = new("item/test/vosongdiemphieu");
		item->set_amount(10);
		i = item->move(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được 10 Vô Song Điểm Phiếu");
		break;
		
		case 6:
		if ( who->get_save("diemgame") < 50 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 50 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Văn Ương :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		who->add_save("diemgame",-50);
		item = new("item/dtkhoa/0032");
		i = item->move(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được Sơ Cấp Đoạn Thạch (Khóa)");
		break;
		
		case 7:
		if ( who->get_save("diemgame") < 90 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 90 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Văn Ương :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		who->add_save("diemgame",-90);
		item = new("item/dtkhoa/1032");
		i = item->move(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được Trung Cấp Đoạn Thạch (Khóa)");
		break;
		
		case 8:
		if ( who->get_save("diemgame") < 70 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 70 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Văn Ương :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		who->add_save("diemgame",-70);
		item = new("item/sell/0032");
		i = item->move(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được Sơ Cấp Đoạn Thạch (Không Khóa)");
		break;
		
		case 9:
		if ( who->get_save("diemgame") < 130 )
			{	
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 130 điểm Mini Game!!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Văn Ương :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
		who->add_save("diemgame",-130);
		item = new("item/sell/1032");
		i = item->move(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Bạn nhận được Trung Cấp Đoạn Thạch (Không Khóa)");
		break;
		}
}
