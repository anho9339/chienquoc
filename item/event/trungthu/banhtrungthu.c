#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

int is_zhongqiu() { return 1;}
int get_item_type_2() { return ITEM_TYPE_2_CON_ALL; }
int get_recover_count() { return 10; }
// 函数：nh9h构造处理
void create()
{
        set_name("Bánh Trung Thu");
        set_picid_1(3570);
        set_picid_2(3570);
        set_unit("Cái");
        set_value(100);
        set_amount(1);      
	set("add_hp", 400);	        
	set("add_mp", 400);
          
}

void reset()
{
        if( gone_time( get_drop_time() ) > 3000 )    // 50 phút
        {
                remove_from_scene();
                destruct( this_object() );
        }
}

// 函数：nh9h获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{
	return "Chỉ tết trung thu mới có loại bánh này. Trong vòng 20 giây khôi phục 400 khí huyết và 400 pháp lực.";    	
}

// 函数：nh9h使用Hiệu quả 
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }