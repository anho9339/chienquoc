2
// �Զ����ɣ�/make/item/make32a

inherit ITEM;
    inherit COMBINED;

// ��������������
//  int get_max_combined() { return 30; }

// ������ԭ������
int get_stuff_type() { return 146; }

// ���������촦��
void create()
{
        set_name("Cao L??ng");
        set_picid_1(3205);
        set_picid_2(3205);
        set_unit("��");
        set_value(20);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "M?t lo?i n?ng s?n."; 
}
