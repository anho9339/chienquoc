#include <ansi.h>

inherit ITEM;

void create()
{
    set_name("Chào Mừng Lễ Bao");

    set_picid_1(4981);
    set_picid_2(4981);

    set_value(10);
}

int is_usable()
{
    return 1;
}

string get_desc()
{
    return "Khi mở túi này, người sẽ nhận được vật phẩm hỗ trợ cần thiết.";
}

void reset()
{
    if (gone_time(get_drop_time()) >= 1800)  // 30 phút làm mới
    {
        remove_from_scene();
        destruct(this_object());
    }
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
    int rate, p, cash, exp, pot;
    object item;

    rate = random(10000);

    if (rate < 2300)
        exp = 400;

    else if (rate < 5100)
        pot = 30;

    else if (rate < 5110)
    {
        item = new ("item/08/0001");  // Chiến Quốc Lệnh
    }

    else if (rate < 5140)
    {
        item = new ("item/08/0002");  // Tù và CQ
    }

    else if (rate < 5160)
    {
        item = new ("item/08/0003");  // Huyết Thạch
    }

    else if (rate < 5190)
    {
        item = new ("item/08/0004");  // Pháp Lực Thạch
    }

    else if (rate < 5220)
    {
        item = new (BOOK_FILE->get_book_file());  //技能进阶书
    }

    else if (rate < 7820)
        cash = 1000;

    /*	else if ( rate < 7825 )
        {
                item = new("item/std/6001");	//百宝囊
        }
        else if ( rate < 7840 )
        {
                item = new("item/91/9178");	//复生丹
        }*/

    else if (rate < 8000)
    {
        item = new (STONE_FILE->get_diamond_file());  // 1级晶石
        item->set_level(1);
    }

    else if (rate < 8500)
    {
        item = new ("item/std/8000");  // Tàng bảo đồ
    }

    else if (rate < 9250)  //炼丹成品
    {
        p = random(6);

        switch (p)
        {
            default:
                item = new ("item/final/91/1808");  //银杏子
                break;

            case 1:
                item = new ("item/final/91/1809");  //仙山灵芝
                break;

            case 2:
                item = new ("item/final/91/1810");  //紫箐丹
                break;

            case 3:
                item = new ("item/final/91/1811");  //舍利子
                break;

            case 4:
                item = new ("item/std/5211");  // Hạc Đỉnh HỒng
                item->set_amount(3);
                break;

            case 5:
                item = new ("item/91/9145");  // Thanh Tâm Đan
                item->set_amount(2);
                break;
        }
    }

    else if (rate < 9350)  // Ngọc Linh Dịch
        item = new ("item/44/4404");

    else if (rate < 9550)  //Đồ xanh
    {
        if (random(2))
            item = new (ARMOR_FILE->get_armor_file_2(who->get_level()));
        else
            item = new (WEAPON_FILE->get_weapon_file_2(who->get_level()));

        ITEM_EQUIP_D->init_equip_prop_1(item);
    }

    else if (rate < 9560)  //Đồ vàng
    {
        if (random(2))
            item = new (ARMOR_FILE->get_armor_file_2(who->get_level()));
        else
            item = new (WEAPON_FILE->get_weapon_file_2(who->get_level()));

        ITEM_EQUIP_D->init_equip_prop_3(item);
    }

    else if (rate < 9830)  // Thuốc Hồi Máu
        item = new ("/item/sell/0007");

    else  // Thuốc Hồi Mana
        item = new ("/item/sell/0009");

    gift->remove_from_user();
    destruct(gift);

    if (item)
    {
        //	CHAT_D->sys_channel(0,sprintf(HIR"恭喜%s在宝藏大搜寻活动中获得奖品%s",who->get_name(),item->get_name()));
        send_user(who, "%c%s", '!', "Chúc mừng, bạn mở túi nhận được " + item->get_name());
        p = item->move2(who);
        item->add_to_user(p);
    }

    else if (cash)
    {
        who->add_cash(cash);
        send_user(who, "%c%s", '!', sprintf("Chúc mừng, bạn mở túi nhận được %d ngân lượng", cash));
    }

    else if (exp)
    {
        who->add_exp(exp);
        send_user(who, "%c%s", '!', sprintf("Chúc mừng, bạn mở túi nhận được %d kinh nghiệm", exp));
    }

    else if (  pot )
    {
        who->add_potential(pot);
        send_user(who, "%c%s", '!', sprintf("Chúc mừng, bạn mở túi nhận được %d tiềm năng", pot));
    }

    return 0;
}
