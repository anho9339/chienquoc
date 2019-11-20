
// ؔ֯ʺԉú/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit HEAD;
//͗װةݾҪ־

//ܸ֚͗
int get_equip_serial() { return 1; }	//ܸ֚͗
// گ˽úˊԃąƉ
int get_item_value() {return 450 ;}
int get_item_value_2() {return 450 ;}
int get_family() { return 8; }
//͗װĻؖ

// گ˽úٹլԦm
void create()
{
        set_name("Thần Chiến Chi Mão");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(10);
        set_value(50000000);
        set_max_lasting(16099);
        set("ap+", 200);
        set("dp+", 200);
        set("cp+", 200);
        set("pp+", 200);
        set("sp+", 200);
        set("hp+", 200);
        set("mp+", 200);
	set_item_color(3);	//؏ɫ	//ӑݸ֨
        setup();
}

// گ˽úܱȡĨ˶
string get_desc()
{
        return "Mão";
}

// گ˽úܱȡ͗װĨ˶
string get_suit_desc()
{
        return "Chiếc mũ lưu truyền ngàn đời nay đã xuất hiện";
}

