#include <iostream>
#include <string>

using namespace std;

class Ball
{
	//제조사, 색상, 크기
	//지금은 객체맴버 (Instance Member): 객체(Instance)를 생성 할 때마다 중복되어 로드되는 맴버 (변수, 함수), static 키워드를 가지지 않는 맴버.
	static string company; // 이건 이제 클래스맴버. 전역 공간에서 초기화한다.
	string color;
	float radius;
public:
	Ball(){}
	Ball(string color, float radius) : color(color), radius(radius) {} //string company는 더 이상 인스턴스 맴버가 아니기 때문에 여기서는 지워준다. (매번 만들어질 때 마다 초기화 해주지 않으니)

	void printBall()
	{
		cout << Ball::company /*클래스 맴버라는 것을 알려줌*/<< ", " << color << ", " << radius << endl;
	}
};

string Ball::company = "공사"; //string company 초기화 방법.

int main()
{
	/*Static Member (정적 맴버)
	클래스가 로드될 때 한번만 메모리에 로드되는 변수, 함수
	객체를 만들 때마다 변하지 않는 변수를 정적 맴버로 정해놓는다.
	*/
	Ball b[] = 
	{
		Ball("Red", 20),
		Ball("green", 30),
		Ball("blue", 40)
	}; //"공사"라는 변수가 반복되어 만들어지니 정적 맴버로 선언해보는 것이 좋을 것 같다.
	//게임에서는 서버 같은 것.
	
	for (int i = 0; i < 3; i++) b[i].printBall();

	return 0;
}