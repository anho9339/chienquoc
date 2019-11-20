#include <npc.h>
#include <ansi.h>
#include <city.h>
#include <effect.h>
#include <public.h>
#include <action.h>

inherit DBASE_F;
inherit SAVE_F;

void update_setpass(object player, string arg);
void checkpass(object player, string arg);
void SAVE_BINARY() { }
string get_save_file()	{ return "data/baomatquankho"SAVE_EXTENSION;}

void checkpass(object player, string arg)
{
	int index,pos,size,id,i;  
	object *objs, target;
       	string tmp="",cmd="",playerid,playername,playerpass,result,blank="";
       	blank = repeat_string(" ",12); 
	restore();
	for(index = 1; index<=10000;index++)
	{	
		id = get_save_2(sprintf("luu.%d",index));	
		if(id)
		{
				playername = get_save_2(sprintf("nc.%d.t",id));									
				playerpass = get_save_2(sprintf("nc.%d.pass",id));
			//	arg = player->get_save("passquankho");	
			if ( playername==player->get_name() )
			{
		if ( arg == player->get_save("passquankho")	)
		{
				if ( playerpass==arg )
				{
				player->set_save("ndmkk",1);
				send_user( player, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn đã nhập đúng Mật khẩu bảo vệ Kho, bây giờ bạn có thể sử dụng Kho mà không cần phải nhập lại Mật khẩu cho đến khi bạn thoát khỏi trò chơi." );
				if (get_z(player)==001)
				objs = children("/npc/base/0001");
				else if (get_z(player)==010)
				objs = children("/npc/base/1001");
				else if (get_z(player)==020)
				objs = children("/npc/base/2001");
				else if (get_z(player)==030)
				objs = children("/npc/base/3001");
				else if (get_z(player)==040)
				objs = children("/npc/base/4001");
				else if (get_z(player)==050)
				objs = children("/npc/base/5001");
				else if (get_z(player)==060)
				objs = children("/npc/base/6001");
				else if (get_z(player)==070)
				objs = children("/npc/base/7001");
				else if (get_z(player)==080)
				objs = children("/npc/base/8001");
				else if (get_z(player)==549)
				objs = children("/npc/base/0911");
				else
				objs = children("/npc/base/1001");
				size = sizeof(objs);
				if (size==0) return 0;
				for (i=0;i<size;i++)
				{
				if (objectp(objs[i]) )
				{
				target = objs[i];
				break;
				}
				}
				if (!target) return 0;	
				player->set("pawn_time", time());
				"/cmd/std/pawn"->do_list(player, sprintf("%x#", getoid(target)), 1);
				return 0;
				}
				else
				{
				send_user( player, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn đã nhập sai Mật khẩu bảo vệ Kho." );
				return 0;
				}
		}
		else
		{
		send_user( player, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn đã nhập sai Mật khẩu bảo vệ Kho." );
		return 0;
		}	
			}
		}
		else
		{	
				
		if ( player->get_save("passquankho") )
			{
			update_setpass(player, player->get_save("passquankho"));
			send_user( player, "%c%c%d%s", 0x43, 10, 0, HIR "Đã xảy ra sự cố ngoài ý muốn, bạn vui lòng nhập Mật khẩu bảo vệ Kho lần nữa." );
			return 0;
			}	
		}
	}	
}
void update_setpass(object player, string arg)
{
	int size,index,pos,oldid,id1,amount,i,phai;
	int id = player->get_number();
	string name = player->get_name();

	if(get_save_2(sprintf("nc.%d",id)))
	{
		if(get_save_2(sprintf("nc.%d.t",id))== name)
		{
			set_save_2(sprintf("nc.%d.pass",id),arg);
			
			set_save_2(sprintf("nc.%d.id",id),id);
			pos = get_save_2(sprintf("nc.%d.h",id));
		}
	}
	else if((size = get_save_2(sprintf("luu.sl"))) <= 10000)
	{
			pos = size+1;
			set_save_2("luu.sl",pos);
			set_save_2(sprintf("luu.%d",pos),id);
			set_save_2(sprintf("nc.%d.t",id),name);
			set_save_2(sprintf("nc.%d.h",id),pos);
			set_save_2(sprintf("nc.%d.pass",id),arg);
			
			set_save_2(sprintf("nc.%d.id",id),id);
	}
	else 
	{
		oldid = get_save_2(sprintf("luu.%d",size));
		if(get_save_2(sprintf("nc.%d.pass",oldid))< arg)
		{
			pos = size;
			delete_save_2(sprintf("nc.%d",oldid));
			set_save_2(sprintf("luu.%d",pos),id);
			set_save_2(sprintf("nc.%d.t",id),name);
			set_save_2(sprintf("nc.%d.h",id),pos);
			set_save_2(sprintf("nc.%d.pass",id),arg);
			
			set_save_2(sprintf("nc.%d.id",id),id);
			set_save_2("luu.sl",pos);		
		}
	}
	if(pos)
	{
		for(index = pos; index > 1; index--)
		{
			id = get_save_2(sprintf("luu.%d",index));
			id1 = get_save_2(sprintf("luu.%d",index-1));
			if(get_save_2(sprintf("nc.%d.id",id1))>= get_save_2(sprintf("nc.%d.id",id)))
			{
				break;
			}
			set_save_2(sprintf("luu.%d",index),id1);			
			set_save_2(sprintf("nc.%d.h",id1),index);
			set_save_2(sprintf("luu.%d",index-1),id);
			set_save_2(sprintf("nc.%d.h",id),index-1);	
		}
		save();
	}
	//save();
}