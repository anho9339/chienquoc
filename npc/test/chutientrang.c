
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 7003; }
int is_self_look() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5302; }

// 函数：构造处理
void create()
{
        set_name(HIB"Chủ Tiền Trang");
		set_real_name("Thuê Cánh Phi Phong");

        set_2( "good", ([
				"01" : "/item/ppvacanh/phiphong/phiphongthue",
				"02" : "/item/ppvacanh/phiphong/phiphongthue2",
				"03" : "/item/ppvacanh/phiphong/phiphongthue3",
				"04" : "/item/ppvacanh/canh/canhthue",
				"05" : "/item/ppvacanh/canh/canhthue2",
				"06" : "/item/ppvacanh/canh/canhthue3",
				
        ]) );
        setup();
}
void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Hoan nghênh bạn đến với Cửa tiệm Tiền Trang, nếu bạn muốn thuê một trang bị Phi Phong hoặc Cánh loại tốt, thì có thể đến tìm ta ! \nMỗi lần thuê đều phải tiêu hao một số \"Hoả Phù\" nhất định ! \nHoả Phù có được khi đổi tại Sứ giả Nhiệm vụ hoặc mua ở Bảo Khố \n"
		ESC HIY"Thuê Phi Phong và Cánh\nlist5 %x#\n"
		ESC"Rời khỏi",get_name(),id));	
}