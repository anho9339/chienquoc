#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
inherit "/inh/std/vitaskill";

void create()
{	
	set_skill(640);
	set_skill_type(6);
	set_number(26);
	set_name("Ti Tuyến Chế Tác");
	set_skill_level(30);
	set_tool(510);
	set_tili(0);
	set_final("/item/stuff/0035");
	set_skill_temp(0);
	set_master("0");
	set_skill_color(0);
	set_base_rate(95);
        set_product( ([
	"47"	: 	1, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}
