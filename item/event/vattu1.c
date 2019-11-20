#include <ansi.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;
int get_item_color() {return 2 ;}
// 函数：构造处理
void create()
{
        set_name( "Vật Tư (1)" );
		set_picid_1(4985);
        set_picid_2(4985);
        set_value(10);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Vật sở hữu đặc biệt, thu thấp đủ 5 loại có thể đổi thưởng.";
}
// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object gift )
{
	int p, nhat;
	object item;
	nhat = me->get_gender()==1?100:110;
			if ( TASK_LEGEND_D->check_task_item_amount(me,"Vật Tư (2)") < 1 ||
				TASK_LEGEND_D->check_task_item_amount(me,"Vật Tư (3)") < 1 ||
				TASK_LEGEND_D->check_task_item_amount(me,"Vật Tư (4)") < 1 ||
				TASK_LEGEND_D->check_task_item_amount(me,"Vật Tư (5)") < 1 )
			{
				notify( "Không đủ 5 loại Vật Tư." );
				return ;	
			}
		if(USER_INVENTORY_D->get_free_count(me) < 2 )
		{
			notify( "Hành trang không đủ 2 chỗ trống." );
			return 0;
		}
		me->add_save("vattuabc",1);
		"sys/party/bxh_vattu"->update_bxh_vattu(me);
		gift->add_amount(-1);
		TASK_LEGEND_D->check_task_item1(me,"Vật Tư (2)",1);
		TASK_LEGEND_D->check_task_item1(me,"Vật Tư (3)",1);
		TASK_LEGEND_D->check_task_item1(me,"Vật Tư (4)",1);
		TASK_LEGEND_D->check_task_item1(me,"Vật Tư (5)",1);
		if ( random100() < 3 )
		{
			item=new(sprintf("item/93/%d",9301+random(10)));
			item->set_level(3);
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được "+item->get_name()+" !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được "+item->get_name()+" !");
		}
		else if ( random100() < 8 )
		{
			item=new(sprintf("item/93/%d",9301+random(10)));
			item->set_level(2);
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được "+item->get_name()+" !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được "+item->get_name()+" !");
		}
		else if ( random100() < 30 )
		{
			item=new("item/test/chenbac");
			item->set_amount(2);
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được 2 Chén Bạc !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được 2 Chén Bạc !");
		}
		else if ( random100() < 40 )
		{
			item=new("item/sell/0008");
			item->set_amount(2);
			p=item->move2(me,-1);
			item->add_to_user(p);
			item=new("item/sell/0010");
			item->set_amount(2);
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được 2 Trị Dược và 2 Phục Dược !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được 2 Trị Dược và 2 Phục Dược !");
		}
		else if ( random100() < 50 )
		{
			item=new(sprintf("item/sell/%d032",random(2)));
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được "+item->get_name()+" !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được "+item->get_name()+" !");
		}
		else if ( random100() < 60 )
		{
			item=new("item/test2/TuiQuaVoSong");
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được "+item->get_name()+" !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được "+item->get_name()+" !");
		}
		else if ( random100() < 75 )
		{
			item=new("item/test2/TuiPhapBao");
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được "+item->get_name()+" !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được "+item->get_name()+" !");
		}
		else if ( random100() < 85 )
		{
			item=new(sprintf("item/100/%d%d",nhat,51+random(8)));
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được "+item->get_name()+" !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được "+item->get_name()+" !");
		}
		else
		{
			item=new("item/08/0001");
			item->set_amount(2);
			p=item->move2(me,-1);
			item->add_to_user(p);
			send_user(me,"%c%s",';', "Bạn nhận được 2 Chiến Quốc Lệnh !");
			CHAT_D->sys_channel(0,"Bằng hữu "+me->get_name()+" sử dụng Vật Tư nhận được 2 Chiến Quốc Lệnh !");
		}
	return 0;
}