#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 500 ;}
int get_item_value_2() {return 500 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Thẻ VIP");
        set_picid_1(3812);
        set_picid_2(3812);
        set_value(1000);
		set_amount(1);   
		set_save("tienxu",50);
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return "Thẻ dành cho Hội viên VIP. \nCó thẻ này gia tăng thêm 5% tỉ lệ ép thành công đoạn thạch."; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{	
	if(who->get_save("thevipl1") >= 1) {
			send_user(who,"%c%s",';',sprintf("Bạn đã sử dụng Thẻ VIP 1 lần rồi, còn muốn tiếp tục sử dụng sao?."));		
			return 0;
	} 
	send_user(who,"%c%s",';',sprintf("Bạn đã sử dụng gói VIP, tỉ lệ ép thành công được gia tăng vĩnh viễn 5%%."));
	who->add_save("thevipl1",1);
	gift->add_amount(-1);
	return 0;
		
}
