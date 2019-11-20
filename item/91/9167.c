
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 30 ;}
int get_item_value_2() {return 30 ;}
int get_item_color() { return 2; }
// 函数：需要确认卖出
int confirm_sell_item() { return 1; }

// 函数：构造处理
void create()
{
        set_name( "Tử Sâm Đơn" );
        set_picid_1(9167);
        set_picid_2(9167);
        set_unit( "粒" );
        set_value(50);
		set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Tăng 2000 điểm tiềm năng, thời gian tái sử dụng 2 giây";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me,this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
		//if (me->get_potential()+2000>me->get_max_potential())
		if (me->get_potential()>=me->get_max_potential())
		{
		
                send_user( me, "%c%s", '!', "Tiềm năng đã đạt giới hạn tối đa." );
                return 0;		
		}	
      	if( gone_time( me->get_time("eat_zs") ) < 2 )
        {
                send_user( me, "%c%s", '!', sprintf("Tái sử dụng sau %d giây", 2 - gone_time( me->get_time("eat_zs") ) ) );
                return 0;
        }        
		me->set_time( "eat_zs", time() );  
        me->add_potential(2000);
		send_user(me, "%c%s",'!',"Bạn đã nhận được 2000 Tiềm năng");
		item->add_amount(-1);
        //return 1;
}
