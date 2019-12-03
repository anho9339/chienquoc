inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Hồ Lô Chiêu Hầu");
        set_picid_1(4271);
        set_picid_2(4271);
	set_amount(1);
        set_value(50);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Hồ Lô Thần Kì，\nChứa đựng những con khỉ ăn cắp dưa hấu，\nHãy Giao nó cho chủ tiệm dưa。"; 
}
