
#include <equip.h>
#include <effect.h>

inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 2108; }

// 有自己的do_look函数
int is_self_look() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Bảo Rương Tình Nhân");
        set("boxname","Rương Tình Nhân");
        setup();
}

// 函数：对话处理
void do_look( object who ) 
{
	if (get_effect(who, EFFECT_OPEN_BOX)) return;
	send_user(who, "%c%c%w%s", 0x5a, 0, 5, "Đang mở……");
	set_effect_2(who, EFFECT_OPEN_BOX, 1,5);
	who->set("openbox",this_object());
	
}

void into_effect(object who,object me)
{
	int rate,p,p2,oldz,x,y,z,level;
	string file,*nTmp;
	object item,item1,user;
	
	if ( me->get("user") != who->get_number() )
		return ;
			if(USER_INVENTORY_D->get_free_count(who) < 1 )
			{
				notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
			}
	if ( user = who->get_save("pbtndp") )
	{
			if(USER_INVENTORY_D->get_free_count(user) < 1 )
			{
				notify( "Hành trang đối phương không đủ 1 chỗ trống" );
				return ;
			}
	}	
	item = new("item/event/pbtnben");
	p = item->move2(who,-1);
	item->add_to_user(p);
	if ( user = who->get_save("pbtndp") )
	{
	item1 = new("item/event/pbtnben");
	p2 = item1->move2(user,-1);
	item1->add_to_user(p2);
	}
		
	me->remove_from_scene();
	destruct(me);
	send_user(who,"%c%s",'!',sprintf("Ngươi mở Rương Tình Nhân nhận được %s",item->get_name()));
	tell_user(who,sprintf("Ngươi mở Rương Tình Nhân nhận được %s",item->get_name()));

	who->delete_save_2("fightpbtn");
	if (who->get_fam_order()<=0)
	        who->set_fam_order(4);
        else		        
	        who->set_fam_order(who->get_fam_order()-1);
	z = who->get_2("pbtn.z");
	x = who->get_2("pbtn.x");
	y = who->get_2("pbtn.y");		
	who->delete_2("pbtn");
	who->delete_2("pbtn");
	if( !( p = get_valid_xy( z, x, y, IS_CHAR_BLOCK ) ) ) return ;
	x = p / 1000;  y = p % 1000;
	who->add_to_scene(z, x, y, 3);
	who->set_save("pbtndalam",1);
	if ( user = who->get_save("pbtndp") )
	{
	user->set_save("pbtndalam",1);
	user->add_to_scene(get_z(who), get_x(who), get_y(who), 3);
	}
}

