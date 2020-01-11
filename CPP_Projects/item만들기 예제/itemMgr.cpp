#include "itemMgr.h"
#include <iostream>
#include "FileIO.h"

ItemMgr::ItemMgr()
{
}

int ItemMgr::get_count()
{
	return FileIO().get_count();
}

Item* ItemMgr::List()
{
	//파일에서 아이템정보를 로드하여 Item 배열을 리턴한다.
	//File IO 기능이 요구됨 (File IO 클래서)
	FileIO io;
	//int cnt = io.get_count();
	//cout << "아이템 수: " << cnt << endl;
	Item*arr = io.loadItemAll();
	return arr;
}

void ItemMgr::print_list(Item * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i].num << "\t" << arr[i].title << "\t" << arr[i].power << "\t" << arr[i].maxuse << "\t" << arr[i].curuse << endl;
	}
	delete[] arr;
}

Item ItemMgr::load_item(int num)
{
	FileIO io;
	Item item = io.load_item(num);
	return item;
}

bool ItemMgr::item_add(Item item)
{
	bool flag = false;
	if (item_cnt < 5)
	{
		itemArr[item_cnt++] = item;
		flag = true;
	}
	return flag;
}

void ItemMgr::print_myitem()
{
	cout << "    **현재 보유 중인 아이템 정보**" << endl;
	for (int i = 0; i < item_cnt; i++)
	{
		cout << itemArr[i].num << "\t" << itemArr[i].title << "\t" << itemArr[i].power << "\t" << itemArr[i].maxuse << "\t" << itemArr[i].curuse 
			<< "\t" << (itemArr[i].inuse ? "사용중": "") << endl;
	}
}

bool ItemMgr::set_use(int num)
{
	for (int i = 0; i < item_cnt; i++)
	{
		if(itemArr[i].num == num) 
		{
			if (itemArr[i].maxuse == itemArr->curuse) {
				cout << "사용 횟수 초과로 더 이상 사용할 수 없습니다." << endl;
				return false;
		}
			itemArr[i].inuse = true;
			itemArr[i].curuse++;
			return true;
		}
	}
	return false;
}
