#include <equip.h>
#include <ansi.h>
//inherit USABLE;
inherit ITEM;
inherit COMBINED;

int get_item_value() {return 20 ;}
int get_item_value_2() {return 20 ;}
//int get_item_number() {return 10001070 ;}
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name("Lệnh PretKuzl");
        set_picid_1(4984);
        set_picid_2(4984);
        set_value(10000);
		set_amount(1);
	//	set_save("knb2",10);
}

// 函数：获取描述
string get_desc()
{
        return "Một loại lệnh bài đặc biệt. Chỉ khi dùng loại lệnh này, các anh hùng mới có thể gia nhập Phó Bản.\n (Nghe đồn người ban bố lệnh này khá đẹp trai).";
}
