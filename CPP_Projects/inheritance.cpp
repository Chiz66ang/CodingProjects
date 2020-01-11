#include <iostream>

using namespace std;

class Shape
{
public:

	float width, height;

	Shape() {}
	Shape (float width, float height): width(width), height(height) {}

	virtual void printShape() //가상 함수로 만들어버림 (없는셈 치는 것)
	{
		cout << "width: " << width << ", height: " << height << endl;
	}

	virtual float get_area() = 0; //일부로 값이 없는 함수를 만들었다 {return 0.0F}를 포함하고 있다고 생각하면 됨
	//어떤 도형인지 모르고 넓이를 구할 수 없으니, 아무것도 리턴하지 않는 함수를 작성해 자녀함수에서 override 해준다.
	//순수 가상함수 (정말 기능이 1도 없는 함수)
	//순수 가상함수를 가지고 있는 class는 미완성이기 때문에 Shape 객체를 만들 수 없다. 
};//parent class, super class 

class Triangle : public Shape //shape을 제한없이(public) 상속받는다. Shape의 맴버들이 모두 들어온다. (private으로 하면 private으로 받겠다)
	//public 부모함수를 가지고 오면 private인 부분은 private으로 public인 부분은 public으로 가져오고, private으로 설정한다면 모두 private으로 가져오는 것이다.
{
	//모든 맴버가 똑같이 온다. (생성자 제외: 생성자는 맴버가 아니다)
	//개발자가 생성자를 정의하지 않았기 때문에 기본 생성자가 있는 것이나 마찬가지이다.
public:
	Triangle() {}
	Triangle(float width, float height): Shape(width, height) {} //부모의 생성자를 가져와 쓴다
	
	void printShape()
	{ //Override : 부모클래스의 함수를 자식이 상속 받아 기능을 개조하는 것.
		cout << "삼각형 정보: " << endl;
		//Shape::printShape(); // 아래의 식이 부모에게 그대로 있으니 부모에 있는 함수를 불러오고 위에 식만 추가한다.
		cout << "width: " << width << ", height: " << height << endl;
	}

	float get_area()
	{
		return width * height / 2.0F;
	}
};//child class, sub class

//사각형 클래스를 정의할 때 Shape클래스를 상속해보세요.
class Rect : public Shape
{
public:
	Rect(){}
	Rect(float width, float height): Shape(width, height) {}


	void printShape()
	{ //Override : 부모클래스의 함수를 자식이 상속 받아 기능을 개조하는 것.
		cout << "사각형 정보: " << endl;
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
	/*상속 (Inheritance)
	객체지향언어의 3대 특징: 상속성, 다형성, 은닉성
	
	
	Shape s1(3.5F, 4.2F); //순수 가상함수를 포함하고 있기 때문에 Shape s1 (추상 클래스) 에러가 난다. 
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
	//같은 부모 함수의 정보를 받았으나 각 자녀 함수에서 다른 특징을 정의해주어 이것을 출력했을 때 다른 특성이 나온다.
	//이것을 개조, override 라고 한다. (다형성:polymorphism)

	//도형이 많아지면 많아질 수록 배열을 만들어주어야 하는데 자료형이 틀린데 어떻게 배열을 만들 것인가.
	//IS-A Relationship (A is a B) A는 B다.
	//삼각형(Triandgle)은 도형(Shape)이다. IS-A 관계에 있다.
	//사각형(Rect)은 도형(Shape)이다. IS-A 관계에 있다.
	//Shape s1 = t;
	//Shape s2 = r;

	//Shape shape[] = { t, r }; //위의 식을 배열로 만들어보았다
	//수가 많아지면 for루프를 돌리면 된다. 
	//for (int i = 0; i < 2; i++)
	//{
	//	shape[i].printShape();
	//}
	//이것을 돌리면 개조된 함수가 돌아가지 않으니 개조된 함수에서 정의한 "삼각형" "사각형"은 돌아가지 않는다. 
	//개조된 함수까지 돌리려면 포인터가 필요하다.

	Shape* shape[] = { &t, &r }; //주소 배열이기 떄문에 객체가 만들어지지 않고 (4byte 공간만 돌아감) 그 때문에 생성자가 돌아가지 않는다.
	//*이 없으면 에러가 난다. 왜냐면 Shape는 추상 클래스이기 때문에.
	//추상 클래스는 부모로써의 역활로만 쓴다. (객체로 만들지 않는다)
	for (int i = 0; i < 2; i++)
	{
		shape[i]->printShape(); //shape[i]가 포인터니까 역참조를 위해 ->를 씀
	}//shape 함수는 부모 함수이니 이렇게 하면 결과가 똑같이 나온다. 이럴 때 가상 함수를 만들어 처리한다.
	//부모함수에서 printShape 함수를 virtual 처리해서 가상함수로 만들어주고 돌리면 override한 정보까지 출력된다.
	

	/* 생각해보기 
	상속은 왜 필요한가 ?
	비슷한 속성의 함수를 반복하지 않기 위해.
	에러가 덜남
	유지보수면에서 좋음.

	오버라이드란 ?
	부모클래스의 속성을 자식클래스가 고쳐서 쓰는것.

	가상함수란 ?
	앞에 virtual이 붙는 함수.Override된 값이 나온다.
	순수 가상함수는 이런 부모 함수에서 아예 값이 없는 가상함수를 말한다.

	순수가상함수의 필요성 ?
	부모함수에서 정확히 어떤 값이 나와야 할지 정의할 수 없을 때 쓴다.
	이때 자녀함수에서 반드시 Override 해줘야 한다.

	추상 클래스란 ?
	클래스에 순수가상함수가 하나 이상 포함된 클래스를 말한다.


	추상 클래스의 필요성
	순수가상함수가..필요하니까..일단 있으면..추상 클래스가 되고..그럼 필요하겠지..
	부모함수가 필요하기 때문.균일성, 유지보수 면에서 좋음.
	*/

	return 0;
}