
// 自动生成：/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit BOOTS;
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
        set_name("Thần Chiến Chi Hài");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(10);
        set_value(50000000);
        set_max_lasting(16099);
        set("ap+", 200);
        set("dp+", 200);
        set("cp+", 200);
        set("pp+", 150);
        set("sp+", 150);
        set("hp+", 150);
        set("mp+", 150);
	set_item_color(3);	//紫色

        setup();
}

// 函数：nh9h获取描述
string get_desc()
{
        return "Hài";
}

// 函数：nh9h获取套装描述
string get_suit_desc()
{
        return "Linh hồ sáo trang kỳ trung chi nhất, tương truyền xuyên thượng\n toàn sáo tựu hội ủng hữu thần bí đích lực lượng";
}

