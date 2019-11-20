
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
        set_name(HIB"Cửa Tiệm Bảo Khố");
       set_real_name(HIR "Vô Tiền");

        set_2( "good", ([
		"01" : "/item/sell/0200",
		"02" : "/item/sell/0201",
		"03" : "/item/sell/0202",
		"04" : "/item/sell/0015",
		"05" : "/item/sell/0016",
		"06" : "/item/sell/0017",
		"07" : "/item/sell/0018",
		"08" : "/item/sell/0019",
		"09" : "/item/sell/0026",
		"10" : "/item/sell/0027",
		"11" : "/item/test2/TuiThanThuHoangDao",
	//	"12" : "/item/test2/TuiThanThu",
		"12" : "/item/test2/Tui12ConGiap",
		"13" : "/item/sell/0060",
	//	"13" : "/item/test2/TanNienLeBao",
	//	"16" : "/item/test2/TuiQuaVoSong",
	//	"14" : "/item/TuiLinhThach/NgauNhien/4",//"/item/test2/TuiLinhThach",
	//	"18" : "/item/test2/NangCap/vktukim",
	//	"14" : "/item/test2/TuiHoaPhu",
	//	"13" : "/item/test2/HatGiong2",
		"14" : "/item/mop/9988",
		"15" : "/item/stuff/0323",
	//	"24" : "/item/sell/6004",
				
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