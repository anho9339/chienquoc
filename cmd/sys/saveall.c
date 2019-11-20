
#include <ansi.h>
#include <city.h>

// 函数：命令处理
int main( object me, string arg )
{
        object *user, who, obj;
        mapping org;
        int time, time2, i, size;
        string id, order;

        if( me != this_player(1) || is_player(me) ) 
        {
                notify( "Ngươi không đủ quyền" );
		return 1;
        }

        if( arrayp( user = users() ) )
                for( i = 0, size = sizeof(user); i < size; i ++ ) 
        {
                if( !objectp( who = user[i] ) ) continue;
                if( !stringp( who->get_id() ) ) continue;
                if( who->get_login_flag() < 2 ) continue;    // 以前注释(有过玩家重起时数据全被清０)

                time = gone_time( who->get_login_time() );
                who->set_game_time( who->get_game_time() + time );

//                db_user_fee( who, who->get_login_time(), time, who->get_feetime() );    // 扣费！
	        if (MAIN_D->get_host_type()==4||MAIN_D->get_host_type()==0||MAIN_D->get_host_type()==1000)
	        {
	        	db_user_fee( who, sprintf( MAIN_D->get_php_ip()+":80\n"
	                	"GET http:/""/%s/logout2.php?t=%s&u=%d&r=%d&h=%d\r\n", 
	                	MAIN_D->get_php_ip(), short_time_2(), who->get_acountid(), MAIN_D->get_region(), MAIN_D->get_host() ) );    // 扣费！          	
	                obj = new ("/inh/user/list");
	                id = who->get_id();
	                obj->set_owner(who->get_real_id());
	                if (who->get_real_id()==id ) order = "1";
	                else order = id[<1..<1];
	                obj->set_save_2(order+".number", who->get_number());
	                obj->set_save_2(order+".shape", who->get_armor_code());
	                obj->set_save_2(order+".level", who->get_level());
	                obj->set_save_2(order+".gold", who->get_cash()+who->get_savings());
		        obj->set_save_2(sprintf("%s.armor", order), who->get_armor_code());
		        obj->set_save_2(sprintf("%s.armorc", order), who->get_armor_color_1());
		        obj->set_save_2(sprintf("%s.hair", order), who->get_hair());
		        obj->set_save_2(sprintf("%s.hairc", order), who->get_hair_color());
		        obj->set_save_2(sprintf("%s.back", order), who->get_back());
		        obj->set_save_2(sprintf("%s.backc", order), who->get_back_color());
		        obj->set_save_2(sprintf("%s.back2", order), who->get_back2());
		        obj->set_save_2(sprintf("%s.back2c", order), who->get_back2_color());
		        obj->set_save_2(sprintf("%s.weapon", order), who->get_weapon_code_2());
		        obj->set_save_2(sprintf("%s.weaponc", order), who->get_weapon_color());        		
		        obj->set_save_2(sprintf("%s.weaponc2", order), who->get_weapon_color_2());        		
	                obj->set_save_2(sprintf("%s.family", order), who->get_fam_name());
	                obj->save();
	                destruct(obj);
		}	      
		else  		
			db_user_fee( who, sprintf( MAIN_D->get_php_ip()+":80\n"
	                	"GET /xq2/fee.php?id=%s&start=%d&end=%d&time=%d&count=%d&host=%d&shape=%d&level=%d&gold=%d&ip=%s\r\n", 
	                	rawurlencode( who->get_id() ), who->get_login_time(), who->get_login_time()+time, time, who->get_feetime(), MAIN_D->get_host(), who->get_armor_code(), who->get_level(), who->get_cash()+ who->get_savings(), get_ip_name(who) ) );    // 扣费！
                time2 = who->get_feetime() + time;
                if( time2 >= FEE_TIME )
                {
                        who->set_fee_start( time() );
                        who->set_feetime(time2 % FEE_TIME);
                }
                else    who->set_feetime(time2);

                who->set_quit_time( time() );
                who->set_quit_ip( get_ip_name(who) );    // 注意 quit 命令

                who->save();
        }

        CITY_QI->save();
        CITY_HAN->save();
        CITY_ZHAO->save();
        CITY_WEI->save();
        CITY_QIN->save();
        CITY_CHU->save();
        CITY_YAN->save();
        CITY_ZHOU->save();

        if( mapp( org = CITY_ZHOU->get_2("org") ) && arrayp( user = values(org) ) ) 
                for( i = 0, size = sizeof(user); i < size; i ++ ) if( user[i] ) user[i]->save();

        tell_user(me, "Đã save toàn bộ dữ liệu");

        return 1;
}
