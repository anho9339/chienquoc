
#include <ansi.h>
#include <city.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who = me;
        string city, relation;
        string result;

        if( is_player(me) ) 
        {
                notify( "Bạn không đủ quyền。" );
		return 1;
        }

        // 查看Quốc gia状态

        switch( arg )
        {
        case "Tề Quốc" : case "01" : city = CITY_QI;  break;
        case "Hàn Quốc" : case "02" : city = CITY_HAN;  break;
        case "Triệu Quốc" : case "03" : city = CITY_ZHAO;  break;
        case "Ngụy Quốc" : case "04" : city = CITY_WEI;  break;
        case "Tần Quốc" : case "05" : city = CITY_QIN;  break;
        case "Sở Quốc" : case "06" : city = CITY_CHU;  break;
        case "Yên Quốc" : case "07" : city = CITY_YAN;  break;
                      default : city = "";  break;
        }

        if( city != "" )
        {
                result = sprintf( "Quốc gia：%-8s  Cấp bậc：%8d  Thành chủ：%s %s，%s %s，%s %s\n", 
                        city->get_name(), city->get_level(),
                        city->get_master_name(), city->get_master(),
                        city->get_master_name_2(), city->get_master_2(),
                        city->get_master_name_3(), city->get_master_3() );
                result += sprintf( "Thành phòng：%8d  Binh lính：%8d  Trang bị：%8d  Huấn luyện：%8d  Cống hiến：[%6d]\n", 
                        city->get_defence(), city->get_soldier(), city->get_armor(), city->get_training(), city->get_contribute() );
                result += sprintf( "Ngân lượng：%10d  Tích lũy：%10d  Thuế thu：%10d  Lương thảo：%10d\n", 
                        city->get_cash(), city->get_money(), city->get_tax(), city->get_food() );
                result += sprintf( "Nông nghiệp：%8d  Ngư nghiệp：%8d  Mỏ nghiệp：%8d Mỹ nghệ：%8d  Buôn bán：%8d\n", 
                        city->get_agriculture(), city->get_fishculture(), city->get_mining(), 
                        city->get_industry(), city->get_commercial() );
                result += sprintf( "Nghệ thuật：%8d  Giáo dục：%8d  Tông giáo：%8d  Dẹp yên：[%6d]  Bệnh tật：[%6d]\n", 
                        city->get_arts(), city->get_education(), city->get_religion(),
                        city->get_stability(), city->get_disease() );

                tell_user(me, result);

                result = "Ngoại giao：";

                if( arg != "Tề Quốc" && arg != "01" ) result += sprintf( "Tề Quốc：(%d)%s  ", city->get_friend(1), city->get_relation_name(1) );
                if( arg != "Hàn Quốc" && arg != "02" ) result += sprintf( "Hàn Quốc：(%d)%s  ", city->get_friend(2), city->get_relation_name(2) );
                if( arg != "Triệu Quốc" && arg != "03" ) result += sprintf( "Triệu Quốc：(%d)%s  ", city->get_friend(3), city->get_relation_name(3) );
                if( arg != "Ngụy Quốc" && arg != "04" ) result += sprintf( "Ngụy Quốc：(%d)%s  ", city->get_friend(4), city->get_relation_name(4) );
                if( arg != "Tần Quốc" && arg != "05" ) result += sprintf( "Tần Quốc：(%d)%s  ", city->get_friend(5), city->get_relation_name(5) );
                if( arg != "Sở Quốc" && arg != "06" ) result += sprintf( "Sở Quốc：(%d)%s  ", city->get_friend(6), city->get_relation_name(6) );
                if( arg != "Yên Quốc" && arg != "07" ) result += sprintf( "Yên Quốc：(%d)%s  ", city->get_friend(7), city->get_relation_name(7) );

                tell_user(me, result);

                result = "Tỷ số thuế：";

                result += sprintf( "Mua：%2d%%%%  Tiêu thụ：%2d%%%%  Thương nhân mua：%2d%%%%  Tiêu thụ：%2d%%%%  Thuế hồng：%2d%%%%\n", 
                        city->get_buy_tax(), city->get_sell_tax(), 
                        city->get_buy_tax_2(), city->get_sell_tax_2(), city->get_tax_2_cash() );

                tell_user(me, result);

		return 1;
        }

        // 查看人物状态

        if( arg && !( who = find_player(arg) ) ) 
        {
                notify( "Chẳng tìm đc ai như vậy cả。" );
		return 1;
        }

        result = sprintf( "Người chơi：%s(%d)  Bang phái：%s  %s\n", who->get_name(), who->get_number(), who->get_org_name(), 
                who->get_save("channel_manager") ? HIY "Quản lí kênh" : "" );

        result += sprintf( "Quốc gia：%-8s  Nghề nghiệp：%-8s  Danh vọng：%8d  Cống hiến：%8d  Thể lực：%8d\n",
                who->get_city_name(), who->get_occupation(), 
                who->get_repute(), who->get_contribute(), who->get_strength() );
        result += sprintf( "Nhân ái：%8d  Chính nghĩa：%8d  Trung thực：%8d  Thành tín：%8d  Dũng cảm：%8d  Mưu trí：%8d\n",
                who->get_gift_ra(), who->get_gift_zy(), who->get_gift_zs(), 
                who->get_gift_cx(), who->get_gift_yg(), who->get_gift_zm() );

        result += sprintf( "Nghệ sĩ：%3d cấp %10d kinh nghiệm    Nông phu：%3d cấp %10d kinh nghiệm\n", 
                who->get_occupation_level(JOB_ACTOR), who->get_occupation_exp(JOB_ACTOR),
                who->get_occupation_level(JOB_FARMER), who->get_occupation_exp(JOB_FARMER) );
        result += sprintf( "Thư sinh：%3d cấp %10d kinh nghiệm    Quan quân：%3d cấp %10d kinh nghiệm   Thương nhân：%3d cấp %10d kinh nghiệm\n", 
                who->get_occupation_level(JOB_SCHOLAR), who->get_occupation_exp(JOB_SCHOLAR),
                who->get_occupation_level(JOB_SOLDIER), who->get_occupation_exp(JOB_SOLDIER),
                who->get_occupation_level(JOB_TRADER), who->get_occupation_exp(JOB_TRADER) );

        tell_user(me, result);

        return 1;
}
