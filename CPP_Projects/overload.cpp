#include <iostream>

using namespace std;

class Math
{
public:
	//�ν��Ͻ� �޼ҵ�(Instance Method)
	void add(int a, int b)
	{
		cout << a << " + " << b << " = " << a + b << endl;
	}

	void add(float a, float b)
	{
		cout << a << " + " << b << " = " << a + b << endl;
	}
};


int main()
{
	/*�Լ� �����ε� (�ߺ�����)
	��ü���� ������ �� ������ �̸��� ������ �Լ��� �ټ��� ���� �� �� �ִ�.
	�� �� ���Ѿ� �� ������ �˾ƾ� �Ѵ�.*/

	Math math;
	math.add(3, 5);
	math.add(3.14F, 5.0F);

	return 0;
}