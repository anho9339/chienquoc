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
	set_number(686);
	set_name("Khâm Thiên Chi Quán Chế Tác");
	set_skill_level(120);
	set_tool(512);
	set_tili(2);
	set_final("/item/final/65/7120");
	set_skill_temp(1);
	set_master("0");
	set_skill_color(1);
	set_base_rate(75);
        set_product( ([
	"54"	: 	4, 
	"273"	: 	3, 
	"28"	: 	3, 
	"89"	: 	2, 
	"320"	: 	1, 
//	无	: 	0,       	     
        ])); 	
        set_count(1);
}