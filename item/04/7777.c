#include <effect.h>

inherit ITEM;
inherit COMBINED;

int get_max_combined()
{
    return 30;
}

int get_item_color()
{
    return 1;
}

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

string get_desc()
{
    return "Hãy lưu giữ lại, nó sẽ được sử dụng trong tương lai！\nBạn ko chỉ có thể nhận được phần thưởng lớn，\n Mà "
           "còn có cơ hội đạt được trang bị cực phẩm!";
}
