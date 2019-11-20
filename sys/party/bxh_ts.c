#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>
#include <public.h>
#include <action.h>

inherit DBASE_F;
inherit SAVE_F;

void update_thongbao(object player);
void update_bxh_cap(object player);
void bxh_cap(object player,object npc);
void SAVE_BINARY() { }
string get_save_file()	{ return "data/bangxephangtrungsinh"SAVE_EXTENSION;}

void bxh_cap(object player,object npc)
{
	int index,pos,name_size,id;  
       	string tmp="",cmd="",playername,playerphai,playerid,result,blank="";
       	blank = repeat_string(" ",12); 
	restore();
	for(index = 1; index<=10;index++)
	{
		id = get_save_2(sprintf("luu.%d",index));
		if(!id)
		{
			tmp = sprintf(" ""%2d: Chưa cập nhật...",index);
			tmp+="\n";
		}
		else
		{
			playername = get_save_2(sprintf("nguoichoi.%d.ten",id));			
			playerphai = get_save_2(sprintf("nguoichoi.%d.phai",id));			
			playerid = get_save_2(sprintf("nguoichoi.%d.id",id));			
			name_size = strlen(playername);
			if(name_size<=12)
			{
				playername+= repeat_string(" ",12-name_size);
			}
			switch(index)
			{
			case 1:
				tmp = sprintf(" ""R""%2d: %12s (ID: %d) %4s Trùng Sinh: %d"NOR,1,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));					
				break;
			case 2:
				tmp = sprintf(" ""M""%2d: %12s (ID: %d) %4s Trùng Sinh: %d"NOR,2,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));					
				break;
			case 3:
				tmp = sprintf(" ""B""%2d: %12s (ID: %d) %4s Trùng Sinh: %d"NOR,3,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));			
				break;
			case 4:
				tmp = sprintf(" ""%2d: %12s (ID: %d) %4s Trùng Sinh: %d",4,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));	//+BLK+BLK		
				break;		
			case 5:
				tmp = sprintf(" ""%2d: %12s (ID: %d) %4s Trùng Sinh: %d",5,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));	//+BLK+BLK
				break;	
			case 6:
				tmp = sprintf(" ""%2d: %12s (ID: %d) %4s Trùng Sinh: %d",6,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));	//+BLK+BLK
				break;	
			case 7:
				tmp = sprintf(" ""%2d: %12s (ID: %d) %4s Trùng Sinh: %d",7,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));	//+BLK+BLK
				break;
			case 8:
				tmp = sprintf(" ""%2d: %12s (ID: %d) %4s Trùng Sinh: %d",8,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));	//+BLK+BLK
				break;	
			case 9:
				tmp = sprintf(" ""%2d: %12s (ID: %d) %4s Trùng Sinh: %d",9,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));	//+BLK+BLK
				break;	
			case 10:
				tmp = sprintf(" ""%2d: %12s (ID: %d) %4s Trùng Sinh: %d",10,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.ts",id)));	//+BLK+BLK
				break;	
			}	
			tmp+="\n";
		}
		cmd+=tmp;
		
	}
		result=sprintf(sprintf("Danh sách top 10 Trùng Sinh : \n")+cmd);
		result+=sprintf(ESC "Xác nhận\nCLOSE\n");
		result+=sprintf(ESC "Rời khỏi\nCLOSE\n");
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),result);
}
void update_thongbao(object player)
{
	int pos;
	player = this_player();
	restore();
	pos = get_save_2(sprintf("nguoichoi.%d.hang",player->get_number()));
	if ( pos == 1 )
	{
	CHAT_D->sys_channel(0,sprintf(HIR "Võ Lâm Minh Chủ "HIY "%s "NOR "đã đăng nhập!",player->get_name()));
	}
}
void update_bxh_cap(object player)
{
	int size,index,pos,oldid,id1,amount,i,phai;
	int id = player->get_number();
	string name = player->get_name();
	amount = player->get_save("trungsinh");
//	phai = player->get_fam_name()=="" ? "Vô Môn Phái" : player->get_fam_name();
	if(get_save_2(sprintf("nguoichoi.%d",id)))
	{
		if(get_save_2(sprintf("nguoichoi.%d.ten",id))== name)
		{
			set_save_2(sprintf("nguoichoi.%d.ts",id),amount);
			set_save_2(sprintf("nguoichoi.%d.id",id),id);
			pos = get_save_2(sprintf("nguoichoi.%d.hang",id));
		}
	}
	else if((size = get_save_2(sprintf("luu.soluong"))) < 10)
	{
			pos = size+1;
			set_save_2("luu.soluong",pos);
			set_save_2(sprintf("luu.%d",pos),id);
			set_save_2(sprintf("nguoichoi.%d.ten",id),name);
			set_save_2(sprintf("nguoichoi.%d.hang",id),pos);
			set_save_2(sprintf("nguoichoi.%d.ts",id),amount);
			set_save_2(sprintf("nguoichoi.%d.id",id),id);
	}
	else 
	{
		oldid = get_save_2(sprintf("luu.%d",size));
		if(get_save_2(sprintf("nguoichoi.%d.ts",oldid))< amount)
		{
			pos = size;
			delete_save_2(sprintf("nguoichoi.%d",oldid));
			set_save_2(sprintf("luu.%d",pos),id);
			set_save_2(sprintf("nguoichoi.%d.ten",id),name);
			set_save_2(sprintf("nguoichoi.%d.hang",id),pos);
			set_save_2(sprintf("nguoichoi.%d.ts",id),amount);
			set_save_2(sprintf("nguoichoi.%d.id",id),id);
			set_save_2("luu.soluong",pos);		
		}
	}
	if(pos)
	{
		for(index = pos; index > 1; index--)
		{
			id = get_save_2(sprintf("luu.%d",index));
			id1 = get_save_2(sprintf("luu.%d",index-1));
			if(get_save_2(sprintf("nguoichoi.%d.ts",id1))>= get_save_2(sprintf("nguoichoi.%d.ts",id)))
			{
				break;
			}
			set_save_2(sprintf("luu.%d",index),id1);			
			set_save_2(sprintf("nguoichoi.%d.hang",id1),index);
			set_save_2(sprintf("luu.%d",index-1),id);
			set_save_2(sprintf("nguoichoi.%d.hang",id),index-1);	
		}
		save();
	}
	//save();
}