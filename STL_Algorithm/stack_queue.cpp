#include <iostream>
#include <stack> //stack 과 queue는 C++ STL(standard template library)
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Graph 자료구조와 탐색 알고리즘
	//비선형 자료구조 (순회/탐색이 중요: 나중에 검색, 삭제, 추가를 위해)
	//자식이 공유됨
	/*stack 과 queue를 활용 해야 graph를 풀 수 있다.
	stack<int> iStack; //template이니 자료형을 정해줘야한다.
	iStack.push(1);
	iStack.push(2);
	iStack.push(3);

	cout << iStack.top() << endl; //맨 꼭대기값을 리턴 :3
	iStack.pop(); // 맨 위 값이 사라짐 (3이 사라짐)
	cout << iStack.top() << endl; //맨 꼭대기값을 리턴: 2

	
	queue<int> iQue;
	iQue.push(1);
	iQue.push(2);
	iQue.push(3);

	cout << iQue.front() << endl; //1
	iQue.pop();
	cout << iQue.front() << endl; //2
	*/

	/*
	1~100사이의 임의의 수를 10개를 추출하며 각 stack, queue에 저장한다. 
	스택은 꼭대기부터 순서대로 값을 출력하고,
	큐는 앞에서부터 차례로 값을 출력해보세요..
	스택과 큐를 나란히 비교하기 위해 동시에 출력해보세요.
	

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

	/*인접 행렬과 인접 리스트

	//그래프의 연결관계를 2차원 배열로 표현한 것(인접행렬)
	int graph[7][7] = 
	{ //특징: n번째 행과 n번째 열의 정보가 같다. (대각선을 기준으로 대칭)
	  //정보가 중복되었다는 뜻이고, 그만큼 상대적으로 메모리를 많이 차지한다.
	  //하지만 성능이 좋다. (빠르다)
		{0,1,1,1,0,0,0},
		{1,0,0,0,1,0,0},
		{1,0,0,0,1,1,0},
		{1,0,0,0,0,1,0},
		{0,1,1,0,0,0,1},
		{0,0,1,1,0,0,1},
		{0,0,0,0,1,1,0}
	};
	탐색방법
	DFS (Depth First Search): 깊이 우선 탐색. 자식을 따라 탐색 (자식 -> 자식의 자식 -> etc)
	BFS (Breadth First Search) : 너비 우선 탐색. 
	*/

	//오후 예제
	

	 /*위의 인접행렬에서 4번 노드와 인접해있는 노드들을 출력하시오
	 cout << "4번 노드 연결목록: ";
	 for (int i = 0; i < 8; i++)
	 {
		 if (graph2[4][i])
		 {
			 cout << i << " ";
		 }
	 }
	 */

	 //0번 노드와 연결된 다른 노드를 찾아서 그 노드를 방문하고,
	 /*그 노드가 연결된 다른 노드를 찾아서 화면에 출력해보세요
	 bool exit = false;
	 for (int i = 0; i < 8; i++)
	 {
		 if (graph2[0][i])
		 {
			 cout << "0노드는" << i << "노드와 연결" << endl;
			 for (int j = 1; j < 8; j++)
			 {
				 if (graph2[i][j])
				 {
					cout << i << "노드는" << j << "노드와 연결됨" << endl;
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

	// 깊이 우선 탐색
	 bool visited[8] = { false, }; //방문여부
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


	 /*너비 우선 탐색
	 bool visited[8] = { false, }; //방문여부
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