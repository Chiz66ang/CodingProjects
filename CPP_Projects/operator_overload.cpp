#include <iostream>

using namespace std;

struct Vector2D
{
	float x, y;

	Vector2D(float x, float y) : x(x), y(y)
	{
		cout << "백터 생성" << endl;
	}

	void print_vector()
	{
		cout << "x(" << x << "), y(" << y << ")" << endl;
	}

	//현재 벡터와 외부에서 전달된 백터를 덧셈하여
	//새로운 백터를 산출해내는 기능을 함수로 정의해보세요.

	Vector2D add_vector(Vector2D* v2)
	{
		return Vector2D(x + v2->x, y + v2->y);
	}

	Vector2D operator+(const Vector2D& v2) //연산자 오버로드 //연산자를 재정의하겠다.
		//Vector2D&라고 쓰면 v2는 참조변수. Call by reference로 함수를 호출하겠다는 뜻.
		//cpp에서는 포인터를 쓰는대신 이걸 쓴다.
		//v2의 값을 함부로 바꾸지 않기 위해 const 를 붙여준다. 이런걸 봐도 당황하지 말 것.
	const {
		return Vector2D(x + v2.x, y + v2.y);
	} //상수 함수. 맴버 데이터를 바꾸지 못하도록 고정해주는 것.

	//벡터의 각성분에 float 값을 각각 곱해주는 함수를 
	//연산자 오버로드 방법으로 정의해보세요.
	//그 결과벡터를 리턴한다.

	Vector2D operator*(float value)
	{
		return Vector2D(x * value, y * value);
	}


};

int main()
{
	//연산자 오버로드 (Operator Overload)
	Vector2D v1(3, 5);
	Vector2D v2(5, 8);

	//벡터의 덧셈
	//Vector2D res(v1.x + v2.x, v1.y + v2.y); //벡터끼리의 덧셈 --> class(지금은 struct) 안에 집어넣고 싶다.
	//또 다른 방법
	//Vector2D res = v1.add_vector (&v2); 

	//연산자 오버로드를 이용한 방법
	Vector2D res = v1 + v2; //함수 호출과 같다. v1.operator+(v2); 여기서 operator랑 괄호만 없엔 것.

	res.print_vector();


	return 0;
}