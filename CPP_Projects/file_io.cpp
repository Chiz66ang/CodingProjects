#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Player
{public:
	Player() {	}
	Player (int num, string name, int score, string team):num(num), name(name), team(team), score(score){}

	int num;
	string name;
	int score;
	string team;

	void print()
	{
		cout << num << "\t" << name << "\t" << score << "\t" << team << "\t" << endl;
	}
};



bool save(Player* pi, int num)
{
	
	ofstream playerinfo;
	playerinfo.open("D:\\test\\playerinfo.txt", ios::app);
	if (!playerinfo.is_open())
	{
		cerr << "파일열기 실패" << endl;
		return false;
	}
	for (int i = 0; i < num; i++)
	{
		playerinfo << pi[i].num << "\t" << pi[i].name << "\t" << pi[i].score << "\t" << pi[i].team << endl;

	}
	playerinfo.close();
	delete[] pi;
	return true;
}

int main()
{
	//파일 입출력
	/*
	ofstream : 파일 출력 스트림 객체 (output file)
	ifstream : 파일 입력 스트림 객체
	fstream: 파일 입출력 스트림 객체
	이미 만들어져있는 클래스이니 객체로 만들어서 쓰면 됨
	헤더 <fstream>
	

	ofstream myfile("D:\\test\\example.txt", ios::app); //open을 쓰던가 아니면 이렇게 생성자에 직접 넣어도 open된다. 
	//myfile.open("D:\\test\\example.txt"); //계속 덮어쓰기된다. 이어쓰기(c언어에서 a) 하려면 ("D:\\test\\example.txt", ios::app) 넣어주면 된다.
	myfile << "Writing this to a file.\n";
	myfile.close();
	cout << "파일 쓰기 성공";
	*/

	/*파일 입출력 예제
	위의 파일을 읽어서 화면에 표시하는 기능을 작성해보세요
	
	ifstream readfile("D:\\test\\example.txt");

	if (!readfile.is_open())
	{
		cerr << "파일 열기 실패" << endl;
		return 1;
	}

	string line;
	string tok;
	stringstream ss;
	while (!readfile.eof())
	{
		getline(readfile, line);
		ss.str(line);
		
		while (ss >> tok)
		{
			cout << tok << endl;
		}
		ss.clear();
	}
	*/

	/*
	키보드에서 입력된 4가지 정보 (번호, 이름, 스코어, 팀명)을 입력받아서
	객체를 생성한 후에 
	그 객체의 참조를 다른 함수에 전달하여
	파일에 한 행으로 저장되도록 해보세요.
	저장할 때는 각 토큰이 공백으로 저장되도록 합니다.
	이용자가 입력할 플레이어 수만큼 정보를 입력받고 
	다수개의 객체가 파일 한꺼번에 파일에 저장해야 한다.
	*/
	
	cout << "입력하실 플레이어 수를 입력하세요: ";
	int num;
	string line;
	getline(cin, line);
	stringstream ss (line);
	ss >> num;
	ss.clear();

	Player* pi = new Player[num];
	for (int i = 0; i < num; i++)
	{
		cout << "플레이어의 번호, 이름, 스코어, 팀명을 입력하세요: ";
		getline(cin, line);
		ss.str(line);
		ss >> pi[i].num >> pi[i].name >> pi[i].score >> pi[i].team;
		ss.clear();
	}
	if (save(pi, num)) cout << "저장성공" << endl;
	else cout << "저장 실패";


	return 0;
}