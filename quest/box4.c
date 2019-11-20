#include <equip.h>

string *FileTable1 = ({
	"cash",
	"cash2",
	"cash3",
	"cash4",
	"cash5",
	"cash6",
	"cash7",
	"cash8",
	"lenhtt",
	"canhtt",
	"ngoctiende",

});

string *FileTable2 = ({
	
        "/item/60/1120",
        "/item/61/1120",
        "/item/65/1120",
        "/item/66/1120",
        "/item/86/1120",
        "/item/87/1120",
        "/item/88/1120",
        "/item/60/2120",
        "/item/61/2120",
        "/item/65/2120",
        "/item/66/2120",
        "/item/86/2120",
        "/item/87/2120",
        "/item/88/2120",
        "/item/60/3120",
        "/item/61/3120",
        "/item/65/3120",
        "/item/66/3120",
        "/item/86/3120",
        "/item/87/3120",
        "/item/88/3120",
        "/item/60/4120",
        "/item/61/4120",
        "/item/65/4120",
        "/item/66/4120",
        "/item/86/4120",
        "/item/87/4120",
        "/item/88/4120",
        "/item/60/5120",
        "/item/61/5120",
        "/item/65/5120",
        "/item/66/5120",
        "/item/86/5120",
        "/item/87/5120",
        "/item/88/5120",
        "/item/60/6120",
        "/item/61/6120",
        "/item/65/6120",
        "/item/66/6120",
        "/item/86/6120",
        "/item/87/6120",
        "/item/88/6120",
        "/item/60/7120",
        "/item/61/7120",
        "/item/65/7120",
        "/item/66/7120",
        "/item/86/7120",
        "/item/87/7120",
        "/item/88/7120",
        "/item/60/1130",
        "/item/65/1130",
        "/item/86/1130",
        "/item/87/1130",
        "/item/88/1130",
        "/item/60/2130",
        "/item/65/2130",
        "/item/86/2130",
        "/item/87/2130",
        "/item/88/2130",
        "/item/60/3130",
        "/item/65/3130",
        "/item/86/3130",
        "/item/87/3130",
        "/item/88/3130",
        "/item/60/4130",
        "/item/65/4130",
        "/item/86/4130",
        "/item/87/4130",
        "/item/88/4130",
        "/item/60/5130",
        "/item/65/5130",
        "/item/86/5130",
        "/item/87/5130",
        "/item/88/5130",
        "/item/60/6130",
        "/item/65/6130",
        "/item/86/6130",
        "/item/87/6130",
        "/item/88/6130",
        "/item/60/7130",
        "/item/65/7130",
        "/item/86/7130",
        "/item/87/7130",
        "/item/88/7130",
        "/item/70/1130",
        "/item/71/1130",
        "/item/72/1130",
        "/item/74/1130",
        "/item/75/1130",
        "/item/76/1130",
        "/item/77/1130",
        "/item/78/1130",
        "/item/79/1130",
        "/item/70/1120",
        "/item/71/1120",
        "/item/72/1120",
        "/item/74/1120",
        "/item/76/1120",
        "/item/75/1120",
        "/item/77/1120",
        "/item/78/1120",
        "/item/79/1120",
});


string *FileTable3 = ({



//	"/item/test2/TuiQuaVoSong",
//	"/item/test2/TuiPhapBao",
	"lenhtt",
	"canhtt",
	"ngoctiende",
	"/item/manhghep/mgphnb",
	"/item/huyetlong/ghep/mg",
	"cash",
	"cash2",
	"cash3",
	"cash4",
	"cash5",
	"cash6",
	"cash7",
	"cash8",

});	

object * get_item()
{
	int i, rand, size;
	string file;
	string * line;
	object * all, item;
	all = ({ });	
	for (i=0;i<3;i++) // 3 món ở bảng 3
	{
	rand = random(sizeof(FileTable3)); 
	file = FileTable3[rand];
	
		if (file=="cash")
		{
		item = new ("/item/std/0001");
		item->set_value(30000);
		}
		else if	(file=="cash2")	{
			item = new ("/item/std/0001");
			item->set_value(50000);
		}
		else if	(file=="cash3")	{
			item = new ("/item/std/0001");
			item->set_value(75000);
		}
		else if	(file=="cash4")	{
			item = new ("/item/std/0001");
			item->set_value(100000);
		}
		else if	(file=="cash5")	{
			item = new ("/item/std/0001");
			item->set_value(200000);
		}
		else if	(file=="cash6")	{
			item = new ("/item/std/0001");
			item->set_value(300000);
		}
		else if	(file=="cash7")	{
			item = new ("/item/std/0001");
			item->set_value(400000);
		}
		else if	(file=="cash8")	{
			item = new ("/item/std/0001");
			item->set_value(500000);
		}
		else if	(file=="lenhtt")	{
			item = new ("/item/nangcap/canhpp/tuilenhtt5");
		}
		else if	(file=="canhtt")	{
			item = new ("/item/nangcap/canhpp/tuicanhtt5");
		}
		else if	(file=="ngoctiende")	{
			item = new ("/item/nangcap/canhpp/tuingoctiende5");
		}
		else {
			item = new (file);
			item->set_amount(2+random(3));	
		}	
	all += ({ item });
	}
/*	line = copy(FileTable2);
	for (i=0;i<1;i++)
	{
		size = sizeof(line);
		file = line[random(size)];
		item = new (file);
		all += ({ item });
		line -= ({ file });
		if (item->get_equip_type()>0 && item->get_equip_type()!=HAND_TYPE)
		{
			"/sys/item/equip"->init_equip_prop_3(item);
			"/sys/item/equip"->init_equip_prop_5(item);
			"/sys/item/equip"->init_equip_prop_5(item);
			"/sys/item/equip"->init_equip_prop_5(item);
			"/sys/item/equip"->init_equip_prop_5(item);
			"/sys/item/equip"->init_equip_prop_5(item);
			"/sys/item/equip"->init_equip_prop_5(item);
			item->set_item_color(2);
			item->set_hide(0);
			item->set("forge", "111111");
		}		
	}*/
//	line = copy(FileTable1);
	for (i=0;i<5;i++) // 5 món ở bảng 1
	{
		rand = random(sizeof(FileTable1));
		file = FileTable1[rand];

//		size = sizeof(line);
//		file = line[random(size)];
		if (file=="cash")
		{
		item = new ("/item/std/0001");
		item->set_value(30000);
		}
		else if	(file=="cash2")	{
			item = new ("/item/std/0001");
			item->set_value(50000);
		}
		else if	(file=="cash3")	{
			item = new ("/item/std/0001");
			item->set_value(75000);
		}
		else if	(file=="cash4")	{
			item = new ("/item/std/0001");
			item->set_value(100000);
		}
		else if	(file=="cash5")	{
			item = new ("/item/std/0001");
			item->set_value(200000);
		}
		else if	(file=="cash6")	{
			item = new ("/item/std/0001");
			item->set_value(300000);
		}
		else if	(file=="cash7")	{
			item = new ("/item/std/0001");
			item->set_value(400000);
		}
		else if	(file=="cash8")	{
			item = new ("/item/std/0001");
			item->set_value(500000);
		} 
		else if	(file=="lenhtt")	{
			item = new ("/item/nangcap/canhpp/tuilenhtt5");
		}
		else if	(file=="canhtt")	{
			item = new ("/item/nangcap/canhpp/tuicanhtt5");
		}
		else if	(file=="ngoctiende")	{
			item = new ("/item/nangcap/canhpp/tuingoctiende5");
		}
		else	
		{		
			item = new (file);
			item->set_amount(1+random(2));
		}		
		all += ({ item });
	//	line -= ({ file });
	}	
	return all;
}

void check_item()
{
	int i, size;
	size = sizeof(FileTable1);
	for (i = 0;i<size;i++)
	{
		if (FileTable1[i]=="cash") continue;
		if(!load_object(FileTable1[i]))
		{
			log_file("test.dat", FileTable1[i]+" error\n");
		}
	}
/*	size = sizeof(FileTable2);
	for (i = 0;i<size;i++)
	{
		if (FileTable2[i]=="cash") continue;
		if(!load_object(FileTable2[i]))
		{
			log_file("test.dat", FileTable2[i]+" error\n");
		}
	}*/
	size = sizeof(FileTable3);
	for (i = 0;i<size;i++)
	{
		if (FileTable3[i]=="cash") continue;
		if(!load_object(FileTable3[i]))
		{
			log_file("test.dat", FileTable3[i]+" error\n");
		}
	}		
}