
#include <ansi.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 1; }
// 函数：构造处理
void create()
{
        set_name( "残图左上角" );
        set_picid_1(8001);
        set_picid_2(8001);
        set_unit( "张" );
        set_value(100);
}

// 函数：获取描述
string get_desc() 
{ 
        return "通过它可以找到宝藏"; 
}

// 函数：使用效果
int get_use_effect( object me )
{
        object obj, obj2, obj3, obj4;
        int p;

        if(     !( obj2 = present("残图右上角", me, 1, MAX_CARRY) )
        ||      !( obj3 = present("残图左下角", me, 1, MAX_CARRY) )
        ||      !( obj4 = present("残图右下角", me, 1, MAX_CARRY) ) )
        {
                send_user(me, "%c%s", '!', "您身上藏宝图残片不全，无法合并。");
                return 0;
        }

        obj2->remove_from_user();
        destruct(obj2);
        obj3->remove_from_user();
        destruct(obj3);
        obj4->remove_from_user();
        destruct(obj4);

        obj = new( "/item/std/8005" );
        if( p = obj->move(me, -1) ) obj->add_to_user(p);
        else destruct(obj);

        if( obj ) write_user(me, ECHO "您将四张藏宝图残片合并成一张残旧藏宝图。");

        return 1;
}
