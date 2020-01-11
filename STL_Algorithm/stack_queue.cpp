#include <iostream>
#include <stack> //stack �� queue�� C++ STL(standard template library)
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Graph �ڷᱸ���� Ž�� �˰���
	//���� �ڷᱸ�� (��ȸ/Ž���� �߿�: ���߿� �˻�, ����, �߰��� ����)
	//�ڽ��� ������
	/*stack �� queue�� Ȱ�� �ؾ� graph�� Ǯ �� �ִ�.
	stack<int> iStack; //template�̴� �ڷ����� ��������Ѵ�.
	iStack.push(1);
	iStack.push(2);
	iStack.push(3);

	cout << iStack.top() << endl; //�� ����Ⱚ�� ���� :3
	iStack.pop(); // �� �� ���� ����� (3�� �����)
	cout << iStack.top() << endl; //�� ����Ⱚ�� ����: 2

	
	queue<int> iQue;
	iQue.push(1);
	iQue.push(2);
	iQue.push(3);

	cout << iQue.front() << endl; //1
	iQue.pop();
	cout << iQue.front() << endl; //2
	*/

	/*
	1~100������ ������ ���� 10���� �����ϸ� �� stack, queue�� �����Ѵ�. 
	������ �������� ������� ���� ����ϰ�,
	ť�� �տ������� ���ʷ� ���� ����غ�����..
	���ð� ť�� ������ ���ϱ� ���� ���ÿ� ����غ�����.
	

	stack<int> rStack;
	queue<int> rQueue;

	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		int ran = rand() % 100 + 1;
		rStack.push(ran);
		rQueue.push(ran);
	}

	cout << "Stack: ";
	for (int i = 0; i < 10; i++)
	{
		cout << rStack.top() << " ";
		rStack.pop();
	}
	cout << endl;

	cout << "Queue: ";
	for (int i = 0; i < 10; i++)
	{
		cout << rQueue.front() << " ";
		rQueue.pop();
	}
	*/

	/*���� ��İ� ���� ����Ʈ

	//�׷����� ������踦 2���� �迭�� ǥ���� ��(�������)
	int graph[7][7] = 
	{ //Ư¡: n��° ��� n��° ���� ������ ����. (�밢���� �������� ��Ī)
	  //������ �ߺ��Ǿ��ٴ� ���̰�, �׸�ŭ ��������� �޸𸮸� ���� �����Ѵ�.
	  //������ ������ ����. (������)
		{0,1,1,1,0,0,0},
		{1,0,0,0,1,0,0},
		{1,0,0,0,1,1,0},
		{1,0,0,0,0,1,0},
		{0,1,1,0,0,0,1},
		{0,0,1,1,0,0,1},
		{0,0,0,0,1,1,0}
	};
	Ž�����
	DFS (Depth First Search): ���� �켱 Ž��. �ڽ��� ���� Ž�� (�ڽ� -> �ڽ��� �ڽ� -> etc)
	BFS (Breadth First Search) : �ʺ� �켱 Ž��. 
	*/

	//���� ����
	

	 /*���� ������Ŀ��� 4�� ���� �������ִ� ������ ����Ͻÿ�
	 cout << "4�� ��� ������: ";
	 for (int i = 0; i < 8; i++)
	 {
		 if (graph2[4][i])
		 {
			 cout << i << " ";
		 }
	 }
	 */

	 //0�� ���� ����� �ٸ� ��带 ã�Ƽ� �� ��带 �湮�ϰ�,
	 /*�� ��尡 ����� �ٸ� ��带 ã�Ƽ� ȭ�鿡 ����غ�����
	 bool exit = false;
	 for (int i = 0; i < 8; i++)
	 {
		 if (graph2[0][i])
		 {
			 cout << "0����" << i << "���� ����" << endl;
			 for (int j = 1; j < 8; j++)
			 {
				 if (graph2[i][j])
				 {
					cout << i << "����" << j << "���� �����" << endl;
					exit = true;
					break;
				}
			 }
			 
		 }
		 if (exit)break;
	 }
	 */
int graph2[][8] =
{
   {0,0,0,1,1,0,1,0}, //0
   {0,0,0,1,0,0,0,0}, //1
   {0,0,0,1,0,0,0,0}, //2
   {1,1,1,0,0,1,0,0}, //3
   {1,0,0,0,0,1,1,0}, //4
   {0,0,0,1,1,0,0,1}, //5
   {1,0,0,0,1,0,0,1}, //6
   {0,0,0,0,0,1,1,0}  //7
};

	// ���� �켱 Ž��
	 bool visited[8] = { false, }; //�湮����
	 int n = 0;
	 stack<int> sg;
	 sg.push(n);
	

	 while (!sg.empty())
	 {
		 n= sg.top();
		 sg.pop();
		 cout << n << " ";

		 for (int i = 7; i > 0; i--)
		 {
			 if (graph2[n][i] && !visited[i])
			 {
				 sg.push(i);
				 visited[i] = true;
			 }
		 }
	 }


	 /*�ʺ� �켱 Ž��
	 bool visited[8] = { false, }; //�湮����
	 int n = 0;
	 queue<int> qg;
	 qg.push(n);

	 while (!qg.empty())
	 {
		 n = qg.front();
		 qg.pop();
		 cout << n << " ";

		 for (int i = 7; i > 0; i--)
		 {
			 if (graph2[n][i] && !visited[i])
			 {
				 qg.push(i);
				 visited[i] = true;
			 }
		 }
	 }
	 */

	return 0;
}