#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(3);
	set_number(139);
	set_name("Thiên Uy Ngoa Chế Tác");
	set_skill_level(79);
	set_tool(511);
	set_tili(1);
	set_final("/item/final/88/4070");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"50"	: 	1, 
	"284"	: 	1, 
	"52"	: 	4, 
	"36"	: 	1, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
