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
		if ( me->get_level() < 20 )
		{
			send_user(me,"%c%s",';',sprintf("Cấp bậc %d không thể nhập Code Pret.",me->get_level()));
			write_user(me, sprintf(ECHO"Cấp bậc %d không thể nhập Code Pret.",me->get_level()));
			return 1;
		}
		if ( me->get_fam_name() == "" )
		{
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhập Code Pret.");
			write_user(me, ECHO"Vô Môn Phái không thể nhập Code Pret.");
			return 1;
		}
		if ( me->get_save("tqp")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Pret rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Pret rồi.");
			return 1;
			}
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		// 30 code
		if ( arg2!="sp2v15as1v6av" &&
			 arg2!="sp25v64w4eb1b" &&
			 arg2!="sp2f4b6df1bfe" &&
			 arg2!="sp2231b51r6gb" &&
			 arg2!="sp2v64fb56e46" &&
			 arg2!="sp2n3db156f46" && 
			 arg2!="sp2e89sd789br" &&
			 arg2!="sp2v231df3b13" &&
			 arg2!="sp2f64h65eg4h" &&
			 arg2!="sp2r987r9kb4f" &&
			 arg2!="sp2e4bf1bf211" &&
			 arg2!="sp21fd6bf4b1n" && 
			 arg2!="sp26f4ngf1n3g" &&
			 arg2!="sp21v3c1b32v1" &&
			 arg2!="sp2989t7n4ntn" &&
			 arg2!="sp2b23f1nig1n" &&
			 arg2!="sp2rt79r4yntn" &&
			 arg2!="sp2fg1ngo1nnr" && 
			 arg2!="sp2v2n31glf31" &&
			 arg2!="sp2r79sd4pbbf" &&
			 arg2!="sp232b1ft354b" &&
			 arg2!="sp2s9798w79f4" &&
			 arg2!="sp2cx13v1ds35" &&
			 arg2!="sp213d13b1d1v" &&
			 arg2!="sp29r79sd4bbf" &&
			 arg2!="sp2ewve841erg" &&
			 arg2!="sp2s9798w79f4" &&
			 arg2!="sp2cx13v1ds35" &&
			 arg2!="sp213d13b1d1v" &&
			 arg2!="sp2ew4gr48u4u"  ) 
		{
			send_user(me,"%c%s",';',"Bạn đã nhập sai Code Pret.");
			write_user(me, ECHO"Bạn đã nhập sai Code Pret.");
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
			case "sp2v15as1v6av":
			case "sp25v64w4eb1b":
			case "sp2f4b6df1bfe":
			case "sp2231b51r6gb":
			case "sp2v64fb56e46":
			case "sp2n3db156f46": 
			case "sp2e89sd789br":
			case "sp2v231df3b13":
			case "sp2f64h65eg4h":
			case "sp2r987r9kb4f":
			case "sp2e4bf1bf211":
			case "sp21fd6bf4b1n": 
			case "sp26f4ngf1n3g":
			case "sp21v3c1b32v1":
			case "sp2989t7n4ntn":
			case "sp2b23f1nig1n":
			case "sp2rt79r4yntn":
			case "sp2fg1ngo1nnr": 
			case "sp2v2n31glf31":
			case "sp2r79sd4pbbf":
			case "sp232b1ft354b":
			case "sp2s9798w79f4":
			case "sp2cx13v1ds35":
			case "sp213d13b1d1v":
			case "sp29r79sd4bbf":
			case "sp2ewve841erg":
			case "sp2s9798w79f4":
			case "sp2cx13v1ds35":
			case "sp213d13b1d1v":
			case "sp2ew4gr48u4u":

		if (exist >= 1) {
			send_user(me,"%c%s",';',"Code Pret này đã có người sử dụng và đã hết hiệu lực.");
			write_user(me, ECHO"Code Pret này đã có người sử dụng và đã hết hiệu lực.");
			return 1;
		}
		if ( me->get_fam_name()=="" )
		{	
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhận phần thưởng từ Code Pret !");
			return 1;
		}
		if ( me->get_save("tqp")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Pret rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Pret rồi.");
			return 1;
			}
			
		 me->set_save("tqp",1);
		// Gửi phần thưởng
		 /*   item = new("item/event/tet/tqp");
			p = item->move(me,-1);
			item->add_to_user(p); */
			me->add_cash(300000);
			"sys/sys/test_db"->add_yuanbao(me,1500);
		  
		
		ghi_file("giftcode.txt",sprintf("%s Het Han\n",arg2));
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code Pret thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 