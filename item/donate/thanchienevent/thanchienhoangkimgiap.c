
// 自动生成：/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit ARMOR;
//套装组件标志
int is_suit()	{ return 1;}	
//第几套
int get_equip_serial() { return 1; }	//第几套
// 函数：nh9h适用门派
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 8; }
//套装名字
string get_suit_name() { return "Linh lộc"; }	//属于某某套装
// 函数：nh9h构造处理
void create()
{
        set_name("Thần Chiến Hoàng Kim Giáp");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(10);
        set_value(99999999);
        set_max_lasting(16099);
        set("ap+", 500);
        set("dp+", 400);
        set("cp+", 450);
		set("cpp+",50);
        set("pp+", 400);
        set("sp+", 350);
        set("hp+", 400);
		set("double+",200);
        set("mp+", 220);
		set("@+",100);
		set("@%+",10);
		set("X@%+",10);
		set("-@%+",10);
		set("/%+",10);
		set("-c*+",100);
		set("-*",100);
	set_item_color(2);	//紫色		//捡取绑定
	set_hide(0);		//已鉴定
        setup();
		set_armor_color_1(H_YELLOW);
        set_armor_color_2(H_YELLOW);
}

// 函数：nh9h获取描述
string get_desc()
{
        return "Hoàng Sa Chiến Giáp , Tương Truyền Đã Thất Lạc Nhiều Năm";
}

// 函数：nh9h获取套装描述
string get_suit_desc()
{
        return " Thần Chiến Hoàng Kim Giáp tương truyền xuyên thượng toàn sáo tựu hội ủng hữu thần bí đích lực lượng";
}


