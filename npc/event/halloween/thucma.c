
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 0902; }

// 函数：构造处理
void create()
{
        set_name("Thực Ma");
        setup();
	//	set_head_color(0x4213);
}

// 函数：对话处理
void do_look( object who )
{
	string result,cmd;
	int i=random(8);
        switch(i)
        {
	        case 0:
			cmd="Hahaha , cuối cùng ta cũng được xuất hiện trong thành!";
		break;
	        case 1:
			cmd="Trời ơi, sao con người ai cũng ăn mặc giống ta vậy!";
		break;
	        case 2:
			cmd="Thành trì đâu đâu cũng là ma quỷ?";
		break;
		case 3:
			cmd="Ngộ thật, bọn người này điên hết rồi sao!";
		break;
		case 4:
			cmd="Sao bạn bè ta lại ở hết trong thành trì vậy?";
		break;
		case 5:
			cmd="Hôm nay nghe nói là ngày mà ta tới chung vui với loài người!";
		break;
		case 6:
			cmd="Hả? Ma Quỷ được ăn uống thoải mái sao?";
		break;
		case 7:
			cmd="Ngươi sao cứ ngắm nhìn ta hoài vậy, ta giống ngươi mà!";
		break;
	}
        result = get_name() + "：\n    "+cmd+"\n"+
       		ESC "Xác nhận\nCLOSE\n";
        send_user( who, "%c%c%w%s", ':', 3, 0902, result );  
}

