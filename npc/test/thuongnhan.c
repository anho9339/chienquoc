/* Edit Pret
check: kiem tra da nhan chua
sqcd: so quai can diet
sll: so lan lam
diemtn: diem thuong nhan
Đông Võ đi từ Đại Biệt Sơn qua 
Hán Trung đi từ Hàm Cốc Quan -> Tử Ngọ Cốc -> Hán Trung
Vũ Quan đi từ Thúy Hoa Sơn qua
*/

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <time.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 9957; }
void do_welcome( string arg );
void do_bonus(string arg);


// 函数：构造处理
	void create()
		{
			set_name("Thương Nhân");
			set_real_name(HIR "Yến Tử");
			set_2( "talk", ([
					
					"welcome"          : (: do_welcome :),
					"bonus"        : (: do_bonus :),
			]));

			setup();
		}

		// 函数：对话处理
	void do_look( object who )
		{
		int id = getoid( this_object() );
		if(who->get_save_2("check.score") == 1)
		{
		send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi hãy kiếm giúp ta giết "HIR ": %d/50 con Gà Núi,Thỏ Hoang,Bù Nhìn. "NOR "(Nghe nói chúng có rất nhiều ở Tân Thủ Thôn)"NOR "\nKhen thưởng nhiệm vụ:"HIM"\n --KNB và Kinh Nghiệm\n"
			ESC HIG"Trả nhiệm vụ\ntalk %x# bonus.1\n"
			ESC "Thôi lát ta làm\n",who->get_save_2("sqcd.score"),id,id));
		}
		else
		if(who->get_save_2("check.score") == 2)
		{
		send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi hãy kiếm giúp ta giết "HIR ": %d/50 con Nỗ Binh,Quyền Pháp Sư,Côn Sư. "NOR "(Nghe nói chúng có rất nhiều ở Đông Vũ <khu vực cấp 45-50>. Đông Võ đi từ Đại Biệt Sơn qua) "NOR "\nKhen thưởng nhiệm vụ:"HIM"\n --KNB và Kinh Nghiệm\n"
			ESC HIG"Trả nhiệm vụ\ntalk %x# bonus.2\n"
			ESC "Thôi lát ta làm\n",who->get_save_2("sqcd1.score"),id,id));
		}
		else
		if(who->get_save_2("check.score") == 3)
		{
		send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi hãy kiếm giúp ta giết "HIR ": %d/50 con Phong Lôi Kiếm,Tử Tù. "NOR "(Nghe nói chúng có rất nhiều ở Hán Trung <khu vực cấp 95-100>. Hán Trung đi từ Hàm Cốc Quan -> Tử Ngọ Cốc là thấy Hán Trung)"NOR "\nKhen thưởng nhiệm vụ:"HIM"\n --KNB và Kinh Nghiệm\n"
			ESC HIG"Trả nhiệm vụ\ntalk %x# bonus.3\n"
			ESC "Thôi lát ta làm\n",who->get_save_2("sqcd2.score"),id,id));
		}
		else
		if(who->get_save_2("check.score") == 4)
		{
		send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi hãy kiếm giúp ta giết "HIR ": %d/50 con Bá Đao Tướng Quân,Phi Vân Tướng Quân. "NOR "(Nghe nói chúng có rất nhiều ở Vũ Quan <khu vực cấp 105-110>. Vũ Quan đi từ Thúy Hoa Sơn qua)"NOR "\nKhen thưởng nhiệm vụ:"HIM"\n --KNB và Kinh Nghiệm\n"
			ESC HIG"Trả nhiệm vụ\ntalk %x# bonus.4\n"
			ESC "Thôi lát ta làm\n",who->get_save_2("sqcd3.score"),id,id));
		}

		else
		send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Số lần làm còn lại của ngươi "HIR ": %d lần."NOR "(Đưa ta 'Phiếu Thương Nhân' ta sẽ đảm bảo giao trách nhiệm cho ngươi.'Phiếu Thương Nhân' có thể mua tại Ngân Khố"NOR " \nNgươi làm nhiệm vụ này có thể đem về rất nhiều KNB\n Điểm thương nhân ngươi hiện có : "HIR "%d điểm "NOR "(Khi quy tụ nhiều điểm thương nhân có thể nhận được nhiều KNB hơn)\n"
			ESC HIG"Đổi 'Phiếu Thương Nhân'\ntalk %x# welcome.2\n"
			ESC HIG"Nhận nhiệm vụ\ntalk %x# welcome.1\n"
		//	ESC HIG"Ta Muốn Đổi Thưởng\ntalk %x# welcome.3\n"
			ESC "Thôi lát ta làm\n",who->get_save_2("sll.score"),who->get_save_2("diemtn.score"),id,id,id,id));
		}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,id,p,diemtn,size,iTime,iDay,iGio,iMin;
	object who,item,map,*team;
	string result;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);     
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];
	iMin = mxTime[TIME_MIN];
	
	who = this_player();
	id = getoid(me);
	flag = to_int(arg);
	who->set_time( "talk",  0);
	
	if( who->get_leader() && arrayp( team = who->get_team() ) && sizeof(team) > 1 )
	{
		team = me->correct_bonus_team(team);
		size = sizeof(team);
	}
	else
	{
	team = ({who});
	size = 1;
	}
			
        switch(flag)
        {
       	case 1:
			/*if(size<0)
			{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Khi làm nhiệm vụ Thương Nhân, không được phép tổ đội"));
			return 0;
			} */
			if(who->get_level() < 20)
			{
				send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi phải đạt cấp cao hơn 20 thì mới có thể nhận nhiệm vụ"));
				return 0;
			}
			//Check time
		/*	if (who->get_save_2("timetn")==iGio/2)
			{
			result = me->get_name()+":\n    Bạn đã làm nhiệm vụ rồi, hãy chờ 30 phút sau theo để đi tiếp !\n";
			send_user( who, "%c%c%w%s", ':', 3, 9957, result );
			return;
			}  */
			
			if(who->get_save_2("sll.score")==0)
			{
				send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi không còn lượt làm .\n Hãy dùng"HIR " 'Phiếu Thương Nhân'"NOR " để lấy thêm lượt làm"));
				return 0;
			}
			
			if(who->get_level() >= 100)
			{
			send_user(who,"%c%s",';',"Bạn đã nhận nhiệm vụ thương nhân !!!"HIC "Cố gắng hoàn thành sẽ được thưởng hậu hỉ");
			who->add_save_2("sll.score",-1);
			who->add_save_2("check.score",4);
	//		who->set_save_2("timetn", iGio/2);  
				return 0;
			}
			if(who->get_level() >= 90)
			{
			send_user(who,"%c%s",';',"Bạn đã nhận nhiệm vụ thương nhân !!!"HIC "Cố gắng hoàn thành sẽ được thưởng hậu hỉ");
			who->add_save_2("sll.score",-1);
			who->add_save_2("check.score",3);
	//		who->set_save_2("timetn", iGio/2); 
				return 0;
			}
			if(who->get_level() >= 50)
			{
			send_user(who,"%c%s",';',"Bạn đã nhận nhiệm vụ thương nhân !!!"HIC "Cố gắng hoàn thành sẽ được thưởng hậu hỉ");
			who->add_save_2("sll.score",-1);
			who->add_save_2("check.score",2);
	//		who->set_save_2("timetn", iGio/2);  
				return 0;
			}			
			send_user(who,"%c%s",';',"Bạn đã nhận nhiệm vụ thương nhân !!!"HIC "Cố gắng hoàn thành sẽ được thưởng hậu hỉ");
			who->add_save_2("sll.score",-1);
			who->add_save_2("check.score",1);
	//		who->set_save_2("timetn", iGio/2); 			
		break;
		
		case 2:
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Phiếu Thương Nhân") < 1 )
			{
			notify( "Ngươi không có Phiếu Thương Nhân trong người xin hãy xem lại" );
			return ;	
			}
			TASK_LEGEND_D->check_task_item1(who,"Phiếu Thương Nhân",1);
			who->add_save_2("sll.score",10) ;
			send_user(who,"%c%s",';',"Ngươi vừa đổi phiếu thương nhân"HIC " Nhận thêm :10 lượt làm nhiệm vụ");
		break;
		
		/*		case 3:
		send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi đã làm giúp ta nhiều việc rồi phải không !!! Ta nên thưởng ngươi vài món quà nhỉ . Ngươi muốn ta thưởng gì nào ???\n Số điểm thương nhân ngươi hiện có:"HIR "%d điểm \n"
		ESC HIY"10000 điểm đổi 1 Bí Kíp Chuyển Sinh\ntalk %x# bonus.10\n"
		ESC HIY"2000 điểm đổi 100 Chén Bạc thường\ntalk %x# bonus.11\n"
		ESC HIY"100 điểm đổi 100 Ngũ Hành Hồn Thạch\ntalk %x# bonus.12\n"
		ESC HIG"Thôi lát ta đổi\n",who->get_save_2("diemtn.score"),id,id,id,id,id,id));
		break;
       	 */
		 }
}


void do_bonus(string arg)
{
	__FILE__->do_bonus_2(this_object(),arg);
}


void do_bonus_2( object me, string arg )
{
	int flag,point,i,id,p,soluong,level,diemtn;
	object who,item;
	string cTmp,cFile;
	who = this_player();
	flag = to_int(arg);
	level = who->get_level();	 
	diemtn = who->get_save_2("diemtn.score");
	
        switch(flag)
        {
			// Gà Núi,Thỏ Hoang,Bù Nhìn
       	case 1:
			if(who->get_save_2("sqcd.score")<50)
			{
				send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi vẫn chưa giết đủ. Số lượng ngươi giết được là " HIR ":%d/50",who->get_save_2("sqcd.score")));
				return 0;
			}
			who->set_save_2("sqcd.score",0);			
			
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Bạn đã hoàn thành nhiệm vụ thương nhân !!!"HIC " Nhận được :%d Ngân bảo và %d kinh nghiệm và 1 điểm Tích Luỹ",100+level+diemtn,100*level));
			who->add_save_2("check.score",-1);
			who->add_save_2("diemtn.score",1);
		//	who->add_cash(600*level+diemtn*10);
			"sys/sys/test_db"->add_yuanbao(who,100+level+diemtn);
			who->add_exp(100*level);
		break;
		// Nỗ Binh,Quyền Pháp Sư,Côn Sư 45 50
		case 2:
			if(who->get_save_2("sqcd1.score")<50)
			{
				send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi vẫn chưa giết đủ. Số lượng ngươi giết được là " HIR ":%d/50",who->get_save_2("sqcd1.score")));
				return 0;
			}
			who->set_save_2("sqcd1.score",0);

			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Bạn đã hoàn thành nhiệm vụ thương nhân !!!"HIC " Nhận được :%d Ngân bảo và %d kinh nghiệm và 2 điểm Tích Luỹ",150+level+diemtn,120*level));
			who->add_save_2("check.score",-1);
			who->add_save_2("diemtn.score",2);
		//	who->add_cash(700*level+diemtn*10);
			"sys/sys/test_db"->add_yuanbao(who,150+level+diemtn);
			who->add_exp(120*level);
		break;
			// Phong Lôi Kiếm,Tử Tù 95 - 100
		case 3:
			if(who->get_save_2("sqcd2.score")<50)
			{
				send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi vẫn chưa giết đủ. Số lượng ngươi giết được là " HIR ":%d/50",who->get_save_2("sqcd2.score")));
				return 0;
			}
			who->set_save_2("sqcd2.score",0);

			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Bạn đã hoàn thành nhiệm vụ thương nhân !!!"HIC " Nhận được :%d Ngân bảo và %d kinh nghiệm và 3 điểm Tích Luỹ",200+level+diemtn,140*level));
			who->add_save_2("check.score",-1);
			who->add_save_2("diemtn.score",3);
		//	who->add_cash(800*level+diemtn*10);
			"sys/sys/test_db"->add_yuanbao(who,200+level+diemtn);
			who->add_exp(140*level);
		break;
		// Bá Đao Tướng Quân,Phi Vân Tướng Quân 105 - 110
		case 4:
			if(who->get_save_2("sqcd3.score")<50)
			{
						send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Ngươi vẫn chưa giết đủ. Số lượng ngươi giết được là " HIR ":%d/50",who->get_save_2("sqcd3.score")));
				return 0;
			}
			who->set_save_2("sqcd3.score",0);
				
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Bạn đã hoàn thành nhiệm vụ thương nhân !!!"HIC " Nhận được :%d Ngân bảo và %d kinh nghiệm và 4 điểm Tích Luỹ",250+level+diemtn,180*level));
			who->add_save_2("check.score",-1);
			who->add_save_2("diemtn.score",4);
		//	who->add_cash(900*level+diemtn*10);
			"sys/sys/test_db"->add_yuanbao(who,250+level+diemtn);
			who->add_exp(180*level);
		break;
		
		
	/*	case 10:
		if(who->get_save_2("diemtn.score")<10000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hình như sức của ngươi ít mà thích đòi công nhiều !!!\n Số điểm thương nhân của ngươi hiện chỉ là :" HIR "%d điểm",who->get_save_2("diemtn.score")));
			return 0;
		}
		who->add_save_2("diemtn.score",-10000);
		item = new("/item/test/phieuchuyensinh");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi quà Thương Nhân nhận được: " HIY"%s " HIG " Cung hỉ !!! Cung hỉ ", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 11:
		if(who->get_save_2("diemtn.score")<2000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hình như sức của ngươi ít mà thích đòi công nhiều !!!\n Số điểm thương nhân của ngươi hiện chỉ là :" HIR "%d điểm",who->get_save_2("diemtn.score")));
			return 0;
		}
		who->add_save_2("diemtn.score",-2000);
		item = new("/item/test/tuichenbac_100");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi quà Thương Nhân nhận được: " HIY"%s " HIG " Cung hỉ !!! Cung hỉ ", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 12:
		if(who->get_save_2("diemtn.score")<300)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hình như sức của ngươi ít mà thích đòi công nhiều !!!\n Số điểm thương nhân của ngươi hiện chỉ là :" HIR "%d điểm",who->get_save_2("diemtn.score")));
			return 0;
		}
		who->add_save_2("diemtn.score",-300);	
		item = new("/item/test/tuinguhanhhonthach(100)");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi quà Thương Nhân nhận được: " HIY"%s " HIG " Cung hỉ !!! Cung hỉ ", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 13:
		if(who->get_save_2("diemtn.score")<1000)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hình như sức của ngươi ít mà thích đòi công nhiều !!!\n Số điểm thương nhân của ngươi hiện chỉ là :" HIR "%d điểm",who->get_save_2("diemtn.score")));
			return 0;
		}
		who->add_save_2("diemtn.score",-1000);	
		item = new("/item/test/tuiphieuthuongnhan_3");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi quà Thương Nhân nhận được: " HIY"%s " HIG " Cung hỉ !!! Cung hỉ ", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 19:
		if(who->get_save_2("diemtn.score")<200)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hình như sức của ngươi ít mà thích đòi công nhiều !!!\n Số điểm thương nhân của ngươi hiện chỉ là :" HIR "%d điểm",who->get_save_2("diemtn.score")));
			return 0;
		}
		who->add_save_2("diemtn.score",-200);	
		item = new("/item/test/heodat");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi quà Thương Nhân nhận được: " HIY"%s " HIG " Cung hỉ !!! Cung hỉ ", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break;
		case 20:
		if(who->get_save_2("diemtn.score")<400)
		{
			send_user(who,"%c%s",':',sprintf( get_name() + ":\n    Hình như sức của ngươi ít mà thích đòi công nhiều !!!\n Số điểm thương nhân của ngươi hiện chỉ là :" HIR "%d điểm",who->get_save_2("diemtn.score")));
			return 0;
		}
		who->add_save_2("diemtn.score",-400);	
		item = new("/item/test/heodat2");
		i = item->move(who,-1);
		item->add_to_user(i);
			USER_D->user_channel(sprintf(HIG"Bằng hữu "HIY "%s" HIG" vừa đổi quà Thương Nhân nhận được: " HIY"%s " HIG " Cung hỉ !!! Cung hỉ ", who->get_name(),item->get_name() ));
		send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		break; */
		}
}

