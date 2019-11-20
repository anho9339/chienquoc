inherit ITEM;
inherit COMBINED;   

int is_zhongqiu() { return 1; }
// 函数：nh9h构造处理
void create()
{
        set_name("Thỏ Ngọc");
        set_picid_1(3569);
        set_picid_2(3569);
        set_unit("Chỉ");
        set_value(100);
        set_amount(1);      
              
}

// 函数：nh9h获取描述
string get_desc() 
{
	return "Thỏ ngọc của Hằng Nga, đem nó về cho Hằng Nga sẽ nhận được phần thưởng hấp dẫn.";    	
}
