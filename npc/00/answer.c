#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <time.h>

#define ANSWER_TEMPLATE "quest/template"
inherit OFFICER;
void do_answer1(string arg);//回答问题模板
// 函数：获取人物造型
int get_char_picid() { return 0700; }

// 函数：构造处理
void create()
{
        set_name( "Sư Tử Thạch Anh" );
		set_real_name( "Hiểu Biết Sâu Rông" );

        set_2( "talk", ([
                "answer"	: (: do_answer1:),
        ]));      
        setup();
}

// 函数：对话处理
void do_look( object who )
{
        object me = this_object();
        string tmp;
        int id = getoid(me);
 	tmp=sprintf(ESC"Trả lời câu hỏi của Sư Tử\ntalk %x# answer.2\n",getoid(me));
	send_user( who, "%c%s", ':', me->get_name() + "：\n"+"So với ta, kẻ ngu đần là kẻ xấu xí, kẻ chưa có kiến thức thì chưa xấu xí! Ta là Sư Tử Thạch Anh - ta biết mọi sự việc trong Chiến Quốc Tâm Diện! Nếu như ngươi có thể đối đáp với ta 10 vấn đề, ta sẽ cho ngươi phần thưởng xứng đáng!\n" +
        tmp +
        ESC "Hủy bỏ\nCLOSE\n" );
}
void do_answer1(string arg)
{
	int day;
	mixed mxTime;
	object player = this_player();
	day = player->get_save_2("question.day");
	mxTime = localtime(time());
	if(mxTime[TIME_YDAY]!= day)
	{
		ANSWER_TEMPLATE->clear_tags(player);
		player->set_save_2("question.day",mxTime[TIME_YDAY]);//记录回答问题的第几天。
	}
	ANSWER_TEMPLATE->do_answer2(this_object(),arg);		
}
