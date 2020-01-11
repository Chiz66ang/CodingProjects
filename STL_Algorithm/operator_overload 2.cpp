#include <iostream>

using namespace std;

struct Vector2D
{//ũ��� ������ ���ÿ� ǥ���ϴ� ������ (�ϳ��� ũ��, �ϳ��� ����)
	//ũ�⸸ �ִ� �������� ��Į�� ���̶�� �Ѵ�. (e.g. �µ�)
	float x, y;
	Vector2D (){}
	Vector2D(float x, float y) : x(x), y(y) {}

	//���� ������(+)�� �����ε��Ͽ� ���� ������ �����ϰ� ��
	Vector2D operator+ (Vector2D& other)
	{
		return Vector2D(x + other.x, y + other.y);
		
	}

	void print()
	{
		cout << "x(" << x << ") y(" << y << ")" << endl;
	}
};

int main()
{
	//������ �����ε� (Operator Overload)
	/*
	�� ���� �����ϴ� �����ڸ� �����ڰ� �ٽ� �����Ͽ� �ٸ� �ǹ̷� ����ϴ� ��.
	*/

	Vector2D v1(2, 3);
	Vector2D v2(4, 6);

	//Vector2D v3(v1.x + v2.x, v1.y + v2.y);
	Vector2D v3 = v1 + v2; //�̰��� �ǰ� �Ϸ��� +�� ���Ǹ� �������ؾ��Ѵ�.
	//v1�� + �������� �����̰�, v2�� �Ķ���ͷ� ���� ���̴�.
	v3.print();

}
