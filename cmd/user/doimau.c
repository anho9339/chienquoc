
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>

int main( object me, string arg )
{
	int gender,gender1,p,x,y,i,z;
	object item;
	string result,cmd1;
	gender = me->get_gender();
	gender1 = me->get_gender() == 1 ? 0 : 1000;
	
		if( !objectp( item = present("Thần Sắc Thạch", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Sắc Thạch!");
                return 1;
        }	
	   if ( arg==0 )
	{
		result = sprintf("Bạn đang sử dụng Thần Sắc Thạch, xin hãy lựa chọn : \n" ); 
		result += ESC HIG"Đổi màu Cánh (Nam)\ndoimau maucnam\n";
		result += ESC HIG"Đổi màu Cánh (Nữ)\ndoimau maucnu\n";
		result += ESC HIC"Đổi màu Phi Phong (Nam)\ndoimau maupnam\n";
		result += ESC HIC"Đổi màu Phi Phong (Nữ)\ndoimau maupnu\n";
		result += ESC "Hủy bỏ\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
	}
			if ( arg=="maucnam" )
	{
			result = sprintf("Bạn đang sử dụng Thần Sắc Thạch, xin hãy lựa chọn màu bạn thích :\n" );
		result += ESC "Đen Huyền\ndoimau 1b\n"; 
		result += ESC "Hỗn thể Xanh Nhạt - Vàng Kem\ndoimau 2b\n"; 
		result += ESC "Hỗn thể Xám - Xanh Lá\ndoimau 3b\n"; 
		result += ESC "Hỗn thể Xanh Đen - Đỏ Đậm\ndoimau 4b\n"; 
		result += ESC "Hỗn thể Hồng Tím - Xanh Lục\ndoimau 5b\n"; 
		result += ESC "Hủy bỏ đổi màu\ndoimau 10b\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
	}
			
	if ( arg == "1b")
	{
	    if( !objectp( item = present("Thánh Linh Chi Dực·Vàng Nhạt", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Vàng Nhạt!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Vàng Nhạt" )
			{
		item->set_back_color(0x0020);
		item->set_back2_color(0x0020);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "2b")
	{
       if( !objectp( item = present("Thánh Linh Chi Dực·Vàng Nhạt", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Vàng Nhạt!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Vàng Nhạt" )
			{
		item->set_back_color(0x00FAFFF5);
		item->set_back2_color(0x0000D7FF); // Xanh đẹp
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "3b")
	{
        if( !objectp( item = present("Thánh Linh Chi Dực·Vàng Nhạt", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Vàng Nhạt!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Vàng Nhạt" )
			{
		item->set_back_color(GRAY);
		item->set_back2_color(LIME);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "4b")
	{
       if( !objectp( item = present("Thánh Linh Chi Dực·Vàng Nhạt", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Vàng Nhạt!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Vàng Nhạt" )
			{
		item->set_back_color(NAVY);
		item->set_back2_color(0x6000);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "5b")
	{
       if( !objectp( item = present("Thánh Linh Chi Dực·Vàng Nhạt", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Vàng Nhạt!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Vàng Nhạt" )
			{
		item->set_back_color(0x008B3D48);
		item->set_back2_color(0x00CDEBFF);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "10b")
	{
		if( !objectp( item = present("Thánh Linh Chi Dực·Vàng Nhạt", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Vàng Nhạt!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Vàng Nhạt" )
			{
		item->set_back_color(0xdf0c);
		item->set_back2_color(0xdf0c);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	
	if ( arg=="maucnu" )
	{
			result = sprintf("Bạn đang sử dụng Thần Sắc Thạch, xin hãy lựa chọn màu bạn thích :\n" );
		result += ESC "Đen Huyền\ndoimau 1g\n"; 
		result += ESC "Hỗn thể Xanh Nhạt - Vàng Kem\ndoimau 2g\n"; 
		result += ESC "Hỗn thể Xám - Xanh Lá\ndoimau 3g\n"; 
		result += ESC "Hỗn thể Xanh Đen - Đỏ Đậm\ndoimau 4g\n";
        result += ESC "Hỗn thể Hồng Tím - Xanh Lục\ndoimau 5g\n"; 		
		result += ESC "Hủy bỏ đổi màu\ndoimau 10g\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
	}
			
	if ( arg == "1g")
	{
	    if( !objectp( item = present("Thánh Linh Chi Dực·Trắng Thuần", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Trắng Thuần!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Trắng Thuần" )
			{
		item->set_back_color(0x0020);
		item->set_back2_color(0x0020);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "2g")
	{
       if( !objectp( item = present("Thánh Linh Chi Dực·Trắng Thuần", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Trắng Thuần!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Trắng Thuần" )
			{
		item->set_back_color(0x00FAFFF5);
		item->set_back2_color(0x0000D7FF); 
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "3g")
	{
        if( !objectp( item = present("Thánh Linh Chi Dực·Trắng Thuần", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Trắng Thuần!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Trắng Thuần" )
			{
		item->set_back_color(GRAY);
		item->set_back2_color(LIME);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "4g")
	{
       if( !objectp( item = present("Thánh Linh Chi Dực·Trắng Thuần", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Trắng Thuần!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Trắng Thuần" )
			{
		item->set_back_color(NAVY);
		item->set_back2_color(0x6000);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "5g")
	{
       if( !objectp( item = present("Thánh Linh Chi Dực·Trắng Thuần", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Trắng Thuần!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Trắng Thuần" )
			{
		item->set_back_color(0x008B3D48);
		item->set_back2_color(0x00CDEBFF);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "10g")
	{
		if( !objectp( item = present("Thánh Linh Chi Dực·Trắng Thuần", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thánh Linh Chi Dực·Trắng Thuần!");
                return 1;
        }
		if (item->get_name()=="Thánh Linh Chi Dực·Trắng Thuần" )
			{
		item->set_back_color(0xffff);
		item->set_back2_color(0xffff);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	
	if ( arg=="maupnam" )
	{
			result = sprintf("Bạn đang sử dụng Thần Sắc Thạch, xin hãy lựa chọn màu bạn thích :\n" );
		result += ESC "Đỏ\ndoimau 1pn\n"; 
		result += ESC "Trắng\ndoimau 2pn\n"; 
		result += ESC "Xanh Lá\ndoimau 3pn\n"; 
		result += ESC "Đen\ndoimau 4pn\n";
        result += ESC "Xanh Nhạt\ndoimau 5pn\n"; 
        result += ESC "Vàng Kem\ndoimau 6pn\n"; 		
		result += ESC "Hủy bỏ màu phi phong\ndoimau 10pn\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
	}
	
	if ( arg == "1pn")
	{
	    if( !objectp( item = present("Thần Phong Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Phong Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Thần Phong Phi Phong" )
			{
		item->set_back_color(0x6186);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "2pn")
	{
       if( !objectp( item = present("Thần Phong Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Phong Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Thần Phong Phi Phong" )
			{
		item->set_back_color(0x00EEEEAF);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "3pn")
	{
        if( !objectp( item = present("Thần Phong Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Phong Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Thần Phong Phi Phong" )
			{
		item->set_back_color(0x3306);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "4pn")
	{
       if( !objectp( item = present("Thần Phong Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Phong Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Thần Phong Phi Phong" )
			{
		item->set_back_color(0x0020);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "5pn")
	{
       if( !objectp( item = present("Thần Phong Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Phong Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Thần Phong Phi Phong" )
			{
		item->set_back_color(0x0000D7FF);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "6pn")
	{
       if( !objectp( item = present("Thần Phong Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Phong Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Thần Phong Phi Phong" )
			{
		item->set_back_color(0x00FAFFF5);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "10pn")
	{
		if( !objectp( item = present("Thần Phong Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Thần Phong Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Thần Phong Phi Phong" )
			{
		item->set_back_color(0);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	
	if ( arg=="maupnu" )
	{
			result = sprintf("Bạn đang sử dụng Thần Sắc Thạch, xin hãy lựa chọn màu bạn thích :\n" );
		result += ESC "Đỏ\ndoimau 1pg\n"; 
		result += ESC "Trắng\ndoimau 2pg\n"; 
		result += ESC "Xanh Lá\ndoimau 3pg\n"; 
		result += ESC "Đen\ndoimau 4pg\n";
        result += ESC "Xanh Nhạt\ndoimau 5pg\n"; 
        result += ESC "Vàng Kem\ndoimau 6pg\n"; 		
		result += ESC "Hủy bỏ màu phi phong\ndoimau 10pg\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
	}
	
	if ( arg == "1pg")
	{
	    if( !objectp( item = present("Xí Nhiệt Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Xí Nhiệt Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Xí Nhiệt Phi Phong" )
			{
		item->set_back_color(0x6186);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "2pg")
	{
       if( !objectp( item = present("Xí Nhiệt Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Xí Nhiệt Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Xí Nhiệt Phi Phong" )
			{
		item->set_back_color(0x00EEEEAF);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "3pg")
	{
        if( !objectp( item = present("Xí Nhiệt Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Xí Nhiệt Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Xí Nhiệt Phi Phong" )
			{
		item->set_back_color(0x3306);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "4pg")
	{
       if( !objectp( item = present("Xí Nhiệt Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Xí Nhiệt Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Xí Nhiệt Phi Phong" )
			{
		item->set_back_color(0x0020);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "5pg")
	{
       if( !objectp( item = present("Xí Nhiệt Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Xí Nhiệt Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Xí Nhiệt Phi Phong" )
			{
		item->set_back_color(0x0000D7FF);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "6pg")
	{
       if( !objectp( item = present("Xí Nhiệt Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Xí Nhiệt Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Xí Nhiệt Phi Phong" )
			{
		item->set_back_color(0x00FAFFF5);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	if ( arg == "10pg")
	{
		if( !objectp( item = present("Xí Nhiệt Phi Phong", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Xí Nhiệt Phi Phong!");
                return 1;
        }
		if (item->get_name()=="Xí Nhiệt Phi Phong" )
			{
		item->set_back_color(0);
		}
     /*   if ( me->get_cash() < 500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 500.000");
		return 1;
		}
		me->add_cash(-500000);
		if("sys/sys/test_db"->get_yuanbao(me)<2000)
			{	
				write_user(me, ECHO "Bạn không có đủ 200 Kim Nguyên Bảo !");
				return 1;
			}					
		"sys/sys/test_db"->add_yuanbao(me,-2000); */
		notify("Đổi Màu Thành Công!");				
    return 1;
	}
	
        return 1;
}