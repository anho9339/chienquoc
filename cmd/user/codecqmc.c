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
			send_user(me,"%c%s",';',sprintf("Cấp bậc %d không thể nhập Code CQMC.",me->get_level()));
			write_user(me, sprintf(ECHO"Cấp bậc %d không thể nhập Code CQMC.",me->get_level()));
			return 1;
		}
		if ( me->get_fam_name() == "" )
		{
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhập Code CQMC.");
			write_user(me, ECHO"Vô Môn Phái không thể nhập Code CQMC.");
			return 1;
		}
		if ( me->get_save("cqmc")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code CQMC rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code CQMC rồi.");
			return 1;
			}
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		if ( /*arg2!="cqmc1564wq6f4" && 
			 arg2!="cqmc4f6wq4f6f" &&  
			 arg2!="cqmcgd65446ge" &&  
			 arg2!="cqmc54fqw46qw" && 
			 arg2!="cqmc4qw46fwq4" &&
 			 arg2!="cqmc48wqr41bz" &&
			 arg2!="cqmc489e49eq2" && 
			 arg2!="cqmc456s4fqw8" && 
			 arg2!="cqmc1asf4a612" &&
			 arg2!="cqmc456q4wfqw" && 
			 arg2!="cqmc1sdb54d6e" && 
			 arg2!="cqmc4sd6f46eh" && 
			 arg2!="cqmc4sd3e1rew" && 
			 arg2!="cqmc1asf1aq6w" && 
			 arg2!="cqmcs1a561fav" &&  
			 arg2!="cqmc16w1r6wqf" && 
			 arg2!="cqmcas461g6aw" &&
			 arg2!="cqmc1as6f4sa6" &&
			 arg2!="cqmciopgsdi12" &&
			 arg2!="cqmcuy1l566t1" &&
			 arg2!="cqmcl15161yij" &&
			 arg2!="cqmc1l161l61p" && 
			 arg2!="cqmcm11j651gf" &&
             arg2!="cqmc16d1f6hf1" &&
			 arg2!="cqmc1bsd1ge1e" */ ) 
		{
			send_user(me,"%c%s",';',"Bạn đã nhập sai Code CQMC.");
			write_user(me, ECHO"Bạn đã nhập sai Code CQMC.");
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
		/*case "cqmc1564wq6f4": 
		case "cqmc4f6wq4f6f":  
		case "cqmcgd65446ge":  
		case "cqmc54fqw46qw": 
		case "cqmc4qw46fwq4":  
		case "cqmc48wqr41bz": 
		case "cqmc489e49eq2": 
		case "cqmc456s4fqw8":
		case "cqmc1asf4a612": 
		case "cqmc456q4wfqw": 
		case "cqmc1sdb54d6e": 
		case "cqmc4sd6f46eh": 
		case "cqmc4sd3e1rew": 
		case "cqmc1asf1aq6w": 
		case "cqmcs1a561fav": 
		case "cqmc16w1r6wqf": 
		case "cqmcas461g6aw":
		case "cqmc1as6f4sa6":
		case "cqmciopgsdi12":
		case "cqmcuy1l566t1":
		case "cqmcl15161yij":
		case "cqmc1l161l61p": 
		case "cqmcm11j651gf":
		case "cqmc16d1f6hf1":
		case "cqmc1bsd1ge1e": */
	
		if (exist >= 1) {
			send_user(me,"%c%s",';',"Code CQMC này đã có người sử dụng và đã hết hiệu lực.");
			write_user(me, ECHO"Code CQMC này đã có người sử dụng và đã hết hiệu lực.");
			return 1;
		}
		if ( me->get_fam_name()=="" )
		{	
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhận phần thưởng từ Code CQMC !");
			return 1;
		}
		if ( me->get_save("cqmc")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code CQMC rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code CQMC rồi.");
			return 1;
			}
			
		 me->set_save("cqmc",1);
		// Gửi phần thưởng
		    me->add_save("yuanbao",2000);
			me->add_cash(1000000);
		  
		
		ghi_file("giftcode.txt",sprintf("%s Expiry\n",arg2));
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code CQMC thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 