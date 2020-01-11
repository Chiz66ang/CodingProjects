#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


class Item
{
public:
	int num; //아이템 번호
	string name; //아이템 이름
	float power; //아이템 파워
	int use_max; //최대 사용 횟수
	int use_now;//현재 사용 횟수
	

	Item() {}
	Item(int num, string name, float power, int max, int now) : num(num), name(name), power(power), use_max(max), use_now(now) {}
	
};

Item* it = new Item[5];

void see_list()
{
	cout << "번호" << "\t" << "이름" << "\t" << "파워" << "\t" << "최대 횟수" << "\t" << "현재 횟수" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << it[i].num << "\t" << it[i].name << "\t" << it[i].power << "\t" << it[i].use_max << "\t" << it[i].use_now << endl;
	}
}


int main()
{
	//10일차 예제 item inventory 만들기

	
	ifstream itemfile ("D:\\test\\item.txt");

	if (!itemfile.is_open())
	{
		cout << "파일 열기 실패" << endl;
		return 1;
	}

	string line;
	stringstream ss;
	Item* pi;

	while (itemfile.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
		getline(itemfile, line);
		ss.str(line);
		ss >> it[i].num >> it[i].name >> it[i].power >> it[i].use_max >> it[i].use_now;
		ss.clear();
		}
		itemfile.close();
	}
	while (1)
	{
		cout << "아이템 리스트 (L)" << endl << "아이템 보유(I)" << endl << "보유한 아이템 보기(S)" << endl << "아이템 사용 (U)" <<endl<< "게임 종료 (X)" << endl;
		string input;
		cin >> input;
		if (input == "L" || input == "ㅣ")
		{
			see_list();
		}
		else if (input == "I"|| input == "i")
		{
			cout << "다음 중 보유하실 아이템의 번호를 입력해주세요" << endl;
			see_list();
			cout << "번호: ";
			int a;
			cin >> a;
			

			for (int i = 0; i < 5; i++)
			{
				if (it[i].num == a)
				{
					pi = it + i;
					break;
				}
			}

			cout << "보유한 아이템은: " << pi->name << endl;
		}
		else if (input == "S"|| input == "s")
		{
			cout << "보유한 아이템은: " << pi->name << endl;
		}
		else if (input == "U" || input == "u")
		{
			if (pi->use_now < pi->use_max)
			{
				pi->use_now++;
				cout << "사용 횟수: " << pi->use_now << "\t" << "최대 횟수: " << pi->use_max << "\t" << "남은 횟수: " << pi->use_max - pi->use_now << endl;
			}
			else
			{
				cout << "더 이상 아이템을 사용할 수 없습니다" << endl;
				break;
			}
			
		}
		else if (input == "X" || input == "x")
		{
			cout << "게임을 종료합니다..." << endl;
			return 1;
		}
		else
		{
			cout << "메뉴에 명시된 알파벳을 입력해주세요" << endl; 
			continue;
		}
	}
	cout << "게임을 종료합니다..." << endl;
	return 0;
}