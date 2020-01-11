#include <iostream>

using namespace std;

template<typename T> //template (�Ʒ��� ��¥ �ڷ����̴�) <typename T> ���� �ڷ����� T��� �����ϰڴ�. typename�� T��� ���� ���� ����ȭ �Ǿ��ִ�.
class Vector2D //���� �������� ���� class template�� �Ǿ���.
{
	T x, y;

public:
	Vector2D(){}
	Vector2D(T x, T y): x(x), y(y) {}

	void printVector()
	{
		cout << "x: " << x << " , y: " << y << endl;
	}
};

template<typename T>
class Dynamicarray
{

	T* arry; //�迭�� ����
	T count; 
	T index; //���� ���ִ� ���� ����� �����ִ� ����


public:
	Dynamicarray()
	{
		arry = new T[5];
		count = 5;
		index = 0;
	}
	~Dynamicarray() { delete[]arry; }
	
	

	void add(T value) //�� �濡 ���� �Ҵ��ϴ� �Լ�
	{
		if (index == count) //���� �� 5���� ��� ã�ٸ�
		{
			T* p = new T[count + 5];

			for (int i = 0; i < count; i++)
			{
				p[i] = arry[i]; //�о��� ������ ������ �Űܿ���
			}
			count += 5;
			delete[] arry;
			arry = p; //�ּҸ� �Űܿ���
		}
		arry[index++] = value; //���� ���� ���� �ڵ������� ���� ���濡 ����.
	}

	void print_elem()
	{
		for (int i = 0; i < index; i++)
		{
			cout << arry[i] << endl;
		}

	}
};

int main()
{
	//Template(Ŭ���� ���ø�): ��Ʋ, ��Ǫ��, ��Ʋ
	//Ŭ������ ���� Ʋ�� �����. 
	//�ڷ����� ������ �ʰ�, �ʿ��� �� �ڷ����� ������ Ŭ������ ������ ��.

	//Vector2D<float> v(2.4F, 3.8F); //Vector2D�� Ʋ�� �� <float>��� �ڷ����� �� Ŭ������ ����� ��üv�� �����.
	//v.printVector();

	//Vector2D<double> v2(2.1234567, 3.7654321); //Vector2D�� Ʋ�� �� <double>�̶�� �ڷ����� �� Ŭ������ ����� ��üv2�� �����.
	//v2.printVector();

	//Vector2D<int> v3(3, 5);
	//v3.printVector();

	/*Template ����
	 ����, �Ǽ� �ڷ����� �����͸� �󸶵��� ���� ������ �� �� �ִ� (�迭, �����Ҵ�)
	 �ڷᱸ���� �����Ѵ�.
	 print()�Լ��� �����ϰ� �ش� �ڷᱸ�� �ȿ� ����� ��� �����͸� ȭ�鿡 ǥ���ϴ� ��ɵ� �ۼ��غ�����.
	*/

	Dynamicarray<int> di;
	di.add(1);
	di.add(2);
	di.add(3);
	di.add(4);
	di.add(5);
	di.add(6);
	di.add(283);
	di.print_elem();
	



	return 0;
}