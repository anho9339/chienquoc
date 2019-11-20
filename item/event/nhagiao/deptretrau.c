// 自动生成：/make/weapon/make72b
#include <item.h>
#include <effect.h>
#include <skill.h>
#include <map.h>
#include <ansi.h>
#include <equip.h>
#include <level.h>

inherit TALISMAN;

// Tỉ lệ hiệu quả
int get_active_rate() { return 100; }

// 函数：法宝识别
int get_talisman_type() { return 6; }
// 函数：nh9h构造处理
void create()
{
        set_name("Dép Trẻ Trâu");
        set_picid_1(8802);
        set_picid_2(8802);
      
        set_level(10);
        set_value(10);
        set_max_lasting(10099);
        set("!%", 1000); 
        set("ap", 50);
		set("cp", 50);
	    set_item_color(1);

        setup();
   
}

// Có thể sử dụng pháp bảo
int is_usable_2() { return 1; }

// 函数：nh9h获取描述
string get_desc()
{
        return "Giúp Trẻ Trâu chạy nhảy lung tung, nhưng có giới hạn.";
}

// 函数：使用效果
int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

// 函数：使用效果(在线更新)
int get_equip_effect_callout( object me, object item )
{
	//处理时间控制上面的。
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time()+1*24*60*60);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
}

//zzz
string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 1 ngày]\n ";
	}

	return desc;
}

// 函数：使用法宝效果
int get_use_effect_2( object me, object who, string arg ) { return __FILE__ ->get_use_effect_2_callout( me, who, this_object(), arg ); }

// 函数：使用法宝效果(在线更新)
int get_use_effect_2_callout( object me, object who, object item, string arg )
{
       object map, npc;
       int z, x, y, p, mp, yuan;
	   int t1,t2,t3,t4,t5;
	   if(me->get_fam_name()=="Đào Hoa Nguyên") t1 = 2;
	   else if(me->get_fam_name()=="Thục Sơn") t2 = 400;
	   else if(me->get_fam_name()=="Cấm Vệ Quân") t1 = 2;
	   else if(me->get_fam_name()=="Đường Môn") t2 = 400;
	   else if(me->get_fam_name()=="Mao Sơn") t2 = 400;
	   else if(me->get_fam_name()=="Côn Luân") t2 = 400;
	   else if(me->get_fam_name()=="Vân Mộng Cốc") t2 = 400;
	   else { notify("Vô Môn Phái không thể sử dụng!"); return 1; }
		// Các môn phái xài sẽ mất tùy ý
		if(t1) { if(me->get_yuan()<t1) { send_user(me,"%c%s",'!',"Không đủ "+t1+" Nguyên khí."); return 1; } me->add_yuan(-t1); }
		if(t2) { if(me->get_mp()<t2) { send_user(me,"%c%s",'!',"Không đủ "+t2+" Nội lực."); return 1; } me->add_mp(-t2); }
		// Kết thúc
	if( me->is_store_open() )
	{
		send_user(me, "%c%s", '!', "Đang mở cửa hàng không thể sử dụng.");
		return 0;
	}        

        if( objectp( map = get_map_object( get_z(me) ) ) 
        	&& map->get_map_type() == BATTLE_MAP && map->is_changping() )
        {
                send_user(me, "%c%s", '!', "Trong Chiến Trường không thể sử dụng Phi Hành Phù.");
                return 0;
        }
		if ( get_z(me)==704 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}  
        if ( get_z(me)==885 )
		{
				notify("Trong Nhà Ngục không thể sử dụng");
                return 0;	
		}  		
         if( objectp( npc = me->get_quest("escort.robber#") ) && npc->is_escort_robber() )   
        {
                send_user(me, "%c%s", '!', "Kẻ Bịt Mặt xuất hiện, hành động bị ảnh hưởng.");
                return 0;
        }
		
        if(   ( z = get_z(me) )
        &&    ( p = get_xy_point(z, IS_CHAR_BLOCK) ) )
        {
                x = p / 1000;  y = p % 1000;

              if( MAP_D->is_inside_city(z, x, y) )
                {
                        write_user(me, ECHO "……Đang trong thành, không có hiệu quả.");
                        return 0;
                }       
 
                if(   ( npc = me->get_quest("escort.npc") )    // 运镖人物
                &&      npc->get_owner() == me
                &&      inside_screen_2(me, npc) )    // 同屏幕内
                        npc->add_to_scene( z, x, y, get_d(me), 40991, 40992, 40991, 40992 );
                if(   ( npc = me->get_2("orgtask2.npc") )    // 帮派任务
                &&      npc->get_owner() == me
                &&      inside_screen_2(me, npc) )
                        npc->add_to_scene(z, x, y, get_d(me));
                if( p = get_valid_xy( z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK ) )
                {
                        me->add_to_scene( z, p / 1000, p % 1000, get_d(me), 40991, 40992, 40991, 40992 );
                }

                return 1;
        }
        else
        {
                 write_user( me, ECHO "Bạn sử dụng " HIY "Dép Trẻ Trâu" ECHO " thất bại." );
                return 0;
        }
}

void start_loop_perform(object me)
{
		CHAR_CHAR_D->init_loop_perform(me);
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1,UNDER_FOOT, PF_LOOP );
}
void stop_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1, UNDER_FOOT, PF_STOP );	
}
