#include <iostream>
#include <string>
#include <sstream> //string stream
#include <cmath> //c���� ��� math library


using namespace std; //standard library ǥ�� ���̺귯�� ���� �ʿ�.

struct Employee //����ü�� Ŭ������ �ǹ� ��ü�� �߻�ȭ �� ��. (�ǹ� ��ü �߻�ȭ)
	//��ü�� ������ ���� �� ��ǥ���� ����� �̾Ƴ� ǥ���Ѵ�.
{
	//cpp������ ������ �Լ��� ���� ����ü �ȿ� �� �� �ִ� = ��ü
	int num;
	string name;
	string email;
	//��� ����
	//��ü�� �Ӽ� property (��ü�� �����ϴµ� ���� ǥ���Ǵ� �͵�) = ������ ǥ�� ����

	//������ constructor = return type�� �־�� �ȵȴ�.
	//�����ڴ� ��ü�� �����ϴ� ����� �ƴϴ�. ��ü ������ �ʱ�ȭ ���ִ� ��.
	//������ ���� ������
	Employee(int num, string name, string email) : num(num), name(name), email(email) //�ʱ��� initializer
	//�ɹ����� num�� �Ķ���� num�� �־�� 
	{
		cout << "�Ķ� ���� �ִ� ������ �����" << endl;
	}
	

	Employee() {//�⺻ ������ (�Ķ���Ͱ� ����)
		cout << "�⺻ ������ �����" << endl;
		this->num = 10; //this�� Employee�����ڰ� ��������� ������ ���ư� ��ü(Employee e)�� ������ �ּ�
		this->name = "����ȣ";
		this->email = "park@naver.com";
	} 

	//������ �����ε� (overload):

	void print_list()
	{
		cout << "�����ȣ: " << /*this.num*/num << endl;
		cout << "�̸�: " << name << endl;
		cout << "�̸���: " << email << endl <<endl;
			
	}
	//��� �Լ�
	//��ü�� ��� (��ü�� �����ϴµ� ����� ǥ���Ǵ� �͵�) = �Լ�
	
};

class Gugu
{//class�� �⺻������ private�̱� ������ �ٸ� �Լ����� �̰� ������ �� �� ���� �ߴ�.
public: //main �Լ� (�ܺ��Լ�)������ �� �� �ֵ��� �ϴ� Ű����
	//���� ����: Public, protected, private
	int dan;

	Gugu() {} //�⺻ ������
	Gugu(int dan) :dan(dan) {} //������ ���� ������
	//Contstructor Overload(������ �ߺ� ����)
	
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
	float speedX, speedY; //�̵���(ũ��), ����
	float x, y; //���� ��ġ ��ǥ

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
		cout << "���� �ӵ�: " << speedX << "," << speedY << endl;
		cout << "���� ��ġ: " << "x: " << x << ", y: " << y << endl;
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
		//�Ʒ� �Լ����� ���͸� �� �����Ͱ� ���� �ȴ�.
	}

	void use_potion()
	{
		health += heal;
	}

	void print_info()
	{
		cout << "������ �̸�: " << title << endl;
		cout << "����ü��: " << health - heal << endl;
		cout << "ġ����: " << heal << endl;
		cout << "ġ�� �� ü��: " << health << endl;

	}

	float get_heal() { return heal; }
	string get_title() { return title; }
	//private �� ������ �ٸ� �Լ����� ���� ���� return�� ����. --> ���� ����
	void set_heal(int heal) //50~100���� ����
	{
		if (heal >= 50 && heal<= 100)
		this->heal = heal; //�ɹ� ���� = �Ķ���� ����
	}
	void set_title(string title) { this->title = title; }

};

/*
��ü���� ����� 3�� Ư¡
��Ӽ�(inheritance)
������(polymorphism)
���м�(encapsulation)
*/

int main()
{
	//C++�� �����մϴ�.
	//��ü ����: ��� ���, ������ ��ü �ȿ� ��Ƽ� ����Ϸ��� ����.
	/*ǥ�� ��� ��Ʈ��
	//std::cout << "�ȳ��ϼ���?" << std::endl; //cout �̶�� ��ü(������ �Լ��� ���Ե� ����ü)
	//cout -> ���� �ܼ� â�� ����� ��������(out)
	//endl -> ���๮�� (\n ������)
	//<< ������. cout(�����)�� ������.
	//:: (scope operator:��� ������) cout, end�� std��� name space�� ����Ǿ��ִ�. 
	//�̷� ���� using namespate std;�� �ּ�ó���ؾ��Ѵ�.

	//�ƴϸ� using namespate std;�� �����ϰ�
	int a = 10;
	cout << "�ȳ��ϼ���?" << a << endl;
	*/

	/*ǥ�� �Է� ��Ʈ�� (c���� scanf)
	cout << "���� 1�Է�:";
	cin >> a; //a��� (����)������ �Է¹޾ƿ´�.

	int b = 0;

	cout << "���� 2 �Է�:";
	cin >> b;

	cout << a << "+" << b << "=" << a + b << endl;
	*/

	/*����
	Ű���忡�� �� ���� �޾Ƽ� �ش� �������� ǥ���ϴ� CPP ���α׷��� ����ÿ�
	�̿��ڰ� 0�� �Է��� ���� ����ǵ��� �Ѵ�.
	

	
	int gugu = 0;
	bool go = true; //�� ������ �����ִ� ���� c���� 1,0���� ǥ���ߴ� ���� ture, false��� ǥ���Ѵ�.

	while (go)
	{
		cout << "����� 0�� �ƴϸ� ���� �ܼ��� �Է��ϼ���:";
		cin >> gugu;

		if (gugu == 0)
		{
			go = false;
			continue;
		} //�� �κ��� while�� true�� �ְ� if (gugu ==0) break;�� ��ü����

		for (int i = 1; i < 10; i++)
		{
			cout << gugu << "x" << i << "=" << gugu * i << endl;
		}
	}
	
	������ ����
	cout << "����� 0�� �ƴϸ� ���� �ܼ��� �Է��ϼ���:";
	int gugu = 0;
	cin >> gugu;

	for (int i = 1; i < 10; i++)
		{
			if (gugu == 0) break;
			cout << gugu << "x" << i << "=" << gugu * i << endl;
		}

	cout << "���α׷� ����";
	*/

	/*���ڿ��� ó���ϱ�
	string line; // ���ڿ��� ó���ϴ� ���̺귯�� #include <string> �ʿ�.
	cout << "id�� pass �Է�: ";
	getline(cin, line); //gets�� ���� �Լ� cin �Էµ� ���ڿ��� line�̶� string ������ �����϶�. (�迭�� ���� �������� �ʾƵ� �Ǵ� ����)
	cout << "�Էµ� ��: " << line << endl;
	
	//�Էµ� �� �ڸ��� c���� strtok �Լ�
	//stringstream Ŭ������ ������Ʈ(�ν��Ͻ�) ����/�ʱ�ȭ
	//Object (��ü), Instance(��ü) ���� ����
	stringstream ss(line); //����ü (����ü ����)��ü �ʱ�ȭ (��ü�� �ʱ�ȭ�ϱ� ���� �Ķ����); 
	//��ü ������ �ʱ�ȭ 
	//stringstream ss;
	//ss.str(line); �̷��� �ص� �ȴ�.
	string id, pass;
	ss >> id >> pass; //ss�ȿ� ����ִ� id �� pass�� �����Ͷ�

	ss.clear(); //ss�� ����ִ� ���� �����
	cout << "id: " << id << ", pass: " << pass << endl;
	ss.str("�ι�° ���ڿ�"); //��ü ���� �� �ʱ�ȭ
	ss >> id >> pass;
	cout << id << "," << pass << endl;
	*/

	/*CPP���� c��� ���̺귯�� �Ẹ��
	include <cmath>
	���� cos(60) ?

	float rad = 3.141592F / 180.0F * 60;
	cout << "cos 60 =" << cos(rad) << endl;
	*/

	/* 
	������
	Ű���忡�� �����ȣ, �̸�, �̸����� �Է¹ް�
	����ü ��ü�� �ʱ�ȭ�� ����, �� ��ü�� �迭�� ����
	�迭�� ���Ұ� 3���� �� ������ �ݺ��� �Ŀ�
	�� �迭�� �Լ��� �����Ͽ� ��������� ��� ǥ���Ѵ�.
	*/
	
	/*
	Employee e; //�⺻ �����ڰ� ���ư�
	e.print_list();

	e.num = 11;
	e.name = "ȫ�浿";
	e.email = "hong@daum.net";
	e.print_list(); //������ �鿡�� ������. �ڷḦ � ������ �־�� ���� Ȯ���� ���̴� �򰥸� ���� ����.

	Employee e2(12, "������", "js@gmail.com"); //�Ķ���� �ִ� �����ڰ� ���ư�
	e2.print_list();*/
	

	/*Employee emps[3]; //��ü 3���� ������ ������ �� ���Ŀ� �����ڰ� ȣ��ȴ�.
	for (int i = 0; i < 3; i++)
	{
		cout << "�����ȣ, �̸�, �̸���: ";
		cin >> emps[i].num >> emps[i].name >> emps[i].email; //��ü�� ���� �ʱ�ȭ
	}

	for (int i = 0; i < 3; i++)
	{
		emps[i].print_list();
	}
	*/

	/*
	������ ����
	Ŭ������ ������ �ȿ� �����ڸ� �������� ������ �ý��ۿ��� 
	�⺻ �����ڸ� ��� �ۼ��Ͽ� �����Ѵ�
	�׷��� �����ڰ� �Ķ���͸� ���� �����ڸ� �����ϸ� 
	�ý��ۿ����� �⺻ �����ڸ� �������� �ʴ´�.
	Ŭ������ ����ü���� �ݵ�� �Ѱ� �̻��� �����ڰ� �ʼ��̴�.
	���࿡ �����ڰ� �����ڸ� �Ѱ��� �������� ������ 
	�ý����� �⺻ �����ڸ� �����Ѵ�.
	*/

	//Employee e(11, "ȫ�浿", "hong@daum.net"); //����ü �̸�, ��ü����, �ʱ�ȭ 
	//e.print_list();

	/* ������ ����
	Gugu ��ü�� �����ϰ� ������ �������� ǥ���� �� �ֵ���
	����ü�� �����غ�����
	�Ӽ�: ���� �ܼ�
	���: �������� ����
		  ȭ�鿡 ���
	
	
	Gugu g7;
	g7.dan = 7;//�̰��� ��ü a ��� �� �� ���赵�� struct Gugu
	g7.print_gugu();
	*/
	//struct Gugu �� class Gugu�� �ٲ��� ������ ����.
	//class�� �ܺο����� ������ ���Ƴ��� ����
	//struct �� �⺻������ public ����. Class�� private.

	/*
	Character�� �𵨸��� Ŭ������ �����ϰ� 
	�Ӽ����� �ӵ�, ��ġ(x,y), ������ �����ϰ�
	����� ���� �� �� �̵��� ���� move() �Լ��� ������ ������.
	move()�Լ��� ȣ���� ������ ��ġ�� ����Ǿ�� �ϰ�
	print_info() �Լ��� ȣ���Ͽ� ������ ��ġ�� �ӵ��� ǥ�õǵ��� �Ѵ�.
	
	Character c1(50, 50, 2, 1);
	c1.move(); c1.move(); c1.move(); //���� ��ġ 50, 50 ���� x�� 2��ŭ, y�� 1��ŭ ���� �Ѵٶ�� ���� ��. 3�� ������
	c1.print_info();
	//character�� �� class�� �߳ĸ�, ���� ���� character�� �� ���� ������ ����� �ֱ� ������ �����Ͽ� ��������� �Ѵ�.
	*/

	/*
	���Ӿ������� �𵨸��� �۷����� �ۼ��ϰ� Ȱ���غ�����.
	*/
	Heal_potion p1("�⺻����",50, 50);
	p1.use_potion();
	p1.print_info();
	
	if (p1.get_heal == 0) 
	{	}
	// ������ ���� ���� ����
	//heal ������ private �̱� ������ ���� ���� �Ұ�. return�ؼ� (�纻�� ������) �о�帰��.
	//�������� ���� �Ժη� �ٲ�� ���� �����Ѵ�.
	//������ ������ ���� �ְ� �ʹٸ�? (�������� ��� ���ݷ��� �������� �� ó��)

	p1.set_heal(60);
	p1.use_potion();
	p1.print_info();

	return 0;
}

