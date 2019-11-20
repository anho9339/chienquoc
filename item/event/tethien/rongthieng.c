#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;   

int is_zhongqiu() { return 1; }
// 函数：nh9h构造处理
void create()
{
        set_name("Rồng Thiêng");
        set_picid_1(4246);
        set_picid_2(4246);
        set_unit("Chỉ");
        set_value(100);
        set_amount(1);      
        set_no_give(0);//
        set_no_drop(0);//可丢弃.
        set_no_sell(0);//可交易,可存当铺,可摆摊.
          
}

// 函数：nh9h获取描述
string get_desc() 
{
	return "Rồng thiêng đc sinh ra từ trên thiên đình. Xuống nhân gian làm gì chả ai biết.";    	
}
