
#define CPP_FILE        __DIR__ "vita.cc"
#define TEXT_FILE       __DIR__ "650.txt"
#define LIST_LOG        "list.txt"

// 函数：命令处理
int main( object me, string arg )
{
        string cpp, *line, file, name, desc, color, type, temp, vita, final, tool, buff, fam;
        int id, pic1, pic2, value, iColor, level, tili, counts, dir;
        int i, j, size, rate;
        string * stuff = ({ "", "", "", "", "", "", "//", "//", "//", "//", "//", "//", });
        int * count = ({ 0, 0, 0, 0, 0, 0});
        object obj;

        cpp = read_file( CPP_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

        size = sizeof(line);
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%s %d %s %s %s %d %s %d %d %d %s %s %d %s %d %s %d %s %d %s %d %s %d", 
                        name, id, color, temp, fam, level, final, counts, rate, tili, tool, stuff[0], count[0], stuff[1], count[1], stuff[2], count[2], stuff[3], count[3], stuff[4], count[4], stuff[5], count[5] ) )
                {
                	
			switch(color)
			{
			case "白色":
				iColor = 0;
				break;
			case "蓝色":
				iColor = 1;
				break;
			case "金色":
				iColor = 2;				
				break;				
				
			}      
/*			
			switch(type)
			{
			case "衣服":
				type = "1";
				break;
			case "帽子":
				type = "2";
				break;
			case "鞋":
				type = "3";
				break;
			case "项链":
				type = "4";
				break;
			case "腰带":
				type = "5";
				break;																							
			}
*/			
			if (fam=="无") 
			{
				fam = "";
				type = "1";
			}
			else type = "2";
			buff = "/make/vita/vitalist"->get_item_file(tool);
			if (buff!="") sscanf(buff, "\"%s\"", tool);
			buff = "/make/vita/vitalist"->get_item_file(final+fam);
			if (buff=="") 
			{
				tell_user(me, sprintf("找不到%s", final+fam));
				return 1;
			}
			if (strlen(buff)<10)
			{
				sscanf(buff, "\"%d\"", j);				
				final = sprintf("\"/item/stuff/%04d\"", j);
			}
			else final = buff;
			id = 65000 + id;        	
                        file = sprintf("make/%04d.c", id );
                        rm( LOG_DIR + file );    // 清除旧文件(WINDOWS)
                        tell_user(me, sprintf("%s %s %s %s %s %s", stuff[0], stuff[1], stuff[2], stuff[3], stuff[4], stuff[5] ));
                        for (j=0;j<6;j++)
                        {
                        	if (stuff[j]!="无")
                        	{
                        		buff = "/make/vita/vitalist"->get_item_file(stuff[j]);
                        		if (buff=="") 
                        		{
                        			tell_user(me, sprintf("找不到%s", stuff[j]));
                        			return 1;
                        		}
                        		if (strlen(buff)>10)
                        		{
		                        	buff = buff[1..<2];     
						obj = load_object(buff);     
						if (obj)
						{
							if (obj->get_fin_type())          			
		                        			stuff[j] = sprintf("\"%d\"", obj->get_fin_type());                        			
		                        		else
		                        		if (obj->get_stuff_type())
		                        			stuff[j] = sprintf("\"%d\"", obj->get_stuff_type());
		                        		else
		                        		{
		                        			tell_user(me, sprintf("找不到材料%s", stuff[j]));
		                        			return 1;
		                        		}
		                        	}
                        		}
                        		else
                        			stuff[j] = buff;
                        		stuff[j+6] = "";
                        	}
                        	else 
                        		stuff[j+6] = "//";
                        }
			if (temp=="是") temp = "0";
			else temp = "1";
			name += "制作";
			
                        log_file( file, sprintf( cpp, 650, to_int(type), id%1000, name, level, tool, tili, final, to_int(temp), "0", iColor, rate, stuff[6], stuff[0], count[0], stuff[7], stuff[1], count[1], stuff[8], stuff[2], count[2], stuff[9], stuff[3], count[3], stuff[10], stuff[4], count[4], stuff[11], stuff[5], count[5], counts  ) );
                        file = LOG_DIR + file;  file->do_nothing();
                }
        }

        tell_user( me, "请查看 /log/make/ 下的文件。" );

        return 1;       
}
