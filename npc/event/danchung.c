#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 0450; }
void do_bonus();
int *ta = ({"Trái Quýt","Chuối","Trái Lê","Trái Táo","Khoai Lang","Gạo Kê"});
// 函数：构造处理
void create()
{
        set_name("Dân Bị Nạn");
        set_2( "talk", ([
                 "bonus"         : (: do_bonus :),
        ]) );

        setup();

}
void do_look( object who )
{
	send_user( who, "%c%c%w%s", ':',3,0450,"Dân Bị Nạn:\n Xin giúp đỡ tôi, xin cho tôi thấy tấm lòng hảo tâm ấp áp của ngài #49#25\n"+
		sprintf(ESC"Ta đồng ý giúp đỡ ngươi\ntalk %x# bonus\n",getoid(this_object())) +
		ESC"Rời khỏi");
}
void do_bonus()
{
	int a;
	object npc;
	object who=this_player(),me=this_object();
			if ( who->get_level()<20 )
			{
				send_user(who,"%c%c%w%s",':',3,0450,"Dân Bị Nạn:\n Thật xin lỗi ngài, tôi thấy ngài vẫn còn nhỏ, làm sao giúp được tôi, khi nào ngài đạt cấp 20 thì đến gặp tôi nhé #2 \n");
				return 0;
			}
	a=random(6);
		npc=new("npc/event/danbinan");
		npc->set("danbinan",who);
		npc->set("danbinan2",who->get_number());
		npc->set("thucan",ta[a]);
		npc->set( "birthday", time() );
		npc->set_owner(who);
		npc->add_to_scene(get_z(me),get_x(me),get_y(me),get_d(me));
		me->remove_from_scene();
		destruct(me);	
}


