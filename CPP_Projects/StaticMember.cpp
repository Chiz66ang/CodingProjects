#include <iostream>
#include <string>

using namespace std;

class Ball
{
	//������, ����, ũ��
	//������ ��ü�ɹ� (Instance Member): ��ü(Instance)�� ���� �� ������ �ߺ��Ǿ� �ε�Ǵ� �ɹ� (����, �Լ�), static Ű���带 ������ �ʴ� �ɹ�.
	static string company; // �̰� ���� Ŭ�����ɹ�. ���� �������� �ʱ�ȭ�Ѵ�.
	string color;
	float radius;
public:
	Ball(){}
	Ball(string color, float radius) : color(color), radius(radius) {} //string company�� �� �̻� �ν��Ͻ� �ɹ��� �ƴϱ� ������ ���⼭�� �����ش�. (�Ź� ������� �� ���� �ʱ�ȭ ������ ������)

	void printBall()
	{
		cout << Ball::company /*Ŭ���� �ɹ���� ���� �˷���*/<< ", " << color << ", " << radius << endl;
	}
};

string Ball::company = "����"; //string company �ʱ�ȭ ���.

int main()
{
	/*Static Member (���� �ɹ�)
	Ŭ������ �ε�� �� �ѹ��� �޸𸮿� �ε�Ǵ� ����, �Լ�
	��ü�� ���� ������ ������ �ʴ� ������ ���� �ɹ��� ���س��´�.
	*/
	Ball b[] = 
	{
		Ball("Red", 20),
		Ball("green", 30),
		Ball("blue", 40)
	}; //"����"��� ������ �ݺ��Ǿ� ��������� ���� �ɹ��� �����غ��� ���� ���� �� ����.
	//���ӿ����� ���� ���� ��.
	
	for (int i = 0; i < 3; i++) b[i].printBall();

	return 0;
}