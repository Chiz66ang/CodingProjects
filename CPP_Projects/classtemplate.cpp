#include <iostream>

using namespace std;

struct Vector2D
{
	float *x, *y;

	;

	Vector2D(){}
	Vector2D(float _x, float _y) {
		float* tmp = new float[2];
		x = tmp++; //후증가 니까 1주소
		y = tmp; // 2주소
		*x = _x;
		*y = _y;
	}

	~Vector2D(){ //소멸자. 지역변수가 사라지기 전에 돌아가는 로직
	
		delete [] x;
		cout << "소멸자 실행" << endl;
	}
	void print_info()
	{
		cout << "x: " << x << ", y: " << y << endl;
	}

};


int main()
{
	//클래스 템플릿
	Vector2D v1(3.14, 2.71829F);
	v1.print_info(); //v1은 지역변수이기 때문에 쓰이고 나서 사라지는데 이 객체가 사라지기 전에 해야하는 것이 있을 때 소멸자를 쓴다. 
	//예시를 들면 file을 열어 정보를 읽어오는 객체를 만들었을 때 객체가 사라지기 전에 file 을 닫아주는 것.
	//동적할당 받은 메모리가 있을 때, delete를 할 때. 
	//보통 객체가 사라지기 전에 객체가 벌어놓은 일들을 정리할 때 쓰인다. 

	/* 객체가 실행될 때 동적으로 메모리를 할당하고, 
	객체가 소멸될 떄 동적으로 할당된 메모리까지 헤제하는 기능을 구현해보자
	*/

	

}