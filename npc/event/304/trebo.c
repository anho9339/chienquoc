
// 自动生成：/make/npc/makenpc

#include <npc.h>
#include <equip.h>
#include <skill.h>
#include <task.h>
#include <ansi.h>
 
inherit BADMAN;

// 函数：获取人物造型
int get_char_picid() { return 0303; }

// 函数：构造处理
void create()
{
        set_name(HIR"Trẻ Bò");
        
        set_char_type(FIGHTER_TYPE);    // init_level 要用到
        
        set_head_color(0xd308);

        NPC_ENERGY_D->init_level( this_object(), 40+ random(3) );    // 
        set_max_seek(4);

        setup();

        set_char_type(FIGHTER_TYPE);    // 重设类型
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }

// 函数：特技攻击对手
int perform_action( object who ) { return 0; }    // XXXXX->perform_action_npc( this_object(), who ); }

// 函数：自动战斗(遇玩家时调用)
void auto_fight( object who ) { }

// 函数：掉宝奖励
void drop_items( object who ) { __FILE__ ->drop_items_callout( this_object(), who ); }

// 函数：掉宝奖励(在线更新)
void drop_items_callout( object me, object who )
{
                object item, leader;
        string file, owner, id;
        int p, rate, i, size, gold, equip, total, total2,tuiquatonsu ;
        int z, x, y;

        z = get_z(me);  x = get_x(me);  y = get_y(me);
        id = who->get_leader();
		who->add_exp(600+random(600));
		who->add_cash(600+random(600));
		
		if ( random100() < 90 )
				switch( random(4) )
		                {
						case 0 : item = new( "/item/event/304/giai" );  break; 
						case 1 : item = new( "/item/event/304/phong" );  break;
						case 2 : item = new( "/item/event/304/lao" );  break; 
						case 3 : item = new( "/item/event/304/dong" );  break;
						}
		else
				item=new("item/event/304/gpld");
		if ( item ) 
		{
		p=item->move2(who,-1);
		item->add_to_user(p);
		send_user(who,"%c%s",';',"Bạn nhận được "+item->get_name()+", xin chúc mừng !");
		USER_D->user_channel(sprintf(HIC"Bằng hữu "HIY "%s"  HIC" vừa đập tên "HIY "Trẻ Bò"HIC" nhận được chữ "HIB"%s.", who->get_name(), item->get_name() ));
		}
			
}       
