#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>
#include <public.h>
#include <action.h>

inherit DBASE_F;
inherit SAVE_F;

void update_thongbao(object player);
void update_bxh_trongcay(object player);
void bxh_trongcay(object player,object npc);
void SAVE_BINARY() { }
string get_save_file()	{ return "data/bangxephangtrongcay"SAVE_EXTENSION;}

void bxh_trongcay(object player,object npc)
{
	int index,pos,name_size,id;  
       	string tmp="",cmd="",playername,playerid,result,blank="";
       	blank = repeat_string(" ",12); 
	restore();
	for(index = 1; index<=10;index++)
	{
		id = get_save_2(sprintf("luu.%d",index));
		if(!id)
		{
			tmp = sprintf(" ""%2d: %12s %4s %s",index,blank,"-","0");
			tmp+="\n";
		}
		else
		{
			playername = get_save_2(sprintf("nguoichoi.%d.ten",id));						
			playerid = get_save_2(sprintf("nguoichoi.%d.id",id));			
			name_size = strlen(playername);
			if(name_size<=12)
			{
				playername+= repeat_string(" ",12-name_size);
			}
			switch(index)
			{
			case 1:
				tmp = sprintf(" ""R""%2d: %12s (%d) %4s %d"NOR,1,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));					
				break;
			case 2:
				tmp = sprintf(" ""M""%2d: %12s (%d) %4s %d"NOR,2,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));					
				break;
			case 3:
				tmp = sprintf(" ""B""%2d: %12s (%d) %4s %d"NOR,3,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));			
				break;
			case 4:
				tmp = sprintf(" ""%2d: %12s (%d) %4s %d",4,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));			
				break;		
			case 5:
				tmp = sprintf(" ""%2d: %12s (%d) %4s %d",5,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));	
				break;	
			case 6:
				tmp = sprintf(" ""%2d: %12s (%d) %4s %d",6,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));	
				break;	
			case 7:
				tmp = sprintf(" ""%2d: %12s (%d) %4s %d",7,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));	
				break;
			case 8:
				tmp = sprintf(" ""%2d: %12s (%d) %4s %d",8,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));	
				break;	
			case 9:
				tmp = sprintf(" ""%2d: %12s (%d) %4s %d",9,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));	
				break;	
			case 10:
				tmp = sprintf(" ""%2d: %12s (%d) %4s %d",10,playername,playerid," ",get_save_2(sprintf("nguoichoi.%d.cay",id)));	
				break;	
			}	
			tmp+="\n";
		}
		cmd+=tmp;
		
	}
		result=sprintf(sprintf("%2s %s %12s %4s %s\n","---"," Tên","-ID"," ","-Số cây đã trồng")+cmd);
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
	CHAT_D->sys_channel(0,sprintf(HIR "Đại Sư Trồng Cây "HIY "%s "NOR "đã đăng nhập!",player->get_name()));
	}
}
void update_bxh_trongcay(object player)
{
	int size,index,pos,oldid,id1,amount,i,phai;
	int id = player->get_number();
	string name = player->get_name();
	amount = player->get_save("diemtrongcayabc");
	if(get_save_2(sprintf("nguoichoi.%d",id)))
	{
		if(get_save_2(sprintf("nguoichoi.%d.ten",id))== name)
		{
			set_save_2(sprintf("nguoichoi.%d.cay",id),amount);
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
			set_save_2(sprintf("nguoichoi.%d.cay",id),amount);
			set_save_2(sprintf("nguoichoi.%d.id",id),id);
	}
	else 
	{
		oldid = get_save_2(sprintf("luu.%d",size));
		if(get_save_2(sprintf("nguoichoi.%d.cay",oldid))< amount)
		{
			pos = size;
			delete_save_2(sprintf("nguoichoi.%d",oldid));
			set_save_2(sprintf("luu.%d",pos),id);
			set_save_2(sprintf("nguoichoi.%d.ten",id),name);
			set_save_2(sprintf("nguoichoi.%d.hang",id),pos);
			set_save_2(sprintf("nguoichoi.%d.cay",id),amount);
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
			if(get_save_2(sprintf("nguoichoi.%d.cay",id1))>= get_save_2(sprintf("nguoichoi.%d.cay",id)))
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