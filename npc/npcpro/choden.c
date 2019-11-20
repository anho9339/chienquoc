
// 自动生成：/make/npc/make0002

#include <npc.h>
#include <cmd.h>

inherit OFFICER;

// 函数：小贩识别
int is_seller_2() { return 1; }

// 函数：获取人物造型
int get_char_picid() { return 5402; }

void reset() ;

// 函数：构造处理
void create()
{
			set_name("Thương Nhân Chợ Đen");
			set_real_name("Hạng Lương");

			set_2( "good", ([
						"01" : "/sys/item/chodenitem"->get_random_itemchoden(),
						"02" : "/sys/item/chodenitem"->get_random_itemchoden(),
						"03" : "/sys/item/chodenitem"->get_random_itemchoden(),
						"04" : "/sys/item/chodenitem"->get_random_itemchoden(),
						"05" : "/sys/item/chodenitem"->get_random_itemchoden(),
						"06" : "/sys/item/chodenitem"->get_random_itemchoden(),
						"07" : "/sys/item/chodenitem"->get_random_itemchoden(),
						"08" : "/sys/item/chodenitem"->get_random_itemchoden(),
				]) );
			set_2( "list", ([
				"01" : 1+random(2),
				"02" : 1+random(2),
				"03" : 1+random(2),
				"04" : 1+random(2),
				"05" : 1+random(2),
				"06" : 1+random(2),
				"07" : 1+random(2),
				"08" : 1+random(2),
	        ]) );	       
        setup();
}

// 函数：复位处理
void reset() 
{
	object me = this_object();
	int count;
	count = me->add("count", 1);
	if (count % 3 == 0 )
	{
	        me->set_2( "good", ([
	                "01" : "/sys/item/chodenitem"->get_random_itemchoden(),
					"02" : "/sys/item/chodenitem"->get_random_itemchoden(),
					"03" : "/sys/item/chodenitem"->get_random_itemchoden(),
					"04" : "/sys/item/chodenitem"->get_random_itemchoden(),
					"05" : "/sys/item/chodenitem"->get_random_itemchoden(),
					"06" : "/sys/item/chodenitem"->get_random_itemchoden(),
					"07" : "/sys/item/chodenitem"->get_random_itemchoden(),
					"08" : "/sys/item/chodenitem"->get_random_itemchoden(),
	        ]) );
	
	        me->set_2( "list", ([
				"01" : 1+random(2),
				"02" : 1+random(2),
				"03" : 1+random(2),
				"04" : 1+random(2),
				"05" : 1+random(2),
				"06" : 1+random(2),
				"07" : 1+random(2),
				"08" : 1+random(2),
	        ]) );		
	}	
}

// 函数：对话处理
void do_look( object who )
{
        "/cmd/std/look"->main( who, sprintf( "%x#", getoid( this_object() ) ) );
}
