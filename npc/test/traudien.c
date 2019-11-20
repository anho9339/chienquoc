#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>
#include <time.h>
inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 9956; }
void do_welcome(string arg);
void do_gift(string arg);
void do_giftben(string arg);
void do_accept(string arg);
int *nh = ({1,2,3,4,5});
int *nh2 = ({"Kim","Mộc","Thổ","Thuỷ","Hoả"});
void create()
{	  
        set_name("Ngũ Hành Đại Sư");
        set_real_name("Trâu Diễn");
		set_2( "talk", ([
                "welcome"	:( : do_welcome :),
                "gift"	:( : do_gift :),
                "giftben"	:( : do_giftben :),
				"giaotrangbi"         : (: do_accept :),
             ]));
        setup();

}
void do_gift(string arg)
{
	"/sys/user/songtu"->do_gift(this_object(),this_player(),arg);
}
void do_giftben(string arg)
{
	"/sys/party/tinhnhan"->do_giftben(this_object(),this_player(),arg);
}
void do_welcome( string arg )
{
	__FILE__->do_welcome2(this_object(),arg);
}
void do_welcome2( object npc, string arg )
{
	int flag,ben1,ben2,ben3,ben4,ben5,ben6,ben7;
	string ben,nhat,nhat1,nhat2,nhat3,nhat4,nhat5,nhat6,nhat7;
	object player  = this_player();
	flag = to_int(arg);
	switch(flag)
	{
		case 1:
	        send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),sprintf(npc->get_name() + ":\n"+"Sau khi rèn ngũ hành trang bị, trang bị của ngươi sẽ được kích hoạt ngẫu nhiên một ngũ hành tiềm ẩn. Thuộc tính ngũ hành của nhân vật sau khi đã được kích hoạt có thể gia tăng sức chiến đấu, tuy nhiên nếu gặp phải đối thủ có ngũ hành tương khắc thì ngươi sẽ rất vất vả. Ngươi muốn rèn ngũ hành cho trang bị không ?\n" 
	        ESC "ALT+G để giao trang bị\ntalk %x# welcome.2\n"
			ESC "Thoát ra\nCLOSE\n",getoid(npc),getoid(npc),getoid(npc))); 
		break;
		case 2:
	        send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),sprintf(npc->get_name() + ":\n"+"Sử dụng Alt+G để giao trang bị cho ta !\n" 
	        ESC "Ta hiểu rồi\nCLOSE\n"
			ESC "Thoát ra\nCLOSE\n",getoid(npc),getoid(npc),getoid(npc))); 
		break;
		case 3:
	        send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),sprintf(npc->get_name() + ":\n"+"Ngũ hành có đặc tính tương sinh/tương khắc : \n1.Tương sinh: gia tăng thêm 15%% sát thương khi mục tiêu khắc hệ với mình, riêng hệ Kim gia tăng thêm 20%% sát thương cùng 15%% chính xác khi mục tiêu khắc hệ với mình.\n2.Tương khắc: Giảm 10%% sát thương khi tấn công nếu mục tiêu kị hệ với mình, riêng hệ Kim sẽ giảm 15%% sát thương khi tấn công nếu mục tiêu kị hệ với mình.\n" 
	        ESC "Ta hiểu rồi\nCLOSE\n"
			ESC "Thoát ra\nCLOSE\n",getoid(npc),getoid(npc),getoid(npc))); 
		break;
		case 4:
			if (player->get_fam_name()=="") return;
		if (player->get_save("nguhanh")==1) { ben="Kim"; nhat1="Mộc";nhat2="Mộc";nhat3="Thuỷ";nhat4="Kim";nhat5="Hoả"; }
		else if (player->get_save("nguhanh")==2) { ben="Mộc"; nhat1="Thuỷ";nhat2="Thuỷ";nhat3="Hoả";nhat4="Kim";nhat5="Thổ"; }
		else if (player->get_save("nguhanh")==3) { ben="Thổ"; nhat1="Kim";nhat2="Mộc";nhat3="Thuỷ";nhat4="Kim";nhat5="Hoả"; }
		else if (player->get_save("nguhanh")==4) { ben="Thuỷ"; nhat1="Kim";nhat2="Hoả";nhat3="Hoả";nhat4="Thổ";nhat5="Mộc"; }
		else if (player->get_save("nguhanh")==5) { ben="Hoả"; nhat1="Thổ";nhat2="Kim";nhat3="Mộc";nhat4="Thuỷ";nhat5="Mộc"; }
	        send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),sprintf(npc->get_name() + ":\n"+"Ngũ hành của ngươi là "HIR+ben+". \nYêu cầu thuộc tính trang bị để kích hoạt Ngũ Hành: \n1.Y Phục:  "+nhat1+" \n2.Nón:  "+nhat2+" \n3.Hạng Liên:  "+nhat3+" \n4.Yêu Đới:  "+nhat4+" \n5.Giày:  "+nhat5+" \n\n" 
	        ESC "Ta hiểu rồi\nCLOSE\n"
			ESC "Thoát ra\nCLOSE\n")); 
		break;
		case 5:
			send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),sprintf(npc->get_name() + ":\n"+" Lợi ích của Song Tu hỗ trợ rất tốt cho người chơi, 2 người cùng ở trong 1 nhóm, sau khi Song Tu khi ngồi gần nhau sẽ nhận được điểm Kinh nghiệm theo cấp bậc, tuy nhiên Song Tu có hạn sử dụng, vì thế hãy trân trọng thời gian !\n" 
	        ESC "Ta muốn tham gia Song Tu\ntalk %x# gift.2\n"
	        ESC "Kiểm tra thời gian Song Tu\ntalk %x# gift.99\n"
	        ESC "Gia hạn thời gian Song Tu\ntalk %x# gift.100\n"
	        ESC "Kiểm tra người cùng Song Tu\ntalk %x# gift.101\n"
			ESC "Thoát ra\nCLOSE\n",getoid(npc),getoid(npc),getoid(npc),getoid(npc)));
		break;
	}
}
void do_look( object player )
{
	int iTime;
	object npc = this_object();
	send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf( "%s :\n"+"Ngũ hành với các quy luật tương sinh/tương khắc, biết phối hợp chúng sẽ mang tới nhiều điều thú vị. Ngươi có biết không ? Mỗi môn phái đều có riêng cho mình một ngũ hành mặc định, tuy nhiên ngũ hành được kích hoạt hay không còn phải dựa vào những trang bị khác!\n"
        ESC "Rèn trang bị ngũ hành\ntalk %x# welcome.1\n"
        ESC HIG"Đặc tính của ngũ hành\ntalk %x# welcome.3\n"
        ESC HIC"Các ngũ hành cần được kích hoạt\ntalk %x# welcome.4\n"
        ESC HIY"Tham gia chức năng Song Tu\ntalk %x# welcome.5\n"
    //    ESC "Tìm kiếm Pháp Bảo Tình Nhân\ntalk %x# giftben.3\n"
        ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc), getoid(npc), getoid(npc) ) );
}

// 函数:接受物品
int accept_object( object who, object item ){ return __FILE__ ->accept_object_callout( this_object(), who, item ); }

// 函数:接受物品(在线更新)
int accept_object_callout( object me, object who, object item )
{
    int level, p, i, t1, t2, t3, t4, mau, cap, cap1, cap2;
	object item2;
	string sao,ngoc;
        me->to_front_eachother(who);
	if( !item->is_equip() ) return 0;
	if( item->is_equip())
	{
		i=item->get_equip_type();
		if ( i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE) {
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Trâu Diễn:\nNgươi đưa cho ta trang bị không đúng !\n"ESC"Xác nhận\nCLOSE\n"ESC"Rời khỏi");
			return -99;
			}
	}
	sao = item->get("forge");
	cap = strlen(sao);
	ngoc = item->get("make");
	cap1 = strlen(ngoc);
	cap2 = item->get_level();
	mau = item->get_item_color();
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Trâu Diễn:\nRèn ngũ hành cho trang bị %s cần phải tiêu hao 50 vạn lượng và 20 Kim Nguyên Bảo, ngươi xác nhận phải rèn thuộc tính ngũ hành của %s không ?\n"ESC"Xác nhận\ntalk %x# giaotrangbi.%x#\n"ESC"Huỷ bỏ",item->get_name(),item->get_name(),getoid(me),getoid(item)));
	
	return -99;
}
// Bla bla
void do_accept( string arg ){ return __FILE__ ->do_accept_callout( this_object(), this_player(), arg ); }

// Bla bla
void do_accept_callout(object me, object who, string arg )
{
	int level, p, i, t1, t2, t3, t4, mau, cap, cap1, cap2, y, ben;
	object item;
	string sao,ngoc,nhat,ben1;
	
	if( !objectp( item = present( arg, who, 1, MAX_CARRY*4 ) ) )
		return 0;
	if( !item->is_equip() ) return 0;
	if( item->is_equip())
	{
		i=item->get_equip_type();
		if ( i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE) {
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Trâu Diễn:\nNgươi đưa cho ta trang bị không đúng !\n"ESC"Xác nhận\nCLOSE\n"ESC"Rời khỏi");
			return 0;
			}
	}
	sao = item->get("forge");
	cap = strlen(sao);
	ngoc = item->get("make");
	cap1 = strlen(ngoc);
	cap2 = item->get_level();
	mau = item->get_item_color();
	if ( cap2 < 40 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Trâu Diễn:\nTrang bị "+item->get_name()+" chưa đạt 40 cấp, không thể rèn thuộc tính ngũ hành !\n"ESC"Ta biết rồi\nCLOSE\n"ESC"Rời khỏi");
		return 0;
	}
	if ( who->get_cash() < 500000 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Trâu Diễn:\nNgươi không có đủ 50 vạn lượng, không thể rèn thuộc tính ngũ hành cho trang bị "+item->get_name()+" được !\n"ESC"Ta biết rồi\nCLOSE\n"ESC"Rời khỏi");
		return 0;
	}
	if ( "sys/sys/test_db"->get_yuanbao(who) < 200 )
	{
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Trâu Diễn:\nNgươi không có đủ 20 Kim Nguyên Bảo, không thể rèn thuộc tính ngũ hành cho trang bị "+item->get_name()+" được !\n"ESC"Xác nhận\nCLOSE\n"ESC"Rời khỏi");
		return 0;
	}
	y = random(5);
	ben = nh[y];
	who->add_cash(-500000);
	"/sys/sys/test_db"->add_yuanbao(who,-200);
	item->set_nh(ben);
	item->add_to_user(get_d(item));
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Trâu Diễn:\nNgươi đã rèn thành công "HIB+item->get_name()+NOR " thuộc tính "HIR+nh2[y]+NOR ". Xin chúc mừng!\n"ESC"Xác nhận\nCLOSE\n"ESC"Rời khỏi");
	send_user(who,"%c%s",';', sprintf("Bạn nhận được "HIY"%s"NOR " thuộc tính "HIG"%s"NOR ", Xin chúc mừng !",item->get_name(),nh2[y]));
	return 0;
}