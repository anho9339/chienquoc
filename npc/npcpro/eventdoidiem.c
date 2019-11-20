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
        set_name("Trao Đổi Điểm");
		set_real_name(HIR "Lưu Hoàng Sư");
        set_2( "good", ([
//              "01" : "/item/doanthachban/0032",
//				"02" : "/item/doanthachban/1032",
//				"03" : "/item/doanthachban/2032",
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
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Vạn vật trong thế giới đều có thừa có thiếu, vậy làm gì với những thứ thừa và dư đấy! Ta sẽ cho ngươi câu trả lời thích đáng!\n"	
		ESC "Vài điều về đổi Điểm Thành Tựu!\ntalk %x# gift.1\n"
		ESC HIY"Ta muốn đổi Điểm Thành Tựu\ntalk %x# gift.2\n"
		ESC HIB"Ta muốn đổi thưởng\ntalk %x# gift.3\n"
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
		 send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Trong quá trình chơi Chiến Quốc Tâm Diện, có một số thứ bị dư ra và một số thứ không xài tới, nhưng chúng ta lại cứ phải để đấy không dùng. Nếu có đồ dư, hãy mang tới ta để phân giải lấy Điểm Thành Tựu để đổi lấy thứ cần thiết. \n * Lưu ý là: Event chỉ có trong thời hạn một tuần, hãy dùng hết điểm khi hết thời hạn, không thì chúng ta còn lâu mới gặp lại mặt nhau đấy! Dĩ nhiên tôi vẫn sẽ nhớ số điểm mà bạn quyên góp rồi!\n"
		 ESC"Rời khỏi",get_name(),id));
		case 2: 
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Hãy chọn một thứ mà ngươi muốn đổi để lấy điểm Thành Tựu.\n"	
		ESC "Đổi "HIB"Ngân Lượng lấy Điểm Thành Tựu\ntalk %x# gift.10\n"
		ESC "Đổi "HIB"Đồ Lam Kim lấy Điểm Thành Tựu\ntalk %x# gift.20\n"
		ESC "Đổi "HIB"Đồ Hoàng Kim lấy Điểm Thành Tựu\ntalk %x# gift.30\n"
		ESC "Đổi "HIB"Cao Cấp Đoạn Thạch lấy Điểm Thành Tựu\ntalk %x# gift.40\n"
		ESC "Đổi "HIB"Kim Nguyên Bảo lấy Điểm Thành Tựu\ntalk %x# gift.50\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		case 12:
				send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Điểm tích luỹ Sư Môn của bạn hiện là "HIR "%d "NOR "điểm !! \n"
					ESC HIY"[Dùng 5 điểm đổi lấy Kinh Nghiệm]\ntalk %x# gift.66\n"
					ESC"Rời khỏi",get_name(),who->get_save("diemsumon.score"),id,id));
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
