#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(2);
	set_number(130);
	set_name("Thị Thiên Quán Chế Tác");
	set_skill_level(74);
	set_tool(511);
	set_tili(1);
	set_final("/item/final/65/5070");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"52"	: 	2, 
	"37"	: 	3, 
//	无	: 	0, 
	"36"	: 	1, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
