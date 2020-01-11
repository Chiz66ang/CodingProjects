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


struct RemovePlayer //함수객체 remove_if함수에서 이용하려고 만듬.
{
	RemovePlayer() {}
	string team;
	RemovePlayer (string team) : team(team) {}

	bool operator() (PlayerState& p) //연산자 오버로드: ()라는 함수를 만들겠다.
	//Call Back 함수: 개발자가 아닌 시스템이 호출하는 함수
	{
		//cout << p.team << " "; //모든 데이터를 List객체가 호출하여 검사한 후 true를 리턴한 PlayerState 객체만 삭제한 것이다.
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

	list<int>::iterator iter = iList.begin(); //반복자.
	

	for (; iter != iList.end(); iter++)
	{
		cout << *iter << " ";
	} //저장된 순서대로 출력된다. 1,2,3,3 중복도 가능하다.
	*/

	/*
	키보드에서 번호, 아이디, 팀명, 점수, 데미지 등을 입력하여 PlayerState 객체를 3개 이상 생성하고 메모리에 저장한다.
	이용자가 입력을 마칠 때까지 PlayerState객체를 생성하여 입력을 마치면 D:\\test\\player.txt 파일에 한명씩 저장한다.
	이용자가 몇개의 PlayerState 정보를 입력할지 모르는 상황이므로 배열이나 동적할당도 사용하기에 적합하지 않다. 
	이 문제를 해결해보시오.
	

	list<PlayerState> PS;
	string input;
	stringstream ss;

	
	while (true)
	{
		cout << "플레이어의 번호, 아이디, 팀명, 점수, 데미지를 입력하세요, 종료(0): ";
		getline(cin, input);
		if (input == "0") break;
		ss.str(input);
		PlayerState p;
		ss >> p.num >> p.id >> p.team >> p.score >> p.damage;
		PS.push_back(p);
		ss.clear();
	}
	
	

	//파일에 저장
	ofstream player;
	player.open("D:\\test\\player.txt", ios::app);
	auto iter = PS.begin(); //auto는 자료형을 컴퓨터가 자동으로 지정해주겠다.
	auto exit = PS.end();
	if (!player.is_open())
	{
		cerr << "파일열기 실패" << endl;
	}
	for (; iter !=exit; iter++)
	{
		PlayerState p = (*iter); //iter가 포인터이기 때문에 역참조 해서 값을 찾아줌.
		player << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	player.close();
	cout << "파일 저장 성공" << endl;
	
	cout << "프로그램 종료" << endl;
	*/

	/*
	player.txt 파일에 저장된 PlayerState정보를 모두 로드하여 목록을 화면에 표시해보세요.
	저장된 정보의 행수는 알 수 없다고 간주한다.
	*/

	ifstream readp ("D:\\test\\player.txt", ios::app);
	if (!readp.is_open())
	{
		cerr << "파일 열기 실패" << endl;
		return 1;
	}
	string line;
	stringstream ss;
	list<PlayerState> PS;

	//파일 데이터를 list에 로드
	/*
	while (!readp.eof())
	{
		getline(readp, line);
		if (line.size() == 0) continue;// 마지막에 개행이 있으면 (아무 정보도 없는) 처음으로 가서 다시 읽어준다. 엄청난 디테일...
		//이거 없으면 이상한 값이 나온다. (마지막 행을 읽었는데 아무런 정보가 없으니까)
		ss.str(line);
		PlayerState p;
		ss >> p.num >> p.id >> p.team >> p.score >> p.damage;
		PS.push_back(p);
		ss.clear();
	}
	cout << "list에 저장 성공" << endl;
	readp.close();
	*/

	// RemovePlayer mem; 함수 객체 생성. 생성자를 통해 우리가 준 번호를 삭제하게끔 할 수 있다.
	//PS.remove_if(RemovePlayer(1)); //remove if 사용 예시.
	//PS.remove_if(RemovePlayer()) 이렇게 해도 됨. 생성자를 생성하고 싶으면 RemovePlayer() 괄호 안에 파라미터를 주면 된다.

	/*
	auto iter = PS.begin();
	auto exit = PS.end();
	for (; iter != exit; iter++)
	{
		PlayerState p = (*iter);
		cout << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	*/

	//리스트에 저장된 PlayerState 객체들 중에서 특정 팀에 속하는 객체를 모두 삭제해보세요.
	//remove_if 함수 사용 예제.

	/*PS.remove_if(RemovePlayer("미국"));

	cout << endl << "       ***삭제 후 Player 리스트***" << endl;
	
	for (iter = PS.begin(); iter != exit; iter++)
	{
		PlayerState p = (*iter);
		cout << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	*/

	/*최고점수 순위로 정렬

	PS.sort(CompPlayer());

	cout << endl << "       ***정렬 후 Player 리스트***" << endl;
	for (iter = PS.begin(); iter != exit; iter++)
	{
		PlayerState p = (*iter);
		cout << p.num << "\t" << p.id << "\t" << p.team << "\t" << p.score << "\t" << p.damage << endl;
	}
	*/

	
	//파일에 저장된 PlayerState 정보를 로드해서 vector에 저장하고
	/*출력전용 함수에 벡터를 전달해서 화면에 표시되도록 하보세요.
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
	cout << "vector에 저장 성공" << endl;
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

	//파일에서 PlayerState 정보를 가져올 때 PlayerState 객체를 맵에 저장 할 때
	//키를 플레이어 번호로 설정하고 value에는 객체를 저장한다.

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
	cout << "map에 저장완료" << endl;
	unordered_map<int, PlayerState>::iterator iter = uomap.find(2);
	cout << "번호: " << iter->first << ", 정보: " << endl;
	iter->second.print();

	return 0;
}