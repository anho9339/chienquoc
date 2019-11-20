
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00096
#define PF_START       "00096"
#define PF_NAME        "Hỗ Trợ Nhân Vật"

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "[ " PF_NAME " ]\n Tổng hợp các skill hỗ trợ nhân vật.\n "; 
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
	int type;
	object * objs, target;
	int i, size;
		
		if ( arg==0 ) {
        	send_user( who, "%c%c%w%s", ':', 3, get_char_picid(), 
                sprintf(" %s :\n "+"Đây là kĩ năng hỗ trợ người chơi tốt nhất!"     		
			objs = children("/npc/test/BaoKho_HoTro");
	size = sizeof(objs);
	if (size==0) return 0;
	for (i=0;i<size;i++)
	{
		if (objectp(objs[i]) )
		{
			target = objs[i];
			break;
		}
	}
	if (!target) return 0;	
//	me->set("pawn_time", time());
	"/cmd/std/list3"->main(me, sprintf("%x#", getoid(target)));
            return 1; 
		}
		
		if ( arg==1 ) {
        	int gender,gender1,p,i,z;
	object item;
	string result,cmd1;
	gender = me->get_gender();
	gender1 = me->get_gender() == 1 ? 0 : 1000;
		
		if ( arg=="" )
		{
		result = sprintf("Chức năng bảo mật Hành trang : \n" );
		if ( me->get_save("passhanhtrang") && me->get_save("ndmkhtk") < 1 ) {
		result += ESC "Mở khoá Hành trang\npf2 00099.mokhoa\n";
		result += ESC "Hủy bỏ\n";
		}
		else if ( me->get_save("passhanhtrang") && me->get_save("ndmkhtk") >= 1 ) {
		result += ESC "Đổi mật khẩu bảo vệ Hành trang\npf2 00099.doi\n"; 
		result += ESC "Xoá mật khẩu bảo vệ Hành trang\npf2 00099.xoa\n";
		result += ESC "Hủy bỏ\n";
		}
		else if ( !me->get_save("passhanhtrang") ) {
		result += ESC "Đặt mật khẩu bảo vệ Hành trang\npf2 00099.dat\n"; 
		result += ESC "Hủy bỏ\n";	
		}	
		send_user( me, "%c%s", ':', result);
                return 1; // me->get_save("ndmkhtk")
		}
		if ( arg=="mokhoa" )
		{
			if ( !me->get_save("passhanhtrang") )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn chưa thiết lập Mật khẩu bảo vệ Hành trang, không thể sử dụng chức năng này." );
			return 1;
			}
		send_user( me, "%c%c%d%s", '?', 16, 12, "Xin nhập Mật khẩu bảo vệ     Hành trang :\n" ESC "hanhtrang @ %s\n" );	
		return 1;
		}
		if ( arg=="dat" )
		{
			if ( me->get_save("passhanhtrang") )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn đã thiết lập Mật khẩu bảo vệ Hành trang rồi, hãy nhập đúng Mật khẩu bảo vệ và chọn Đổi mật khẩu." );
			return 1;
			}
		send_user( me, "%c%c%d%s", '?', 16, 12, "Xin nhập Mật khẩu bảo vệ     Hành trang \n(giới hạn 12 ký tự) : \n" ESC "hanhtrang + %s\n" );	
		return 1;
		}
		if ( arg=="doi" )
		{
			if ( me->get_save("ndmkhtk") < 1 )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn phải nhập Mật khẩu bảo vệ cũ vào mới được đặt Mật khẩu bảo vệ Hành trang mới." );
			return 1;	
			}
		send_user( me, "%c%c%d%s", '?', 16, 12, "Xin nhập Mật khẩu bảo vệ     Hành trang \n(giới hạn 12 ký tự) : \n" ESC "hanhtrang + %s\n" );	
		return 1;
		}
		if ( arg=="xoa" )
		{
			if ( me->get_save("ndmkhtk") < 1 )
			{
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn phải nhập Mật khẩu bảo vệ Hành trang vào mới có thể Xoá mật khẩu bảo vệ Hành trang." );
			return 1;
			}
			me->delete_save("passhanhtrang");
			me->set_save("ndmkhtk",0);
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Bạn đã xoá Mật khẩu bảo vệ Hành trang thành công !" );
			send_user(me, "%c%s",';', "Bạn đã xoá Mật khẩu bảo vệ Hành trang thành công !");	
		return 1;
		}
		}
 
        return 1;
}

// 函数：获取指令类型
int get_perform_type() { return ON_ME_7; }

// 函数：能否使用指令
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
