#include <iostream>

using namespace std;

class Transport
{
public:
//protected: //(�ܺ��� ������ ���� �ڽ� �Լ����Դ� ����)
	virtual void cost() = 0;

};

class Ship : public Transport
{
	float peer_time;
	float run_time;
public:
	Ship(float peer_time, float run_time) : peer_time(peer_time), run_time(run_time) {}
	~Ship() { cout << "Ship �Ҹ���" << endl; }
	void cost() override {//override�� �ڳ��Լ��� �θ��Լ��� ����� ������ �ߴ��� Ȯ��/�˻� ���ִ� Ű����.
		cout << "Ship ��ۺ�: " << peer_time + run_time << endl;
	}

};

class Truck : public Transport
{
	float run_time;
	float distance;
	
public:
	Truck(float run_time, float distance) : run_time(run_time), distance(distance) {}
	~Truck() { cout << "Truck �Ҹ���" << endl; }
	void cost() override {
		cout << "Truck ��ۺ�: " << run_time + distance << endl;
	}

};

class Airplane : public Transport
{
	float distance;

public:
	Airplane(float distance) : distance(distance) {}
	~Airplane() { cout << "Airplane �Ҹ���" << endl; }
	void cost() override {
		cout << "Airplane ��ۺ�: " << distance * 3 << endl;
	}

};

int main()
{
	/*
	9���� ���� ����
	��� ��ۻ翡�� �� ��ۼ��ܿ� ���� ������� ������ ���� ���ȴ�.
	Ship: peer time + running time
	Truck: running time + distance
	Airplane: distance *3

	�̵� ��ۼ����� Ŭ������ ���ڸ��ϰ� cost()�Լ��� ȣ���ϸ� �� ��ۼ����� ������ 
	���Ǿ� ǥ�õ� �� �ֵ��� �غ�����.
	Ŭ����, ������, �Ҹ���, �������̵�, ������ ���� ��ü���� ����� �迭�� ����ؾ��մϴ�.
	*/

	/*Transport* trans[3]; //�����Լ��̱� ������ �����ͷν� ȣ��������Ѵ�.
	Ship s(3, 50);
	Truck t(5, 500);
	Airplane a(3000);

	trans[0] = &s;
	trans[1] = &t;
	trans[2] = &a;
	

	for (int i = 0; i < 3; i++) {
		trans[i]->cost(); //protected�� �����س����� ������ �����. 
		//�θ������͸� �̿��� �θ� ȣ�������� �θ��Լ��� �����Լ��̱� ������ �ڳ� �Լ��鿡 �� ���� ���ư���.
		//(���� �����Լ��� �ƴ϶�� ���� ��) �θ� �Լ��� ���������� ȣ�� �� ���� ����. �׷� �θ��Լ��� �� ���� ���ư��ϱ�.
		//�����ͷθ� �ڳ��Լ��� �ִ� overriding �� �Լ��� ���ư���.
	}*/
	/* ���� �θ��Լ��� �����Լ��� �ƴҶ� ȣ���. (�θ� ������ �̿�)*/
	Transport* t = &Ship(10, 100); //������ ����ȯ
	//t->cost();
	//float f = (float)100;//����� ����ȯ. (100�� int ������ float�� ��ȯ�϶�) -> �������� �����Ϸ��� �ڵ������� ���ִ� �Ƚᵵ �ȴ�.
	//Transport* t = (Transport*) &Ship(10, 100);//�������� �����Ϸ��� �ڵ����� ���༭ ������ ����ȯ���� �ᵵ �ȴ�.

	/*Ship�� Transport�� ���� �� ������
	//Ship* s = t; ������ ����ȯ���� �ϸ� ����
	Ship* sp = (Ship*)t; //����� ����ȯ ���� (�����ڰ� �����ؼ� �� ��)

	Ship* s = dynamic_cast<Ship*>(t); //���� ����ȯ. dynamic_cast: ����ð��� �̷������ ����ȯ.
	if(s==NULL)
	{
	cout<<"����ȯ ����" <<endl;
	return 1;
	}
	s->cost();
	//���� ����ȯ dynamic_cast�� t�� �� ���� ���� ship�� ��ü���� �ƴ��� Ȯ���ϱ� ���� ����Ѵ�.
	//����� ����ȯ�� ���� ���� ������ ���� (���α׷��� ������ ����), ���� ����ȯ�� ���� s���� NULL�� �� ���α׷��� ���� ���� ���� �ִ�.
	//��Ȳ�� �°� ���� �ȴ�. 
	*/

	return 0;
}