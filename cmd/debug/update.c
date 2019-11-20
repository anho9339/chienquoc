void update_dir(object me,string arg);

// 函数：命令处理
int main( object me, string arg )
{
        object obj;
        string file, err;

        if( is_player(me) ) 
        {
                notify( "您没有足够的权限。" );
		return 1;
        }

        if( !arg )
        {
                notify( "您想更新什么东西？" );
		return 1;
        }
	if ( file_size(arg) == -2 )
	{
		log_file("updatefile.txt",short_time()+" 编译目录："+arg+"\n");
		update_dir(me,arg);
		tell_user(me,"编译ok");
		return 1;
	}
        if( obj = find_any_object(arg) ) file = get_file_name(obj) + ".c";
        else if( file_exist( file = absolute_path(me, arg) ) ) ;
        else if( file_exist( file = absolute_path(me, arg + ".c") ) ) ;
        else if( file_exist( absolute_path(me, arg + ".cpp") ) ) file = absolute_path(me, arg + ".c");
        else if( arg == "cwf" ) file = me->get_cwf();
        else
        {
                notify( "您找不到这个物体。" );
		return 1;
        }

        me->set_cwf(file);    // 设置工作文件名
        tell_user( me, "重新编译: " + file );

        if( obj = find_object(file) ) 
        {
                obj->before_destruct();
                destruct(obj);
        }

        if( obj ) 
        {
                tell_user( me, "无法清除旧的程序。" );
		return 1;
        }

        if( err = catch( call_other( file, "???" ) ) ) 
                tell_user( me, "发生错误！\n%s", err );
        else    tell_user( me, "更新成功！" );
                
        return 1;
}
int update_file(object me,string arg)
{
        object obj;
        string file, err;

        if( obj = find_any_object(arg) ) file = get_file_name(obj) + ".c";
        else if( file_exist( file = absolute_path(me, arg) ) ) ;
        else if( file_exist( file = absolute_path(me, arg + ".c") ) ) ;
        else if( file_exist( absolute_path(me, arg + ".cpp") ) ) file = absolute_path(me, arg + ".c");
        else if( arg == "cwf" ) file = me->get_cwf();
        else
        {
                log_file("updatefile.txt",sprintf("%s %s can't find obj\n",short_time(),arg));
		return 1;
        }

	log_file("updatefile.txt","重新编译"+file+"\n");
        if( obj = find_object(file) ) 
        {
                obj->before_destruct();
                destruct(obj);
        }

        if( obj ) 
        {
                tell_user( me, "无法清除旧的程序。" );
		return 1;
        }

        if( err = catch( call_other( file, "???" ) ) ) 	
        	log_file("updatefile.txt",err+"\n");
        return 1;
}
void update_dir(object me,string arg)
{
	int i,size;
	mixed *mxTmp;	
	
	mxTmp = get_dir(arg);
	for(i=0,size=sizeof(mxTmp);i<size;i++)
	{
		if ( mxTmp[i] == ".svn" )
			continue;
		if ( file_size(arg+mxTmp[i]) == -2 )
			update_dir(me,arg+mxTmp[i]+"/");
		if ( strstr(mxTmp[i],".c") == -1 )
			continue;
//		tell_user(me,"%s %s",arg,mxTmp[i]);
		update_file(me,arg+mxTmp[i]);
	}
}