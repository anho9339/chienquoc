
#include <ansi.h>

#define CRASH_LOG       "sys/crash.txt"         // 系统当机日志
//#define CRASH_LOG       "crash.txt"         // 系统当机日志

// 函数：生成二进制码
void SAVE_BINARY() { }

int Region, Host, HostType;                               // 游戏服务器分区、标识

// 函数：获取服务器分区
int get_region() { return Region; }

// 函数：设置服务器分区
int set_region( int id ) { return Region = id; }

// 函数：获取服务器标识
int get_host() { return Host; }

// 函数：设置服务器标识
int set_host( int id ) { return Host = id; }

// 函数：获取服务器标识
int get_host_type() { return HostType; }

// 函数：设置服务器标识
int set_host_type( int id ) { return HostType = id; }

// -------------------------------------------------------------

int ValidAbsoluteRandomNumber;

string *InitializationTable = ({
        "广州网游数码科技有限公司  版权所有",    // Windows :)
        "Intel Pentium III i386c0a8164055d6a12a5",    // 192.168.1.100
        "Intel(R) Celeron(R) CPU 2.40GHz i386c0a81650ea693e07d",    // 192.168.1.101
	"Intel(R) Celeron(R) CPU 2.40GHz i386c0a816601731955c9",	// 102
        "Intel(R) Pentium(R) 4 CPU 1.80GHz i386c0a81c8055d87688c", 	// 200
        "Intel(R) Pentium(R) D CPU 3.40GHz i386ca69df5017315237c6", 	// 天下
        "Intel(R) Pentium(R) D CPU 3.40GHz i386ca69df601731523b66",	// 战国
        "Intel(R) Xeon(TM) CPU 2.80GHz i3867d5d356401143e898a4",	// 五羊逐梦
        "Intel(R) Xeon(TM) CPU 2.80GHz i3867d5d356d01143e898a5",	// 新五羊
        "Intel(R) Xeon(TM) CPU 2.80GHz i3867d5d356501143e898f6",	// 广州2
        "Intel(R) Xeon(TM) CPU 2.80GHz i3867d405c180ec4bf0c7",		// 金沙成都
        "Intel(R) Xeon(TM) CPU 2.80GHz i386da3d04e0e081444f58",		// 泰山
        "Intel(R) Xeon(TM) CPU 3.00GHz i386da71d790423b3307c",		// 松花江畔
        "Intel(R) Xeon(TM) CPU 3.00GHz i386c0a80550c09fc66363", 	// 台湾85
        "Intel(R) Xeon(TM) CPU 3.20GHz i386c0a8056015f25224",		// 台湾86
        "Intel(R) Xeon(TM) CPU 3.00GHz i386c0a804b0c09fc6636c",		// 台湾75
        "Intel(R) Xeon(TM) CPU 3.00GHz i386c0a80460c09fc66588", 	// 台湾70
        "Intel(R) Xeon(TM) CPU 3.00GHz i386c0a80620c09fc66362",		// 台湾 98
        "Intel(R) Xeon(TM) CPU 2.80GHz i3867d405c310c09f6d68d5",	//四川
        "Intel(R) Xeon(TM) CPU 2.80GHz i3863dafe29e030485883b",		// 杭州
        "Intel(R) Pentium(R) D CPU 3.40GHz i386d21575910173157a41f",	// 网通测试
//        "Intel(R) Pentium(R) D CPU 3.40GHz i386ca69df50173157a424",	// 新 245
	"Intel(R) Pentium(R) D CPU 2.80GHz i386ca67a06f017314cf5c1",	// 111
        "Intel(R) Xeon(TM) CPU 3.00GHz i3863d87aa370145e7f824c",	// 猫扑 61.135.170.55
        "Intel(R) Xeon(TM) CPU 3.00GHz i3863d87aa380145e7f8176",	// 猫扑 61.135.170.56
        "Intel(R) Xeon(TM) CPU 3.00GHz i3863cd9e44b01635b0de21a1fc14b01635b0de20", 	// 猫扑 60.217.228.75 屈原
        "Intel(R) Xeon(TM) CPU 3.00GHz i3863cd9e44c01635b0ddffa1fc14c01635b0ddfe", 	// 60.217.228.76 商鞅
        "Intel(R) Xeon(TM) CPU 3.00GHz i3863cd9e44d01635b0da51a1fc14d01635b0da50", 	// 60.217.228.77
        "Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb351501422fe713a1bc11501422fe714",	// 猫扑 221.235.53.21 傲视
        "Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb351601422fe75ea1bc11601422fe75f",	// 221.235.53.22 无双
        "Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb351701422fd5e8a1bc11701422fd5e9", 	// 221.235.53.23 郑国渠
        "Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb351801422fe6dda1bc11801422fe6de", 	// 221.235.53.24
        "Intel(R) Xeon(TM) CPU 3.00GHz i3863d87aa3c0145e7f821ca488150145e7f821d",	// 61.135.170.60
        "Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb351901422fec53a1bc11901422fec54",	// 221.235.53.25
        "Intel(R) Pentium(R) D CPU 2.80GHz i386dde78949017a48f161da19c549017a48f161e", 	// 6.2 测试机
	"Intel(R) Xeon(TM) CPU 3.00GHz i386c0a80610c09fc66588",		//台湾黄大仙 210.17.20.97
	"Intel(R) Xeon(TM) CPU 3.00GHz i386c0a806e0c09fc6636c",		//台湾三太子 210.17.20.110
//      "Intel(R) Xeon(TM) CPU 3.00GHz i386c0a80550c09fc66363",    // 203.67.80.85(台湾)

	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde78949017a48f161da19c549017a48f161e", //221.231.137.73
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde7894a017a48fe5c5a19c54a017a48fe5c6", //221.231.137.74
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde7894b017a48fb5e9a19c54b017a48fb5ea", //221.231.137.75
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde7894c017a48fe575a19c54c017a48fe576", //221.231.137.76
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde7894d017a48f267ba19c54d017a48f267c", //221.231.137.77
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde7894e017a48d97f1a19c54e017a48d97f2", //221.231.137.78
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde7894f017a48d779da19c54f017a48d779e", //221.231.137.79
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde78950017a48fa573a19c550017a48fa574", //221.231.137.80
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde78951017a48d8781a19c551017a48d8782", //221.231.137.81
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde78952017a48fa52da19c552017a48fa52e", //221.231.137.82
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde78953017a43ca37ba19c553017a43ca37c", //221.231.137.83
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde789540178534a57a19c5540178534a56", //221.231.137.84
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde7895501635b0da4da19c55501635b0da4c", //221.231.137.85
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde789560137261c5b8a19c5560137261c5b9", //221.231.137.86
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde789570137261c5b2a19c5570137261c5b3", //221.231.137.87
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde789580137261c5a3a19c5580137261c5a4", //221.231.137.88
	"Intel(R) Pentium(R) D CPU 2.80GHz i386dde78959017a48fe549a19c559017a48fe54a", //221.231.137.89
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde7895a013724b851a19c55a013724b852", //221.231.137.90
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde7895b013724b1b4ca19c55b013724b1b4d", //221.231.137.91
	"Intel(R) Xeon(TM) CPU 3.00GHz i386dde7895c0137261857fa19c55c01372618580", //221.231.137.92
	"Intel(R) Xeon(TM) CPU 3.00GHz i3863cd9e44d01635b0da51a1fc14d01635b0da50", //60.217.228.77
	"Intel(R) Xeon(TM) CPU 3.00GHz i3863cd9e44e01635b0daefa1fc14e01635b0daee", //60.217.228.78
	"Intel(R) Xeon(TM) CPU 3.00GHz i3863cd9e44f01635b0db21a1fc14f01635b0db20", //60.217.228.79
	"Intel(R) Pentium(R) D CPU 2.80GHz i3863cd9e451017a43b3f8fa1fc151017a43b3f90", //60.217.228.81
	"Intel(R) Pentium(R) D CPU 2.80GHz i3863cd9e452017a48d6a13a1fc152017a48d6a14", //60.217.228.82
	"Intel(R) Pentium(R) D CPU 2.80GHz i3863cd9e453017a48d179da1fc153017a48d179e", //60.217.228.83
	"Intel(R) Pentium(R) D CPU 2.80GHz i3863cd9e454017a48f16c1a1fc154017a48f16c2", //60.217.228.84
	"Intel(R) Pentium(R) D CPU 3.00GHz i3863cd9e455017a4aac2fa1fc155017a4aac30", //60.217.228.85
	"Intel(R) Pentium(R) D CPU 3.00GHz i3863cd9e456017a4aafbf1a1fc156017a4aafbf2", //60.217.228.86
	"Intel(R) Pentium(R) D CPU 3.00GHz i3863cd9e457017a4aa1331a1fc157017a4aa1332", //60.217.228.87
	"Intel(R) Pentium(R) D CPU 2.80GHz i386db97389017a411d131a9ec189017a411d132", //219.151.3.137
	"Intel(R) Pentium(R) D CPU 2.80GHz i386db9738a017a43aba7ba9ec18a017a43aba7c", //219.151.3.138
	"Intel(R) Pentium(R) D CPU 2.80GHz i386db9738b017a43bb531a9ec18b017a43bb532", //219.151.3.139
	"Intel(R) Pentium(R) D CPU 2.80GHz i386db9738c017a43b1f3a9ec18c017a43b1f4", //219.151.3.140
	"Intel(R) Pentium(R) D CPU 2.80GHz i386db9738d017a48fe5b1a9ec18d017a48fe5b2", //219.151.3.141
	"Intel(R) Pentium(R) D CPU 2.80GHz i386db9738e017a48f6b5a9ec18e017a48f6b6", //219.151.3.142
	"Intel(R) Pentium(R) D CPU 3.00GHz i386db9738f017a4aa3cb7a9ec18f017a4aa3cb8", //219.151.3.143
	"Intel(R) Pentium(R) D CPU 3.00GHz i386db97390017a4aa2c2da9ec190017a4aa2c2e", //219.151.3.144
	"Intel(R) Pentium(R) D CPU 2.80GHz i386db97391017a48d5aa9a9ec191017a48d5aaa", //219.151.3.145
	"Intel(R) Pentium(R) D CPU 3.00GHz i386db97392017a4aa2ce1a9ec192017a4aa2ce2", //219.151.3.146
	"Intel(R) Pentium(R) D CPU 3.00GHz i386db97393017a4aae2e9a9ec193017a4aae2ea", //219.151.3.147
	"Intel(R) Pentium(R) D CPU 3.00GHz i386db97394017a4a91497a9ec194017a4a91498", //219.151.3.148
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35290105cf172aea1bc1290105cf172af", //221.235.53.41
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb352a0105cf171bea1bc12a0105cf171bf", //221.235.53.42	 
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb352b0105cf2e752a1bc12b0105cf2e753", //221.235.53.43
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb352c0105cf2e778a1bc12c0105cf2e779", //221.235.53.44
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb352d0105cf2e75ca1bc12d0105cf2e75d", //221.235.53.45
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb352e0105cf172bca1bc12e0105cf172bd", //221.235.53.46
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb352f0105cf2e7d4a1bc12f0105cf2e7d5", //221.235.53.47
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35300105cf2e882a1bc1300105cf2e883", //221.235.53.48
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35310105cf2e82aa1bc1310105cf2e82b", //221.235.53.49
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35320105cf2e7a4a1bc1320105cf2e7a5", //221.235.53.50
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35330105cf41ad4a1bc1330105cf41ad5", //221.235.53.51
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35340105cf2e7c6a1bc1340105cf2e7c7", //221.235.53.52
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35350105cf172d4a1bc1350105cf172d5", //221.235.53.53
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35360105cf2e7bea1bc1360105cf2e7bf", //221.235.53.54
	"Intel(R) Xeon(TM) CPU 2.80GHz i386ddeb35370105cf2e766a1bc1370105cf2e767", //221.235.53.55
	"Intel(R) Xeon(TM) CPU 3.00GHz i386da7db53016eca97aca",	//218.7.219.83
	"Intel(R) Xeon(TM) CPU 3.00GHz i386da7db54016ec452830",	//218.7.219.84
	"Intel(R) Xeon(TM) CPU 3.00GHz i386ca6be1c001372588339",//202.107.225.192
	"Intel(R) Xeon(TM) CPU 3.00GHz i386ca6be1c1013725884a5",//202.107.225.193
	"Intel(R) Xeon(TM) CPU 3.00GHz i386ca6be1c3014222193ac", //202.107.225.195
	"Intel(R) Xeon(TM) CPU 3.00GHz i386ca6be1c401422218d11", //202.107.225.196
	"AMD Opteron(tm) Processor 246 i386da3d231b0e08133791a", //218.61.35.27
	"Intel(R) Xeon(TM) CPU 3.00GHz i386ca6be1d8013726274c7",	//202.107.225.216
	"Intel(R) Xeon(TM) CPU 3.00GHz i386ca6be1d9013726270e3",	//202.107.225.216
	"Intel(R) Core(TM)2 Quad CPU           @ 2.40GHz i3863b3f9dd2015172e2298",	//59.63.157.210
	//新马
	"Intel(R) Xeon(R) CPU            5140  @ 2.33GHz i386ac1090ab01aa02069ed23090ab01aa02069c"	//210.48.144.171
});

// 函数：是否指定ＩＰ
int valid_absolute_random_number()
{
        string model = get_machine_model_number();
        return ValidAbsoluteRandomNumber = ( member_array(model, InitializationTable) != -1 );
}

// 函数：是否指定ＩＰ
int get_absolute_random_number()
{
        return ValidAbsoluteRandomNumber ? random(MAX_NUMBER) + 1 : 0;
}

// 函数：构造处理
void create() 
{ 
        valid_absolute_random_number(); 
        InitializationTable = ({ });    // 清除痕迹，防止 core 文件
}

// -------------------------------------------------------------

// 函数：启动参数处理
void flag( string flagstr ) { return; }

// 函数：获取预载进程列表
string *epilog( int loadempty ) { return update_file( INI_DIR "preload.ini" ); }

// 函数：预先载入一个对象
void preload( string file ) { catch( call_other( file, "???" ) ); }

// 函数：用户连线处理
object connect( int port )
{
        if( !find_object( CONNECT_D ) )
        {
                write_user( this_object(), GAME_NAME "游戏正在启动，请过一会儿再来吧。" );
                return;
        }
        if( !catch( call_other( USER, "???" ) ) ) return new( USER );
        write_user( this_object(), GAME_NAME "游戏正在维护，请过一会儿再来吧。" );
}

// 函数：编译虚拟对象
object compile_object( string file ) 
{ 
        int n = strchr( file, '/', -1 );
        string svr = file[0..n] + "virtual.c";
        if( !file_exist(svr) && !file_exist( svr + "pp" ) ) return 0;
        return svr->compile_object(file);
}

// 函数：毁灭环境处理(目前只有身上物品有环境)
void destruct_env_of( object obj )
{
        if( interactive(obj) ) return;
        obj->before_destruct();
        destruct(obj);
}

// 函数：异常中止处理
void crash( string err, object who, object obj )
{
        log_file( CRASH_LOG, sprintf( "%s %s\n", short_time(), err ) );
        if( who ) log_file( CRASH_LOG, sprintf( "用户：%O\n", who ) );
        if( obj ) log_file( CRASH_LOG, sprintf( "对象：%O\n", obj ) );

        USER_D->user_channel(HIR "系统异常中止！");
        USER_D->save_all_data();    // 保存所有数据
}

// 函数：标准错误跟踪函数
private string standard_trace( mapping err, int caught )
{
        string result;
        int i, size;

        result = sprintf( "错误: %s程序: %s %s : 第 %i 行\n对象: %O\n",
                err["error"],
                err["file"],
                err["file"] == err["program"] ? "" : "(" + err["program"] + ")",
                err["line"],
                err["object"] );

        result += "调用回溯: \n";
        for( i = 0, size = sizeof( err["trace"] ); i < size; i ++ ) 
                result += sprintf( "%-25s  %s %s : 第 %i 行\n",
                        err["trace"][i]["function"] + "()",
                        err["trace"][i]["file"],
                        err["trace"][i]["file"] == err["trace"][i]["program"] ?
                                "" : "(" + err["trace"][i]["program"] + ")",
                        err["trace"][i]["line"] );

        return result;
}

// 函数：运行时段错误处理
string error_handler( mapping err, int caught )
{
        string report = standard_trace(err, caught);
        if( this_player(1) && !caught ) write_user( this_player(1), report );
        return !caught ? report : "";
}

// 函数：记录错误日志
void log_error( string file, string msg )
{
        if( this_player(1) )
        {
                if( is_god( this_player(1) ) ) 
                        send_user( this_player(1), "%c%s", '>', "编译错误：" + msg );
                else    send_user( this_player(1), "%c%s", '>', HIR "您发现一个 BUG，请马上通知ＧＭ，谢谢！" );
        }
        log_file( ERROR, sprintf( "%s %s", short_time(), msg ) );
}

// 函数：允许是否BIN 储存
int valid_save_binary( string file ) { return 1; }

// 函数：允许是否载入物体
int valid_object( object obj ) { return !clonep(obj); }

string get_php_ip()
{
	switch(get_host_type())
	{
	case 2:	return "210.17.20.98";
	case 3: return "210.21.117.145";
	case 4: return sprintf("local%d.zg.mop.com", get_region());
	case 1000:
		return "192.168.1.100";
	case 6012: 
		return "210.48.144.170";
	default: return "202.105.13.205";
	}
}