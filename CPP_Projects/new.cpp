#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void print_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	delete[] arr; //�迭�� ���� delete[] �ƴ� ���� �׳� delete
}


int main()
{
	/*�����Ҵ�(malloc(12), new Ű����)
	int* arr = new int[3]; //����� ���� 3�� ������ ������ Ȯ�����ּ���.
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	cout << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;
	//���⵵ �����Ҵ��� ������ �޸𸮸� �������� ��������Ѵ�.
	delete[]arr; //�����Ҵ� �޸� ����.
	*/


	/* �����Ҵ� ����1
	Ű���忡�� �Է� �������� ���� ���� �޾Ƽ� "��� ���� �Է��Ͻǰǰ���?"
	�� ���� �ش��ϴ� ������ �迭�� �����ϰ� -> �� ������ ��ŭ�� �迭 ������ �����.
	�ٸ� �Լ��� �����Ͽ� ȭ�鿡 ǥ���ϴ� ����� �ۼ��غ�����.
	*/

	/*
	int a;
	cout << "�Է��Ͻ� ������ ������ �˷��ּ���: ";
	cin >> a;

	int* arr = new int[a];

	for (int i = 0; i < a; i++)
	{
		cout << "���ڸ� �Է����ּ���: ";
		cin >> arr[i];
	}

	for (int i = 0; i < a; i++)
	{
		cout << arr[i] <<"\t" ;
	}
	

	stringstream�� �� ������ ����
	cout << "�Է��� ������ ������: ";
	int size = 0;
	string line;
	getline(cin, line);
	
	stringstream ss(line);//���� �Է� �κ�
	ss >> size;
	ss.clear();

	int* arr = new(nothrow)int[size];
	if (arr == NULL)
	{
		cerr << "�����Ҵ� ����" << endl; //�����Ҵ��� �������� ��, arr�� �ƹ��� ���� �ȵ�����, �����ߴٰ� �ϰ�
		return 1; // main �Լ��� ������.
	}

	cout << size << "���� ���� �Է�";
	getline(cin, line);

	ss.str(line);
	for (int i = 0; !ss.eof(); i++) //eof -> end of file ���⼭�� ��Ʈ���� ���� �ǹ� (Ture/ false)���� ���´�. ������ ture�� ���;��Ѵ�. ��Ʈ���� ���� �������� �ʾ����� ��� ������
	{
		ss >> arr[i];
	}//�迭�� �ʱ�ȭ �κ�

	print_arr(arr, size);
	*/

	/*
	typedef Ű����
	�ڷ����� ���� �����Ѵ�. -> ������ ����� ����
	*/
	typedef int* IP; //���� ������(int*)�� IP��� �ϰڴ�.
	int a = 5;
	IP ip = &a;

	/*enum Ű����
	�������� �����ϰ� ������ ������ ������ ���� 
	�ʱ�ȭ�ϰ� ����Ͽ� Ȯ���غ�����.
	������ ����: IDEL, WALK, RUN, DIE
	
	enum Status
	{
		IDEL, WALK, RUN, DIE //0,1,2,3���� ���ǵǰ� �ִ�
	};
	//Satus game_state = WALK;
	//cout << "���� ���� ����: " << game_state << endl;
	//Ȥ��

	enum class Status
	{
		IDEL, WALK, RUN, DIE 
	};
	Status game_state = Status::WALK; //Ŭ������ �������� �� ȣ���ϴ� ��
	switch (game_state)
	{
	case Status::IDEL:
		break;
	case Status::WALK:
		break;
	case Status::RUN:
		break;
	}
	*/



	return 0;
}