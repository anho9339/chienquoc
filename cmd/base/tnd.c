#include <cmd.h>

int main(object me, string arg) {
      if( is_player(me) )
        {
                notify( "Bạn không đủ quyền." );
		return 1;
        }
		
    int skillid = to_int(arg), p;
    object item;
    if (is_player(me)) return 1;
    if (!"quest/pet"->get_skill_desc(skillid)) return 1;
    if (skillid >= 74201) {
        item = new("/item/44/4489");
    }
    else item = new("/item/44/4488");
    if (item) {
        item->set("special", sprintf("%d", skillid));
        p = item->move2(me, -1);
        item->add_to_user(p);
    }
    return 1;
} 