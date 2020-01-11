#pragma once
#include "itemMgr.h"
#include "item.h"// 아까 만들어놨던 item 헤더 불러오기

class ItemMgr
{
	Item itemArr[5];
	int item_cnt = 0; //ItemArr이 채워질 때마다 그 수를 세어주기 위한 용도.

public:
	ItemMgr();
	//파일에서 아이템 정보를 불러와서 출력해주는 것
	int get_count();
	Item* List();
	void print_list(Item* arr, int size);
	Item load_item(int num);
	bool item_add(Item item);
	void print_myitem();
	bool set_use(int num);

};