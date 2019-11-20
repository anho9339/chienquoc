
#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit USABLE;

//private int KIMNGUYENBAO; 

int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}
int get_item_color() { return 2; }
int get_item_type() { return ITEM_TYPE_CHIENTICH; }


// 函数：构造处理
void create()
{
        set_name("Bí Kíp Chiến Tích(5000)");
        set_picid_1(0089);
        set_picid_2(0089);
        set_unit("本");
        set_value(500000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Có thể chứa đựng 5000 điểm Chiến Tích dùng cho giao dịch \nClick chuột phải để cất điểm Chiến Tích vào Bí Kíp \nNếu đã cất điểm Chiến Tích vào Bí Kíp thì click chuột phải sẽ sử dụng";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        if( item->get_save_2("changping.score") < 1 )
        {
                if( me->get_save_2("changping.score") < 5000 )
                {
                        send_user(me, "%c%s", '!', "Không đủ 5000 điểm Chiến Tích !");
                        return 0;
                }
				me->add_save_2("changping.score",-5000);
				item->set_save_2("changping.score",5000);
                write_user(me, "Bạn đem 5000 điểm Chiến Tích cất vào %s.", item->get_name() );
                send_user( me, "%c%d%c", 0x31, getoid(item), 0 );

                return 0;    // 不能删除
        }
        else
        {
                me->add_save_2("changping.score",5000);
				send_user(me,"%c%s",';',"Bạn nhận được "HIY " 5000 điểm Chiến Tích");
                return 1;
        }
		
        return 0;
}
