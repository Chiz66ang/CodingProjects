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
		cerr << "���Ͽ��� ����" << endl;
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
	//���� �����
	/*
	ofstream : ���� ��� ��Ʈ�� ��ü (output file)
	ifstream : ���� �Է� ��Ʈ�� ��ü
	fstream: ���� ����� ��Ʈ�� ��ü
	�̹� ��������ִ� Ŭ�����̴� ��ü�� ���� ���� ��
	��� <fstream>
	

	ofstream myfile("D:\\test\\example.txt", ios::app); //open�� ������ �ƴϸ� �̷��� �����ڿ� ���� �־ open�ȴ�. 
	//myfile.open("D:\\test\\example.txt"); //��� �����ȴ�. �̾��(c���� a) �Ϸ��� ("D:\\test\\example.txt", ios::app) �־��ָ� �ȴ�.
	myfile << "Writing this to a file.\n";
	myfile.close();
	cout << "���� ���� ����";
	*/

	/*���� ����� ����
	���� ������ �о ȭ�鿡 ǥ���ϴ� ����� �ۼ��غ�����
	
	ifstream readfile("D:\\test\\example.txt");

	if (!readfile.is_open())
	{
		cerr << "���� ���� ����" << endl;
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
	Ű���忡�� �Էµ� 4���� ���� (��ȣ, �̸�, ���ھ�, ����)�� �Է¹޾Ƽ�
	��ü�� ������ �Ŀ� 
	�� ��ü�� ������ �ٸ� �Լ��� �����Ͽ�
	���Ͽ� �� ������ ����ǵ��� �غ�����.
	������ ���� �� ��ū�� �������� ����ǵ��� �մϴ�.
	�̿��ڰ� �Է��� �÷��̾� ����ŭ ������ �Է¹ް� 
	�ټ����� ��ü�� ���� �Ѳ����� ���Ͽ� �����ؾ� �Ѵ�.
	*/
	
	cout << "�Է��Ͻ� �÷��̾� ���� �Է��ϼ���: ";
	int num;
	string line;
	getline(cin, line);
	stringstream ss (line);
	ss >> num;
	ss.clear();

	Player* pi = new Player[num];
	for (int i = 0; i < num; i++)
	{
		cout << "�÷��̾��� ��ȣ, �̸�, ���ھ�, ������ �Է��ϼ���: ";
		getline(cin, line);
		ss.str(line);
		ss >> pi[i].num >> pi[i].name >> pi[i].score >> pi[i].team;
		ss.clear();
	}
	if (save(pi, num)) cout << "���强��" << endl;
	else cout << "���� ����";


	return 0;
}