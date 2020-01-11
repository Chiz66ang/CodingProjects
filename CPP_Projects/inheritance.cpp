#include <iostream>

using namespace std;

class Shape
{
public:

	float width, height;

	Shape() {}
	Shape (float width, float height): width(width), height(height) {}

	virtual void printShape() //���� �Լ��� �������� (���¼� ġ�� ��)
	{
		cout << "width: " << width << ", height: " << height << endl;
	}

	virtual float get_area() = 0; //�Ϻη� ���� ���� �Լ��� ������� {return 0.0F}�� �����ϰ� �ִٰ� �����ϸ� ��
	//� �������� �𸣰� ���̸� ���� �� ������, �ƹ��͵� �������� �ʴ� �Լ��� �ۼ��� �ڳ��Լ����� override ���ش�.
	//���� �����Լ� (���� ����� 1�� ���� �Լ�)
	//���� �����Լ��� ������ �ִ� class�� �̿ϼ��̱� ������ Shape ��ü�� ���� �� ����. 
};//parent class, super class 

class Triangle : public Shape //shape�� ���Ѿ���(public) ��ӹ޴´�. Shape�� �ɹ����� ��� ���´�. (private���� �ϸ� private���� �ްڴ�)
	//public �θ��Լ��� ������ ���� private�� �κ��� private���� public�� �κ��� public���� ��������, private���� �����Ѵٸ� ��� private���� �������� ���̴�.
{
	//��� �ɹ��� �Ȱ��� �´�. (������ ����: �����ڴ� �ɹ��� �ƴϴ�)
	//�����ڰ� �����ڸ� �������� �ʾұ� ������ �⺻ �����ڰ� �ִ� ���̳� ���������̴�.
public:
	Triangle() {}
	Triangle(float width, float height): Shape(width, height) {} //�θ��� �����ڸ� ������ ����
	
	void printShape()
	{ //Override : �θ�Ŭ������ �Լ��� �ڽ��� ��� �޾� ����� �����ϴ� ��.
		cout << "�ﰢ�� ����: " << endl;
		//Shape::printShape(); // �Ʒ��� ���� �θ𿡰� �״�� ������ �θ� �ִ� �Լ��� �ҷ����� ���� �ĸ� �߰��Ѵ�.
		cout << "width: " << width << ", height: " << height << endl;
	}

	float get_area()
	{
		return width * height / 2.0F;
	}
};//child class, sub class

//�簢�� Ŭ������ ������ �� ShapeŬ������ ����غ�����.
class Rect : public Shape
{
public:
	Rect(){}
	Rect(float width, float height): Shape(width, height) {}


	void printShape()
	{ //Override : �θ�Ŭ������ �Լ��� �ڽ��� ��� �޾� ����� �����ϴ� ��.
		cout << "�簢�� ����: " << endl;
		Shape::printShape();
		//cout << "width: " << width << ", height: " << height << endl;
	}


	float get_area()
	{
		return width * height;
	}
};

int main()
{
	/*��� (Inheritance)
	��ü�������� 3�� Ư¡: ��Ӽ�, ������, ���м�
	
	
	Shape s1(3.5F, 4.2F); //���� �����Լ��� �����ϰ� �ֱ� ������ Shape s1 (�߻� Ŭ����) ������ ����. 
	s1.printShape();

	Triangle t;
	t.width = 3.5F;
	t.height = 4.2F;
	t.printShape();
	*/

	Triangle t(3.5F, 4.2F);
	//t.printShape();
	
	Rect r(3.5F, 4.2F);
	//r.printShape();
	//���� �θ� �Լ��� ������ �޾����� �� �ڳ� �Լ����� �ٸ� Ư¡�� �������־� �̰��� ������� �� �ٸ� Ư���� ���´�.
	//�̰��� ����, override ��� �Ѵ�. (������:polymorphism)

	//������ �������� ������ ���� �迭�� ������־�� �ϴµ� �ڷ����� Ʋ���� ��� �迭�� ���� ���ΰ�.
	//IS-A Relationship (A is a B) A�� B��.
	//�ﰢ��(Triandgle)�� ����(Shape)�̴�. IS-A ���迡 �ִ�.
	//�簢��(Rect)�� ����(Shape)�̴�. IS-A ���迡 �ִ�.
	//Shape s1 = t;
	//Shape s2 = r;

	//Shape shape[] = { t, r }; //���� ���� �迭�� �����Ҵ�
	//���� �������� for������ ������ �ȴ�. 
	//for (int i = 0; i < 2; i++)
	//{
	//	shape[i].printShape();
	//}
	//�̰��� ������ ������ �Լ��� ���ư��� ������ ������ �Լ����� ������ "�ﰢ��" "�簢��"�� ���ư��� �ʴ´�. 
	//������ �Լ����� �������� �����Ͱ� �ʿ��ϴ�.

	Shape* shape[] = { &t, &r }; //�ּ� �迭�̱� ������ ��ü�� ��������� �ʰ� (4byte ������ ���ư�) �� ������ �����ڰ� ���ư��� �ʴ´�.
	//*�� ������ ������ ����. �ֳĸ� Shape�� �߻� Ŭ�����̱� ������.
	//�߻� Ŭ������ �θ�ν��� ��Ȱ�θ� ����. (��ü�� ������ �ʴ´�)
	for (int i = 0; i < 2; i++)
	{
		shape[i]->printShape(); //shape[i]�� �����ʹϱ� �������� ���� ->�� ��
	}//shape �Լ��� �θ� �Լ��̴� �̷��� �ϸ� ����� �Ȱ��� ���´�. �̷� �� ���� �Լ��� ����� ó���Ѵ�.
	//�θ��Լ����� printShape �Լ��� virtual ó���ؼ� �����Լ��� ������ְ� ������ override�� �������� ��µȴ�.
	

	/* �����غ��� 
	����� �� �ʿ��Ѱ� ?
	����� �Ӽ��� �Լ��� �ݺ����� �ʱ� ����.
	������ ����
	���������鿡�� ����.

	�������̵�� ?
	�θ�Ŭ������ �Ӽ��� �ڽ�Ŭ������ ���ļ� ���°�.

	�����Լ��� ?
	�տ� virtual�� �ٴ� �Լ�.Override�� ���� ���´�.
	���� �����Լ��� �̷� �θ� �Լ����� �ƿ� ���� ���� �����Լ��� ���Ѵ�.

	���������Լ��� �ʿ伺 ?
	�θ��Լ����� ��Ȯ�� � ���� ���;� ���� ������ �� ���� �� ����.
	�̶� �ڳ��Լ����� �ݵ�� Override ����� �Ѵ�.

	�߻� Ŭ������ ?
	Ŭ������ ���������Լ��� �ϳ� �̻� ���Ե� Ŭ������ ���Ѵ�.


	�߻� Ŭ������ �ʿ伺
	���������Լ���..�ʿ��ϴϱ�..�ϴ� ������..�߻� Ŭ������ �ǰ�..�׷� �ʿ��ϰ���..
	�θ��Լ��� �ʿ��ϱ� ����.���ϼ�, �������� �鿡�� ����.
	*/

	return 0;
}