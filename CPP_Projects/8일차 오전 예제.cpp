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

	void set_num(int num) { this->num = num; } //set �Լ� (���� �޾��ִ� �Լ�)
	void set_team(string team) { this->team = team; }
	void set_score(int score) { this->score = score; }

	int get_num() { return num; } //get �Լ� (���� �ҷ����� �Լ�)
	string get_team() { return team; }
	int get_score() { return score; }
	

	void print_info()
	{
		cout << " " << num << " " << team << " " << score << endl;
	}

};

int main()
{
	/*8���� ����
�÷��̾�� ��ȣ, �Ҽ���, ���ھ� ������ �䱸�ȴٰ� �� ��
�÷��̾� ������ �����ϱ� ���� ��ü�������� ����� �����Ϸ� �Ѵ�.
��ü�������� ���м��� �����Ͽ� �÷��̾ ���� Ŭ������ �����ϰ�
�Ӽ� �� �޼ҵ�, ������ ���� �����Ѵ�.
5���� �÷��̾� ������ �迭�� �����ϰ� ȭ�鿡 ǥ���غ�����.
*/

	Player p[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "�÷��̾� ��ȣ, �Ҽ���, ���ھ�" << endl;
		int a;
		string b;
		int c;
		cin >> a >> b >> c;

		p[i].set_num(a); //�Ķ���͸� ����ϴ� �Լ����� cin�� ���������� ���� ����. �׷��� ���� ������ ���� �� �������� �ް� �Լ� �Ķ���Ϳ� ����.
		p[i].set_team(b); 
		p[i].set_score(c);
	}



	for (int i = 0; i < 5; i++)
	{
		p[i].print_info();
	}


}