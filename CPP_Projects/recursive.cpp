#include <iostream>

using namespace std;

void print(int a)
{

	if (a < 1) return;
	cout << a << " ";
	print(--a);

	//무한루프가 될 수 있기 때문에, 탈출 조건이 있어야한다.
}

int add(int b)
{
	{
		if (b > 10) return 0; //return 0가 끝났다는 뜻.
		b += add(b+1);
	}
	return b;
}

int sum(int i)
{//선생님 예시
	if (i < 10) return i + sum(i + 1);
	else return i;
}

int main()
{

	//재귀 호출, Self invocation, Recursive Call
	//print(10); // 10~1까지 출력되게 한다.
	

	//1을 전달하면 1~10을 합산하여 그 결과를 리턴하는 기능. 
	
	cout << add(1) << " ";





	return 0;
}