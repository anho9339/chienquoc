
// 自动生成：/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit WAIST;
//套装组件标志

//第几套
int get_equip_serial() { return 1; }	//第几套
// 函数：nh9h适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 8; }
//套装名字

// 函数：nh9h构造处理
void create()
{
        set_name("Thần Chiến Chi Yêu Đới");
        set_picid_1(8710);
        set_picid_2(8710);

        set_level(10);
        set_value(50000000);
        set_max_lasting(16099);
        set("ap+", 200);
        set("dp+", 200);
        set("cp+", 200);
        set("pp+", 200);
        set("sp+", 200);
        set("hp+", 200);
        set("mp+", 200);
	set_item_color(3);	//紫色
	//已鉴定
        setup();
}

// 函数：nh9h获取描述
string get_desc()
{
        return "Yêu Đới";
}

// 函数：nh9h获取套装描述
string get_suit_desc()
{
        return "Chiếc thắt lưng truyền kỳ nay đã trở lại !!!!";
}

