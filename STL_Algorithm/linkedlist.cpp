#include <iostream>
#include <chrono> //프로그램 구동 경과 시간을 구하기 위해 추가.
#include <string>

using namespace std;
using namespace std::chrono; //프로그램 구동 경과 시간을 구하기 위해 추가.

template<typename T>
struct Node
{
	T num;
	Node* next; //next라는 이름에 다음에 연결될 Node의 주소를 준다. 
	
};

template<typename T>
class LinkedList
{
	Node<T>* root; //자료구조의 시작
	Node<T>* last;	//자료구조의 끝
public:
	LinkedList(): root(NULL), last(NULL) {}
	~LinkedList() //동적 객체들을 삭제해주는 소멸자
	{
		Node<T>* node = root;
		Node<T>* next = NULL;
		while (node != NULL) //node가 끝이 아니라면 이 루프를 돌아라
		{
			next = node->next; //node에 연결된 다음 노드를 저장해놓고
			delete node; //node를 지운 다음
			node = next; //다음 next(주소)를 node(주소)에 넣어준다.
		}
	}

	void add(T value)
	{
		Node<T>* node = new Node<T>; //node가 지역변수이기 때문에 개발자가 명령하지 않는 한 (remove) 다른 함수에서도 쓸 수 있도록 남아있게 동적할당을 했다. 
		//함수가 끝나면 그 메모리 공간이 다 지워져버리니, 이용을 모두 할 때까지 지우지 않는 동적할당이 적합니다.
		node->num = value;
		node->next = NULL;//리스트의 끝을 나타내는 NULL;

		if (root == NULL)//첫번째 (자료구조의 정점)이 없다면
		{
			root = node;//root에 node를 넣어주고
			last = root;//아직 다른 node가 없으니 last이기도 하다.
		}
		else //root가 이미 채워졌다면
		{
			last->next = node; //node(포인터)를 last의 next에 넣어주고
			last = node; //그것이 last가 된다.
		}
	}

	void remove(T value)
	{
		if (root->num == value) //value가 맨 첫번째 방 num일 때
		{
			Node<T>* node = root->next; //여기서의 노드는 위의 동적할당된 노드와 따로라고 취급하라.
			delete root;
			root = node;
			return;
		}
		Node<T>* node = root->next;
		Node<T>* prev = root;

		while (node != NULL) //노드가 끝이 아닐때
		{
			if (node->num == value)
			{
				prev->next = node->next; //현재 노드 삭제 전에 앞 노드에 next변수에 다음 (삭제될)노드에서 가지고 있는 주소를 주었다.
				if (node == last) //삭제대상 노드가 마지막 노드라면, 그 앞노드에 NULL을 넣어준다.
				{
					prev->next = NULL;
					last = prev;
				}
				delete node;
				cout << "\t" << value << " <- 삭제" << endl;
				break;
			}
			else
			{
				prev = node;
				node = node->next;
			}
		}
	}

	void print() 
	{
		//cout << a->num << a->next->num << a->next->next->num << endl;
		Node<T>* node = root;
		while (node != last)
		{ 
			cout << node->num << endl;
			node = node->next;
		}
		cout << node->num << endl;
	}

};


int main()
{
	//Linked List (연결 리스트) 자료구조

	/*
	정수배열에 10만개의 정수를 저장하고 맨 처음의 데이터를 삭제하기 위해 모든 데이터를 한칸씩 앞으로 옮기는 기능을 작성해보세요
	

	int arr[100000];
	for (int i = 0; i < 100000; i++)
	{
		arr[i] = i;
	}

	unsigned __int64 begin = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	for (int k = 0; k < 10; k++)
	{
		for (int i = 1; i < 100000; i++)
		{
			arr[i - 1] = arr[i];
		}
	}

	unsigned __int64 end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	cout << "경과시간: " << end - begin << endl;
	//경과시간은 3milisecond 였다.
	*/

	/*
	Node a;
	a.num = 1;

	Node b;
	b.num = 2;
	a.next = &b; //객체 a에 a의 주소를 줌으로 a객체와 b를 연결할 발판을 만들어준다.

	Node c;
	c.num = 3;
	b.next = &c;
	c.next = NULL; //c 이후의 객체는 없으니까 NULL을 준다.

	//함수를 작성하여 Node a의 포인터를 그 함수로 전달하면
	//a에 연결된 모든 데이터를 화면에 표시한다.

	a.print_list(&a);
	*/

	//Linked List 클래스 템플릿을 작성하고 추가 (add), 삭제(delete), 출력(print) 기능을 구현해보세요.
	//삭제의 경우 해당 노드를 삭제하면서 그 노드에 들어있는 주소를 그 전 노드에 줘야한다.

	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);

	list.print();

	
	list.remove(3);
	

	list.print();

	


	cout << "프로그램 종료..." << endl;
	return 0;
}