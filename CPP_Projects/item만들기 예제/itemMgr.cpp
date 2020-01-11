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
	//���Ͽ��� ������������ �ε��Ͽ� Item �迭�� �����Ѵ�.
	//File IO ����� �䱸�� (File IO Ŭ����)
	FileIO io;
	//int cnt = io.get_count();
	//cout << "������ ��: " << cnt << endl;
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
	cout << "    **���� ���� ���� ������ ����**" << endl;
	for (int i = 0; i < item_cnt; i++)
	{
		cout << itemArr[i].num << "\t" << itemArr[i].title << "\t" << itemArr[i].power << "\t" << itemArr[i].maxuse << "\t" << itemArr[i].curuse 
			<< "\t" << (itemArr[i].inuse ? "�����": "") << endl;
	}
}

bool ItemMgr::set_use(int num)
{
	for (int i = 0; i < item_cnt; i++)
	{
		if(itemArr[i].num == num) 
		{
			if (itemArr[i].maxuse == itemArr->curuse) {
				cout << "��� Ƚ�� �ʰ��� �� �̻� ����� �� �����ϴ�." << endl;
				return false;
		}
			itemArr[i].inuse = true;
			itemArr[i].curuse++;
			return true;
		}
	}
	return false;
}
