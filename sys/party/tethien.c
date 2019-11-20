/*******************************
	**Tế Thiên**
*******************************/
#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>
#include <skill.h>
inherit DBASE_F;
inherit SAVE_F;
#define DEBUG_STR(player,str) {tell_user(player,"str=%s",str);}

#define YUEBING	"item/event/tethien/thandon"//Thần Đơn Kim Bảo
#define YUEHUAN "item/event/tethien/tethienchihoan"//Tế THiên Chỉ hoàn
//#define YUTU	"npc/party/yutu1"
#define YUTU	"npc/event/thienmau" //Thiên Mẫu
int iStart,iFinish,iFinish_a,kkkk,close;
//object* nObjs= ({});//保存玩家的信息以便访问删除兔子的数量。
object change;
string *nWord = ({
	"Nhường tối viên Thiên Thư làm bạn ngươi cùng ta, nhường Thiên Thư nhắn dùm tâm nguyện của ta cùng chúc phúc. Chúc, Tế thiên khoái hoạt, trăng tròn người viên mọi chuyện viên.",

	"Nghe được ~ nghĩ đến ~ tâm đến, nói đến ~ làm được ~ được đến, đã đến giờ, vẻ đẹp của ta hảo chúc phúc cùng tưởng niệm đã muốn toàn bộ cho ngươi thu được.",

	"Lòng ở trên bàn phím, chờ ngươi đến nhẹ nhàng đánh. Bầu trời thiên, chờ người có tình đến trông chờ, Tế thiên ban đêm ta đem Thiên Thư cùng đốm nhỏ xếp thành đẹp nhất chúc phúc: Tế thiên khoái hoạt.",

	"Ta hơi giật mình nhìn lên Tế thiên ánh trăng, giống như nó là một mặt gương sáng, chúng ta ở cho nhau nhìn chăm chú kéo dài tư ý cùng chúc phúc.",

	"Ta đem của ngươi ID dãy số nói cho một cái người lạ, hắn gọi thiên lão, hắn sẽ tại Tế thiên đêm trăng tròn phải giúp ta cho ngươi biết, ta tưởng niệm ngươi.",

	"Phương xa bằng hữu ngươi là hay không không việc gì? Tại...này tưởng niệm mùa lý, thay đổi của ta dung nhan, không thay đổi vĩnh viễn vướng bận lòng của ngươi!",

	"Trăng khuyết khi ta nghĩ ngươi, trăng tròn khi ta niệm tình ngươi, vô luận trăng tròn trăng khuyết, lòng như kia hằng cổ không thay đổi ánh trăng yên lặng đuổi theo chúc phúc ngươi.",

	"Bánh Tế thiên lễ tới! Hư! Đừng lên tiếng! Đối với màn hình vui một chút! Tiếp tục vui một chút! Ha ha! Ta nhìn thấy! Tốt lắm! Nguyện ngươi khoái hoạt!",

	"Một luồng tình ý một viên đậu đỏ, trăng tròn thời gian ta sẽ cho Ngọc Thố đưa đi ta đặc chế ngọc Tế thiên! Tế thiên khoái hoạt!",

	"Trên biển sinh Thiên Thư, chân trời cùng lúc này.",

	"Chứng kiến kia ngọc xe Thiên Thư, liền nhớ lại phương xa ngươi; tắm rửa Nguyệt Huy ấm áp, liền cảm nhận được ngươi ôn nhu tươi cười. Thân ái, ta nghĩ ngươi. ",

	"Tế thiên ngày hội, rất xa ngươi ăn tròn tròn bính xem tròn tròn thiên muốn tròn tròn sự, chớ quên phương xa ta! ",

	"Thiên Thương thương, dã mờ mịt, có người trẻ ở phương xa. Thu Phong thổi, đạo mùi hoa. Tế thiên có không quay về cố hương? ",

	"Thiên Thư vốn vô giá, núi cao đều có chuyện. Nguyện sinh hoạt của ngươi tựa như này mười lăm ánh trăng giống nhau, mỹ mãn! Đưa lên hương vị ngọt ngào ngọc Tế thiên, tính cả một viên chúc phúc tâm",

	"Võng duyên! Tình duyên! Trăng tròn! Tế thiên chi dạ gửi tương tư, đoàn tụ sum vầy chuyện khó khăn viên. Mang đến ân cần thăm hỏi cùng tơ vương, tâm tưởng sự thành nguyện duyên viên.",

	"Tương tư là một loại nồng đậm rượu, cuối cùng nâng chén khi tản mát ra say lòng người thơm; nỗi nhớ quê là một phần thật dày tình hình thực tế, cuối cùng trăng tròn khi khẽ gọi lên khôn kể phiền muộn.",

	"Một tháng lượng một cái ngươi, hai bóng dáng ta và ngươi, tam sinh hữu hạnh nhận thức ngươi, bốn tháng đến rất nhớ ngươi, ngũ hồ tứ hải tìm kiếm ngươi, hoang mang lo sợ mê luyến ngươi, Thất Tinh bạn thiên quay chung quanh ngươi, tám tháng mười lăm ta chờ ngươi.",

	"Ngươi là ngọc Tế thiên ta là hãm, triền triền miên miên tổng gặp mặt; ngươi là diều ta là tuyến, truy truy đuổi trục đem ngươi khiên; ngươi là Thiên Thư ta là tuyền, Mỹ Mỹ tràn đầy một vạn năm!",

	"Mỗi phùng ngày hội lần tư thân, chúng ta cảm tình giống như hải thâm, trăng tròn lại là thiên minh thì dạy ta có thể nào không tư quân!",

	"Lưu Tinh xẹt qua phía chân trời, ta bỏ lỡ cầu nguyện; bọt sóng chụp thượng nham thạch, ta bỏ lỡ chúc phúc; chuyện xưa nói một lần, ta bỏ lỡ nghe; nhân sinh chỉ có một hồi, ta may mắn không có sai qua ngươi cái này hay hữu! Đêm nay mời ngươi cộng đồng ngắm trăng! ",

	"Rượu càng lâu càng thuần, bằng hữu giao nhau càng lâu càng thực; thủy càng lưu càng thanh, thế gian tang thương càng lưu càng đạm. Chúc trong bằng hữu thu ngày hội quả thật vui vẻ! ",

	"Năm trước trăng tròn thì hoa đăng lượng như ban ngày; trên ánh trăng ngọn liễu đầu, người ước chừng hoàng hôn sau. Năm nay trăng tròn thì thiên cùng đèn như trước; không thấy năm trước người, lệ thấp áo xuân tay áo.",

	"Tế thiên tương tư, ý nồng đậm; hai mắt đẫm lệ thiên hạ, mộng trong ngực; thiên là cố hương minh, người là ngươi tốt nhất.",

	"Gió mát đưa đi lời chúc phúc của ta, Thiên Thư mang đến ta ân cần thăm hỏi, Lưu Tinh ghi lại ngày xưa chuyện xưa, Ngọc Thố để lại vĩnh hằng Cát Tường. Chúc ngươi Tế thiên ngày hội khoái hoạt, trăng tròn người viên mọi chuyện viên mãn!",

	"Người cách ngàn dậm, lộ từ từ, lại cần hỏi, cuối cùng không có bằng chứng, thỉnh Thiên Thư thay mặt triệu đến, gửi ta chữ phiến giấy trẻ an ủi cách chuyện.",

	"Lộ theo tối nay trắng, thiên là cố hương minh. Tối nay thiên đang viên, đúng là nhớ nhà. Cùng mong nhô lên cao thiên, trăng tròn mộng chưa viên.",
	
	});
void get_chang();
void destruct_chang();
void generate_yutu();
void destroy_yutu();
void destroy_yuebing();
void generate_yuebing();
void yuetu_bonus(object player,object npc);
void update_record(object player);
void check_time2();
void paihangbang(object player,object npc);
void paihangbang_bonus(int vip,int potential,int cash,object player,object npc);
int check_yuebing(object who, int count,string name);
int give_yuebing(object who,string name, int count);
int exchange( object player,object npc);
int get_close();
// 函数：生成二进制码
void SAVE_BINARY() { }
string get_save_file()	{ return "data/tethien"SAVE_EXTENSION;}
void create()
{	
	restore();
	iStart = mktime(2015,4,1,8,0,0); // Năm, tháng, ngày , giờ	
   	iFinish = mktime(2015,9,26,22,0,0);
	iFinish_a = mktime(2015,10,3,22,0,0);
	call_out("check_time",1);
}

void check_time()
{
	int iTime;
	mixed* mixTime;

	iTime = get_party_time();
	remove_call_out("check_time");
	
	if(iTime < iStart)
	{
		call_out("check_time",iStart - iTime);
		return;
	}
	if ( iTime > iFinish_a )
	{
		destroy_yuebing();
		destroy_yutu();	
		destruct_chang();
		return;
	}
	if(iTime > iFinish)
	{
		destroy_yuebing();
		destroy_yutu();	
		get_chang();
		call_out("destruct_chang",iFinish_a - iTime);
		return;
	}
	mixTime = localtime(iTime);
	if(mixTime[TIME_HOUR] >= 22) // 22h kết thúc
	{
		destroy_yuebing();//在活动结束以后直接将玉兔和Thần Đơn Kim Bảo从场景里面清除。
		destroy_yutu();	
		call_out("check_time",3600*24 - mixTime[TIME_HOUR]*3600 - mixTime[TIME_MIN]*60);
		return;
	}

	if ( mixTime[TIME_HOUR] < 8 ) //  8h bắt đầu
	{
		call_out("check_time",3600*8-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
		return ;
	}
	check_time2();
}


void check_time2()
{
	int iTime;
	mixed *mixTime;
//	iTime = time();
	iTime = get_party_time();
	mixTime = localtime(iTime);
	get_chang();
	CHAT_D->sys_channel(0,"Chúc các vị một ngày vui vẻ！Ở Chiến quốc pro hôm nay ta lại đc đón lễ tế thiên bên cạnh các chiến hữu của mình，đặc biệt sẽ có nhiều hoạt động sắp tới。Bây giờ hãy nhanh tới"HIR"Chu quốc"NOR"tìm sử giả của thiên đình là——"HIR" Thiên Mẫu"NOR" tham dự hoạt động，nàng đang ở gần thần tiên gia gia。");
	CHAT_D->sys_channel(0,"Chúc các vị một ngày vui vẻ！Ở Chiến quốc pro hôm nay ta lại đc đón lễ tế thiên bên cạnh các chiến hữu của mình，đặc biệt sẽ có nhiều hoạt động sắp tới。Bây giờ hãy nhanh tới"HIR"Chu quốc"NOR"tìm sử giả của thiên đình là——"HIR" Thiên Mẫu"NOR" tham dự hoạt động，nàng đang ở gần thần tiên gia gia。");
	log_file( "tethien.dat", sprintf( "%d tháng %d ngày %d ：%d ngày bắt đầu hoạt động Tế Thiên.\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
	if (mixTime[TIME_MIN]<30) 
	{
		kkkk=-1;
		generate_yutu();		
		log_file( "tethien.dat", sprintf( "%d tháng %d ngày %d ：%d thả rồng thiêng。\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		call_out("check_time3",60*(30-mixTime[TIME_MIN]));
	}
	else
	{
		kkkk=1;
		generate_yuebing();
//		CHAT_D->sys_channel(0,HIR"Nghe nói thất quốc bên ngoài đều là Thần Đơn Kim Bảo，ko biết có phải thật ko，mọi người nhanh đi lấy đi！");
		CHAT_D->rumor_channel( 0, CHAT+HIR"Nghe nói bát quốc bên ngoài đều là Thần Đơn Kim Bảo，ko biết có phải thật ko，mọi người nhanh đi lấy đi！" );  
		log_file( "tethien.dat", sprintf( "%d tháng %d ngày %d ：%d thả Thần Đơn Kim Bảo。\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		call_out("check_time3",60*(60-mixTime[TIME_MIN]));
	}
}

void check_time3()
{
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time3");
//	iTime = time();
	iTime = get_party_time();	
	mixTime = localtime(iTime);
	if (get_close()) return;
	if ( iTime > iFinish_a )
	{
		destroy_yuebing();
		destroy_yutu();	
		destruct_chang();
		return;
	}
	if ( iTime > iFinish )
	{
		destroy_yuebing();
		destroy_yutu();	
		USER_D->user_channel("Hỡi anh em trong chiến quốc pro，hoạt động tế thiên sẽ triển khai trong 3 ngày，trong khoảng thời gian ấy đã làm cho nó nhiệt liệt hơn bao giờ hết，cảm ơn mọi người。Hoạt động lần này kết thúc mĩ mãn，mời các anh em hãy tới  Thiên Mẫu nhận thưởng，thời gian nhận 10 tháng 3 ngày 22：00 giờ。");
		log_file( "tethien.dat", sprintf( "%d tháng %d ngày %d ：%d hoạt động tế thiên kết thúc。\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		call_out("destruct_chang",iFinish_a - iTime);
		return;
	}
	if(mixTime[TIME_HOUR] >= 22)
	{
		destroy_yuebing();//在活动结束以后直接将玉兔和Thần Đơn Kim Bảo从场景里面清除。
		destroy_yutu();	
		USER_D->user_channel("Hôm nay hoạt động tế thiên sẽ kết thúc，ngày mai cũng vào lúc đó hãy trở lại tham gia nha，chúc mọi người vui vẻ。");
		call_out("check_time3",3600*24 - mixTime[TIME_HOUR]*3600 - mixTime[TIME_MIN]*60);
		log_file( "tethien.dat", sprintf( "%d tháng %d ngày %d ：%d hoạt động kết thúc vào ngày đó。\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
		return;
	}

	if ( mixTime[TIME_HOUR] < 8 )
	{
		call_out("check_time3",3600*8-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
		return ;
	}
	if ( mixTime[TIME_HOUR] == 8 && mixTime[TIME_MIN] < 30 )
		CHAT_D->sys_channel(0,"Chúc các vị một ngày vui vẻ！Ở Chiến quốc pro hôm nay ta lại đc đón lễ tế thiên bên cạnh các chiến hữu của mình，đặc biệt sẽ có nhiều hoạt động sắp tới。Bây giờ hãy nhanh tới"HIR"Chu quốc"NOR"tìm sử giả của tế thiên là——"HIR" Thiên Mẫu"NOR" tham dự hoạt động，nàng đang ở gần thần tiên gia gia。");
	else
		CHAT_D->sys_channel(0,"CQ Pro tuyên bố hoạt động tế thiên bắt đầu tiến hành，muốn tham gia hãy đi tới——"HIR" Thiên Mẫu"NOR"nhé，nàng ở "HIR"Chu quốc"NOR" gần thần tiên gia gia。");
	if ( kkkk == 1 )
	{
		generate_yutu();
		log_file( "tethien.dat", sprintf( "%d tháng %d ngày %d ：%d thả rồng thiêng。\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
	}
	if ( kkkk == -1 )
	{
		generate_yuebing();
		CHAT_D->rumor_channel( 0, CHAT+HIR"Nghe nói bát quốc bên ngoài toàn là Thần Đơn Kim Bảo，ko biết có thật ko，hãy đi xem thử！" );  
//		CHAT_D->sys_channel(0,HIR"Nghe nói thất quốc bên ngoài toàn là Thần Đơn Kim Bảo，không biết có phải hay không，mọi người nhanh đi nào！");
		log_file( "tethien.dat", sprintf( "%d tháng %d ngày %d ：%d thả Thần Đơn Kim Bảo。\n",mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
	}
	kkkk=-kkkk;
	call_out("check_time3",1800);
}

// 放入嫦娥
void get_chang()
{
	if ( !objectp(change) )
	{
		change = new("npc/event/thienmau");
		change->add_to_scene(80,286,178,4);
	}
}

// 移除嫦娥
void destruct_chang()
{
	if ( objectp(change) )
	{
		change->remove_from_scene();
		destruct(change);
	}
}

void generate_yutu()
{
	int i,z,p,x,y;
	object *nObj,npc;
	destroy_yutu();
	nObj = ({});	
	for(z=10;z<=80;z+=10)
	{
		for(i=0;i<20;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
		//	npc = new("npc/party/yutu1");
		    npc = new("npc/event/rongthieng");
			if ( !objectp(npc) )
				continue;
			npc->add_to_scene(z,x,y);	
			nObj += ({ npc });	
		}
	}
	YUTU->set("npc",nObj);
}

void destroy_yutu()
{
	int i,size;
	object *nObj;
	nObj = 	YUTU->get("npc");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i])	)
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("npc");
}
void generate_yuebing()
{
	int i,z,p,x,y;
	object *nObj,item;	
	destroy_yuebing();
	nObj = ({});
	for(z=10;z<=80;z+=10)
	{
		for(i=0;i<30;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(YUEBING);
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
			nObj += ({ item });
		}
	}
	YUTU->set("item",nObj);
}

void destroy_yuebing()
{
	int i,size;
	object *nObj;	
	nObj = YUTU->get("item");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i]) )
			continue;
		if ( get_d(nObj[i]) )
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("item");
}
//设置中秋节活动的开启
int set_open(object who,string arg)
{
	int year,mon,day,hour,min;
	string cTmp1,cTmp2;
	if ( sscanf(arg ,"%s-%s",cTmp1,cTmp2) != 2 )
	{
		send_user(who,"%c%s",'!',"Cách thức sai！");	
		return 0;
	}
	year = to_int(cTmp1[0..3]);
	mon = to_int(cTmp1[4..5]);
	day = to_int(cTmp1[6..7]);
	hour = to_int(cTmp1[8..9]);
	min = to_int(cTmp1[10..11]);
	iStart = mktime(year,mon,day,hour,min,0);	//活动开始时间

	year = to_int(cTmp2[0..3]);
	mon = to_int(cTmp2[4..5]);
	day = to_int(cTmp2[6..7]);
	hour = to_int(cTmp2[8..9]);
	min = to_int(cTmp2[10..11]);
	iFinish = mktime(year,mon,day,hour,min,0);	//结束时间

	if ( !iStart || !iFinish )
	{
		send_user(who,"%c%s",'!',"Sai thời gian！");	
		return 0;
	}
	if ( iStart > iFinish || iFinish < time() )
	{
		send_user(who,"%c%s",'!',"Sai thời gian！！");	
		return 0;
	}
	tell_user(who,"Hoạt động Tế thiên mở ra：%s！",arg);	
	send_user(who,"%c%s",'!',"Hoạt động Tế thiên mở ra！");	
	save();
	call_out("check_time",3);
	return 1;
}
//设置中秋节活动的关闭
/*int set_close(object who)
{
	remove_call_out("check_time");
	iStart = 0;	
	iFinish = 0;		
	send_user(who,"%c%s",'!',"Hoạt động Tế thiên đóng！");	
	save();
	return 1;	
}*/
//获取中秋节活动状态。
/*int is_open()
{
	mixed* mixTime;
	int iHour,iDay,iTime;
	mixTime = localtime(get_party_time());
	iHour = mixTime[TIME_HOUR];
   	iDay = mixTime[TIME_MDAY];
   	iTime = get_party_time();
	if(!iStart || !iFinish)//设置活动开始和结束时间无效。
	{
		return 0;
	}
	if(iTime < iStart || iTime > iFinish)//还没有到时间以及已经活动过期。
	{
		return 0;
	}
	if(iDay == 20 || iDay == 21 || iDay == 22 || iDay == 23 || iDay == 24 || iDay == 25 || iDay == 26)//9月24 25 26 18:00-21:00
	{
		if(iHour == 18)
		{
			return 1;
		}
	}
	return 0;	
}*/
void do_look(object npc,object player)
{
	int index;
	string dailogue = "";
	string* choices1 = ({"Rồng Thiêng trở lại","Bảng anh hùng bắt rồng thiêng","Đổi Thần Đơn Kim Bảo","Xem thêm về hoạt động tế thiên","Xem về thời gian hoạt động",});
	string* choices2 = ({"Đổi Thần Đơn Kim Bảo","Rồng Thiêng trở lại","Bảng anh hùng bắt rồng thiêng","Nhận phần thưởng anh hùng bắt rồng thiêng",});
	int iTime;
	mixed *mixTime;
	iTime = get_party_time();
	mixTime = localtime(iTime);
	if( iTime < iFinish )
//	if(is_open())
	{
		dailogue += "    Tế thiên vui vẻ！Hôm nay là lễ tế thiên ta mang theo rồng thiêng từ thiên cung xuống chiến quốc pro ăn mừng lễ naỳ，nhưng bọn nó đi đâu rùi đó，ko nghe lời ta hjx hjx！Ai，có thể bắt nó về，thì ta sẽ thưởng cho hậu hĩnh。Liệu ngươi có thể ko？\n";
		for(index = 0; index < 5;index++)
		{
			dailogue+=sprintf(ESC"%s\ntalk %x# welcome.%d\n",choices1[index],getoid(npc),index+2);
		}
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+dailogue+ESC"Lượn đi\n");
	}	
	else
	{
		dailogue += "    Chúc lễ tế thiên vui vẻ tại Chiến Quốc Pro. Ngươi cần ta giúp một tay sao？\n";
		for(index = 0; index < 4; index++)
		{
			dailogue+=sprintf(ESC"%s\ntalk %x# welcome.%d\n",choices2[index],getoid(npc),index+7);
		}
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+dailogue+ESC"Lượn đi\n");	
	}	
}
void do_welcome( object npc, string arg )
{
	int flag,i,size,index,move,pos,record,index2,name_size;
	int id = getoid(npc);
       	object who,item,player,obj;  
       	string name,cTmp,id1,tmp="",cmd="",playername; 
        player = this_player();
        if ( sscanf(arg,"%d.%s",flag,id1) != 2 )//这里主要处理输入ID祝福的信息。
	{
        	flag = to_int(arg);
        }
        if(!flag)
        {
        	return;
        }
//        player->set_2("rabbit.day",localtime(get_party_time())[TIME_MDAY]);//记录与嫦娥交互的时间。	
        switch(flag)
        {
        case 1://乐意帮忙，我想知道月兔在哪里
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Ở chu quốc、tề quốc、hàn quốc、triệu quốc、ngụy quốc、tần quốc、sở quốc sẽ xuất hiện rồng thiêng ，hãy sử dụng dây càn khôn để bắt rồng thiêng lại cho ta，sẽ đc trọng thưởng。Ta sẽ mệt mỏi khi ngươi bắt đủ số lượng đây hjx，nhưng khi bắt đủ，tên ngươi sẽ có mặt ở bảng xếp hạng bắt rồng thiêng，như vậy sẽ đc tế thiên lễ bao，haha。\n"+ESC"Xác nhận\n");
        	break;
        case 2://交还月兔，排行
		if( get_party_time() > iFinish ) return ;
		if ( check_yuebing(player,1,"Rồng Thiêng") != 1 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Xin lỗi，dường như ngươi không bắt đc rồng thiêng 。\n"+ESC"Xác nhận\n");
			return ;
		}
		player->add_save("tuzi",1);
		yuetu_bonus(player,npc);//给玉兔奖励。
		update_record(player);//这里更新兔子数量记录以及排行榜。
		break;
        case 3://抓兔英雄榜,
		paihangbang(player,npc);
        	break;
        case 4://Thần Đơn Kim Bảo兑换(前)
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Lễ tế thiên đã có từ lâu。Nơi đây rất đặc biệt trong ngày lễ，ngươi có muốn thứ gì ko？Ngươi có nhiều thứ muốn đổi sao？ Chỉ có thể đổi Thần Đơn Kim Bảo tại đây thôi！Tỷ tỷ sẽ giúp ngươi thực hiện nguyện vọng tìm đồ！！！\n"ESC"Giao ra 5 Thần Đơn để đổi quà\ntalk %x# welcome.13\n"ESC"Giao ra 2 Thần Đơn để gửi lời nhắn yêu thương\ntalk %x# welcome.14\n"ESC"Lượn đi",npc->get_name(),id,id,));  	
        	break;
        case 7://Thần Đơn Kim Bảo兑换(后)
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Thời gian đổi Thần Đơn Kim Bảo đã hết，bất qua ta sẽ cho ngươi đổi tí lễ vật mọn！\n"ESC"Đổi 1 cái ngọc lấy lễ vật thần bí\ntalk %x# welcome.13\n"ESC"Lượn đi",npc->get_name(),id,id));  	
        	break;
        case 5://询问中秋活动规则
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Ở chu quốc、tề quốc、hàn quốc、triệu quốc、ngụy quốc、tần quốc、sở quốc sẽ xuất hiện rồng thiêng，hãy sử dụng dây càn khôn để bắt rồng thiêng lại cho ta，sẽ đc trọng thưởng。Ta sẽ mệt mỏi khi ngươi bắt đủ số lượng đây hjx，nhưng khi bắt đủ，tên ngươi sẽ có mặt ở bảng xếp hạng bắt rồng thiêng，như vậy sẽ đc tế thiên lễ bao，haha！\n"ESC"Xác nhận\n",npc->get_name()));  	
        	break;	 
        case 6://询问活动时间
        	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Thời gian hoạt động là ngày 24 tháng 9 đến 26 ngày tháng 9，vào lúc 18：00 đến 22：00 tối！\n"ESC"Xác nhận",npc->get_name()));
		break;
	case 8:
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Hoạt động thời gian đã qua , trả lại rồng thiêng chỉ có thể đạt được thưởng nhỏ, sẽ không ghi vào bắt rồng thiêng anh hùng bảng đâu ！ Ngươi xác nhận muốn trả lại rồng thiêng sao？\n"+sprintf(ESC"Xác nhận\ntalk %x# welcome.12\n",getoid(npc))+ESC"Lượn đi\n");
		break;
        case 12://交还月兔，不排行
		if ( check_yuebing(player,1,"Rồng Thiêng") != 1 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Xin lỗi，thứ ngươi bắt không phải rồng thiêng 。\n"+ESC"Xác nhận\n");
			return ;
		}
		yuetu_bonus(player,npc);//给玉兔奖励。
		break;
        case 13://交出1个Thần Đơn Kim Bảo兑换节日礼物
        	if(check_yuebing(player,5,"Thần Đơn Kim Bảo") == 0   )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Ngươi đến đây làm gì，Thần Đơn Kim Bảo của ngươi đâu，nhanh đi tìm rồi hãy tới đây，hừ hừ！\n"ESC"Xác nhận",npc->get_name()));
			return ;	
		}
        	//给予Thần Đơn Kim Bảo兑换的奖励。
        	exchange(player,npc);
        	break;
        case 14: 
        	if ( check_yuebing(player,2,"Thần Đơn Kim Bảo") == 0 ) //2 thần đơn để nhắn
        	{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Ngươi đến đây làm gì，Thần Đơn Kim Bảo của ngươi đâu，nhanh đi tìm rồi hãy tới đây，hừ hừ！\n"ESC"Xác nhận",npc->get_name()));
			return ;        			
        	}
		send_user( player, "%c%c%d%s", '?', 16, 30, "Mời nhập số ID của bằng hữu mình，ta có thể gửi lời chúc của ngươi tới người đó。Nếu như nhập số 0，ta sẽ gửi lời chúc của ngươi tới tất cả mọi người：\n"+sprintf( ESC"talk %x# welcome.15",getoid(npc))+".%s\n");
        	break;
        case 15://处理温馨的祝福。
        	if ( !sizeof(id1) )
        		return ;
        	cTmp = nWord[random(sizeof(nWord))];
        	if ( id1 == "0" )
        		name = "Mọi người";
		else
		{        
			i = to_int(id1);
			if ( !i )
				return ;	
        		obj = find_char(id1);
       			if ( !objectp(obj) )
			{
        			if( !( player->get_friend_id(i) ) )//玩家不在线并且不在好友列表，不发送祝福.
        			{
//					name = "Mọi người";
					send_user(player,"%c%s",'!',"Thật xin lỗi，người chơi không tồn tại");
					return ;
				}
				else
				{
					name = player->get_friend_name(i);
//					MAILBOX->send_mail(player,i,cTmp);
//					MAILBOX->sys_mail(obj->get_id(),obj->get_number(),cTmp);
				}				
			}
			else
				name = obj->get_name();
			if(name == player->get_name())
			{
				send_user(player,"%c%s",'!',"Ngươi không thể tự gửi chúc phúc！");
				return;
			}						
		}
		if ( give_yuebing(player,"Thần Đơn Kim Bảo",5) == 0 )  //5 Thần đơn 1 lần nói
        	{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Xin lỗi，Thần Đơn Kim Bảo của bạn chưa đủ，hãy đi thu thập đi nào！\n"ESC"Xác nhận",npc->get_name()));
			return ;        			
        	}
        	cTmp = sprintf(HIY"%s"HIR" nhìn "HIY"%s"HIR" nói：%s",player->get_name(),name,cTmp); 		
		if (objectp(obj)) MAILBOX->sys_mail(obj->get_id(),obj->get_number(),cTmp);
        	CHAT_D->sys_channel(0,HIR+cTmp);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
        	break;
	case 9://抓兔英雄榜,
		paihangbang(player,npc);
		break;
	case 10://领取排行榜的奖励
		if(get_save_2(sprintf("player.%d.bonus",player->get_number())))
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Ngươi đã nhận phần thưởng，không thể nhận thêm！\n"+ESC"Xác nhận\n");
			return;
		}
		pos = get_save_2(sprintf("player.%d.pos",player->get_number()));//在排行榜的位置。				
		if ( pos<1 || pos > 10 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Xin lỗi，tên của ngươi không ở trên bảng xếp hạng bắt rồng thiêng！\n"+ESC"Xác nhận\n");
			return ;	
		}
//		if(player->get_2("rabbit.day")== localtime(get_party_time())[TIME_MDAY])
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    AA，Ngươi thật lợi hại，đây là phần thưởng của ngươi，hãy nhận đi！\n"+sprintf(ESC"Nhận phần thưởng。\ntalk %x# welcome.16\n",getoid(npc)),npc->get_name()));
		}
		break;
	case 16:
		if(get_save_2(sprintf("player.%d.bonus",player->get_number())))
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Ngươi đã nhận phần thưởng，không thể nhận thêm。\n"+ESC"Xác nhận\n");
			return;
		}	
		pos = get_save_2(sprintf("player.%d.pos",player->get_number()));//在排行榜的位置。
		if ( pos<1 || pos > 10 )
		{
			send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Xin lỗi，tên của ngươi không ở trên bảng xếp hạng bắt rồng thiêng！\n"+ESC"Xác nhận\n");
			return ;	
		}
		switch(pos)
		{
		case 1:
			paihangbang_bonus(1,1000,100000,player,npc);
			break;
		case 2:
			paihangbang_bonus(1,900,90000,player,npc);
			break;
		case 3:
			paihangbang_bonus(1,800,80000,player,npc);
			break;
		case 4:
			paihangbang_bonus(0,700,70000,player,npc);
			break;
		case 5:
			paihangbang_bonus(0,600,60000,player,npc);
			break;
		case 6:
			paihangbang_bonus(0,500,50000,player,npc);
			break;
		case 7:
			paihangbang_bonus(0,400,40000,player,npc);
			break;
		case 8:
			paihangbang_bonus(0,300,30000,player,npc);
			break;
		case 9:
			paihangbang_bonus(0,200,20000,player,npc);
			break;	
		default:
			paihangbang_bonus(0,100,10000,player,npc);	
		}
		break;
        }      
}
//物品奖励
void move_to_user(object player, int amount_s, string name,object npc)
{
	int p,total,amount;
	object item;
	string name_s;
	item = new(name);
	if (item)
	{
		name_s=item->get_name();
		if( item->get_max_combined()>1 )
		{
			total = amount_s;
			amount = USER_INVENTORY_D->carry_combined_item(player, item, total);
		        if( amount > 0 && item->set_amount(amount) )
		        {
		                if( p = item->move(player, -1) )
		                {
		                        item->add_to_user(p);
		                }
		        }
		        else
		        {
		        	item->add_amount( -total );
		        }
		}
		else
		{
			if( p = item->move(player, -1) )
		        {
		                item->add_to_user(p);
		        }
		}
	//	USER_D->user_channel("Chúc mừng "+player->get_name()+" vào lễ tế thiên nhận được "+HIR+name_s+"。\n");
	}
}
//给予排行榜的奖励
void paihangbang_bonus(int vip,int potential,int cash,object player,object npc)
{
	int flag = 0,iVipTime,iVip;
	int id = player->get_number();
	mixed* mixTime;

	if(sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY )
	{
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n	Xin lỗi，muốn đạt được phần thưởng，hãy dọn dẹp túi đồ。Nếu exp cùng tiềm năng đạt giới hạn，hãy chuyển sinh rùi tới đây。"+ESC"Xác nhận\n");
		return;
	}
	move_to_user(player,1,YUEHUAN,npc);
	if(vip)//给出VIP效果到玩家身上。
	{
		iVip = player->get_vip();
		if ( iVip != 0 && iVip != 1 )
			return 0;
		iVipTime = player->get_save_2("vip_package.time");
		if ( iVipTime == 0 )
			iVipTime = time()+3600*24*31;
		else 
			iVipTime += 3600*24*31;
		if ( iVip == 0 )
			player->delete_save_2("vip_package");
		player->delete_save_2("vip_package.trial");	//试用VIP包
		player->set_vip(1);
		player->add_save_2("vip_package.doubles",40);
		player->set_save_2("vip_package.time",iVipTime);
		player->add_title("V001");
		send_user( player, "%c%w%w%c", 0x81, 7401, 999, EFFECT_GOOD );
		USER_ENERGY_D->count_cp(player);
		USER_ENERGY_D->count_pp(player);
		USER_ENERGY_D->count_ap(player);
		USER_ENERGY_D->count_dp(player);
		mixTime = localtime(iVipTime);
		send_user(player,"%c%s",';',sprintf("Ngươi nhận đc gói VIP，ngày hết hạn VIP là %d-%02d-%02d %02d:%02d:%02d。Hiệu quả VIP sẽ hết hiệu nghiệm khi thời gian kết thúc。Có thể tìm thần tiên gia gia để gia hạn thêm。",mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]));
		send_user( player, "%c%w%s", 0x82, 7401, "item/sell/0061"->get_loop_desc(player));
		send_user( player, "%c%c%c", 0xA2, 4, 1);
		send_user( player, "%c%c%c", 0xA2, 3, 3-player->get_save_2("vip_package.revive.count"));
		"item/sell/0061"->send_vip_to_friend(player,1);
		USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên nhận được "+HIR+" túi VIP "+"。\n");
	}
	player->add_potential(potential);//潜能
	player->add_cash(cash);//金钱	
	set_save_2(sprintf("player.%d.bonus",id),1);
	save();
}
void paihangbang(object player,object npc)
{
	int index,pos,name_size,id;  
       	string tmp="",cmd="",playername,blank="";
       	blank = repeat_string(" ",12); 

	for(index = 1; index<=5;index++)
	{
		id = get_save_2(sprintf("record.%d",index));//找到index位置所对应的id.
		if(!id)
		{
			tmp = sprintf(" ""%2d．%12s%4s%4s",index,blank,"：\t","Chỗ trống");
			tmp+="\t\t";
			tmp += sprintf(" ""%2d．%12s%4s%4s",index+5,blank,"：\t","Chỗ trống");
			tmp+="\n";
		}
		else
		{
			playername = get_save_2(sprintf("player.%d.name",id));
			name_size = strlen(playername);
			if(name_size<=12)
			{
				playername+= repeat_string(" ",12-name_size);
			}
			switch(index)
			{
			case 1:
				tmp = sprintf(" ""R""%2d．%12s%4s%4d"NOR,1,playername,"：\t",get_save_2(sprintf("player.%d.count",id)));
					//tmp+="      ";
				break;
			case 2:
				tmp = sprintf(" ""M""%2d．%12s%4s%4d"NOR,2,playername,"：\t",get_save_2(sprintf("player.%d.count",id)));
					//tmp+="  ";
				break;
			case 3:
				tmp = sprintf(" ""B""%2d．%12s%4s%4d"NOR,3,playername,"：\t",get_save_2(sprintf("player.%d.count",id)));
					//tmp+="   ";
				break;
			case 4:
				tmp = sprintf(" ""%2d．%12s%4s%4d",4,playername,"：\t",get_save_2(sprintf("player.%d.count",id)));	//+BLK+BLK
					//tmp+="       ";
				break;		
			case 5:
				tmp = sprintf(" ""%2d．%12s%4s%4d",5,playername,"：\t",get_save_2(sprintf("player.%d.count",id)));	//+BLK+BLK
				break;							
			}	
			tmp+="\t\t";
			id = get_save_2(sprintf("record.%d",index+5));
			if(!id)
			{
				tmp += sprintf(" ""%2d．%12s%4s%4s",index+5,blank,"：\t","Chỗ trống");
			}
			else
			{
				playername = get_save_2(sprintf("player.%d.name",id));
				name_size = strlen(playername);
				if(name_size<=12)
				{
					playername+= repeat_string(" ",12-name_size);
				}
				tmp += sprintf(" ""%2d．%8s%4s%4d",index+5,playername,"：\t",get_save_2(sprintf("player.%d.count",id)));
//				tmp += sprintf(" ""%2d．%8s%4s%4d",index+5,get_save_2(sprintf("player.%d.name",id)),"：\t",get_save_2(sprintf("player.%d.count",id)));//+BLK+BLK
			}		
			tmp+="\n";
		}
		cmd+=tmp;
		
	}
//	log_file("zhongqiu.txt",short_time() + "\n"+cmd );
       	send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf("Bảng xếp hạng anh hùng bắt rồng thiêng（Số rồng thiêng đã nộp của ngươi là %d con） \n",player->get_save("tuzi"))+cmd
		+ESC "Xác nhận\n");
}
int exchange( object player,object npc) 
{
	int rand,p,cash,exp,pot;
	if(sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY )
	{
		send_user(player,"%c%s",'!',"Trên người ngươi không đủ chỗ trống，ko thể nhận phần thưởng，lần sau đổi thưởng hãy chú ý nha。");
		return;
	}
	// Quà Đổi thần đơn
	if ( give_yuebing(player,"Thần Đơn Kim Bảo",5) == 0 ) //5 thần đơn 1 lần đổi
        {
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Xin lỗi，Thần Đơn Kim Bảo của bạn chưa đủ，hãy đi thu thập đi nào！\n"ESC"Xác nhận",npc->get_name()));
		return ;        			
        }
	rand = random(10000);
	if(rand < 2000)
	{
			player->add_cash(10000);//活络丸。
	}
	else if(rand < 4000)
	{
			player->add_potential(1234);//安神丸。
	}
	else if(rand < 5500)
	{
			player->add_cash(15000);//造化丹。	
	}
	else if(rand < 7000)
	{
		move_to_user(player, 1, "item/test2/TuiPhapBao",npc);//补心丹。		
	}
	else if(rand < 8000)
	{
	    move_to_user(player, 1, "item/test2/TuiQuaVoSong",npc);	
	}
	else if(rand < 8500)
	{
		move_to_user(player, 1, "item/bikipknb/knb2",npc);//救急丹。	
	}
	else if(rand < 9000)
	{
		move_to_user(player, 1, "item/bikipknb/knb1",npc);//活心丹。
	}
	else if(rand < 9450)
	{
		player->add_cash(20000);  
	//	USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR" 20000 nl"+"。\n");
	}
	else if(rand < 9850)
	{
		move_to_user(player,1,"item/44/4488",npc);//随机 宠物技能丹
	}
	else if(rand < 9880)
	{
		move_to_user(player,1,"item/event/tethien/tethienchihoan",npc);//Pháp bảo
		USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR" Tế Thiên Chỉ Hoàn"+"\n");
	}
	else if(rand < 9990)
	{
		move_to_user(player,1,"item/sell/0032",npc); // Rồng Thiêng
		USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR" Đoạn Thạch Sơ Cấp"+"\n");
	}
	else
	{
		move_to_user(player,1,YUEHUAN,npc);//月环
	}
	send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n    Chúc ngươi một mùa Tế thiên vui vẻ，lễ vật ta đã đưa cho ngươi，hãy kiểm tra lại！\n",npc->get_name()));
}
//检查玩家道具栏上面是否有count个name。是的话，就返回1，否则返回0。
int check_yuebing(object who, int count,string name)
{
	int i,size,amount;
	object *inv,item;	
	inv = all_inventory(who, 1, MAX_CARRY*4);
	if(!inv)
	{
		return 0;
	}
	if( !(objectp( item = present(name, who, 1, MAX_CARRY*4) )) || (item->is_zhongqiu() != 1) )
	{		
		return 0;	
	}		
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1 )
			continue;
		if ( inv[i]->is_combined() )//如果可以叠加的话，那么就增加叠加的数量。
			amount += inv[i]->get_amount();		
		else
			amount ++;
	}
	if ( amount < count )
	{
		return 0;	
	}
	return 1;
}
//如果玩家身上有足够的count个数目，那么就遍历道具栏进行扣除。
int give_yuebing(object who, string name,int count)
{
	int i,size,amount;
	object *inv,item;	
	if ( check_yuebing(who,count,name) != 1 )
		return 0;
	inv = all_inventory(who, 1, MAX_CARRY*4);
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1 )//
			continue;
		amount = inv[i]->get_amount();
		if ( count >= amount )
		{
			count -= amount;//这里做个修正。如果玩家给的数量超过实际道具栏上对应物品数量的话。
			inv[i]->remove_from_user();//这里将玩家道具栏上的对应物品清光。
			destruct(inv[i]);			
		}
		else//否则减去相应数目。
		{
			inv[i]->add_amount(-count);
			count = 0;	
		}
		if ( count <= 0 )
			break;
	}
	return 1;		
	
}

//在交还月兔的时候，更新月兔的数量记录排行榜。
void update_record(object player)
{
	/*
	首先获得玩家的id信息，如果有的话，
	那么就找他的id对应的月兔数量记录，并且累加1
	如果排行榜名单个数小于10的话，那么就将这个新来的添加到排行榜上面，
	要记住这个玩家的id,玩家的position,以及这个排行榜的大小。
	如果排行榜名单个数大于10的话，那么就进行比较，找出排行榜上面月兔数量比自己少的，
	这样的话，就将那个比自己少的删除掉，并且将自己加入到排行榜上面。
	最后进行全部数据的排序。
	*/
	int size,index,pos,oldid,id1,amount,i;
	int id = player->get_number();
	string name = player->get_name();
//	amount = YUTU->get_2(sprintf("player.%d.rabbit",id));//增加该玩家的排行榜兔子数量。
	amount = player->get_save("tuzi");//获取该玩家的排行榜兔子数量。
	if(get_save_2(sprintf("player.%d",id)))
	{
		if(get_save_2(sprintf("player.%d.name",id))== name)//找到原来排行榜上已经有记录的玩家，
		{
//			add_save_2(sprintf("player.%d.count",id),1);//并且将记录增加1。
			set_save_2(sprintf("player.%d.count",id),amount);
			pos = get_save_2(sprintf("player.%d.pos",id));//获得对应玩家在排行榜上的位置。
		}
	}
	else if((size = get_save_2(sprintf("record.size"))) < 10)//判断排行榜的大小是否已经超出10。
	{
			pos = size+1;
			set_save_2("record.size",pos);//更新排行榜的大小。
			set_save_2(sprintf("record.%d",pos),id);//保存排行榜pos位置对应的id。
			set_save_2(sprintf("player.%d.name",id),name);//保存id玩家的姓名
			set_save_2(sprintf("player.%d.pos",id),pos);
			set_save_2(sprintf("player.%d.count",id),amount);//保存玩家交还月兔的数目。
	}
	else 
	{
		oldid = get_save_2(sprintf("record.%d",size));
		if(get_save_2(sprintf("player.%d.count",oldid))< amount)
		{
			pos = size;
			delete_save_2(sprintf("player.%d",oldid));//删除这个旧记录
			set_save_2(sprintf("record.%d",pos),id);//保存排行榜玩家当前排行上的id。
			set_save_2(sprintf("player.%d.name",id),name);//保存玩家的姓名
			set_save_2(sprintf("player.%d.pos",id),pos);//记录名次
			set_save_2(sprintf("player.%d.count",id),amount);//保存玩家交还月兔的数目。
			set_save_2("record.size",pos);//保存排行榜的大小。		
		}
	}
	if(pos)
	{
		for(index = pos; index > 1; index--)
		{
			id = get_save_2(sprintf("record.%d",index));
			id1 = get_save_2(sprintf("record.%d",index-1));
			if(get_save_2(sprintf("player.%d.count",id1))>= get_save_2(sprintf("player.%d.count",id)))
			{
				break;
			}
			set_save_2(sprintf("record.%d",index),id1);			
			set_save_2(sprintf("player.%d.pos",id1),index);
			set_save_2(sprintf("record.%d",index-1),id);
			set_save_2(sprintf("player.%d.pos",id),index-1);	
		}
		save();
	}
	
}

//Phần thưởng bắt rồng thiêng
void yuetu_bonus(object player,object npc)
{
	int rand,id,move,level;
	int *decoration = ({HEAD_TYPE,NECK_TYPE,ARMOR_TYPE,WAIST_TYPE,BOOTS_TYPE});
        string *nFamily = ({"Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
	string *nTmp;
	object item;
	rand = random(10000);
	id = player->get_number();
	if(sizeof_inventory(player, 1, MAX_CARRY) >= MAX_CARRY )
	{
		send_user(player,"%c%s",'!',"Trên người ngươi không đủ chỗ trống，ko thể nhận phần thưởng，lần sau đổi thưởng hãy chú ý nha。");
		return;
	}
	if ( give_yuebing(player,"Rồng Thiêng",5) == 0 ) //5 con rồng 1 lần đổi
        {
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),sprintf("%s：\n   Xin lỗi, số lượng rồng thiêng của ngươi chưa đủ.\n"ESC"Xác nhận",npc->get_name()));
		return ;        			
        }
//        YUTU->add_2(sprintf("player.%d.rabbit",id),1);//增加该玩家的排行榜兔子数量。
	if(rand < 2000)
	{
		move_to_user(player, 1, YUEBING,npc);//Thần Đơn Kim Bảo。
	}
	else if(rand < 4000)
	{

		move_to_user(player, 1, "item/91/9102",npc);//Tạo hóa。		
	}
	else if(rand < 6000)
	{
		move_to_user(player, 1, "item/91/9112",npc);//Bổ tâm。		
	}
	else if(rand < 7000)
	{
		move_to_user(player, 1, "item/91/9120",npc);//Cấp cứu。		
	}
	else if(rand < 8000)
	{
		move_to_user(player, 1, "item/91/9121",npc);//Hoạt tâm。
	}
	else if(rand < 8500)
	{
		move_to_user(player, 1, "item/bikipknb/knb2",npc);//Bí kíp knb。	
	}
	else if(rand < 9000)
	{
		move_to_user(player,1,"item/event/tethien/tethienchihoan",npc);//Pháp bảo
		USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR" Tế Thiên Chỉ Hoàn"+"\n");
	}
	else if(rand < 9500)
	{
		move_to_user(player,1,"item/sell/0032",npc);//DT
		USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR" Đoạn Thạch Sơ Cấp"+"\n");
	}
	else if(rand < 9900)
	{
		player->add_cash(100000);
		USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR" 100000 ngân lượng"+"。\n");
	}
	else if(rand < 9990)//随机门派的金色装备1件。
	{
		if ( (level=player->get_level()+5) >= 120 ) level=120;
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],random(2),level,decoration[random(sizeof(decoration))]);
		if ( sizeof(nTmp) )
		{	
			item = new(nTmp[random(sizeof(nTmp))]);
			if ( !item )
				return;
			ITEM_EQUIP_D->init_equip_prop_3(item);
		}
		move = item->move(player,-1);
		if(move)
		{
			item->add_to_user(move);
			USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR+item->get_name()+"。\n");
		}	
		else
			destruct(item);
	}
	else //随机门派的金色武器1件
	{
		if ( (level=player->get_level()+5) >= 120 ) level=120;
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)],random(2),level,WEAPON_TYPE);
		if ( sizeof(nTmp) )
		{	
			item = new(nTmp[random(sizeof(nTmp))]);
			if ( !item )
				return;
			ITEM_EQUIP_D->init_equip_prop_3(item);
		}
		move = item->move(player,-1);
		if(move)
		{
			item->add_to_user(move);
			USER_D->user_channel("Chúc mừng "+player->get_name()+" ở lễ tế thiên đạt được "+HIR+item->get_name()+"。\n");
		}	
		else
			destruct(item);
	}
	if( get_party_time() > iFinish ) 
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Cảm ơn đã giúp 1 tay，đây là phần thưởng。\n"+ESC"Xác nhận\n");
	else
		send_user(player,"%c%c%w%s",':',3,npc->get_char_picid(),npc->get_name()+"：\n"+"    Cảm ơn ngươi giúp 1 tay，đây là phần thưởng，số lượng rồng thiêng ngươi bắt ta đã ghi lại，xin hãy tiếp tục cố gắng。\n"+ESC"Xác nhận\n");
}

void before_destruct()
{
	if ( objectp(change) )
	{
		change->remove_from_scene();
		destruct(change);
	}
}

//交还月兔，获得金色装备或者金色武器。
/*void equipment(string*schoolname, int*gender,int*decoration,object player)
{
	int level,move;
	object present; 
	string* gold_equip = ({});
	level = player->get_level();
	level = level+random(10)+1;
	if(level > 120)
	{
		level = 120;
	}
	gold_equip = WEAPON_FILE->get_family_equip(schoolname[random(sizeof(schoolname))],gender[random(sizeof(gender))],level,decoration[random(sizeof(decoration))]);
	if(sizeof(gold_equip)> 0)
	{
		present = new(gold_equip[random(sizeof(gold_equip))]);
		if(!present)
		{
			return;
		}
		ITEM_EQUIP_D->init_equip_prop_3(present);
		if( move = present->move(player, -1) )
	        {
	                present->add_to_user(move);
	                USER_D->user_channel("Chúc mừng "+player->get_name()+" trong lễ tế thiên nhận được"+HIR+present->get_name()+"。\n");
	        }
	        else
	        {
	        	destruct(present);
	        }
	}
}*/

//活动开关
int get_close()
{
	return close;
}

void set_close()
{
	close=1;
	destruct_chang();
	destroy_yutu();
	destroy_yuebing();
}