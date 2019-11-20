
// 自动生成:/make/npc/make0001

#include <npc.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;

// 函数:Quản Khố
int is_banker() { return 1; }
void do_welcome(string arg);
// 函数:获取人物造型
int get_char_picid() { return 5301; }

// 函数:构造处理
void create()
{
        set_name("Quản Khố");
        set_real_name("Quản Khố");
		set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));

        setup();
}

// 函数:对话处理
void do_look( object who )
{
	int i, size, exist;
	string tmp="", *line, *data;
	
	//"/quest/help"->send_help_tips(who, 4);
    //    PAWN_CMD->main( who, sprintf( "%x# %d", getoid( this_object() ), 0 ) );    // who->get("pawn#") + 1
		send_user( who, "%c%c%w%s", ':', 3, get_char_picid(), 
                sprintf(" %s :\n "+"/quest/word"->get_normal_word(this_object())+"\n"     
						ESC "Ta muốn sử dụng kho\npawn %x# 1\n"
			ESC "Ta muốn mở rộng kho của ta\npawn expand %x# 0\n"
			ESC HIG"Đặt mật khẩu bảo vệ Kho\ntalk %x# welcome.100\n"
			ESC HIG"Đổi mật khẩu bảo vệ Kho\ntalk %x# welcome.101\n"
			ESC HIG"Xoá mật khẩu bảo vệ Kho\ntalk %x# welcome.102\n"
                        ESC "Ta chỉ xem qua\nCLOSE\n",get_name(), getoid(this_object()), getoid(this_object()), getoid(this_object()), getoid(this_object()), getoid(this_object()) ) );
	"/quest/help"->send_help_tips(who, 4);
}
void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,size,p,amount;
	object who,*inv,item;

	who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {	
		case 1:
			break;
		case 100:
			if ( who->get_save("passquankho") )
			{
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn đã có thiết lập Mật khẩu bảo vệ Kho rồi, hãy nhập đúng Mật khẩu bảo vệ Kho và chọn Đổi Mật khẩu !\n"ESC"Xác nhận");
				return;
			}
send_user( who, "%c%c%d%s", '?', 16, 12, "Quản Khố :\nXin nhập Mật khẩu bảo vệ     Kho : \n(giới hạn 12 ký tự) \n" ESC "quankho + %s\n" );
			break;
		case 101:
			if ( !who->get_save("passquankho") )
			{
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn chưa đặt Mật khẩu bảo vệ Kho, không thể sử dụng chức năng này!\n"ESC"Xác nhận");
				return;
			}
			if ( who->get_save("ndmkk") < 1 )
			{
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn phải nhập Mật khẩu bảo vệ cũ vào mới được đặt Mật khẩu Bảo vệ Kho mới !\n"ESC"Xác nhận");
				return;
			}
send_user( who, "%c%c%d%s", '?', 16, 12, "Quản Khố :\nXin nhập Mật khẩu bảo vệ     Kho mới : \n(giới hạn 12 ký tự) \n" ESC "quankho + %s\n" );
			break;
		case 102:
			if ( !who->get_save("passquankho") )
			{
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn chưa đặt Mật khẩu bảo vệ Kho, không thể sử dụng chức năng này!\n"ESC"Xác nhận");
				return;
			}
			if ( who->get_save("ndmkk") < 1 )
			{
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn phải nhập Mật khẩu bảo vệ Kho vào mới có thể Xoá Mật khẩu bảo vệ Kho !\n"ESC"Xác nhận");
				return;
			}
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Quản Khố:\nBạn chắc chắn phải xoá Mật khẩu bảo vệ Kho không ?\n"
ESC"Xác nhận\ntalk %x# welcome.103\n"
ESC"Huỷ bỏ\nCLOSE\n",getoid(me)));			
			break;
		case 103:
			if ( !who->get_save("passquankho") )
			{
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn chưa đặt Mật khẩu bảo vệ Kho, không thể sử dụng chức năng này!\n"ESC"Xác nhận");
				return;
			}
			if ( who->get_save("ndmkk") < 1 )
			{
send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),"Quản Khố:\nBạn phải nhập Mật khẩu bảo vệ Kho vào mới có thể Xoá Mật khẩu bảo vệ Kho !\n"ESC"Xác nhận");
				return;
			}			
			who->delete_save("passquankho");
			who->set_save("ndmkk",0);
			send_user(who, "%c%s",';', "Bạn đã xoá Mật khẩu bảo vệ Kho thành công !");
			break;	
	}
}