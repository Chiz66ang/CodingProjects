#include <iostream>

using namespace std;

struct Vector2D
{//크기와 방향을 동시에 표현하는 물리량 (하나는 크기, 하나는 방향)
	//크기만 있는 물리량을 스칼라 값이라고 한다. (e.g. 온도)
	float x, y;
	Vector2D (){}
	Vector2D(float x, float y) : x(x), y(y) {}

	//덧셈 연산자(+)를 오버로드하여 백터 덧셈을 지원하게 함
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
	//연산자 오버로드 (Operator Overload)
	/*
	한 언어에서 지원하는 연산자를 개발자가 다시 정의하여 다른 의미로 사용하는 것.
	*/

	Vector2D v1(2, 3);
	Vector2D v2(4, 6);

	//Vector2D v3(v1.x + v2.x, v1.y + v2.y);
	Vector2D v3 = v1 + v2; //이것이 되게 하려면 +의 정의를 재정의해야한다.
	//v1이 + 연산자의 주인이고, v2가 파라미터로 들어가는 값이다.
	v3.print();

}
