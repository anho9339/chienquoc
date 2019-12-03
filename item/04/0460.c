inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Thù Du");
        set_picid_1(3289);
        set_picid_2(3289);
        set_amount(1);
        set_value(40);
}

void reset()
{
        if( gone_time( get_drop_time() ) > 3000 )    // 100分钟
        {
                remove_from_scene();
                destruct( this_object() );
        }
}

// 函数：获取描述
string get_desc() 
{ 
        return "Một trong bốn báu vật của Trọng Dương"; 
}
