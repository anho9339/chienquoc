
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
 
inherit BADMAN;

// 函数：获取人物造型
int get_char_picid() { return 8250; }

// 函数：构造处理
void create()
{
        set_name(HIY"Bảo Thạch Tinh Yêu");
        
        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0xd308);

        NPC_ENERGY_D->init_level( this_object(), 60+ random(10) );    // 
        set_max_seek(4);

        setup();

        set_char_type(FIGHTER_TYPE);    // 重设类型
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
int perform_action( object who ) { return 0; }    // XXXXX->perform_action_npc( this_object(), who ); }

// 函数：掉宝奖励
void drop_items( object who ) { __FILE__ ->drop_items_callout( this_object(), who ); }

// 函数：掉宝奖励(在线更新)
void drop_items_callout( object me, object who )
{
                object item, leader;
        string file, owner, id;
        int p, rate, i, size, gold, equip, total, total2,vatpham,level ;
        int z, x, y;
		
		level = who->get_level();
		
		
        z = get_z(me);  x = get_x(me);  y = get_y(me);
        id = who->get_leader();
		who->add_exp(level*50+random(1000));
		who->add_cash(level*10+random(5000));
	//	"sys/sys/test_db"->add_yuanbao(who, 2);
	
		switch( random(4) )
		                {
						case 0 : item = new( "/item/manhghep/mgdt" );  break;
						case 1 : item = new( "/item/manhghep/mgdt" );  break; 
						case 2 : item = new( "/item/manhghep/mgdt" );  break; 						
						case 3 : item = new( "/item/manhghep/bdp" );  break;
						}
		//item = new("item/event/tuihang");
		item->set_amount(1+random(5));
		vatpham = item->move(who,-1);
			if ( !vatpham )
			{
				destruct(item);
				return ;	
			}
			item->add_to_user(vatpham);
			send_user(who,"%c%s",';',"Bạn nhận được "HIR+item->get_name());
		//	USER_D->user_channel(sprintf(HIC"Vị anh hùng "HIY "%s"  HIC" vừa đánh được "HIY "Tù Nhân Vượt Ngục"HIC" và nhận được lấy được Túi Hàng từ tay chúng", who->get_name() ));	
			
        }       

int can_fight( object who ) 
{ 
	/*if ( !objectp(this_object()->get_enemy()) )
		return 0;
	if ( who->is_user() && this_object()->get_level()+10 < who->get_level() ) {
	return 0;
	}
	if ( who->is_user() && who->get_level()+10 <= this_object()->get_level() ) {
	return 0;
	}	*/
	if(who->get_level() > 80) {
		return 0;
	}
	
	return 1;
}
int can_be_fighted( object who ) 
{ 
        object owner;
        string leader, id;
/*	if( who->is_npc() && objectp(owner = who->get_owner()) ) who = owner;
	if( who->is_npc() )
	{
		return 0;
	}
	if ( who->is_user() && this_object()->get_level()+10 < who->get_level() ) {
	send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),  "Đẳng cấp cao vậy rồi mà vẫn tới bắt nạt ta. Hãy tới nơi khác đi !" );
	return 0;
	}
	if ( who->is_user() && who->get_level()+10 <= this_object()->get_level() ) {
	send_user( who, "%c%c%w%s", ':', 3, get_char_picid(),  "Ngươi không nhìn thấy ta! Ngươi không nhìn thấy ta! \nHa ha ha ! Ha ha ha !" );
	return 0;
	} */
	if(who->get_level() > 80) {
		send_user( who, "%c%c%w%s", ':', 3, get_char_picid(), "Đẳng cấp quá cao so với qui định, không thể bắt nạt ta được nữa đâu! Cút đi!" );
		return 0;
	}
	
	return 1;
}