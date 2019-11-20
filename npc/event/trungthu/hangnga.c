/*
Edit by Pret Kuzl
*/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>

inherit OFFICER;

// 函数:获取人物造型
void reset();
int get_char_picid() { return 6009; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name("Tết Trung Thu");
		set_real_name(HIR "Hằng Nga");
    /*    set_2( "good", ([
                "01" : "/item/test/tuihoangkimtanthucap20",
                "02" : "/item/test/tuihoangkimtanthucap30",             
        ]) );*/
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Haizz, bọn Thỏ Ngọc fake đã xuống đây quấy rối người dân, còn ăn cắp đồ ăn của họ, vị anh hùng đây có hứng thú muốn giúp không?\n Ngươi có lấy được Bánh Trung Thu và thu phục được bọn chúng ko? Ta có phần thưởng hậu hĩnh đấy!\n"
		ESC HIG"Ta muốn đổi Bánh Trung Thu lấy phần thưởng\ntalk %x# gift.1\n"
		ESC HIY"Ta muốn đổi Thỏ Ngọc lấy phần thưởng\ntalk %x# gift.2\n"
		ESC"Rời khỏi",get_name(),id,id,id,id));	
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien,item1,gioitinh;
	object who,item,item2,item3;
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
		gioitinh = who->get_gender() == 1 ? 10 : 11;
        switch(flag)
        {
       	case 1:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Bánh Trung Thu") < 10 )
			{
				notify( "Ngươi không có 10 Bánh Trung Thu" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Bánh Trung Thu",10);	
	if ( rate < 10 )	//Sơ Cấp Đoạn Thạch	
	{
		item = new("/item/sell/0032");
		if ( !item )
			return 0;
	}
	else if ( rate < 15 )		// 10 KNB
	{
		item = new("/item/bikipknb/knb10");
		if ( !item )
			return 0;
	}
	else if ( rate < 20 )		// Thẻ Giảm Giá
	{
		item = new("/item/test2/TheGiamGia");
		if ( !item )
			return 0;
	}
	else if ( rate < 25 )	
	{
		item = new("/item/bikipknb/knb4");
		if ( !item )
			return 0;
	}
	
	else if ( rate < 32 )	//Túi Pháp Bảo
	{
		item = new("/item/test2/TuiPhapBao"); 
		if ( !item )
			return 0;
	}
	else if ( rate < 40 )	
	{
		item = new("item/91/0002"); // Khu Ma Tán
		if ( !item )
			return 0;
	}
	else if ( rate < 60 )	// Thần thú Trung Thu
	{
		item = new(sprintf("/item/event/trungthu/qua/thanthu/1%d",random(2)));
		if ( !item )
			return 0;
	}
	else if ( rate < 70 )	
	{
		item = new("item/91/9112"); // Bổ Tâm Đan
		if ( !item )
			return 0;
	}
	else if ( rate < 80 )
	{
		item = new("item/91/9102"); // Tạo Hóa Đơn
		if ( !item )
			return 0;
	}
	else 			
	{
		who->add_cash(20000);
	}
	if ( item )
	{
		l = item->move2(who,-1);
		item->add_to_user(l);
		send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
		USER_D->user_channel(sprintf("Anh hùng "HIG "%s "NOR " vừa đổi Bánh Trung Thu nhận được: " HIC"%s " HIG " .", who->get_name(),item->get_name() ));
	}
		return 0;
		break;
		
		case 2:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Thỏ Ngọc") < 20 )
			{
				notify( "Ngươi không có 20 Thỏ Ngọc" );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
				notify( "Hành trang không đủ 1 chỗ trống" );
		return ;
		}	
			TASK_LEGEND_D->check_task_item1(who,"Thỏ Ngọc",20);
			/*if ( random100() < 20 )
			{
	nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),who->get_level(),HEAD_TYPE+random(6));
	cFile = nTmp[random(sizeof(nTmp))];
	if( load_object(cFile) )
	{
		item = new( cFile );
		ITEM_EQUIP_D->init_equip_prop_3(item);
		item->set_hide(0);
		item->set_bind(1);
		l = item->move2(who,-1);
		item->add_to_user(l);
	}
				if ( item ) send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+".");
			}
			else 
			{
				notify("Đổi thất bại !");
			} */
		 if ( rate < 10 )		
	{
		item = new("/item/sell/0032"); // Sơ Cấp
		if ( !item )
			return 0;
	}
	else if ( rate < 15 )		
	{
		item = new("/item/sell/0034"); // Bảo Để Phù
		if ( !item )
			return 0;
	}
	else if ( rate < 25 )	// Đồ Xanh
	nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(),who->get_gender(),who->get_level(),HEAD_TYPE+random(6));
	cFile = nTmp[random(sizeof(nTmp))];
	if( load_object(cFile) )
	{
		item = new( cFile );
		ITEM_EQUIP_D->init_equip_prop_2(item);
		item->set_hide(0);
		item->set_bind(1);
		l = item->move2(who,-1);
		item->add_to_user(l);
	}
	else if ( rate < 32 )	 // Linh Thạch
	{
		item = new(sprintf("/item/event/trungthu/qua/random/93%d",random(10))); 
		if ( !item )
			return 0;
	}
	else if ( rate < 40 )	// Tinh Nguyên Đơn
	{
		item = new("/item/44/4488"); 
		if ( !item )
			return 0;
	}
	else if ( rate < 60 )	
	{
		item = new(sprintf("/item/event/trungthu/qua/thanthu/1%d",random(2))); // Thần thú trung thu
		if ( !item )
			return 0;
	}
	else if ( rate < 70 )	
	{
		item = new("item/91/9121"); //Hoạt Tâm Đơn
		if ( !item )
			return 0;
	}
	else if ( rate < 80 )
	{
		item = new("item/91/9120"); // Cấp Cứu Đơn
		if ( !item )
			return 0;
	}
	else 				
		{
		who->add_cash(40000);
	}	
	if ( item )
	{
		l = item->move2(who,-1);
		item->add_to_user(l);
		send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
		USER_D->user_channel(sprintf("Anh hùng "HIG "%s "NOR " vừa giao ra Thỏ Ngọc và nhận được: " HIC"%s " HIG " .", who->get_name(),item->get_name() ));
	}
		return 0;
		break;
		case 3:
			break;	
			
		}
}
