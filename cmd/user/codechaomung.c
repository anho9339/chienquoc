#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main(object me, string arg) 
{

    int p, cap, cap1, exist, i, size;
	string result,arg2,arg3,*line,*data;
    object item, item1, item2, item3, who;
		
		if( !arg ) return 1;
		if (arg==0) return 1;
		if ( me->get_level() < 60 )
		{
			send_user(me,"%c%s",';',sprintf("Cấp bậc %d không thể nhập Code.",me->get_level()));
			write_user(me, sprintf(ECHO"Cấp bậc %d không thể nhập Code.",me->get_level()));
			return 1;
		}
		if ( me->get_fam_name() == "" )
		{
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhập Code.");
			write_user(me, ECHO"Vô Môn Phái không thể nhập Code.");
			return 1;
		}
		if ( me->get_save("cmncm") > 0 || me->get_save("tancc") > 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			return 1;
			}
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		if ( arg2!="cqcms1da64f6qw" && 
			arg2!="cqcmsafqw456fg" &&  
			arg2!="cqcmohi45uh6ij" &&  
			arg2!="cqcmkj6hkj667j" && 
			arg2!="cqcmn82n4dsnfo" &&
			arg2!="cqcmjfw02ruj2d" &&
			arg2!="cqcmpqw09jf9fd" && // Done
			arg2!="cqcmiojdsof93d" && 
			arg2!="cqcm2qkopkđ3fn" &&
			arg2!="cqcmokmd3mf2kd" && 
			arg2!="cqcmwf902jdeks" && 
			arg2!="cqcmsd02dwjefw" && // Done
			arg2!="cqcmwofo02fiwn" && // Done
			arg2!="cqcmosjd2wfejd" && // Done
			arg2!="cqcmkdfjspo20f" &&  // Done
			arg2!="cqcmowpedo20fj" && // Done
			arg2!="cqcmksjdf3jfwk" && // Done
			arg2!="cqcmkjđw3fj93f" && // done
			arg2!="cqcmksjđ2j9wdd" && // Done
			arg2!="cqcmksdfif209f" && // Done
			arg2!="cqcmkdjof20fjw" && // Done
			arg2!="cqcmpkdopsk02r" && // Done
			arg2!="cqcmguiieg93gh" && // Done
			arg2!="cqcmksjdowr920" && // Done
			arg2!="cqcmkds94r03jf" && // Done
			arg2!="cqcmojđwjfklls" &&  // Done
			arg2!="cqcm83yrhfskdf" &&   // Done
			arg2!="cqcm92fidnslsj" &&  // Done
			arg2!="cqcmdsjfo9093w" && // Done
			arg2!="cqcm9wfjdfjskf" && // Done
			arg2!="cqcmladsjwejf9" && // Done
			arg2!="cqcmisdf39fjis" && // Done
			arg2!="cqcmisjd092fjd" && // Done
			arg2!="cqcmksdf92fisk" && // Done
			arg2!="cqcmsfdoiwjf02" &&  // Done
			arg2!="cqcmkafoish92f" && 
			arg2!="cqcmijadskoj92" && // Done
			arg2!="cqcmkadj9wh9jd" && // Done
			arg2!="cqcmakjdwf02uf" &&  
			arg2!="cqcmkajd92fisa" && 
			arg2!="cqcmkajd92jdij" &&
			arg2!="cqcmkadpq845hd" &&
			arg2!="cqcmkjfow9fiwf" &&
			arg2!="cqcmkafjdhg83d" &&
			arg2!="cqcmakdio2hfss" &&
			arg2!="cqcmakdj92hfuw" && 
			arg2!="cqcmkaj9hri7hs" &&
			arg2!="cqcm519uhdskad" &&
			arg2!="cqcmlajd9293jf" &&
			arg2!="cqcmad02938had"  ) 
		{
			send_user(me,"%c%s",';',"Bạn đã nhập sai Code.");
			write_user(me, ECHO"Bạn đã nhập sai Code.");
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
		case "cqcms1da64f6qw": 
			case "cqcmsafqw456fg":  
			case "cqcmohi45uh6ij":  
			case "cqcmkj6hkj667j": 
			case "cqcmn82n4dsnfo":
			case "cqcmjfw02ruj2d":
			case "cqcmpqw09jf9fd": 
			case "cqcmiojdsof93d": 
			case "cqcm2qkopkđ3fn":
			case "cqcmokmd3mf2kd": 
			case "cqcmwf902jdeks": 
			case "cqcmsd02dwjefw": 
			case "cqcmwofo02fiwn": 
			case "cqcmosjd2wfejd": 
			case "cqcmkdfjspo20f":  
			case "cqcmowpedo20fj": 
			case "cqcmksjdf3jfwk":
			case "cqcmkjđw3fj93f":
			case "cqcmksjđ2j9wdd":
			case "cqcmksdfif209f":
			case "cqcmkdjof20fjw":
			case "cqcmpkdopsk02r": 
			case "cqcmguiieg93gh":
			case "cqcmksjdowr920":
			case "cqcmkds94r03jf": 
			case "cqcmojđwjfklls":  
			case "cqcm83yrhfskdf":  
			case "cqcm92fidnslsj": 
			case "cqcmdsjfo9093w":
			case "cqcm9wfjdfjskf":
			case "cqcmladsjwejf9": 
			case "cqcmisdf39fjis": 
			case "cqcmisjd092fjd":
			case "cqcmksdf92fisk": 
			case "cqcmsfdoiwjf02": 
			case "cqcmkafoish92f": 
			case "cqcmijadskoj92": 
			case "cqcmkadj9wh9jd": 
			case "cqcmakjdwf02uf":  
			case "cqcmkajd92fisa": 
			case "cqcmkajd92jdij":
			case "cqcmkadpq845hd":
			case "cqcmkjfow9fiwf":
			case "cqcmkafjdhg83d":
			case "cqcmakdio2hfss":
			case "cqcmakdj92hfuw": 
			case "cqcmkaj9hri7hs":
			case "cqcm519uhdskad":
			case "cqcmlajd9293jf":
			case "cqcmad02938had": 
	
		if (exist >= 1) {
			send_user(me,"%c%s",';',"Code này đã có người sử dụng và đã hết hiệu lực.");
			write_user(me, ECHO"Code này đã có người sử dụng và đã hết hiệu lực.");
			return 1;
		}
		if ( me->get_fam_name()=="" )
		{	
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhận phần thưởng từ Code !");
			return 1;
		}
		if ( me->get_save("cmncm") > 0 || me->get_save("tancc") > 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			return 1;
			}
			
		 me->set_save("cmncm",1);
		// Gửi phần thưởng
		me->add_save("yuanbao",2000);
		//me->add_cash(1000000);
		item = new("item/event/tqcmncm");
			p = item->move(me,-1);
			item->add_to_user(p);
		  
		
		ghi_file("giftcode.txt",sprintf("%s Expiry\n",arg2));
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 