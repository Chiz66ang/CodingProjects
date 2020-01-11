#include <iostream>
#include <string>

using namespace std;

float circle(float rad)
{
	return (rad * rad * 3.141592F);
}

float area(float r, float(*func)(float))
{
	return(*func)(r); //함수의 주소를 주고 그 함수에 r을 넣고 실행하라.

}


int main()
{
	//함수 포인터(function pointer)
	//함수의 이름에는 그 함수의 주소가 들어있다. 뒤에 괄호가 있으면 호출, 없으면 함수 주소.
	//온라인 교재 p.73

	/*
	반지름(float)을 입력받아서 원의 면적을 계산하고 (반지름*반지름*3.14)
	그 값을 리턴하는 함수를 정의하고
	그 함수 포인터를 다른 함수로 전달하여 원의 면적을 계산하는 내용을 작성해보세요.
	*/

	cout << area(2.5F, circle) << endl;


	return 0;
}