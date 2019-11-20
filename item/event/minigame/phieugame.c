#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_color() { return 2; }
int get_item_value() {return 20 ;}
int get_item_value_2() {return 20 ;}

// 函数：构造处理
void create()
{
        set_name("Phiếu Trò Chơi");
		set_picid_1(0008);
        set_picid_2(0008);
		//set_level(0);
        set_value(1000);
		set_amount(1);
}

string get_desc() 
{ 
        return "Dùng để tham gia các Trò Chơi trong Chiến Quốc."; 
}
