
#include <npc.h>
#include <ansi.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 0752; }

// 函数：构造处理
void create()
{
        set_name("Oan Quỷ");
        setup();
	//	set_head_color(0x49af);
}

// 函数：对话处理
void do_look( object who )
{
	string result,cmd;
	int i=random(8);
        switch(i)
        {
	        case 0:
			cmd="Oan ức quá, oan ức quá huhuhuhu!";
		break;
	        case 1:
			cmd="Huhuhuhu đừng nhìn ta nữa, ngươi thật kinh tởm!";
		break;
	        case 2:
			cmd="Không phải cứ thích ngắm ta là ngắm đâu huhu..";
		break;
		case 3:
			cmd="Sao ai cũng xấu xí hết vậy huhu..";
		break;
		case 4:
			cmd="Huhu ai ai cũng giống nhau, tìm đâu ra người đẹp trai đây..";
		break;
		case 5:
			cmd="Huhuhu ta là oan quỷ";
		break;
		case 6:
			cmd="Hôm nay là ngày gì mà hồn ma vào thành tấp nập vậy huhu";
		break;
		case 7:
			cmd="Đồ quỷ sứ mà! Ngươi trông thật kinh tởm huhuhu";
		break;
	}
        result = get_name() + "：\n    "+cmd+"\n"+
       		ESC "Xác nhận\nCLOSE\n";
        send_user( who, "%c%c%w%s", ':', 3, 0752, result );  
}
