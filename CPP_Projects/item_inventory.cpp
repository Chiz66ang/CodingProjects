#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


class Item
{
public:
	int num; //������ ��ȣ
	string name; //������ �̸�
	float power; //������ �Ŀ�
	int use_max; //�ִ� ��� Ƚ��
	int use_now;//���� ��� Ƚ��
	

	Item() {}
	Item(int num, string name, float power, int max, int now) : num(num), name(name), power(power), use_max(max), use_now(now) {}
	
};

Item* it = new Item[5];

void see_list()
{
	cout << "��ȣ" << "\t" << "�̸�" << "\t" << "�Ŀ�" << "\t" << "�ִ� Ƚ��" << "\t" << "���� Ƚ��" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << it[i].num << "\t" << it[i].name << "\t" << it[i].power << "\t" << it[i].use_max << "\t" << it[i].use_now << endl;
	}
}


int main()
{
	//10���� ���� item inventory �����

	
	ifstream itemfile ("D:\\test\\item.txt");

	if (!itemfile.is_open())
	{
		cout << "���� ���� ����" << endl;
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
		cout << "������ ����Ʈ (L)" << endl << "������ ����(I)" << endl << "������ ������ ����(S)" << endl << "������ ��� (U)" <<endl<< "���� ���� (X)" << endl;
		string input;
		cin >> input;
		if (input == "L" || input == "��")
		{
			see_list();
		}
		else if (input == "I"|| input == "i")
		{
			cout << "���� �� �����Ͻ� �������� ��ȣ�� �Է����ּ���" << endl;
			see_list();
			cout << "��ȣ: ";
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

			cout << "������ ��������: " << pi->name << endl;
		}
		else if (input == "S"|| input == "s")
		{
			cout << "������ ��������: " << pi->name << endl;
		}
		else if (input == "U" || input == "u")
		{
			if (pi->use_now < pi->use_max)
			{
				pi->use_now++;
				cout << "��� Ƚ��: " << pi->use_now << "\t" << "�ִ� Ƚ��: " << pi->use_max << "\t" << "���� Ƚ��: " << pi->use_max - pi->use_now << endl;
			}
			else
			{
				cout << "�� �̻� �������� ����� �� �����ϴ�" << endl;
				break;
			}
			
		}
		else if (input == "X" || input == "x")
		{
			cout << "������ �����մϴ�..." << endl;
			return 1;
		}
		else
		{
			cout << "�޴��� ��õ� ���ĺ��� �Է����ּ���" << endl; 
			continue;
		}
	}
	cout << "������ �����մϴ�..." << endl;
	return 0;
}