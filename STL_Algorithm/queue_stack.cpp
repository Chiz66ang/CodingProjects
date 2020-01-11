#include <iostream>

using namespace std;

template <typename T>
class Stack
{
	T* stack;
	int count;
	int idx; //������ ���� ��ġ
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

	/*��������� 15���� ������ Stack Overflow ���ܰ� �߻���*/
	void push(T value) throw (exception)
	{
		if (idx == max_sz)
		{
			throw exception("Stack Overflow: 15�� �ʰ�");
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
			stack[i - 1] = stack[i]; //�����͸� ������ ��ĭ�� �̵���Ų��.
		}
		idx--; //�����͸� ������ ������ ��ĭ ������Ѵ�.
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
	//Queue: ���Լ��� Ư���� �ڷᱸ��(FIFO) First in First out
	//��⿭ �ڷᱸ��
	//����: �α��� ��⿭ ó��

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