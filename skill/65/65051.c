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
	set_number(51);
	set_name("Viêm Dương Hạng Liên Chế Tác");
	set_skill_level(52);
	set_tool(516);
	set_tili(1);
	set_final("/item/final/86/2050");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(75);
        set_product( ([
	"60"	: 	1, 
	"81"	: 	1, 
	"78"	: 	1, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
