#include <ansi.h>
#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
int get_item_color() {return 1 ;}
int get_item_type_2() { return ITEM_TYPE_2_USABLE2; }
// 函数：构造处理
void create()
{
        set_name( "Quà nhỏ" );
		set_picid_1(3221);
        set_picid_2(3221);
        set_value(10);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Món quà đã được gói lại dành cho ngày Quốc Tế Phụ Nữ.";
}
// 函数：使用效果
int get_use_effect( object me, object who ) { return __FILE__ ->get_use_effect_callout(me, who); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object who )
{
	int p,level,exp,gender,tId,tId1;
	object *team,user;
    string *nTmp,tmp,cTmp,leader,result="";
	me = this_player();
	tId = me->get_team_id();
	tId1 = who->get_team_id();
	if ( !who->is_user() )
	{
		send_user(me,"%c%s",'!',"Bạn chỉ có thể tặng Hoa cho người chơi!");
		return 0;
	}
	if ( who == me )
	{
		send_user(me,"%c%s",'!',"Không thể tự tặng hoa cho chính mình!");
		return 0;
	}
	if ( who->get_gender()!=2 )
	{
		send_user(me,"%c%s",'!',"Chỉ có thể tặng hoa cho Nữ giới!");
		return 0;
	}
	me->add_save("quaqtpn",1);
	"/sys/bxh_tangqua"->update_tangqua(me);
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5914, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5916, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5917, 2, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5915, 3, OVER_BODY, PF_ONCE );
	send_user( me,"%c%s",';', sprintf("Bạn đã tặng Quà cho %s, gửi kèm ngàn lời yêu thương.", who->get_name()) );
	send_user( who,"%c%s",';', sprintf("%s đã tặng bạn Quà, gửi kèm ngàn lời yêu thương đồng thời bạn nhận được điểm Tặng quà.", me->get_name()) );
	CHAT_D->sys_channel(0,me->get_name()+" nhân ngày Quốc Tế Phụ Nữ đã tặng Quà cho "+who->get_name()+" cùng lời chúc đầy ý nghĩa !");
	return 1;
}