#include <iostream>

using namespace std;

template<typename T> //template (아래는 가짜 자료형이다) <typename T> 가상 자료형을 T라고 정의하겠다. typename은 T라고 쓰는 것이 관례화 되어있다.
class Vector2D //위의 선언으로 이제 class template이 되었다.
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

	T* arry; //배열을 만듬
	T count; 
	T index; //값이 차있는 방이 몇개인지 세어주는 변수


public:
	Dynamicarray()
	{
		arry = new T[5];
		count = 5;
		index = 0;
	}
	~Dynamicarray() { delete[]arry; }
	
	

	void add(T value) //각 방에 값을 할당하는 함수
	{
		if (index == count) //만약 방 5개가 모두 찾다면
		{
			T* p = new T[count + 5];

			for (int i = 0; i < count; i++)
			{
				p[i] = arry[i]; //넓어진 방으로 값들을 옮겨오기
			}
			count += 5;
			delete[] arry;
			arry = p; //주소를 옮겨오기
		}
		arry[index++] = value; //새로 들어온 값을 자동적으로 가장 끝방에 저장.
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
	//Template(클래스 탬플릿): 형틀, 거푸집, 빵틀
	//클래스를 찍어내는 틀을 만든다. 
	//자료형을 정하지 않고, 필요할 때 자료형을 정의한 클래스를 만들어내는 것.

	//Vector2D<float> v(2.4F, 3.8F); //Vector2D의 틀을 써 <float>라는 자료형을 준 클래스를 만들고 객체v를 만든다.
	//v.printVector();

	//Vector2D<double> v2(2.1234567, 3.7654321); //Vector2D의 틀을 써 <double>이라는 자료형을 준 클래스를 만들고 객체v2를 만든다.
	//v2.printVector();

	//Vector2D<int> v3(3, 5);
	//v3.printVector();

	/*Template 예제
	 정수, 실수 자료형의 데이터를 얼마든지 많이 저장해 둘 수 있는 (배열, 동적할당)
	 자료구조를 정의한다.
	 print()함수를 정의하고 해당 자료구조 안에 저장된 모든 데이터를 화면에 표시하는 기능도 작성해보세요.
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