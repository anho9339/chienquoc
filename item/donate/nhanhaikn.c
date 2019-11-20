#include <ansi.h>
#include <skill.h>
inherit COMBINED;
inherit ITEM;

int get_item_value() {return 450 ;}
int get_item_value_2() {return 380 ;}
int get_item_number() {return 10001006 ;}
int get_item_color() {return 1 ;}

// 函数：nh9h构造处理
void create()
{
        set_name("Chiến quốc lệnh");
        set_picid_1(0096);
        set_picid_2(0096);
        set_value(100);
        set_amount(1);
        set_record(1);
}
int is_usable() {return 1;}
// 函数：nh9h获取描述
string get_desc() 
{ 
        return "Lệnh bài thần kỳ, sau khi sử dụng,\ntrong 1 tiếng đồng hồ bạn có thể sẽ đạt được Kinh nghiệm nhân đôi khi giết quái vật.\n(Mỗi tuần chỉ có thể sử dụng 25 Chiến Quốc Lệnh.)"; 
}
// 函数：nh9h获取描述(trì tục)加血
string get_loop_desc( object me )
{
	return "1 tiếng thời nội khả thu được song bội kinh nghiệm phần thưởng.";
}
int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	int i,iWeek;
	if ( gone_time( who->get_login_time() )+ who->get_game_time()<who->get_double_time())
	{
		send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("你身上已经有Song bội thời gian存在,你确定要累加它的Hiệu quả phải không?\n"ESC"Xác định\nuse ! %x#\n"ESC"Thủ tiêu",getoid(item))); 
		return 0;
	}
	iWeek = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
	if (who->get_save_2("double_time.week")!=iWeek)
	{
		who->set_save_2("double_time.week", iWeek);
		who->set_save_2("double_time.time", 0);		//双
		who->set_save_2("double_time.time1", 0);	//Chiến quốc lệnh
		who->set_save_2("double_time.time2", 0);	//Tù Và Chiến Quốc
		who->set_save_2("double_time.time3", 0);	//Tù Và Chiến Quốc
		who->set_save_2("double_time.freeze", 0);	//冻结的Song bội thời gian		
	}
	if ( who->get_save_2("double_time.time1") >= 25 )
	{
		send_user(who,"%c%s",'!',"Bạn bổn chu Khả sử dụng Chiến quốc lệnh đã đạt đến sử dụng thượng hạn.");
		return 0;	
	}
	if ( who->get_online_rate() == 50 )
	{
		send_user(who,"%c%s",'!',"Bì lao du hí thời gian cấm chỉ sử dụng Chiến quốc lệnh.");
		return 0;	
	}
	else if ( who->get_online_rate() == 0 )
	{
		send_user(who,"%c%s",'!',"Bất kiện khang du hí thời gian cấm chỉ sử dụng Chiến quốc lệnh.");
		return 0;	
	}
	if (who->get_save_2("double_time.freeze")>3600*18)
	{
		send_user(who,"%c%s",'!',"您冻结的Song bội thời gian超过了18小时");
		return 0;		
	}
	i = gone_time( who->get_login_time() );		
	who->add_save_2("double_time.time1",1);
	
	if (who->get_save_2("double_time.freeze")>0)
	{
		who->add_save_2("double_time.freeze", 3600);
		send_user( who, "%c%c%d%s", 0x43, 10, 0, HIY "你的双倍经验时间已经寄存到神仙爷爷处." );
	        "/inh/user/mail"->sys_mail(who->get_id(), who->get_number(), "因为你已经Sử dụng 双倍经验 đích đông kết,因此使用Chiến quốc lệnh后得到的双倍经验时间也会一并寄存在"HIR"Chu quốc（291,175）Hoặc tân thủ thôn（91,164）Đích thần tiên gia gia"NOR"Xứ. Thỉnh nhĩ vụ tất ký đắc tại"HIR"Chu nhật đích23：59Phận tiền giải trừSong bội thời gian đích đông kết"NOR",Phủ tắc ký tồn đích song bội kinh nghiệm thời gian hội bị hệ thống hồi thu trạo.");
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Du hí phụ trợ" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Song bội thời gian" );
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);				        
		return 1;
	}	
	if ( i+ who->get_game_time()<who->get_double_time())
		who->set_double_time(who->get_double_time()+3600);
	else
		who->set_double_time(i+ who->get_game_time()+3600);	
	send_user( who, "%c%w%w%c", 0x81, 9998, 3600, EFFECT_GOOD );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Du hí phụ trợ" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Song bội thời gian" ); 
	"/sys/task/task"->send_task_intro(who, 1, 1, 1);		
	return 1;
}

// 函数：nh9h使用Hiệu quả 
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// 函数：nh9h使用Hiệu quả (在线更新)
int confirm_use_callout( object who, object item )
{
	int i,iWeek;

	iWeek = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
	if (who->get_save_2("double_time.week")!=iWeek)
	{
		who->set_save_2("double_time.week", iWeek);
		who->set_save_2("double_time.time", 0);		//双
		who->set_save_2("double_time.time1", 0);	//Chiến quốc lệnh
		who->set_save_2("double_time.time2", 0);	//Tù Và Chiến Quốc
		who->set_save_2("double_time.time3", 0);	//Tù Và Chiến Quốc
		who->set_save_2("double_time.freeze", 0);	//冻结的Song bội thời gian
	}
	if ( who->get_save_2("double_time.time1") >= 25 )
	{
		send_user(who,"%c%s",'!',"Bạn bổn chu Khả sử dụng Chiến quốc lệnh đã đạt đến sử dụng thượng hạn.");
		return 0;	
	}
	if ( who->get_online_rate() == 50 )
	{
		send_user(who,"%c%s",'!',"Bì lao du hí thời gian cấm chỉ sử dụng Chiến quốc lệnh.");
		return 0;	
	}
	else if ( who->get_online_rate() == 0 )
	{
		send_user(who,"%c%s",'!',"Bất kiện khang du hí thời gian cấm chỉ sử dụng Chiến quốc lệnh.");
		return 0;	
	}
	who->add_save_2("double_time.time1",1);
	if (who->get_save_2("double_time.freeze")>0)
	{
		who->add_save_2("double_time.freeze", 3600);
	        send_user(who, "%c%s", '!', "你的双倍经验时间已经寄存到神仙爷爷处.");
	        "/inh/user/mail"->sys_mail(who->get_id(), who->get_number(), "因为你已经Sử dụng 双倍经验 đích đông kết,因此使用Chiến quốc lệnh后得到的双倍经验时间也会一并寄存在"HIR"Chu quốc（291,175）Hoặc tân thủ thôn（91,164）Đích thần tiên gia gia"NOR"Xứ. Thỉnh nhĩ vụ tất ký đắc tại"HIR"Chu nhật đích23：59Phận tiền giải trừSong bội thời gian đích đông kết"NOR",Phủ tắc ký tồn đích song bội kinh nghiệm thời gian hội bị hệ thống hồi thu trạo.");
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Du hí phụ trợ" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Song bội thời gian" );
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);				        
		return 1;
	}	
	i = gone_time( who->get_login_time() );	
	if ( gone_time( who->get_login_time() )+ who->get_game_time()<who->get_double_time())
		who->set_double_time( who->get_double_time()+3600);
	else
		who->set_double_time(i+ who->get_game_time()+3600);
	send_user( who, "%c%w%w%c", 0x81, 9998, who->get_double_time() - i - who->get_game_time(), EFFECT_GOOD );
	send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"Du hí phụ trợ" ); 
	send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "Song bội thời gian" ); 
	"/sys/task/task"->send_task_intro(who, 1, 1, 1);
	return 1;
}