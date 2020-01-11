#include <iostream>

using namespace std;

class Math
{
public:
	//인스턴스 메소드(Instance Method)
	void add(int a, int b)
	{
		cout << a << " + " << b << " = " << a + b << endl;
	}

	void add(float a, float b)
	{
		cout << a << " + " << b << " = " << a + b << endl;
	}
};


int main()
{
	/*함수 오버로드 (중복정의)
	객체지향 언어에서는 한 영역에 이름이 동일한 함수를 다수개 선언 할 수 있다.
	이 때 지켜야 할 문법을 알아야 한다.*/

	Math math;
	math.add(3, 5);
	math.add(3.14F, 5.0F);

	return 0;
}