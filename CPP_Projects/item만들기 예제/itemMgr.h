#pragma once
#include "itemMgr.h"
#include "item.h"// �Ʊ� �������� item ��� �ҷ�����

class ItemMgr
{
	Item itemArr[5];
	int item_cnt = 0; //ItemArr�� ä���� ������ �� ���� �����ֱ� ���� �뵵.

public:
	ItemMgr();
	//���Ͽ��� ������ ������ �ҷ��ͼ� ������ִ� ��
	int get_count();
	Item* List();
	void print_list(Item* arr, int size);
	Item load_item(int num);
	bool item_add(Item item);
	void print_myitem();
	bool set_use(int num);

};