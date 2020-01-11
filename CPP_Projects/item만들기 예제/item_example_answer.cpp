#include <iostream>
#include <string>
#include <sstream>
#include "itemMgr.h"

using namespace std;

//class를 헤더파일에다가 정의 할 것 (다른 개발자들과 공유할 수 있도록)

enum class MENU {LIST, SELECT, MYITEM, USE, EXIT};

MENU menu() //메뉴를 출력하는 함수
{
	cout << "아이템 리스트(L), 아이템 선택 (S), 보유아이템 보기(M), 아이템 사용(U), 게임 종료(X): ";
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
	cout << "아이템 번호: ";
	int num;
	string line;
	getline(cin, line);
	stringstream(line) >> num;
	return num;
}

int use_select()
{
	cout << "사용할 아이템 번호: ";
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
		//cout << (added ? "저장 성공" : "저장 실패") << endl;
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
		cout << "게임을 종료합니다..." << endl;
		return 0;
		}
	}

	return 0;
}