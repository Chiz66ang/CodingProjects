#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Member
{
	int num;
	string name;
	Member() {}
	Member(int num, string name) : num(num), name(name) {}

	void print()
	{
		cout << num << "\t" << name << endl;
	}

};

int main()
{
	//�˻� �˰��� (�����˻�, �����˻�)
	//�����˻�: �迭�� ù ���Һ���, ������ ���ұ��� �񱳰˻��ϴ� ���
	//�����˻�: ���ĵ� �迭�� ������� ���ݾ� ������ �˻� (���ɸ鿡�� �� ����)

	/*Member ��ü (��ȣ, �̸�)�� 5�� ������ �迭�� �غ�.
	//ȸ���� ��ȣ�� ���������� �˻��Ͽ� �˻��� ȸ���� ������ ǥ��
	//�˻��� �� ���, ������ ��� �����. 

	Member mem[5];
	mem[0] = { 1, "����" };
	mem[1] = { 2, "����" };
	mem[2] = { 3, "����" };
	mem[3] = { 4, "����" };
	mem[4] = { 5, "���" };

	for (int i = 0; i < 5; i++) //���� �˻� (���ʿ� �ִ� �����͸� �˻��� ���� �ð��� ���� �ɸ�����)
	{
		if (mem[i].num = 3)
		{
			mem[i].print();
			break;
		}
	}

	//���� �˻�
	//���� �� �������� �߰� �� ���ϱ�. (�ǳ��� ��ȣ - ��ù�� ��ȣ)/2 + ��ù�� ��ȣ
	�Ʒ� ���� ����
	*/

	/*
		Member ��ü�� 20�� ������ �� ��ȣ, �̸��� �ߺ����� �ʵ��� �����ϰ�
		������ �Ŀ��� ��ȣ�� �����Ͽ� �����˻��� �����Ѵ�.
		��ȣ�� 11~30���� �����ϰ� �̸��� ���������� ���Ͽ� ���ĺ����� �����Ͽ� ����Ѵ�.
		(atoi, itoa ���)
		char c = 65;
		cout << c << endl; �̷��� �ص� �ȴ�
	*/
	//�ߺ����� ���� �� ����
	Member mem[20];
	srand(time(0));
	int i = 0;
	int rd = 0;

	outer_loop:
	while (i < 20) //for(int i =0; i <20; i++)
	{
		rd = rand()% 20 + 11;
			for (int j = 0; j <= i; j++)
			{
			if (mem[j].num == rd)
				goto outer_loop;
			}
		mem[i++].num = rd;
		//c = rd + 54; //�ƽ�Ű �ڵ�� 65 -91���� (�빮�� ����)
		//mem[i++].name = c;
	}

	outer_loop2:
	for (int idx = 0; idx < 20;)
	{
		string _name;
		_name += (char)(rand() % 26 + 65);

		for (int j = 0; j < idx; j++)
		{
		if (mem[j].name == _name)
			goto outer_loop2;
		}
		mem[idx++].name = _name;
	}
	
	
	//��ȣ�� ����
	Member mp;
	for (int i = 1; i < sizeof(mem) / sizeof(Member); i++) 
	{
		int temp = mem[i].num; 
		Member mp = mem[i];
		int idx = i; 
		for (int j = i - 1; mem[j].num > temp && j >= 0; j--)
		{
			mem[idx--] = mem[j]; 
			mem[j] = mp;
		}
	}


	for (int i = 0; i < 20; i++)
	{
		mem[i].print();
	}
	
	//���� �˻�
	int mid = 0;
	int begin = 0;
	int end = (sizeof(mem) / sizeof(Member)-1);
	int target = 27;

	bool found = false;

	
	while (begin <= end) //���ݾ� ������ ���۰� ���� ��������. //while (1)�� �ص� �ȴ�.
	{
		mid = (end - begin) / 2 + begin;
		if (mem[mid].num == target)
		{
			cout << target << "�� ��ġ: " << mid << endl;
			mem[mid].print();
			found = true;
			break;
		}
		else if (mem[mid].num > target)
		{
			end = (mid - 1);
		}
		else if (mem[mid].num < target)
		{
			begin = (mid + 1);
		}
	}

	return 0;
}