
#define CPP_FILE        __DIR__ "76b.cc"
#define HTM_FILE        __DIR__ "76.htm"
#define TEXT_FILE       __DIR__ "76b.txt"
#define LIST_LOG        "list.txt"

// 函数：命令处理
int main( object me, string arg )
{
        string cpp, htm, *line, file, name, unit;
        int id, num, pic1, pic2, level, value, lasting, ap, cp, rate;
        int i, size;

        cpp = read_file( CPP_FILE );
        htm = read_file( HTM_FILE );
        line = explode( read_file( TEXT_FILE ), "\n" );

                        log_file( LIST_LOG, "# 法剑\n\n" );

        size = sizeof(line);
        for( i = 0; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( sscanf( line[i], "%d %d %s %d %d %s %d %d %d %d %d %d%%", 
                        id, num, name, pic1, pic2, unit, level, value, lasting, ap, cp, rate ) )
                {
                        file = sprintf("make/%04d.c", id );
                        rm( LOG_DIR + file );    // 清除旧文件(WINDOWS)

                        lasting = lasting / 100 * 100 + 99;
                        log_file( file, sprintf( cpp, name, pic1, pic2, unit, level, value, lasting, ap, cp, rate, num ) );
                        file = LOG_DIR + file;  file->do_nothing();

                        log_file( LIST_LOG, sprintf( htm, pic2, name, level, "男、女", "无", ap, cp, rate, lasting / 100, lasting / 100, value ) );
                }
        }

        tell_user( me, "请查看 /log/make/ 下的文件。" );

        return 1;       
}
