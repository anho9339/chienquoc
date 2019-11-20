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
int get_char_picid() { return 8291; }
void do_gift( string arg );
// 函数：小贩识别
//int is_seller() { return 4; }
// 有自己的do_look函数
int is_self_look() { return 1; }


void create()
{
     
		set_name("Mèo Đại Gia");
		 set_real_name("Nhập Code Nhận Tiền");
		set_2( "good", ([
                "01" : "/item/event/tet/phao",
       //         "02" : "/item/ngoai_trang/vip102",			
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
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Meo...meo..Vâng lệnh của đại ca Pret, từ cấp 50 -> 105 sẽ nhận được 5 ngân lượng và 5 ngân bảo mỗi 5 giây nha..chết chết....lên cót hộ ta với!!! \n"
		ESC "Xàm xàm chút\ntalk %x# gift.1\n"	
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
		send_user(who,"%c%c%w%s",':',3,8291,sprintf("Mèo Đại Gia:\nTa được lệnh của Pret xuống đây để cho các ngươi tí tiền tiêu dùng...cọt cọt...\n Vào thời gian rảnh hãy tới đây nằm cạnh ta nhé...Chết mịa...Hết cót rồi...\n"
		ESC"Rời khỏi",id));
			break;
       case 2:
			send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Đây là những Code có trong CQTD, nhưng code không phải lúc nào cũng có thể xin và nhập, bạn hãy chờ đợi và lắng nghe chỉ thị từ GM trên Group Chiến Quốc Tâm Diện nhé! \n"
					ESC HIY"Nhập Code Tân Thủ\ntalk %x# gift.1000\n"
					ESC HIC"Nhập Code Năm Mới\ntalk %x# gift.2000\n"
					ESC HIG"Nhập Code CQMC\ntalk %x# gift.3000\n"
					ESC HIC"Nhập Code Event\ntalk %x# gift.4000\n"
					ESC HIC"Nhập Code Tri Ân\ntalk %x# gift.5000\n"
					ESC HIC"Nhập Code Pret\ntalk %x# gift.6000\n"
					ESC HIC"Nhập Code 8x\ntalk %x# gift.7000\n"
					ESC"Rời khỏi",get_name(),id,id,id,id,id,id,id));
			break;
     
		    // Code Tân Thủ
	 	case 1000:
	      /*  iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() <= 60 ) 
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi dưới 60 và Đã gia nhập Môn phái thì ta có thể hỗ trợ cho ngươi ! Nào, muốn nhập Code Tân Thủ không ?\n"
	                ESC HIY"Nhập code Tân Thủ\ntalk %x# gift.1001\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() > 60 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Trên cấp 60 không thể nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	*/
		break;
		case 1001:
	        /*  iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() <= 60 ) 
				{
					send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Tân Thủ    (Tối đa 15 ký tự):\n" ESC "codetanthu + %s\n" );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() > 60 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Trên cấp 60 không thể nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	 */
		break; 
		// Code Năm Mới
		case 2000:
	       /* iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 40 ) 
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi trên 40 và Đã gia nhập Môn phái thì ta có thể hỗ trợ cho ngươi ! Nào, muốn nhập Code Năm Mới không ?\n"
	                ESC HIY"Nhập code Năm Mới\ntalk %x# gift.2001\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
				}	
				 else if ( who->get_save("tqnm")> 0 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi đã nhận code 1 lần rồi, không thể nhập Code Năm Mới!\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
			}
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Năm Mới!\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 40 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 40 không thể nhập Code Năm Mới !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
			/*}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Năm Mới !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	*/
		break;
		case 2001:
	       /* iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 40 ) 
				{
					send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Năm Mới   (Tối đa 15 ký tự):\n" ESC "codenammoi + %s\n" );
					return ;
				}
                else if ( who->get_save("tqnm")> 0 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi đã nhận code 1 lần rồi, không thể nhập Code Năm Mới!\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
			}				
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Năm Mới !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 40 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 40 không thể nhập Code Năm Mới !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Năm Mới !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	 */
		break;
		// Code CQMC
		case 3000:
	        iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{
				if ( who->get_fam_name()!="" && who->get_level() >= 40 ) 
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi trên 40 và Đã gia nhập Môn phái thì ta có thể hỗ trợ cho ngươi ! Nào, muốn nhập Code CQMC không ?\n"
	                ESC HIY"Nhập code CQMC\ntalk %x# gift.3001\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
				}	
				 else if ( who->get_save("cqmc")> 0 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi đã nhận code 1 lần rồi, không thể nhập Code CQMC!\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
			}
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code CQMC!\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 40 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 40 không thể nhập Code CQMC !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
			}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code CQMC !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			} 	
		break;
		case 3001:
	        iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{
				if ( who->get_fam_name()!="" && who->get_level() >= 40 ) 
				{
					send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code CQMC   (Tối đa 15 ký tự):\n" ESC "codecqmc + %s\n" );
					return ;
				}
                else if ( who->get_save("cqmc")> 0 )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi đã nhận code 1 lần rồi, không thể nhập Code CQMC!\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
			}				
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code CQMC !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 40 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 40 không thể nhập Code CQMC !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
					return ;
				}
			}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code CQMC !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			} 	
		break;
		 // Code Event
	 	case 4000:
	     /*   iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 20 ) 
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi trên 20 và Đã gia nhập Môn phái thì ta có thể giúp ngươi! Nào, ngươi muốn nhận gì ?\n"
	                ESC HIY"Nhập code Event\ntalk %x# gift.4001\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Event !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.4002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 20 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 20 không thể nhập Code Event !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.4002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Event !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			} */	
		break;
		case 4001:
	    /*    iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 20 ) 
				{
					send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Event    (Tối đa 15 ký tự):\n" ESC "codeevent + %s\n" );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Event !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.4002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 20 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 20 không thể nhập Code Event !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.4002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Event !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.4002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			} */	
		break; 
		 // Code Tri Ân
	 	case 5000:
	    /*    iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 20 ) 
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi trên 20 và đã gia nhập Môn phái thì ta có thể hỗ trợ cho ngươi ! Nào, muốn nhập Code Tri Ân không ?\n"
	                ESC HIY"Nhập Code Tri Ân\ntalk %x# gift.5001\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 20 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 20 không thể nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	 */
		break;
		case 5001:
	 /*       iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 20 ) 
				{
					send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Tri Ân    (Tối đa 15 ký tự):\n" ESC "codetrian + %s\n" );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 20 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 20 không thể nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			} */	
		break; 
		
		case 6000:
	    /*    iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 20 ) 
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi trên 20 và đã gia nhập Môn phái thì ta có thể hỗ trợ cho ngươi ! Nào, muốn nhập Code Pret không ?\n"
	                ESC HIY"Nhập Code Tri Ân\ntalk %x# gift.6001\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Pret !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.6002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 20 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 20 không thể nhập Code Pret !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.6002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	 */
		break;
		case 6001:
	 /*       iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() >= 20 ) 
				{
					send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code Pret    (Tối đa 15 ký tự):\n" ESC "codepret + %s\n" );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code Pret !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.6002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() < 20 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Dưới cấp 20 không thể nhập Code Pret !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.6002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tri Ân !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.5002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			} */	
		break; 
		
		case 7000:
	      /*  iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() <= 80 ) 
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Chỉ cần đẳng cấp của ngươi dưới 80 và Đã gia nhập Môn phái thì ta có thể hỗ trợ cho ngươi ! Nào, muốn nhập Code 8x không ?\n"
	                ESC HIY"Nhập code 8x\ntalk %x# gift.7001\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code 8x !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() > 80 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Trên cấp 80 không thể nhập Code 8x !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	*/
		break;
		case 7001:
	        /*  iTime = time();
			if ( iTime > BatDau && iTime < KetThuc )
			{ */
				if ( who->get_fam_name()!="" && who->get_level() <= 80 ) 
				{
					send_user( who, "%c%c%d%s", '?', 16, 15, "Xin nhập mã Code 8x    (Tối đa 15 ký tự):\n" ESC "code8x + %s\n" );
					return ;
				}	
				else if ( who->get_fam_name()=="" )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Ngươi chưa gia nhập Môn phái, không thể nhập Code 8x !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );	
					return ;
				}
				else if ( who->get_level() > 80 )
				{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Trên cấp 80 không thể nhập Code 8x !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(), getoid(me) ) );	
					return ;
				}
		/*	}
			else if ( iTime < BatDau || iTime > KetThuc )
			{
			send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),
	        	sprintf(" %s :\n Bây giờ không phải thời gian nhập Code Tân Thủ !\n"
	                ESC HIY"Ta hiểu rồi\ntalk %x# gift.1002\n"
	                ESC "Huỷ bỏ\nCLOSE\n", me->get_name(),getoid(me) ) );
					return ;
			}	 */
		break; 
		}
}



