
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 7009; }
int is_self_look() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5105; }

// 函数：构造处理
void create()
{
        set_name("NPC Đổi Fashion");
		set_real_name("Huyền Băng");

        set_2( "good", ([
				"01" : "/item/ngoai_trang/nam/1",
				"02" : "/item/ngoai_trang/nam/2",
				"03" : "/item/ngoai_trang/nam/3",
				"04" : "/item/ngoai_trang/nam/4",
				"05" : "/item/ngoai_trang/nam/5",
				"06" : "/item/ngoai_trang/nu/1",
				"07" : "/item/ngoai_trang/nu/2",
				"08" : "/item/ngoai_trang/nu/3",
				"09" : "/item/ngoai_trang/nu/4",
				"10" : "/item/ngoai_trang/nu/5",
				
        ]) );
        setup();
}
void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Ta là người cung cấp trang phục cho các ngươi, hãy mang Nhẫn Huyền Băng đến cho ta và lựa đồ ngươi thích!\n"
		ESC HIY"Đổi vật phẩm\nlist11 %x#\n"
		ESC"Rời khỏi",get_name(),id));	
}