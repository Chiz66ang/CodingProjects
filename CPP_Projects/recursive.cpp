#include <iostream>

using namespace std;

void print(int a)
{

	if (a < 1) return;
	cout << a << " ";
	print(--a);

	//���ѷ����� �� �� �ֱ� ������, Ż�� ������ �־���Ѵ�.
}

int add(int b)
{
	{
		if (b > 10) return 0; //return 0�� �����ٴ� ��.
		b += add(b+1);
	}
	return b;
}

int sum(int i)
{//������ ����
	if (i < 10) return i + sum(i + 1);
	else return i;
}

int main()
{

	//��� ȣ��, Self invocation, Recursive Call
	//print(10); // 10~1���� ��µǰ� �Ѵ�.
	

	//1�� �����ϸ� 1~10�� �ջ��Ͽ� �� ����� �����ϴ� ���. 
	
	cout << add(1) << " ";





	return 0;
}