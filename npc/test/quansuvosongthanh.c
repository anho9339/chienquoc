
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller() { return 7002; }
int is_self_look() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5502; }

// 函数：构造处理
void create()
{
        set_name("Quân Sư Vô Song Thành");

        set_2( "good", ([
				"01" : "/item/100/10051",
				"02" : "/item/100/11051",
				"03" : "/item/30/3020",
				"04" : "/item/30/3021",
				"05" : "/item/30/3031",
				"06" : "/item/30/3028",
				"07" : "/item/test2/tuitukim55",
				
        ]) );
        setup();
}
void do_look( object who ) 
{
	int id = getoid( this_object() );
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf(" %s :\n Hoan nghênh! Vô Song Thành là thiên hạ đệ nhất đại thành với những bảo vật quý hiếm trên nhân gian, chỉ cần ngươi giao cho ta Vô Song Điểm Phiếu thì sẽ được tưởng thưởng hậu hĩ \n"
		ESC HIY"Đổi vật phẩm\nlist4 %x#\n"
		ESC"Rời khỏi",get_name(),id));	
}