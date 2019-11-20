#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Kéo Cắt Tóc");
		set_picid_1(3513);
        set_picid_2(3513);
		set_level(0);
        set_value(5000);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{
		return "Cây kéo dùng để cắt Tóc, kích chuột phải để sử dụng \nCó thể cắt tóc miễn phí 2 lần \nSau khi cắt tóc Miễn phí 2 lần phải tiêu hao \n5 Kim Nguyên Bảo cho những lần kế tiếp \n";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object me,object gift ) 
{
	string arg;
	
	"cmd/user/doitoc"->main(me,arg);
	return 0;
}