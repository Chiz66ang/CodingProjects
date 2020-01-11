#include <iostream>
#include <string>
#include <sstream> //string stream
#include <cmath> //c언어에서 썼던 math library


using namespace std; //standard library 표준 라이브러리 사용시 필요.

struct Employee //구조체나 클래스는 실물 객체를 추상화 한 것. (실물 객체 추상화)
	//객체의 수많은 정보 중 대표적인 몇가지만 뽑아내 표현한다.
{
	//cpp에서는 변수와 함수가 같은 구조체 안에 들어갈 수 있다 = 객체
	int num;
	string name;
	string email;
	//멤버 변수
	//객체의 속성 property (객체를 설명하는데 명사로 표현되는 것들) = 변수로 표현 가능

	//생성자 constructor = return type이 있어서는 안된다.
	//생성자는 객체에 존재하는 멤버가 아니다. 객체 변수를 초기화 해주는 것.
	//개발자 정의 생성자
	Employee(int num, string name, string email) : num(num), name(name), email(email) //초기자 initializer
	//맴버변수 num에 파라미터 num을 넣어라 
	{
		cout << "파라 미터 있는 생성자 실행됨" << endl;
	}
	

	Employee() {//기본 생성자 (파라미터가 없음)
		cout << "기본 생성자 실행됨" << endl;
		this->num = 10; //this는 Employee생성자가 만들어지기 직전에 돌아간 객체(Employee e)의 변수의 주소
		this->name = "백찬호";
		this->email = "park@naver.com";
	} 

	//생성자 오버로드 (overload):

	void print_list()
	{
		cout << "사원번호: " << /*this.num*/num << endl;
		cout << "이름: " << name << endl;
		cout << "이메일: " << email << endl <<endl;
			
	}
	//멤버 함수
	//객체의 기능 (객체를 설명하는데 동사로 표현되는 것들) = 함수
	
};

class Gugu
{//class는 기본적으로 private이기 때문에 다른 함수에서 이걸 가져다 쓸 수 없게 했다.
public: //main 함수 (외부함수)에서도 쓸 수 있도록 하는 키워드
	//접근 강도: Public, protected, private
	int dan;

	Gugu() {} //기본 생성자
	Gugu(int dan) :dan(dan) {} //개발자 정의 생성자
	//Contstructor Overload(생성자 중복 정의)
	
	void print_gugu()
	{
		for (int i = 1; i < 10; i++)
		{
			if (dan == 0) break;
			cout << dan << "x" << i << "=" << dan * i << endl;
		}
	}
};

class Character
{public:
	float speedX, speedY; //이동량(크기), 방향
	float x, y; //현재 위치 좌표

	Character(){}
	Character(float x, float y, float sx, float sy) : x(x), y(y), speedX(sx), speedY(sy)
	{	}
	
	void move()
	{
		x += speedX;
		y += speedY;


	}
	void print_info()
	{
		cout << "현재 속도: " << speedX << "," << speedY << endl;
		cout << "현재 위치: " << "x: " << x << ", y: " << y << endl;
	}

};

class Heal_potion
{
	float health;
	float heal;
	string title;

public:
	Heal_potion() {}
	Heal_potion(string title,float heal, float health)
	{
		set_heal(heal);
		set_title(title);
		//아래 함수에서 필터링 된 데이터가 들어가게 된다.
	}

	void use_potion()
	{
		health += heal;
	}

	void print_info()
	{
		cout << "아이템 이름: " << title << endl;
		cout << "현재체력: " << health - heal << endl;
		cout << "치유량: " << heal << endl;
		cout << "치유 후 체력: " << health << endl;

	}

	float get_heal() { return heal; }
	string get_title() { return title; }
	//private 한 변수를 다른 함수에서 쓰기 위해 return을 쓴다. --> 간접 접근
	void set_heal(int heal) //50~100으로 제한
	{
		if (heal >= 50 && heal<= 100)
		this->heal = heal; //맴버 변수 = 파라미터 변수
	}
	void set_title(string title) { this->title = title; }

};

/*
객체지향 언어의 3대 특징
상속성(inheritance)
다형성(polymorphism)
은닉성(encapsulation)
*/

int main()
{
	//C++를 공부합니다.
	//객체 지향: 모든 기능, 변수를 객체 안에 담아서 사용하려는 현상.
	/*표준 출력 스트림
	//std::cout << "안녕하세요?" << std::endl; //cout 이라는 개체(변수도 함수도 포함된 구조체)
	//cout -> 검은 콘솔 창에 결과를 내보내라(out)
	//endl -> 개행문자 (\n 같은것)
	//<< 연산자. cout(모니터)로 나간다.
	//:: (scope operator:명령 연산자) cout, end가 std라는 name space에 선언되어있다. 
	//이럴 때는 using namespate std;를 주석처리해야한다.

	//아니면 using namespate std;를 포함하고
	int a = 10;
	cout << "안녕하세요?" << a << endl;
	*/

	/*표준 입력 스트림 (c언어에서 scanf)
	cout << "정수 1입력:";
	cin >> a; //a라는 (정수)변수에 입력받아온다.

	int b = 0;

	cout << "정수 2 입력:";
	cin >> b;

	cout << a << "+" << b << "=" << a + b << endl;
	*/

	/*예제
	키보드에서 단 수를 받아서 해당 구구단을 표시하는 CPP 프로그램을 만드시오
	이용자가 0을 입력할 때만 종료되도록 한다.
	

	
	int gugu = 0;
	bool go = true; //참 거짓을 정해주는 변수 c언어에서 1,0으로 표현했던 것을 ture, false라고 표현한다.

	while (go)
	{
		cout << "종료시 0을 아니면 정수 단수를 입력하세요:";
		cin >> gugu;

		if (gugu == 0)
		{
			go = false;
			continue;
		} //이 부분은 while에 true를 주고 if (gugu ==0) break;로 대체가능

		for (int i = 1; i < 10; i++)
		{
			cout << gugu << "x" << i << "=" << gugu * i << endl;
		}
	}
	
	간략한 버전
	cout << "종료시 0을 아니면 정수 단수를 입력하세요:";
	int gugu = 0;
	cin >> gugu;

	for (int i = 1; i < 10; i++)
		{
			if (gugu == 0) break;
			cout << gugu << "x" << i << "=" << gugu * i << endl;
		}

	cout << "프로그램 종료";
	*/

	/*문자열을 처리하기
	string line; // 문자열을 처리하는 라이브러리 #include <string> 필요.
	cout << "id와 pass 입력: ";
	getline(cin, line); //gets와 같은 함수 cin 입력된 문자열을 line이란 string 변수에 저장하라. (배열을 따로 정의하지 않아도 되는 편리함)
	cout << "입력된 행: " << line << endl;
	
	//입력된 행 자르기 c언어에서 strtok 함수
	//stringstream 클래스의 오브젝트(인스턴스) 생성/초기화
	//Object (객체), Instance(객체) 같은 개념
	stringstream ss(line); //구조체 (구조체 변수)객체 초기화 (객체를 초기화하기 위한 파라미터); 
	//객체 생성시 초기화 
	//stringstream ss;
	//ss.str(line); 이렇게 해도 된다.
	string id, pass;
	ss >> id >> pass; //ss안에 들어있는 id 와 pass를 가져와라

	ss.clear(); //ss에 들어있는 값을 비워라
	cout << "id: " << id << ", pass: " << pass << endl;
	ss.str("두번째 문자열"); //객체 생성 후 초기화
	ss >> id >> pass;
	cout << id << "," << pass << endl;
	*/

	/*CPP에서 c언어 라이브러리 써보기
	include <cmath>
	예제 cos(60) ?

	float rad = 3.141592F / 180.0F * 60;
	cout << "cos 60 =" << cos(rad) << endl;
	*/

	/* 
	생성자
	키보드에서 사원번호, 이름, 이메일을 입력받고
	구조체 객체에 초기화한 다음, 그 객체를 배열에 저장
	배열의 원소가 3개가 될 때까지 반복한 후에
	그 배열을 함수에 전달하여 사원정보를 모두 표시한다.
	*/
	
	/*
	Employee e; //기본 생성자가 돌아감
	e.print_list();

	e.num = 11;
	e.name = "홍길동";
	e.email = "hong@daum.net";
	e.print_list(); //가독성 면에서 괜춘함. 자료를 어떤 변수에 넣어야 할지 확실히 보이니 헷갈릴 일이 없다.

	Employee e2(12, "박지성", "js@gmail.com"); //파라미터 있는 생성자가 돌아감
	e2.print_list();*/
	

	/*Employee emps[3]; //객체 3개가 생성될 때마다 그 직후에 생성자가 호출된다.
	for (int i = 0; i < 3; i++)
	{
		cout << "사원번호, 이름, 이메일: ";
		cin >> emps[i].num >> emps[i].name >> emps[i].email; //객체에 대한 초기화
	}

	for (int i = 0; i < 3; i++)
	{
		emps[i].print_list();
	}
	*/

	/*
	생성자 정의
	클레스나 구조차 안에 생성자를 정의하지 않으면 시스템에서 
	기본 생성자를 대신 작성하여 제공한다
	그러나 개발자가 파라미터를 가진 생성자를 정의하면 
	시스템에서는 기본 생성자를 제공하지 않는다.
	클레스나 구조체에는 반드시 한개 이상의 생성자가 필수이다.
	만약에 개발자가 생성자를 한개도 정의하지 않으면 
	시스템은 기본 생성자를 제공한다.
	*/

	//Employee e(11, "홍길동", "hong@daum.net"); //구조체 이름, 객체변수, 초기화 
	//e.print_list();

	/* 생성자 예제
	Gugu 객체를 생성하고 임의의 구구단을 표시할 수 있도록
	구조체를 정의해보세요
	속성: 구구 단수
	기능: 구구단을 돌림
		  화면에 출력
	
	
	Gugu g7;
	g7.dan = 7;//이것은 객체 a 라는 것 그 설계도는 struct Gugu
	g7.print_gugu();
	*/
	//struct Gugu 를 class Gugu로 바꾸자 오류가 난다.
	//class는 외부에서의 접근을 막아놨기 때문
	//struct 는 기본적으로 public 포함. Class는 private.

	/*
	Character를 모델링한 클래스를 정의하고 
	속성으로 속도, 위치(x,y), 방향을 포함하고
	기능을 정의 할 때 이동을 위한 move() 함수를 정의해 보세요.
	move()함수를 호출할 때마다 위치가 변경되어야 하고
	print_info() 함수를 호출하여 현재의 위치와 속도가 표시되도록 한다.
	
	Character c1(50, 50, 2, 1);
	c1.move(); c1.move(); c1.move(); //현재 위치 50, 50 에서 x는 2만큼, y는 1만큼 가야 한다라고 정의 함. 3번 움직임
	c1.print_info();
	//character를 왜 class로 했냐면, 실제 게임 character는 수 많은 변수와 기능이 있기 때문에 고정하여 관리해줘야 한다.
	*/

	/*
	게임아이템을 모델링한 글래스를 작성하고 활용해보세요.
	*/
	Heal_potion p1("기본물약",50, 50);
	p1.use_potion();
	p1.print_info();
	
	if (p1.get_heal == 0) 
	{	}
	// 변수에 대한 간접 접근
	//heal 변수는 private 이기 때문에 직접 접근 불가. return해서 (사본을 가져와) 읽어드린다.
	//데이터의 값이 함부로 바뀌는 것을 방지한다.
	//하지만 변수에 값을 넣고 싶다면? (아이템을 사면 공격력이 강해지는 것 처럼)

	p1.set_heal(60);
	p1.use_potion();
	p1.print_info();

	return 0;
}

