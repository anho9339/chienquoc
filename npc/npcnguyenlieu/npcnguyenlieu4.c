
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
        set_name("Bán Nguyên Liệu 4");
        set_city_name("Vô gia cư");

        set_2( "good", ([
				"01" : "/item/stuff/0081",
				"02" : "/item/stuff/0082",
				"03" : "/item/stuff/0083",
				"04" : "/item/stuff/0084",
				"05" : "/item/stuff/0085",
				"06" : "/item/stuff/0086",
				"07" : "/item/stuff/0087",
				"08" : "/item/stuff/0088",
				"09" : "/item/stuff/0089",
				"10" : "/item/stuff/0090",
				"11" : "/item/stuff/0091",
				"12" : "/item/stuff/0092",
				"13" : "/item/stuff/0093",
				"14" : "/item/stuff/0094",
				"15" : "/item/stuff/0095",
				"16" : "/item/stuff/0096",
				"17" : "/item/stuff/0097",
				"18" : "/item/stuff/0098",
				"19" : "/item/stuff/0099",
				"20" : "/item/stuff/0100",
				"21" : "/item/stuff/0101",
				"22" : "/item/stuff/0102",
				"23" : "/item/stuff/0103",
				"24" : "/item/stuff/0104",				
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