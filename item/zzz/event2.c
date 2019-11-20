#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

// 函数：构造处理
void create()
{
        set_name("Thánh Linh Chi Dực·Xanh Lục");
        set_picid_1(3032);
        set_picid_2(3032);

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
        set_back_type(7);
		set_back2_type(7);
		set_back_color(0x008B3D48);//0x00E22B8A
		set_back2_color(0x008B3D48);
}

// 函数：获取描述
string get_desc()
{
    object item = this_object();
	if(item->get_lock_time()== 0)
	{
		item->set_lock_time(time()+24*3600*14);
	}    
		return "Thánh vật của sứ giả Quang Minh, dùng để ngăn cản lực lượng tà ác uy hiếp.";
}
