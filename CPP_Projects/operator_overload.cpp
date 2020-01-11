#include <iostream>

using namespace std;

struct Vector2D
{
	float x, y;

	Vector2D(float x, float y) : x(x), y(y)
	{
		cout << "���� ����" << endl;
	}

	void print_vector()
	{
		cout << "x(" << x << "), y(" << y << ")" << endl;
	}

	//���� ���Ϳ� �ܺο��� ���޵� ���͸� �����Ͽ�
	//���ο� ���͸� �����س��� ����� �Լ��� �����غ�����.

	Vector2D add_vector(Vector2D* v2)
	{
		return Vector2D(x + v2->x, y + v2->y);
	}

	Vector2D operator+(const Vector2D& v2) //������ �����ε� //�����ڸ� �������ϰڴ�.
		//Vector2D&��� ���� v2�� ��������. Call by reference�� �Լ��� ȣ���ϰڴٴ� ��.
		//cpp������ �����͸� ���´�� �̰� ����.
		//v2�� ���� �Ժη� �ٲ��� �ʱ� ���� const �� �ٿ��ش�. �̷��� ���� ��Ȳ���� �� ��.
	const {
		return Vector2D(x + v2.x, y + v2.y);
	} //��� �Լ�. �ɹ� �����͸� �ٲ��� ���ϵ��� �������ִ� ��.

	//������ �����п� float ���� ���� �����ִ� �Լ��� 
	//������ �����ε� ������� �����غ�����.
	//�� ������͸� �����Ѵ�.

	Vector2D operator*(float value)
	{
		return Vector2D(x * value, y * value);
	}


};

int main()
{
	//������ �����ε� (Operator Overload)
	Vector2D v1(3, 5);
	Vector2D v2(5, 8);

	//������ ����
	//Vector2D res(v1.x + v2.x, v1.y + v2.y); //���ͳ����� ���� --> class(������ struct) �ȿ� ����ְ� �ʹ�.
	//�� �ٸ� ���
	//Vector2D res = v1.add_vector (&v2); 

	//������ �����ε带 �̿��� ���
	Vector2D res = v1 + v2; //�Լ� ȣ��� ����. v1.operator+(v2); ���⼭ operator�� ��ȣ�� ���� ��.

	res.print_vector();


	return 0;
}