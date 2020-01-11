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
	ifstream fin(filepath); //�޸����� ��
	if (!fin.is_open())
	{
		cerr << "���� ���� ����" << endl;
		throw exception("���� ���� ����"); //return ���� �� �� ���� ������ try catch��
	}
	//���Ͽ� ������ ����Ǿ� �ִ��� Ȯ���Ѵ�.(get_count�Լ�)
	int cnt = this->get_count();
	Item* arr = new Item[cnt];
	
	string line;
	stringstream ss;
	for(int i = 0; !fin.eof(); i++)
	{
		getline(fin, line);
		// �� ���� �о Item ��ü ����, �迭�� ����.
		ss.str(line);
		ss >> arr[i].num >> arr[i].title >> arr[i].power >> arr[i].maxuse >> arr[i].curuse;
		ss.clear();
	}
	//delete[] arr;
	return arr;
}

int FileIO::get_count()//���Ͽ� �� ���� �ִ��� ���� �Լ�.
{
	ifstream fin(filepath);
	if (!fin.is_open())
	{
		throw exception("���� ���� ����");
	}
	string line;
	int cnt = 0;
	while (!fin.eof())
	{
		getline(fin, line);
		if (line.length() == 0) break; //������ ���� ���. line�� ���̰� 0 (�ƹ��͵� ���� ��)�̶�� �ǳʶٰ� �ٽ� ������.break���� ����.
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
		cerr << "���� ���� ����" << endl;
		throw exception("���� ���� ����");
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
	throw exception("�ش� ��ȣ�� ��ġ�ϴ� �������� �����ϴ�");
}
