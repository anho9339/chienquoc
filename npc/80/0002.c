// 自动生成：/make/npc/make-biao

#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <public.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 9715; }
void do_welcome( string arg );

// 函数：构造处理
void create()
{
        set_name("Lý Ẩn Sĩ");
        set_city_name("Chu Quốc");

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));      
	set("mpLegend2",([0:({32*40+6,32*40+9,32*40+12,}),]));
        setup();
}
// 函数：对话处理
void do_look( object who )
{
	string tmp="";
        if ( who->get_legend(TASK_40,5) && !who->get_legend(TASK_40,6) ) 
		tmp += sprintf(ESC HIY "Tù Và Lập Bang\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_40,6) && !who->get_legend(TASK_40,9) ) 
		tmp += sprintf(ESC HIY "Thẻ Tre Bị Mất\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_40,9) && !who->get_legend(TASK_40,12) ) 
		tmp += sprintf(ESC HIY "Sừng Trâu Vàng\ntalk %x# welcome.1\n",getoid(this_object())); 
        if ( who->get_legend(TASK_40,12) && !who->get_legend(TASK_40,13) ) 
		tmp += sprintf(ESC HIY "Thỉnh Cầu Vua Giúp Đỡ\ntalk %x# welcome.1\n",getoid(this_object())); 

        send_user( who, "%c%s", ':', sprintf( " %s :\n Giang hồ phân tranh, mãi mãi không có điểm dừng.Vinh hoa phú quý cũng chỉ là mây khói, sống không tìm ra, chết không thể mang theo, không có giá trị gì cả.\n", get_name())
        + tmp +
        ESC"Rời khỏi"
         );
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}
void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_legend(TASK_40,5) && !who->get_legend(TASK_40,6) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Tay nghề của ta không tệ, nhưng phương pháp chế tạo Tù Và ta đã ghi vào Thẻ tre, nhưng nó đã mất, nếu người có khả năng tìm về ta có thể giúp người chế tạo Tù Và.\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.2\n"ESC"Rời khỏi", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_40,6) && !who->get_legend(TASK_40,7) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Thẻ tre hiện đang trong tay của Tiêu Trụ, hiện tại hắn đang ở Đông Hải Đảo đứng gần những bụi rơm.\n"ESC"Tiếp nhận nhiệm vụ\ntalk %x# welcome.3\n"ESC"Rời khỏi", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_40,7) && !who->get_legend(TASK_40,8) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Nếu như không có Thẻ tre, ta không thể nào nhớ được phương pháp chế tạo Tù Và đâu.\n"ESC"Rời khỏi", me->get_name()));
        	else if ( who->get_legend(TASK_40,8) && !who->get_legend(TASK_40,9) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Chế tạo Tù Và thấy đơn giản, nhưng thật ra cần rất nhiều nguyên liệu.\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.4\n"ESC"Rời khỏi", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_40,9) && !who->get_legend(TASK_40,10) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Tuy rằng người đã giao cho ta Thẻ tre, ta cũng đã nhớ lại phương pháp chế tạo Tù Và, nhưng cái này thật sự khó...ngươi phải đi tới Kênh Trịnh Quốc tìm Sừng Trâu Vàng từ trên người Khổ Dịch mới có hy vọng chế tạo được tù Và, ngươi có đồng ý đi hay không ?.\n"ESC"Tiếp nhận nhiệm vụ\ntalk %x# welcome.5\n"ESC"Rời khỏi", me->get_name(),getoid(me)));
		else if ( who->get_legend(TASK_40,10) && !who->get_legend(TASK_40,11) )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Không có Sừng Trâu Vàng, ta cũng không thể chế tạo Tù Và.\n"ESC"Rời khỏi", me->get_name()));
        	else if ( who->get_legend(TASK_40,11) && !who->get_legend(TASK_40,12) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Đã có Thẻ tre, nếu có thêm Sừng Trâu Vàng ta nghĩ chế tạo Tù Và là đều nhanh chóng.\n"ESC"Hoàn thành nhiệm vụ\ntalk %x# welcome.6\n"ESC"Rời khỏi", me->get_name(),getoid(me)));
        	else if ( who->get_legend(TASK_40,12) && !who->get_legend(TASK_40,13) ) 
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    Bây giờ, việc ngươi cần làm là nhờ một công tượng trong cung rèn đúc Tù Và, ngươi có thể đến tìm Đại Vương của nước ngươi sống và thỉnh cầu Đại Vương giúp đỡ.\n"ESC"Tiếp nhận nhiệm vụ\ntalk %x# welcome.7\n"ESC"Rời khỏi", me->get_name(),getoid(me)));

        	break;

        case 2:
        	if ( who->get_legend(TASK_40,5) && !who->get_legend(TASK_40,6) ) 
        	{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,6);
			who->add_exp(3000);
			who->add_potential(100);
			who->add_cash(2500);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,10,"" );
			send_user(who,"%c%s",';',"Tù Và Lập Bang Kinh nghiệm 3000 Tiềm năng 100 Ngân lượng 2500");
			me->do_welcome(1);
        	}
        	break;   
 	case 3:
        	if ( who->get_legend(TASK_40,6) && !who->get_legend(TASK_40,7) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_40,7);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"Chu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,11,"Thẻ Tre Bị Mất" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ "HIY"Thẻ Tre Bị Mất");
        	}
        	break;  
        case 4:
        	if ( who->get_legend(TASK_40,8) && !who->get_legend(TASK_40,9) ) 
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"Thẻ Tre",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,9);
			who->add_exp(3500);
			who->add_potential(120);
			who->add_cash(3000);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,11,"" );
			send_user(who,"%c%s",';',"Thẻ Tre Bị Mất Kinh nghiệm 3500 Tiềm năng 120 Ngân lượng 3000");
			me->do_welcome(1);
        	}
        	break;
 	case 5:
        	if ( who->get_legend(TASK_40,9) && !who->get_legend(TASK_40,10) )
        	{
        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
        		who->set_legend(TASK_40,10);
			who->delete_save("lysjinsnj");
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"Chu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,12,"Sừng Trâu Vàng" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ "HIY"Sừng Trâu Vàng");
        	}
        	break;  
        case 6:
        	if ( who->get_legend(TASK_40,11) && !who->get_legend(TASK_40,12) ) 
        	{
        		if (TASK_LEGEND_D->check_task_item(who,"Rương Chứa Sừng Trâu Vàng",1) != 1 )
        			return;
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_40,12);
			who->delete_save("lysjinsnj");
			who->add_exp(3100);
			who->add_potential(105);
			who->add_cash(2700);
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,12,"" );
			send_user(who,"%c%s",';',"Sừng Trâu Vàng Kinh nghiệm 3100 Tiềm năng 105 Ngân lượng 2700");
			me->do_welcome(1);
        	}
        	break;
 	case 7:
        	if ( who->get_legend(TASK_40,12) && !who->get_legend(TASK_40,13) )
        	{
			if ( TASK_LEGEND_D->can_carry_amount(who,1) != 1 )
				return ;        		
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			TASK_LEGEND_D->give_item(who,"item/98/0196",1); 
        		who->set_legend(TASK_40,13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"Chu Quốc" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,13,"Thỉnh Cầu Vua Giúp Đỡ" );
			send_user( who, "%c%s", '!', "Nhận nhiệm vụ "HIY"Thỉnh Cầu Vua Giúp Đỡ");
        	}
        	break;
        }
}