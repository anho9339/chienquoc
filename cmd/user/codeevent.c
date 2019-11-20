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
			send_user(me,"%c%s",';',sprintf("Cấp bậc %d không thể nhập Code Event.",me->get_level()));
			write_user(me, sprintf(ECHO"Cấp bậc %d không thể nhập Code Event.",me->get_level()));
			return 1;
		}
		if ( me->get_fam_name() == "" )
		{
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhập Code Event.");
			write_user(me, ECHO"Vô Môn Phái không thể nhập Code Event.");
			return 1;
		}
		if ( me->get_save("tqe")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Event rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Event rồi.");
			return 1;
			}
			// 50 code
		if( sscanf(arg, "+ %s", arg2 ) != 1 ) return 1;
		if ( arg2!="sp1cs6a1cs65" && // Done
			 arg2!="spn15fg1nt4r" && // Done
			 arg2!="spr41v1d2f1v" && // Done
			 arg2!="spv1d51vds6e" && // Done
			 arg2!="spv1d54d6sv1" && // Done
			 arg2!="sp8e9w1vv1dv" && // Done
			 arg2!="sp1cd5c1c6cx" && // Done
			 arg2!="sp4vd41vcvwe" && // Done
			 arg2!="sp489ewg1ght" && // Done
			 arg2!="sp489gfng1rg" && // Done
			 arg2!="sptu56n4gfnm" && // Done
			 arg2!="sp4t8h4bg1fn" && // Done
			 arg2!="spe9wg1g3gbf" && // Done
			 arg2!="sp1fd2b1e5gr" && // Done
			 arg2!="spf4ewvs3brd" && // Done
			 arg2!="spv1c231d5bf" && // Done
			 arg2!="sptre981fdb1" && // Done
			 arg2!="spe489b1sdbd" && // Done
			 arg2!="spwq4e89qwf1" && // Done
			 arg2!="spv1cv2ds123" && // Done
			 arg2!="sprewg11bfsf" && // Done
			 arg2!="sp4e8w1dsbdg" && // Done
			 arg2!="spv1c23vds5g" && // Done
			 arg2!="sp4vcd31gefg" && // Done
			 arg2!="spqr89wq4vsf" && // Done
			 arg2!="spvcx1v23sd1" && // Done
			 arg2!="sp7rwq98f1vb" && // Done
			 arg2!="spe89ew4g1bd" && // Done
			 arg2!="spwq4e89wq4f" && // Done
			 arg2!="spe7wt98we1v" && // Done
			 arg2!="spv1c2b1d5gb" && // Done
			 arg2!="spv4d89g4we9" && // Done
			 arg2!="spv1d2b13gre" && // Done
			 arg2!="spvd48ew98gb" && // Done
			 arg2!="sp1bv2c3b65e" && // Done
			 arg2!="sp489ewv1vve" && // Done
			 arg2!="sps1v6sd1bee" && // Done
			 arg2!="spw1q61vvvwq" && // Done
			 arg2!="spb4f49efewf" &&
			 arg2!="sp1bd5s6fees" &&
			 arg2!="spvbds4e984w" &&
			 arg2!="spsv156sd16e" && 
			 arg2!="spv4e8949vee" &&
			 arg2!="sp1vcx23v16s" &&
			 arg2!="spv1df4efewf" &&
			 arg2!="spb1d6456ree" &&
			 arg2!="spsv1549ewwq" &&
			 arg2!="sp1bdv61b6fl" &&
			 arg2!="sp1bd5f465fe" &&
			 arg2!="spv1sd56e4g9"  ) 
		{
			send_user(me,"%c%s",';',"Bạn đã nhập sai Code Event.");
			write_user(me, ECHO"Bạn đã nhập sai Code Event.");
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
		case "sp1cs6a1cs65":
		case "spn15fg1nt4r":
		case "spr41v1d2f1v":
		case "spv1d51vds6e":
		case "spv1d54d6sv1":
		case "sp8e9w1vv1dv": 
		case "sp1cd5c1c6cx":
		case "sp4vd41vcvwe":
		case "sp489ewg1ght":
		case "sp489gfng1rg":
		case "sptu56n4gfnm":
		case "sp4t8h4bg1fn": 
		case "spe9wg1g3gbf":
		case "sp1fd2b1e5gr":
		case "spf4ewvs3brd":
		case "spv1c231d5bf":
		case "sptre981fdb1":
		case "spe489b1sdbd": 
		case "spwq4e89qwf1":
		case "spv1cv2ds123":
		case "sprewg11bfsf":
		case "sp4e8w1dsbdg":
		case "spv1c23vds5g":
		case "sp4vcd31gefg":
		case "spqr89wq4vsf": 
		case "spvcx1v23sd1": 
		case "sp7rwq98f1vb": 
		case "spe89ew4g1bd":
		case "spwq4e89wq4f": 
		case "spe7wt98we1v":  
		case "spv1c2b1d5gb": 
		case "spv4d89g4we9": 
		case "spv1d2b13gre": 
		case "spvd48ew98gb": 
		case "sp1bv2c3b65e": 
		case "sp489ewv1vve": 
		case "sps1v6sd1bee":
		case "spw1q61vvvwq":
		case "spb4f49efewf":
		case "sp1bd5s6fees":
		case "spvbds4e984w":
		case "spsv156sd16e": 
		case "spv4e8949vee":
		case "sp1vcx23v16s":
		case "spv1df4efewf":
		case "spb1d6456ree":
		case "spsv1549ewwq":
		case "sp1bdv61b6fl":
		case "sp1bd5f465fe":
		case "spv1sd56e4g9":
			 

		if (exist >= 1) {
			send_user(me,"%c%s",';',"Code Event này đã có người sử dụng và đã hết hiệu lực.");
			write_user(me, ECHO"Code Event này đã có người sử dụng và đã hết hiệu lực.");
			return 1;
		}
		if ( me->get_fam_name()=="" )
		{	
			send_user(me,"%c%s",';',"Vô Môn Phái không thể nhận phần thưởng từ Code Event !");
			return 1;
		}
		if ( me->get_save("tqe")> 0 )
			{
			send_user(me,"%c%s",';',"Ngươi đã nhận Code Event rồi.");
			write_user(me, ECHO"Ngươi đã nhận Code Event rồi.");
			return 1;
			}
			
		 me->set_save("tqe",1);
		// Gửi phần thưởng
		  /*  item = new("item/event/tqe");
			p = item->move(me,-1);
			item->add_to_user(p); */
			me->add_cash(200000);
			"sys/sys/test_db"->add_yuanbao(me,2000);
			
		  
		
		ghi_file("giftcode.txt",sprintf("%s Da Het Han\n",arg2));
		send_user(me,"%c%s",';',HIY"Bạn đã nhận phần thưởng từ Code Event thành công !");
			return 1;
		break; 			
	}		
		
	return 1;
} 