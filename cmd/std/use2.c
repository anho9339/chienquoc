#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
#include <item.h>

// 函数：命令处理
int main( object me, string arg )
{
        object item, who;
        string id, id2, arg1, key, func, *allkey;
        int busy, z, x, y, size;
	if( me->is_store_open() )
	{
		send_user(me, "%c%s", '!', "Đang bán hàng rong, không thể sử dụng");
		return 0;
	}

        if( gone_time( me->get_time("use") ) < 1 )    // 时间限制
        {
//                me->set_time( "use", time() );
                return 1;
        }
        me->set_time( "use", time() );

        if( busy = get_effect(me, EFFECT_CHAR_BUSY) )
        {
                notify( "Bạn còn phải bận %d giây", busy );
                return 1;
        }
        if(     get_effect(me, EFFECT_CHAR_FAINT) 
        ||      get_effect(me, EFFECT_CHAR_FAINT_2)
        ||      get_effect(me, EFFECT_SLEEP)
        ||      get_effect(me, EFFECT_CHAR_DREAM_1)
        ||      get_effect(me, EFFECT_CHAR_DREAM) ) return 1;

        if( get_effect(me, EFFECT_USER_THUNDER) ) PF_FILE_04236->effect_thunder_break(me);    // 雷龙诀(中断)

	if( !arg ) return 1;
        
        if( !objectp( item = present(arg, me, 1, MAX_CARRY*4) ) ) 
	{
		if ( !objectp(item=find_any_object(arg)) )
			return 1;
		if ( item == me->get_equip(FAMILY_TYPE) )
		{
			item->get_use_effect(me);
		}
        	return 1;
        }
		if ( me->get_save("passhanhtrang") && me->get_save("ndmkhtk") < 1 && item->get_name()!="Bảo Mật Tín Vật" ) 
		{
		send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Hành trang của bạn đang trong trạng thái Khoá !" );
		return 1;
		}
		else if ( me->get_save("passhanhtrang") && me->get_save("ndmkhtk") < 1 && item->get_name()=="Bảo Mật Tín Vật" ) 
		{
		
		}
		else if ( me->get_save("passhanhtrang") && me->get_save("ndmkhtk") >= 1 )
		{
		
		}
		else if ( me->get_save("ndmkhtk") < 1 )
		{
		
		}
		
		// Cấm sử dụng item trong CQMC
		if (me->get_save("csdvp") >= 1 )
		{
		  if ( !item->is_ridepk() &&item->get_equip_type()!=HAND_TYPE &&item->get_equip_type()!=NECK_TYPE &&item->get_equip_type()!=HEAD_TYPE
          && item->get_equip_type()!=WEAPON_TYPE &&item->get_equip_type()!=ARMOR_TYPE&& item->get_equip_type()!=WAIST_TYPE
		  && item->get_equip_type()!=BOOTS_TYPE &&item->get_equip_type()!=FAMILY_TYPE && item->get_equip_type()!=BACK_TYPE&&item->get_equip_type()!=FASHION_TYPE         
		   && item->get_name()!="Thần Thú - Thìn" && item->get_name()!="Thần Thú - Thỏ" 
		   && item->get_name()!="Thần Thú - Sửu (Giới hạn)" && item->get_name()!="Thần Thú - Dần (Giới hạn)" 
		   && item->get_name()!="Song Tử Anh Minh" && item->get_name()!="Song Tử Dũng Cảm" && item->get_name()!="Song Tử Trung Thành" && item->get_name()!="12 con Giáp - Chuột"
           && item->get_name()!="Thần Thú - Ma Yết"	 && item->get_name()!="Bột Huỳnh Quang"	 && item->get_name()!="Sơ Phục Dược"  && item->get_name()!="Tiểu Pháp Lực Thạch"
           && item->get_name()!="Đại Pháp Lực Thạch"  && item->get_name()!="Thiên Nguyên Đan"		   
		   )
				{ 
		send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Không thể sử dụng vp trong map này!" );
		return 1;
		}
		}
		/*
		if ( get_z(me)==891 )
		{
				if ( !item->is_ridepk()&&item->get_equip_type()!=HAND_TYPE )
				{ 
			notify(HIY"Không thể sử dụng ở bản đồ này !");
			return 1;
				}
		} */
      
        // 装备道具
        if( item->get_equip_type() && FAMILY_TYPE != item->get_equip_type() ) 
        {
        	if( get_effect(me, EFFECT_MAGIC_4243) ) return 1;
			if (item->get_bind()==5) return 1;
	        if (me->get_fam_name()=="Đào Hoa Nguyên" && me->get_perform("03191"))
	        {
	        	notify( "Trạng thái Cuồng Bạo không thể thay đổi trang bị" );
	        	return 1;
	        }     
	        if (me->get_fam_name()=="Đào Hoa Nguyên" && me->get_perform("03192"))
	        {
	        	notify( "Trạng thái Phòng Ngự không thể thay đổi trang bị" );
	        	return 1;
	        } 
	        if (me->get_fam_name()=="Thục Sơn" && me->get_perform("02221#"))
	        {
	        	notify( "Trạng thái Miễn Nhiễm Trầm Mặc không thể thay đổi trang bị" );
	        	return 1;
	        }	
	        if (me->get_fam_name()=="Thục Sơn" && me->get_perform("02222#"))
	        {
	        	notify( "Trạng thái Miễn Nhiễm Choáng không thể thay đổi trang bị" );
	        	return 1;
	        }
        	return me->use_equip(item);
        }

        // 使用道具
        if( !item->is_usable() )
        {
                notify( "Không thể sử dụng %s .", item->get_name() );
                return 1;
        }
        else if( !item->get_use_effect(me) )
        {
                return 1;
        }
        if( item->is_combined() ) 
                item->add_amount(-1);
        else 
        {
                item->remove_from_user();
                destruct(item);
        }

        return 1;
}
