#pragma once
#include <string>

using namespace std;

class Item
{
public:
	int num;
	string title;
	int power;
	int maxuse;
	int curuse;
	bool inuse;

	Item();
	Item(int name, string title, int power, int maxuse, int curuse); //����� �ٵ� �и�. Item�� �ʷ� ���ٿ� Ŀ���� �뼭 ��ũ�� ������ �����ڸ� ���� ���Ǹ� ���ش�.
	//��� ���Ͽ��� Ŭ������ ���� (������ �պκи�)
	//�ҽ� ���Ͽ��� ������� ��ū Ŭ������ ���� (������ �ʱ�ȭ)


};