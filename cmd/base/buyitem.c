
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

mapping	allgood	=([
	"good1": ([
		"01" : "/item/sell/0061",
		"02" : "/pretkuzl/newitem/truyentongp",
		"03" : "/item/ppvacanh/HoaPhu",
		"04" : "/item/event/minigame/phieugame",
	//    "05" : "/item/event/tet/phao",
		"05" : "/item/test/phieuthuongnhan",
		]),
	"good2": ([   
		"01" : "/item/test/tuihoangkimtanthucap40", 
		"02" : "/item/test2/BatTuDon",
		"03" : "/item/08/0001",  
		"04" : "/item/08/0002", 	
		"05" : "/item/sell/0007",  
		"06" : "/item/sell/0009",
		"07" : "/item/08/0003",
		"08" : "/item/08/0004",
		"09" : "/item/91/9166",  
	//	"10" : "/item/91/9178",  // Phục Sinh Đơn
		"10" : "/item/sell/0006",
		"11" : "/item/sell/0044",	  
		]),
	"good3": ([
	//	"01" : "/item/test2/NangCap/TC",
		"01" : "/item/08/0841",
		"02" : "/item/08/0842",
		"03" : "/item/08/0843",
		"04" : "/item/08/shuiping",		
		"05" : "/item/test2/SVT",
		"06" : "/item/test2/SungVatDuoc",
		"07" : "/item/test2/SungVatDuoc2",
		"08" : "/item/sell/0025",
		]),
	"good4":  ([
	/*	"01" : "/item/sell/9301",
		"02" : "/item/sell/9302",
		"03" : "/item/sell/9303",
		"04" : "/item/sell/9304",
		"05" : "/item/sell/9305",
		"06" : "/item/sell/9306",
		"07" : "/item/sell/9307",
		"08" : "/item/sell/9308",
		"09" : "/item/sell/9309",
		"10" : "/item/sell/9310", */
		"01" : "/item/test2/LTDB",
		"02" : "/item/01/0006",
		"03" : "/item/std/8000",
		"04" : "/item/sell/0044",
		"05" : "/item/test2/TLTA",
		"06" : "/item/test2/AXP",
		"07" : "/item/test2/TuiQuaVoSong",
		"08" : "/item/test2/TuiPhapBao",
		"09" : "/item/test2/TuiLinhThach",
	//	"08" : "/item/test/tuimanhghephoangkim",		
		"10" : "/item/test2/TheGiamGia",
		"11" : "/item/test2/TuiThanThu",
		
	//	"20" : "/item/08/0003",
	//	"21" : "/item/08/0004",
	//	"10" : "/item/test2/NangCap/vktukim",
		 ]) ,
	"good5": ([
		"01" : "/item/sell/0045",			
		"02" : "/item/sell/0012",				
	//	"03" : "/item/01/0006",
	//	"03" : "/item/sell/0050",		// Khóa càn khôn				
		"03" : "/item/sell/0030",
		"04" : "/item/sell/0031",				
		"05" : "/item/sell/0043",
		"06" : "/item/sell/0042",
		"07" : "/item/sell/0028",
		"08" : "/item/sell/0029",
		"09" : "/item/sell/0033",
		"10" : "/item/test2/BiKipKNB1",
		"11" : "/item/test2/BiKipKNB2",
		"12" : "/item/test2/BiKipKNB3",
	//	"13" : "/item/event/nhagiao/thuchucphuc",
	//	"11" : "/item/test2/AXP",
		]),		
	"good6": ([
		"01" : "/item/100/10061",
		"02" : "/item/100/11061",
		"03" : "/item/100/10060",
		"04" : "/item/100/11060",
		"05" : "/item/100/10059",
		"06" : "/item/100/11059",
		"07" : "/item/ngoai_trang/sell/3nam",
		"08" : "/item/ngoai_trang/sell/3nu",
		"09" : "/item/ngoai_trang/sell/4nam",
		"10" : "/item/ngoai_trang/sell/4nu",
		"11" : "/item/ngoai_trang/sell/5nam",
		"12" : "/item/ngoai_trang/sell/5nu",
	//	"07" : "/item/test2/TrungSinh/1100",
		"13" : "/item/std/0004",
		"14" : "/item/std/0005",
		"15" : "/item/std/0006",
		"16" : "/item/std/0007",
		]),
//----------------这个只是在国庆卖的一个特殊物品，而且是不显示的------------------------------------
	"good99": ([
	//	"01" : "/item/mop/9003",
		"01" : "/item/test2/tuitukim55",
		"02" : "/item/mop/9006",
		]),
//--------------------------------------------------------------------------------------------
	]);
mapping	gonggao	=([
	"充值优惠" : "2007年4月11日至5月11日期间，凡购买元宝的用户（不论何种充值方式），每单次充值100个元宝可额外获得 “紫参丹”1个，如果单次充值元宝数额超过100，每多100便多赠送一个“紫参丹”.（紫参丹功能：使用后+2000潜能）",
	"直充优惠" : "2007年4月11日开始凡通过《大话战国》官网的“银行卡直充”功能购买元宝的用户，可按充值数量额外获得游戏道具.详细活动介绍请参见zg.mop.com相关活动公告.",
		]);


void send_gonggao(object me);
int xacnhanmua(object me, string arg, int total, string file);
mapping	goodprice = ([ ]);

void create()
{
	string cpp, *line;
	int i, size, a,	b, c, d, ret;
	cpp = read_file("/quest/good.dat");
	if (!cpp)
	{
		return;
	}
	line = explode(	cpp, "\n" );
	size = sizeof(line);
	if (size==0) return;
	for (i=0;i<size;i++)
	{		
		if (sscanf(line[i], "%d %d %d %d", a, b, c, d)!=4) 
		{
			continue;	
		}
		goodprice[a] = ({b, c, d });
	}
}
//Question before Buy
int xacnhanmua(object me,string arg,int total,string file)
{
	string result;
	if ( me->get_save("muaxn2")>=1 )
	 return 0;
	me->set_save("muaxn",arg);
	result = sprintf("Bạn quyết định mua %d cái %s chưa?\n"
			ESC "%c\n" ESC "\nvip 123\n"
			, total, file->get_name(), 1 );
				send_user(me, "%c%c%s", 0x59, 1, result);	
	return 1;
}
// 函数：命令处理
int main( object me, string arg	)
{
	mapping	list;
	int iVip, i, size, price, type,	what, total, amount, count, p, x, y, z,	itemid;
	string *key, file, desc, name, legend, result;
	object item;
	int * prices;
//	iVip = me->get_vip();
//	if (time()<iVip) iVip =	1;
//	else iVip = 0;

	if (!arg)
	{
//tell_user(me, "打开珍宝铺");		
		send_user(me, "%c%c%c",	0x45, 1, 0 );
		if (MAIN_D->get_host_type()==1||MAIN_D->get_host_type()==1000)
		{
			send_user(me, "%c%c%d",	0x45, 2, "sys/sys/test_db"->get_yuanbao(me) );
		}
		else
		if (MAIN_D->get_host_type()==6012)
		{
//tell_user(me, "打开珍宝铺1");			
			me->set_pay_money_buy_item(1);
			me->set_pay_type(5);
			me->set_buy_item_cmd_string("  ");
			db_user_pay( me, sprintf( "210.48.144.183:2500\n"
				"21,\"%s\",%d\r\n", me->get_real_id(), me->get_acountno() ) );
//			log_file( "php.date", sprintf( "open 210.48.144.183:2500\n"
//				"21,\"%s\",%d\r\n", me->get_real_id(), me->get_acountno() ) );			
		}
		else
		if (me->get_pay_money_buy_item()==0 && !me->get("phpbalance"))
		{					
			me->set_pay_money_buy_item(1);
			me->set_pay_type(5);
			me->set_buy_item_cmd_string("  ");
			db_user_pay( me, sprintf( "%s:80\n"
				"GET http:/""/%s/querybalance.php?t=%s&u=%d\r\n", MAIN_D->get_php_ip(),
				MAIN_D->get_php_ip(), short_time_2(), me->get_acountid() ) );
//log_file( "php.date", 	sprintf( "%s:80\n"
//				"GET http:/""/%s/querybalance.php?t=%s&u=%d\r\n", MAIN_D->get_php_ip(),
//				MAIN_D->get_php_ip(), short_time_2(), me->get_acountid() ) );			
		}


		arg = "2";
	}

	if (arg=="notice")
	{
		send_gonggao(me);
		return 1;
	}
	key = explode( arg, " "	);
	if (sizeof(key)==1)
	{
		list = allgood["good"+arg];
		if( !mapp(list)) return	1;
		key = keys(list);
		size = sizeof(key);
		if (size==0) return 1;
		key = sort_array(key, 1);
		send_gonggao(me);
		for( i = 0; i <	size; i	++ )
		{
			file = list[ key[i] ];
			desc = file->get_short();
			prices = goodprice[file->get_item_number()];
			if (sizeof(prices)==3)
			{
				if (iVip==0) price = prices[0];
				else
				{
					if (prices[2]>0) price = prices[2];
					else price = prices[1];
				}
				if (prices[2]>0 && prices[2] < price ) 	//存在促销价
					price = prices[2];
					
				if (desc==0) desc = file->get_desc();
				name = sprintf("%-40s%s", file->get_name(), desc);
				send_user( me, "%c%c%c%c%d%d%d%w%w%c%c%s", 0x45, 3, to_int(arg), to_int( key[i]	), prices[0], prices[1], price,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), name );
			}
			else
			{
				price =	file->get_item_value();
				if (iVip==0) price = file->get_item_value();
				else
				{
					if (file->get_item_value_3()>0)	price =	file->get_item_value_3();
					else price = file->get_item_value_2();
				}
				if (desc==0) desc = file->get_desc();
				name = sprintf("%-40s%s", file->get_name(), desc);
				send_user( me, "%c%c%c%c%d%d%d%w%w%c%c%s", 0x45, 3, to_int(arg), to_int( key[i]	), file->get_item_value(), file->get_item_value_2(), price,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), name );
			}
		}
		return 1;
	}
	if (key[0]=="desc")
	{
		if (sizeof(key)!=3) return 1;
		type = to_int(key[1]);
		what = to_int(key[2]);
		if( !stringp( file = allgood[sprintf("good%d.%02d", type, what ) ] ) ) return 1;
		send_user( me, "%c%c%c%c%s", 0x45, 4, type, what, file->get_desc() );
		return 1;
	}
	if (sscanf(arg,	"%d %d %d", type, what,	total)!=3) return 1;
	if( total < 1 )
	{
		notify(	"Ngài mua đích cái sổ đắc lớn hơn 0." );
		return 1;
	}
	if (MAIN_D->get_host_type()==1||MAIN_D->get_host_type()==1000)
	{
		list = allgood[sprintf("good%d", type)];
		if( !mapp(list))
		{
			notify(	"Đạo cụ này không có bán ra" );
			return 1;
		}
		file = list[sprintf("%02d", what+1)];
		if( !stringp( file ) )
		{
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}
		if( me->get_save("passhanhtrang") && me->get_save("ndmkhtk") < 1 )
		{
			notify(	"Hành trang đang trong trạng thái Khoá." );
			send_user( me, "%c%c%d%s", 0x43, 10, 0, HIR "Hành trang của bạn đang trong trạng thái Khoá !" );
			return 1;
		}
		if( ( amount = USER_INVENTORY_D->can_carry_3( me, load_object(file) ) ) < 1 )
		{		
			notify(	"Hãy chừa 1 chỗ trống" );
			return 1;
		}
		if( ( price = file->get_item_value() ) < 1 )
		{
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}
		if ( file->get_sell_amount() && amount > file->get_sell_amount() )
			amount = file->get_sell_amount();
		if( total > amount ) total = amount;
		if ( xacnhanmua(me,arg,total,file)==1 ) return 1;
		if ( file->question_before_buy(me,arg) == 1 )
			return 1;
		prices = goodprice[file->get_item_number()];
		if (sizeof(prices)==3)
		{
			price =	prices[0];
			if (iVip>0)
			{
				if (prices[2]>0)  price	= prices[2];
				else
				if (prices[1]>0)  price	= prices[1];
			}
			if (prices[2]>0 && prices[2] < price )  
				price	= prices[2];
		}
		else
		{
			price =	file->get_item_value();
			if (iVip>0)
			{
				if (file->get_item_value_3()>0)	 price = file->get_item_value_3();
				else
				if (file->get_item_value_2()>0)	 price = file->get_item_value_2();
			}
		}
		price *= total;
		if ("sys/sys/test_db"->get_yuanbao(me)<price)
		{
			notify(	"Ngươi không có đủ Kim Nguyên Bảo" );
			if ( stringp(me->get_save("muaxn")) ) me->delete_save("muaxn");
			if ( me->get_save("muaxn2")>=1 ) me->delete_save("muaxn2");
			if ( stringp(me->get_save("muavip")) ) me->delete_save("muavip");
			if ( me->get_save("muavip2")>=1 ) me->delete_save("muavip2");
			return 1;
		}
		"sys/sys/test_db"->add_yuanbao(me, -price);
		send_user(me, "%c%c%d",	0x45, 2, "sys/sys/test_db"->get_yuanbao(me) );
		"/sys/sys/id"->add_buy(total, price);
		if ( file->give_item_to_user(me) )
			return ;
		else if( file->is_combined()	)
		{
			if( amount = USER_INVENTORY_D->carry_combined_item( me,	load_object(file), total ) )
			{

				item = new(file);
				item->set_hide(0);
				item->set_amount(amount);
				count =	"/sys/sys/count"->add_buy_count(1);
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id( sprintf("#%d#", itemid) );
				log_file("itemid.dat", sprintf("%s %d %s %s\n",	short_time(), itemid, item->get_name(),	"/sys/item/item"->get_pawn_save_string(item) ));
				legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(),	get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(legend);
				if( p =	item->move2(me) )
				{
					item->add_to_user(p);
				}
				else if( p = get_valid_xy(z, x,	y, IS_ITEM_BLOCK) )
				{
					item->add_to_scene(z, p	/ 1000,	p % 1000);
				}
			}
		}
		else for( i = 0; i < total; i ++ )
		{
			item = new(file);
			item->set_hide(0);
			count =	"/sys/sys/count"->add_buy_count(1);
			itemid = "/sys/sys/id"->add_max_itemid(1);
			item->set_user_id( sprintf("#%d#", itemid) );
			log_file("itemid.dat", sprintf("%s %d %s %s\n",	short_time(), itemid, item->get_name(),	"/sys/item/item"->get_pawn_save_string(item) ));
			legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(),	get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
			"/sys/user/cmd"->log_item(legend);
			if( p =	item->move2(me) )
			{
				item->add_to_user(p);
			}
			else if( p = get_valid_xy(z, x,	y, IS_ITEM_BLOCK) )
			{
				item->add_to_scene(z, p	/ 1000,	p % 1000);
			}
		}
log_file("buyitem.dat",	sprintf("%s %s(%d) mua %s thành công %d %d\n",	short_time(), me->get_id(), me->get_number(), file->get_name(),	total, price));
		send_user(me,  "%c%s", '!', sprintf("Bạn đã mua %s .", file->get_name()) );
		if ( stringp(me->get_save("muaxn")) ) me->delete_save("muaxn");
		if ( me->get_save("muaxn2")>=1 ) me->delete_save("muaxn2");	
		return 1;
	}
	if( !me->get_pay_money_buy_item() )
	{
		if (me->get("paycount")<0)
		{
			notify(	"Ngươi không đủ Kim Nguyên Bảo,nếu ngươi đã bổ sung hãy reset trò chơi rồi lại mua đạo cụ" );
			return 1;
		}
		list = allgood[sprintf("good%d", type)];
		if( !mapp(list))
		{
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}
		file = list[sprintf("%02d", what+1)];
		if( !stringp( file ) )
		{
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}
		if( ( amount = USER_INVENTORY_D->can_carry_3( me,	load_object(file) ) ) <	1 )
		{
			notify(	"Hành trang không đủ ô trống." );
			return 1;
		}
		if( ( price = file->get_item_value() ) < 1 )
		{
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}
		if ( file->question_before_buy(me,arg) == 1 )
			return 1;
		if ( file->get_sell_amount() && amount > file->get_sell_amount() )
			amount = file->get_sell_amount();
		if( total > amount ) total = amount;
		prices = goodprice[file->get_item_number()];
		if (sizeof(prices)==3)
		{
			price =	prices[0];
			if (iVip>0)
			{
				if (prices[2]>0)  price	= prices[2];
				else
				if (prices[1]>0)  price	= prices[1];
			}
			if (prices[2]>0 && prices[2] < price )  
				price	= prices[2];
		}
		else
		{
			price =	file->get_item_value();
			if (iVip>0)
			{
				if (file->get_item_value_3()>0)	 price = file->get_item_value_3();
				else
				if (file->get_item_value_2()>0)	 price = file->get_item_value_2();
			}
		}
		price *= total;
		me->set_pay_money_buy_item(1);	  // 通过Đã mua道具中
		me->set_pay_type(6);
		me->set_buy_item_cmd_string( sprintf("%d %d %d", type, what, total) );
log_file("buyitem.dat",	sprintf(" %s %s ( %d ) đã mua %s %d \n", short_time(), me->get_id(), me->get_number(), file->get_name(), total));
		if (MAIN_D->get_host_type()==4||MAIN_D->get_host_type()==0)
		{
			db_user_pay( me, sprintf( "%s:80\n"
				"GET http:/""/%s/purchase.php?t=%s&u=%d&o=%d&n=%d&m=%d&c=%d&ip=%s&r=%d&h=%d\r\n", MAIN_D->get_php_ip(),
				MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), total, price, file->get_item_number(), get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );
//log_file("php.dat", sprintf( "%s:80\n"
//				"GET http:/""/%s/purchase.php?t=%s&u=%d&o=%d&n=%d&m=%d&c=%d&ip=%s&r=%d&h=%d\n",	MAIN_D->get_php_ip(),
//				MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), me->get_number(), total, price, file->get_item_number(), get_ip_name(me), MAIN_D->get_region(), MAIN_D->get_host() ) );
		}
		else
		if (MAIN_D->get_host_type()==6012)
		{
			db_user_pay( me, sprintf( "210.48.144.183:2500\n"
				"22,\"%s\",%d,\"99\",99,%d,\"%d\",\"%d\",\"%s\",\"%s\"\r\n", me->get_real_id(), me->get_acountno(),price, "/sys/sys/id"->get_transid(), file->get_item_number(), file->get_name(), get_ip_name(me)  ) );
//			log_file( "php.date", sprintf( "210.48.144.183:2500\n"
//				"22,\"%s\",%d,\"99\",99,%d,\"%d\",\"%d\",\"%s\",\"%s\"\r\n", me->get_real_id(), me->get_acountno(),price, "/sys/sys/id"->get_transid(), file->get_item_number(), file->get_name(), get_ip_name(me)  ) );			
			"/sys/sys/id"->add_transid(1);				
		}
		else
		db_user_pay( me, sprintf( "%s:80\n"
			"GET /xq2/buy.php?id=%s&time=%d&region=%d&host=%d&item=%d&point=%d&ip=%s\r\n", MAIN_D->get_php_ip(),
			rawurlencode( me->get_id() ), time(), MAIN_D->get_region(), MAIN_D->get_host(),	file->get_item_number(), price,	get_ip_name(me)	) );	// 扣点！
		return 1;
	}
	if( me->get_pay_money_buy_item() == 8 && me->get_pay_type()==6 )    // 通过Đã mua道具成功！
	{
		me->set_pay_money_buy_item(0);	  // 取消通过Đã mua道具
		me->set_pay_type(0);

		list = allgood[sprintf("good%d", type)];
		if( !mapp(list))
		{
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}
		file = list[sprintf("%02d", what+1)];
		if( !stringp( file ) )
		{
log_file("buyitem.dat",	sprintf("%s %s(%d) không có mua đối tượng\n", short_time(), me->get_id(),	me->get_number() ));
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}
		if( ( price = file->get_item_value() ) < 1 )
		{
log_file("buyitem.dat",	sprintf("%s %s(%d) mua thương phẩm không đúng\n", short_time(), me->get_id(),	me->get_number()));
			notify(	"Không có đạo cụ bán ra" );
			return 1;
		}

		if( ( amount = USER_INVENTORY_D->can_carry_3( me,	load_object(file) ) ) <	1 )
		{
log_file("buyitem.dat",	sprintf("%s %s(%d) mua không đủ không vị\n", short_time(), me->get_id(),	me->get_number()));
			notify(	"Hành trang không đủ chỗ trống" );
			return 1;
		}
		prices = goodprice[file->get_item_number()];
		if (sizeof(prices)==3)
		{
			price =	prices[0];
			if (iVip>0)
			{
				if (prices[2]>0)  price	= prices[2];
				else
				if (prices[1]>0)  price	= prices[1];
			}
			if (prices[2]>0 && prices[2] < price )  
				price	= prices[2];
		}
		else
		{
			price =	file->get_item_value();
			if (iVip>0)
			{
				if (file->get_item_value_3()>0)	 price = file->get_item_value_3();
				else
				if (file->get_item_value_2()>0)	 price = file->get_item_value_2();
			}
		}
		if ( file->get_sell_amount() && amount > file->get_sell_amount() )
			amount = file->get_sell_amount();
		if( total > amount ) total = amount;
		price *= total;
		"/sys/sys/id"->add_buy(total, price);
		if ( file->give_item_to_user(me) )
			return ;
		else if( file->is_combined()	)
		{
			if( amount = USER_INVENTORY_D->carry_combined_item( me,	load_object(file), total ) )
			{

				item = new(file);
				item->set_hide(0);
				item->set_amount(amount);
				count =	"/sys/sys/count"->add_buy_count(1);
				itemid = "/sys/sys/id"->add_max_itemid(1);
				item->set_user_id( sprintf("#%d#", itemid) );
				log_file("itemid.dat", sprintf("%s %d %s %s\n",	short_time(), itemid, item->get_name(),	"/sys/item/item"->get_pawn_save_string(item) ));
				legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(),	get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), amount, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
				"/sys/user/cmd"->log_item(legend);
				if( p =	item->move2(me) )
				{
					item->add_to_user(p);
				}
				else if( p = get_valid_xy(z, x,	y, IS_ITEM_BLOCK) )
				{
					item->add_to_scene(z, p	/ 1000,	p % 1000);
				}
			}
		}
		else for( i = 0; i < total; i ++ )
		{
			item = new(file);
			item->set_hide(0);
			count =	"/sys/sys/count"->add_buy_count(1);
			itemid = "/sys/sys/id"->add_max_itemid(1);
			item->set_user_id( sprintf("#%d#", itemid) );
			log_file("itemid.dat", sprintf("%s %d %s %s\n",	short_time(), itemid, item->get_name(),	"/sys/item/item"->get_pawn_save_string(item) ));
			legend = sprintf("Đã mua @%s %s,%d,%s,%s %s %s %d %s %d_%d_%d", "Ngân Khố", me->get_name(), me->get_number(),	get_ip_name(me), me->get_id(), item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me) );
			"/sys/user/cmd"->log_item(legend);
			if( p =	item->move2(me) )
			{
				item->add_to_user(p);
			}
			else if( p = get_valid_xy(z, x,	y, IS_ITEM_BLOCK) )
			{
				item->add_to_scene(z, p	/ 1000,	p % 1000);
			}
		}
log_file("buyitem.dat",	sprintf(" %s %s ( %d ) đã mua %s thành công %d %d \n",	short_time(), me->get_id(), me->get_number(), file->get_name(),	total, price));
		send_user(me,  "%c%s", '!', sprintf("Bạn đã mua %s .", file->get_name()) );
		if (file->get_name()=="国庆大礼包") send_user(me, "%c%s", ';', "恭喜你成功购买了一份国庆疯狂大礼包，同时获得了"HIR "200元宝"NOR "，赶快去体验这个礼包带来的热闹国庆吧！");
	}
	else
	{
		if (me->get_pay_money_buy_item()>0)
		{
			send_user(me,"%c%s",'!',"Đang xử lý, xin chờ 1 chút");
			return ;
		}
	}
	return 1;
}

void send_gonggao(object me)
{
	int i, size;
	string * key;
	key = keys(gonggao);
	size = sizeof(key);
	for (i=0;i<size;i++)
	{
		send_user( me, "%c%c%c%s", 0x45, 5, i+1, key[i]	);
		send_user( me, "%c%c%c%s", 0x45, 6, i+1, gonggao[key[i]] );
	}
}