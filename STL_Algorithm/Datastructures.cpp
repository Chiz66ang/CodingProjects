#include <iostream>

using namespace std;

/*int stack[5];
int idx = 0;
int sz = 5;

void push(int value) //���� �ִ´�
{
	stack[idx++] = value;
}
int pop () //���� �̾ƿ´�
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
	int idx; //������ ���� ��ġ
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

	/*��������� 15���� ������ Stack Overflow ���ܰ� �߻���*/
	void push(int value) throw (exception)
	{
		if (idx == max_sz)
		{
			throw exception("Stack Overflow: 15�� �ʰ�");
		}
		else if (idx == count)
		{
			int* nst = new int[count + 5]; //nst�� ��������. ���߿� stack�� �ּҸ� �ش�.
			
			for (int i = 0; i < count; i++) //�޸� ���� (mem set���� ����)
			{
				nst[i] = stack[i];
			}
			count += 5;
			delete[] stack;
			stack = nst;

		}
		stack[idx++] = value; //else �� ������ ���ܰ� �Ǵ� else ���ֱ�
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
	//Data Structures(�ڷᱸ��): Stack, Queue, Linked List, Tree, Graph
	//Stack : Last In First Out :���Լ����� Ư¡�� ���� �ڷᱸ��. ���߿� �� ���� ���� ���´�
	//���������� ����Ǵ� �ڷᱸ��
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

	/* 13���� ����
	Stack Ŭ���� ���ø� �ȿ� push(), pop() �ɹ��Լ��� �����Ѵ�.
	�ʱ� ������ ũ��� 5�� �ϰ� �� �̻� ������ �ʿ��ϸ� �����Ҵ��ϵ��� �Ѵ�.
	��������� 15���� ������ "stack Overflow" ���ܸ� �������� �Ѵ�.
	
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
	catch (exception& e) //���� ��ü�� �ּҸ� ���� �̸��� ���ؼ� �����Ͷ�. �޸� �ս��� ���� �� �ִ�.
	{
		cout << e.what() << endl;
	}

	

	return 0;
}