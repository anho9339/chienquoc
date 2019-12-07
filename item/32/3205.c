
// ×Ô¶¯Éú³É£º/make/item/make32a

inherit ITEM;
    inherit COMBINED;

// º¯Êý£ºµþ¼ÓÉÏÏÞ
//  int get_max_combined() { return 30; }

// º¯Êý£ºÔ­ÁÏÀàÐÍ
int get_stuff_type() { return 146; }

// º¯Êý£º¹¹Ôì´¦Àí
void create()
{
        set_name("Cao Lương");
        set_picid_1(3205);
        set_picid_2(3205);
        set_unit("¸ù");
        set_value(20);
        set_amount(1);
}

// º¯Êý£º»ñÈ¡ÃèÊö
string get_desc() 
{ 
        return "Một loại nông sản."; 
}
