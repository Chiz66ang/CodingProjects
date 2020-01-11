#include <iostream>
#include <string>

using namespace std;

class Player
{
	int num;
	string team;
	int score;

public:
	Player () {}
	Player (int num, string team, int score) : num(num), team(team), score(score)
	{}

	void set_num(int num) { this->num = num; } //set 함수 (값을 받아주는 함수)
	void set_team(string team) { this->team = team; }
	void set_score(int score) { this->score = score; }

	int get_num() { return num; } //get 함수 (값을 불러오는 함수)
	string get_team() { return team; }
	int get_score() { return score; }
	

	void print_info()
	{
		cout << " " << num << " " << team << " " << score << endl;
	}

};

int main()
{
	/*8일차 예제
플레이어는 번호, 소속팀, 스코어 정보가 요구된다고 볼 때
플레이어 정보를 관리하기 위해 객체지향적인 방법을 적용하려 한다.
객체지향언어의 은닉성을 적용하여 플레이어를 위한 클래스를 정의하고
속성 및 메소드, 생성자 등을 정의한다.
5인의 플레이어 정보를 배열에 저장하고 화면에 표시해보세요.
*/

	Player p[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "플레이어 번호, 소속팀, 스코어" << endl;
		int a;
		string b;
		int c;
		cin >> a >> b >> c;

		p[i].set_num(a); //파라미터를 줘야하는 함수여서 cin에 직접적으로 들어가지 못함. 그래서 따로 변수를 만들어서 그 변수에다 받고 함수 파라미터에 적용.
		p[i].set_team(b); 
		p[i].set_score(c);
	}



	for (int i = 0; i < 5; i++)
	{
		p[i].print_info();
	}


}