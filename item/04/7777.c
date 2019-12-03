#include <effect.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 30; }

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Thất Quốc Lệnh");
        set_picid_1(98);
        set_picid_2(98);
        set_value(50);
        set_amount(1);
        set_no_give(1);
        set_no_sell(1);  
}

// 函数：获取描述
string get_desc() 
{ 
        return "Hãy lưu giữ lại, nó sẽ được sử dụng trong tương lai！\nBạn ko chỉ có thể nhận được phần thưởng lớn，\n Mà còn có cơ hội đạt được trang bị cực phẩm!"; 
}
