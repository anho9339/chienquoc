
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
//int is_item_seller() { return 1; }
int is_seller() { return 7001; }
int is_self_look() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5402; }

// 函数：构造处理
void create()
{
        set_name("Cửa Tiệm Tinh Nguyên Đơn");
        set_city_name("Chu Quốc");

        set_2( "good", ([
				"01" : "/item/test2/TND/14",
				"02" : "/item/test2/TND/15",
				"03" : "/item/test2/TND/16",
				"04" : "/item/test2/TND/17",
				"05" : "/item/test2/TND/18",
				"06" : "/item/test2/TND/19",
				"07" : "/item/test2/TND/20",
				"08" : "/item/test2/TND/21",
				"09" : "/item/test2/TND/22",
				"10" : "/item/test2/TND/23",
				"11" : "/item/test2/TND/24",
				"12" : "/item/test2/TND/25",
				"13" : "/item/test2/TND/26",
				
        ]) );
        setup();
}
void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn mua Tinh Nguyên Đơn không ? \n(Chỉ có thể mua bằng Kim Nguyên Bảo ) \n \nHiện bạn đang có "HIB"%d "NOR "Kim Nguyên Bảo \n"
		ESC HIY"Mua Tinh Nguyên Đơn\nlist3 %x#\n"
		ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id));	
}