
#include <ansi.h>
#include <skill.h>

int * vita_skill = ({ 620, 630, 640, 650, 660, 670, 680, });

void learn_menu( object me, object who );

// 函数:增添对话菜单
void more_look_menu( object me, object who, string text )
{
        string name1, name2, result = "";
        int p, id;

        id = getoid(who);
        name1 = me->get_fam_name();
        name2 = who->get_fam_name();

        if( name1 == "" && name2 != "" )    // !name1 && name2
        {
                result = sprintf( ESC "您能教我什么技能?\nlearn ? %x#\n"
                                  ESC "请您收下我这个弟子吧!\nlearn @.? %x#\n", id, id );
        }
        else if( name1 != "" && name1 == name2 )    // name1 && name1 == name2
        {
                result = sprintf( ESC "脱离师门!\nlearn x.? %x#\n", id );
        }

        if( result == "" )
        {
                send_user( me, "%c%s", ':', text );
                return;
        }

        if( strlen(text) > 10 && text[<6..<1] == "CLOSE\n" )    // 有关闭选择
        {
                if( p = strchr(text, 27, -1) )    // ESC
                        send_user( me, "%c%s", ':', sprintf( "%s%s%s", text[0..p-1], result, text[p..<1] ) );
                else    send_user( me, "%c%s", ':', text + result );
        }
        else    send_user( me, "%c%s", ':', sprintf( "%s%s%s", text, result, ESC "离开.\nCLOSE\n" ) );
}

// 函数:命令处理
int main( object me, string arg )
{
	object who, fileobj;
        mapping skls;
	string *name, file, result, arg2;
        int total, skill, level, gold, pot, maxlevel, number, contrib;
        int i, size, flag, type, degree, select;

        if( gone_time( me->get_time("learn") ) < 1 )    // 时间限制
        {
                me->set_time( "learn", time() );
                return 1;
        }
        me->set_time( "learn", time() );

        if( !arg ) return 1;                
        if( sscanf(arg, "@.? %s", arg2)==1 ) flag = 2;    // apprentice
        else if( sscanf(arg, "@ %s", arg2)==1 ) flag = 3;
        else if( sscanf(arg, "x.? %s", arg2)==1 ) flag = 4;    // betrayer
        else if( sscanf(arg, "x %s", arg2)==1 ) flag = 5;
        else if( sscanf(arg, "? %s", arg2)==1 ) flag = 1;
        else if( sscanf(arg, "%s %d", arg2, skill) == 2 ) flag = 0;
        else if( sscanf(arg, "%s ! %d %d", arg2, skill, select) == 3 ) flag = 8;
        else if( sscanf(arg, "%s !! %d %d", arg2, skill, select) == 3 ) flag = 9;        
        else if( sscanf(arg, "%s ! %d", arg2, skill) == 2 ) flag = 6;
        else if( sscanf(arg, "%s !! %d", arg2, skill) == 2 ) flag = 7;
        else if( sscanf(arg, "%s %d %d", arg2, skill, pot) == 3 ) flag = 0;        
        else return 1;
        if( !arg2 || !objectp( who = find_char(arg2) ) ) return 1;

        if( !inside_screen_2(me, who) && who->is_org_officer()==0 )
        {
                notify( "Bạn cách %s quá xa rồi.", who->get_name() );
                return 1;
        }

        if( !who->is_master() && !who->is_org_officer() ) return 1;

        me->to_front_eachother(who);
        if( flag == 1 )
        {
                if( !sizeof( skls = who->get_skill_dbase() ) ) return 1;
/*
                result = sprintf( "%s说道:你能从我这里学到\n", who->get_name() );

                name = sort_array( keys(skls), 1 );
                for( i = 0, size = sizeof(name); i < size; i ++ )
                {
                        skill = to_int( name[i] );
                        file = SKILL->get_skill_file(skill);
                        file = load_object(file) ? file->get_name() : "未知技能";
                        result = sprintf( "%s" ESC "%s(%d 级)\nNONE\n", result, file, who->get_skill(skill) );
                }
                result += sprintf( ESC "返回.\nlook %x#\n", getoid(who) );

                send_user( me, "%c%s", ':', result );
*/		learn_menu(me, who);
                return 1;
        }
        else if( flag == 2 )
        {
                // if( me->get_fam_name() || !who->get_fam_name() ) return 1;
                if( me->get_fam_name() != "" || who->get_fam_name() == "" ) return 1;

                if( me->get_level() < 10 )
                {
                        notify( "十级以上才能拜入师门." );
                        return 1;
                }

                send_user( me, "%c%s", ':', sprintf( "您确定要拜%s为师，投入“%s”门下吗?\n" 
                        ESC "是的.\nlearn @ %x#\n"
                        ESC "我再想想……\nCLOSE\n", 
                        who->get_name(), who->get_fam_name(), getoid(who) ) );

                return 1;
        }
        else if( flag == 3 )
        {
                if( me->get_level() < 10 )
                {
                        notify( "十级以上才能拜入师门." );
                        return 1;
                }

                if( me->get_fam_name() == "" && who->get_fam_name() != "" )
                {
                        result = who->get_fam_name();
                        me->set_fam_name(result);
                        me->set_fam_position(1);
                        me->set_fam_title("Đệ Tử");
                        me->set_fam_master( who->get_name() );
                        me->set_fam_time( time() );

                        FAMILY_D->family_channel( result, 0, sprintf( HIY "%s(%d)决定投入“%s”门下.", me->get_name(), me->get_number(), result ) );
                        USER_ENERGY_D->count_max_yuan(me);
                }

                return 1;
        }
        else if( flag == 4 )
        {
                // if( !( result = me->get_fam_name() ) || result != who->get_fam_name() ) return 1;
                if( me->get_fam_name() == "" || me->get_fam_name() != who->get_fam_name() ) return 1;

                send_user( me, "%c%s", ':', sprintf( "脱离“%s”将会失去所有的师门技能，您考虑清楚了吗?\n" 
                        ESC "是的.\nlearn x %x#\n"
                        ESC "我再想想……\nCLOSE\n", 
                        who->get_fam_name(), getoid(who) ) );

                return 1;
        }
        else if( flag == 5 )
        {
                // if( ( result = me->get_fam_name() ) && result == who->get_fam_name() )
                if( me->get_fam_name() != "" && me->get_fam_name() == who->get_fam_name() )
                {
                        FAMILY_D->family_channel( result, 0, sprintf( HIY "%s(%d)决定脱离“%s”门下!!!", me->get_name(), me->get_number(), result ) );

                        me->set_fam_name(0);
                        me->set_fam_position(0);
                        me->set_fam_title(0);
                        me->set_fam_master(0);
                        me->set_fam_time( time() );

                        who->delete_family_skill(me);
                        USER_ENERGY_D->count_max_yuan(me);
                }

                return 1;
        }

        if( who->get_fam_name() != "" && who->get_fam_name() != me->get_fam_name() ) return 1;

        if( ( level = me->get_skill(skill) ) >= who->get_skill(skill) )
        {
                notify( "您没必要向%s学这样技能.", who->get_name() );
                return 1;
        }      
        
/*
        switch( skill )
        {
      case SKILL_0425 : 
      case SKILL_0417 : 
      case SKILL_0408 : case SKILL_0418 : 
      case SKILL_0409 : case SKILL_0429 : 
                        if( me->get_skill(SKILL_0401) < 1 && me->get_skill(SKILL_0411) < 1 && me->get_skill(SKILL_0421) < 1 )
                        {
                                notify( "在学习这样技能之前，您得先学会“道家学说”." );
                                return 1;
                        }
                        break;

      case SKILL_0511 : case SKILL_0521 : 
                        if( me->get_skill(SKILL_0501) < 1 )
                        {
                                notify( "在学习这样技能之前，您得先学会“中医药理”." );
                                return 1;
                        }
                        break;

        }
*/
	if (skill>=610&&skill<=680)
	{
		if (MAIN_D->get_host_type()==6012)
		{
			if (skill!=610)
			{
				notify( "技能尚未开放" );
				return 1;
			}
		}
		size = sizeof(vita_skill);
		total = 1;
		for (i=0;i<size;i++)
		{
			if (me->get_skill(vita_skill[i]))
			{
				if (vita_skill[i]!=skill) total ++;
			}
		}
		if (total>2 && skill!=610)
	        {
	                notify( "一个人只能学习两样特殊生活技能!" );
	                return 1;
	        }
	        level = me->get_level();
	        if (level<10) maxlevel = 0;
	        else
	        if (level<25) maxlevel = 39;
	        else
	        if (level<35) maxlevel = 69;
	        else
	        if (level<60) maxlevel = 99;
	        else maxlevel = 200;
	        if (me->get_skill(skill)>=maxlevel)
	        {
	                notify( "你的等级不足于学习这样技能" );
	                return 1;
	        }	 
/*	        
	        type = me->get_save_2("vita.type");    
	        if (skill==640 && me->get_skill(skill)>=39&&(type==0||type>3))       	        		
	        {       	        	        	
	        	if (select==0)
	        	{
	        		result ="现在你需要选择发展的系别:\n"
	        			ESC"帽子\nlearn "+arg+" 20\n"
	        			ESC"衣服\nlearn "+arg+" 10\n"
	        			ESC"鞋子\nlearn "+arg+" 30\n";
		        	send_user(me, "%c%s", ':', result);	        	
		        	return 1;	        			
	        	}		
	        	else
	        	{
	        		if (select>3)
	        		{
	        			if (flag==6||flag==8)
	        				arg = sprintf("%s ! %d", arg2, skill);
	        			else
	        				arg = sprintf("%s !! %d", arg2, skill);
	        			switch(select)
	        			{
	        			case 20:
	        				result = "你选择的是帽子的系别.帽子系别是专门做帽子系列的裁缝制品，当你选择了这个系别后，你就不能再转衣服或者鞋子的系别，以后很多裁缝的配方都是只有特定系别的专属配方，所以现在请你选择好你的系别.\n"ESC"确定\nlearn "+arg+" 2\n"ESC"返回\nCLOSE\n";
	        				break;
	        			case 10:
	        				result = "你选择的是衣服的系别.衣服系别是专门做衣服系列的裁缝制品，当你选择了这个系别后，你就不能再转帽子或者鞋子的系别，以后很多裁缝的配方都是只有特定系别的专属配方，所以现在请你选择好你的系别.\n"ESC"确定\nlearn "+arg+" 1\n"ESC"返回\nCLOSE\n";
	        				break;
	        			case 30:
	        				result = "你选择的是鞋子的系别.鞋子系别是专门做鞋子系列的裁缝制品，当你选择了这个系别后，你就不能再转衣服或者帽子的系别，以后很多裁缝的配方都是只有特定系别的专属配方，所以现在请你选择好你的系别.\n"ESC"确定\nlearn "+arg+" 3\n"ESC"返回\nCLOSE\n";
	        				break;
	        			default:
	        				return 1;
	        				break;
	        			}
	        			me->set_save_2("vita.type", select);
			        	send_user(me, "%c%s", ':', result);
			        	return 1;	        			
	        		} 
	        		else
	        		{
	        			if (select>0&&select<=3)
	        				me->set_save_2("vita.type", select);
	        		}
	        	}	        	

		}
*/	
	}
	else
        if( level >= me->get_level()+10 )    // 限制:等级、最高
        {
                notify( "Cấp bậc không đủ !" );
                return 1;
        }
//        pot = range_value( pot, 1, USER_SKILL_D->get_upgrade_potential(me, skill) );
	level = me->get_skill(skill);
	degree = USER_SKILL_D->get_upgrade_degree(level);
	fileobj = load_object(SKILL->get_skill_file(skill));
	if (!fileobj) return 1;	
	if (flag==0)
	{
		result = sprintf("%s:\n    请选择提升%s的方式:\n", who->get_name(), fileobj->get_name());
		if (fileobj->is_vita_skill())
			pot = degree / 5 + 1;
		else
			pot = USER_SKILL_D->get_upgrade_potential(me, skill);
		gold = pot * 25 / 2; 
		if (level+1<50) gold = gold * (level+1) / 50;
		result += sprintf(ESC"花费%d潜能，%d金钱\nlearn %s ! %d\n", pot, gold, who->get_char_id(), skill );
		pot = (level*level*level*level/15+100*(level+1))/5;
		result += sprintf(ESC"花费%d经验，%d金钱\nlearn %s !! %d\n", pot, gold, who->get_char_id(), skill );
		result += ESC "离开.\nCLOSE\n";
		send_user( me, "%c%s", ':', result );	
		return 1;
	}
	if (fileobj->is_vita_skill())
		pot = degree / 5 + 1;	
	else
		pot = USER_SKILL_D->get_upgrade_potential(me, skill);
	gold = pot * 25 / 2;     // 1 潜能 == 5 熟练 == 20 金  (武教头加倍)
	if (level+1<50) gold = gold * (level+1) / 50;

	if (fileobj->is_enhance_skill() )
		gold = 10000+(level+1)*(level+1)*200;

	if (flag==6)
	{
		if ( fileobj->is_enhance_skill() )
		{
			notify( "%s只能用经验来学习.", fileobj->get_name() );
			return 1;
		}
		
	        if( me->get_potential() < pot ) 
	        {
	                notify( "您的潜能不够%d.", pot );
	                return 1;
	        }
	}
	else
	{

		if ( fileobj->is_enhance_skill() )
		{
			if (!me->get_save("kjh_enhance_sk") )
			{
				notify( "你现在还不能学习强化技能.", pot );
				return;
			}
		 	pot = 20000+(level+1)*(level+1)*800;
		}
		else
		pot = (level*level*level*level/15+100*(level+1))/5;
		
	        if( me->get_upgrade_exp() < pot ) 
	        {
	                notify( "您的经验不够%d.", pot );
	                return 1;
	        }
	}
        if( me->get_cash() < gold && me->get_cash() + me->get_savings() < gold )    // 现金＋存款
        {
                notify( "您的金钱不够." );
                return 1;
        }
        if (who->is_org_officer())
        {
        	if (me->get_org_name()!=who->get_org_name()) return 1;
        	if (me->get_org_position()==0) return 1;
        	number = me->get_number();
        	contrib = 10*((me->get_skill(skill)+1)/10+1);
        	if (skill>=610&&skill<=670)
        	{
        		if (me->get_skill(skill)<39) contrib = 10;
        		else contrib = 10*((me->get_skill(skill)-39)/10+1);
        	}
        	if (who->get_member_contribute(number)<contrib)
        	{
        		notify( sprintf("您的帮派贡献不足%d.", contrib) );
        		return 1;
        	}
        	who->set_member_contribute(number, who->get_member_contribute(number)-contrib);
        }
        if (flag==6) me->add_potential( -pot );
        else me->add_exp( -pot);
        if( me->get_cash() >= gold ) 
        {
                me->add_cash2( -gold );  me->add_gold_log("learn", gold);    // 现金＋存款
        }
        else 
        { 
                me->add_savings( -gold + me->get_cash() );  me->set_cash(0); 
                me->add_gold_log("learn", gold);
        }
        result = sprintf("学习 %s,%d,%s,%s @%s 金 0 %d 0 %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), who->get_name(), gold, get_z(me), get_x(me), get_y(me) );
	"/sys/user/cmd"->log_item(result);
        "/sys/sys/count"->add_use("learn", gold);
        degree = me->get_skill_degree(skill);
       	me->improve_skill( skill, pot * 5 );
       	// 保留熟练度
       	if (degree==0) degree = 1;
        if (fileobj->is_vita_skill() ) me->set_skill_degree(skill, degree);
        // learn_menu(me, who);

        return 1;
}

// 函数:学习选择菜单
void learn_menu( object me, object who )
{
        mapping skls;
        string *name, file;
        object skillobj;
        int skill, i, size;

        if( !who->is_master() ) return;

        // if( ( result = who->get_fam_name() ) && result != me->get_fam_name() )
        if( who->get_fam_name() != "" && who->get_fam_name() != me->get_fam_name() )
        {
                if( me->get_fam_name() == "" )    // !me->get_fam_name()
                {
                        more_look_menu( me, who, who->get_name() + ":\n你找我有什么事情吗?\n" );
                }
                return;
        }

        if( !sizeof( skls = who->get_skill_dbase() ) ) return;
	if (who->get_fam_name()!="") "/quest/help"->send_help_tips(me, 27);
        send_user( me, "%c%w%d%w%w", 0x73, 0, getoid(who), 1, who->is_basic_master()==1 ? 40 : 20 );    // 武教头加倍

        name = sort_array( keys(skls), 1 );
        for( i = 0, size = sizeof(name); i < size; i ++ )
        {
                skill = to_int( name[i] );
                file = SKILL->get_skill_file(skill);
                skillobj = load_object(file);
                file = skillobj ? file->get_name() : "未知技能";
                //强化技能判断
                if (skillobj->is_enhance_skill() && !me->get_save("kjh_enhance_sk") )	continue;
                send_user( me, "%c%w%w%w%s", 0x73, skill, me->get_skill(skill), who->get_skill(skill), file );
                if (skillobj) skillobj->can_perform(me);
        }
}
