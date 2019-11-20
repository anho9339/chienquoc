
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
int get_char_picid() { return 9815; }

// 函数：构造处理
void create()
{
        set_name(HIB"Cửa Tiệm Tinh Thạch");
        set_real_name(HIR "Vô Hậu");

        set_2( "good", ([
		"01" : "/item/sell/9301",
		"02" : "/item/sell/9302",
		"03" : "/item/sell/9303",
		"04" : "/item/sell/9304",
		"05" : "/item/sell/9305",
		"06" : "/item/sell/9306",
		"07" : "/item/sell/9307",
		"08" : "/item/sell/9308",
		"09" : "/item/sell/9309",
		"10" : "/item/sell/9310",
				
        ]) );
        setup();
}
void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Bạn muốn mua vật phẩm không ? \n(Chỉ có thể mua bằng Kim Nguyên Bảo ) \n \nHiện bạn đang có "HIB"%d "NOR "Kim Nguyên Bảo \n"
		ESC HIY"Mua vật phẩm\nlist3 %x#\n"
		ESC"Rời khỏi",get_name(),"sys/sys/test_db"->get_yuanbao(who)/10,id));	
}