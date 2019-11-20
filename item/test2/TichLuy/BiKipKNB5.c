
#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit USABLE;

//private int KIMNGUYENBAO; 

int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}
int get_item_color() { return 2; }
int get_item_type() { return ITEM_TYPE_KIMNGUYENBAO; }


// 函数：构造处理
void create()
{
        set_name("Bí Kíp Kim Nguyên Bảo(20000)");
        set_picid_1(0089);
        set_picid_2(0089);
        set_unit("本");
        set_value(700000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Có thể chứa đựng 20.000 Kim Nguyên Bảo dùng cho giao dịch \nClick chuột phải để cất Kim Nguyên Bảo vào Bí Kíp \nNếu đã cất Kim Nguyên Bảo vào Bí Kíp thì click chuột phải sẽ sử dụng";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
        if( "sys/sys/test_db"->get_yuanbao(item) < 1 )
        {
                if( "sys/sys/test_db"->get_yuanbao(me) < 200000 )
                {
                        send_user(me, "%c%s", '!', "Không đủ 20.000 Kim Nguyên Bảo !");
                        return 0;
                }
                "sys/sys/test_db"->add_yuanbao(me,-200000);
                "sys/sys/test_db"->set_yuanbao(item,200000);
                write_user(me, "Bạn đem 20.000 Kim Nguyên Bảo cất vào %s.", item->get_name() );
                send_user( me, "%c%d%c", 0x31, getoid(item), 0 );

                return 0;    // 不能删除
        }
        else
        {
                "sys/sys/test_db"->add_yuanbao(me,200000);
				send_user(me,"%c%s",';',"Bạn nhận được "HIY " 20.000 Kim Nguyên Bảo");
                return 1;
        }
		
        return 0;
}
