#include <iostream>
#include <chrono> //���α׷� ���� ��� �ð��� ���ϱ� ���� �߰�.
#include <string>

using namespace std;
using namespace std::chrono; //���α׷� ���� ��� �ð��� ���ϱ� ���� �߰�.

template<typename T>
struct Node
{
	T num;
	Node* next; //next��� �̸��� ������ ����� Node�� �ּҸ� �ش�. 
	
};

template<typename T>
class LinkedList
{
	Node<T>* root; //�ڷᱸ���� ����
	Node<T>* last;	//�ڷᱸ���� ��
public:
	LinkedList(): root(NULL), last(NULL) {}
	~LinkedList() //���� ��ü���� �������ִ� �Ҹ���
	{
		Node<T>* node = root;
		Node<T>* next = NULL;
		while (node != NULL) //node�� ���� �ƴ϶�� �� ������ ���ƶ�
		{
			next = node->next; //node�� ����� ���� ��带 �����س���
			delete node; //node�� ���� ����
			node = next; //���� next(�ּ�)�� node(�ּ�)�� �־��ش�.
		}
	}

	void add(T value)
	{
		Node<T>* node = new Node<T>; //node�� ���������̱� ������ �����ڰ� ������� �ʴ� �� (remove) �ٸ� �Լ������� �� �� �ֵ��� �����ְ� �����Ҵ��� �ߴ�. 
		//�Լ��� ������ �� �޸� ������ �� ������������, �̿��� ��� �� ������ ������ �ʴ� �����Ҵ��� ���մϴ�.
		node->num = value;
		node->next = NULL;//����Ʈ�� ���� ��Ÿ���� NULL;

		if (root == NULL)//ù��° (�ڷᱸ���� ����)�� ���ٸ�
		{
			root = node;//root�� node�� �־��ְ�
			last = root;//���� �ٸ� node�� ������ last�̱⵵ �ϴ�.
		}
		else //root�� �̹� ä�����ٸ�
		{
			last->next = node; //node(������)�� last�� next�� �־��ְ�
			last = node; //�װ��� last�� �ȴ�.
		}
	}

	void remove(T value)
	{
		if (root->num == value) //value�� �� ù��° �� num�� ��
		{
			Node<T>* node = root->next; //���⼭�� ���� ���� �����Ҵ�� ���� ���ζ�� ����϶�.
			delete root;
			root = node;
			return;
		}
		Node<T>* node = root->next;
		Node<T>* prev = root;

		while (node != NULL) //��尡 ���� �ƴҶ�
		{
			if (node->num == value)
			{
				prev->next = node->next; //���� ��� ���� ���� �� ��忡 next������ ���� (������)��忡�� ������ �ִ� �ּҸ� �־���.
				if (node == last) //������� ��尡 ������ �����, �� �ճ�忡 NULL�� �־��ش�.
				{
					prev->next = NULL;
					last = prev;
				}
				delete node;
				cout << "\t" << value << " <- ����" << endl;
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
	//Linked List (���� ����Ʈ) �ڷᱸ��

	/*
	�����迭�� 10������ ������ �����ϰ� �� ó���� �����͸� �����ϱ� ���� ��� �����͸� ��ĭ�� ������ �ű�� ����� �ۼ��غ�����
	

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
	cout << "����ð�: " << end - begin << endl;
	//����ð��� 3milisecond ����.
	*/

	/*
	Node a;
	a.num = 1;

	Node b;
	b.num = 2;
	a.next = &b; //��ü a�� a�� �ּҸ� ������ a��ü�� b�� ������ ������ ������ش�.

	Node c;
	c.num = 3;
	b.next = &c;
	c.next = NULL; //c ������ ��ü�� �����ϱ� NULL�� �ش�.

	//�Լ��� �ۼ��Ͽ� Node a�� �����͸� �� �Լ��� �����ϸ�
	//a�� ����� ��� �����͸� ȭ�鿡 ǥ���Ѵ�.

	a.print_list(&a);
	*/

	//Linked List Ŭ���� ���ø��� �ۼ��ϰ� �߰� (add), ����(delete), ���(print) ����� �����غ�����.
	//������ ��� �ش� ��带 �����ϸ鼭 �� ��忡 ����ִ� �ּҸ� �� �� ��忡 ����Ѵ�.

	LinkedList<int> list;
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);

	list.print();

	
	list.remove(3);
	

	list.print();

	


	cout << "���α׷� ����..." << endl;
	return 0;
}