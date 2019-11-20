#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 2006; }

// 函数：构造处理
void create()
{
        set_city_name("");
        set_name( "Bảng Xếp Hạng 8/3" );

        setup();
}
void do_look(object who)
{
	object me=this_object();
	"sys/bxh_tangqua"->tangqua(who, me);
}