/* Tổng hợp and Edit by Pret Kuzl */
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>

inherit OFFICER;

// 函数：获取人物造型
void reset();
int get_char_picid() { return 8299; } // 6010
int is_seller() { return 7009; }
int is_self_look() { return 1; }
void do_gift( string arg );

// 函数：构造处理
void create()
{
        set_name("Sứ Giả Sự Kiện");
		set_real_name(HIR "Nguyệt Nhi");
        set_2( "good", ([
                "01" : "/item/ngoai_trang/nam/1",
				"02" : "/item/ngoai_trang/nam/2",
				"03" : "/item/ngoai_trang/nam/3",
				"04" : "/item/ngoai_trang/nam/4",
				"05" : "/item/ngoai_trang/nam/5",
				"06" : "/item/ngoai_trang/nu/1",
				"07" : "/item/ngoai_trang/nu/2",
				"08" : "/item/ngoai_trang/nu/3",
				"09" : "/item/ngoai_trang/nu/4",
				"10" : "/item/ngoai_trang/nu/5",
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Chào các bằng hữu, ta là sứ giả sự kiện của chiến quốc tâm diện. Nay các vị tìm đến ta có việc gì??! \n"
		ESC HIY"Nhận hỗ trợ mỗi giờ\ntalk %x# gift.1\n"
		ESC HIY"Nhận hỗ trợ hằng ngày\ntalk %x# gift.2\n"
		ESC HIB"Ta muốn Nâng Cấp Trang Bị Vai\ntalk %x# gift.3\n"
		ESC HIB"Ta muốn Nâng Cấp Thú Cưỡi\ntalk %x# gift.4\n"	
		ESC HIC"Ta muốn Tách Đoạn Thạch\ntalk %x# gift.5\n"
		ESC HIC"Ta muốn Ghép Vật Phẩm\ntalk %x# gift.6\n"
	//	ESC HIC"Ta muốn Ghép Đoạn Thạch\ntalk %x# gift.7\n"
		ESC HIY"Nhận Túi Quà May Mắn\ntalk %x# gift.8\n"	
		ESC "Tham gia Event\ntalk %x# gift.9\n"
		ESC "Đổi Vật Phẩm Hoạt Động\ntalk %x# gift.10\n"
		ESC HIM"Đổi Cầu\ntalk %x# gift.11\n"
		ESC HIM"Phần Thưởng Nạp Thẻ\ntalk %x# gift.12\n"
		ESC HIY"Đổi Nhẫn Huyền Băng\nlist11 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id,id,id,id,id,id));
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,s,size,sao,ben,ben123,tien,tet1=0,tet2=0,l,tet3,tet4,bennhat2,bn2,gioitinh,rate,knb;
	object who,item,item1,item2,item3,item4,item5;
	string *nTmp,cFile,cTmp,cFinal,result;
	string name,name2,name3,name4,thanbinh,ss,forge="",nhat123,nhat1234,bennhat,bn;
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
			/// Nhận Hỗ Trợ Mỗi Giờ
       	case 1:
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
			/// Hỗ Trợ Mỗi Ngày
		case 2:
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
					send_user(who,"%c%s",':',me->get_name()+"：\nExp: +1 ít\nKim Nguyên Bảo +5 \nNgân lượng +10.000 lượng \n1 Chiến Quốc Lệnh \n" ESC"Rời khỏi.");
					break;
					
					/* Nâng Cấp Trang Bị Vai */
			/// Lựa Chọn
		case 3:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Vạn vật luân hồi, chúng cần phải được đổi mới để theo kịp thời đại. Trong thời buổi loạn lạc này, càng mạnh thì càng có thế, vậy ngươi tìm ta có chuyện gì không? \n"
				ESC "Nâng Cấp Cánh\ntalk %x# gift.31\n"
				ESC "Nâng Cấp Phi Phong\ntalk %x# gift.32\n"
				ESC "Công thức và nguyên liệu nâng cấp\ntalk %x# gift.33\n"
				ESC "Rời khỏi",get_name(),id,id,id,id,id));
				break;
			/// Lựa chọn cánh Nam Nữ
		case 31:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC "Cánh Nam\ntalk %x# gift.34\n"
				ESC "Cánh Nữ\ntalk %x# gift.35\n"
				ESC "Rời khỏi",get_name(),id,id,id,id,id));
				break;
			/// Lựa chọn phi phong Nam Nữ 
		case 32:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" Nguyệt Nhi :\n Ta có khả năng làm vạn vật phát sinh, sinh sôi nảy nở. Tươi mới và đầy sức mạnh, ngươi cần gì nào?\n"
				ESC"Phi Phong Nam\ntalk %x# gift.36\n"
				ESC"Phi Phong Nữ\ntalk %x# gift.37\n"
				ESC"Rời khỏi\n",id,id,id,id));
				break;
			/// Lựa chọn công thức và nguyên liệu nâng cấp
		case 33:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" Nguyệt Nhi :\n Ngươi muốn tìm hiểu gì? Ta sẽ cho ngươi biết mọi thứ về nâng cấp trang bị vai.\n"
				ESC"Nơi tìm nguyên liệu?\ntalk %x# gift.38\n"
      			ESC"Số lượng nguyên liệu cần có\ntalk %x# gift.39\n"
				ESC"Rời khỏi\n",id,id,id));
				break;
			/// Lựa chọn loại cánh Nam
		case 34:
				send_user(who,"%c%s",':',sprintf("Nguyệt Nhi:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Thánh Linh Chi Dực·Vàng Nhạt\ntalk %x# gift.301\n"
				ESC"Nâng cấp Hoả Lân Chi Dực\ntalk %x# gift.302\n"
				ESC"Nâng cấp Thanh Long Chi Dực\ntalk %x# gift.309\n"
				ESC"Rời khỏi\n",id,id,id,id));
				break;
			/// Lựa chọn loại cánh Nữ
		case 35:
				send_user(who,"%c%s",':',sprintf("Nguyệt Nhi:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Thánh Linh Chi Dực·Trắng Thuần\ntalk %x# gift.303\n"
				ESC"Nâng cấp Huyết Phụng Chi Dực\ntalk %x# gift.304\n"
				ESC"Nâng cấp Huyết Thần Chi Dực\ntalk %x# gift.310\n"		
				ESC"Rời khỏi\n",id,id,id,id));
				break;
			/// Lựa chọn loại pp Nam
		case 36:
				send_user(who,"%c%s",':',sprintf("Nguyệt Nhi:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Vương Giả Phi Phong\ntalk %x# gift.305\n"
				ESC"Nâng cấp Sát Thần Phi Phong\ntalk %x# gift.306\n"
				ESC"Nâng cấp Vương Tử Phi Phong\ntalk %x# gift.311\n"
				ESC"Rời khỏi\n",id,id,id,id));
				break;
			/// Lựa chọn loại pp Nữ
		case 37:
				send_user(who,"%c%s",':',sprintf("Nguyệt Nhi:\n Ở chỗ ta ngươi có thể hoàn toàn yên tâm, ta rất ít khi nâng cấp, mốt khi nâng cấp là sẽ không thất bại. Hãy tin và giao nguyên liệu cho ta!\n"
				ESC"Nâng cấp Xí Nhiệt Phi Phong\ntalk %x# gift.307\n"
				ESC"Nâng cấp Linh Quy Phi Phong\ntalk %x# gift.308\n"
				ESC"Nâng cấp Vương Mẫu Phi Phong\ntalk %x# gift.312\n"				
				ESC"Rời khỏi\n",id,id,id,id));
				break;
		    /// Giới thiệu nơi tìm nguyên liệu
		case 38:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Nâng cấp cánh ngươi có thể đổi cánh bằng vô song điểm phiếu tại Quân Sư Vô Song Thành Chu (282,180).\n Cánh Thiên THần, Lệnh Thiên Tôn và Ngọc Tiên Đế có thể săn boss, đi phụ bản mà có! \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				break;
			/// Giới thiệu số lượng cần có
		case 39:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Cần có 200 Cánh Thiên Thần, 200 Lệnh Thiên Tôn và 180 Ngọc Tiên Đế, nếu thiếu 1 trong 3 thì không thể nâng cấp được \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				break;		
			/// Xuất ra sản phẩm 
		case 301:
		case 302:
		case 303:
		case 304:
		case 305:
		case 306:
		case 307:
		case 308:
		case 309:
		case 310:
		case 311: 
		case 312:
		//Cánh lv 1 2
		if ( flag == 301 )
		{
			cTmp = "Thánh Linh Chi Dực·Vàng Nhạt";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv1";
		}
		else if ( flag == 302 )
		{
			cTmp = "Hoả Lân Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv2";
		}
		else if ( flag == 303 )
		{
			cTmp = "Thánh Linh Chi Dực·Trắng Thuần";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv1";
		}
		else if ( flag == 304 )
		{
			cTmp = "Huyết Phụng Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv2";
		}
		//Pp lv 1 2
		else if ( flag == 305 )
		{
			cTmp = "Vương Giả Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv1";
		}
		else if ( flag == 306 )
		{
			cTmp = "Sát Thần Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv2";
		}
		else if ( flag == 307 )
		{
			cTmp = "Xí Nhiệt Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv1";
		}
		else if ( flag == 308 )
		{
			cTmp = "Linh Quy Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv2";
		}
		//Cánh lv 3
		else if ( flag == 309 )
		{
			cTmp = "Thanh Long Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nam/lv3";
		}
		else if ( flag == 310 )
		{
			cTmp = "Huyết Thần Chi Dực";
			cFile = "item/ppvacanh2/canhnangcap/nu/lv3";
		}
		//PP lv 3
		else if ( flag == 311 )
		{
			cTmp = "Vương Tử Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nam/lv3";
		}
		else if ( flag == 312 )
		{
			cTmp = "Vương Mẫu Phi Phong";
			cFile = "item/ppvacanh2/ppnangcap/nu/lv3";
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Cánh Thiên Thần") < 200 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Lệnh Thiên Tôn") < 200 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Ngọc Tiên Đế") < 180 )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Nguyệt Nhi:\n Nguyên liệu của ngươi không đủ nâng cấp! Nâng cấp %s cần các loại nguyên liệu:\n "+cTmp+", 200 cánh thiên thần, 200 lệnh thiên tôn và 180 ngọc tiên đế.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Cánh Thiên Thần",200);
		TASK_LEGEND_D->check_task_item1(who,"Lệnh Thiên Tôn",200);
		TASK_LEGEND_D->check_task_item1(who,"Ngọc Tiên Đế",180);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(2);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn nâng cấp thành công "HIR+item->get_name());
			break;
			/* Kết thúc nâng cấp trang bị Vai */
			
			/* Nâng Cấp Thú Cưỡi */
			/// Lựa chọn nâng cấp
		case 4:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Mọi thứ đều có quy luật riêng, chúng cần phải được đổi mới để theo kịp thời đại. Trong thời buổi loạn lạc này, chư vị có gì muốn tìm ta? \n"
				ESC"Nâng cấp thú cưỡi\ntalk %x# gift.40\n"
				ESC"Công thức và nguyên liệu nâng cấp thú cưỡi\ntalk %x# gift.41\n"
				ESC"Rời khỏi",get_name(),id,id,id));
				break;
		case 40:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" Nguyệt Nhi :\n Ta có thể nâng cấp toàn bộ thú cưỡi, ta được nữ oa nương nương sai xuống hạ giới cũng chỉ là giúp các ngươi trong thời loạn lạc này mà thôi! Vậy ngươi cần gì ở ta?\n"
				ESC"Nâng cấp Ưng Njnja\ntalk %x# gift.401\n"
				ESC"Nâng cấp Cáo Tuyết\ntalk %x# gift.402\n"
				ESC"Nâng cấp Gấu Trắng\ntalk %x# gift.403\n"
				ESC"Nâng cấp Voi Địa\ntalk %x# gift.404\n"
				ESC"Nâng cấp Rùa Xanh\ntalk %x# gift.405\n"
				ESC"Nâng cấp Ác Điểu\ntalk %x# gift.406\n"
				ESC"Nâng cấp Ngựa Máy\ntalk %x# gift.407\n"
				ESC"Nâng cấp Tuần Lộc Đỏ\ntalk %x# gift.408\n"
				ESC"Nâng cấp Thảm Bay Vàng\ntalk %x# gift.409\n"
				ESC"Nâng cấp Kiến Chiến Binh\ntalk %x# gift.410\n"
				ESC"Nâng cấp Cá Voi Đom Đóm\ntalk %x# gift.411\n"
				ESC"Rời khỏi\n",id,id,id,id,id,id,id,id,id,id,id));
				break;
			/// Lựa chọn giới thiệu
		case 41:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" Nguyệt Nhi :\n Ta có thể nâng cấp toàn bộ thú cưỡi, ta được nữ oa nương nương sai xuống hạ giới cũng chỉ là giúp các ngươi trong thời loạn lạc này mà thôi! Vậy ngươi cần gì ở ta?\n"
				ESC"Phương pháp tìm nguyên liệu nâng cấp thú cưỡi\ntalk %x# gift.42\n"
      			ESC"Số lượng nguyên liệu cần có\ntalk %x# gift.43\n"
				ESC"Rời khỏi\n",id,id));
				break;
			/// Giới thiệu cách tìm nguyên liệu
		case 42:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Nâng cấp thú cưỡi thần có Trứng Thú Cưỡi gốc mở Túi Thú Cưỡi mua từ Tiệm Bảo Khố - CQ Tâm Diện ở Chu (300-155).\n Bánh Ngọt và Đá Thần có thể săn boss, đi phụ bản để có. \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				break;			
			/// Giới thiệu số lượng nguyên liệu
		case 43:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Cần có 200 bánh ngọt và 200 đá thần để nâng cấp thú cưỡi, nếu thiếu thần thú không thể tiến hóa được! \n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				break;
			/// Xuất ra sản phẩm
		case 401:
		case 402:
		case 403:
		case 404:
		case 405:
		case 406:
		case 407:
		case 408:
		case 409:
		case 410:
		case 411:
		if ( flag == 401 )
		{
			cTmp = "Ưng Njnja";
			cFile = "item/ride/NangCap/011";
		}
		else if ( flag == 402 )
		{
			cTmp = "Cáo Tuyết";
			cFile = "item/ride/NangCap/027";
		}
		else if ( flag == 403 )
		{
			cTmp = "Gấu Trắng";
			cFile = "item/ride/NangCap/029";
		}
		else if ( flag == 404 )
		{
			cTmp = "Voi Địa";
			cFile = "item/ride/NangCap/031";
		}
		else if ( flag == 405 )
		{
			cTmp = "Rùa Xanh";
			cFile = "item/ride/NangCap/033";
		}
		else if ( flag == 406 )
		{
			cTmp = "Ác Điểu";
			cFile = "item/ride/NangCap/035";
		}
		else if ( flag == 407 )
		{
			cTmp = "Ngựa Máy";
			cFile = "item/ride/NangCap/037";
		}
		else if ( flag == 408 )
		{
			cTmp = "Tuần Lộc Đỏ";
			cFile = "item/ride/NangCap/039";
		}
		else if ( flag == 409 )
		{
			cTmp = "Thảm Bay Vàng";
			cFile = "item/ride/NangCap/041";
		}
		else if ( flag == 410 )
		{
			cTmp = "Kiến Chiến Binh";
			cFile = "item/ride/NangCap/043";
		}
		else if ( flag == 411 )
		{
			cTmp = "Cá Voi Đom Đóm";
			cFile = "item/ride/NangCap/055";
		}
		if( USER_INVENTORY_D->get_free_count(who) < 1 )
		{
			send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
			return 0;
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Bánh Ngọt") < 200 ||
			TASK_LEGEND_D->check_task_item_amount(who,"Đá Thần") < 200 )
		{
			send_user(who,"%c%c%w%s",':',2,me->get_char_picid(),sprintf("Nguyệt Nhi:\n Nguyên liệu của ngươi không đủ nâng cấp! Nâng cấp %s cần các loại nguyên liệu:\n "+cTmp+", 200 đá thần, 200 bánh ngọt.\n"ESC"Rời khỏi",cFile->get_name()));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"Bánh Ngọt",200);
		TASK_LEGEND_D->check_task_item1(who,"Đá Thần",200);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(2);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"Chúc mừng bạn nâng cấp thành công "HIR+item->get_name());
			break;
		
		/* Kết Thúc Nâng Cấp Thú Cưỡi */
		
		/// Tách Đoạn Thạch
		case 5:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ta sẽ giúp ngươi tách Đoạn Thạch cấp cao thành cấp thấp nếu ngươi cảm thấy có quá nhiều Đoạn Thạch cấp cao. (Lưu ý Cao Cấp kể cả khóa hay không khi tách ra cũng sẽ là khóa hết) ! Nào ngươi muốn tham gia chức năng này không ? \n"
				ESC "Tách Cao Cấp Thành 2 Trung Cấp\ntalk %x# gift.51\n"
				ESC "Tách Trung Cấp Thành 2 Sơ Cấp\ntalk %x# gift.52\n"
				ESC "Rời khỏi",get_name(),id,id,id));
				break;
		/// Xuất ra Tách Đoạn Thạch
		case 51:
		case 52: 		
				if ( flag==51 ){ben123=1;nhat123="Cao Cấp Đoạn Thạch";nhat1234="item/dtkhoa/1032";}
				else if ( flag==52 ){ben123=1;nhat123="Trung Cấp Đoạn Thạch";nhat1234="item/dtkhoa/0032";}
				if( USER_INVENTORY_D->get_free_count(who) < 2 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(), "Nguyệt Nhi: \nHành trang của ngươi không đủ 2 ô trống, hãy thu xếp hành trang rồi đến gặp ta ! \n"ESC"Xác nhận");
					return;
				}
				if ( TASK_LEGEND_D->check_task_item_amount(who,nhat123) < ben123 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(), "Nguyệt Nhi: \nNgươi không có đủ "+nhat123+"  ! \n"ESC"Xác nhận");
					return;
				}
				TASK_LEGEND_D->check_task_item1(who,nhat123,ben123); 
				item=new(nhat1234);
				p=item->move2(who,-1);
				item->add_to_user(p);
		
				item2=new(nhat1234);
				s=item2->move2(who,-1);
				item2->add_to_user(s);
				send_user(who,"%c%c%w%s",':',3,get_char_picid(), "Nguyệt Nhi: \nNgươi đã Tách thành công! Chúc mừng!\n"ESC"Xác nhận");
				break;
				
				/* Menu Ghép vật phẩm */
		/// Lựa chọn menu
		case 6:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Rèn luyện, ghép phẩm ta đều biết làm cả! Nhưng có điều sẽ có tỉ lệ hên xui được hay không? Ngươi muốn nhờ ta ghép thứ gì thế?\n"
				ESC "Ghép Bảo Để Phù\ntalk %x# gift.61\n"
				ESC "Ghép Đoạn Thạch\ntalk %x# gift.62\n"
				ESC "Ghép Ngọc Bội Tín Vật\ntalk %x# gift.63\n"
		//		ESC "Ghép Đoạn Thạch\ntalk %x# gift.62\n"
				ESC "Rời khỏi",get_name(),id,id,id,id,id));
				break;
				/// Ghép Bảo Để Phù
		case 61:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"MG Bảo Để Phù") < 50 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nVậy là ngươi không có 50 MG Bảo Để Phù? Vậy đến đây làm gì vậy !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}
				if (who->get_cash() < 100000 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Ngươi không đủ 100.000 ngân lượng! \n"ESC"Xác Nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}		
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"MG Bảo Để Phù",50);	
				if ( random100() < 80 )
					item=new("item/sell/0034");
				else
					notify("Ghép thất bại, xin chia buồn cùng các hạ!");
				if ( item ) 
				{
					who->add_cash(-100000);
					p=item->move2(who,-1);
					item->add_to_user(p);
					send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
					CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR" đã đổi thành công "HIY"%s"NOR "!",item->get_name()));
				}
				break;
				/* Ghép Đoạn Thạch */
				/// Lựa chọn ghép
		case 62:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Nghe đồn rằng, Chiến Quốc Tâm Diện khi kết thúc hè đã cho rớt một đống Mảnh Đoạn Thạch lải rải khắp nơi. Phải chăng các hạ đã tìm ra nó? Ta sẽ giúp các hạ tổng hợp lại thành một đoạn thạch tùy thích nha!! \n"
				ESC "Chức năng này là sao?\ntalk %x# gift.620\n"
				ESC "Ghép Sơ Cấp Đoạn Thạch\ntalk %x# gift.621\n"
				ESC "Ghép Trung Cấp Đoạn Thạch\ntalk %x# gift.623\n"
				ESC "Ghép Cao Cấp Đoạn Thạch\ntalk %x# gift.624\n"
				ESC "Rời khỏi",get_name(),id,id,id,id,id));
				break;
		/// Giới Thiệu
		case 620:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Khi có đủ số lượng Mảnh Ghép Đoạn Thạch, các bạn có thể đổi được Đoạn Thạch tùy thích. \nTuy nhiên mỗi đoạn thạch có tỉ lệ đổi khác nhau: Sơ Cấp cần 10 mảnh ghép có tỉ lệ đổi thành công 80%, Trung Cấp cần 15 mảnh ghép có tỉ lệ đổi thành công 60% và Cao Cấp cần 25 mảnh ghép có tỉ lệ đổi thành công 50%. Ngoài ra còn tiêu hao 100.000 ngân lượng một lần đổi (Tăng lên 20.000 ngân lượng tùy cấp đoạn thạch)!\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				break;
		/// Ghép Sơ Cấp
		case 621: 
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Đoạn Thạch") < 5 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nVậy là ngươi không có 5 Mảnh Ghép Đoạn Thạch? Vậy đến đây làm gì vậy !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}
				if (who->get_cash() < 100000 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Ngươi không đủ 100.000 ngân lượng! \n"ESC"Xác Nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}		
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Đoạn Thạch",5);
				if ( random100() <= 80 )
					item=new("item/sell/0032");
				else
					notify("Ghép thất bại, xin chia buồn cùng các hạ!");
				if ( item ) 
				{
					who->add_cash(-100000);
					p=item->move2(who,-1);
					item->add_to_user(p);
					send_user(who,"%c%s",';',"Bạn đã thành công ghép được "+item->get_name()+", xin chúc mừng !");
					CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR" đã ghép thành công "HIY"%s"NOR "!",item->get_name()));
				}
				break;
		/// Ghép Trung Cấp 
		case 622: 
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Đoạn Thạch") < 15 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nVậy là ngươi không có 15 Mảnh Ghép Đoạn Thạch? Vậy đến đây làm gì vậy !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}
				if (who->get_cash() < 120000 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Ngươi không đủ 120.000 ngân lượng! \n"ESC"Xác Nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}		
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Đoạn Thạch",15);	
				if ( random100() <= 60 )
					item=new("item/sell/0032");
				else
					notify("Ghép thất bại, xin chia buồn cùng các hạ!");
				if ( item ) 
				{
					who->add_cash(-120000);
					p=item->move2(who,-1);
					item->add_to_user(p);
					send_user(who,"%c%s",';',"Bạn đã thành công ghép được "+item->get_name()+", xin chúc mừng !");
					CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR" đã ghép thành công "HIY"%s"NOR "!",item->get_name()));
				}
				break;
		/// Ghép Cao Cấp 
		case 623:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Đoạn Thạch") < 25 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nVậy là ngươi không có 25 Mảnh Ghép Đoạn Thạch? Vậy đến đây làm gì vậy !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}
				if (who->get_cash() < 140000 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\n Ngươi không đủ 140.000 ngân lượng! \n"ESC"Xác Nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}		
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Đoạn Thạch",25);	
				if ( random100() <= 50 )
					item=new("item/sell/0032");
				else
					notify("Ghép thất bại, xin chia buồn cùng các hạ!");
				if ( item ) 
				{
					who->add_cash(-140000);
					p=item->move2(who,-1);
					item->add_to_user(p);
					send_user(who,"%c%s",';',"Bạn đã thành công ghép được "+item->get_name()+", xin chúc mừng !");
					CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR" đã ghép thành công "HIY"%s"NOR "!",item->get_name()));
				}
				break;
			/* Kết thúc ghép đoạn thạch */
			/// Ghép Ngọc Bội TÍn Vật
		case 63: 
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn hợp thành vật phẩm nào?? \n"
					ESC HIY"[Phượng Hoàng Ngọc Bội]\ntalk %x# gift.630\n"
				/*	ESC HIY"[Phượng Vũ Ngọc Bội]\ntalk %x# gift.631\n"
					ESC HIY"[Chu Tước Ngọc Bội]\ntalk %x# gift.632\n"
					ESC HIY"[Uyên Ương Ngọc Bội]\ntalk %x# gift.633\n"
					ESC HIY"[Bạch Hổ Ngọc Bội]\ntalk %x# gift.634\n"
					ESC HIY"[Thiên Ân Ngọc Bội]\ntalk %x# gift.635\n"
					ESC HIY"[Âm Dương Ngọc Bội]\ntalk %x# gift.636\n"
					ESC HIY"[Song Phụng Ngọc Bội]\ntalk %x# gift.637\n" */
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id,id));
			break;
		case 630:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Mảnh Ghép Phượng Hoàng") < 50 )
				{
					write_user(who, ECHO "Ngươi không có đủ 50 Mảnh Ghép Phượng Hoàng !");
					return ;
				}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
					notify( "Hành trang không đủ 1 chỗ trống" );
			return ;
			}		
				TASK_LEGEND_D->check_task_item1(who,"Mảnh Ghép Phượng Hoàng",50);
			if ( random(100) < 10 )		
			{
			item1 = new("/item/01/0008");
			if ( !item1 )
				return 0;
			}
			else if ( random(100) < 12 )	
			{
				tien = 12500;
			}
			else if ( random(100) < 36 )	
			{
				tien = 16200;
			}
			else if ( random(100) < 48 )	
			{
				tien = 11230;
			}
			else if ( random(100) < 54 )
			{
				tien = 12200;
			}
			else if ( random(100) < 72 )
			{
				tien = 11200;
			}
			else if ( random(100) < 84 )
			{
				tien = 11000;
			}
			else if ( random(100) < 93 )
			{
				tien = 10000;
			}
			else 			
			{
				tien = 10000;
			}
			//item2->add_amount(-20);
			 if ( tien ) 
			 {
		   who->add_cash(tien);
		   send_user(who,"%c%s",'!',"Hợp thành thất bại !!!");
			 }
			else if ( item1 )
			 {
			cTmp = sprintf(HIY "Chúc mừng bằng hữu "HIG"%s "HIY" đã Hợp Thành \"thành công\"...Nhận được "HIG"%s"HIY"！！！", who->get_name(), item1->get_name() );
			l = item1->move2(who,-1);
			item1->add_to_user(l);
			send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
			send_user(who,"%c%s",';',HIY"Hợp thành thành công !!!");	
			  }
			  return 0;
			  break;	
		case 631:
		case 632:
		case 633:
		case 634:
		case 635:
		case 636:
		case 637:
			/* Kết Thúc Menu Ghép */
			
			/// Nhận túi quà may mắn
		case 8:
				if ( who->get_level() < 55 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nNgươi chưa đạt cấp 55, không thể nhận Túi Quà May Mắn !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
			return;
			}
			if ( mxTime[TIME_WDAY] != 6 &&mxTime[TIME_WDAY] != 0 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nChỉ có thể nhận Túi Quà May Mắn vào thứ bảy và chủ nhật !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
			return;
			}
			if ( (mxTime[TIME_WDAY] == 6||mxTime[TIME_WDAY] == 0) && (mxTime[TIME_HOUR] < 10 || mxTime[TIME_HOUR] >= 22) )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nThời gian có thể nhận Túi Quà May Mắn chưa tới !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
			return;
			}
			if ( who->get_save("pblx")>0 )
			{
				if ( who->get_save("pblx")>=3600 )
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("Sứ Giả Phát Thưởng :\nMuốn nhận Túi Quà May Mắn phải chờ thêm %d giờ %d phút nữa !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save("pblx")/3600,(who->get_save("pblx")-3600)/60));
				else if ( who->get_save("pblx")>=60 )
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("Sứ Giả Phát Thưởng :\nMuốn nhận Túi Quà May Mắn phải chờ thêm %d phút nữa !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save("pblx")/60));
				else if ( who->get_save("pblx")<60 )
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("Sứ Giả Phát Thưởng :\nMuốn nhận Túi Quà May Mắn phải chờ thêm %d giây nữa !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi",who->get_save("pblx")));	
			return;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}	
			who->set_save("pblx2",1);
			who->set_save("pblx",5400);
			item = new("/item/event/phongbaolixi");
			p = item->move2(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nNgươi đã nhận thành công 1 Túi Quà May Mắn !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			break;	
			/* Menu Event */
			/// Menu Event 
		case 9: 
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Trong thế giới Chiến Quốc, có khá nhiều hoạt động hay, ngươi muốn tham gia hoạt động nào trong số đó ?\n"
				ESC "Tham gia Con số may mắn\ntalk %x# gift.90\n"
			//	ESC "Cánh Nữ\ntalk %x# gift.91\n"
				ESC "Rời khỏi",get_name(),id,id,id,id,id));
				break;
			/// Con Số May Mắn
		case 90:
				if ( who->get_save("csmm1")>0 && who->get_save("csmm2")>0 )
				{
				if ( !is_god(who) )
				{	
					if ( random(1000) < 1 ) ben = 1;
					else ben = random(1000);
				}
				else ben = who->get_save("csmm1")+10;	
				if ( abs(who->get_save("csmm1")-ben)<11 ) { tet1 = 1; tet3 = who->get_save("csmmm")*10; }
				if ( abs(who->get_save("csmm2")-ben)<11 ) { tet2 = 1; tet4 = who->get_save("csmmm")*10; }
				if ( tet1 ==1 && tet2==1 )
				{
				who->add_cash(tet3);
				who->add_cash(tet4);
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi đã trúng cả 2 số !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng cả 2 con số, xin chúc mừng !");
				return ;
				}
				else if ( tet1 ==1 )
				{
				who->add_cash(tet3);
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi đã trúng con số thứ 1 !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");	
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng được con số đầu tiên, xin chúc mừng !");
				return ;
				}
				else if ( tet2 ==1 )
				{
				who->add_cash(tet4);
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi đã trúng con số thứ 2 !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" tham gia Con số may mắn đã trúng được con số thứ hai, xin chúc mừng !");
				return ;
				}
				who->delete_save("csmm1");
				who->delete_save("csmm2");
				who->delete_save("csmmm");
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nCon số may mắn là "+ben+", ngươi không trúng số nào !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				if ( who->get_save("csmmm")<1 )
				send_user( who, "%c%c%d%s", '?', 16, 10, "Xin nhập số tiền muốn tham   gia trò chơi con số may mắn:\n" ESC "csmm ? %s\n" );
				else if ( who->get_save("csmm1")<1 )
				send_user( who, "%c%c%d%s", '?', 16, 3, "Bạn đặt "+who->get_save("csmmm")+" lượng \nXin nhập con số may mắn:\n" ESC "csmm a "+who->get_save("csmmm")+" %s\n" );
				else if ( who->get_save("csmm2")<1 )
				send_user( who, "%c%c%d%s", '?', 16, 3, "Bạn đặt "+who->get_save("csmmm")+" lượng \nCon số đầu tiên : "+who->get_save("csmm1")+"\nXin nhập con số may mắn:\n" ESC "csmm b "+who->get_save("csmmm")+" "+who->get_save("csmm1")+" %s\n" );
				break;
				
				/* Menu đổi vật phẩm event */
			/// Menu Đổi Vật Phẩm Hoạt Động
		case 10:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ta nghe nói ngươi muốn đổi thưởng sao? Ở đây có rất nhiều quà cho ngươi lựa chọn, vậy sự kiện nhận quà ngươi muốn là sự kiện nào ?\n"
				ESC "Đổi thưởng Tích luỹ Cứu thế\ntalk %x# gift.100\n"
				ESC "Đổi gói quà Quốc Tế Phụ Nữ\ntalk %x# gift.101\n"
				ESC "Đổi Phi Phong bằng Dầu Ăn\ntalk %x# gift.102\n"
				ESC "Đổi Cánh bằng Dép Lào\ntalk %x# gift.103\n"
				ESC "Đổi Chiến Y hoặc Chiến Mão\ntalk %x# gift.104\n"
				ESC "Đổi Cờ Tướng\ntalk %x# gift.105\n"
				ESC "Đổi Ác Quỷ(vương)\ntalk %x# gift.106\n"
				ESC "Rời khỏi",get_name(),id,id,id,id,id,id,id));
				break;
				/// Đổi thưởng Tích Lũy Cứu Thế
		case 100:
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s: \nĐiểm tích luỹ Cứu Thế của bạn hiện tại là %d điểm. \nBạn muốn nhận phần thưởng nào? Xin hãy lựa chọn : \n"
				ESC"20 điểm tích lấy Túi Hoàng Kim ( tỷ lệ đổi thành công là 10%% )\ntalk %x# gift.1000\n"
				ESC"15 điểm tích lấy Túi Kim Bảo ( tỷ lệ đổi thành công là 20%% )\ntalk %x# gift.1001\n"
				ESC"10 điểm tích lấy Túi Ngân Lượng ( tỷ lệ đổi thành công là 20%% )\ntalk %x# gift.1002\n"
				ESC"Rời khỏi",me->get_name(),who->get_save("diemcuudoi"),id,id,id,id,id));
				break;
		case 1000:
		case 1001:
		case 1002:
			if ( flag==1000 ) {bennhat="item/event/tuihoangkim";bennhat2=20;bn2=10;}
			else if ( flag==1001 ) {bennhat="item/event/tuikimbao";bennhat2=15;bn2=20;}
			else if ( flag==1002 ) {bennhat="item/event/tuinganluong";bennhat2=10;bn2=20;}
			if ( who->get_save("diemcuudoi") < bennhat2 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nNgươi không có đủ "+bennhat2+" điểm tích luỹ Cứu Thế !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Phát Thưởng :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
			return ;
			}
			who->add_save("diemcuudoi",-bennhat2);
			if ( random100() < bn2 )
				item=new(bennhat);
			else
				notify("Đổi thất bại !");
			if ( item ) 
			{
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
			}
			break;
			/// Gói Quà Quốc Tế Phụ Nữ
		case 101:	
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s :\n Ngươi muốn gói quà thường hay quà đặc biệt ? \n"
				ESC"Gói quà thường \ntalk %x# gift.1011\n"
				ESC"Gói quà đặc biệt \ntalk %x# gift.1012\n"
				ESC"Rời khỏi",me->get_name(),id,id));
				break;	
		case 1011:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Quà") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Giấy Gói Quà") < 1 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Năm Mới :\nNgươi không có 1 giấy Gói quà và hộp quà !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}			
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Năm Mới :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"Quà",1);
				TASK_LEGEND_D->check_task_item1(who,"Giấy Gói Quà",1);
				item=new("item/event/quanho");
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
				break;
		case 1012:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Quà ") < 1 || TASK_LEGEND_D->check_task_item_amount(who,"Giấy Gói Quà") < 1 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Năm Mới :\nNgươi không có 1 giấy Gói quà và hộp quà hoàng kim !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}			
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Sứ Giả Năm Mới :\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"Quà ",1);
				TASK_LEGEND_D->check_task_item1(who,"Giấy Gói Quà",1);
				item=new("item/event/quato");
				p=item->move2(who,-1);
				item->add_to_user(p);
				send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
				break;
				/// Phi Phong = Dầu Ăn 
		case 102:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(me->get_name()+": \nNgươi muốn đổi Phi Phong nào bằng cái Dầu Ăn này?\n"
				ESC"Ta muốn đổi lấy Vương Giả Phi Phong\ntalk %x# gift.1020\n"
				ESC"Ta muốn đổi lấy Xí Nhiệt Phi Phong\ntalk %x# gift.1021\n"
				ESC"Rời khỏi",id,id,id,id));
				break; 
		case 1020:	
		case 1021:		
				if ( flag==1020 ) bn="item/30/3020";
				else if ( flag==1021 ) bn="item/30/3021";
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Dầu Ăn") < 300 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nVậy là ngươi không có 300 Dầu Ăn? Vậy thì đừng đến đây !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}			
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"Dầu Ăn",300);	
				if ( random100() < 30 )
					item=new(bn);
				else
					notify("Đổi thất bại, xin chia buồn!");
				if ( item ) 
				{
					p=item->move2(who,-1);
					item->add_to_user(p);
					send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
					CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR"đã đổi thành công "HIY"%s"NOR "!",item->get_name()));
				}
				break;
				/// Cánh = Dép Lào
		case 103:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(me->get_name()+": \nNgươi muốn đổi loại Cánh nào bằng cái Dép Lào này?\n"
				ESC"Ta muốn đổi lấy Thánh Linh Chi Dực Vàng Nhạt\ntalk %x# gift.1030\n"
				ESC"Ta muốn đổi lấy Thánh Linh Chi Dực Trắng Thuần\ntalk %x# gift.1031\n"
				ESC"Rời khỏi",id,id,id,id));
				break; 
		case 1030:	
		case 1031:		
				if ( flag==1030 ) bn="item/30/3031";
				else if ( flag==1031 ) bn="item/30/3028";
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Dép Lào") < 300 )
				{
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nVậy là ngươi không có 300 Dép Lào? Vậy thì đừng đến đây !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
					return ;
				}			
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),"Nguyệt Nhi:\nHành trang của ngươi không đủ 1 ô trống !\n"ESC"Xác nhận \nCLOSE\n"ESC"Rời khỏi");
				return ;
				}
				TASK_LEGEND_D->check_task_item1(who,"Dép Lào",300);	
				if ( random100() < 30 )
					item=new(bn);
				else
					notify("Đổi thất bại, xin chia buồn!");
				if ( item ) 
				{
					p=item->move2(who,-1);
					item->add_to_user(p);
					send_user(who,"%c%s",';',"Bạn đã thành công đổi được "+item->get_name()+", xin chúc mừng !");
					CHAT_D->vip_channel( 0, sprintf("Chúc mừng "HIR""+who->get_name()+" "NOR"đã đổi thành công "HIY"%s"NOR "!",item->get_name()));
				}
				break;
				/// Menu Chiến Y hoặc Chiến Mão
		case 104:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" Nguyệt Nhi :\n Ngày xưa có một tướng quân vĩ đại trên thiên đình vì phạm tội tế nhị như nhìn gái nên quần áo bị ném xuống dưới đây.\n Nếu các ngươi có thể tìm lại 20 Chiến Y và 30 Chiến Mão do ngọc hoàng ném xuống đây thì chắc chắn ta sẽ ban tặng phần thưởng không nhỏ.\n"
				ESC"Ta muốn đổi Chiến Y lấy quà\ntalk %x# gift.1040\n"
				ESC"Ta muốn đổi Chiến Mão lấy quà\ntalk %x# gift.1041\n"
				ESC"Rời khỏi",id,id,id,id));
				break; 
		case 1040:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Chiến Y") < 20 )
				{
					notify( "Ngươi không có 20 Chiến Y" );
					return ;	
				}
				TASK_LEGEND_D->check_task_item1(who,"Chiến Y",20);	
				item = new(sprintf("/item/cycm/Ghep/ChienY/%d", 1001+random(7)));
				i = item->move(who,-1);
				item->add_to_user(i);
					USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" dùng 20 Chiến Y trao cho Thiên Sơn Tướng Quân nhận được phần thưởng: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
				send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
				break;
		case 1041:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Chiến Mão") < 30 )
				{
					notify( "Ngươi không có 30 Chiến Mão" );
					return ;	
				}
				TASK_LEGEND_D->check_task_item1(who,"Chiến Mão",30);	
				item = new(sprintf("/item/cycm/Ghep/ChienMao/%d", 1001+random(7)));
				i = item->move(who,-1);
				item->add_to_user(i);
					USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" dùng 40 Chiến Mão trao cho Thiên Sơn Tướng Quân nhận được phần thưởng: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
				send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
				break;
				/// Đổi cờ tướng
		case 105:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Cờ Tướng") < 30 )
				{
					notify( "Ngươi không có 30 Cờ Tướng" );
					return ;	
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				TASK_LEGEND_D->check_task_item1(who,"Cờ Tướng",30);	
				if ( rate < 10 )		
				{
					item = new("/item/sell/1032");
					if ( !item )
						return 0;
				}
				else if ( rate < 15 )		
				{
					item = new("/item/sell/0032");
					if ( !item )
						return 0;
				}
				else if ( rate < 25 )	
				{
					item = new(sprintf("/item/event/cotuong/%d",gioitinh));
					if ( !item )
						return 0;
				}
				else if ( rate < 32 )	
				{
					item = new(sprintf("/item/event/cotuong/%d",gioitinh));
					if ( !item )
						return 0;
				}
				else if ( rate < 35 )	
				{
					item = new("item/bikipknb/knb4");
					if ( !item )
						return 0;
				}
				else if ( rate < 45 )	
				{
					item = new("item/manhghep/mgphnb");
					if ( !item )
						return 0;
				}
				else if ( rate < 40 )	
				{
					item = new(sprintf("/item/100/%d051",gioitinh));
					if ( !item )
						return 0;
				}
				else if ( rate < 50 )	
				{
					item = new("/item/exp/tinhdonexp2");
					if ( !item )
						return 0;
				}
				else if ( rate < 65 )	
				{
					item = new("item/manhghep/mgphnb");
					if ( !item )
						return 0;
				}
				else if ( rate < 60 )	
				{
					item = new("/item/sell/0002");
					if ( !item )
						return 0;
				}
				else if ( rate < 75 )	
				{
					item = new("/item/exp/tinhdonexp");
					if ( !item )
						return 0;
				}
				else if ( rate < 70 )	
				{
					item = new(sprintf("/item/100/%d053",gioitinh));
					if ( !item )
						return 0;
				}
				else if ( rate < 80 )
				{
					item = new("/item/sell/0004");
					if ( !item )
						return 0;
				}
				else 			
				{
					item = new(sprintf("/item/100/%d055",gioitinh));
					if ( !item )
						return 0;
				}
				if ( item )
				{
					l = item->move2(who,-1);
					item->add_to_user(l);
					send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
					USER_D->user_channel(sprintf("Bằng hữu "HIG "%s "NOR " vừa đổi Cờ Tướng nhận được: " HIC"%s " HIG " .", who->get_name(),item->get_name() ));
				}
				return 0;
				break;
			/// Đổi Ác Quỷ vương
		case 106:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Ác Quỷ(vương)") < 10 )
				{
					notify( "Ngươi không có 10 Ác Quỷ(vương)" );
					return ;	
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				TASK_LEGEND_D->check_task_item1(who,"Ác Quỷ(vương)",10);
				if ( random100() < 20 )
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
				}
			
				break;
				/* Kết thúc menu đổi event */
				
				/// Đổi cầu
		case 11:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi muốn dùng loại Cầu nào để đổi thưởng ?? Nếu có 4 Loại thì càng tốt !!! \n"
				ESC HIY"[Dùng Hắc Cầu đổi thưởng]\ntalk %x# gift.110\n"
				ESC HIY"[Dùng Lam Cầu đổi thưởng]\ntalk %x# gift.111\n"
				ESC HIY"[Dùng Hồng Cầu đổi thưởng]\ntalk %x# gift.112\n"
				ESC HIY"[Dùng Hoa Cầu đổi thưởng]\ntalk %x# gift.113\n"
				ESC HIY"[Dùng Hắc + Lam + Hồng + Hoa Cầu đổi thưởng]\ntalk %x# gift.114\n"
				ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id,id,id));
				break;
				/// Hắc Cầu
		case 110:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Hắc Cầu") < 1 )
					{
						notify( "Ngươi không có Hắc Cầu" );
						return ;	
					}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				TASK_LEGEND_D->check_task_item1(who,"Hắc Cầu",1);	
			/*	if ( rate < 20 )		
				{
					item = new("/item/test2/TuiQuaVoSong");
					if ( !item )
						return 0;
				}
				else */if ( rate < 45 )	
				{
					item = new("/item/test2/tuithucuoi");
					if ( !item )
						return 0;
				}
				else if ( rate < 60 )	
				{
					knb = 10;
				}
				else if ( rate < 90 )
				{
					tien = 20000;
				}
				else 			
				{
					tien = 10000;
				}
				if ( tien ) 
				{
					who->add_cash(tien);
					send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d ngân lượng",tien));
				}
				else if ( item )
				{
					l = item->move2(who,-1);
					item->add_to_user(l);
					send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				}
				else if ( knb )
				{
					"sys/sys/test_db"->add_yuanbao(who,knb);
					send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d Ngân Bảo",knb));				
				}
				return 0;
				break;
				/// Lam Cầu
		case 111:
				if ( TASK_LEGEND_D->check_task_item_amount(who,"Lam Cầu") < 1 )
					{
						notify( "Ngươi không có Lam Cầu" );
						return ;	
					}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
					TASK_LEGEND_D->check_task_item1(who,"Lam Cầu",1);	
		/*	if ( rate < 20 )		
			{
				item = new("/item/test2/TuiQuaVoSong");
			//	item->set_amount(2);
				if ( !item )
					return 0;
			}
			else */if ( rate < 45 )	
			{
				item = new("/item/test2/tuithucuoi");
				if ( !item )
					return 0;
			}
			else if ( rate < 60 )	
			{
				knb = 20;
			}
			else if ( rate < 90 )
			{
				tien = 40000;
			}
			else 			
			{
				tien = 20000;
			}
			if ( tien ) 
			{
				who->add_cash(tien);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d ngân lượng",tien));
			}
			else if ( item )
			{
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
			}
			else if ( knb )
			{
				"sys/sys/test_db"->add_yuanbao(who,knb);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d Ngân Bảo",knb));
			}
				return 0;
				break;
				/// Hồng Cầu 
	case 112:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Hồng Cầu") < 1 )
			{
				notify( "Ngươi không có Hồng Cầu" );
				return ;	
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
					notify( "Hành trang không đủ 1 chỗ trống" );
			return ;
			}	
			TASK_LEGEND_D->check_task_item1(who,"Hồng Cầu",1);	
		/*	if ( rate < 15 )		
			{
				item = new("/item/test2/TuiQuaVoSong");
			//	item->set_amount(2);
				if ( !item )
					return 0;
			}
			else */if ( rate < 35 )	
			{
				item = new("/item/test2/tuithucuoi");
				item->set_amount(2);
				if ( !item )
					return 0;
			}
			else if ( rate < 45 )	
			{
				knb = 20;
			}
			else if ( rate < 66 )	
			{
				item = new("/item/08/0016");
				item->set_amount(3);
				if ( !item )
					return 0;
			}
			else if ( rate < 75 )	
			{
				item = new("/item/08/0017");
				item->set_amount(3);
				if ( !item )
					return 0;
			}
			else if ( rate < 90 )
			{
				tien = 60000;
			}
			else 			
			{
				tien = 30000;
			}
			if ( tien ) 
			{
				who->add_cash(tien);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d ngân lượng",tien));				
			}
			else if ( item )
			{
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());				
			}
			else if ( knb )
			{
				"sys/sys/test_db"->add_yuanbao(who,knb);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d Ngân Bảo",knb));	
			}
			return 0;
			break;
			/// Hoa Cầu 
	case 113:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Hoa Cầu") < 1 )
			{
				notify( "Ngươi không có Hoa Cầu" );
				return ;	
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
					notify( "Hành trang không đủ 1 chỗ trống" );
			return ;
			}	
			TASK_LEGEND_D->check_task_item1(who,"Hoa Cầu",1);	
			if ( rate < 15 )		
			{
				item = new("/item/test2/TuiQuaVoSong");
			//	item->set_amount(2);
				if ( !item )
					return 0;
			}
			else if ( rate < 35 )	
			{
				item = new("/item/test2/tuithucuoi");
				item->set_amount(3);
				if ( !item )
					return 0;
			}
			else if ( rate < 45 )	
			{
				knb = 30;
			}
			else if ( rate < 66 )	
			{
				item = new("/item/08/0016");
				item->set_amount(5);
				if ( !item )
					return 0;
			}
			else if ( rate < 75 )	
			{
				item = new("/item/08/0017");
				item->set_amount(5);
				if ( !item )
					return 0;
			}
			else if ( rate < 83 )	
			{
				item = new("/item/test2/tuitukim55");
				if ( !item )
					return 0;
			}
			else if ( rate < 93 )
			{
				tien = 80000;
			}
			else 			
			{
				tien = 40000;
			}
			if ( tien ) 
			{
				who->add_cash(tien);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d ngân lượng",tien));			
			}
			else if ( item )
			{
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());				
			}
			else if ( knb )
			{
				"sys/sys/test_db"->add_yuanbao(who,knb);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d Kim Nguyên Bảo",knb));
			}
			return 0;
			break;
			/// Cả 4 loại Cầu 
	case 114:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Hắc Cầu") < 1 ||
				 TASK_LEGEND_D->check_task_item_amount(who,"Lam Cầu") < 1 ||
				 TASK_LEGEND_D->check_task_item_amount(who,"Hồng Cầu") < 1 ||
				 TASK_LEGEND_D->check_task_item_amount(who,"Hoa Cầu") < 1 )
				 {
					notify( "Ngươi không đủ 4 loại Cầu" );
					return ;	
				 }
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
					notify( "Hành trang không đủ 1 chỗ trống" );
			return ;
			}	
			TASK_LEGEND_D->check_task_item1(who,"Hắc Cầu",1);	
			TASK_LEGEND_D->check_task_item1(who,"Lam Cầu",1);	
			TASK_LEGEND_D->check_task_item1(who,"Hồng Cầu",1);	
			TASK_LEGEND_D->check_task_item1(who,"Hoa Cầu",1);	
			if ( rate < 15 )		
			{
				item = new("/item/test2/TuiQuaVoSong");
				item->set_amount(2);
				if ( !item )
					return 0;
			}
			else if ( rate < 25 )	
			{
				item = new("/item/test2/TuiPhapBao");
				if ( !item )
					return 0;
			}
			else if ( rate < 30 )	
			{
				item = new("/item/test2/tuithucuoi");
				item->set_amount(5);
				if ( !item )
					return 0;
			}
			else if ( rate < 35 )	
			{
				knb = 50;
			}
			else if ( rate < 55 )	
			{
				item = new("/item/08/0016");
				item->set_amount(10);
				if ( !item )
					return 0;
			}
			else if ( rate < 65 )	
			{
				item = new("/item/08/0017");
				item->set_amount(10);
				if ( !item )
					return 0;
			}
			else if ( rate < 75 )	
			{
				item = new("/item/test2/tuitukim55");
				if ( !item )
					return 0;
			}
			else if ( rate < 85 )	
			{
				item = new("/item/test2/tuitukim85");
				if ( !item )
					return 0;
			}
			else if ( rate < 92 )
			{
				tien = 140000;
			}
			else 			
			{
				tien = 70000;
			}
			if ( tien ) 
			{
				who->add_cash(tien);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d ngân lượng",tien));
				USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi 4 loại Cầu nhận được:"HIY"%d "HIG "Ngân lượng .", who->get_name(),tien ));
			}
			else if ( item )
			{
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi 4 loại Cầu nhận được: " HIY"%s " HIG " .", who->get_name(),item->get_name() ));
			}
			else if ( knb )
			{
				"sys/sys/test_db"->add_yuanbao(who,knb);
				send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d Kim Nguyên Bảo",knb));
				USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi 4 loại Cầu nhận được:"HIY"%d "HIG "Kim Nguyên Bảo .", who->get_name(),knb ));
			}
			return 0;
			break;
				/// Phần Thưởng Nạp Thẻ
		case 12: 	
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi đã từng Nạp Thẻ ????\nSố điểm tích luỹ Nạp Thẻ của ngươi là "HIB"%d"NOR " . \nNgươi muốn đổi thưởng không ???? \n"
				ESC HIY"[Nhận Đá Tương Uyên] - 1 điểm\ntalk %x# gift.120\n"
				ESC HIY"[Nhận 10 Đá Tương Uyên] - 6 điểm\ntalk %x# gift.121\n"
				ESC HIY"[Nhận Đá Càn Khôn] - 1 điểm\ntalk %x# gift.122\n"
				ESC HIY"[Nhận 10 Đá Càn Khôn] - 6 điểm\ntalk %x# gift.123\n"
				ESC HIY"[Nhận Sơ Cấp Đoạn Thạch] - 6 điểm\ntalk %x# gift.124\n"
				ESC HIY"[Nhận Trung Cấp Đoạn Thạch] - 10 điểm\ntalk %x# gift.125\n"
				ESC HIY"[Nhận Cao Cấp Đoạn Thạch] - 18 điểm\ntalk %x# gift.126\n"
				ESC"Rời khỏi",get_name(),who->get_save("diemnapknb"),id,id,id,id,id,id,id,id,id));
				/* Chọn quà */
		case 120:	
				if ( who->get_save("diemnapknb") < 1 )
				{
					notify( "Không đủ 1 điểm Tích Luỹ" );
					return ;
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				who->add_save("diemnapknb",-1);	
				item = new("/item/08/0016");
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				break;
		case 121:	
				if ( who->get_save("diemnapknb") < 6 )
				{
					notify( "Không đủ 6 điểm Tích Luỹ" );
					return ;
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				who->add_save("diemnapknb",-6);	
				item = new("/item/08/0016");
				item->set_amount(10);
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				break;
		case 122:	
				if ( who->get_save("diemnapknb") < 1 )
				{
					notify( "Không đủ 1 điểm Tích Luỹ" );
					return ;
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				who->add_save("diemnapknb",-1);	
				item = new("/item/08/0017");
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				break;
		case 123:	
				if ( who->get_save("diemnapknb") < 6 )
				{
					notify( "Không đủ 6 điểm Tích Luỹ" );
					return ;
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				who->add_save("diemnapknb",-6);	
				item = new("/item/08/0017");
				item->set_amount(10);
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				break;
		case 124:	
				if ( who->get_save("diemnapknb") < 6 )
				{
					notify( "Không đủ 6 điểm Tích Luỹ" );
					return ;
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				who->add_save("diemnapknb",-6);	
				item = new("/item/sell/0032");
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				break;
		case 125:	
				if ( who->get_save("diemnapknb") < 10 )
				{
					notify( "Không đủ 10 điểm Tích Luỹ" );
					return ;
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				who->add_save("diemnapknb",-10);	
				item = new("/item/sell/1032");
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				break;
		case 126:	
				if ( who->get_save("diemnapknb") < 18 )
				{
					notify( "Không đủ 18 điểm Tích Luỹ" );
					return ;
				}
				if(USER_INVENTORY_D->get_free_count(who) < 1 )
				{
						notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
				}	
				who->add_save("diemnapknb",-18);	
				item = new("/item/sell/2032");
				l = item->move2(who,-1);
				item->add_to_user(l);
				send_user(who,"%c%s",'!',"Bạn nhận được "HIY+item->get_name());
				break;
			/* Kết thúc chọn quà */
				
				
		}
}
