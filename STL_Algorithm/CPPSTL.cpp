#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class PlayerState
{
public:
	int num;
	string id;
	string team;
	int score;
	int damage;


	PlayerState() {};
	PlayerState(int num, string id, string team, int score, int damage): num(num), id(id), team(team), score(score), damage(damage) {}

	void print()
	{
		cout << num << "\t" << id << "\t" << team << "\t" << score << "\t" << damage << endl;
	}
};

void print_player(vector<PlayerState>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].print();
	}
}


struct RemovePlayer //�Լ���ü remove_if�Լ����� �̿��Ϸ��� ����.
{
	RemovePlayer() {}
	string team;
	RemovePlayer (string team) : team(team) {}

	bool operator() (PlayerState& p) //������ �����ε�: ()��� �Լ��� ����ڴ�.
	//Call Back �Լ�: �����ڰ� �ƴ� �ý����� ȣ���ϴ� �Լ�
	{
		//cout << p.team << " "; //��� �����͸� List��ü�� ȣ���Ͽ� �˻��� �� true�� ������ PlayerState ��ü�� ������ ���̴�.
		return p.team == team;
	}
};

struct CompPlayer
{

	bool operator() (PlayerState& l, PlayerState& r)
	{
		return l.score > r.score;
	}
};

int main()
{
	// C++ STL (Standard Template Library)
	/*
	list<int> iList;
	iList.push_back(1);
	iList.push_back(2);
	iList.push_back(3);
	iList.push_back(3);

	list<int>::iterator iter = iList.begin(); //�ݺ���.
	

	for (; iter != iList.end(); iter++)
	{
		cout << *iter << " ";
	} //����� ������� ��µȴ�. 1,2,3,3 �ߺ��� �����ϴ�.
	*/

	/*
	Ű���忡�� ��ȣ, ���̵�, ����, ����, ������ ���� �Է��Ͽ� PlayerState ��ü�� 3�� �̻� �����ϰ� �޸𸮿� �����Ѵ�.
	�̿��ڰ� �Է��� ��ĥ ������ PlayerState��ü�� �����Ͽ� �Է��� ��ġ�� D:\\test\\player.txt ���Ͽ� �Ѹ� �����Ѵ�.
	�̿��ڰ� ��� PlayerState ������ �Է����� �𸣴� ��Ȳ�̹Ƿ� �迭�̳� �����Ҵ絵 ����ϱ⿡ �������� �ʴ�. 
	�� ������ �ذ��غ��ÿ�.
	

	list<PlayerState> PS;
	string input;
	stringstream ss;

	
	while (true)
	{
		cout << "�÷��̾��� ��ȣ, ���̵�, ����, ����, �������� �Է��ϼ���, ����(0): ";
		getline(cin, input);
		if (input == "0") break;
		ss.str(input);
		PlayerState p;
		ss >> p.num >> p.id >> p.team >> p.score >> p.damage;
		PS.push_back(p);
		ss.clear();
	}
	
	

	//���Ͽ� ����
	ofstream player;
	player.open("D:\\test\\player.txt", ios::app);
	auto iter = PS.begin(); //auto�� �ڷ����� ��ǻ�Ͱ� �ڵ����� �������ְڴ�.
	auto exit = PS.end();
	if (!player.is_open())
	{
		cerr << "���Ͽ��� ����" << endl;
	}
	for (; iter !=exit; iter++)
	{
		PlayerState p = (*iter); //iter�� �������̱� ������ ������ �ؼ� ���� ã����.
		player << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	player.close();
	cout << "���� ���� ����" << endl;
	
	cout << "���α׷� ����" << endl;
	*/

	/*
	player.txt ���Ͽ� ����� PlayerState������ ��� �ε��Ͽ� ����� ȭ�鿡 ǥ���غ�����.
	����� ������ ����� �� �� ���ٰ� �����Ѵ�.
	*/

	ifstream readp ("D:\\test\\player.txt", ios::app);
	if (!readp.is_open())
	{
		cerr << "���� ���� ����" << endl;
		return 1;
	}
	string line;
	stringstream ss;
	list<PlayerState> PS;

	//���� �����͸� list�� �ε�
	/*
	while (!readp.eof())
	{
		getline(readp, line);
		if (line.size() == 0) continue;// �������� ������ ������ (�ƹ� ������ ����) ó������ ���� �ٽ� �о��ش�. ��û�� ������...
		//�̰� ������ �̻��� ���� ���´�. (������ ���� �о��µ� �ƹ��� ������ �����ϱ�)
		ss.str(line);
		PlayerState p;
		ss >> p.num >> p.id >> p.team >> p.score >> p.damage;
		PS.push_back(p);
		ss.clear();
	}
	cout << "list�� ���� ����" << endl;
	readp.close();
	*/

	// RemovePlayer mem; �Լ� ��ü ����. �����ڸ� ���� �츮�� �� ��ȣ�� �����ϰԲ� �� �� �ִ�.
	//PS.remove_if(RemovePlayer(1)); //remove if ��� ����.
	//PS.remove_if(RemovePlayer()) �̷��� �ص� ��. �����ڸ� �����ϰ� ������ RemovePlayer() ��ȣ �ȿ� �Ķ���͸� �ָ� �ȴ�.

	/*
	auto iter = PS.begin();
	auto exit = PS.end();
	for (; iter != exit; iter++)
	{
		PlayerState p = (*iter);
		cout << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	*/

	//����Ʈ�� ����� PlayerState ��ü�� �߿��� Ư�� ���� ���ϴ� ��ü�� ��� �����غ�����.
	//remove_if �Լ� ��� ����.

	/*PS.remove_if(RemovePlayer("�̱�"));

	cout << endl << "       ***���� �� Player ����Ʈ***" << endl;
	
	for (iter = PS.begin(); iter != exit; iter++)
	{
		PlayerState p = (*iter);
		cout << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	*/

	/*�ְ����� ������ ����

	PS.sort(CompPlayer());

	cout << endl << "       ***���� �� Player ����Ʈ***" << endl;
	for (iter = PS.begin(); iter != exit; iter++)
	{
		PlayerState p = (*iter);
		cout << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	*/

	
	//���Ͽ� ����� PlayerState ������ �ε��ؼ� vector�� �����ϰ�
	/*������� �Լ��� ���͸� �����ؼ� ȭ�鿡 ǥ�õǵ��� �Ϻ�����.
	vector<PlayerState>vec;

	while (!readp.eof())
	{
		getline(readp, line);
		if (line.size() == 0) continue;
		ss.str(line);
		PlayerState p;
		ss >> p.num >> p.id >> p.team >> p.score >> p.damage;
		vec.push_back(p);
		ss.clear();
	}
	cout << "vector�� ���� ����" << endl;
	readp.close();

	print_player(vec);
	*/

	/*map
	map<int, float>myMap;
	myMap.insert(map<int, float> ::value_type(10, 45.6f));
	myMap.insert(map<int, float> ::value_type(20, 65.6f));
	myMap.insert(map<int, float> ::value_type(30, 85.6f));

	map<int, float>::iterator it = myMap.find(20);
	cout << (*it).first << "\t" << (*it).second << endl;
	*/

	/*
	unordered_map<int, float> uomap;
	uomap.insert(unordered_map<int, float>::value_type(10, 3.14F));
	uomap.insert(unordered_map<int, float>::value_type(20, 2.14F));
	uomap.insert(unordered_map<int, float>::value_type(30, 5.14F));
	unordered_map<int, float>::iterator iter = uomap.find(20);
	cout << "Key: " << iter->first << ", Value: " << iter->second << endl;
	*/

	//���Ͽ��� PlayerState ������ ������ �� PlayerState ��ü�� �ʿ� ���� �� ��
	//Ű�� �÷��̾� ��ȣ�� �����ϰ� value���� ��ü�� �����Ѵ�.

	unordered_map<int, PlayerState> uomap;
	while (!readp.eof())
	{
		getline(readp, line);
		if (line.size() == 0) continue;
		ss.str(line);
		PlayerState p;
		ss >> p.num >> p.id >> p.team >> p.score >> p.damage;
		uomap.insert(unordered_map<int, PlayerState>::value_type(p.num, p));
		ss.clear();
	}
	cout << "map�� ����Ϸ�" << endl;
	unordered_map<int, PlayerState>::iterator iter = uomap.find(2);
	cout << "��ȣ: " << iter->first << ", ����: " << endl;
	iter->second.print();

	return 0;
}