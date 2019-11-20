#include <effect.h>
#include <skill.h>
#include <ansi.h>
#include <item.h>
#include <equip.h>

// 函数：生成二进制码
void SAVE_BINARY() { }

string get_random_itemchoden()
{
	switch( random(4) )
		                {
						case 0 : return sprintf("/pretkuzl/choden/vsdpban"); break;
						case 1 : return sprintf("/pretkuzl/choden/huyenbangnhan"); break;
						case 2 : return sprintf("/pretkuzl/choden/knb10"); break;
						case 3 : return sprintf("/pretkuzl/choden/0032"); break;
		                }
}
