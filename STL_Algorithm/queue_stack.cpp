#include <iostream>

using namespace std;

template <typename T>
class Stack
{
	T* stack;
	int count;
	int idx; //스택의 저장 위치
	int max_sz;

public:
	Stack()
	{
		stack = new T[5];
		count = 5;
		idx = 0;
		max_sz = 15;
	}
	~Stack() { delete[] stack; }

	/*저장공간이 15개를 넘으면 Stack Overflow 예외가 발생함*/
	void push(T value) throw (exception)
	{
		if (idx == max_sz)
		{
			throw exception("Stack Overflow: 15개 초과");
		}
		else if (idx == count)
		{
			T* nst = new T[count + 5]; 

			for (int i = 0; i < count; i++) 
			{
				nst[i] = stack[i];
			}
			count += 5;
			delete[] stack;
			stack = nst;

		}
		stack[idx++] = value; 
	}

	T pop()
	{
		T first = stack[0];
		for (int i = 1; i < idx; i++)
		{
			stack[i - 1] = stack[i]; //데이터를 앞으로 한칸씩 이동시킨다.
		}
		idx--; //데잍터를 저장할 공간도 한칸 빼줘야한다.
		return first;
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
	//Queue: 선입선출 특성의 자료구조(FIFO) First in First out
	//대기열 자료구조
	//예시: 로그인 대기열 처리

	Stack<char> st;
	try
	{
		st.push(65);
		st.push(66);
		st.push(67);
		st.push(68);
		st.push(69);
		st.push(70);
		st.push(71);
		st.push(72);
		st.push(73);
		st.push(74);
		st.push(75);
		st.push(76);
		st.push(77);
		st.push(78);
		st.push(79);

		
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	st.print();

	
	cout << "pop: " << st.pop() << endl;
	
	cout << "pop: " << st.pop() << endl;
	
	cout << "pop: " << st.pop() << endl;

	st.print();

	return 0;
}