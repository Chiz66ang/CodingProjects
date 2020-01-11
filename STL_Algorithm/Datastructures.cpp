#include <iostream>

using namespace std;

/*int stack[5];
int idx = 0;
int sz = 5;

void push(int value) //값은 넣는다
{
	stack[idx++] = value;
}
int pop () //값을 뽑아온다
{
	--sz;
	return stack[--idx];
}
void print_stack()
{
	for (int i = 0; i < sz; i++)
	{
		cout << stack[i] << "\t";
	}
}
*/

class Stack
{
	int* stack;
	int count;
	int idx; //스택의 저장 위치
	int max_sz;
public:
	Stack() 
	{
		stack = new int[5];
		count = 5;
		idx = 0;
		max_sz = 15;
	}
	~Stack() { delete[] stack; }

	/*저장공간이 15개를 넘으면 Stack Overflow 예외가 발생함*/
	void push(int value) throw (exception)
	{
		if (idx == max_sz)
		{
			throw exception("Stack Overflow: 15개 초과");
		}
		else if (idx == count)
		{
			int* nst = new int[count + 5]; //nst는 지역변수. 나중에 stack에 주소를 준다.
			
			for (int i = 0; i < count; i++) //메모리 복사 (mem set으로 가능)
			{
				nst[i] = stack[i];
			}
			count += 5;
			delete[] stack;
			stack = nst;

		}
		stack[idx++] = value; //else 로 넣으면 제외가 되니 else 빼주기
	}

	int pop()
	{
		return stack[--idx];
	}

	void print()
	{
		for (int i = 0; i < idx; i++)
		{
			cout << stack[i] << endl;
		}
	}
};

int main()
{
	//Data Structures(자료구조): Stack, Queue, Linked List, Tree, Graph
	//Stack : Last In First Out :후입선출의 특징을 가진 자료구조. 나중에 들어간 것이 먼저 나온다
	//지역변수가 저장되는 자료구조
	/*
	push(2);
	push(4);
	push(6);
	print_stack();
	int i = pop();
	i = pop();
	i = pop();
	cout << "pop(): " << i << endl;
	*/

	/* 13일차 예제
	Stack 클래스 템플릿 안에 push(), pop() 맴버함수를 선언한다.
	초기 스택의 크기는 5로 하고 그 이상 공간이 필요하면 동적할당하도록 한다.
	저장공간이 15개를 넘으면 "stack Overflow" 예외를 던지도록 한다.
	
	*/
	Stack ex;

	try
	{
		ex.push(1);
		ex.push(2);
		ex.push(3);
		ex.push(4);
		ex.push(5);
		ex.push(7);
		ex.push(8);
		ex.push(9);
		ex.push(10);
		ex.push(11);
		ex.push(12);
		ex.push(13);
		ex.push(14);
		ex.push(15);
		ex.push(16);
		ex.push(17);
		ex.push(18);
	
		
		ex.print();

		int p = ex.pop();
		cout << "pop: " << p << endl;
	}
	catch (exception& e) //에러 객체의 주소만 따로 이름을 정해서 가져와라. 메모리 손실을 막을 수 있다.
	{
		cout << e.what() << endl;
	}

	

	return 0;
}