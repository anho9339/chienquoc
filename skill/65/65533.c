#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(650);
	set_skill_type(2);
	set_number(533);
	set_name("Huyền Kim Hạng Liên Chế Tác");
	set_skill_level(65);
	set_tool(516);
	set_tili(1);
	set_final("/item/final/86/7065");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"84"	: 	1, 
	"1811"	: 	1, 
	"57"	: 	1, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}