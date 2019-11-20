#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main(object me, string arg) 
{

    int p, cap, cap1, exist, i, size;
	string result,arg2,arg3,*line,*data;
    object item, item1, who;
		
		if( !arg ) return 1;
		if (arg==0) return 1;
		if ( me->get_level() >= 80 )
		{
			send_user(me,"%c%s",';',sprintf("Cấp bậc %d không thể nhập Code 8x.",me->get_level()));
			write_user(me, sprintf(ECHO"Cấp bậc %d không thể nhập Code 8x.",me->get_level()));
			return 1;
		}
		if ( me->get_fam_name() == "" )
		{
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhập Code 8x.");
			write_user(me, ECHO"Vô Môn Phái không thể nhập Code 8x.");
			return 1;
		}
		// 20 code
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		if ( arg2!="CQTD1b6321sbv" && // Done
			 arg2!="CQTD1421t615v" && 
			 arg2!="CQTDb4415be4f" && 
			 arg2!="CQTDb1rcx2d1d" && 
			 arg2!="CQTD79re4hg4g" &&  
			 arg2!="CQTDb16gw16ds" &&  
			 arg2!="CQTD1bbs1b64g" && 
			 arg2!="CQTD1vdj487bd" && 
			 arg2!="CQTD1b1d5jf5f" && 
			 arg2!="CQT1vdj5sv56d" && 
			 arg2!="CQTD43jqei6fq" && 
			 arg2!="CQTD64jgwbr42" &&
			 arg2!="CQTDbje5c6we5" && 
			 arg2!="CQTDbj4ae46rg" && 
			 arg2!="CQTD156w6enro" && 
			 arg2!="CQTD4e4jkuil1" && 
			 arg2!="CQTDlpkpyjy45" && 
			 arg2!="CQTDvdgdjt6w5" && 
			 arg2!="CQTD215jj21fp" && 
	         arg2!="CQTD15j4j44jy" && 
			 arg2!="CQTD65qnj6wqw" &&  
			 arg2!="CQTD165jmge6w" &&  
			 arg2!="CQTDlmtjj16ty" &&
			 arg2!="CQTD1nfjnb1mg" && 
			 arg2!="CQTD897j4y9sd" &&
			 arg2!="CQTD6ajw1u1fw" && 
			 arg2!="CQTD1sd1efjej" && 
			 arg2!="CQTD9e4jie4gb" && 
			 arg2!="CQTDb1s6j5gw6" && 
			 arg2!="CQTD15djpdsj8" && 
			 arg2!="CQTD4g9w4p9ge" &&
			 arg2!="CQTD1b42343sbv" &&
			 arg2!="CQTD1421tt615v" && 
			 arg2!="CQTDb441u5be4f" &&
			 arg2!="CQTDb15rcx2d1d" && 
			 arg2!="CQTD79rej4hg4g" &&  
			 arg2!="CQTDb16grw16ds" &&  
			 arg2!="CQTD1bbhs1b64g" && 
			 arg2!="CQTD1vdj4t87bd" &&
			 arg2!="CQTD1b1d5jjf5f" && 
			 arg2!="CQT1vdj5isv56d" &&
			 arg2!="CQTD43jqeii6fq" &&
			 arg2!="CQTD64jgywbr42" && 
			 arg2!="CQTDbje5ce6we5" && 
			 arg2!="CQTDbj4aue46rg" &&
			 arg2!="CQTD156w6eynro" &&
			 arg2!="CQTD4e4djkuil1" && 
			 arg2!="CQTDlpkphyjy45" && 
			 arg2!="CQTDvdgdjut6w5" && 
			 arg2!="CQTD215juj21fp" && 
	         arg2!="CQTD1t5j4j44jy" && 
			 arg2!="CQTD65qnj6wuqw" && 
			 arg2!="CQTD16u5jmge6w" && 
			 arg2!="CQTDlmtjj16tty" && 
			 arg2!="CQTD1nfjrnb1mg" &&  
			 arg2!="CQTD897j4y9isd" && 
			 arg2!="CQTD6ajw1u1ofw" && 
			 arg2!="CQTD1sd1pefjej" && 
			 arg2!="CQTD9e4jeie4gb" && 
			 arg2!="CQTDb1s6jl5gw6" &&
			 arg2!="CQTD15ddjpdsj8" && 
			 arg2!="CQTD4g9w4ph9ge" &&// Done 
			 arg2!="CQTDbg5215gg2g" && // Done 
			 arg2!="CQTD1g521g2nro" && // Done
			 arg2!="CQTD4g51tytyl1" && // Done
			 arg2!="CQTDlpg52gger5" && // Done
			 arg2!="CQTDvdther56r5" && // Done
			 arg2!="CQTD2teug89erg" && // Done
	         arg2!="CQTD1wsđ9jjfgf" && // Done
			 arg2!="CQTD65e9uj3kjw" &&  // Done
			 arg2!="CQTD1qw4wqre6w" &&  // Done
			 arg2!="CQTDl7weywgty" && // Done
			 arg2!="CQTD18rthe45g" && // Done
			 arg2!="CQTD895wtwtgd" &&
			 arg2!="CQTD6w67yuvgw" && 
			 arg2!="CQTD1we56ewtej" && // Done
			 arg2!="CQTD9ew6wgtwb" && // Done
			 arg2!="CQTDbw6wyhwg6" && // Done
			 arg2!="CQTD15dw6whg8" && // Done
			 arg2!="CQTD4g9w6wywg" && // Done
			 arg2!="CQTD14gger4bv" && // Done
			 arg2!="CQTD1tree615v" && // Done
			 arg2!="CQTDb44547y4f" && // Done
			 arg2!="CQTDbtre7hg1d" && //Done
			 arg2!="CQTD79rr7ereg" && // Done  
			 arg2!="CQTDb1rê7rehs" && // Done  
			 arg2!="CQTD1bbr3r74g" && // Done
			 arg2!="CQTD1sety6y7bd" && // Done
			 arg2!="CQTDb14214rf5f" && // Done
			 arg2!="CQT1vdj4634g6d" && // Done
			 arg2!="CQTD43we5fggfq" && // Done
			 arg2!="CQTD64vaeret42" && // Done
			 arg2!="CQTDb536ydese5" && // Done
			 arg2!="CQTDbj61gtr6g" &&
			 arg2!="CQTD156rew67yw" &&
			 arg2!="CQTD4ew6632il1" && 
			 arg2!="CQTDlew6gwe45" && 
			 arg2!="CQTDvdg65t325" && 
			 arg2!="CQTDwew2557fp" && 
	         arg2!="CQTD1t5we6e6yjy" && 
			 arg2!="CQTD65ew5ew5qw" && 
			 arg2!="CQTD16ae7uyy6w" && 
			 arg2!="CQTDlmjsg63ty" && 
			 arg2!="CQTD1nyret78g" &&  
			 arg2!="CQTD897rt83sd" && 
			 arg2!="CQTD6ajyrt7fw" && 
			 arg2!="CQTD1sd1re6jej" && 
			 arg2!="CQTD9e4jer634gb" && 
			 arg2!="CQTDbewq469gw6" &&
			 arg2!="CQTD15ddjre78" ) 
		{
			send_user(me,"%c%s",';',"Bạn đã nhập sai Code 8x.");
			write_user(me, ECHO"Bạn đã nhập sai Code 8x.");
			return 1;
		}
		line = explode(read_file("giftcode.txt"), "\n");
		for (i = 0, size = sizeof(line); i < size; i++) 
		{
			data = explode(line[i], " ");
			if (arg2 == data[0]) 
			{
            exist = 1;
			break;
			}
		}
	switch ( arg2 )
	{
		case "CQTD1b6321sbv": 
			 case "CQTD1421t615v": 
			 case "CQTDb4415be4f": 
			 case "CQTDb1rcx2d1d": 
			 case "CQTD79re4hg4g":  
			 case "CQTDb16gw16ds":  
			 case "CQTD1bbs1b64g": 
			 case "CQTD1vdj487bd": 
			 case "CQTD1b1d5jf5f":  
			 case "CQT1vdj5sv56d":
			 case "CQTD43jqei6fq":
			 case "CQTD64jgwbr42": 
			 case "CQTDbje5c6we5": 
			 case "CQTDbj4ae46rg":
			 case "CQTD156w6enro": 
			 case "CQTD4e4jkuil1": 
			 case "CQTDlpkpyjy45": 
			 case "CQTDvdgdjt6w5": 
			 case "CQTD215jj21fp": 
	         case "CQTD15j4j44jy":
			 case "CQTD65qnj6wqw": 
			 case "CQTD165jmge6w": 
			 case "CQTDlmtjj16ty": 
			 case "CQTD1nfjnb1mg": 
			 case "CQTD897j4y9sd": 
			 case "CQTD6ajw1u1fw": 
			 case "CQTD1sd1efjej":
			 case "CQTD9e4jie4gb": 
			 case "CQTDb1s6j5gw6": 
			 case "CQTD15djpdsj8": 
			 case "CQTD4g9w4p9ge": 
			 case "CQTD1b42343sbv":
			 case "CQTD1421tt615v":
			 case "CQTDb441u5be4f":
			 case "CQTDb15rcx2d1d":
			 case "CQTD79rej4hg4g": 
			 case "CQTDb16grw16ds": 
			 case "CQTD1bbhs1b64g":
			 case "CQTD1vdj4t87bd":
			 case "CQTD1b1d5jjf5f":
			 case "CQT1vdj5isv56d":
			 case "CQTD43jqeii6fq":
			 case "CQTD64jgywbr42":
			 case "CQTDbje5ce6we5":
			 case "CQTDbj4aue46rg":
			 case "CQTD156w6eynro":
			 case "CQTD4e4djkuil1":
			 case "CQTDlpkphyjy45":
			 case "CQTDvdgdjut6w5":
			 case "CQTD215juj21fp":
	         case "CQTD1t5j4j44jy":
			 case "CQTD65qnj6wuqw": 
			 case "CQTD16u5jmge6w": 
			 case "CQTDlmtjj16tty":
			 case "CQTD1nfjrnb1mg":
			 case "CQTD897j4y9isd":
			 case "CQTD6ajw1u1ofw":
			 case "CQTD1sd1pefjej":
			 case "CQTD9e4jeie4gb":
			 case "CQTDb1s6jl5gw6": 
			 case "CQTD15ddjpdsj8":
			 case "CQTD4g9w4ph9ge":
			 case "CQTDbg5215gg2g": 
			 case "CQTD1g521g2nro": 
			 case "CQTD4g51tytyl1": 
			 case "CQTDlpg52gger5": 
			 case "CQTDvdther56r5": 
			 case "CQTD2teug89erg": 
	         case "CQTD1wsđ9jjfgf": 
			 case "CQTD65e9uj3kjw":  
			 case "CQTD1qw4wqre6w":  
			 case "CQTDl7weywgty":
			 case "CQTD18rthe45g": 
			 case "CQTD895wtwtgd":
			 case "CQTD6w67yuvgw": 
			 case "CQTD1we56ewtej": 
			 case "CQTD9ew6wgtwb": 
			 case "CQTDbw6wyhwg6": 
			 case "CQTD15dw6whg8": 
			 case "CQTD4g9w6wywg":
			 case "CQTD14gger4bv":
			 case "CQTD1tree615v": 
			 case "CQTDb44547y4f":
			 case "CQTDbtre7hg1d": 
			 case "CQTD79rr7ereg":  
			 case "CQTDb1rê7rehs":  
			 case "CQTD1bbr3r74g": 
			 case "CQTD1sety6y7bd":
			 case "CQTDb14214rf5f": 
			 case "CQT1vdj4634g6d":
			 case "CQTD43we5fggfq":
			 case "CQTD64vaeret42": 
			 case "CQTDb536ydese5": 
			 case "CQTDbj61gtr6g":
			 case "CQTD156rew67yw":
			 case "CQTD4ew6632il1": 
			 case "CQTDlew6gwe45": 
			 case "CQTDvdg65t325": 
			 case "CQTDwew2557fp": 
	         case "CQTD1t5we6e6yjy": 
			 case "CQTD65ew5ew5qw": 
			 case "CQTD16ae7uyy6w": 
			 case "CQTDlmjsg63ty": 
			 case "CQTD1nyret78g":  
			 case "CQTD897rt83sd": 
			 case "CQTD6ajyrt7fw": 
			 case "CQTD1sd1re6jej": 
			 case "CQTD9e4jer634gb": 
			 case "CQTDbewq469gw6":
			 case "CQTD15ddjre78": 
		if (exist >= 1) {
			send_user(me,"%c%s",';',"Code 8x này đã có người sử dụng và đã hết hiệu lực.");
			write_user(me, ECHO"Code 8x này đã có người sử dụng và đã hết hiệu lực.");
			return 1;
		}
		if ( me->get_fam_name()=="" )
		{	
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhận phần thưởng từ Code 8x !");
			return 1;
		}

		cap = 80;//skill
		cap1 = 80;//cấp
		if ( me->get_fam_name()=="Đào Hoa Nguyên" )
		{	
me->set_skill(0211, cap);me->set_skill(0212, cap);me->set_skill(0316, cap);me->set_skill(0317, cap);me->set_skill(0319, cap);
		}
		else if ( me->get_fam_name()=="Thục Sơn" )	
		{	
me->set_skill(0221, cap);me->set_skill(0231, cap);me->set_skill(0222, cap);me->set_skill(0325, cap);me->set_skill(0329, cap);	
		}
		else if ( me->get_fam_name()=="Cấm Vệ Quân" )	
		{	
me->set_skill(0241, cap);me->set_skill(0251, cap);me->set_skill(0242, cap);me->set_skill(0348, cap);me->set_skill(0349, cap);	
		}
		else if ( me->get_fam_name()=="Đường Môn" )	
		{	
me->set_skill(0261, cap);me->set_skill(0363, cap);me->set_skill(0364, cap);me->set_skill(0365, cap);me->set_skill(0368, cap);	
		}
		else if ( me->get_fam_name()=="Mao Sơn" )	
		{	
me->set_skill(0271, cap);me->set_skill(0413, cap);me->set_skill(0414, cap);me->set_skill(0417, cap);me->set_skill(0418, cap);	
		}
		else if ( me->get_fam_name()=="Côn Luân" )	
		{	
me->set_skill(0421, cap);me->set_skill(0422, cap);me->set_skill(0423, cap);me->set_skill(0424, cap);me->set_skill(0425, cap);me->set_skill(0426, cap);	
		}
		else if ( me->get_fam_name()=="Vân Mộng Cốc" )	
		{	
me->set_skill(0281, cap);me->set_skill(0501, cap);me->set_skill(0511, cap);me->set_skill(0531, cap);me->set_skill(0591, cap);	
		}
		me->set_level(cap1);
		me->count_gift();
		USER_ENERGY_D->count_all_prop(me);
        USER_ENERGY_D->count_max_yuan(me);
		me->set_hp( me->get_max_hp() );
        me->set_mp( me->get_max_mp() ); 
		me->add_save("yuanbao",2000);
		me->add_cash(500000);
		ghi_file("giftcode.txt",sprintf("%s Expiry\n",arg2));
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code 8x thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 