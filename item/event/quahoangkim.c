#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Quả hoàng kim");
        set_picid_1(3282);
        set_picid_2(3282);
        set_value(10);
	//	set_save("knb",50);
		set_amount(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Một loại quả rất kỳ lạ, có thể phát sáng trong đêm tối, ăn vào chắc chắn sống lâu trăm tuổi."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash,exp;
	object item;
	if ( who->get_level() < 1 )
	{
		send_user(who, "%c%s", '!', "Cấp 1 trở lên mới có thể sử dụng !");
		return 0;
	}
	gift->add_amount(-1);
	exp = who->get_level()*2000+random(5000);
	who->add_exp(exp);
	send_user(who, "%c%s", ';', sprintf("Bạn đã nhận được %d kinh nghiệm, xin chúc mừng !",exp));
	return 0;
}

