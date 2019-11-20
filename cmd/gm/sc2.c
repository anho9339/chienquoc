
#include <ansi.h>
#include <city.h>

// 函数：命令处理
int main( object me, string arg )
{
        object who = me;
        string city;
        string result;
        int i, cash, exp, pot, times, cash2, exp2, pot2, times2;

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
                result = sprintf( "%s thuế hồng ghi chép：Thuế hồng(còn thừa)/Cống hiến", city->get_name() );
                for( i = 1; i <= 30; i ++ ) result = sprintf( "%s%s%d(%d)/%d, ", result, (i - 1) % 5 ? "" : "\n", 
                        city->get_salary_0(i), city->get_salary_2(i), city->get_contribute_0(i) );

                tell_user(me, result);

		return 1;
        }

        if( arg && !( who = find_player(arg) ) ) 
        {
                notify( "Không thấy người này。" );
		return 1;
        }

        result = sprintf( "Kinh nghiệm thưởng：%s(%d)  %d\n", who->get_name(), who->get_number(), who->get_exp() );

        times = who->get_log("#task");  exp = who->get_log("&task");
        times2 = who->get_log("#task2");  exp2 = who->get_log("&task2");  pot2 = who->get_log("*task2");

        result += sprintf( "Sứ mạng(%d)：%d *%d ＝ Vật phẩm(%d)：%d ＋nhân vật(%d)：%d *%d  Đánh chiếm(%d)：%d *%d\n",
                times + times2, exp + exp2, pot2, times, exp, times2, exp2, pot2,
                who->get_log("#npc"), who->get_log("&npc"), who->get_log("*npc") );
        result += sprintf( "Trừ phiến loạn(%d)：%d *%d  Sư gia(%d)：%d *%d\n",
                who->get_log("#banditi"), who->get_log("&banditi"), who->get_log("*banditi"),
                who->get_log("#robber"), who->get_log("&robber"), who->get_log("*robber") );

        times = who->get_log("#monster");  exp = who->get_log("&monster");  pot = who->get_log("*monster");
        times2 = who->get_log("#monster2");  exp2 = who->get_log("&monster2");  pot2 = who->get_log("*monster2");

        result += sprintf( "Trọng phạm(%d)：%d *%d  Bảo đồ(%d)：%d *%d ＝ Giết đồ(%d)：%d *%d ＋ để đồ(%d)：%d *%d\n",
                who->get_log("#criminal"), who->get_log("&criminal"), who->get_log("*criminal"),
                times + times2, exp + exp2, pot + pot2, times, exp, pot, times2, exp2, pot2 );

        times = who->get_log("#escort");  cash = who->get_log("$escort");  exp = who->get_log("&escort");
        times2 = who->get_log("#escort2");  cash2 = who->get_log("$escort2");  exp2 = who->get_log("&escort2");

        result += sprintf( "Thất thiết(%d)：$%d %d *%d  Vận tiêu(%d)：$%d %d ＝ thành công(%d)：$%d %d ＋thất bại(%d)：$%d %d\n",
                who->get_log("#thief"), who->get_log("$thief"), who->get_log("&thief"), who->get_log("*thief"),
                times + times2, cash + cash2, exp + exp2, times, cash, exp, times2, cash2, exp2 );

        tell_user(me, result);

        result = sprintf( "Bỏ lại：%d %09d  Giãn khởi：%d %09d  Cho người khác：%d %09d  người khác cho：%d %09d\n", 
                who->get_log("$drop$H"), who->get_log("$drop$L"), who->get_log("$get$H"), who->get_log("$get$L"),
                who->get_log("$give$H"), who->get_log("$give$L"), who->get_log("$give2$H"), who->get_log("$give2$L") );

        result += sprintf( "Giao dịch cho：%d %09d  Giao dịch thu：%d %09d\n", 
                who->get_log("$exchange$H"), who->get_log("$exchange$L"), who->get_log("$exchange2$H"), who->get_log("$exchange2$L") );

        result += sprintf( "Mua vào：%d %09d  Bán ra：%d %09d  Than mua：%d %09d  Than bán：%d %09d\n", 
                who->get_log("$buy$H"), who->get_log("$buy$L"), who->get_log("$sell$H"), who->get_log("$sell$L"),
                who->get_log("$buy2$H"), who->get_log("$buy2$L"), who->get_log("$sell2$H"), who->get_log("$sell2$L") );

        result += sprintf( "Ngày lễ：%d %09d  Nhiệm vụ：%d %09d  Vận tiêu：%d %09d  Buôn bán：%d %09d\n", 
                who->get_log("$date$H"), who->get_log("$date$L"), who->get_log("$task$H"), who->get_log("$task$L"), 
                who->get_log("$biao$H"), who->get_log("$biao$L"), who->get_log("$trade$H"), who->get_log("$trade$L") );

        result += sprintf( "Sửa chữa：%d %09d  Hợp thành：%d %09d  Quyên góp：%d %09d\n", 
                who->get_log("$repair$H"), who->get_log("$repair$L"), who->get_log("$make$H"), who->get_log("$make$L"),
                who->get_log("$org$H"), who->get_log("$org$L") );

        result += sprintf( "Học tập：%d %09d  Hệ thống：%d %09d  Khác：%d %09d\n", 
                who->get_log("$learn$H"), who->get_log("$learn$L"), who->get_log("$pay$H"), who->get_log("$pay$L"),
                who->get_log("$????$H"), who->get_log("$????$L") );

        tell_user(me, result);

	result = USER_TASK_D->get_task_done(who);
	if (result!="" && result!=0) tell_user( me, result );

        return 1;
}
