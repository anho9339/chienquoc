#include <effect.h>
#include <map.h>

inherit TALISMAN;

// 函数：法宝识别
int get_talisman_type() { return 12; }

// 函数：构造处理
void create()
{
        set_name( "Khóa Đồng Tâm" );
        set_picid_1(9611);
        set_picid_2(9611);
        set_unit( "把" );

        set_level(1);
        set_value(5000);
        set_max_lasting(38888);
        set("hp", 50);  
        set("mp", 50);  
        set("dp", 5);  
        set("pp", 5);  
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
        setup();
}

// 函数：获取描述
string get_desc() 
{ 
        return "Phu thuê pháp bảo, tốc độ đạt đến người bạn thân bên mình, thì có thể tăng thuộc tính nhân vật";
}
// 函数：可使用法宝
int is_usable_2() { return 1; }

int get_use_effect_2( object me, object who, string arg ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object item) 
{
	int x,y,z;
	object user,map,map1,npc;
	if ( !who->get_save_2("marry") )
	{
		item->remove_from_user();
		destruct(item);
		return 1;
	}
        if( objectp( map = get_map_object( get_z(who) ) ) && map->get_map_type() == BATTLE_MAP )
        {
                send_user(who, "%c%s", '!', "Ở Chiến Trường không thể sử dụng");
                return 0;
        }
		if ( get_z(who)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}
		if ( get_z(who)==888 )
		{
				notify("Trong VST không thể sử dụng");
                return 0;	
		}
		if ( get_z(who)==889 )
		{
				notify("Trong VSC không thể sử dụng");
                return 0;	
		}
	/*	if ( objectp( map = get_map_object( get_z(who) ) ) && map->get_map_type() == CAVE_MAP )
		{
				notify("Ở Hang động không thể sử dụng");
                return 0;	
		}*/
		if ( get_z(who)==50 )
		{
			   notify("Tần Quốc không cho sử dụng vật phẩm này");
			   return 0;
		}
        if( present("Vật Phẩm Quý Báu", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "Mang theo Vật Phẩm Quý Báu không thể sử dụng.");
                return 0;
        }
	/*	if( present("Ngân Phiếu", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "Mang theo Ngân Phiếu không thể sử dụng.");
                return 0;
        }  */
		if( present("Cờ Hiệu Vô Song Thành", who, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "Mang theo Cờ Hiệu Vô Song Thành không thể sử dụng.");
                return 0;
        }
        if( objectp( npc = who->get_quest("escort.robber#") ) && npc->is_escort_robber() )    // 寻找蒙面人
        {
                send_user(who, "%c%s", '!', "蒙面人出现，您的行动受到影响.");
                return 0;
        }
	if( who->is_store_open() )
	{
                send_user(who, "%c%s", '!', "Bán hàng rong không thể sử dụng");
                return 0;
        }
	user = find_player(sprintf("%d",who->get_save_2("marry.id")));
	if ( !user )
	{
                send_user(who, "%c%s", '!', "Đối phương đang ngoại tuyến, không thể sử dụng");
                return 0;
        }
	x = get_x(user);	
	y = get_y(user);	
	z = get_z(user);	
	if( MAP_D->is_inside_city(z, x, y) )
		{
                send_user(who, "%c%s", '!', "Đối phương ở trong thành, không thể sử dụng");
                return 0;
        }
        if( !objectp( map1 = get_map_object( z ) ) )
        	return 0;
	if( map1->is_copy_scene() )
        {
                send_user(who, "%c%s", '!', "Đối phương ở trong Phó Bản, không thể sử dụng");
                return 0;
        } 
	if( map1->is_changping() )
        {
                send_user(who, "%c%s", '!', "Đối phương ở trong Chiến Trường, không thể sử dụng");
                return 0;
        }
	if ( get_z(user)==704 )
		{
				notify("Đối phương đang ở trong Nhà Ngục");
                return 0;	
		}
	if ( get_z(user)==888 )
		{
				notify("Đối phương đang ở trong VST");
                return 0;	
		}
	if ( get_z(user)==889 )
		{
				notify("Đối phương đang ở trong VSC");
                return 0;	
		}
	if ( get_z(me)==910 )
				{
				notify("Trong Bãi Luyện Tập không thể sử dụng");
                return 0;	
				}
				if ( get_z(me)==920 )
				{
				notify("Trong Bãi Luyện Tập không thể sử dụng");
                return 0;	
				}
	/*if ( map1->get_map_type() == CAVE_MAP )
		{
				notify("Đối phương đang ở Hang động");
                return 0;	
		}*/	
		if( present("Vật Phẩm Quý Bấu", user, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "Đối phương đang Áp tiêu.");
                return 0;
        }
	/*	if( present("Ngân Phiếu", user, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "Đối phương đang làm Thương Nhân.");
                return 0;
        } */
		if( present("Cờ Hiệu Vô Song Thành", user, 1, MAX_CARRY) )
        {
                send_user(who, "%c%s", '!', "Đối phương đang mang theo Cờ Hiệu.");
                return 0;
        }	
		if ( get_z(user)==50 )
		{
				notify("Đối phương đang ở trong Tần Quốc");
                return 0;	
		}
	send_user(who, "%c%c%w%s", 0x5a, 0, 10, "Đang di chuyển……");	
        send_user( who, "%c%c%c%w", 0x30, 0, 8, 60 );   
        who->set_2("travel.z", get_z(user));
        who->set_2("travel.p", get_x(user)*1000+get_y(user));
        who->set_2("travel.money", 0);
        set_effect(who, EFFECT_TRAVEL, 10);
	return 0;
}

