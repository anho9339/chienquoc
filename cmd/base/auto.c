#include <ansi.h>
#include <effect.h>
#include <equip.h>
#include <skill.h>
#include <time.h>
int main(object me, string arg)
{
    int a, b, c, d;

    if (sscanf(arg, "%d %d", a, b) != 2)
        return 1;

    switch (a)
    {
        case 2:
            if (b < 1 || b > 10)
                return 1;

            if (b == 1)
                c = (1 * 60 * 60) / 2;
            else if (b == 2)
                c = (2 * 60 * 60) / 2;
            else if (b == 3)
                c = (3 * 60 * 60) / 2;
            else if (b == 4)
                c = (4 * 60 * 60) / 2;
            else if (b == 5)
                c = (5 * 60 * 60) / 2;
            else if (b == 6)
                c = (6 * 60 * 60) / 2;
            else if (b == 7)
                c = (7 * 60 * 60) / 2;
            else if (b == 8)
                c = (8 * 60 * 60) / 2;
            else if (b == 9)
                c = (9 * 60 * 60) / 2;
            else if (b == 10)
                c = (10 * 60 * 60) / 2;

            if ("/sys/sys/test_db"->get_yuanbao(me) < b * 10)
                return 1;

            "/sys/sys/test_db"->add_yuanbao(me, -(b * 10));
            set_effect_2(me, EFFECT_XUESHI_HP, c, 2);
            me->set_save("stone_hp", 40);
            send_user(me, "%c%w%w%c", 0x81, 2, c * 2, EFFECT_GOOD);
            set_effect_2(me, EFFECT_FALISHI_MP, c, 2);
            me->set_save("stone_mp", 40);
            send_user(me, "%c%w%w%c", 0x81, 4, c * 2, EFFECT_GOOD);
            send_user(me, "%c%s", ';',
                      sprintf("Bạn đã sử dụng gói Auto loại 2 trong %d giờ, bạn bị trừ đi %d kim nguyên bảo !", b, b));

        case 5:
            if (b < 1 || b > 10)
                return 1;

            if (b == 1)
            {
                c = (1 * 60 * 60) / 2;
                d = 25;
            }
            else if (b == 2)
            {
                c = (2 * 60 * 60) / 2;
                d = 50;
            }
            else if (b == 3)
            {
                c = (3 * 60 * 60) / 2;
                d = 75;
            }
            else if (b == 4)
            {
                c = (4 * 60 * 60) / 2;
                d = 100;
            }
            else if (b == 5)
            {
                c = (5 * 60 * 60) / 2;
                d = 125;
            }
            else if (b == 6)
            {
                c = (6 * 60 * 60) / 2;
                d = 150;
            }
            else if (b == 7)
            {
                c = (7 * 60 * 60) / 2;
                d = 175;
            }
            else if (b == 8)
            {
                c = (8 * 60 * 60) / 2;
                d = 200;
            }
            else if (b == 9)
            {
                c = (9 * 60 * 60) / 2;
                d = 225;
            }
            else if (b == 10)
            {
                c = (10 * 60 * 60) / 2;
                d = 250;
            }

            if ("/sys/sys/test_db"->get_yuanbao(me) < d)
                return 1;

            "/sys/sys/test_db"->add_yuanbao(me, -d);
            set_effect_2(me, EFFECT_XUESHI_HP, c, 2);
            me->set_save("stone_hp", 100);
            send_user(me, "%c%w%w%c", 0x81, 2, c * 2, EFFECT_GOOD);
            set_effect_2(me, EFFECT_FALISHI_MP, c, 2);
            me->set_save("stone_mp", 100);
            send_user(me, "%c%w%w%c", 0x81, 4, c * 2, EFFECT_GOOD);
            send_user(me, "%c%s", ';',
                      sprintf("Bạn đã sử dụng gói Auto loại 5 trong %d giờ, bạn bị trừ đi %d ngân bảo !", b, d));
    }
}
