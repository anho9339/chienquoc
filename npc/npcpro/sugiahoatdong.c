/*
Edit by Nguyễn Quang Hiếu
*/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>

inherit OFFICER;

// 函数：获取人物造型
void reset();
int get_char_picid() { return 6010; }
int is_seller() { return 1; }
int is_self_look() { return 1; }
void do_gift( string arg );

// 函数：构造处理
void create()
{
        set_name("Hỗ Trợ Mỗi Ngày");
		set_real_name(HIR "Nguyễn Ngọc Nhi");
        set_2( "good", ([
                "01" : "/item/doanthachban/0032",
				"02" : "/item/doanthachban/1032",
				"03" : "/item/doanthachban/2032",
//				"04" : "/item/test/dacankhon",
//				"05" : "/item/test/datuonguyen",
//				"06" : "/item/sell/0033",
//				"04" : "/item/70/1075",
//				"05" : "/item/71/1075",
//				"06" : "/item/72/1075",
//				"07" : "/item/73/1075",
//				"08" : "/item/74/1075",
//				"09" : "/item/75/1075",
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn nhận hỗ trợ hay tham gia hoạt động gì?????? \n"
		ESC HIY"Nhận hỗ trợ mỗi giờ\ntalk %x# gift.59\n"
		ESC HIY"Nhận hỗ trợ hằng ngày\ntalk %x# gift.56\n"
//		ESC HIY"Ta muốn thuê trang bị Bá Vương\ntalk %x# gift.1\n"
//		ESC HIY"Ta muốn đổi Cực Hiệu lấy Siêu Cấp\ntalk %x# gift.11\n"
//		ESC HIY"Ta muốn Hợp Thành Vật Phẩm\ntalk %x# gift.2\n"
//		ESC HIY"Ta muốn đổi Kinh Nghiệm\ntalk %x# gift.12\n"
//		ESC HIY"Tham gia Sự kiện Ngũ Đại Thần Khí\ntalk %x# gift.7\n"
//		ESC HIY"Dùng 100 KNB mua 1000 cây Pháo đánh Niên Thú\ntalk %x# gift.57\n"
//		ESC HIY"Mua Vật Phẩm\nlist %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio;
	object who,item;
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
        switch(flag)
        {
       	case 1:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn thuê trang bị Truyền Thuyết nguyên bộ hay từng món??? \nMỗi món có giá : 1 Tiền Vàng 500 Xu \nNguyên bộ có giá : 5 Tiền Vàng 500 Xu \n Trang bị Truyền Thuyết sau khi thuê có hạn sử dụng 30 ngày \n"
					ESC HIY"Thuê trang bị [Áo]\ntalk %x# gift.20\n"
					ESC HIY"Thuê trang bị [Nón]\ntalk %x# gift.21\n"
					ESC HIY"Thuê trang bị [Hạng Liên]\ntalk %x# gift.22\n"
					ESC HIY"Thuê trang bị [Yêu Đới]\ntalk %x# gift.23\n"
					ESC HIY"Thuê trang bị [Giày]\ntalk %x# gift.24\n"
					ESC HIY"Thuê [Nguyên Bộ Truyền Thuyết]\ntalk %x# gift.25\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
			break;
		case 2:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \nPháp Bảo Bá Vương: cần 200 mảnh ghép Pháp Bảo \nHoả Kì Lân: cần 30 mảnh ghép Thú Cưỡi \nVũ Khí Bá Vương: cần 500 mảnh ghép Vũ Khí \nMỗi lần Hợp Thành Vật Phẩm tiêu hao: 50.000.000 lượng \n"
//					ESC HIY"[Pháp Bảo Bá Vương]\ntalk %x# gift.26\n"
//					ESC HIY"[Hoả Kì Lân]\ntalk %x# gift.27\n"
//					ESC HIY"[Vũ Khí Bá Vương]\ntalk %x# gift.28\n"
					ESC HIY"[Phi Phong và Cánh]\ntalk %x# gift.3\n"
					ESC HIY"[Ngoại Trang Bá Vương]\ntalk %x# gift.4\n"
					ESC HIY"[Ngọc Bội Tín Vật]\ntalk %x# gift.5\n"
//					ESC HIY"[Trang bị Bá Vương 8 sao]\ntalk %x# gift.6\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id));
			break;
		case 3:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \nPhi Phong và Cánh: cần 100 mảnh ghép Vương Giả \nMỗi lần Hợp Thành Vật Phẩm tiêu hao: 50.000.000 lượng \n"
					ESC HIY"[Phi Phong Nam]\ntalk %x# gift.29\n"
					ESC HIY"[Phi Phong Nữ]\ntalk %x# gift.30\n"
					ESC HIY"[Cánh Nam]\ntalk %x# gift.31\n"
					ESC HIY"[Cánh Nữ]\ntalk %x# gift.32\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id));
			break;
		case 4:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \nNgoại Trang Bá Vương: cần 200 mảnh ghép Ngoại Trang \nMỗi lần Hợp Thành Vật Phẩm tiêu hao: 50.000.000 lượng \n"
					ESC HIY"[Bá Vương Trang Nam]\ntalk %x# gift.33\n"
					ESC HIY"[Bá Vương Trang Nữ]\ntalk %x# gift.34\n"
					ESC"Rời khỏi",get_name(),id,id,id));
			break;
		case 5:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \nKì Lân Ngọc Bội: cần 5 mảnh ghép Ngọc Bội \nPhượng Hoàng Ngọc Bội: cần 10 mảnh ghép Ngọc Bội \nThỏ Thần Ngọc Bội: cần 20 mảnh ghép Ngọc Bội \nĐại Thánh Ngọc Bội: cần 30 mảnh ghép Ngọc Bội \nThiên Long Ngọc Bội 1: cần 50 mảnh ghép Ngọc Bội \nThiên Long Ngọc Bội 2: cần 100 mảnh ghép Ngọc Bội \nThiên Long Ngọc Bội 3: cần 150 mảnh ghép Ngọc Bội \nThiên Long Ngọc Bội 4: cần 200 mảnh ghép Ngọc Bội \nThiên Long Ngọc Bội 5: cần 300 mảnh ghép Ngọc Bội \nMỗi lần Hợp Thành Vật Phẩm tiêu hao: 50.000.000 lượng \n"
					ESC HIY"[Kì Lân Ngọc Bội]\ntalk %x# gift.35\n"
					ESC HIY"[Phượng Hoàng Ngọc Bội]\ntalk %x# gift.36\n"
					ESC HIY"[Thỏ Thần Ngọc Bội]\ntalk %x# gift.37\n"
					ESC HIY"[Đại Thánh Ngọc Bội]\ntalk %x# gift.38\n"
					ESC HIY"[Thiên Long Ngọc Bội 1]\ntalk %x# gift.39\n"
					ESC HIY"[Thiên Long Ngọc Bội 2]\ntalk %x# gift.40\n"
					ESC HIY"[Thiên Long Ngọc Bội 3]\ntalk %x# gift.41\n"
					ESC HIY"[Thiên Long Ngọc Bội 4]\ntalk %x# gift.42\n"
					ESC HIY"[Thiên Long Ngọc Bội 5]\ntalk %x# gift.43\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id,id));
			break;
		case 6:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \n[Áo]: cần 500 mảnh ghép Áo \n[Nón]: cần 500 mảnh ghép Nón \n[Hạng Liên]: cần 500 mảnh ghép Hạng Liên \n[Yêu Đới]: cần 500 mảnh  ghép Yêu Đới \n[Giày]: cần 500 mảnh ghép Giày  \nMỗi lần Hợp Thành Vật Phẩm tiêu hao: 50.000.000 lượng \n"
					ESC HIY"[Áo]\ntalk %x# gift.44\n"
					ESC HIY"[Nón]\ntalk %x# gift.45\n"
					ESC HIY"[Hạng Liên]\ntalk %x# gift.46\n"
					ESC HIY"[Yêu Đới]\ntalk %x# gift.47\n"
					ESC HIY"[Giày]\ntalk %x# gift.48\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
			break;
		case 7:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn giúp ta tìm Ngũ Quy Thần Khí sao?????? \n"
					ESC HIY"Ta muốn dùng Ngũ Quy Thần Khí đổi thưởng\ntalk %x# gift.8\n"
					ESC HIY"Ta muốn tìm hiểu\ntalk %x# gift.9\n"
					ESC HIY"Ta muốn Hợp thành Ngũ Quy Thần Khí\ntalk %x# gift.10\n"
					ESC"Rời khỏi",get_name(),id,id,id,id));
			break;
		case 8:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi chỉ cần đưa ta 3 Ngũ Quy Thần Khí ta sẽ tặng lại ngươi một thứ quý giá của ta (Cấp bậc +1 chỉ cần 1 Ngũ Quy Thần Khí) \nNgươi muốn lấy thứ gì??!! \n"
//					ESC HIY"Trang bị Truyền Thuyết\ntalk %x# gift.50\n"
					ESC HIY"500 Mảnh Ghép Vũ Khí\ntalk %x# gift.51\n"
					ESC HIY"500 Mảnh Ghép Pháp Bảo\ntalk %x# gift.52\n"
					ESC HIY"500 Mảnh Ghép Vương Giả\ntalk %x# gift.53\n"
//					ESC HIY"3000 điểm Tiềm Năng\ntalk %x# gift.54\n"
					ESC HIY"Mật Tịch Bá Vương\ntalk %x# gift.55\n"
					ESC HIY"Cộng thêm 1 cấp bậc\ntalk %x# gift.58\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id));
			break;
		case 9:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi đã bao giờ nghe đến 5 món Thần Khí từ thời thượng cổ chưa ? Trong thế giới Chiến Quốc này ngoài ta ra không ai biết được nó đang ở đâu ! hahaha \nTa nghe nói 5 món Thần Khí thượng cổ đang bị con yêu nghiệt Sói Vương cất giấu. Vào lúc 3 - 5 - 7 giờ ta thường thấy nó đi dạo tại Phong Thiền Đài của nước Chu (105,140). Ngươi hãy nắm bắt cơ hội đi tiêu diệt nó để có được 5 món Thần Khí thượng cổ \nSau khi có được 5 món Thần Khí thượng cổ hãy Hợp thành Ngũ Quy Thần Khí và ta sẽ tặng ngươi rất nhiều Bảo vật nếu như ngươi chịu đưa ta 3 Ngũ Quy Thần Khí  \n"
					ESC"Rời khỏi",get_name(),id));
			break;
		case 10:
		if ( flag == 10 )
		{
			cTmp = "Đàn Phục Hy";
			cFile = "item/event/NguQuyThanKhi";
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Kính Côn Lôn") < 1 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Ấn Không Động") < 1 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Đỉnh Thần Nông") < 1 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Đá Nữ Oa") < 1 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Sứ Giả Hoạt Động:\n Ngươi không có đủ 5 món Thần Khí! Hợp thành %s cần 5 loại Thần Khí:\n "+cTmp+", Kính Côn Lôn, Đá Nữ Oa, Ấn Không Động, Đỉnh Thần Nông \n5 món Thần Khí thượng cổ sẽ có được khi tiêu diệt Sói Vương.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		if(USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang của bạn đã đầy!");
			return 0;
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Kính Côn Lôn",1);
		TASK_LEGEND_D->check_task_item1(who,"Ấn Không Động",1);
		TASK_LEGEND_D->check_task_item1(who,"Đỉnh Thần Nông",1);
		TASK_LEGEND_D->check_task_item1(who,"Đá Nữ Oa",1);
		item = new(cFile);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn hợp thành được "HIY+item->get_name());
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
		case 12:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Điểm tích luỹ Sư Môn của bạn hiện là "HIR "%d "NOR "điểm !! \n"
					ESC HIY"[Dùng 5 điểm đổi lấy Kinh Nghiệm]\ntalk %x# gift.66\n"
					ESC"Rời khỏi",get_name(),who->get_save("diemsumon.score"),id,id));
			break;	
		case 20:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Năm Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Trăm Xu",1);
		item = new("/item/set10sao/truyenthuyet30ngay/ao");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 1 Tiền Vàng Năm Trăm Xu để thuê: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 21:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Năm Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Trăm Xu",1);
		item = new("/item/set10sao/truyenthuyet30ngay/non");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 1 Tiền Vàng Năm Trăm Xu để thuê: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 22:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Năm Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Trăm Xu",1);
		item = new("/item/set10sao/truyenthuyet30ngay/hanglien");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 1 Tiền Vàng Năm Trăm Xu để thuê: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 23:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Năm Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Trăm Xu",1);
		item = new("/item/set10sao/truyenthuyet30ngay/yeudoi");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 1 Tiền Vàng Năm Trăm Xu để thuê: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 24:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Trăm Xu") < 1 )
			{
				notify( "Ngươi không có Tiền Vàng Năm Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Trăm Xu",1);
		item = new("/item/set10sao/truyenthuyet30ngay/giay");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 1 Tiền Vàng Năm Trăm Xu để thuê: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 25:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Tiền Vàng Năm Trăm Xu") < 5 )
			{
				notify( "Ngươi không có 5 Tiền Vàng Năm Trăm Xu" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Tiền Vàng Năm Trăm Xu",5);
		item = new("/item/set10sao/truyenthuyet30ngay/set10sao");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 5 Tiền Vàng Năm Trăm Xu để thuê: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 26:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Pháp Bảo") < 250 )
			{
				notify( "Ngươi không có 250 Mảnh Ghép Pháp Bảo" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Pháp Bảo",250);	
		item = new("/item/phapbaoHK/tuiphapbaohoangkimcaocap");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 250 Mảnh Ghép Pháp Bảo hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 27:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Thú Cưỡi") < 30 )
			{
				notify( "Ngươi không có 30 Mảnh Ghép Thú Cưỡi" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Thú Cưỡi",30);
		item = new("/item/ride/018");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 30 Mảnh Ghép Thú Cưỡi hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		break;
		case 28:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Vũ Khí") < 500 )
			{
				notify( "Ngươi không có 500 Mảnh Ghép Vũ Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Vũ Khí",500);	
		item = new("/item/set10sao/bavuong/tuivukhibavuong");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 500 Mảnh Ghép Vũ Khí hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 29:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Vương Giả") < 100 )
			{
				notify( "Ngươi không có 100 Mảnh Ghép Vương Giả" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Vương Giả",100);	
		item = new("/item/ppvacanh/phiphong/phiphong1");
		//item->set_hide(0);
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100 Mảnh Ghép Vương Giả hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 30:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Vương Giả") < 100 )
			{
				notify( "Ngươi không có 100 Mảnh Ghép Vương Giả" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Vương Giả",100);
		item = new("/item/ppvacanh/phiphong/phiphong2");
		item->set_hide(0);
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100 Mảnh Ghép Vương Giả hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 31:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Vương Giả") < 100 )
			{
				notify( "Ngươi không có 100 Mảnh Ghép Vương Giả" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Vương Giả",100);	
		item = new("/item/ppvacanh/canh/canh1");
		item->set_hide(0);
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100 Mảnh Ghép Vương Giả hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 32:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Vương Giả") < 100 )
			{
				notify( "Ngươi không có 100 Mảnh Ghép Vương Giả" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Vương Giả",100);
		item = new("/item/ppvacanh/canh/canh2");
		item->set_hide(0);
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100 Mảnh Ghép Vương Giả hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 33:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngoại Trang") < 200 )
			{
				notify( "Ngươi không có 200 Mảnh Ghép Ngoại Trang" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngoại Trang",200);	
		item = new("/item/ngoai_trang/vip10");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 200 Mảnh Ghép Ngoại Trang hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 34:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngoại Trang") < 200 )
			{
				notify( "Ngươi không có 200 Mảnh Ghép Ngoại Trang" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngoại Trang",200);	
		item = new("/item/ngoai_trang/vip20");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 200 Mảnh Ghép Ngoại Trang hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 35:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 5 )
			{
				notify( "Ngươi không có 5 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",5);	
		item = new("/item/01/0007");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 5 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 36:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 10 )
			{
				notify( "Ngươi không có 10 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",10);	
		item = new("/item/01/0008");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 10 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 37:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 20 )
			{
				notify( "Ngươi không có 20 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",20);	
		item = new("/item/01/0009");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 20 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 38:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 30 )
			{
				notify( "Ngươi không có 30 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",30);	
		item = new("/item/01/0010");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 30 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 39:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 50 )
			{
				notify( "Ngươi không có 50 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",50);	
		item = new("/item/01/0011");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 50 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 40:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 100 )
			{
				notify( "Ngươi không có 100 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",100);	
		item = new("/item/01/0012");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 100 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 41:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 150 )
			{
				notify( "Ngươi không có 150 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",150);	
		item = new("/item/01/0013");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 150 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 42:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 200 )
			{
				notify( "Ngươi không có 200 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",200);	
		item = new("/item/01/0014");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 200 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 43:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Ngọc Bội") < 300 )
			{
				notify( "Ngươi không có 300 Mảnh Ghép Ngọc Bội" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Ngọc Bội",300);	
		item = new("/item/01/0015");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 300 Mảnh Ghép Ngọc Bội hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 44:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Áo") < 500 )
			{
				notify( "Ngươi không có 500 Mảnh Ghép Áo" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Áo",500);	
		item = new("/item/set10sao/bavuongghep/ao");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 500 Mảnh Ghép Áo hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 45:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Nón") < 500 )
			{
				notify( "Ngươi không có 500 Mảnh Ghép Nón" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Nón",500);	
		item = new("/item/set10sao/bavuongghep/non");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 500 Mảnh Ghép Nón hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 46:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Hạng Liên") < 500 )
			{
				notify( "Ngươi không có 500 Mảnh Ghép Hạng Liên" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Hạng Liên",500);	
		item = new("/item/set10sao/bavuongghep/hanglien");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 500 Mảnh Ghép Hạng Liên hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 47:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Yêu Đới") < 500 )
			{
				notify( "Ngươi không có 500 Mảnh Ghép Yêu Đới" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Yêu Đới",500);	
		item = new("/item/set10sao/bavuongghep/yeudoi");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 500 Mảnh Ghép Yêu Đới hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 48:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Giày") < 500 )
			{
				notify( "Ngươi không có 500 Mảnh Ghép Giày" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Giày",500);	
		item = new("/item/set10sao/bavuongghep/giay");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 500 Mảnh Ghép Giày hợp thành: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 50:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Quy Thần Khí") < 3 )
			{
				notify( "Ngươi không có 3 Ngũ Quy Thần Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Quy Thần Khí",3);	
		item = new("/item/set10sao/bavuongghep/set10sao");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy Ngũ Quy Thần Khí để đổi lấy: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 51:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Quy Thần Khí") < 3 )
			{
				notify( "Ngươi không có 3 Ngũ Quy Thần Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Quy Thần Khí",3);
		item = new("/item/test/tuimanhghepvukhi_500");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy Ngũ Quy Thần Khí để đổi lấy: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 52:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Quy Thần Khí") < 3 )
			{
				notify( "Ngươi không có 3 Ngũ Quy Thần Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Quy Thần Khí",3);	
		item = new("/item/test/tuimanhghepphapbao_500");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy Ngũ Quy Thần Khí để đổi lấy: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 53:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Quy Thần Khí") < 3 )
			{
				notify( "Ngươi không có 3 Ngũ Quy Thần Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Quy Thần Khí",3);
		item = new("/item/test/tuimanhghepvuonggia_500");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy Ngũ Quy Thần Khí để đổi lấy: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 54:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Quy Thần Khí") < 3 )
			{
				notify( "Ngươi không có 3 Ngũ Quy Thần Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Quy Thần Khí",3);
		who->add_gift_point(3000);
		USER_D->user_channel(sprintf(HIG "Bằng hữu "HIC "%s" HIG " đổi Ngũ Quy Thần Khí nhận được  "HIY " 3000 điểm Tiềm Năng  "HIG " . ", who->get_name() ));
		break;
		case 55:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Quy Thần Khí") < 3 )
			{
				notify( "Ngươi không có 3 Ngũ Quy Thần Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Quy Thần Khí",3);
		item = new("/item/bikip150/mattichbavuong");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy Ngũ Quy Thần Khí để đổi lấy: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 56:
		if (who->get_save_2("fride.day")==iDay)
		{
			result = me->get_name()+"：\n    Hôm nay đã nhận rồi, ngày mai hãy đến !\n";
			send_user( who, "%c%c%w%s", ':', 3, 6010, result );
			return;
		}
		who->set_save_2("fride.day", iDay);
		who->add_cash(10000);
		who->add_exp(who->get_level()*100);
//		who->set_level(who->get_level()+1);
//		who->add_save_2("diemtienvang.score",1000);
//		"sys/sys/test_db"->add_yuanbao(who,50);
		item = new("/item/08/0001");
		i = item->move(who,-1);
		item->add_to_user(i);
		send_user(who,"%c%s",':',me->get_name()+"：\nExp: +1 ít\nKim Nguyên Bảo +5 \nNgân lượng +10.000 lượng \n1 cái CQLx4 \n" ESC"Rời khỏi.");
		break;
		case 57:
		if("sys/sys/test_db"->get_yuanbao(who)<1000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Không đủ 100 Kim Bảo !!!\n Số KNB của ngươi hiện chỉ là :" HIR "%d Kim","sys/sys/test_db"->get_yuanbao(who)/10));
			return 0;
		}
		"sys/sys/test_db"->add_yuanbao(who,-1000);
		item = new("/item/test/tuiphao");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa lấy 200 Kim Bảo để mua: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 58:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Ngũ Quy Thần Khí") < 1 )
			{
				notify( "Ngươi không có 1 Ngũ Quy Thần Khí" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Ngũ Quy Thần Khí",1);
		who->set_level(who->get_level()+1);	
		send_user(who,"%c%s",':',me->get_name()+"：\nBạn được thăng lên thêm 1 cấp bậc...Xin chúc mừng !! \n"ESC"Rời khỏi.");
		break;
		case 59:
		if (who->get_save_2("fride.gio")==iGio)
		{
			result = me->get_name()+"：\n    Đã nhận rồi, hãy đợi tới giờ kế tiếp !\n";
			send_user( who, "%c%c%w%s", ':', 3, 6010, result );
			return;
		}
		who->set_save_2("fride.gio", iGio);
		who->add_cash(5000);
		who->add_exp(who->get_level()*20);
//		who->set_level(who->get_level()+1);
//		who->add_save_2("diemtienvang.score",1000);
//		"sys/sys/test_db"->add_yuanbao(who,10);
		send_user(who,"%c%s",':',me->get_name()+"：\nNgân lượng +5.000 lượng \nMột ít exp \n"ESC"Rời khỏi.");
		break;
		case 60:
		if ( TASK_LEGEND_D->check_task_item_amount(who,"Cực Hiệu Khí Huyết") < 2 )
			{
				notify( "Ngươi không có 2 Cực Hiệu Khí Huyết" );
				return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Khí Huyết",2);	
		item = new("/item/final/SieuCap/1524");
		i = item->move(who,-1);
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
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Pháp Lực",2);	
		item = new("/item/final/SieuCap/1526");
		i = item->move(who,-1);
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
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Ngoại Công",2);	
		item = new("/item/final/SieuCap/1525");
		i = item->move(who,-1);
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
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Nội Công",2);	
		item = new("/item/final/SieuCap/1528");
		i = item->move(who,-1);
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
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Ngoại Kháng",2);	
		item = new("/item/final/SieuCap/1527");
		i = item->move(who,-1);
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
			TASK_LEGEND_D->check_task_item1(who,"Cực Hiệu Nội Kháng",2);	
		item = new("/item/final/SieuCap/1529");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf("Bằng hữu %s vừa đổi 2 Cực Hiệu Nội Kháng để lấy: %s", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 66:
		if ( who->get_save_2("diemsumon.score") < 5 )
			{	
				send_user(who,"%c%s",':',me->get_name()+"：\n    Không đủ 5 điểm tích luỹ Sư Môn!!! \nĐiểm tích luỹ Sư Môn có thể có được 1 điểm sau mỗi lần hoàn thành nhiệm vụ lượt thứ 10 của Sư Môn !!!\n"ESC"Rời khỏi.");
				return 0;
			}	
		who->add_exp(who->get_level()*5000);
		send_user(who,"%c%s",';',"Bạn nhận được "HIY " kinh nghiệm chúc phúc của Chưởng Môn Nhân");
		break;
		}
}
