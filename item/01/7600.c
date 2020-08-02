inherit ITEM;

#define ZG_DICTIONARY "/quest/zg_dict"
#define _DEBUG(str) ;

int is_usable()
{
    return 1;
}

void create()
{
    set_name("Chiến Quốc Bảo Điển");

    set_picid_1(1017);
    set_picid_2(1017);

    set_value(0);

    set_no_give(1);
    set_no_sell(1);
}

string get_desc()
{
    return "Tương truyền trong bảo điển ghi lại những nơi có thể rèn luyện theo từng cấp độ.\n Mỗi lần tăng 1 cấp "
           "người chơi còn được nhận 1 lần quay xổ số may mắn, nhưng nếu bỏ qua cơ hội này thì sẽ không thể nhận lại "
           "nữa.";
}

int get_use_effect(object me)
{
    return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
    ZG_DICTIONARY->search_in_user(me);
}
