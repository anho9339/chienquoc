
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
	
		if( !objectp( item = present("Kéo Cắt Tóc", me, 1, MAX_CARRY*4) ) )
        {
                write_user(me, ECHO "Bạn không có Kéo Cắt Tóc !");
                return 1;
        }	
	   if ( arg==0 )
	{
		result = sprintf("Bạn đang sử dụng Kéo Cắt Tóc, xin hãy lựa chọn : \n" );
		result += ESC HIY"Cắt Tóc...\ndoitoc doitoc2\n"; 
		result += ESC HIC"Đổi Khuôn Mặt...\ndoitoc doitoc3\n"; 
		result += ESC HIG"Đổi màu Tóc...\ndoitoc mautoc\n";  
	//	result += ESC "Hủy bỏ\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
	}
	   if ( arg=="doitoc2" )
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
		if ( me->get_save_2("doitoc.score")<2 )
		{
		result = sprintf("Bạn đang sử dụng Kéo Cắt Tóc, xin hãy lựa chọn kiểu Tóc :\n ( Cắt tóc miễn phí còn "HIB"%d"NOR " lần) \n", 2-me->get_save_2("doitoc.score") );
		result += ESC "Vô Môn Phái\ndoitoc vmp\n"; 
		result += ESC "Đào Hoa Nguyên\ndoitoc dhn\n"; 
		result += ESC "Thục Sơn\ndoitoc ts\n"; 
		result += ESC "Cấm Vệ Quân\ndoitoc cvq\n"; 
		result += ESC "Đường Môn\ndoitoc dm\n"; 
		result += ESC "Mao Sơn\ndoitoc ms\n"; 
		result += ESC "Côn Luân\ndoitoc cl\n"; 
		result += ESC "Vân Mộng Cốc\ndoitoc vmc\n"; 
	//	result += ESC "Hủy bỏ\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
		}
		else
		{
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
		result = sprintf("Bạn đang sử dụng Kéo Cắt Tóc, xin hãy lựa chọn kiểu Tóc :\n ( Lần này phải tiêu hao "HIB"5 "NOR "Kim Nguyên Bảo ) \n \nSố Kim Nguyên Bảo hiện tại của bạn là "HIB"%d "NOR ".\n", "sys/sys/test_db"->get_yuanbao(me)/10 );
		result += ESC "Vô Môn Phái\ndoitoc vmp2\n"; 
		result += ESC "Đào Hoa Nguyên\ndoitoc dhn2\n"; 
		result += ESC "Thục Sơn\ndoitoc ts2\n"; 
		result += ESC "Cấm Vệ Quân\ndoitoc cvq2\n"; 
		result += ESC "Đường Môn\ndoitoc dm2\n"; 
		result += ESC "Mao Sơn\ndoitoc ms2\n"; 
		result += ESC "Côn Luân\ndoitoc cl2\n"; 
		result += ESC "Vân Mộng Cốc\ndoitoc vmc2\n"; 
	//	result += ESC "Hủy bỏ\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
		}
		return 1;
	}
		if ( arg=="doitoc3" )
	{
			result = sprintf("Bạn đang sử dụng Kéo Cắt Tóc, xin hãy lựa chọn Khuôn Mặt :\n" );
		result += ESC "Khuôn mặt 1\ndoitoc 100\n"; 
		result += ESC "Khuôn mặt 2\ndoitoc 200\n"; 
		result += ESC "Khuôn mặt 3\ndoitoc 300\n"; 
		result += ESC "Khuôn mặt 4\ndoitoc 400\n"; 
		result += ESC "Khuôn mặt 5\ndoitoc 500\n";  
		send_user( me, "%c%s", ':', result);
                return 1;
	}
			if ( arg=="mautoc" )
	{
			result = sprintf("Bạn đang sử dụng Kéo Cắt Tóc, xin hãy lựa chọn màu Tóc : \n(Một lần đổi màu tóc cần tiêu hao 1.500.000 lượng)\n" );
		result += ESC "Xanh lá cây\ndoitoc 1\n"; 
		result += ESC "Đỏ\ndoitoc 2\n"; 
		result += ESC "Đen\ndoitoc 3\n"; 
		result += ESC "Xanh da trời\ndoitoc 4\n"; 
		result += ESC "Hồng\ndoitoc 5\n"; 
		result += ESC "Trắng\ndoitoc 6\n"; 
		result += ESC "Tím\ndoitoc 7\n"; 
		result += ESC "Vàng\ndoitoc 8\n"; 
		result += ESC "Olive\ndoitoc 9\n"; 
		//result += ESC "Tím đỏ\ndoitoc 10\n"; 
		//result += ESC "Tím đậm\ndoitoc 11\n"; 
		//result += ESC "Trà\ndoitoc 12\n"; 
		result += ESC "Cam\ndoitoc 13\n"; 
		//result += ESC "Phấn Hồng\ndoitoc 14\n"; 
		result += ESC "Hoàng Kim\ndoitoc 15\n"; 
		result += ESC "Hủy bỏ màu tóc\ndoitoc 16\n"; 
		send_user( me, "%c%s", ':', result);
                return 1;
	}
		if (arg=="vmp")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+1);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Vô Môn Phái thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="vmp2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+1);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Vô Môn Phái thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="dhn")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+2);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Đào Hoa Nguyên thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="dhn2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+2);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Đào Hoa Nguyên thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="ts")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+3);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Thục Sơn thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="ts2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+3);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Thục Sơn thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="cvq")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+4);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Cấm Vệ Quân thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="cvq2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+4);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Cấm Vệ Quân thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="dm")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+5);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Đường Môn thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="dm2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+5);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Đường Môn thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="ms")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+8);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Mao Sơn thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="ms2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+8);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Mao Sơn thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="cl")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+6);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Côn Luân thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="cl2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+6);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Côn Luân thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="vmc")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			
			if(me->get_save_2("doitoc.score")>=2)
			{	
				write_user(me, ECHO "Bạn đã cắt tóc Miễn phí đủ 2 lần rồi !");
				return 1;
			}
			me->set_hair(gender1+7);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Vân Mộng Cốc thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		if (arg=="vmc2")
	{
			if ( me->get_hair()==10 ) 
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1010 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
			else if ( me->get_hair()==1009 )
			{
			write_user(me, ECHO "Hãy ẩn tóc áo cưới trước khi cắt tóc !");
			return 1; 
			}
		/*	else if ( me->get_save_2("marry_fashion.type")==1 && gender == 1 )
			{
			write_user(me, ECHO "Không thể cắt tóc khi mặc Lễ Phục !");
			return 1; 
			}*/
			if("sys/sys/test_db"->get_yuanbao(me)<50)
			{	
				write_user(me, ECHO "Bạn không có đủ 5 Kim Nguyên Bảo !");
				return 1;
			}
			"sys/sys/test_db"->add_yuanbao(me,-50);
			me->set_hair(gender1+7);
			me->add_save_2("doitoc.score",1);
			write_user(me, ECHO "Bạn đã đổi tóc Vân Mộng Cốc thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
		
	if ( arg == "1")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x19830000);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "2")
	{
       if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x60c3);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "3")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x18c3);//0x0020
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "4")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x318c);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "5")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x6006);//0x3000
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "6")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x630c);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "7")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x30c6);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "8")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x6306);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "9")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x3183);//0x3180
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "10")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x600c);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "11")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x3006);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "12")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x0186);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "13")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x6180);//0x4100
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "14")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x4004);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "15")
	{
        if ( me->get_cash() < 1500000 )
		{
		write_user(me, ECHO"Ngân lượng của bạn không đủ 1.500.000");
		return 1;
		}
		me->add_cash(-1500000);
		me->set_hair_color(0x3003);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if ( arg == "16")
	{
		me->set_hair_color(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
    return 1;
	}
	if (arg=="100")
	{
			me->set_photo(gender1+1);
			write_user(me, ECHO "Bạn đã đổi Khuôn Mặt 1 thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
	if (arg=="200")
	{
			me->set_photo(gender1+2);
			write_user(me, ECHO "Bạn đã đổi Khuôn Mặt 2 thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
	if (arg=="300")
	{
			me->set_photo(gender1+3);
			write_user(me, ECHO "Bạn đã đổi Khuôn Mặt 3 thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
	if (arg=="400")
	{
			me->set_photo(gender1+4);
			write_user(me, ECHO "Bạn đã đổi Khuôn Mặt 4 thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
        	return 1;
    }
	if (arg=="500")
	{
			me->set_photo(gender1+5);
			write_user(me, ECHO "Bạn đã đổi Khuôn Mặt 5 thành công !");
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
			return 1;
    }
 
        return 1;
}