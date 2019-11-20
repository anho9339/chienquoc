
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 4; }

// 函数：获取人物造型
int get_char_picid() { return 9972; }

// 有自己的do_look函数
int is_self_look() { return 1; }

void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Bán Nguyên Liệu 3");
        set_city_name("Vô gia cư");

        set_2( "good", ([
				"01" : "/item/stuff/0057",
				"02" : "/item/stuff/0058",
				"03" : "/item/stuff/0059",
				"04" : "/item/stuff/0060",
				"05" : "/item/stuff/0061",
				"06" : "/item/stuff/0062",
				"07" : "/item/stuff/0063",
				"08" : "/item/stuff/0064",
				"09" : "/item/stuff/0065",
				"10" : "/item/stuff/0066",
				"11" : "/item/stuff/0067",
				"12" : "/item/stuff/0068",
				"13" : "/item/stuff/0069",
				"14" : "/item/stuff/0070",
				"15" : "/item/stuff/0071",
				"16" : "/item/stuff/0072",
				"17" : "/item/stuff/0073",
				"18" : "/item/stuff/0074",
				"19" : "/item/stuff/0075",
				"20" : "/item/stuff/0076",
				"21" : "/item/stuff/0077",
				"22" : "/item/stuff/0078",
				"23" : "/item/stuff/0079",
				"24" : "/item/stuff/0080",				
        ]) );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
        setup();
}

// 函数：对话处理
void do_look( object who )
{
	object me = this_object();
	string result;
	result = sprintf("%s：\n    "+"/quest/word"->get_normal_word(me)+"\n", me->get_name() );
	result += sprintf(ESC "Bạn muốn mua gì nào？\ntalk %x# welcome.99\n", getoid(me) ) ;        	
	result += sprintf( ESC "Giao dịch\nlist %x#\n" ESC "Rời khỏi\nCLOSE\n", getoid(me) ) ;        	
	send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(), result );
}

void do_welcome( string arg )
{
        object me = this_object();
        "/npc/base/0005"->do_welcome2(me, "99");
}