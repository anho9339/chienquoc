
inherit SKILL;
//强化技能标志
int is_enhance_skill() {return 1;}

// 函数：构造处理
void create() 
{ 
        set_number(0334);
        set_name( "Cường Hoá Chu Thiên Vạn Chuyển" );
}

// 函数：重计属性
void recount_char( object me ) 
{ 
	USER_ENERGY_D->count_max_hp(me); 
//	USER_ENERGY_D->count_pp(me); 
}

// 函数：获取描述
string get_desc() 
{
        return "［Cường Hoá Chu Thiên Vạn Chuyển］Gia tăng Khí Huyết cao nhất, mỗi cấp gia tăng 4 điểm.";
}
