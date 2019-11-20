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
		if ( me->get_save("tancc") > 0 || me->get_save("cmncm") > 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			return 1;
			}
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		if ( arg2!="cqtajaskfj23n" && // Done
			 arg2!="cqta1as56vfwf" &&  // Done
			 arg2!="cqtasf454f5ew" &&  // Done 
			 arg2!="cqtav15d56dfg" && // Done
			 arg2!="cqtav1564f564" && // Done
 			 arg2!="cqtab1fd156gr" && // Done
			 arg2!="cqta4re4re1vg" && // Done
			 arg2!="cqta564b6d4ge" && // Done
			 arg2!="cqta1v56sd16d" && // Done
			 arg2!="cqtab1df15ege" && // Done
			 arg2!="cqtav1ds21ewe" && 
			 arg2!="cqtab4r456r1g" && 
			 arg2!="cqtaj4y5tjy56" && 
			 arg2!="cqtai4uyi65nb" && // Done
			 arg2!="cqta1bdf56465" &&  // Done
			 arg2!="cqta4ngf8r1yb" && // Done
			 arg2!="cqtab1d54f564" && // Done
			 arg2!="cqtab156165fe" && // Done
			 arg2!="cqtav1ds515ew" && // Done
			 arg2!="cqtab1f1561e6" && // Done
			 arg2!="cqta15ds1651g" && // Done
			 arg2!="cqta1bdf6156g" && // DOne
			 arg2!="cqtab1fd51f5e" && // Done
             arg2!="cqtak1jh51hg3" && // Done
			 arg2!="cqta1b54h65et" && // DOne
			 arg2!="cqtab1d5f4f56" && // Done 
			 arg2!="cqtab1fd156ew" &&  
			 arg2!="cqta1bd1456ew" && 
			 arg2!="cqtaw4e64r6ge" &&
 			 arg2!="cqtab2f156ewc" &&
			 arg2!="cqta1g56156ew" && 
			 arg2!="cqtab2fd13wer" && 
			 arg2!="cqta1d2s1g5e1" &&
			 arg2!="cqta15615ew1w" && 
			 arg2!="cqta1b1efe1ff" && 
			 arg2!="cqta1i5u1o1h6" && 
			 arg2!="cqta1561g5lpw" && 
			 arg2!="cqta1b5s6456g" && 
			 arg2!="cqtab231bd5ew" &&  
			 arg2!="cqta1vsd156ew" && 
			 arg2!="cqta154e654re" &&
			 arg2!="cqta4r6e4wvew" &&
			 arg2!="cqtav1d153swf" &&
			 arg2!="cqta4w84e61vs" &&
			 arg2!="cqta1f56w456w" &&
			 arg2!="cqta1vcx2v1ew" && 
			 arg2!="cqta1231v65wc" &&
             arg2!="cqta15q4rwqpo" &&
			 arg2!="cqtapo15f1lfe" &&
			 arg2!="cqta1v3d415eq"  ) 
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
		case "cqtajaskfj23n":
			 case "cqta1as56vfwf": 
			 case "cqtasf454f5ew": 
			 case "cqtav15d56dfg":
			 case "cqtav1564f564":
 			 case "cqtab1fd156gr":
			 case "cqta4re4re1vg":
			 case "cqta564b6d4ge":
			 case "cqta1v56sd16d":
			 case "cqtab1df15ege":
			 case "cqtav1ds21ewe":
			 case "cqtab4r456r1g":
			 case "cqtaj4y5tjy56":
			 case "cqtai4uyi65nb":
			 case "cqta1bdf56465": 
			 case "cqta4ngf8r1yb":
			 case "cqtab1d54f564":
			 case "cqtab156165fe":
			 case "cqtav1ds515ew":
			 case "cqtab1f1561e6":
			 case "cqta15ds1651g":
			 case "cqta1bdf6156g":
			 case "cqtab1fd51f5e":
             case "cqtak1jh51hg3":
			 case "cqta1b54h65et":
			 case "cqtab1d5f4f56": 
			 case "cqtab1fd156ew": 
			 case "cqta1bd1456ew":
			 case "cqtaw4e64r6ge":
 			 case "cqtab2f156ewc":
			 case "cqta1g56156ew":
			 case "cqtab2fd13wer":
			 case "cqta1d2s1g5e1":
			 case "cqta15615ew1w":
			 case "cqta1b1efe1ff":
			 case "cqta1i5u1o1h6":
			 case "cqta1561g5lpw":
			 case "cqta1b5s6456g":
			 case "cqtab231bd5ew": 
			 case "cqta1vsd156ew":
			 case "cqta154e654re":
			 case "cqta4r6e4wvew":
			 case "cqtav1d153swf":
			 case "cqta4w84e61vs":
			 case "cqta1f56w456w":
			 case "cqta1vcx2v1ew":
			 case "cqta1231v65wc":
             case "cqta15q4rwqpo":
			 case "cqtapo15f1lfe":
			 case "cqta1v3d415eq":
	
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
		if ( me->get_save("tancc") > 0 || me->get_save("cmncm") > 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Tri Ân hoặc Chào Mừng rồi.");
			return 1;
			}
			
		 me->set_save("tancc",1);
		// Gửi phần thưởng
		  me->add_save("yuanbao",5000);
		//	me->add_cash(1000000);
		item = new("item/event/tqtancc");
			p = item->move(me,-1);
			item->add_to_user(p);
		  
		
		ghi_file("giftcode.txt",sprintf("%s Expiry\n",arg2));
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 