#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>


inherit OFFICER;

int iStart2,iFinish2,close_val,open_val,BatDau,KetThuc;

// 函数:获取人物造型
int get_char_picid() { return 9971; }
void do_gift( string arg );
// 函数：小贩识别
int is_seller() { return 7010; }
int is_self_look() { return 1; }

void create()
{

		set_name("Pret Già");
		 set_real_name("Nhập Code Tri Ân");
		set_2( "good", ([
                "01" : "/item/tienxu/thevip",
                "02" : "/item/tienxu/tuidoanthach",	
				"03" : "/item/tienxu/TLTA",	
				"04" : "/item/01/0200",	
				"05" : "/item/01/0201",	
				"06" : "/item/01/0202",			
				"07" : "/item/tienxu/setcankhon",
				"08" : "/item/tienxu/setmuahe",	
				"09" : "/item/tienxu/settieudao",
				"10" : "/item/tienxu/setnuhiep",	
				"11" : "/item/tienxu/setcankhonnu",
				"12" : "/item/tienxu/setdaopho",	
				"13" : "/item/tienxu/setlangtu",
				"14" : "/item/tienxu/setanhhungcy",	
        ]) );
        set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
		
}

void do_look( object who ) 
{
	int id = getoid( this_object() );
	object me = this_object();
	string result;
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Xin chào, tôi là GM Pret, nếu bạn có code thì hãy tới chỗ tôi để nhận quà! Nào, bạn có code không vậy? \n"
		ESC "Xàm xàm chút\ntalk %x# gift.1\n"	
		ESC HIB"Mua vật phẩm (Bằng Tiền Xu)\nlist12 %x#\n"	
        ESC HIY"Chọn Loại Code Cần Nhập\ntalk %x# gift.2\n"		
		ESC"Rời khỏi",get_name(),id,id,id,id,id));	
		
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,sec,tien,ben, tet1=0,tet2=0, tet3, tet4,bennhat2,bn2,level;
	object who,item,item1,item2,item3;
	string *nTmp,cFile,cTmp,cFinal,result,bennhat,bn;
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
			send_user(who,"%c%c%w%s",':',3,9971,sprintf("Pret Kuzl:\nTôi là GM Chiến Quốc Tâm Diện....về già, hẳn các bạn đã biết. Ngoài già ra cơ mà đẹp trai ra thì không biết phải giới thiệu thêm gì về tôi nữa. Mà thôi, nói nhiều làm gì, bạn muốn gì ở tôi vậy?\n"
			ESC"Rời khỏi",id));
		break;
			case 2:
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Chỉ có những người chơi tham gia Event mới nhập code ở đây! Bạn muốn nhập code gì vậy? \n"
				ESC HIY"Nhập Code Tri Ân Người Chơi Cũ\ntalk %x# gift.1000\n"
				ESC HIC"Nhập Code Chào Mừng Người Chơi Mới\ntalk %x# gift.2000\n"
				//ESC HIG"Nhập Code CQMC\ntalk %x# gift.3000\n"
				//ESC HIC"Nhập Code Event\ntalk %x# gift.4000\n"
				//ESC HIC"Nhập Code Tri Ân\ntalk %x# gift.5000\n"
				//ESC HIC"Nhập Code Pret\ntalk %x# gift.6000\n"
				ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
		break;

			// Code Tri Ân Người Chơi Cũ
			case 1000:
			if ( who->get_fam_name()!="" && who->get_level() >= 60 ) 
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi trên 60 và đã gia nhập Môn phái thì mới có thể nhận quà!\n"
				ESC HIY"Nhập code Tri Ân Người Chơi Cũ\ntalk %x# gift.1001\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
				return ;
			}	
			else if ( who->get_fam_name()=="" )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code !\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
				return ;
			}
			else if ( who->get_level() < 60 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Dưới cấp 60 không thể nhập Code!\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
				return ;
			}
		break;
		
		case 1001:
			if ( who->get_fam_name()!="" && who->get_level() >= 60 ) 
			{
				send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Tri Ân    (Tối đa 15 ký tự):\n" ESC "codetrianncc + %s\n" );
				return ;
			}	
			else if ( who->get_fam_name()=="" )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code!\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
				return ;
			}
			else if ( who->get_level() < 60 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Dưới cấp 60 không thể nhập Code!\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
				return ;
			}
		break; 
			
			// Code Chào Mừng Người Chơi MỚi
		case 2000:

			if ( who->get_fam_name()!="" && who->get_level() >= 60 ) 
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi trên 60 và đã gia nhập Môn phái thì mới có thể nhận quà!\n"
				ESC HIY"Nhập code Chào Mừng Người Chơi Mới\ntalk %x# gift.2001\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
				return ;
			}	
			else if ( who->get_fam_name()=="" )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code !\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
				return ;
			}
			else if ( who->get_level() < 60 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Dưới cấp 60 không thể nhập Code!\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
				return ;
			}
		break;
		
		case 2001:
			if ( who->get_fam_name()!="" && who->get_level() >= 60 ) 
			{
				send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Chào Mừng    (Tối đa 15 ký tự):\n" ESC "codechaomung + %s\n" );
				return ;
			}	
			else if ( who->get_fam_name()=="" )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code!\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
				return ;
			}
			else if ( who->get_level() < 60 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
			sprintf(" %s :\n Dưới cấp 60 không thể nhập Code!\n"
				ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
				ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
				return ;
			}	
		break;
		}
}



