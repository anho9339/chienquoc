/*
NPC Trùng Sinh - by Ben
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
void do_gift( string arg );

// 函数:构造处理
void create()
{
        set_name("Tiên Đế Thánh Thượng");
		set_real_name(HIR "Trùng Sinh");
		set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));

        setup();
}

void do_look( object who ) 
{
	int id = getoid( this_object() ), chp, cd, cap, tien;
	if(who->get_save("trungsinh")==0) { chp = 500; cd = 5000; cap = 100; tien = 300000; }
	else if(who->get_save("trungsinh")==1) { chp = 1000; cd = 6000; cap = 100; tien = 500000; }
	else if(who->get_save("trungsinh")==2) { chp = 1500; cd = 7000; cap = 100; tien = 800000; }
	else if(who->get_save("trungsinh")==3) { chp = 2000; cd = 8000; cap = 100; tien = 1000000; }
	else if(who->get_save("trungsinh")==4) { chp = 2500; cd = 9000; cap = 100; tien = 1500000; }
	else if(who->get_save("trungsinh")==5) { chp = 3000; cd = 10000; cap = 100; tien = 2000000; }
	else if(who->get_save("trungsinh")==6) { chp = 5000; cd = 11000; cap = 100; tien = 2500000; }
	else if(who->get_save("trungsinh")==7) { chp = 8000; cd = 12000; cap = 100; tien = 3000000; }
	else if(who->get_save("trungsinh")==8) { chp = 12000; cd = 13000; cap = 100; tien = 3500000; }
	else if(who->get_save("trungsinh")==9) { chp = 15000; cd = 15000; cap = 100; tien = 4000000; }
		if ( who->get_save("trungsinh") < 10 )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nSố lần trùng sinh của ngươi hiện tại là "HIR "%d"NOR " lần. Bây giờ ngươi muốn trùng sinh phải đạt tới cấp "HIR "%d"NOR " và cần tiêu hao "HIR "%d"NOR " cống hiến môn phái,\n "HIR "%d"NOR " thể lực, "HIR "%d"NOR " điểm công đức cùng "HIR "%d"NOR " ngân lượng. \nNgươi có chắc chắn muốn trùng sinh không?\n"
		ESC "Trùng Sinh lần %d\ntalk %x# gift.2\n"
		ESC "Bảng xếp hạng Trùng sinh\ntalk %x# gift.3\n"
		ESC "Nhận danh hiệu Trùng sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),who->get_save("trungsinh"),cap,chp,200,cd/10,tien,who->get_save("trungsinh")+1,id,id,id,id,id,id));	
		else 
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf("%s :\nNgươi hiện tại đã trùng sinh đến giới hạn, ta nhìn thấy võ công của ngươi đã lên một đỉnh cao mới, hy vọng ngươi có thể vì võ lâm chính nghĩa góp sức chống lại thế lực yêu quái và bảo vệ dân chúng !\n"
		ESC "Bảng xếp hạng Trùng sinh\ntalk %x# gift.3\n"
		ESC "Nhận danh hiệu Trùng sinh\ntalk %x# gift.54\n"
		ESC"Rời khỏi",get_name(),id,id,id,id,id,id));
}

void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,chp, cd, cap, tien;
	object who,item,*nEquip;
	string *nTmp,cFile,cTmp,dh;
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
       	case 1:
			break;
		case 2:
				if ( who->get_save("trungsinh")>=10 )
				{
        		send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), me->get_name()+":\n Ngươi đã Chuyển Sinh tới giới hạn rồi !\n"ESC"Rời khỏi.");
        		return;
				}
			nEquip = who->get_all_equip();
				if ( nEquip[WEAPON_POSITION]!=0 || nEquip[HEAD_POSITION]!=0 || nEquip[NECK_POSITION]!=0 ||
				nEquip[ARMOR_POSITION]!=0 || nEquip[WAIST_POSITION]!=0 || nEquip[BOOTS_POSITION]!=0 )
				{
				send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), me->get_name()+":\n Ngươi hãy tháo Trang bị và Vũ khí ra rồi hãy đến tìm ta !\n"ESC"Rời khỏi.");
        		return;
				}	
	if(who->get_save("trungsinh")==0) { chp = 500; cd = 5000; cap = 100; tien = 300000; dh = "Y001"; }
	else if(who->get_save("trungsinh")==1) { chp = 1000; cd = 6000; cap = 100; tien = 500000; dh = "Y001"; }
	else if(who->get_save("trungsinh")==2) { chp = 1500; cd = 7000; cap = 100; tien = 800000; dh = "Y001"; }
	else if(who->get_save("trungsinh")==3) { chp = 2000; cd = 8000; cap = 100; tien = 1000000; dh = "Y010"; }
	else if(who->get_save("trungsinh")==4) { chp = 2500; cd = 9000; cap = 100; tien = 1500000; dh = "Y010"; }
	else if(who->get_save("trungsinh")==5) { chp = 3000; cd = 10000; cap = 100; tien = 2000000; dh = "Y010"; }
	else if(who->get_save("trungsinh")==6) { chp = 5000; cd = 11000; cap = 100; tien = 2500000; dh = "Y015"; }
	else if(who->get_save("trungsinh")==7) { chp = 8000; cd = 12000; cap = 100; tien = 3000000; dh = "Y015"; }
	else if(who->get_save("trungsinh")==8) { chp = 12000; cd = 13000; cap = 100; tien = 3500000; dh = "Y015"; }
	else if(who->get_save("trungsinh")==9) { chp = 15000; cd = 15000; cap = 100; tien = 4000000; dh = "Y025"; }		
				if ( who->get_level() < cap )
				{
				send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), sprintf(me->get_name()+":\n Cấp bậc của ngươi chưa đạt %d cấp, không thể trùng sinh !\n"ESC"Rời khỏi.",cap));
        		return;
				}
				else if ( who->get_cash() < tien )
				{
				send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), sprintf(me->get_name()+":\n Ngươi không có đủ %d lượng, không thể trùng sinh !\n"ESC"Rời khỏi.",tien));
        		return;
				}
				else if ( who->get_fam_contribute() < chp )
				{
				send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), sprintf(me->get_name()+":\n Ngươi không có đủ %d cống hiến môn phái, không thể trùng sinh !\n"ESC"Rời khỏi.",chp));
        		return;
				}
				else if ( who->get_bonus() < cd )
				{
				send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), sprintf(me->get_name()+":\n Ngươi không có đủ %d điểm công đức, không thể trùng sinh !\n"ESC"Rời khỏi.",cd/10));
        		return;
				}
				else if ( who->get_strength() < 200 )
				{
				send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), sprintf(me->get_name()+":\n Ngươi không có đủ %d điểm thể lực, không thể trùng sinh !\n"ESC"Rời khỏi.",200));
        		return;
				}
			who->add_cash(-tien);
			who->add_bonus(-cd);
			who->set_fam_contribute(who->get_fam_contribute()-chp);
			who->add_strength(-200);
			who->add_save("trungsinh",1);	
			send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), sprintf(me->get_name()+":\n Chúc mừng ngươi đã trùng sinh đến lần thứ %d !\n"ESC"Rời khỏi.",who->get_save("trungsinh")));
			USER_D->user_channel(sprintf(HIG "Chúc mừng "HIC "%s" HIG " đã Trùng Sinh lần thứ "HIC "%d "HIG " . ", who->get_name(),who->get_save("trungsinh") ));
			who->set_level(who->get_level()-90);
			who->count_gift();
			who->add_gift_point(50);
			"/sys/party/bxh_ts"->update_bxh_cap(who);
			who->add_title(dh);
			who->show_title(dh);
			return 0;
			break;
		case 3:
			"/sys/party/bxh_ts"->bxh_cap(who,me);
			break;
		case 54:
		if(who->get_save("trungsinh")<1)
		{
			send_user(who,"%c%c%w%s",':',3, me->get_char_picid(), me->get_name()+":\n Ngươi chưa Trùng Sinh, không thể nhận danh hiệu !\n"ESC"Rời khỏi.");
			return;
		}
		if(who->get_save("trungsinh")<4) { who->add_title("Y001"); who->show_title("Y001"); }
		else if(who->get_save("trungsinh")<7) { who->add_title("Y010"); who->show_title("Y010"); }
		else if(who->get_save("trungsinh")<10) { who->add_title("Y015"); who->show_title("Y015"); }
		else if(who->get_save("trungsinh")<20) { who->add_title("Y025"); who->show_title("Y025"); }
		"/sys/party/bxh_ts"->update_bxh_cap(who);
		break;
				
		}
}
