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
		if ( me->get_level() < 40 )
		{
			send_user(me,"%c%s",';',sprintf("Cấp bậc %d không thể nhập Code Năm Mới.",me->get_level()));
			write_user(me, sprintf(ECHO"Cấp bậc %d không thể nhập Code Năm Mới.",me->get_level()));
			return 1;
		}
		if ( me->get_fam_name() == "" )
		{
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhập Code Năm Mới.");
			write_user(me, ECHO"Vô Môn Phái không thể nhập Code Năm Mới.");
			return 1;
		}
		if ( me->get_save("tqnm")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code năm mới rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code năm mới rồi.");
			return 1;
			}
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		if ( arg2!="cqlxh4k32jh4" && // Done
			arg2!="cqlx2lkj4lkf" &&  // Done
			arg2!="cqlxdbsfj2r3" &&  // Done
			arg2!="cqlxjhfdh28e" &&  // Done
			arg2!="cqlxadsbbfk0" && // Done
			arg2!="cqlxjfjiwfs2" && // Done
			arg2!="cqlx3xy283hd" &&  // Done
			arg2!="cqlxdv93jhw8" &&  // Done
			arg2!="cqlxqowj2hfh" && // Done
			arg2!="cqlxi0129fhu" &&  // Done
			arg2!="cqlxaidj092d" &&  // Done
			arg2!="cqlxi920fjwe" && // Done
			arg2!="cqlxi29dsfsj" && // Done
			arg2!="cqlxq92hudhj" && // Done
			arg2!="cqlxwif92hfu" &&  // Done
			arg2!="cqlxjd82hfuf" && // Done
			arg2!="cqlxndf92fnd" && // Done
			arg2!="cqlxjsh89fhs" && // Done
			arg2!="cqlxakd29hfd" && // Done
			arg2!="cqlxaj83hc92" && // Done
			arg2!="cqlxndjsbdf9" && // Done
			arg2!="cqlxnsf892fn" && // Done
			arg2!="cqlxdbif28fa" && // Done
			arg2!="cqlxnvj982fs" && // Done
			arg2!="cqlxbvsi82fa" && // Done
			arg2!="cqlxnviw832h" && // Done  
			arg2!="cqlxnsjdfn92" && // Done 
			arg2!="cqlxniw82fwa" && // Done 
			arg2!="cqlxvbis28fw" && // Done
			arg2!="cqlxncsiu82f" &&
			arg2!="cqlxnc8w9fhw" && 
			arg2!="cqlxncs92fh0" && 
			arg2!="cqlxc9s92hfs" &&
			arg2!="cqlxncs920fa" && 
			arg2!="cqlxns992fus" && 
			arg2!="cqlxvbi281rs" && 
			arg2!="cqlxvnso92fh" && 
			arg2!="cqlxnw92hf8w" && 
			arg2!="cqlxnci92rh8" &&  
			arg2!="cqlxna92hfwi" && 
			arg2!="cqlxns98adsf" &&
			arg2!="cqlx91rudsjf" &&
			arg2!="cqlx91r8dkad" &&
			arg2!="cqlxbauii28f" &&
			arg2!="cqlxba882eds" &&
			arg2!="cqlxanf92fhu" && 
			arg2!="cqlxbca82rfh" &&
			arg2!="cqlxnc992hfa" &&
			arg2!="cqlxushf92fd" &&
			arg2!="cqlxfnuiw929"  ) 
		{
			send_user(me,"%c%s",';',"Bạn đã nhập sai Code Năm Mới.");
			write_user(me, ECHO"Bạn đã nhập sai Code Năm Mới.");
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
			case "cqlxh4k32jh4": 
			case "cqlx2lkj4lkf":  
			case "cqlxdbsfj2r3":  
			case "cqlxjhfdh28e": 
			case "cqlxadsbbfk0":
			case "cqlxjfjiwfs2":
			case "cqlx3xy283hd": 
			case "cqlxdv93jhw8": 
			case "cqlxqowj2hfh":
			case "cqlxi0129fhu": 
			case "cqlxaidj092d": 
			case "cqlxi920fjwe": 
			case "cqlxi29dsfsj": 
			case "cqlxq92hudhj": 
			case "cqlxwif92hfu":  
			case "cqlxjd82hfuf": 
			case "cqlxndf92fnd":
			case "cqlxjsh89fhs":
			case "cqlxakd29hfd":
			case "cqlxaj83hc92":
			case "cqlxndjsbdf9":
			case "cqlxnsf892fn": 
			case "cqlxdbif28fa":
			case "cqlxnvj982fs":
			case "cqlxbvsi82fa": 
			case "cqlxnviw832h":  
			case "cqlxnsjdfn92":  
			case "cqlxniw82fwa": 
			case "cqlxvbis28fw":
			case "cqlxncsiu82f":
			case "cqlxnc8w9fhw": 
			case "cqlxncs92fh0": 
			case "cqlxc9s92hfs":
			case "cqlxncs920fa": 
			case "cqlxns992fus": 
			case "cqlxvbi281rs": 
			case "cqlxvnso92fh": 
			case "cqlxnw92hf8w": 
			case "cqlxnci92rh8":  
			case "cqlxna92hfwi": 
			case "cqlxns98adsf":
			case "cqlx91rudsjf":
			case "cqlx91r8dkad":
			case "cqlxbauii28f":
			case "cqlxba882eds":
			case "cqlxanf92fhu": 
			case "cqlxbca82rfh":
			case "cqlxnc992hfa":
			case "cqlxushf92fd":
			case "cqlxfnuiw929":

		if (exist >= 1) {
			send_user(me,"%c%s",';',"Code Năm Mới này đã có người sử dụng và đã hết hiệu lực.");
			write_user(me, ECHO"Code Năm Mới này đã có người sử dụng và đã hết hiệu lực.");
			return 1;
		}
		if ( me->get_fam_name()=="" )
		{	
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhận phần thưởng từ Code Năm Mới !");
			return 1;
		}
		if ( me->get_save("tqnm")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code năm mới rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code năm mới rồi.");
			return 1;
			}
			
		 me->set_save("tqnm",1);
		// Gửi phần thưởng
		    item = new("item/event/tet/tqnm");
			p = item->move(me,-1);
			item->add_to_user(p);
		  
		
		ghi_file("giftcode.txt",sprintf("%s Expiry\n",arg2));
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code Năm Mới thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 