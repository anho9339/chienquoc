#include <npc.h>
#include <ansi.h>
#include <time.h>

inherit OFFICER;

mapping maps = ([
	101: ([ "name" : "Trại Thành Kiều", 
	      "locate" : ({ 050,215,69, }), 
	    ]),		   
	102: ([ "name" : "Lăng Ly Sơn", 
	      "locate" : ({ 082,132,118, }), ]),		   
	201: ([ "name" : "Vạn Nhân Khanh 85 cấp",
		  "locate" : ({ 335,116,165, }),
		]),		   
	202: ([ "name" : "Tướng Quân Cổ Mộ 80 cấp",
		  "locate" :	({ 345,194,78, }),
		]),		   
	203: ([ "name" : "Cửu Khúc Cầu 100 cấp",
		  "locate" : ({ 374,53,83, }),
		]),		   
	301: ([ "name" : "Địa Ngục Ma Quật tầng 8",
		  "locate" : ({ 540,152,128, }),
		]),		   
	302: ([ "name" : "Thiên Ngoại Ảo Cảnh tầng 8",
		  "locate" : ({ 548,283,128, }),
		]),
    ]);




// 函数：获取人物造型
int get_char_picid() { return 5311; }
void do_welcome(string arg);

// 函数：构造处理
void create()
{
	set_name("Dịch Chuyển");
	set_real_name("Thiên Khởi");
	set_2("talk",(["welcome":(:do_welcome:)]));
	setup();
}

void do_look(object who)
{
    object me = this_object();
    __FILE__ ->do_welcome2(me, "");
}

void do_welcome( string arg )
{
    object who = this_object();
    __FILE__ ->do_welcome2(who, arg);
}

void do_welcome2( object who, string arg )
{
	int flag,id,i,size,p, x, y, z, *locate;
    object me, robber;
    string result;
    mapping temp;
    me = this_player();
    flag = to_int(arg);
    me->set_time( "talk",  0);
    id = getoid(who);
    if (arg=="")
    {
        result = sprintf("%s：\n    Ta là một người đẹp trai~~~Do đó ta có thể giúp ngươi tới nơi ngươi muốn~\n", who->get_name() );
        result += sprintf(ESC "Dịch chuyển đến Phó Bản\ntalk %x# welcome.100\n", id );
        result += sprintf(ESC "Dịch chuyển đến Bản Đồ Khuất\ntalk %x# welcome.200\n", id );
        result += sprintf(ESC "Dịch chuyển đến Cự Thú Đảo tầng cuối\ntalk %x# welcome.300\n", id );
        result += ESC"Rời khỏi\nCLOSE";
        send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        return ;
    }
    switch(flag)
    {
        case 100:
        	result = sprintf("%s：\n    Ngươi muốn tới bản đồ phó bản nào?\n", who->get_name() );
        	for (i=0;i<2;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[101+i]["name"], id, 101+i );
        	result += ESC"Rời khỏi\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;
        case 200:
        	result = sprintf("%s：\n    Ngươi muốn đi bản đồ khuất hả? Ok，Chọn đi! Ấn Alt+M để xem loại quái vật nhé.\n", who->get_name() );
        	for (i=0;i<3;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[201+i]["name"], id, 201+i );
        	result += ESC"Rời khỏi\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;        	
        case 300:
        	result = sprintf("%s：\n    Ngươi muốn đi Cự thú đảo tầng cuối hả? Xem kĩ cấp và trang bị rùi đi nhé.\n", who->get_name() );
        	for (i=0;i<2;i++)
        		result += sprintf(ESC "%s\ntalk %x# welcome.%d\n", maps[301+i]["name"], id, 301+i );
        	result += ESC"Rời khỏi\nCLOSE";
        	send_user( me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
        	break;
        default:     	        	
        	temp = 	maps[flag];
        	if (!temp) return;
        	if (temp["name"]==0) return;
        	locate = temp["locate"];
        	if (sizeof(locate)!=3) return;
        	z = locate[0], x = locate[1], y = locate[2];
        	if( p = get_valid_xy(z, x, y, IS_CHAR_BLOCK) )
        	{
	            x = p / 1000;  y = p % 1000;	
	            me->add_to_scene( z, x, y, 3 );        		
        	}
        	break;
    }
}
