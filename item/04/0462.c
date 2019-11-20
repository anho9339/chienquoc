inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("菊花酒");
        set_picid_1(3151);
        set_picid_2(3151);
        set_amount(1);
        set_value(100);
}

void reset()
{
        if( gone_time( get_drop_time() ) > 3000 )    // 50分钟
        {
                remove_from_scene();
                destruct( this_object() );
        }
}

// 函数：获取描述
string get_desc() 
{ 
        return "重阳四宝之一"; 
}
