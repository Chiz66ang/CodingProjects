#include <iostream>
#include <string>

using namespace std;

float circle(float rad)
{
	return (rad * rad * 3.141592F);
}

float area(float r, float(*func)(float))
{
	return(*func)(r); //�Լ��� �ּҸ� �ְ� �� �Լ��� r�� �ְ� �����϶�.

}


int main()
{
	//�Լ� ������(function pointer)
	//�Լ��� �̸����� �� �Լ��� �ּҰ� ����ִ�. �ڿ� ��ȣ�� ������ ȣ��, ������ �Լ� �ּ�.
	//�¶��� ���� p.73

	/*
	������(float)�� �Է¹޾Ƽ� ���� ������ ����ϰ� (������*������*3.14)
	�� ���� �����ϴ� �Լ��� �����ϰ�
	�� �Լ� �����͸� �ٸ� �Լ��� �����Ͽ� ���� ������ ����ϴ� ������ �ۼ��غ�����.
	*/

	cout << area(2.5F, circle) << endl;


	return 0;
}