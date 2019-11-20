#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>
inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 5505; } 
int is_seller() { return 1; }
int is_self_look() { return 1; }
void do_welcome(string arg);
void do_accept(string arg);
void create()
{	  
        set_name("Lặt Vặt");
		set_2( "good", ([
                "01" : "/item/test/chenbacvip",
				"02" : "/item/test/tuihoangkimtanthucap130",
				"03" : "/item/test/tuitukim85",
				"04" : "/item/sell/3032",
				"05" : "/item/sell/0032",
				"06" : "/item/sell/1032",
				"07" : "/item/sell/2032",
				"08" : "/item/test2/bbbzzz/KyNangBangDuongMon",
				"09" : "/item/test2/bbbzzz/KyNangBangNoiCong",
				"10" : "/item/test2/bbbzzz/KyNangBangNgoaiCong",
				"11" : "/item/std/0095",
			//	"11" : "/item/test2/TichLuy/BKCT",
			//	"12" : "/item/test2/TichLuy/BKCT1",
			//	"13" : "/item/test2/TichLuy/BKCT2",	
        ]) );
		set_2( "talk", ([
                "welcome"	:( : do_welcome :),
				"accept"         : (: do_accept :),
             ]));
        setup();

}

void do_welcome( string arg )
{
	__FILE__->do_welcome2(this_object(),arg);
}
void do_welcome2( object npc, string arg )
{
	int flag,p,gender;
	object player  = this_player(),item;
	string *nTmp,cFile;
	flag = to_int(arg);
	switch(flag)
	{
		case 1:
	        send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(),npc->get_name() + ":\n"+"Nếu muốn tiêu huỷ trang bị, có thể đến gặp ta, ta chỉ nhận tiêu huỷ trang bị có 1 ngôi sao trở lên. Sau khi tiêu huỷ trang bị, bạn có thể nhận được một số ngân lượng tuỳ vào mức quý hiếm của trang bị đó, trang bị có số sao càng cao ngân lượng nhận được sẽ càng nhiều !\n" 
	        ESC "ALT+G để giao trang bị\nCLOSE\n"
			ESC "Thoát ra\nCLOSE\n"); 
		break;
		case 2:
			if ( TASK_LEGEND_D->check_task_item_amount(player,"Thiệp Quốc Tế Phụ Nữ") < 10 )
			{
                notify( "Không đủ 10 Thiệp Quốc Tế Phụ Nữ" );
                return ;
			}
			if(USER_INVENTORY_D->get_free_count(player) < 1 )
			{
				notify( "Hành trang không đủ 1 chỗ trống" );
				return ;
			}
			TASK_LEGEND_D->check_task_item1(player,"Thiệp Quốc Tế Phụ Nữ",10);
			if ( random100() < 1 )
			{
			item=new("item/sell/0032");
			p=item->move2(player,-1);
			item->add_to_user(p);
			}
			else if ( random100() < 5 )
			{
	nTmp = WEAPON_FILE->get_family_equip(player->get_fam_name(),player->get_gender(),player->get_level(),HEAD_TYPE+random(6));
	cFile = nTmp[random(sizeof(nTmp))];
	if( load_object(cFile) )
	{
		item = new( cFile );
		ITEM_EQUIP_D->init_equip_prop_3(item);
		item->set_hide(0);
		item->set_bind(1);
		p = item->move2(player,-1);
		item->add_to_user(p);
	}
			}
			else if ( random100() < 10 )
			{
			gender = player->get_gender()==1?10:11;
			item=new(sprintf("item/100/%d110",gender));
			p=item->move2(player,-1);
			item->add_to_user(p);
			}
			else if ( random100() < 50 )
			{
			item=new("item/08/0003");
			p=item->move2(player,-1);
			item->add_to_user(p);
			}
			else if ( random100() < 70 )
			{
			item=new("item/08/0004");
			p=item->move2(player,-1);
			item->add_to_user(p);
			}
			else if ( random100() < 85 )
			{
			item=new("item/08/0851");
			p=item->move2(player,-1);
			item->add_to_user(p);
			}
			else
			{
			item=new("item/08/0852");
			p=item->move2(player,-1);
			item->add_to_user(p);
			}
			if ( item ) CHAT_D->sys_channel(0,"Bằng hữu "+player->get_name()+" đổi Thiệp Quốc Tế Phụ Nữ đã may mắn nhận được "+item->get_name()+", xin chúc mừng!");
			break;
	}
}
void do_look( object player )
{
	object npc = this_object();
	
	send_user( player, "%c%c%w%s", ':',3,npc->get_char_picid(), sprintf( "%s :\n"+"Mùa thi cử lần này ta nhất định sẽ đỗ Trạng Nguyên !\n"
        ESC "Tiêu huỷ trang bị\ntalk %x# welcome.1\n"
    //    ESC "Đổi thiệp 8/3 lấy quà tặng\ntalk %x# welcome.2\n"
        ESC "Mua vật phẩm \nlist %x#\n"
        ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc) ) );
}

// 函数:接受物品
int accept_object( object who, object item ){ return __FILE__ ->accept_object_callout( this_object(), who, item ); }

// 函数:接受物品(在线更新)
int accept_object_callout( object me, object who, object item )
{
    int level, p, i, t1, t2, t3, t4, mau, cap, cap1, cap2;
	object item2;
	string sao,ngoc;
        me->to_front_eachother(who);
	if( !item->is_equip() ) return 0;
	if( item->is_equip())
	{
		i=item->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE) {
			write_user(who,ECHO"Bạn đưa Thư Sinh trang bị không đúng");
		//	send_user(who,"%c%s",':',me->get_name()+":\nBạn đưa tôi trang bị không đúng !!!\n"ESC"Rời khỏi.");
			return -99;
			}
	}
	sao = item->get("forge");
	cap = strlen(sao);
	ngoc = item->get("make");
	cap1 = strlen(ngoc);
	cap2 = item->get_level();
	mau = item->get_item_color();
	if ( cap < 1 ) {
		write_user(who,ECHO"Trang bị chưa đạt 1 sao, không thể tiêu huỷ");
	//	send_user(who,"%c%s",':',me->get_name()+":\nTrang bị chưa đạt 1 sao, không thể tiêu huỷ !!!\n"ESC"Rời khỏi.");
		return -99;
	}
	if ( mau==1 ) {
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thư Sinh:\nTiêu huỷ trang bị này bạn có thể nhận được %d lượng, bạn muốn tiêu huỷ không ?\n"ESC"Xác nhận\ntalk %x# accept.%x#\n"ESC"Huỷ bỏ",cap*cap2*1000,getoid(me),getoid(item)));
	}
	else if ( mau==2 ) {
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thư Sinh:\nTiêu huỷ trang bị này bạn có thể nhận được %d lượng, bạn muốn tiêu huỷ không ?\n"ESC"Xác nhận\ntalk %x# accept.%x#\n"ESC"Huỷ bỏ",cap*cap2*1500,getoid(me),getoid(item)));
	}
	else if ( mau==3 ) {
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thư Sinh:\nTiêu huỷ trang bị này bạn có thể nhận được %d lượng, bạn muốn tiêu huỷ không ?\n"ESC"Xác nhận\ntalk %x# accept.%x#\n"ESC"Huỷ bỏ",cap*cap2*1250,getoid(me),getoid(item)));
	}
	else if ( mau==4 ) {
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thư Sinh:\nTiêu huỷ trang bị này bạn có thể nhận được %d lượng, bạn muốn tiêu huỷ không ?\n"ESC"Xác nhận\ntalk %x# accept.%x#\n"ESC"Huỷ bỏ",cap*cap2*1100,getoid(me),getoid(item)));
	}
	else if ( mau==0 ) {
	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("Thư Sinh:\nTiêu huỷ trang bị này bạn có thể nhận được %d lượng, bạn muốn tiêu huỷ không ?\n"ESC"Xác nhận\ntalk %x# accept.%x#\n"ESC"Huỷ bỏ",cap*cap2*800,getoid(me),getoid(item)));
	}
	
	return -99;
}
// Bla bla
void do_accept( string arg ){ return __FILE__ ->do_accept_callout( this_object(), this_player(), arg ); }

// Bla bla
void do_accept_callout(object me, object who, string arg )
{
	int level, p, i, t1, t2, t3, t4, mau, cap, cap1, cap2;
	object item;
	string sao,ngoc;
	
	if( !objectp( item = present( arg, who, 1, MAX_CARRY*4 ) ) )
		return 0;
	if( !item->is_equip() ) return 0;
	if( item->is_equip())
	{
		i=item->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE) {
			write_user(who,ECHO"Bạn đưa Thư Sinh trang bị không đúng");
		//	send_user(who,"%c%s",':',me->get_name()+":\nBạn đưa tôi trang bị không đúng !!!\n"ESC"Rời khỏi.");
			return 0;
			}
	}
	sao = item->get("forge");
	cap = strlen(sao);
	ngoc = item->get("make");
	cap1 = strlen(ngoc);
	cap2 = item->get_level();
	mau = item->get_item_color();
	if ( cap < 1 ) {
		write_user(who,ECHO"Trang bị chưa đạt 1 sao, không thể tiêu huỷ");
	//	send_user(who,"%c%s",':',me->get_name()+":\nTrang bị chưa đạt 1 sao, không thể tiêu huỷ !!!\n"ESC"Rời khỏi.");
		return 0;
	}
	if ( mau==1 ) {
		who->add_cash( cap*cap2*1000 );
		write_user(who, sprintf(ECHO"Bạn tiêu huỷ %s và nhận được %d lượng", item->get_name(), cap*cap2*1000 ));
		item->remove_from_user();
		destruct(item);
	}
	else if ( mau==2 ) {
		who->add_cash( cap*cap2*1500 );
		write_user(who, sprintf(ECHO"Bạn tiêu huỷ %s và nhận được %d lượng", item->get_name(), cap*cap2*1500 ));
		item->remove_from_user();
		destruct(item);
	}
	else if ( mau==3 ) {
		who->add_cash( cap*cap2*1250 );
		write_user(who, sprintf(ECHO"Bạn tiêu huỷ %s và nhận được %d lượng", item->get_name(), cap*cap2*1250 ));
		item->remove_from_user();
		destruct(item);
	}
	else if ( mau==4 ) {
		who->add_cash( cap*cap2*1100 );
		write_user(who, sprintf(ECHO"Bạn tiêu huỷ %s và nhận được %d lượng", item->get_name(), cap*cap2*1100 ));
		item->remove_from_user();
		destruct(item);
	}
	else if ( mau==0 ) {
		who->add_cash( cap*cap2*800 );
		write_user(who, sprintf(ECHO"Bạn tiêu huỷ %s và nhận được %d lượng", item->get_name(), cap*cap2*800 ));
		item->remove_from_user();
		destruct(item);
	}
	return 0;
}