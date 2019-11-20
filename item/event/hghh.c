#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   
int get_item_color() {return 1 ;}
// 函数：构造处理
void create()
{
        set_name("Hạt Giống Hoa Hồng");
        set_picid_1(3234);
        set_picid_2(3234);
        set_unit("只");
        set_value(5000);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
	return "Loại hạt giống rất khó tìm, dùng cho sự kiện Lễ Tình Nhân.";
}

int get_use_effect(object who) { return __FILE__->get_use_effect_callout(who,this_object()); }

int get_use_effect_callout(object who,object item)
{
	int x,y,z,x0,y0,p;
	object obj,*nObj;
	
   if ( who->get_save("solantronghh") == 1 ) {
    if ( who->get_save("trongcayhh") < 1 ) {
		write_user(who, ECHO"Cây biến mất mới có thể trồng tiếp được");
		return 0;
	}
	}
	z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
	p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK);
        if( !p )
        	return 0;
	x = p / 1000;  y = p % 1000;
	obj = new("npc/event/hhnho");
	if ( !obj )
		return 0;
	obj->set("birth",time());
	obj->set_save("tuoinuochh",who->get_number());
	obj->add_to_scene( z, x, y);
	who->set_save("trongcayhh",0);
	who->set_save("solantronghh",1);
	who->set_save("trongcayabcxyz3",obj);
	who->set_save("trongcayabcxyz4",time());
	send_user(who,"%c%s",';',"Bạn đã trồng ra cây nảy mầm !");
	return 1;
}