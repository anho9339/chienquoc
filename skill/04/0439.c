
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0439);
        set_name( "Cường Hoá Chính Xác" );
}

int get_learn_money() {return 107000; }

// 函数：重计属性
//void recount_char( object me ) { USER_ENERGY_D->count_max_mp(me); }

// 函数：获取描述
string get_desc() 
{
        return "［Cường Hoá Bảo Hộ］ Tăng độ chính xác khi công kích từ xa và cận chiến, công kích từ xa mỗi cấp tăng 1％, công kích cận chiến mỗi cấp tăng 2％.\n";
}
