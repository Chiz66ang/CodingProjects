#pragma once
#include "item.h"

class FileIO
{
	string filepath = "D:\\test\\item.txt";
public:
	FileIO();
	//피알에서 아이템 정보를 로드하고 Item* 형으로 리턴한다.
	Item* loadItemAll();
	int get_count();
	Item load_item(int num);
};