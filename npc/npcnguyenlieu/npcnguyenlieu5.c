
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
        set_name("Bán Nguyên Liệu 5");
        set_city_name("Vô gia cư");

        set_2( "good", ([
				"01" : "/item/stuff/0105",
				"02" : "/item/stuff/0106",
				"03" : "/item/stuff/0107",
				"04" : "/item/stuff/0108",
				"05" : "/item/stuff/0109",
				"06" : "/item/stuff/0110",
				"07" : "/item/stuff/0111",
				"08" : "/item/stuff/0112",
				"09" : "/item/stuff/0113",
				"10" : "/item/stuff/0114",
				"11" : "/item/stuff/0115",
				"12" : "/item/stuff/0116",
				"13" : "/item/stuff/0117",
				"14" : "/item/stuff/0118",
				"15" : "/item/stuff/0119",
				"16" : "/item/stuff/0120",
				"17" : "/item/stuff/0121",
				"18" : "/item/stuff/0122",
				"19" : "/item/stuff/0123",
				"20" : "/item/stuff/0124",
				"21" : "/item/stuff/0125",
				"22" : "/item/stuff/0126",
				"23" : "/item/stuff/0127",
				"24" : "/item/stuff/0128",				
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