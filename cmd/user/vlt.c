#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

int main(object me, string arg) 
{

    int p, cap, exist, exist2, i, size, iTime,ben,tet1=0,tet2=0,tet3,tet4;
	string result,*line,*data,mename,arg2,arg3,arg4,whoname;
    object item, item1, who, *objs, target;
	mixed *mixTime;
	iTime = time();
	mixTime = localtime(iTime);	
		if( !arg ) return 1;
		if (arg==0) return 1;
		if( sscanf(arg, "? %s", arg2 ) == 1 ) 
		{
			if( arg2 && !( who = find_any_char(arg2) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				return 1;
			}
			if ( !who->is_user() )
			{
				write_user(me, ECHO "Đối phương không phải là người chơi !");
				return 1;
			}
		/*	if ( who->get_gender()==me->get_gender() )
			{
				write_user(me, ECHO "Đối phương cùng giới với bạn !");
				return 1;
			}*/
			if ( who==me )
			{
				write_user(me, ECHO "Không thể tự nói với chính mình !");
				return 1;
			}
			if ( TASK_LEGEND_D->check_task_item_amount(me,"Hoa Hồng Thâu Tâm") < 1 ) return 1;
			send_user( me, "%c%c%d%s", '?', 16, 100, "Xin nhập nội dung muốn bày tỏ tình cảm với ID "+arg2+":\n" ESC "vlt + "+arg2+" %s\n" );	
		}
		else if( sscanf(arg, "+ %s %s", arg2, arg3 ) == 2 ) 
		{
			if( arg2 && !( who = find_any_char(arg2) ) )
			{
                write_user(me, ECHO "Không tìm thấy người này !");
				return 1;
			}
			if ( !who->is_user() )
			{
				write_user(me, ECHO "Đối phương không phải là người chơi !");
				return 1;
			}
			/*if ( who->get_gender()==me->get_gender() )
			{
				write_user(me, ECHO "Đối phương cùng giới với bạn !");
				return 1;
			}*/
			if ( who==me )
			{
				write_user(me, ECHO "Không thể tự nói với chính mình !");
				return 1;
			}
			if ( TASK_LEGEND_D->check_task_item_amount(me,"Hoa Hồng Thâu Tâm") < 1 ) return 1;
			TASK_LEGEND_D->check_task_item1(me,"Hoa Hồng Thâu Tâm",1);
			mename = sprintf("%c+%d,%s=%d%c-", '\t', 0xff0202, me->get_name(), me->get_number(), '\t');
			whoname = sprintf("%c+%d,%s=%d%c-", '\t', 0xff0202, who->get_name(), who->get_number(), '\t');
			CHAT_D->sys_channel(0,sprintf("%s nhìn %s với ánh mắt long lanh, và nói: %s",mename,whoname,arg3));	
			me->add_save("diemtrongcayabchh",1);
			"sys/party/bxh_trongcayhh"->update_bxh_trongcay(me);
		}	
	return 1;
} 