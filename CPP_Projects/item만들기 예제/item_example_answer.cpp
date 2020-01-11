#include <iostream>
#include <string>
#include <sstream>
#include "itemMgr.h"

using namespace std;

//class�� ������Ͽ��ٰ� ���� �� �� (�ٸ� �����ڵ�� ������ �� �ֵ���)

enum class MENU {LIST, SELECT, MYITEM, USE, EXIT};

MENU menu() //�޴��� ����ϴ� �Լ�
{
	cout << "������ ����Ʈ(L), ������ ���� (S), ���������� ����(M), ������ ���(U), ���� ����(X): ";
	string input;
	getline(cin, input);

	MENU menu;
	if (input == "L" || input == "l")	  menu = MENU::LIST;
	else if (input == "S"|| input == "s") menu = MENU::SELECT;
	else if (input == "M"||input == "m")  menu = MENU::MYITEM;
	else if (input == "U" || input == "u") menu = MENU::USE;
	else if (input == "X" || input == "x") menu = MENU::EXIT;
	return menu;
}

int select()
{
	cout << "������ ��ȣ: ";
	int num;
	string line;
	getline(cin, line);
	stringstream(line) >> num;
	return num;
}

int use_select()
{
	cout << "����� ������ ��ȣ: ";
	int num;
	string line;
	getline(cin, line);
	stringstream(line) >> num;
	return num;
}


int main()
{
	MENU m;
	ItemMgr mgr;
	Item item;
	bool added = false;

	while (true) 
	{
		m = menu();
	switch (m)
	{
	case MENU::LIST:
		mgr.print_list(mgr.List(), mgr.get_count());
		break;
	case MENU::SELECT:
		added = mgr.item_add(mgr.load_item(select()));
		//cout << (added ? "���� ����" : "���� ����") << endl;
		mgr.print_myitem();
		break;
	case MENU::MYITEM:
		mgr.print_myitem();
		break;
	case MENU::USE:
		mgr.print_myitem();
		mgr.set_use(use_select());
		break;
	case MENU::EXIT:
		cout << "������ �����մϴ�..." << endl;
		return 0;
		}
	}

	return 0;
}