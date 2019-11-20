/*
Edit by Nguyễn Quang Hiếu
*/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>

inherit OFFICER;

// 函数:获取人物造型
int get_char_picid() { return 5101; }
int is_seller() { return 7006; }
int is_self_look() { return 1; }
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name("Tiên Đế Thánh Thượng");
		set_real_name(HIR "Chuyển Sinh");
        set_2( "good", ([
                "01" : "/item/test2/ChuyenSinh/phiphongthue",
				"02" : "/item/test2/ChuyenSinh/canhthue",
				"03" : "/item/test2/ChuyenSinh/phiphongthue2",
				"04" : "/item/test2/ChuyenSinh/canhthue2",
				"05" : "/item/test2/ChuyenSinh/phiphongthue3",
				"06" : "/item/test2/ChuyenSinh/canhthue3",	
        ]) );
		set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() ), knb, cap;
	if(who->get_save_2("diem.cs")==0) { knb = 400; cap = 150; }
	else if(who->get_save_2("diem.cs")==1) { knb = 400; cap = 150; }
	else if(who->get_save_2("diem.cs")==2) { knb = 400; cap = 150; }
	else if(who->get_save_2("diem.cs")==3) { knb = 400; cap = 150; }
	else if(who->get_save_2("diem.cs")==4) { knb = 400; cap = 150; }
	else if(who->get_save_2("diem.cs")==5) { knb = 400; cap = 150; }
	else if(who->get_save_2("diem.cs")==6) { knb = 600; cap = 150; }
	else if(who->get_save_2("diem.cs")==7) { knb = 600; cap = 150; }
	else if(who->get_save_2("diem.cs")==8) { knb = 600; cap = 150; }
	else if(who->get_save_2("diem.cs")==9) { knb = 600; cap = 150; }
	if ( who->get_save_2("diem.cs") < 1 )
	{
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
//		ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
	}
	else if ( who->get_save_2("diem.cs") == 1 )
	{
		if ( who->get_save("npccs1")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 1 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 1 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 1\ntalk %x# gift.7\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 2 )
	{
		if ( who->get_save("npccs2")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 2 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 2 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 2\ntalk %x# gift.7\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 3 )
	{
		if ( who->get_save("npccs3")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 3 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 3 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 3\ntalk %x# gift.7\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 4 )
	{
		if ( who->get_save("npccs4")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 4 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 4 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 4\ntalk %x# gift.7\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 5 )
	{
		if ( who->get_save("npccs5")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 5 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 5 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 5\ntalk %x# gift.7\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 6 )
	{
		if ( who->get_save("npccs6")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//  ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 6 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 6 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 6\ntalk %x# gift.7\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 7 )
	{
		if ( who->get_save("npccs7")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//	ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 7 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 7 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 7\ntalk %x# gift.7\n"
		//ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 8 )
	{
		if ( who->get_save("npccs8")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//  ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 8 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 8 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 8\ntalk %x# gift.7\n"
		//ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else if ( who->get_save_2("diem.cs") == 9 )
	{
		if ( who->get_save("npccs9")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi muốn Chuyển Sinh không ? \nSố lần Chuyển Sinh của ngươi là : "HIR "%d "NOR "Lần \nBây giờ Chuyển Sinh cần phải đạt tới cấp "HIB"%d "NOR " \nVà cần phải tiêu hao "HIB"%d "NOR "Kim Nguyên Bảo !\n"
		ESC HIY"Chuyển Sinh\ntalk %x# gift.2\n"
	//  ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save_2("diem.cs"),cap,knb,id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 9 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 9 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 9\ntalk %x# gift.7\n"
		//ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}
	else
	{
		if ( who->get_save("npccs10")>=1 ) {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh đến giới hạn, khi Sự kiện Chuyển Sinh Bá Vương bắt đầu mới có thể tiếp tục Chuyển Sinh !\n"
	//  ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
	//	ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi đã Chuyển Sinh 10 lần !!! \nNgươi muốn nhận thưởng Chuyển Sinh lần 10 không ?\n"
		ESC HIC"Nhận thưởng Chuyển Sinh lần 10\ntalk %x# gift.7\n"
		//ESC HIG"Thuê Phi Phong và Cánh với giá ưu đãi\nlist8 %x#\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		}
	}	
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p;
	object who,item;
	string *nTmp,cFile,cTmp;
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
       	case 1:
			break;
		case 2:
			if ( who->get_save_2("diem.cs")>=10 )
				{
        		send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã Chuyển Sinh tới giới hạn rồi !!!\n"ESC"Rời khỏi.");
        		return;
				}
			if(who->get_save_2("diem.cs")<1)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 1 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 4000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 400 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 1 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-4000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 1 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 1 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(1);
			return 0;
			}
			if(who->get_save_2("diem.cs")==1)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 2 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 4000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 400 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 2 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-4000);	
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 2 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 1 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(1);
			return 0;
			}
			if(who->get_save_2("diem.cs")==2)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 3 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 4000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 400 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 3 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-4000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 3 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 1 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(1);
			return 0;
			}
			if(who->get_save_2("diem.cs")==3)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 4 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 4000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 400 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 4 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-4000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 4 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 1 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(1);
			return 0;
			}
			if(who->get_save_2("diem.cs")==4)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 5 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 4000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 400 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 5 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-4000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 5 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 1 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(1);
			return 0;
			}
			if(who->get_save_2("diem.cs")==5)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 6 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 6000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 600 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 6 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-6000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 6 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 2 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(2);
			who->add_title("Y001");
			who->show_title("Y001");
			return 0;
			}
			if(who->get_save_2("diem.cs")==6)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 7 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 6000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 600 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 7 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-6000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 7 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 2 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(2);
			return 0;
			}
			if(who->get_save_2("diem.cs")==7)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 8 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 6000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 600 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 8 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-6000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 8 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 2 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(2);
			return 0;
			}
			if(who->get_save_2("diem.cs")==8)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 9 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 6000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 600 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 9 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-6000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 9 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 2 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(2);
			return 0;
			}
			if(who->get_save_2("diem.cs")==9)
			{	
				if ( who->get_level() < 150 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Cấp độ chưa đạt tới cấp 150, không thể Chuyển Sinh Lần 10 !!!\n"ESC"Rời khỏi.");
				return;
				}
				else if ( "sys/sys/test_db"->get_yuanbao(who) < 6000 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Không đủ 600 Kim Nguyên Bảo, không thể Chuyển Sinh Lần 10 !!!\n"ESC"Rời khỏi.");
				return;
				}
			"sys/sys/test_db"->add_yuanbao(who,-6000);
			who->add_save_2("diem.cs",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã Chuyển Sinh lần 10 !!!");
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Chuyển Sinh lần thứ "HIC " %d  "HIG " tăng 2 bậc sức mạnh. ", who->get_name(),who->get_save_2("diem.cs") ));
			cTmp = sprintf(HIY "Chúc mừng "HIG"%s "HIY" đã Chuyển Sinh lần thứ 10 !!!", who->get_name() );
			send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
			who->set_level(who->get_level()-140);
			who->count_gift();
			who->add_gift_point(2);
		/*	who->delete_title("Y010");
			who->add_title("Y015");
			who->show_title("Y015");
		    who->delete_title("Y015");
			who->add_title("Y025");
			who->show_title("Y025");  */
			who->delete_title("Y001");
			who->add_title("Y010");
			who->show_title("Y010");
			return 0;
			}
			break;
		case 6:
			/*	if ( who->get_save_2("diem.cs") < 10 ) {
					send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi chưa Chuyển Sinh đến giới hạn, \n chưa nhận thưởng được đâu !\n"
					ESC HIY"Ta biết rồi.....\ntalk %x# gift.2000\n"
					ESC"Rời khỏi",get_name(),id));
				}
				else {
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ngươi đã Chuyển Sinh đến giới hạn !!.\n Ngươi muốn nhận thưởng không ?\n"
					ESC HIY"Nhận 2000 Cống Hiến Môn Phái\ntalk %x# gift.55\n"
					ESC HIY"Tăng Kỹ năng Môn Phái lên 150\ntalk %x# gift.56\n"
					ESC HIY"Nhận Danh hiệu Chuyển Sinh\ntalk %x# gift.54\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id));
					}*/
			break;	
		case 7:
			if ( who->get_save_2("diem.cs")<1 )
				{
        		send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi chưa Chuyển Sinh đã muốn nhận thưởng ???\n"ESC"Rời khỏi.");
        		return;
				}
			if(who->get_save_2("diem.cs")==1)
			{	
				if ( who->get_save("npccs1")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 1 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs1",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 1 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(5000000);
			who->set_fam_contribute(who->get_fam_contribute()+10);
			return 0;
			}
			if(who->get_save_2("diem.cs")==2)
			{	
				if ( who->get_save("npccs2")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 2 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs2",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 2 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(7000000);
			who->set_fam_contribute(who->get_fam_contribute()+20);
			return 0;
			}
			if(who->get_save_2("diem.cs")==3)
			{	
				if ( who->get_save("npccs3")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 3 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs3",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 3 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(10000000);
			who->set_fam_contribute(who->get_fam_contribute()+30);
			return 0;
			}
			if(who->get_save_2("diem.cs")==4)
			{	
				if ( who->get_save("npccs4")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 4 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs4",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 4 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(13000000);
			who->set_fam_contribute(who->get_fam_contribute()+40);
			return 0;
			}
			if(who->get_save_2("diem.cs")==5)
			{	
				if ( who->get_save("npccs5")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 5 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs5",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 5 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(17000000);
			who->set_fam_contribute(who->get_fam_contribute()+50);
			return 0;
			}
			if(who->get_save_2("diem.cs")==6)
			{	
				if ( who->get_save("npccs6")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 6 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs6",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 6 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(20000000);
			who->set_fam_contribute(who->get_fam_contribute()+60);
			return 0;
			}
			if(who->get_save_2("diem.cs")==7)
			{	
				if ( who->get_save("npccs7")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 7 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs7",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 7 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(23000000);
			who->set_fam_contribute(who->get_fam_contribute()+70);
			return 0;
			}
			if(who->get_save_2("diem.cs")==8)
			{	
				if ( who->get_save("npccs8")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 8 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs8",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 8 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(27000000);
			who->set_fam_contribute(who->get_fam_contribute()+80);
			return 0;
			}
			if(who->get_save_2("diem.cs")==9)
			{	
				if ( who->get_save("npccs9")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 9 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs9",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 9 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(30000000);
			who->set_fam_contribute(who->get_fam_contribute()+90);
			return 0;
			}
			if(who->get_save_2("diem.cs")==10)
			{	
				if ( who->get_save("npccs10")>=1 )
				{
				send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận thưởng Chuyển Sinh lần 10 một lần rồi !\n"ESC"Rời khỏi.");
				return;
				}	
			who->add_save("npccs10",1);	
			send_user(who,"%c%s",';',HIY"Bạn đã nhận thưởng Chuyển Sinh lần 10 !!!");
			who->set_level(who->get_level()+1);
			who->count_gift();
			who->add_cash(35000000);
			who->set_fam_contribute(who->get_fam_contribute()+100);
			return 0;
			}
			break;	
		case 54:
		if(who->get_save_2("diem.cs")<1)
		{
			send_user(who,"%c%s",':',get_name() + ":\n    Không đủ 1 lần Chuyển Sinh, không thể nhận Danh hiệu !");
			return 0;
		}
		if(who->get_save_2("diem.cs")<5)
		{
		who->add_title("Y001");
		who->show_title("Y001");
		}
		else if(who->get_save_2("diem.cs")<10)
		{
		who->add_title("Y010");
		who->show_title("Y010");
		}
	/*	else if(who->get_save_2("diem.cs")<10)
		{
		who->add_title("Y015");
		who->show_title("Y015");
		}
		else if(who->get_save_2("diem.cs")<20)
		{
		who->add_title("Y025");
		who->show_title("Y025"); 
		}*/
//		USER_D->user_channel(sprintf(HIG "Chúc Mừng "HIC "%s (%d)" HIG " đã thông qua Chuyển Sinh nhận được danh hiệu "HIB " Thiên Hạ Vô Song  "HIG " . ", who->get_name(), who->get_number() ));
		break;
	/*	case 55:
		if(who->get_save_2("diem.cs")<10)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Không đủ 10 điểm Chuyển Sinh !!!\n Số điểm Chuyển Sinh của ngươi hiện chỉ là :" HIR " %d điểm",who->get_save_2("diem.cs")));
			return 0;
		}
		if(who->get_save("conghiencs")>=1)
		{
			send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận 1 lần rồi, không nhận thêm được nữa đâu!!!\n"ESC"Rời khỏi.");
			return 0;
		}
		who->add_save("conghiencs",1);
		who->set_fam_contribute(who->get_fam_contribute()+2000);
		USER_D->user_channel(sprintf(HIG "Chúc Mừng "HIC "%s (%d)" HIG " đã thông qua Chuyển Sinh nhận được "HIY " 2000 điểm Cống Hiến Môn Phái  "HIG " . ", who->get_name(), who->get_number() ));
		break;
		case 56:
		if(who->get_save_2("diem.cs")<10)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Không đủ 10 điểm Chuyển Sinh !!!\n Số điểm Chuyển Sinh của ngươi hiện chỉ là :" HIR " %d điểm",who->get_save_2("diem.cs")));
			return 0;
		}
		if(who->get_save("skillphai")>=1)
		{
			send_user(who,"%c%s",':',me->get_name()+":\n    Ngươi đã nhận 1 lần rồi, không nhận thêm được nữa đâu!!!\n"ESC"Rời khỏi.");
			return 0;
		}
		if ( who->get_fam_name()=="" )
		{
			send_user(who,"%c%s",':',me->get_name()+":\n    Vô Môn Phái không thể nhận phần thưởng này!!!\n"ESC"Rời khỏi.");
			return 0;
		}
		else if ( who->get_fam_name()=="Đào Hoa Nguyên" )
		{
			who->set_skill(0316, 150);
			who->set_skill(0211, 150);
			who->set_skill(0212, 150);
			who->set_skill(0319, 150);
			who->set_skill(0317, 150);
			who->add_save("skillphai",1);
			send_user(who,"%c%s",';',"Tất cả kĩ năng "HIY "Môn Phái Đào Hoa Nguyên"NOR " đã thăng lên cấp 150");
			return 0;
		}
		else if ( who->get_fam_name()=="Thục Sơn" )
		{
			who->set_skill(0329, 150);
			who->set_skill(0325, 150);
			who->set_skill(0231, 150);
			who->set_skill(0221, 150);
			who->set_skill(0222, 150);
			who->add_save("skillphai",1);
			send_user(who,"%c%s",';',"Tất cả kĩ năng "HIY "Môn Phái Thục Sơn"NOR " đã thăng lên cấp 150");
			return 0;
		}
		else if ( who->get_fam_name()=="Cấm Vệ Quân" )
		{
			who->set_skill(0349, 150);
			who->set_skill(0242, 150);
			who->set_skill(0241, 150);
			who->set_skill(0348, 150);
			who->set_skill(0251, 150);
			who->add_save("skillphai",1);
			send_user(who,"%c%s",';',"Tất cả kĩ năng "HIY "Môn Phái Cấm Vệ Quân"NOR " đã thăng lên cấp 150");
			return 0;
		}
		else if ( who->get_fam_name()=="Đường Môn" )
		{
			who->set_skill(0365, 150);
			who->set_skill(0364, 150);
			who->set_skill(0368, 150);
			who->set_skill(0261, 150);
			who->set_skill(0363, 150);
			who->add_save("skillphai",1);
			send_user(who,"%c%s",';',"Tất cả kĩ năng "HIY "Môn Phái Đường Môn"NOR " đã thăng lên cấp 150");
			return 0;
		}
		else if ( who->get_fam_name()=="Mao Sơn" )
		{
			who->set_skill(0414, 150);
			who->set_skill(0417, 150);
			who->set_skill(0271, 150);
			who->set_skill(0413, 150);
			who->set_skill(0418, 150);
			who->add_save("skillphai",1);
			send_user(who,"%c%s",';',"Tất cả kĩ năng "HIY "Môn Phái Mao Sơn"NOR " đã thăng lên cấp 150");
			return 0;
		}
		else if ( who->get_fam_name()=="Côn Luân" )
		{
			who->set_skill(0421, 150);
			who->set_skill(0423, 150);
			who->set_skill(0424, 150);
			who->set_skill(0425, 150);
			who->set_skill(0422, 150);
			who->add_save("skillphai",1);
			send_user(who,"%c%s",';',"Tất cả kĩ năng "HIY "Môn Phái Côn Luân"NOR " đã thăng lên cấp 150");
			return 0;
		}
		else if ( who->get_fam_name()=="Vân Mộng Cốc" )
		{
			who->set_skill(0511, 150);
			who->set_skill(0531, 150);
			who->set_skill(0501, 150);
			who->set_skill(0281, 150);
			who->set_skill(0591, 150);
			who->add_save("skillphai",1);
			send_user(who,"%c%s",';',"Tất cả kĩ năng "HIY "Môn Phái Vân Mộng Cốc"NOR " đã thăng lên cấp 150");
			return 0;
		}
	//	USER_D->user_channel(sprintf(HIG "Chúc Mừng "HIC "%s (%d)" HIG " đã thông qua Chuyển Sinh và tăng tất cả kỹ năng Môn Phái lên "HIY "cấp 150  "HIG " . ", who->get_name(), who->get_number() ));
		break;
		case 1000:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Điều kiện để Chuyển Sinh là cần đạt tới cấp độ và một lượng Kim Nguyên Bảo nhất định ! \nLần 1: yêu cầu cấp 150 + 400 KNB\nLần 2: yêu cầu cấp 145 + 800 KNB\nLần 3: yêu cầu cấp 140 + 1200 KNB\nLần 4: yêu cầu cấp 135 + 1600 KNB\nLần 5: yêu cầu cấp 130 + 2000 KNB\nLần 6: yêu cầu cấp 125 + 2400 KNB\nLần 7: yêu cầu cấp 120 + 2800 KNB\nLần 8: yêu cầu cấp 115 + 3200 KNB\nLần 9 : yêu cầu cấp 110 + 3600 KNB\nLần 10: yêu cầu cấp 105 + 4000 KNB\nMỗi lần Chuyển Sinh nhân vật được cộng thêm 250 điểm thuộc tính \nSau khi đạt tới 10 lần Chuyển Sinh có thể nhận được danh hiệu cao quý ! \n"
					ESC HIY"Ta đã hiểu rồi...\ntalk %x# gift.1001\n"
					ESC"Rời khỏi",get_name(),id,id));
			break;*/
				
		}
}
