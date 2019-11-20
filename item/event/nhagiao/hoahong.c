
#include <ansi.h>
#include <item.h>
#include <effect.h>
#include <skill.h>
#include <equip.h>
inherit ITEM;
inherit COMBINED;

// 函数：可对目标使用的物品
int get_max_combined() { return 10000; }
int get_item_type_2() { return ITEM_TYPE_2_USABLE2; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name( "Hoa Hồng" );
        set_picid_1(3005);
        set_picid_2(3005);
        set_value(100);
        set_amount(1);
}

// 函数：获取描述
string get_desc()
{
        return "Một đoá Hoa hồng tươi thắm dành tặng cho những người thầy, cô \nnhân dịp ngày Lễ Nhà giáo Việt Nam 20/11";
}

// 函数：使用效果
int get_use_effect( object me, object who ) { return __FILE__ ->get_use_effect_callout(me, who); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object who )
{
	int p,level,exp,gender,tId,tId1,cash;
	object *team,user,item,pize;
    string *nTmp,tmp,cTmp,leader,result="";
	me = this_player();
	tId = me->get_team_id();
	tId1 = who->get_team_id();
	if ( !who->is_user() )
	{
		send_user(me,"%c%s",'!',"Bạn chỉ có thể tặng Hoa cho người chơi !");
		return 0;
	}
	if ( who == me )
	{
		send_user(me,"%c%s",'!',"Không thể tự tặng hoa cho chính mình !");
		return 0;
	}
	if ( USER_INVENTORY_D->get_free_count(me) < 1 )
	{
	        send_user(me,"%c%s",'!',"Hành trang không đủ 1 chỗ trống.");
    		return 0;
	}
	if ( me->get_level() < 10 )
	{
	        send_user(me,"%c%s",'!',"Cấp bậc của bạn chưa đủ 10 cấp.");
    		return 0;
	}
	if ( !who->have_title("B002") && !who->get_save_2("baishi.tudi") )
	{
		send_user(me,"%c%s",'!',sprintf("Đối phương không phải là %s !",who->get_gender() == 1 ? "Thầy Giáo" : "Cô Giáo"));
		return 0;
	}
//	me->add_exp(30000);
//	me->add_cash(50000);
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5914, 1, OVER_BODY, PF_ONCE );
	send_user( get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5916, 1, OVER_BODY, PF_ONCE );
	send_user( me,"%c%s",';', sprintf("Bạn đã tặng Hoa Hồng cho %s, gửi kèm ngàn lời chúc phúc nhân ngày Lễ Nhà giáo Việt Nam 20/11, đồng thời bạn nhận được phần thưởng đầy ý nghĩa !", who->get_name()) );
	send_user( who,"%c%s",';', sprintf("%s đã tặng bạn Hoa Hồng, gửi kèm ngàn lời chúc phúc nhân ngày Lễ Nhà giáo Việt Nam 20/11.", me->get_name()) );
	if ( objectp( item = present("Thư Chúc Phúc", me, 1, MAX_CARRY*4) ) ) {
	cTmp = sprintf(HIY "Bằng hữu "HIR "%s "HIY"đã gửi lời chúc đầy ý nghĩa tới %s "HIR "%s "HIY "mến yêu nhân dịp ngày Lễ nhà giáo Việt nam 20/11.", me->get_name(), who->get_gender() == 1 ? "thầy giáo" : "cô giáo", who->get_name() );
	send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
	item->add_amount(-1);
	}
	if ( random(100) < 7 ) 
	{
		pize = new("/item/event/nhagiao/hoahongdacbiet");
		if ( !pize )
			return 0;
	}
	else if ( random(100) < 15 ) // Đồ Hoàng Kim 5x
	{
		nTmp = WEAPON_FILE->get_family_equip( me->get_fam_name(),me->get_gender(),50,HEAD_TYPE+random(6) );
		pize = new(nTmp[random(sizeof(nTmp))]);
		ITEM_EQUIP_D->init_equip_prop_3(pize);
		if ( !pize )
			return 0;
	}
	else if ( random(100) < 35 ) // Nguyên Liệu nâng cấp random
	{
		pize = new(sprintf("/item/event/nhagiao/nlrandom/1%d",random(5)));
		if ( !pize )
			return 0;
	}
	else if ( random(100) < 45 )
	{
		exp = 20000;
	}
	else if ( random(100) < 60 )
	{
		cash = 30000;
	}
	else if ( random(100) < 65 )
	{
		pize = new("/item/test2/TuiQuaVoSong");
		if ( !pize )
			return 0;
	}
	else if ( random(100) < 75 ) // Tiểu Huyết Thạch
	{
		pize = new("/item/08/0003");
		if ( !pize )
			return 0;
	}
	else if ( random(100) < 85 ) // Tiểu Pháp Lực Thạch
	{
		pize = new("/item/08/0004");
		if ( !pize )
			return 0;
	}
	else
	{
		pize = new("/item/08/0001"); // Chiến Quốc Lệnh
		if ( !pize )
			return 0;
	}
	if ( pize )
	{
		send_user(me,"%c%s",'!',"Bạn nhận được "+pize->get_name());
		p = pize->move2(me);
		pize->add_to_user(p);	
	}
	else if ( exp )
	{
		me->add_exp(exp);
		send_user(me,"%c%s",'!',sprintf("Bạn nhận được %d kinh nghiệm",exp));
    		
	}
	else if ( cash )
	{
		me->add_cash(cash);
		send_user(me,"%c%s",'!',sprintf("Bạn nhận được %d ngân lượng",cash));	
	}
	return 1;
}
