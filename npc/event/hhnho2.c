#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <equip.h>
#include <time.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

inherit OFFICER;
// 函数：获取人物造型
int get_char_picid() { return 3032; }
void do_gift( string arg );
// 函数：构造处理
void create()
{
        set_name("");
		set_2( "talk", ([
				"gift"          : (: do_gift :),
        ]));
        setup();
}


void do_look(object who)
{
	int id = getoid( this_object() );
		if ( this_object()->get_save("tuoinuochh") == who->get_number() ) {
		send_user(who,"%c%c%w%s",':',3,0,sprintf("Xác nhận phải dùng Nước Ngọt để tưới tôi không ? \n"
		ESC "Xác nhận\ntalk %x# gift.2\n"
		ESC"Rời khỏi",id));
		}
		else {
		send_user(who,"%c%c%w%s",':',3,0,sprintf("Ngươi đâu phải là người trồng ra ta ! \n"
		ESC "Ta biết rồi\ntalk %x# gift.100\n"
		ESC"Rời khỏi",id));
		}
}
void do_gift( string arg )
{
        object me = this_object();
        __FILE__ ->do_gift2(me, arg);
}

void do_gift2( object me, string arg )
{
	int flag,id,i,p,iTime,iDay,iGio,rate,l,tien,z,x,y,x0,y0,exp,level;
	object who,item,item1,item2,item3,npc;
	string *nTmp,cFile,cTmp,cFinal,result;
	mixed *mxTime;
	iTime = time();
	mxTime = localtime(iTime);     
	iDay = mxTime[TIME_YDAY];
	iGio = mxTime[TIME_HOUR];
	
        who = this_player();
		id = getoid(me);
        flag = to_int(arg);
        who->set_time( "talk",  0);
		rate = random(100);
        switch(flag)
        {
       	case 1:
			break;
		case 2:
				if ( me->get_save("tuoinuochh") != who->get_number() ) {
				write_user(who, ECHO"Cây này không phải của bạn trồng" );
				return 0;
				}
			if ( TASK_LEGEND_D->check_task_item_amount(who,"Nước Ngọt") < 1 )
			{
                write_user(who, ECHO "Bạn không có Nước Ngọt !");
                return ;
			}
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
				write_user(who, ECHO "Hành trang không đủ 1 ô trống !");
				return ;
			}
			TASK_LEGEND_D->check_task_item1(who,"Nước Ngọt",1);
			me->remove_from_scene();
			z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
			p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK);
			if( !p )
        	return 0;
			x = p / 1000;  y = p % 1000;
			npc = new("npc/event/hhlon");
			if ( !npc )
			return 0;
			who->set_save("trongcayabcxyz",npc);
			who->set_save("trongcayabcxyz2",time());
		//	npc->set_save("caytohh",who->get_number());
			npc->add_to_scene( z, x, y);

				item=new("item/event/hhtt");
				p=item->move2(who,-1);
				item->add_to_user(p);
			send_user(who,"%c%s",';', sprintf("Bạn đã tưới nước cho cây, bạn nhận được %s, xin chúc mừng !", item->get_name()));
			break;
		}
}		