
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// 函数：命令处理
int main( object me, string arg )
{
	object who;
        int i, size, a1, a2, a3, a4;
		if ( arg!=0 ) return 1;
		if ( me->get_save("nonhatdo") < 1 ) {
			me->set_save("nonhatdo",1);
			tell_user(me, "Bạn đã thiết lập: Không Nhặt Đồ");
		}	
		else {
			me->delete_save("nonhatdo");
			tell_user(me, "Bạn đã thiết lập: Cho Phép Nhặt Đồ");
		}	
	
        return 1;
}
