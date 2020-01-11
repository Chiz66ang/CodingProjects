#include <iostream>

using namespace std;

class Transport
{
public:
//protected: //(외부의 접근은 막고 자식 함수에게는 연다)
	virtual void cost() = 0;

};

class Ship : public Transport
{
	float peer_time;
	float run_time;
public:
	Ship(float peer_time, float run_time) : peer_time(peer_time), run_time(run_time) {}
	~Ship() { cout << "Ship 소멸자" << endl; }
	void cost() override {//override는 자녀함수가 부모함수를 제대로 제정의 했는지 확인/검사 해주는 키워드.
		cout << "Ship 운송비: " << peer_time + run_time << endl;
	}

};

class Truck : public Transport
{
	float run_time;
	float distance;
	
public:
	Truck(float run_time, float distance) : run_time(run_time), distance(distance) {}
	~Truck() { cout << "Truck 소멸자" << endl; }
	void cost() override {
		cout << "Truck 운송비: " << run_time + distance << endl;
	}

};

class Airplane : public Transport
{
	float distance;

public:
	Airplane(float distance) : distance(distance) {}
	~Airplane() { cout << "Airplane 소멸자" << endl; }
	void cost() override {
		cout << "Airplane 운송비: " << distance * 3 << endl;
	}

};

int main()
{
	/*
	9일차 오전 예제
	어느 운송사에서 각 운송수단에 따른 유지비는 다음과 같이 계산된다.
	Ship: peer time + running time
	Truck: running time + distance
	Airplane: distance *3

	이들 운송수단을 클래스로 모텔링하고 cost()함수를 호출하면 각 운송수단의 유지비가 
	계산되어 표시될 수 있도록 해보세요.
	클래스, 생성자, 소멸자, 오버라이드, 다형성 등의 객체지향 개념과 배열을 사용해야합니다.
	*/

	/*Transport* trans[3]; //가상함수이기 때문에 포인터로써 호출해줘야한다.
	Ship s(3, 50);
	Truck t(5, 500);
	Airplane a(3000);

	trans[0] = &s;
	trans[1] = &t;
	trans[2] = &a;
	

	for (int i = 0; i < 3; i++) {
		trans[i]->cost(); //protected로 설정해놓으면 에러가 생긴다. 
		//부모포인터를 이용해 부모를 호출하지만 부모함수는 가상함수이기 때문에 자녀 함수들에 든 것이 돌아간다.
		//(가령 가상함수가 아니라고 했을 때) 부모 함수를 직접적으로 호출 할 수는 없다. 그럼 부모함수에 든 것이 돌아가니까.
		//포인터로만 자녀함수에 있는 overriding 된 함수가 돌아간다.
	}*/
	/* 만약 부모함수가 가상함수가 아닐때 호출법. (부모 포인터 이용)*/
	Transport* t = &Ship(10, 100); //묵시적 형변환
	//t->cost();
	//float f = (float)100;//명시적 형변환. (100은 int 이지만 float로 변환하라) -> 이정도는 컴파일러가 자동적으로 해주니 안써도 된다.
	//Transport* t = (Transport*) &Ship(10, 100);//이정도는 컴파일러가 자동으로 해줘서 묵시적 형변환으로 써도 된다.

	/*Ship을 Transport로 넣을 순 없을까
	//Ship* s = t; 묵시적 형변환으로 하면 오류
	Ship* sp = (Ship*)t; //명시적 형변환 가능 (개발자가 정의해서 한 것)

	Ship* s = dynamic_cast<Ship*>(t); //동적 형변환. dynamic_cast: 실행시간에 이루어지는 형변환.
	if(s==NULL)
	{
	cout<<"형변환 실패" <<endl;
	return 1;
	}
	s->cost();
	//동적 형변환 dynamic_cast는 t에 든 것이 정말 ship의 객체인지 아닌지 확인하기 위해 사용한다.
	//명시적 형변환을 썼을 때는 오류가 나고 (프로그램을 돌릴수 없다), 동적 형변환을 쓰면 s값에 NULL이 들어가 프로그램을 마저 돌릴 수는 있다.
	//상황에 맞게 쓰면 된다. 
	*/

	return 0;
}