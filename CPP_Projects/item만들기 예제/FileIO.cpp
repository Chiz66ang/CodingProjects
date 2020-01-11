#include "FileIO.h"
#include "item.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

FileIO::FileIO()
{
}

Item * FileIO::loadItemAll()
{
	ifstream fin(filepath); //메모장을 염
	if (!fin.is_open())
	{
		cerr << "파일 열기 실패" << endl;
		throw exception("파일 열기 실패"); //return 값을 줄 수 없기 때문에 try catch로
	}
	//파일에 몇행이 저장되어 있는지 확인한다.(get_count함수)
	int cnt = this->get_count();
	Item* arr = new Item[cnt];
	
	string line;
	stringstream ss;
	for(int i = 0; !fin.eof(); i++)
	{
		getline(fin, line);
		// 한 행을 읽어서 Item 객체 생성, 배열에 저장.
		ss.str(line);
		ss >> arr[i].num >> arr[i].title >> arr[i].power >> arr[i].maxuse >> arr[i].curuse;
		ss.clear();
	}
	//delete[] arr;
	return arr;
}

int FileIO::get_count()//파일에 몇 행이 있는지 세는 함수.
{
	ifstream fin(filepath);
	if (!fin.is_open())
	{
		throw exception("파일 열기 실패");
	}
	string line;
	int cnt = 0;
	while (!fin.eof())
	{
		getline(fin, line);
		if (line.length() == 0) break; //공란이 있을 경우. line의 길이가 0 (아무것도 없는 행)이라면 건너뛰고 다시 돌린다.break여도 가능.
		cnt++;
	}
	fin.close();

	return cnt;
}

Item FileIO::load_item(int num)
{
	ifstream fin(filepath); 
	if (!fin.is_open())
	{
		cerr << "파일 열기 실패" << endl;
		throw exception("파일 열기 실패");
	}
	string line;
	stringstream ss;
	Item item;
	int n;
	for (int i = 0; !fin.eof(); i++)
	{
		getline(fin, line);
		ss.str(line);
		ss >> n;
		if (n == num)
		{
			item.num = n;
			ss >> item.title >> item.power >> item.maxuse >> item.curuse;
			fin.close();
			return item;
		}
		ss.clear();
	}
	throw exception("해당 번호와 일치하는 아이템이 없습니다");
}
