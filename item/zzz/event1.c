#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Vạn Ác Chi Dực - Vàng Rực");
        set_picid_1(3038);
        set_picid_2(3038);

        set_level(1);
		set_bind(1);
        set_value(1000);
	//	set_save("qsvst",1200);
        set_max_lasting(21599);
		set("time_item", 1);
        set("ap+", 100);
        set("cp+", 100);
        set("dp+", 100);
        set("hp+", 300);
		set("mp+", 300);
		set("sp+", 50);
	//	set("double", 500);

        setup();

    //    set_gender(1);
        set_back_type(8);
		set_back2_type(8);
		set_back_color(0x00EBCE87);
		set_back2_color(0x00EBCE87);
}

// 函数：获取描述
string get_desc()
{
    object item = this_object();
	if(item->get_lock_time()== 0)
	{
		item->set_lock_time(time()+24*3600*14);
	}
		return "Vạn Ác chi dực do Nha Ác Vu Sư chế tạo, hiệu quả bất ngờ khi sử dụng.";
}