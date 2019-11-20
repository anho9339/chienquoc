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
		if ( me->get_level() >= 60 )
		{
			send_user(me,"%c%s",';',sprintf("Cấp bậc %d không thể nhập Code Tân Thủ.",me->get_level()));
			write_user(me, sprintf(ECHO"Cấp bậc %d không thể nhập Code Tân Thủ.",me->get_level()));
			return 1;
		}
		if ( me->get_fam_name() == "" )
		{
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhập Code Tân Thủ.");
			write_user(me, ECHO"Vô Môn Phái không thể nhập Code Tân Thủ.");
			return 1;
		}
		// 20 code
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		if ( arg2!="CQTD1b61d6vnsbv" && // Done
			 arg2!="CQTD1v6d1vt61sv" && // Done
			 arg2!="CQTDb4fb6uf4e4f" && // Done
			 arg2!="CQTDb1rcxb1wd1d" && // Done
			 arg2!="CQTD79re4hid64g" &&  //Done
			 arg2!="CQTDb16kdsw16ds" && // Done 
			 arg2!="CQTD1bd6js1b64g" && 
			 arg2!="CQTD1vdj48v47bd" && 
			 arg2!="CQTD1b1d5jbgf5f" &&  
			 arg2!="CQTD1vdj5s1v56d" &&
			 arg2!="CQTD43qjjqei6fq" &&
			 arg2!="CQTD64j6gw6br42" && 
			 arg2!="CQTDbjeg5ce6we5" && 
			 arg2!="CQTDbbj46ae46rg" &&
			 arg2!="CQTD1j564hw6ero" && 
			 arg2!="CQTD4e4juukuil1" && 
			 arg2!="CQTDlpkpjhyjy45" && 
			 arg2!="CQTDvdgdjtsg6w5" && // Done
			 arg2!="CQTD215jj21fkop" && 
	         arg2!="CQTD15j45nj44jy" && // Done
			 arg2!="CQTD65qnj4f6wqw" && // Done
			 arg2!="CQTD165e1jmge6w" && // Done
			 arg2!="CQTDlk1mtjj16ty" && // Done
			 arg2!="CQTD1nfj65nb1mg" && // Done
			 arg2!="CQTD8979gj4y9sd" && // Done
			 arg2!="CQTD6ajw1wqu1fw" && 
			 arg2!="CQTD1sd1ekwfjej" &&
			 arg2!="CQTD9e49wjie4gb" && // Done
			 arg2!="CQTDb1s6j51ogw6" && // Done
			 arg2!="CQTD15dj1sbpds8" && // Done
			 arg2!="CQTD4g9jevw49ge" && // Done
			 arg2!="CQTD1b6421444bv" && // Done
			 arg2!="CQTD1v65456tbsv" && // DOne
			 arg2!="CQTDb4fb6ret4rf" && // Done
			 arg2!="CQTDb1325b1wd1d" && // Done
			 arg2!="CQTD79re67id64g" &&  // dONE
			 arg2!="CQTDb167hgdr6ds" && // Done
			 arg2!="CQTD1bd6jer464g" && // Done
			 arg2!="CQTD1vdj45rffbd" && // Done
			 arg2!="CQTD1b5345bgf5f" &&  // Done
			 arg2!="CQTD1vdj7t1v56d" && // Done
			 arg2!="CQTD43qj564y6fq" && // Done
			 arg2!="CQTD64jer3ghr42" && // Done
			 arg2!="CQTDb56hghjuwe5" && // Done
			 arg2!="CQTDb46a9u4j6rg" && // Done
			 arg2!="CQTD1j54htu6ero" && // Done
			 arg2!="CQTD4e9jgkelrl1" && // Done
			 arg2!="CQTD23o5jgbjy45" && // Done
			 arg2!="CQTDv9jhrehn4w5" && // Done
			 arg2!="CQTD215498jgkop" && // Done
	         arg2!="CQTD1545ehfhhjy" && // Done
			 arg2!="CQTD65q7uyerybw" && // Done
			 arg2!="CQTD1rr4grehrew" && // Done
			 arg2!="CQTDlk1jiirfhty" && // DOne
			 arg2!="CQTD1n35gehnnmg" && 
			 arg2!="CQTD8943erhhdgd" &&
			 arg2!="CQTD643534gu1fw" && 
			 arg2!="CQTD16hfherenej" &&
			 arg2!="CQTD9e45hrhehhb" && 
			 arg2!="CQTDb145yerhnd6" && 
			 arg2!="CQTD157563dfds8" && 
			 arg2!="CQTD4g95654uytr") 
		{
			send_user(me,"%c%s",';',"Bạn đã nhập sai Code Tân Thủ.");
			write_user(me, ECHO"Bạn đã nhập sai Code Tân Thủ.");
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
		case "CQTD1b61d6vnsbv": 
		case "CQTD1v6d1vt61sv": 
		case "CQTDb4fb6uf4e4f": 
		case "CQTDb1rcxb1wd1d": 
		case "CQTD79re4hid64g":  
		case "CQTDb16kdsw16ds":  
		case "CQTD1bd6js1b64g": 
		case "CQTD1vdj48v47bd": 
		case "CQTD1b1d5jbgf5f":  
		case "CQTD1vdj5s1v56d":
		case "CQTD43qjjqei6fq":
		case "CQTD64j6gw6br42": 
		case "CQTDbjeg5ce6we5": 
		case "CQTDbbj46ae46rg":
		case "CQTD1j564hw6ero": 
		case "CQTD4e4juukuil1": 
		case "CQTDlpkpjhyjy45": 
		case "CQTDvdgdjtsg6w5": 
		case "CQTD215jj21fkop": 
		case "CQTD15j45nj44jy":
		case "CQTD65qnj4f6wqw": 
		case "CQTD165e1jmge6w": 
		case "CQTDlk1mtjj16ty": 
		case "CQTD1nfj65nb1mg": 
		case "CQTD8979gj4y9sd": 
		case "CQTD6ajw1wqu1fw": 
		case "CQTD1sd1ekwfjej":
		case "CQTD9e49wjie4gb": 
		case "CQTDb1s6j51ogw6": 
		case "CQTD15dj1sbpds8": 
		case "CQTD4g9jevw49ge":
		case "CQTD1b6421444bv":
	 case "CQTD1v65456tbsv":
	 case "CQTDb4fb6ret4rf":
	 case "CQTDb1325b1wd1d":
	 case "CQTD79re67id64g": 
	 case "CQTDb167hgdr6ds":
	 case "CQTD1bd6jer464g":
	 case "CQTD1vdj45rffbd":
	 case "CQTD1b5345bgf5f": 
	 case "CQTD1vdj7t1v56d":
	 case "CQTD43qj564y6fq":
	 case "CQTD64jer3ghr42":
	 case "CQTDb56hghjuwe5":
	 case "CQTDb46a9u4j6rg":
	 case "CQTD1j54htu6ero":
	 case "CQTD4e9jgkelrl1":
	 case "CQTD23o5jgbjy45":
	 case "CQTDv9jhrehn4w5":
	 case "CQTD215498jgkop":
	 case "CQTD1545ehfhhjy":
	 case "CQTD65q7uyerybw":
	 case "CQTD1rr4grehrew":
	 case "CQTDlk1jiirfhty":
	 case "CQTD1n35gehnnmg":
	 case "CQTD8943erhhdgd":
	 case "CQTD643534gu1fw":
	 case "CQTD16hfherenej":
	 case "CQTD9e45hrhehhb":
	 case "CQTDb145yerhnd6":
	 case "CQTD157563dfds8": 
	 case "CQTD4g95654uytr":
		if (exist >= 1) {
			send_user(me,"%c%s",';',"Code Tân Thủ này đã có người sử dụng và đã hết hiệu lực.");
			write_user(me, ECHO"Code Tân Thủ này đã có người sử dụng và đã hết hiệu lực.");
			return 1;
		}
		if ( me->get_fam_name()=="" )
		{	
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhận phần thưởng từ Code Tân Thủ !");
			return 1;
		}

		cap = 65;//skill
		cap1 = 60;//cấp
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
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code Tân Thủ thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 