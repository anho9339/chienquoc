
inherit SKILL;

// 函数：构造处理
void create() 
{ 
        set_number(0426);
        set_name( "Côn Luân Đao Chú" );
}

// 函数：能否特殊技
void can_perform( object me )
{
        __DIR__ "04261"->can_perform(me);
        __DIR__ "04262"->can_perform(me);
		__DIR__ "04263"->can_perform(me);
}

// 函数：删除特殊技
void remove_perform( object me )
{
        send_user( me, "%c%w%w", 0x50, 0xffff, 04261 );
        send_user( me, "%c%w%w", 0x50, 0xffff, 04262 );
		send_user( me, "%c%w%w", 0x50, 0xffff, 04263 );
}
void recount_char( object me ) { USER_ENERGY_D->count_hit_rate(me); }
// 函数：获取描述
string get_desc() 
{
        return "[Côn Luân Đao Chú]Pháp chú dành cho Côn Luân hệ Đao pháp, mỗi cấp gia tăng thêm 0.4% Chính Xác và 0.1% xác xuất gây Choáng.\n";
}
