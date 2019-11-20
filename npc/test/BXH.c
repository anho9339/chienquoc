#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>

inherit OFFICER;

void do_welcome(string arg);
// 函数：获取人物造型
int get_char_picid() { return 2006; }

// 函数：构造处理
void create()
{
        set_city_name("");
        set_name( "Bảng Xếp Hạng" );
        set_2("talk",(["welcome":(:do_welcome:)]));

        setup();
}
void do_look(object who)
{
	string result;
	object me=this_object();
	result=sprintf("                   Hoan nghênh đến với Bảng xếp Hạng Chiến Quốc\n");
	result+=sprintf(ESC HIY"Bảng xếp hạng Cấp bậc\ntalk %x# welcome.1\n",getoid(me));
	result+=sprintf(ESC HIY"Bảng xếp hạng Trồng cây\ntalk %x# welcome.2\n",getoid(me));
	result+=sprintf(ESC HIY"Bảng xếp hạng Vật Tư\ntalk %x# welcome.3\n",getoid(me));
	send_user(who,"%c%c%w%s",':',3,get_char_picid(),result);
}

void do_welcome(string arg)
{
	object me=this_object();
	__FILE__->do_welcome2(me,arg);
}

void do_welcome2(object me ,string arg)
{
	int flag,i,size,time;
	string result,*name;
	mapping org;
	object who,char;
	
	who=this_player();
	who->set_time("talk",0);
	if(!arg) return;
	flag=to_int(arg);
	switch(flag)
	{
		case 1:
			"sys/party/bxh_cap"->bxh_cap(who, me);
			break;
		case 2:
			"sys/party/bxh_trongcay"->bxh_trongcay(who, me);
			break;
		case 3:
			"sys/party/bxh_vattu"->bxh_vattu(who, me);
			break;	
		
	}
}