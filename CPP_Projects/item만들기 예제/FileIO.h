#pragma once
#include "item.h"

class FileIO
{
	string filepath = "D:\\test\\item.txt";
public:
	FileIO();
	//�Ǿ˿��� ������ ������ �ε��ϰ� Item* ������ �����Ѵ�.
	Item* loadItemAll();
	int get_count();
	Item load_item(int num);
};